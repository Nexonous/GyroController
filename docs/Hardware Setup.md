# Hardware Setup 🔧

The controller does not require a ton of hardware. It only needs the MPU6050 sensor, a universal joystick rocker (2 axis), a NRF25L01+PA+LNA Wireless Transceiver and the actual Arduino board. When connecting everything together, use the following table as a guide.

| Component | Component's pin/ connection | Arduino pin number |
|:---------:|:---------------------------:|:------------------:|
|  MPU6050  |             VCC             |         VIN        |
|  MPU6050  |             GND             |         GND        |
|  MPU6050  |             SCL             |         SCL        |
|  MPU6050  |             SDA             |         SDA        |
|  NRF24L01 |             VCC             |        3.3V        |
|  NRF24L01 |             GND             |         GND        |
|  NRF24L01 |              CE             |          9         |
|  NRF24L01 |             CSN             |         10         |
|  NRF24L01 |             SCK             |         SCK        |
|  NRF24L01 |             MOSI            |        MOSI        |
|  NRF24L01 |             MISO            |        MISO        |
