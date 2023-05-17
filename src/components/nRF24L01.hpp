// Copyright 2023 Nexonous
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <nRF24L01.h>
#include <RF24.h>

constexpr auto g_ChipEnablePin = 9;
constexpr auto g_ChipSelectNotPin = 10;
constexpr byte g_DefaultAddress[6] = "00001";

/**
 * @brief nRF24L01 transceiver module class.
 * This class can be used to transmit and/ or receive data from a nRF24L01 data link.
 */
class nRF24L01
{
public:
	/**
	 * @brief Construct a new n R F24 L01 object.
	 */
	nRF24L01();

	/**
	 * @brief Initialize the transceiver module.
	 */
	void initialize();

	/**
	 * @brief Write from a variable.
	 *
	 * @tparam Type The type of the variable.
	 * @param data The data to write.
	 */
	template <class Type>
	void write(const Type &data)
	{
		writeRaw(&data, sizeof(Type));
	}

	/**
	 * @brief Write data to the default address.
	 *
	 * @param data The data to be written.
	 */
	void write(String data);

	/**
	 * @brief Write a raw packet of data.
	 *
	 * @param pData The data pointer to write.
	 * @param length The length of the data.
	 */
	void writeRaw(const void *pData, size_t length);

	/**
	 * @brief Check if there are data to be read.
	 *
	 * @return true if there are data to be read.
	 * @return false if there are no data to be read.
	 */
	bool isAvailable();

	/**
	 * @brief Read data from the default address.
	 *
	 * @return The incoming data. If nothing is available it'll return an empty string.
	 */
	String read();

private:
	RF24 m_Transceiver;
};