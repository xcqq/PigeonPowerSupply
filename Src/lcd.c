#include "lcd.h"

#define LCD_PORT        GPIOD
#define LCD_RST_PIN     GPIO_PIN_11



typedef struct {
    __IO uint16_t reg;
    __IO uint16_t ram;
} lcd_controller_t;

#define LCD_BASE ((uint32_t) 0x60000000 | 0x003FFFE)
#define LCD     ((lcd_controller_t *)LCD_BASE)

#define LCD_REG(data)    \
    {                    \
        LCD->reg = data; \
    }
#define LCD_RAM(data)    \
    {                    \
        LCD->ram = data; \
    }
#define LCD_WRITE_REG(register, data) \
    {                                 \
        LCD->reg = register;          \
        LCD->ram = data;              \
    }

static void fsmc_init(void)
{
    SRAM_HandleTypeDef hsram1;
    FSMC_NORSRAM_TimingTypeDef Timing;

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_FSMC_CLK_ENABLE();

    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();

    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;

    GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_14 | GPIO_PIN_15;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 |
                          GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 |
                          GPIO_PIN_15;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    hsram1.Instance = FSMC_NORSRAM_DEVICE;
    hsram1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;

    hsram1.Init.NSBank = FSMC_NORSRAM_BANK1;
    hsram1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
    hsram1.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
    hsram1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
    hsram1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
    hsram1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
    hsram1.Init.WrapMode = FSMC_WRAP_MODE_DISABLE;
    hsram1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
    hsram1.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
    hsram1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
    hsram1.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
    hsram1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
    hsram1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
    hsram1.Init.PageSize = FSMC_PAGE_SIZE_NONE;

    Timing.AddressSetupTime = 9;
    Timing.AddressHoldTime = 0;
    Timing.DataSetupTime = 8;
    Timing.BusTurnAroundDuration = 0;
    Timing.CLKDivision = 0;
    Timing.DataLatency = 0;
    Timing.AccessMode = FSMC_ACCESS_MODE_A;

    
    if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
    {
        Error_Handler();
    }
}


void lcd_init()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    fsmc_init();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    GPIO_InitStruct.Pin = LCD_RST_PIN ;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LCD_PORT, &GPIO_InitStruct);

    __HAL_RCC_GPIOC_CLK_ENABLE();
    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, 1);

    HAL_GPIO_WritePin(LCD_PORT, LCD_RST_PIN, 0);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(LCD_PORT, LCD_RST_PIN, 1);
    HAL_Delay(1000);


    LCD_REG(0x2300);

    /* Power Supply Setting */
	LCD_WRITE_REG(0x11, 0x0000);
    LCD_WRITE_REG(0x12, 0x0000);
    LCD_WRITE_REG(0x13, 0x0000);
    LCD_WRITE_REG(0x14, 0x0000);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0010);
    LCD_WRITE_REG(0x12, 0x3222);
    LCD_WRITE_REG(0x13, 0x204E);
	//LCD_WRITE_REG(0x14, 0x0248);//VCOM
    LCD_WRITE_REG(0x14, 0x0228);//VCOM
	

	
    LCD_WRITE_REG(0x10, 0x0700);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0112);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0312);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0712);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0F1B);
    HAL_Delay(1);
    
    LCD_WRITE_REG(0x11, 0x0F3B);
    HAL_Delay(3);

    /* Display Contron Register Setup */
    LCD_WRITE_REG(0x01, 0x0136);
    LCD_WRITE_REG(0x02, 0x0000);
    #ifdef LCD_LANDSCAPE
    LCD_WRITE_REG(0x03, 0x1060);
    #else
	LCD_WRITE_REG(0x03, 0x1000);		//Set BGR = 1
    #endif
	
    LCD_WRITE_REG(0x07, 0x0104);
    LCD_WRITE_REG(0x08, 0x00E2);
    LCD_WRITE_REG(0x0B, 0x1100);
    LCD_WRITE_REG(0x0C, 0x0000);
    LCD_WRITE_REG(0x0F, 0x0001);     // OSC. freq.
    HAL_Delay(4);
    
    LCD_WRITE_REG(0x15, 0x0031);
    LCD_WRITE_REG(0x46, 0x00EF);
    LCD_WRITE_REG(0x47, 0x0000);
    LCD_WRITE_REG(0x48, 0x01AF);
    LCD_WRITE_REG(0x49, 0x0000);
    /*
    // Gamma (R)
    LCD_WRITE_REG(0x50, 0x0000);
    LCD_WRITE_REG(0x51, 0x030c);
    LCD_WRITE_REG(0x52, 0x0801);
    LCD_WRITE_REG(0x53, 0x0109);
    LCD_WRITE_REG(0x54, 0x0b01);
    LCD_WRITE_REG(0x55, 0x0200);
    LCD_WRITE_REG(0x56, 0x020d);
    LCD_WRITE_REG(0x57, 0x0e00);
    LCD_WRITE_REG(0x58, 0x0002);
    LCD_WRITE_REG(0x59, 0x010b);

    // Gamma (G)
    LCD_WRITE_REG(0x60, 0x0B00);
    LCD_WRITE_REG(0x61, 0x000D);
    LCD_WRITE_REG(0x62, 0x0000);
    LCD_WRITE_REG(0x63, 0x0002);
    LCD_WRITE_REG(0x64, 0x0604);
    LCD_WRITE_REG(0x65, 0x0000);
    LCD_WRITE_REG(0x66, 0x000C);
    LCD_WRITE_REG(0x67, 0x060F);
    LCD_WRITE_REG(0x68, 0x0F0F);
    LCD_WRITE_REG(0x69, 0x0A06);
		
		// Gamma (B)
		LCD_WRITE_REG(0x70, 0x0B00);
    LCD_WRITE_REG(0x71, 0x000D);
    LCD_WRITE_REG(0x72, 0x0000);
    LCD_WRITE_REG(0x73, 0x0002);
    LCD_WRITE_REG(0x74, 0x0604);
    LCD_WRITE_REG(0x75, 0x0000);
    LCD_WRITE_REG(0x76, 0x000C);
    LCD_WRITE_REG(0x77, 0x060F);
    LCD_WRITE_REG(0x78, 0x0F0F);
    LCD_WRITE_REG(0x79, 0x0A06);
    
		*/
		
    //LCD_WRITE_REG(0x80, 0x0101);		//MTP control
    
    // Display Sequence
    LCD_WRITE_REG(0x07, 0x0112);
    HAL_Delay(4);
    LCD_WRITE_REG(0x07, 0x1113);

    LCD_WRITE_REG(0x13, 0x2055);

    // Power Control 1(R10h)
    // SAP: Fast    DSTB1F: Off    DSTB: Off    STB: Off
    LCD_WRITE_REG(0x10, 0x0700);
		 
    // Blank Period Control(R08h)
    // FP: 2    BP: 2
    LCD_WRITE_REG(0x08, 0x0022);
		 
    // Frame Cycle Control(R0Bh)
    // NO: 2 INCLK    SDT: 2 INCLK    DIV: fosc/1    RTN: 17 INCLK
    LCD_WRITE_REG(0x0B, 0x2201);
}

