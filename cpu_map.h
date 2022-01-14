/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2017-2018 Gauthier Briere
  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The cpu_map.h files serve as a central pin mapping selection file for different
   processor types or alternative pin layouts. This version of Grbl supports only the
   Arduino Mega2560. */

#ifndef cpu_map_h
#define cpu_map_h

#ifdef CPU_MAP_2560_RAMPS_BOARD // (Arduino Mega 2560) with Ramps 1.4 Board
  #include "nuts_bolts.h"

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Define ports and pins
  #define DDR(port) DDR##port
  #define _DDR(port) DDR(port)
  #define PORT(port) PORT##port
  #define _PORT(port) PORT(port)
  #define PIN(pin) PIN##pin
  #define _PIN(pin) PIN(pin)

  // Define step pulse output pins.

  #define STEP_PORT_0 F
  #define STEP_PORT_1 F
  #define STEP_PORT_2 L
  #if N_AXIS > 3
    #define STEP_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define STEP_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define STEP_PORT_5 L // Axis number 6 (Ramps Aux-3 D49)
  #endif
  #define STEP_BIT_0 0  // X Step - Pin A0
  #define STEP_BIT_1 6  // Y Step - Pin A6
  #define STEP_BIT_2 3  // Z Step - Pin D46
  #if N_AXIS > 3
    #define STEP_BIT_3 4 // Axis number 4 Step - Pin D26
  #endif
  #if N_AXIS > 4
    #define STEP_BIT_4 1 // Axis number 5 Step - Pin D36
  #endif
  #if N_AXIS > 5
    #define STEP_BIT_5 0 // Axis number 6 Step - Pin D49
  #endif
  #define _STEP_BIT(i) STEP_BIT_##i
  #define STEP_BIT(i) _STEP_BIT(i)
  #define STEP_DDR(i) _DDR(STEP_PORT_##i)
  #define _STEP_PORT(i) _PORT(STEP_PORT_##i)
  #define STEP_PORT(i) _STEP_PORT(i)
  #define STEP_PIN(i) _PIN(STEP_PORT_##i)

  // Define step direction output pins.
  #define DIRECTION_PORT_0 F
  #define DIRECTION_PORT_1 F
  #define DIRECTION_PORT_2 L
  #if N_AXIS > 3
    #define DIRECTION_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define DIRECTION_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define DIRECTION_PORT_5 B // Axis number 6 (Ramps Aux-3 D51)
  #endif
  #define DIRECTION_BIT_0 1 // X Dir - Pin A1
  #define DIRECTION_BIT_1 7 // Y Dir - Pin A7
  #define DIRECTION_BIT_2 1 // Z Dir - Pin D48
  #if N_AXIS > 3
    #define DIRECTION_BIT_3 6 // Axis number 4 Step - Pin D28
  #endif
  #if N_AXIS > 4
    #define DIRECTION_BIT_4 3 // Axis number 5 Step - Pin D34
  #endif
  #if N_AXIS > 5
    #define DIRECTION_BIT_5 2 // Axis number 6 Step - Pin D51
  #endif
  #define _DIRECTION_BIT(i) DIRECTION_BIT_##i
  #define DIRECTION_BIT(i) _DIRECTION_BIT(i)
  #define DIRECTION_DDR(i) _DDR(DIRECTION_PORT_##i)
  #define _DIRECTION_PORT(i) _PORT(DIRECTION_PORT_##i)
  #define DIRECTION_PORT(i) _DIRECTION_PORT(i)
  #define DIRECTION_PIN(i) _PIN(DIRECTION_PORT_##i)

  // Define stepper driver enable/disable output pin.
  #define STEPPER_DISABLE_PORT_0 D
  #define STEPPER_DISABLE_PORT_1 F
  #define STEPPER_DISABLE_PORT_2 K
  #if N_AXIS > 3
    #define STEPPER_DISABLE_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define STEPPER_DISABLE_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define STEPPER_DISABLE_PORT_5 B // Axis number 5 (Ramps Aux-3 D53)
  #endif
  #define STEPPER_DISABLE_BIT_0 7 // X Enable - Pin D38
  #define STEPPER_DISABLE_BIT_1 2 // Y Enable - Pin A2
  #define STEPPER_DISABLE_BIT_2 0 // Z Enable - Pin A8
  #if N_AXIS > 3
    #define STEPPER_DISABLE_BIT_3 2 // Axis number 4 Step - Pin D24
  #endif
  #if N_AXIS > 4
    #define STEPPER_DISABLE_BIT_4 7 // Axis number 5 Step - Pin D30
  #endif
  #if N_AXIS > 5
    #define STEPPER_DISABLE_BIT_5 0 // Axis number 5 Step - Pin D53
  #endif
  #define STEPPER_DISABLE_BIT(i) STEPPER_DISABLE_BIT_##i
  #define STEPPER_DISABLE_DDR(i) _DDR(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PORT(i) _PORT(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PIN(i) _PIN(STEPPER_DISABLE_PORT_##i)

  // Define homing/hard limit switch input pins and limit interrupt vectors.
  #define MIN_LIMIT_PORT_0 E
  #define MIN_LIMIT_PORT_1 J
  #define MIN_LIMIT_PORT_2 D
  #if N_AXIS > 3
    #define MIN_LIMIT_PORT_3 L
  #endif
  #if N_AXIS > 4
    #define MIN_LIMIT_PORT_4 L
  #endif
  #if N_AXIS > 5
    #define MIN_LIMIT_PORT_5 F // (Ramps Aux-1 D57)
  #endif
  #define MIN_LIMIT_BIT_0 5 // X Limit Min - Pin D3
  #define MIN_LIMIT_BIT_1 1 // Y Limit Min - Pin D14
  #define MIN_LIMIT_BIT_2 3 // Z Limit Min - Pin D18
  #if N_AXIS > 3
    #define MIN_LIMIT_BIT_3 7 // Axis number 4 : RAMPS AUX2 pin D42
  #endif
  #if N_AXIS > 4
    #define MIN_LIMIT_BIT_4 5 // Axis number 5 : RAMPS AUX2 pin D44
  #endif
  #if N_AXIS > 5
    #define MIN_LIMIT_BIT_5 3 // Axis number 6 : RAMPS AUX2 pin D57
  #endif
  #define _MIN_LIMIT_BIT(i) MIN_LIMIT_BIT_##i
  #define MIN_LIMIT_BIT(i) _MIN_LIMIT_BIT(i)
  #define MIN_LIMIT_DDR(i) _DDR(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PORT(i) _PORT(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PIN(i) _PIN(MIN_LIMIT_PORT_##i)

  #define MAX_LIMIT_PORT_0 E
  #define MAX_LIMIT_PORT_1 J
  #define MAX_LIMIT_PORT_2 D
  #if N_AXIS > 3
    #define MAX_LIMIT_PORT_3 G
  #endif
  #if N_AXIS > 4
    #define MAX_LIMIT_PORT_4 F
  #endif
  #if N_AXIS > 5
    #define MAX_LIMIT_PORT_5 F // (Ramps Aux-3 D58)
  #endif
  #define MAX_LIMIT_BIT_0 4 // X Limit Max - Pin D2
  #define MAX_LIMIT_BIT_1 0 // Y Limit Max - Pin D15
  #define MAX_LIMIT_BIT_2 2 // Z Limit Max - Pin D19
  #if N_AXIS > 3
    #define MAX_LIMIT_BIT_3 1 // Axis number 4 : RAMPS AUX2 pin D40
  #endif
  #if N_AXIS > 4
    #define MAX_LIMIT_BIT_4 5 // Axis number 5 : RAMPS AUX2 pin D59
  #endif
  #if N_AXIS > 5
    #define MAX_LIMIT_BIT_5 4 // Axis number 6 : RAMPS AUX2 pin D58
  #endif
  #define _MAX_LIMIT_BIT(i) MAX_LIMIT_BIT_##i
  #define MAX_LIMIT_BIT(i) _MAX_LIMIT_BIT(i)
  #define MAX_LIMIT_DDR(i) _DDR(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PORT(i) _PORT(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PIN(i) _PIN(MAX_LIMIT_PORT_##i)

  // Enable Hardware limit support for RAMPS without using interrupt...
  // Warning! bouncing switches can cause a state check like this to misread the pin.
  // When hard limits are triggered, they should be 100% reliable.
  // The RAMPS_HW_LIMIT is implemented inside the stepper driver interrupt. Depending of your
  // hardware, this can affect the max speed possibility of movments
  // Disabled by default for performance optimization, uncomment to enable.
  //#define ENABLE_RAMPS_HW_LIMITS

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRG
  #define SPINDLE_ENABLE_PORT     PORTG
  #define SPINDLE_ENABLE_BIT      5 // MEGA2560 Digital Pin 4 - Ramps 1.4 Servo 4 Signal pin (D4)
  #define SPINDLE_DIRECTION_DDR   DDRE
  #define SPINDLE_DIRECTION_PORT  PORTE
  #define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5 - Ramps 1.4 Servo 3 Signal pin (D5)

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRB
  #define COOLANT_FLOOD_PORT  PORTB
  #define COOLANT_FLOOD_BIT   4 // MEGA2560 Digital Pin 10 - Ramps 1.4 12v output
  #define COOLANT_MIST_DDR    DDRH
  #define COOLANT_MIST_PORT   PORTH
  #define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9 - Ramps 1.4 12v output

  // Define M62 - M65 Digital Output Control ports
  // D16 D17 D23 D25
  #define DIGITAL_OUTPUT_DDR_0  DDRH
  #define DIGITAL_OUTPUT_PORT_0 PORTH
  #define DIGITAL_OUTPUT_BIT_0  1 // MEGA2560 Digital Pin 16 - Ramps 1.4 AUX-4 D16
  #define DIGITAL_OUTPUT_DDR_1  DDRH
  #define DIGITAL_OUTPUT_PORT_1 PORTH
  #define DIGITAL_OUTPUT_BIT_1  0 // MEGA2560 Digital Pin 17 - Ramps 1.4 AUX-4 D17
  #define DIGITAL_OUTPUT_DDR_2  DDRA
  #define DIGITAL_OUTPUT_PORT_2 PORTA
  #define DIGITAL_OUTPUT_BIT_2  1 // MEGA2560 Digital Pin 23 - Ramps 1.4 AUX-4 D23
  #define DIGITAL_OUTPUT_DDR_3  DDRA
  #define DIGITAL_OUTPUT_PORT_3 PORTA
  #define DIGITAL_OUTPUT_BIT_3  3 // MEGA2560 Digital Pin 23 - Ramps 1.4 AUX-4 D25
  
  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRK
  #define CONTROL_PIN       PINK
  #define CONTROL_PORT      PORTK
  #define CONTROL_RESET_BIT         1  // Pin A9 - RAMPS Aux 2 Port
  #define CONTROL_FEED_HOLD_BIT     2  // Pin A10 - RAMPS Aux 2 Port
  #define CONTROL_CYCLE_START_BIT   3  // Pin A11 - RAMPS Aux 2 Port
  #define CONTROL_SAFETY_DOOR_BIT   4  // Pin A12 - RAMPS Aux 2 Port
  #define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
  #define CONTROL_INT_vect  PCINT2_vect
  #define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRK
  #define PROBE_PIN       PINK
  #define PROBE_PORT      PORTK
  #define PROBE_BIT       7  // MEGA2560 Analog Pin 15
  #define PROBE_MASK      (1<<PROBE_BIT)

  //-------------------------------------------------------------------------------------------------------
  // Advanced Configuration Below You should not need to touch these variables
  //-------------------------------------------------------------------------------------------------------

  // Spindle PWM configuration :
  // list of timers in Arduino Mega 2560
  // timer 0 (controls pin 13, 4);
  // timer 1 (controls pin 12, 11);
  // timer 2 (controls pin 10, 9);
  // timer 3 (controls pin 5, 3, 2);
  // timer 4 (controls pin 8, 7, 6);
  // 
  // Arduino pin number and the corresponding register for controlling the duty cycle :
  // Pin  Register
  //   2  OCR3B
  //   3  OCR3C
  //   4  OCR4C
  //   5  OCR3A
  //   6  OCR4A
  //   7  OCR4B
  //   8  OCR4C
  //   9  OCR2B
  //  10  OCR2A
  //  11  OCR1A
  //  12  OCR1B
  //  13  OCR0A
  //  44  OCR5C
  //  45  OCR5B
  //  46  OCR5A

  #if defined(SPINDLE_PWM_ON_D8)

    // Set Timer up to use TIMER4B which is attached to Digital Pin 8 - Ramps 1.4 12v output with heat sink
    #define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
    #ifndef SPINDLE_PWM_MIN_VALUE
      #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
    #endif
    #define SPINDLE_PWM_OFF_VALUE     0
    #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

    //Control Digital Pin 8
    #define SPINDLE_TCCRA_REGISTER    TCCR4A
    #define SPINDLE_TCCRB_REGISTER    TCCR4B
    #define SPINDLE_OCR_REGISTER      OCR4C
    #define SPINDLE_COMB_BIT          COM4C1

    // 1/8 Prescaler, 16-bit Fast PWM mode
    #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
    #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
    #define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
    #define SPINDLE_OCRA_TOP_VALUE  0x400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

    // Define spindle output pins.
    #define SPINDLE_PWM_DDR   DDRH
    #define SPINDLE_PWM_PORT  PORTH
    #define SPINDLE_PWM_BIT   5 // MEGA2560 Digital Pin 8

  #elif defined (SPINDLE_PWM_ON_D6)

    // Set Timer up to use TIMER4C which is attached to Digital Pin 6 - Ramps Servo 2
    #define SPINDLE_PWM_MAX_VALUE     255.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
    #ifndef SPINDLE_PWM_MIN_VALUE
      #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
    #endif
    #define SPINDLE_PWM_OFF_VALUE     0
    #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

    //Control Digital Pin 6 which is Servo 2 signal pin on Ramps 1.4 board
    #define SPINDLE_TCCRA_REGISTER    TCCR4A
    #define SPINDLE_TCCRB_REGISTER    TCCR4B
    #define SPINDLE_OCR_REGISTER      OCR4A
    #define SPINDLE_COMB_BIT          COM4A1

    // 1/8 Prescaler, 16-bit Fast PWM mode
    #define SPINDLE_TCCRA_INIT_MASK (1<<WGM41)
    #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
    #define SPINDLE_OCRA_REGISTER   ICR4 // 8-bit Fast PWM mode requires top reset value stored here.
    #define SPINDLE_OCRA_TOP_VALUE  0xFF // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

    // Define spindle output pins.
    #define SPINDLE_PWM_DDR   DDRH
    #define SPINDLE_PWM_PORT  PORTH
    #define SPINDLE_PWM_BIT   3 // MEGA2560 Digital Pin 6

  #else
    #error "You must define SPINDLE_PWM_ON_D8 or SPINDLE_PWM_ON_D6 or SPINDLE_PWM_ON_D11 in config.h"
  #endif

