#define VERSION "0.1" //version number
#define COMPILE_DATE __DATE__ " " __TIME__
#define DEV_TYPE "M5STACK"
#define ROTATION 1

#define KEYPAD

#define BUF_SIZE 80
#define DISP_BUF_SIZE (LV_HOR_RES_MAX * BUF_SIZE)
#define BUF_NUM 1

#define I2C_SPEED 400000U

// Log level definitions
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_ERROR 2

// Set current log level, change this to control log output
#define CURRENT_LOG_LEVEL LOG_LEVEL_INFO

// Log macros for different levels
#ifdef _DEBUG_
    #define LOG_DEBUG(format, ...) do { \
        if (CURRENT_LOG_LEVEL <= LOG_LEVEL_DEBUG) { \
            Serial.printf("[DEBUG] "); \
            Serial.printf(format, ##__VA_ARGS__); \
            Serial.println(); \
        } \
    } while(0)
#else
    #define LOG_DEBUG(format, ...) do {} while(0)
#endif

#define LOG_INFO(format, ...) do { \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_INFO) { \
        Serial.printf("[INFO] "); \
        Serial.printf(format, ##__VA_ARGS__); \
        Serial.println(); \
    } \
} while(0)

#define LOG_ERROR(format, ...) do { \
    if (CURRENT_LOG_LEVEL <= LOG_LEVEL_ERROR) { \
        Serial.printf("[ERROR] "); \
        Serial.printf(format, ##__VA_ARGS__); \
        Serial.println(); \
    } \
} while(0)