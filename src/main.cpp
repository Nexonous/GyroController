#include "core/Logging.hpp"
#include "core/Constants.hpp"

#include "components/MPU6050.hpp"
#include "components/nRF24L01.hpp"

MPU6050 g_Sensor;
nRF24L01 g_Radio;

void setup()
{
	GYRO_CONTROLLER_SETUP_LOGGING(115200);

	// Initialize the MPU6050 sensor.
	g_Sensor.initialize();

	// Initialize the nRF24L01 transceiver.
	g_Radio.initialize();

	GYRO_CONTROLLER_PRINT("Controller initialized. Jumping into the main loop.");
}

void loop()
{
	// Update the sensor data.
	g_Sensor.readData();
	auto reading = Vec4(g_Sensor.getAcceleration());

	// Process the outputs.
	reading.m_Pitch = map(reading.m_Pitch, g_PitchInputMinimum, g_PitchInputMaximum, g_OutputMinimum, g_OutputMaximum);
	reading.m_Roll = map(reading.m_Roll, g_RollInputMinimum, g_RollInputMaximum, g_OutputMinimum, g_OutputMaximum);
	reading.m_Yaw = map(reading.m_Yaw, g_YawInputMinimum, g_YawInputMaximum, g_OutputMinimum, g_OutputMaximum);

	// Transmit the data.
	g_Radio.write(reading);

	// Print them for debugging.
	GYRO_CONTROLLER_PRINT("Throttle: ");
	GYRO_CONTROLLER_PRINT(reading.m_Throttle);
	GYRO_CONTROLLER_PRINT(" Pitch: ");
	GYRO_CONTROLLER_PRINT(reading.m_Pitch);
	GYRO_CONTROLLER_PRINT(" Roll: ");
	GYRO_CONTROLLER_PRINT(reading.m_Roll);
	GYRO_CONTROLLER_PRINT(" Yaw: ");
	GYRO_CONTROLLER_PRINT(reading.m_Yaw);
	GYRO_CONTROLLER_PRINTLN();
}
