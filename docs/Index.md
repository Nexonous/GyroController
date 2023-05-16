# Gyro Controller 🎮

Gyro Controller is a drone controller that gets its pitch and roll values from the internal gyroscope/ accelerometer sensor. The default data link (communication method) is the [NRF24L01+PA+LNA transceiver](https://www.sparkfun.com/datasheets/Components/SMD/nRF24L01Pluss_Preliminary_Product_Specification_v1_0.pdf) module. In the future we'll add support for [LoRa](https://en.wikipedia.org/wiki/LoRa) communication links.

## Getting Started 🍃

The project is based on [PlatformIO](https://platformio.org/) and uses an Arduino Uno/ Micro/ Nano. First, start by installing the PlatformIO extension to [Visual Studio Code](https://platformio.org/install/ide?install=vscode). Once it's installed and the PlatformIO SDK is also installed in your machine, you can clone this repository using the following commands.

```sh
git clone https://github.com/Nexonous/GyroController
```

Once the project is cloned, open the folder up in VS Code. Once all the hardware components are ready, plug in the Arduino board to your machine and configure the port. Afterwards go to the PlatformIO extension and select the build you want to upload. If it's the first time you're uploading the code to the controller, consider uploading the debug code since it has some additional features to detect if there's a problem with the hardware components. When uploading the debug code, select the correct target and click on the 'Upload and Monitor' task. This should upload the code to the controller and show the controller's output in the monitor.

If the debug code runs without an issue, you can then go ahead and upload the release target to the controller. Here you just need to run the 'Upload' task since it does not have any console loggings.

## License ⚖️

This repository is licensed under [Apache-2.0](https://github.com/Nexonous/GyroController/blob/release/LICENSE).
