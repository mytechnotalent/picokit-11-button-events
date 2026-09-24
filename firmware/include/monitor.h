// MIT License
//
// Copyright (c) 2026 Kevin Thomas
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Author:  Kevin Thomas
// Email:   kevin@mytechnotalent.com
// GitHub:  https://github.com/mytechnotalent/picokit-11-button-events
// File:    monitor.h
// Desc:    Declares the button events state machine that classifies short,
//          long, and double presses from the tactile switch.
// Created: 2026

#ifndef MONITOR_H
#define MONITOR_H

#include <stdbool.h>
#include <stdint.h>

/**
 * @brief Spacing between two button event steps in milliseconds.
 */
#define MONITOR_STEP_INTERVAL_MS 50u

/**
 * @brief Long-press threshold in microseconds.
 */
#define MONITOR_LONG_PRESS_US 800000u

/**
 * @brief Double-press gap threshold in microseconds.
 */
#define MONITOR_DOUBLE_GAP_US 300000u

/**
 * @brief Event code for no classified event.
 */
#define MONITOR_EVENT_NONE 0u

/**
 * @brief Event code for a short press.
 */
#define MONITOR_EVENT_SHORT 1u

/**
 * @brief Event code for a long press.
 */
#define MONITOR_EVENT_LONG 2u

/**
 * @brief Event code for a double press.
 */
#define MONITOR_EVENT_DOUBLE 3u

/**
 * @brief Number of classified button event codes.
 */
#define MONITOR_EVENT_COUNT 4u

/**
 * @brief Onboard heartbeat LED on and off time in microseconds.
 */
#define MONITOR_HEARTBEAT_BLINK_US 50000u

/**
 * @brief Initialize the button events monitor state machine.
 *
 * Configures the three event LEDs, the tactile button, the onboard
 * heartbeat LED, and the RYLR998 UART, derives the field key, and resets
 * the sequence counter.
 *
 * @param void No parameters.
 * @return bool true when all submodules initialized.
 */
bool monitor_init(void);

/**
 * @brief Clear the monitor-ready flag.
 *
 * Test and recovery hook that returns the state machine to the
 * uninitialized policy state.
 *
 * @param void No parameters.
 * @return void
 */
void monitor_deinit(void);

/**
 * @brief Execute one monitor state-machine tick.
 *
 * Classifies a short, long, or double button event, shows the event on
 * the lamps, blinks the onboard LED as a heartbeat, transmits the
 * authenticated heartbeat frame on the telemetry interval, and pumps
 * inbound +RCV lines.
 *
 * @param void No parameters.
 * @return bool true when the tick completed without a policy error.
 */
bool monitor_step(void);

#endif // MONITOR_H
