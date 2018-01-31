/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/
#include "PeripheralPins.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
extern const PinName digitalPin[];

enum {
// Right side
  PB11, //D0
  PB10, //D1
  PB2,  //D2
  PB0,  //D3
  PA7,  //D4
  PA6,  //D5
  PA5,  //D6
  PA4,  //D7
  PA3,  //D8
  PA2,  //D9
  PA1,  //D10
  PA0,  //D11
  PC15, //D12
  PC14, //D13
  PC13, //D14
// Left side
  PB7,  //D15
  PB6,  //D16
  PB5,  //D17
  PB4,  //D18
  PB3,  //D19
  PA15, //D20
  PA14, //D21
  PA13, //D22
  PA12, //D23
  PA11, //D24
  PA10, //D25
  PA9,  //D26
  PA8,  //D27
  PB15, //D28
  PB14, //D29
  PB13, //D30
  PB12, //D31
// Other
  PB8,  //D32 - User buttons
  PB1,  //D33 - LED
  PB9,  //D34
// Duplicated pins in order to be aligned with PinMap_ADC
  PB0_2,//D35/A0 = D3
  PA7_2,//D36/A1 = D4
  PA6_2,//D37/A2 = D5
  PA5_2,//D38/A3 = D6
  PA4_2,//D39/A4 = D7
  PA3_2,//D40/A5 = D8
  PA2_2,//D41/A6 = D9
  PA1_2,//D42/A7 = D10
  PA0_2,//D43/A8 = D11
  PEND
};

// This must be a literal with the same value as PEND
#define NUM_DIGITAL_PINS        44
// This must be a literal with a value less than or equal to to MAX_ANALOG_INPUTS
#define NUM_ANALOG_INPUTS       9
#define NUM_ANALOG_FIRST        35

//ADC resolution is 12bits
#define ADC_RESOLUTION          12
#define DACC_RESOLUTION         12

//PWR resolution
#define PWM_RESOLUTION          8
#define PWM_FREQUENCY           1000
#define PWM_MAX_DUTY_CYCLE      255

//On-board LED pin number
#define LED_BUILTIN             D33
#define LED_GREEN               LED_BUILTIN

//On-board user button
#define USER_BTN                D32

//SPI definitions
//define 16 channels. As many channel as digital IOs
#define SPI_CHANNELS_NUM        16

//default chip salect pin
#define BOARD_SPI_DEFAULT_SS    7

//In case SPI CS channel is not used we define a default one
#define BOARD_SPI_OWN_SS        SPI_CHANNELS_NUM

#define PIN_SPI_SS              D7
#define PIN_SPI_SS1             D8
#define PIN_SPI_SS2             D9
#define PIN_SPI_SS3             D10
#define PIN_SPI_MOSI            D6
#define PIN_SPI_MISO            D5
#define PIN_SPI_SCK             D4

//I2C Definitions
#define PIN_WIRE_SDA            D0
#define PIN_WIRE_SCL            D1

//Timer Definitions
//Do not use timer used by PWM pins when possible. See PinMap_PWM.
#define TIMER_TONE              TIM4
#define TIMER_UART_EMULATED     TIM4

//Do not use basic timer: OC is required
#define TIMER_SERVO             TIM2  //TODO: advanced-control timers don't work

#define DEBUG_UART              ((USART_TypeDef *) USART1)

// Serial Pin Firmata
#define PIN_SERIAL_RX           D25
#define PIN_SERIAL_TX           D26
#define PIN_SERIAL1_RX          D8
#define PIN_SERIAL1_TX          D9
#define PIN_SERIAL2_RX          D0
#define PIN_SERIAL2_TX          D1

#if defined(SERIAL_USB) && defined(USBCON) && !defined(USB_DISC_PIN)
#define USB_DISC_PIN            D34
#endif

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

#if defined(SERIAL_USB) && defined(USBCON)
extern USBSerial Serial;
#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL  Serial
#define SERIAL_PORT_HARDWARE    Serial1
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
