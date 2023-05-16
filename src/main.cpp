#include "core/Logging.hpp"

#include "components/MPU6050.hpp"

MPU6050 sensor;

void setup()
{
  GYRO_CONTROLLER_SETUP_LOGGING(9600);

  sensor.initialize();
}

void loop()
{
  sensor.readData();
  const auto reading = sensor.getAcceleration();

  GYRO_CONTROLLER_PRINT("Throttle: ");
  GYRO_CONTROLLER_PRINT(500);
  GYRO_CONTROLLER_PRINT(" Pitch: ");
  GYRO_CONTROLLER_PRINT(map(reading.m_Pitch, -90, 90, 0, 1000));
  GYRO_CONTROLLER_PRINT(" Roll: ");
  GYRO_CONTROLLER_PRINT(map(reading.m_Roll, -90, 90, 0, 1000));
  GYRO_CONTROLLER_PRINT(" Yaw: ");
  GYRO_CONTROLLER_PRINT(map(reading.m_Yaw, -90, 90, 0, 1000));
  GYRO_CONTROLLER_PRINTLN();
}