static void lcd_set_window(uint16_t x_start, uint16_t y_start, uint16_t x_end,uint16_t y_end)
{
    #ifdef LCD_LANDSCAPE
    LCD_WRITE_REG(0x47, x_start);
	LCD_WRITE_REG(0x46, (x_start+x_end-1));
		
	LCD_WRITE_REG(0x49, y_start);
	LCD_WRITE_REG(0x48, (y_start+y_end-1));
    #else
    LCD_WRITE_REG(0x47, x_start);
	LCD_WRITE_REG(0x46, (x_start+x_end-1));
		
	LCD_WRITE_REG(0x49, y_start);
	LCD_WRITE_REG(0x48, (y_start+y_end-1));
    #endif
	
	LCD_REG(0x22);
}

void lcd_clear()
{
    uint32_t i;
    lcd_set_window(0, 0, LCD_WIDTH, LCD_HEIGHT);
    for (i = 0; i < LCD_WIDTH * LCD_HEIGHT;i++)
    {
        LCD_RAM(BLACK);
    }
}

void lcd_draw_bmp(uint16_t x_start,uint16_t y_start,uint16_t width,uint16_t height,uint8_t *bmp)
{
    uint16_t i;
    uint16_t *tmp = (uint16_t *)bmp;
    lcd_set_window(x_start, y_start, width, height);

    for(i=0; i<width*height; i++)
	{
        LCD_RAM(*(tmp++));
	}
}


void lcd_display_color_bar(void)
{
static unsigned int colorbar[]=
{
	RGB(0xFF, 0xFF, 0x00),
	RGB(0xFF, 0x00, 0x00),
	RGB(0x00, 0xFF, 0x00),
	RGB(0x00, 0x00, 0xFF),

	RGB(0xFF, 0x00, 0xFF),
	RGB(0x00, 0xFF, 0xFF),
	RGB(0x00, 0x00, 0x00),		//there can not be 0x00 or 0xFF
	RGB(0xFF, 0xFF, 0xFF),

};
	int i=0, j/*, index=0*/;
	uint8_t step;

	step = LCD_WIDTH / 8;
	lcd_set_window(0, 0, LCD_WIDTH, LCD_HEIGHT); 

	for(j=0; j<LCD_WIDTH; j++)
	{
		for(i=0; i< LCD_HEIGHT; i++)
		{
			LCD_RAM(colorbar[j/step]);
		}
	}
}

void lcd_display_gray_bar(void)
{
static unsigned int gray[]=
{
	RGB(0x00, 0x00, 0x00),
	RGB(0x10, 0x10, 0x10),
	RGB(0x20, 0x20, 0x20),
	RGB(0x30, 0x30, 0x30),
	RGB(0x40, 0x40, 0x40),
	RGB(0x50, 0x50, 0x50),
	RGB(0x60, 0x60, 0x60),
	RGB(0x70, 0x70, 0x70),
	RGB(0x80, 0x80, 0x80),
	RGB(0x90, 0x90, 0x90),
	RGB(0xA0, 0xA0, 0xA0),
	RGB(0xB0, 0xB0, 0xB0),
	RGB(0xC0, 0xC0, 0xC0),
	RGB(0xD0, 0xD0, 0xD0),
	RGB(0xE0, 0xE0, 0xE0),
	RGB(0xF0, 0xF0, 0xF0),
};
	int i=0,j;
	uint8_t step;
	step = LCD_HEIGHT / 16;
	lcd_set_window(0, 0, LCD_WIDTH, LCD_HEIGHT); 
	
	for(j=0; j< LCD_HEIGHT; j++)
	{
		for(i=0; i< LCD_WIDTH; i++)
		{
			LCD_RAM(RGB(i, i, i));
		}
	}
}