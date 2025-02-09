# PigeonPowerSupply
使用M5模块构成的一个数控可调电源。
![preview](/assets/preview.jpg)
## 硬件组成
硬件部分由以下模块构成
* [M5 CORE basic](https://docs.m5stack.com/en/core/basic_v2.7)
* [PPS Module](https://docs.m5stack.com/en/module/Module13.2-PPS)
* [HMI Module](https://docs.m5stack.com/en/module/HMI%20Module)

模块堆叠顺序如下
|模块堆叠顺序|
|---|
|M5 CORE|
|HMI Module|
|PPS Module|

### 基本参数
输出能力： 0.5V~30V/0-5A
最大功率：100W(150W峰值)
## 功能
- [x] 数控设定电压电流调节
- [x] 回显数据刷新率可调，尽量快的CC/CV显示
- [x] 回显电压电流模拟条
- [x] 可配置的电源输出限制
- [x] 快捷输出选择
### 开发计划
- [ ] 曲线图标显示
- [ ] 模拟条和曲线荧光模式
- [ ] 更好的UI动画
## 使用方法
![1_chs](/assets/1_chs.png)
