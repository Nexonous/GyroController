// Copyright 2023 Nexonous
// SPDX-License-Identifier: Apache-2.0

#pragma once

constexpr auto g_ThrottleInputMinimum = 0;
constexpr auto g_ThrottleInputMiddle = 500;
constexpr auto g_ThrottleInputMaximum = 1000;

constexpr auto g_PitchInputMinimum = -90;
constexpr auto g_PitchInputMiddle = 0;
constexpr auto g_PitchInputMaximum = 90;

constexpr auto g_RollInputMinimum = g_PitchInputMinimum;
constexpr auto g_RollInputMiddle = g_PitchInputMiddle;
constexpr auto g_RollInputMaximum = g_PitchInputMaximum;

constexpr auto g_YawInputMinimum = g_RollInputMinimum;
constexpr auto g_YawInputMiddle = g_RollInputMiddle;
constexpr auto g_YawInputMaximum = g_RollInputMaximum;

constexpr auto g_OutputMinimum = 0;
constexpr auto g_OutputMaximum = 1000;
