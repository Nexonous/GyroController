// Copyright 2023 Nexonous
// SPDX-License-Identifier: Apache-2.0

#include <SPI.h>
#include "nRF24L01.hpp"

#ifdef GYRO_CONTROLLER_DEBUG
#include "printf.h"

#endif

#include "core/Logging.hpp"

nRF24L01::nRF24L01()
	: m_Transceiver(g_ChipEnablePin, g_ChipSelectNotPin)
{
}

void nRF24L01::initialize()
{
	GYRO_CONTROLLER_PRINTLN("Initializing the nRF24L01 transceiver.");

	if (!m_Transceiver.begin())
	{
		GYRO_CONTROLLER_PRINTLN("Failed to initialize the nRF24L01 transceiver!");
		return;
	}

	m_Transceiver.setDataRate(RF24_250KBPS);
	m_Transceiver.setPALevel(RF24_PA_MAX);
	m_Transceiver.setAutoAck(false);
	m_Transceiver.setRetries(5, 15);

	m_Transceiver.openWritingPipe(g_DefaultAddress);

#ifdef GYRO_CONTROLLER_DEBUG
	printf_begin();
	m_Transceiver.printPrettyDetails();

#endif

	GYRO_CONTROLLER_PRINTLN("The nRF24L01 transceiver is initialized.");
}

void nRF24L01::write(String data)
{
#ifdef GYRO_CONTROLLER_DEBUG
	if (!m_Transceiver.write(data.c_str(), data.length()))
	{
		GYRO_CONTROLLER_PRINT("Failed to transfer data! ");
	}

#else
	m_Transceiver.write(data.c_str(), data.length());

#endif
}

void nRF24L01::writeRaw(const void *pData, size_t length)
{
#ifdef GYRO_CONTROLLER_DEBUG
	if (!m_Transceiver.write(pData, length))
	{
		GYRO_CONTROLLER_PRINT("Failed to transfer data! ");
	}

#else
	m_Transceiver.write(pData, length);

#endif
}

bool nRF24L01::isAvailable()
{
	return m_Transceiver.available();
}

String nRF24L01::read()
{
	char buffer[32] = {0};

	m_Transceiver.openReadingPipe(0, g_DefaultAddress);
	m_Transceiver.read(buffer, sizeof(buffer));

	return buffer;
}
