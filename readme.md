# PigeonPowerSupply
A programmable power supply built with M5Stack modules.
![preview](/assets/preview.jpg)

## Hardware Overview
The hardware consists of the following modules:
* [M5 CORE basic](https://docs.m5stack.com/en/core/basic_v2.7)
* [PPS Module](https://docs.m5stack.com/en/module/Module13.2-PPS)
* [HMI Module](https://docs.m5stack.com/en/module/HMI%20Module)

Module stacking order:
|Stack Order|
|---|
|M5 CORE|
|HMI Module|
|PPS Module|

### Basic Parameters
Output Capability: 0.5V~30V/0-5A
Maximum Power: 100W(150W peak)

## Features
- [x] Digital voltage and current control
- [x] Adjustable refresh rate for feedback display, fastest possible CC/CV indication
- [x] Voltage and current feedback with progress bars
- [x] Configurable power output limits
- [x] Quick output selection

### Development Plan
- [ ] Graph display
- [ ] Fluorescent mode for progress bars and graphs
- [ ] Enhanced UI animations

## Usage
![1](/assets/1.png)
