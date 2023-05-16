// Copyright 2023 Nexonous
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <Arduino.h>

/**
 * @brief No-op function.
 * This function does not do anything and will be optimized out.
 */
inline void NoOp() {}

#if defined(GYRO_CONTROLLER_DEBUG) || defined(GYRO_CONTROLLER_PRODUCTION_TEST)
#define GYRO_CONTROLLER_SETUP_LOGGING(bound) Serial.begin(bound)
#define GYRO_CONTROLLER_PRINT(...) Serial.print(__VA_ARGS__)
#define GYRO_CONTROLLER_PRINTLN(...) Serial.println(__VA_ARGS__)

#else
#define GYRO_CONTROLLER_SETUP_LOGGING(bound) NoOp()
#define GYRO_CONTROLLER_PRINT(...) NoOp()
#define GYRO_CONTROLLER_PRINTLN(...) NoOp()

#endif