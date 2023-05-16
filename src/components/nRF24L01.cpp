// Copyright 2023 Nexonous
// SPDX-License-Identifier: Apache-2.0

#include "nRF24L01.hpp"

#include "core/Logging.hpp"

nRF24L01::nRF24L01()
	: m_Transceiver(g_ChipEnablePin, g_ChipSelectNotPin)
{
}

void nRF24L01::initialize()
{
	GYRO_CONTROLLER_PRINTLN("Initializing the nRF24L01 transceiver.");

	m_Transceiver.begin();
	m_Transceiver.openWritingPipe(g_DefaultAddress);
	m_Transceiver.stopListening();

	GYRO_CONTROLLER_PRINTLN("The nRF24L01 transceiver is initialized.");
}

void nRF24L01::write(String data)
{
	m_Transceiver.openWritingPipe(g_DefaultAddress);
	m_Transceiver.write(data.c_str(), data.length());
}

void nRF24L01::writeRaw(const void *pData, size_t length)
{
	m_Transceiver.openWritingPipe(g_DefaultAddress);
	m_Transceiver.write(pData, length);
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