#endif // CPU_MAP_2560_RAMPS_BOARD

#ifdef CPU_MAP_2560_ULTIMAKER_BOARD //For Boxzy CNC Machine
  #include "nuts_bolts.h"

  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect

  // Define ports and pins
  #define DDR(port) DDR##port
  #define _DDR(port) DDR(port)
  #define PORT(port) PORT##port
  #define _PORT(port) PORT(port)
  #define PIN(pin) PIN##pin
  #define _PIN(pin) PIN(pin)

  // Define step pulse output pins.

  #define STEP_PORT_0 A
  #define STEP_PORT_1 C
  #define STEP_PORT_2 C
  #if N_AXIS > 3
    #define STEP_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define STEP_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define STEP_PORT_5 L // Axis number 6 (Ramps Aux-3 D49)
  #endif
  #define STEP_BIT_0 3  // X Step - Pin D25 (PA3)
  #define STEP_BIT_1 6  // Y Step - Pin D31 (PC6)
  #define STEP_BIT_2 0  // Z Step - Pin D37 (PC0)
  #if N_AXIS > 3
    #define STEP_BIT_3 4 // Axis number 4 Step - Pin D26
  #endif
  #if N_AXIS > 4
    #define STEP_BIT_4 1 // Axis number 5 Step - Pin D36
  #endif
  #if N_AXIS > 5
    #define STEP_BIT_5 0 // Axis number 6 Step - Pin D49
  #endif
  #define _STEP_BIT(i) STEP_BIT_##i
  #define STEP_BIT(i) _STEP_BIT(i)
  #define STEP_DDR(i) _DDR(STEP_PORT_##i)
  #define _STEP_PORT(i) _PORT(STEP_PORT_##i)
  #define STEP_PORT(i) _STEP_PORT(i)
  #define STEP_PIN(i) _PIN(STEP_PORT_##i)

  // Define step direction output pins.
  #define DIRECTION_PORT_0 A
  #define DIRECTION_PORT_1 C
  #define DIRECTION_PORT_2 G
  #if N_AXIS > 3
    #define DIRECTION_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define DIRECTION_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define DIRECTION_PORT_5 B // Axis number 6 (Ramps Aux-3 D51)
  #endif
  #define DIRECTION_BIT_0 1 // X Dir - Pin D23 (PA1)
  #define DIRECTION_BIT_1 4 // Y Dir - Pin D33 (PC4)
  #define DIRECTION_BIT_2 2 // Z Dir - Pin D39 (PG2)
  #if N_AXIS > 3
    #define DIRECTION_BIT_3 6 // Axis number 4 Step - Pin D28
  #endif
  #if N_AXIS > 4
    #define DIRECTION_BIT_4 3 // Axis number 5 Step - Pin D34
  #endif
  #if N_AXIS > 5
    #define DIRECTION_BIT_5 2 // Axis number 6 Step - Pin D51
  #endif
  #define _DIRECTION_BIT(i) DIRECTION_BIT_##i
  #define DIRECTION_BIT(i) _DIRECTION_BIT(i)
  #define DIRECTION_DDR(i) _DDR(DIRECTION_PORT_##i)
  #define _DIRECTION_PORT(i) _PORT(DIRECTION_PORT_##i)
  #define DIRECTION_PORT(i) _DIRECTION_PORT(i)
  #define DIRECTION_PIN(i) _PIN(DIRECTION_PORT_##i)

  // Define stepper driver enable/disable output pin.
  #define STEPPER_DISABLE_PORT_0 A
  #define STEPPER_DISABLE_PORT_1 A
  #define STEPPER_DISABLE_PORT_2 C
  #if N_AXIS > 3
    #define STEPPER_DISABLE_PORT_3 A // Axis number 4 (Ramps E0)
  #endif
  #if N_AXIS > 4
    #define STEPPER_DISABLE_PORT_4 C // Axis number 5 (Ramps E1)
  #endif
  #if N_AXIS > 5
    #define STEPPER_DISABLE_PORT_5 B // Axis number 5 (Ramps Aux-3 D53)
  #endif
  #define STEPPER_DISABLE_BIT_0 5 // X Enable - Pin D27 (PA5)
  #define STEPPER_DISABLE_BIT_1 7 // Y Enable - Pin D29 (PA7)
  #define STEPPER_DISABLE_BIT_2 2 // Z Enable - Pin D35 (PC2)
  #if N_AXIS > 3
    #define STEPPER_DISABLE_BIT_3 2 // Axis number 4 Step - Pin D24
  #endif
  #if N_AXIS > 4
    #define STEPPER_DISABLE_BIT_4 7 // Axis number 5 Step - Pin D30
  #endif
  #if N_AXIS > 5
    #define STEPPER_DISABLE_BIT_5 0 // Axis number 5 Step - Pin D53
  #endif
  #define STEPPER_DISABLE_BIT(i) STEPPER_DISABLE_BIT_##i
  #define STEPPER_DISABLE_DDR(i) _DDR(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PORT(i) _PORT(STEPPER_DISABLE_PORT_##i)
  #define STEPPER_DISABLE_PIN(i) _PIN(STEPPER_DISABLE_PORT_##i)

  // Define homing/hard limit switch input pins and limit interrupt vectors.
  #define MIN_LIMIT_PORT_0 A
  #define MIN_LIMIT_PORT_1 A
  #define MIN_LIMIT_PORT_2 C
  #if N_AXIS > 3
    #define MIN_LIMIT_PORT_3 L
  #endif
  #if N_AXIS > 4
    #define MIN_LIMIT_PORT_4 L
  #endif
  #if N_AXIS > 5
    #define MIN_LIMIT_PORT_5 F // (Ramps Aux-1 D57)
  #endif
  #define MIN_LIMIT_BIT_0 0 // X Limit Min - Pin D22 (PA0)
  #define MIN_LIMIT_BIT_1 4 // Y Limit Min - Pin D26 (PA4)
  #define MIN_LIMIT_BIT_2 7 // Z Limit Min - Pin D30 (PC7)
  #if N_AXIS > 3
    #define MIN_LIMIT_BIT_3 7 // Axis number 4 : RAMPS AUX2 pin D42
  #endif
  #if N_AXIS > 4
    #define MIN_LIMIT_BIT_4 5 // Axis number 5 : RAMPS AUX2 pin D44
  #endif
  #if N_AXIS > 5
    #define MIN_LIMIT_BIT_5 3 // Axis number 6 : RAMPS AUX2 pin D57
  #endif
  #define _MIN_LIMIT_BIT(i) MIN_LIMIT_BIT_##i
  #define MIN_LIMIT_BIT(i) _MIN_LIMIT_BIT(i)
  #define MIN_LIMIT_DDR(i) _DDR(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PORT(i) _PORT(MIN_LIMIT_PORT_##i)
  #define MIN_LIMIT_PIN(i) _PIN(MIN_LIMIT_PORT_##i)

  #define MAX_LIMIT_PORT_0 A
  #define MAX_LIMIT_PORT_1 A
  #define MAX_LIMIT_PORT_2 C
  #if N_AXIS > 3
    #define MAX_LIMIT_PORT_3 G
  #endif
  #if N_AXIS > 4
    #define MAX_LIMIT_PORT_4 F
  #endif
  #if N_AXIS > 5
    #define MAX_LIMIT_PORT_5 F // (Ramps Aux-3 D58)
  #endif
  #define MAX_LIMIT_BIT_0 2 // X Limit Max - Pin D24 (PA2)
  #define MAX_LIMIT_BIT_1 6 // Y Limit Max - Pin D31 (PA6)
  #define MAX_LIMIT_BIT_2 5 // Z Limit Max - Pin D32 (PC5)
  #if N_AXIS > 3
    #define MAX_LIMIT_BIT_3 1 // Axis number 4 : RAMPS AUX2 pin D40
  #endif
  #if N_AXIS > 4
    #define MAX_LIMIT_BIT_4 5 // Axis number 5 : RAMPS AUX2 pin D59
  #endif
  #if N_AXIS > 5
    #define MAX_LIMIT_BIT_5 4 // Axis number 6 : RAMPS AUX2 pin D58
  #endif
  #define _MAX_LIMIT_BIT(i) MAX_LIMIT_BIT_##i
  #define MAX_LIMIT_BIT(i) _MAX_LIMIT_BIT(i)
  #define MAX_LIMIT_DDR(i) _DDR(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PORT(i) _PORT(MAX_LIMIT_PORT_##i)
  #define MAX_LIMIT_PIN(i) _PIN(MAX_LIMIT_PORT_##i)

  // Enable Hardware limit support for RAMPS without using interrupt...
  // Warning! bouncing switches can cause a state check like this to misread the pin.
  // When hard limits are triggered, they should be 100% reliable.
  // The RAMPS_HW_LIMIT is implemented inside the stepper driver interrupt. Depending of your
  // hardware, this can affect the max speed possibility of movments
  // Disabled by default for performance optimization, uncomment to enable.
  //#define ENABLE_RAMPS_HW_LIMITS

  // Define spindle enable and spindle direction output pins.
  #define SPINDLE_ENABLE_DDR      DDRG
  #define SPINDLE_ENABLE_PORT     PORTG
  #define SPINDLE_ENABLE_BIT      5 // MEGA2560 Digital Pin 4 - Ramps 1.4 Servo 4 Signal pin (D4)
  #define SPINDLE_DIRECTION_DDR   DDRE
  #define SPINDLE_DIRECTION_PORT  PORTE
  #define SPINDLE_DIRECTION_BIT   3 // MEGA2560 Digital Pin 5 - Ramps 1.4 Servo 3 Signal pin (D5)

  // Define flood and mist coolant enable output pins.
  #define COOLANT_FLOOD_DDR   DDRB
  #define COOLANT_FLOOD_PORT  PORTB
  #define COOLANT_FLOOD_BIT   4 // MEGA2560 Digital Pin 10 - Ramps 1.4 12v output
  #define COOLANT_MIST_DDR    DDRH
  #define COOLANT_MIST_PORT   PORTH
  #define COOLANT_MIST_BIT    6 // MEGA2560 Digital Pin 9 - Ramps 1.4 12v output

  // Define M62 - M65 Digital Output Control ports
  // D16 D17 D23 D25
  #define DIGITAL_OUTPUT_DDR_0  DDRH
  #define DIGITAL_OUTPUT_PORT_0 PORTH
  #define DIGITAL_OUTPUT_BIT_0  1 // MEGA2560 Digital Pin 16 - Ramps 1.4 AUX-4 D16
  #define DIGITAL_OUTPUT_DDR_1  DDRH
  #define DIGITAL_OUTPUT_PORT_1 PORTH
  #define DIGITAL_OUTPUT_BIT_1  0 // MEGA2560 Digital Pin 17 - Ramps 1.4 AUX-4 D17
  #define DIGITAL_OUTPUT_DDR_2  DDRA
  #define DIGITAL_OUTPUT_PORT_2 PORTA
  #define DIGITAL_OUTPUT_BIT_2  1 // MEGA2560 Digital Pin 23 - Ramps 1.4 AUX-4 D23
  #define DIGITAL_OUTPUT_DDR_3  DDRA
  #define DIGITAL_OUTPUT_PORT_3 PORTA
  #define DIGITAL_OUTPUT_BIT_3  3 // MEGA2560 Digital Pin 23 - Ramps 1.4 AUX-4 D25
  
  // Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
  // NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
  #define CONTROL_DDR       DDRK
  #define CONTROL_PIN       PINK
  #define CONTROL_PORT      PORTK
  #define CONTROL_RESET_BIT         1  // Pin A9 - RAMPS Aux 2 Port
  #define CONTROL_FEED_HOLD_BIT     2  // Pin A10 - RAMPS Aux 2 Port
  #define CONTROL_CYCLE_START_BIT   3  // Pin A11 - RAMPS Aux 2 Port
  #define CONTROL_SAFETY_DOOR_BIT   4  // Pin A12 - RAMPS Aux 2 Port
  #define CONTROL_INT       PCIE2  // Pin change interrupt enable pin
  #define CONTROL_INT_vect  PCINT2_vect
  #define CONTROL_PCMSK     PCMSK2 // Pin change interrupt register
  #define CONTROL_MASK      ((1<<CONTROL_RESET_BIT)|(1<<CONTROL_FEED_HOLD_BIT)|(1<<CONTROL_CYCLE_START_BIT)|(1<<CONTROL_SAFETY_DOOR_BIT))

  // Define probe switch input pin.
  #define PROBE_DDR       DDRK
  #define PROBE_PIN       PINK
  #define PROBE_PORT      PORTK
  #define PROBE_BIT       7  // MEGA2560 Analog Pin 15
  #define PROBE_MASK      (1<<PROBE_BIT)

  //-------------------------------------------------------------------------------------------------------
  // Advanced Configuration Below You should not need to touch these variables
  //-------------------------------------------------------------------------------------------------------

  // Spindle PWM configuration :
  // list of timers in Arduino Mega 2560
  // timer 0 (controls pin 13, 4);
  // timer 1 (controls pin 12, 11);
  // timer 2 (controls pin 10, 9);
  // timer 3 (controls pin 5, 3, 2);
  // timer 4 (controls pin 8, 7, 6);
  // 
  // Arduino pin number and the corresponding register for controlling the duty cycle :
  // Pin  Register
  //   2  OCR3B
  //   3  OCR3C
  //   4  OCR4C
  //   5  OCR3A
  //   6  OCR4A
  //   7  OCR4B
  //   8  OCR4C
  //   9  OCR2B
  //  10  OCR2A
  //  11  OCR1A
  //  12  OCR1B
  //  13  OCR0A
  //  44  OCR5C
  //  45  OCR5B
  //  46  OCR5A

  #if defined(SPINDLE_PWM_ON_D8)

    // Set Timer up to use TIMER4B which is attached to Digital Pin 8 - Ramps 1.4 12v output with heat sink
    #define SPINDLE_PWM_MAX_VALUE     1024.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
    #ifndef SPINDLE_PWM_MIN_VALUE
      #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
    #endif
    #define SPINDLE_PWM_OFF_VALUE     0
    #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

    //Control Digital Pin 8
    #define SPINDLE_TCCRA_REGISTER    TCCR4A
    #define SPINDLE_TCCRB_REGISTER    TCCR4B
    #define SPINDLE_OCR_REGISTER      OCR4C
    #define SPINDLE_COMB_BIT          COM4C1

    // 1/8 Prescaler, 16-bit Fast PWM mode
    #define SPINDLE_TCCRA_INIT_MASK ((1<<WGM40) | (1<<WGM41))
    #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
    #define SPINDLE_OCRA_REGISTER   OCR4A // 16-bit Fast PWM mode requires top reset value stored here.
    #define SPINDLE_OCRA_TOP_VALUE  0x400 // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

    // Define spindle output pins.
    #define SPINDLE_PWM_DDR   DDRH
    #define SPINDLE_PWM_PORT  PORTH
    #define SPINDLE_PWM_BIT   5 // MEGA2560 Digital Pin 8

  #elif defined (SPINDLE_PWM_ON_D6)

    // Set Timer up to use TIMER4C which is attached to Digital Pin 6 - Ramps Servo 2
    #define SPINDLE_PWM_MAX_VALUE     255.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
    #ifndef SPINDLE_PWM_MIN_VALUE
      #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
    #endif
    #define SPINDLE_PWM_OFF_VALUE     0
    #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

    //Control Digital Pin 6 which is Servo 2 signal pin on Ramps 1.4 board
    #define SPINDLE_TCCRA_REGISTER    TCCR4A
    #define SPINDLE_TCCRB_REGISTER    TCCR4B
    #define SPINDLE_OCR_REGISTER      OCR4A
    #define SPINDLE_COMB_BIT          COM4A1

    // 1/8 Prescaler, 16-bit Fast PWM mode
    #define SPINDLE_TCCRA_INIT_MASK (1<<WGM41)
    #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
    #define SPINDLE_OCRA_REGISTER   ICR4 // 8-bit Fast PWM mode requires top reset value stored here.
    #define SPINDLE_OCRA_TOP_VALUE  0xFF // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

    // Define spindle output pins.
    #define SPINDLE_PWM_DDR   DDRH
    #define SPINDLE_PWM_PORT  PORTH
    #define SPINDLE_PWM_BIT   3 // MEGA2560 Digital Pin 6

  #elif defined (SPINDLE_PWM_ON_D7)

    // Set Timer up to use TIMER4C which is attached to Digital Pin D7 on Boxzy
    #define SPINDLE_PWM_MAX_VALUE     255.0 // Translates to about 1.9 kHz PWM frequency at 1/8 prescaler
    #ifndef SPINDLE_PWM_MIN_VALUE
      #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
    #endif
    #define SPINDLE_PWM_OFF_VALUE     0
    #define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

    //Control Digital Pin 7 which is Servo 2 signal pin on Ramps 1.4 board
    #define SPINDLE_TCCRA_REGISTER    TCCR4A
    #define SPINDLE_TCCRB_REGISTER    TCCR4B
    #define SPINDLE_OCR_REGISTER      OCR4B
    #define SPINDLE_COMB_BIT          COM4B1

    // 1/8 Prescaler, 16-bit Fast PWM mode
    #define SPINDLE_TCCRA_INIT_MASK (1<<WGM41)
    #define SPINDLE_TCCRB_INIT_MASK ((1<<WGM42) | (1<<WGM43) | (1<<CS41))
    #define SPINDLE_OCRA_REGISTER   ICR4 // 8-bit Fast PWM mode requires top reset value stored here.
    #define SPINDLE_OCRA_TOP_VALUE  0xFF // PWM counter reset value. Should be the same as PWM_MAX_VALUE in hex.

    // Define spindle output pins.
    #define SPINDLE_PWM_DDR   DDRH
    #define SPINDLE_PWM_PORT  PORTH
    #define SPINDLE_PWM_BIT   4 // MEGA2560 Digital Pin 7

  #else
    #error "You must define SPINDLE_PWM_ON_D8 or SPINDLE_PWM_ON_D6 or SPINDLE_PWM_ON_D11 in config.h"
#endif // CPU_MAP_2560_BOXZY_BOARD


#endif
#endif