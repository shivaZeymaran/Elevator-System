/********************************* Final Project ********************************/
/*************************** Real-time Embedded Systems *************************/
/******************************** Elevator System *******************************/
/************************* By Shiva Zeymaran & Sara Mahmoodi ********************/
/********************************* Summer 2020 **********************************/

//typedef
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

//first library : arduinoAVRScheduler.h
#ifndef _ARDUINOSCHEDULER_H_
#define _ARDUINOSCHEDULER_H_

#include "Arduino.h"
#ifdef __cplusplus
extern "C" {
#endif
    
void configureArduinoAVRTimer(void);
boolean MW_Arduino_Loop(void);
void rt_OneStep(void);
void disable_rt_OneStep(void);

#ifdef __cplusplus
}
#endif

#define INIT_TIMER_VAL  MW_TIMERCOUNT

#if (defined(MW_TIMERID) && (MW_TIMERID == 1))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==1024)
             #define SETUP_PRESCALER   TCCR1B |= ((1<<CS12) | (1<<CS10)); \
                                       TCCR1B &= ~((1<<CS11))
        #elif (MW_PRESCALAR==256)
             #define SETUP_PRESCALER   TCCR1B |= ((1<<CS12)); \
                                       TCCR1B &= ~((1<<CS11) | (1<<CS10))
        #elif (MW_PRESCALAR==64)
             #define SETUP_PRESCALER   TCCR1B |= ((1<<CS11) | (1<<CS10)); \
                                       TCCR1B &= ~((1<<CS12))
        #elif (MW_PRESCALAR==8)
             #define SETUP_PRESCALER   TCCR1B |= ((1<<CS11)); \
                                       TCCR1B &= ~((1<<CS12) | (1<<CS10))
        #elif (MW_PRESCALAR==1)
             #define SETUP_PRESCALER   TCCR1B |= ((1<<CS10)); \
                                       TCCR1B &= ~((1<<CS12) | (1<<CS11))
        #endif 
    #endif
                                        
      #define INTERRUPT_VECTOR    TIMER1_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK1 &= ~(1<<TOIE1)
      #define ENABLE_SCHEDULER_INT()        TIMSK1 |= (1<<TOIE1)
      #define TIMER_NORMAL_MODE   TCCR1A &= ~((1<<WGM11) | (1<<WGM10)); \
                                  TCCR1B &= ~((1<<WGM13) | (1<<WGM12))
      #define RESET_TIMER         TCNT1 = INIT_TIMER_VAL

#elif (defined(MW_TIMERID) && (MW_TIMERID == 2))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==1024)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS22) | (1<<CS21) | (1<<CS20))
                                  
        #elif (MW_PRESCALAR==256)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS22) | (1<<CS21)); \
                                        TCCR2B &= ~(1<<CS20)
        #elif (MW_PRESCALAR==128)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS22) | (1<<CS20)); \
                                        TCCR2B &= ~((1<<CS21))
        #elif (MW_PRESCALAR==64)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS22)); \
                                        TCCR2B &= ~((1<<CS21) | (1<<CS20))
        #elif (MW_PRESCALAR==32)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS21) | (1<<CS20)); \
                                        TCCR2B &= ~((1<<CS22))
        #elif (MW_PRESCALAR==8)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS21)); \
                                        TCCR2B &= ~((1<<CS22) | (1<<CS20))
        #elif (MW_PRESCALAR==1)
              #define SETUP_PRESCALER   TCCR2B |= ((1<<CS20)); \
                                        TCCR2B &= ~((1<<CS22) | (1<<CS21))
        #endif 
    #endif

      #define INTERRUPT_VECTOR    TIMER2_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK2 &= ~(1<<TOIE2)
      #define ENABLE_SCHEDULER_INT()        TIMSK2 |= (1<<TOIE2)
      #define TIMER_NORMAL_MODE   TCCR2A &= ~((1<<WGM21) | (1<<WGM20)); \
                                  TCCR2B &= ~(1<<WGM22)
      #define RESET_TIMER         TCNT2 = INIT_TIMER_VAL

#elif (defined(MW_TIMERID) && (MW_TIMERID == 3))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==1024)
              #define SETUP_PRESCALER   TCCR3B |= ((1<<CS32) | (1<<CS30)); \
                                        TCCR3B &= ~((1<<CS31))
        #elif (MW_PRESCALAR==256)
              #define SETUP_PRESCALER   TCCR3B |= ((1<<CS32)); \
                                        TCCR3B &= ~((1<<CS31) | (1<<CS30))
        #elif (MW_PRESCALAR==64)
              #define SETUP_PRESCALER   TCCR3B |= ((1<<CS31) | (1<<CS30)); \
                                        TCCR3B &= ~((1<<CS32))
        #elif (MW_PRESCALAR==8)
              #define SETUP_PRESCALER   TCCR3B |= ((1<<CS31)); \
                                        TCCR3B &= ~((1<<CS32) | (1<<CS30))
        #elif (MW_PRESCALAR==1)
              #define SETUP_PRESCALER   TCCR3B |= ((1<<CS30)); \
                                        TCCR3B &= ~((1<<CS32) | (1<<CS31))
        #endif 
    #endif

      #define INTERRUPT_VECTOR    TIMER3_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK3 &= ~(1<<TOIE3)
      #define ENABLE_SCHEDULER_INT()        TIMSK3 |= (1<<TOIE3)
      #define TIMER_NORMAL_MODE   TCCR3A &= ~((1<<WGM31) | (1<<WGM30)); \
                                  TCCR3B &= ~((1<<WGM33) | (1<<WGM32))
      #define RESET_TIMER         TCNT3 = INIT_TIMER_VAL

#elif (defined(MW_TIMERID) && (MW_TIMERID == 4))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==1024)
              #define SETUP_PRESCALER   TCCR4B |= ((1<<CS42) | (1<<CS40)); \
                                        TCCR4B &= ~((1<<CS41))
        #elif (MW_PRESCALAR==256)
              #define SETUP_PRESCALER   TCCR4B |= ((1<<CS42)); \
                                        TCCR4B &= ~((1<<CS41) | (1<<CS40))
        #elif (MW_PRESCALAR==64)
              #define SETUP_PRESCALER   TCCR4B |= ((1<<CS41) | (1<<CS40)); \
                                        TCCR4B &= ~((1<<CS42))
        #elif (MW_PRESCALAR==8)
              #define SETUP_PRESCALER   TCCR4B |= ((1<<CS41)); \
                                        TCCR4B &= ~((1<<CS42) | (1<<CS40))
        #elif (MW_PRESCALAR==1)
              #define SETUP_PRESCALER   TCCR4B |= ((1<<CS40)); \
                                        TCCR4B &= ~((1<<CS42) | (1<<CS41))
        #endif 
    #endif

      #define INTERRUPT_VECTOR    TIMER4_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK4 &= ~(1<<TOIE4)
      #define ENABLE_SCHEDULER_INT()        TIMSK4 |= (1<<TOIE4)
      #define TIMER_NORMAL_MODE   TCCR4A &= ~((1<<WGM41) | (1<<WGM40)); \
                                  TCCR4B &= ~((1<<WGM43) | (1<<WGM42))
      #define RESET_TIMER         TCNT4 = INIT_TIMER_VAL

#elif (defined(MW_TIMERID) && (MW_TIMERID == 5))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==1024)
              #define SETUP_PRESCALER   TCCR5B |= ((1<<CS52) | (1<<CS50)); \
                                        TCCR5B &= ~((1<<CS51))
        #elif (MW_PRESCALAR==256)
              #define SETUP_PRESCALER   TCCR5B |= ((1<<CS52)); \
                                        TCCR5B &= ~((1<<CS51) | (1<<CS50))
        #elif (MW_PRESCALAR==64)
              #define SETUP_PRESCALER   TCCR5B |= ((1<<CS51) | (1<<CS50)); \
                                        TCCR5B &= ~((1<<CS52))
        #elif (MW_PRESCALAR==8)
              #define SETUP_PRESCALER   TCCR5B |= ((1<<CS51)); \
                                        TCCR5B &= ~((1<<CS52) | (1<<CS50))
        #elif (MW_PRESCALAR==1)
              #define SETUP_PRESCALER   TCCR5B |= ((1<<CS50)); \
                                        TCCR5B &= ~((1<<CS52) | (1<<CS51))
        #endif 
    #endif

      #define INTERRUPT_VECTOR    TIMER5_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK5 &= ~(1<<TOIE5)
      #define ENABLE_SCHEDULER_INT()        TIMSK5 |= (1<<TOIE5)
      #define TIMER_NORMAL_MODE   TCCR5A &= ~((1<<WGM51) | (1<<WGM50)); \
                                  TCCR5B &= ~((1<<WGM53) | (1<<WGM52))
      #define RESET_TIMER         TCNT5 = INIT_TIMER_VAL

#elif (defined(MW_TIMERID) && (MW_TIMERID == 6))
    #if (defined(MW_PRESCALAR))
        #if (MW_PRESCALAR==16384)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(1<<CS42) | (1<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==8192)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(1<<CS42) | (1<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==4096)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(1<<CS42) | (0<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==2048)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(1<<CS42) | (0<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==1024)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(0<<CS42) | (1<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==512)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(0<<CS42) | (1<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==256)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(0<<CS42) | (0<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==128)
          #define SETUP_PRESCALER   TCCR4B = (1<<CS43) |(0<<CS42) | (0<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==64)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(1<<CS42) | (1<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==32)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(1<<CS42) | (1<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==16)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(1<<CS42) | (0<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==8)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(1<<CS42) | (0<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==4)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(0<<CS42) | (1<<CS41) | (1<<CS40)
        #elif (MW_PRESCALAR==2)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(0<<CS42) | (1<<CS41) | (0<<CS40)
        #elif (MW_PRESCALAR==1)
          #define SETUP_PRESCALER   TCCR4B = (0<<CS43) |(0<<CS42) | (0<<CS41) | (1<<CS40)
        #endif 
    #endif
                                  
      #define INTERRUPT_VECTOR    TIMER4_OVF_vect
      #define DISABLE_SCHEDULER_INT()       TIMSK4 &= ~(1<<TOIE4)
      #define ENABLE_SCHEDULER_INT()        TIMSK4 |= (1<<TOIE4)
      #define TIMER_NORMAL_MODE   TCCR4A = TCCR4C = TCCR4D = TCCR4E = 0
      #define RESET_TIMER         TCNT4 = 0
      #define LOAD_COMPARE_VALUE  TC4H = ((INIT_TIMER_VAL >> 8) & 0xFF); \
                                  OCR4C = (INIT_TIMER_VAL & 0xFF) 
                                      
#endif

#endif // _ARDUINOSCHEDULER_H_
//second library : MW_target_hardware_resources.h

#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 0
#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Arduino Uno
#define MW_CONNECTIONINFO_SERIAL_IPADDRESS codertarget.arduinobase.registry.getLoopbackIP;
#define MW_CONNECTIONINFO_SERIAL_PORT 17725
#define MW_CONNECTIONINFO_SERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Ethernet')
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_WIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_WIFI_PORT 17725
#define MW_CONNECTIONINFO_WIFI_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION Serial
#define MW_EXTMODE_COMPORTBAUD 921600
#define MW_RTOS Baremetal
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_HOSTCOMPORT_SET_HOST_COM_PORT 0
#define MW_HOSTCOMPORT_COM_PORT_NUMBER 1
#define MW_SIMULINKIO_ENABLE_SIMULINKIO 1
#define MW_OVERRUNDETECTION_ENABLE_OVERRUN_DETECTION 0
#define MW_OVERRUNDETECTION_DIGITAL_OUTPUT_TO_SET_ON_OVERRUN 13
#define MW_ANALOGINREFVOLTAGE_ANALOG_INPUT_REFERENCE_VOLTAGE 0.000000
#define MW_SERIAL_SERIAL0_BAUD_RATE 3
#define MW_I2C_I2C0BUSSPEEDHZ 100000
#define MW_SPI_SPI_CLOCK_OUT_FREQUENCY 1
#define MW_SPI_SPI_MODE 0
#define MW_SPI_SPI_BITORDER 0
#define MW_ETHERNET_DISABLE_DHCP_ETHERNET 0
#define MW_ETHERNET_LOCAL_IP_ADDRESS 192.168.0.20
#define MW_ETHERNET_LOCAL_MAC_ADDRESS DE:AD:BE:EF:FE:ED
#define MW_WIFI_WIFI_HARDWARE 0
#define MW_WIFI_DISABLE_DHCP_WIFI 0
#define MW_WIFI_WIFI_IP_ADDRESS 192.168.1.20
#define MW_WIFI_WIFI_SSID yourNetwork
#define MW_WIFI_SET_WIFI_ENCRYPTION 0
#define MW_WIFI_WIFI_WEP_KEY D0D0DEADF00DABBADEAFBEADED
#define MW_WIFI_WIFI_WEP_KEY_INDEX 0
#define MW_WIFI_WIFI_WPA_PASSWORD secretPassword
#define MW_WIFI_WIFI_ESP8266_HW_SERIAL_PORT 0
#define MW_THINGSPEAK_ENABLE_CUSTOMSERVER 48
#define MW_THINGSPEAK_IP_ADDRESS 184.106.153.149
#define MW_THINGSPEAK_PORT 80
#define MW_DATAVERSION 2016.02

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
//third library : rtwtypes.h

#ifndef RTWTYPES_H
#define RTWTYPES_H

/* Logical type definitions */
#if (!defined(__cplusplus))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

/*=======================================================================*
 * Target hardware information
 *   Device type: Atmel->AVR
 *   Number of bits:     char:   8    short:   16    int:  16
 *                       long:  32    long long:  64
 *                       native word size:   8
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef int int16_T;
typedef unsigned int uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;
typedef long long int64_T;
typedef unsigned long long uint64_T;

/*===========================================================================*
 * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *
 *                           ulong_T, ulonglong_T.                           *
 *===========================================================================*/
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef unsigned long long ulonglong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MAX_int32_T                    ((int32_T)(2147483647L))
#define MIN_int32_T                    ((int32_T)(-2147483647L-1L))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFUL))
#define MAX_int64_T                    ((int64_T)(9223372036854775807LL))
#define MIN_int64_T                    ((int64_T)(-9223372036854775807LL-1LL))
#define MAX_uint64_T                   ((uint64_T)(0xFFFFFFFFFFFFFFFFULL))

/* Block D-Work pointer type */
typedef void * pointer_T;

#endif                                 /* RTWTYPES_H */

//fourth library
#include <stddef.h>
//fifth library : rtmodel.h
#ifndef RTW_HEADER_rtmodel_h_
#define RTW_HEADER_rtmodel_h_
/* Macros generated for backwards compatibility  */
#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif
#endif 
/*******************************************  Main Code  ***********************************************/

/*********** code.h generated by matlab **********/

#ifndef RTW_HEADER_elevator_2017b_h_
#define RTW_HEADER_elevator_2017b_h_
#include <stddef.h>
#ifndef elevator_2017b_COMMON_INCLUDES_
# define elevator_2017b_COMMON_INCLUDES_
#endif                                 /* elevator_2017b_COMMON_INCLUDES_ */


/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define elevator_2017b_M               (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T downward;                     /* '<S6>/position processor ' */
  real_T upward;                       /* '<S6>/position processor ' */
  real_T at_floor;                     /* '<S6>/position processor ' */
  real_T pos;                          /* '<S6>/position processor ' */
  real_T speed;                        /* '<S6>/position processor ' */
  real_T door_open;                    /* '<S6>/bottun processor ' */
  real_T two_pressed;                  /* '<S6>/bottun processor ' */
  real_T three_pressed;                /* '<S6>/bottun processor ' */
  real_T stop_pressed;                 /* '<S6>/bottun processor ' */
  real_T one_pressed;                  /* '<S6>/bottun processor ' */
  real_T stop;                         /* '<S5>/Chart' */
  real_T dest;                         /* '<S4>/Chart' */
  real_T stop_i;                       /* '<S4>/Chart' */
  real_T door_open_c;                  /* '<S4>/Chart' */
  real_T upward_b;                     /* '<S4>/Chart' */
  real_T downward_p;                   /* '<S4>/Chart' */
  real_T downward_final;               /* '<S1>/Chart' */
  real_T upward_final;                 /* '<S1>/Chart' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S15>/Integrator' */
  real_T Integrator_DSTATE_a;          /* '<S27>/Integrator' */
  real_T counter;                      /* '<S6>/position processor ' */
  real_T last;                         /* '<S6>/position processor ' */
  real_T last_counter;                 /* '<S6>/position processor ' */
  real_T two_open;                     /* '<S4>/Chart' */
  real_T one_pressed_m;                /* '<S4>/Chart' */
  real_T two_pressed_c;                /* '<S4>/Chart' */
  real_T three_pressed_k;              /* '<S4>/Chart' */
  uint32_T temporalCounter_i1;         /* '<S4>/Chart' */
  uint16_T temporalCounter_i1_l;       /* '<S6>/position processor ' */
  int8_T Integrator_PrevResetState;    /* '<S15>/Integrator' */
  int8_T Integrator_PrevResetState_j;  /* '<S27>/Integrator' */
  uint8_T is_active_c1_elevator_2017b; /* '<S6>/position processor ' */
  uint8_T is_c1_elevator_2017b;        /* '<S6>/position processor ' */
  uint8_T is_pos_cal;                  /* '<S6>/position processor ' */
  uint8_T temporalCounter_i2;          /* '<S6>/position processor ' */
  uint8_T is_active_c3_elevator_2017b; /* '<S6>/bottun processor ' */
  uint8_T is_c3_elevator_2017b;        /* '<S6>/bottun processor ' */
  uint8_T temporalCounter_i1_p;        /* '<S6>/bottun processor ' */
  uint8_T is_active_c2_elevator_2017b; /* '<S5>/Chart' */
  uint8_T is_c2_elevator_2017b;        /* '<S5>/Chart' */
  uint8_T temporalCounter_i1_b;        /* '<S5>/Chart' */
  uint8_T is_active_c4_elevator_2017b; /* '<S4>/Chart' */
  uint8_T is_c4_elevator_2017b;        /* '<S4>/Chart' */
  uint8_T is_plan_handle;              /* '<S4>/Chart' */
  uint8_T is_active_c5_elevator_2017b; /* '<S1>/Chart' */
  uint8_T is_c5_elevator_2017b;        /* '<S1>/Chart' */
  boolean_T Initial_FirstOutputTime;   /* '<S15>/Initial' */
  boolean_T Initial_FirstOutputTime_g; /* '<S27>/Initial' */
} DW;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Inport;                       /* '<Root>/Inport' */
  real_T Inport1;                      /* '<Root>/Inport1' */
  real_T Inport2;                      /* '<Root>/Inport2' */
  real_T Inport3;                      /* '<Root>/Inport3' */
  real_T Inport4;                      /* '<Root>/Inport4' */
  real_T Inport5;                      /* '<Root>/Inport5' */
  real_T Inport6;                      /* '<Root>/Inport6' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T Out2;                      /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void elevator_2017b_initialize(void);
extern void elevator_2017b_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S20>/Multiport Switch' : Eliminated due to constant selection input
 * Block '<S8>/Constant10' : Unused code path elimination
 * Block '<S8>/Constant2' : Unused code path elimination
 * Block '<S8>/Constant6' : Unused code path elimination
 * Block '<S18>/Bias1' : Unused code path elimination
 * Block '<S19>/Compare' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S18>/Initial' : Unused code path elimination
 * Block '<S18>/Integrator' : Unused code path elimination
 * Block '<S12>/Constant2' : Unused code path elimination
 * Block '<S12>/Switch' : Unused code path elimination
 * Block '<S13>/Constant2' : Unused code path elimination
 * Block '<S13>/Switch' : Unused code path elimination
 * Block '<S8>/Saturation' : Unused code path elimination
 * Block '<S8>/Sum3' : Unused code path elimination
 * Block '<S8>/Sum4' : Unused code path elimination
 * Block '<S8>/Sum5' : Unused code path elimination
 * Block '<S20>/Constant10' : Unused code path elimination
 * Block '<S20>/Constant2' : Unused code path elimination
 * Block '<S20>/Constant6' : Unused code path elimination
 * Block '<S30>/Bias1' : Unused code path elimination
 * Block '<S31>/Compare' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S30>/Initial' : Unused code path elimination
 * Block '<S30>/Integrator' : Unused code path elimination
 * Block '<S24>/Constant2' : Unused code path elimination
 * Block '<S24>/Switch' : Unused code path elimination
 * Block '<S25>/Constant2' : Unused code path elimination
 * Block '<S25>/Switch' : Unused code path elimination
 * Block '<S20>/Saturation' : Unused code path elimination
 * Block '<S20>/Sum3' : Unused code path elimination
 * Block '<S20>/Sum4' : Unused code path elimination
 * Block '<S20>/Sum5' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'elevator_2017b'
 * '<S1>'   : 'elevator_2017b/Actuator module'
 * '<S2>'   : 'elevator_2017b/PWM Generator'
 * '<S3>'   : 'elevator_2017b/PWM Generator1'
 * '<S4>'   : 'elevator_2017b/Planning module'
 * '<S5>'   : 'elevator_2017b/Safety module'
 * '<S6>'   : 'elevator_2017b/Sensor module'
 * '<S7>'   : 'elevator_2017b/Actuator module/Chart'
 * '<S8>'   : 'elevator_2017b/PWM Generator/Carrier counter'
 * '<S9>'   : 'elevator_2017b/PWM Generator/Compare To Zero'
 * '<S10>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S11>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S12>'  : 'elevator_2017b/PWM Generator/Carrier counter/Limitation'
 * '<S13>'  : 'elevator_2017b/PWM Generator/Carrier counter/Limitation1'
 * '<S14>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Continuous'
 * '<S15>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S16>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S17>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Continuous'
 * '<S18>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S19>'  : 'elevator_2017b/PWM Generator/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S20>'  : 'elevator_2017b/PWM Generator1/Carrier counter'
 * '<S21>'  : 'elevator_2017b/PWM Generator1/Compare To Zero'
 * '<S22>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)'
 * '<S23>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1'
 * '<S24>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Limitation'
 * '<S25>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Limitation1'
 * '<S26>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Continuous'
 * '<S27>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete'
 * '<S28>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)/Discrete/Compare To Constant'
 * '<S29>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Continuous'
 * '<S30>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete'
 * '<S31>'  : 'elevator_2017b/PWM Generator1/Carrier counter/Integrator with Wrapped State (Discrete or Continuous)1/Discrete/Compare To Constant'
 * '<S32>'  : 'elevator_2017b/Planning module/Chart'
 * '<S33>'  : 'elevator_2017b/Safety module/Chart'
 * '<S34>'  : 'elevator_2017b/Sensor module/bottun processor '
 * '<S35>'  : 'elevator_2017b/Sensor module/position processor '
 */
#endif                                 /* RTW_HEADER_elevator_2017b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
/*********** End of code.h generated by matlab ***********/

/*********** code.c generated by matlab **********/

/* Named constants for Chart: '<S1>/Chart' */                // Actuator States
#define IN_move                        ((uint8_T)1U)
#define IN_stop                        ((uint8_T)2U)

/* Named constants for Chart: '<S4>/Chart' */                // Planning States
#define IN_floor1                      ((uint8_T)1U)
#define IN_floor2                      ((uint8_T)2U)
#define IN_floor3                      ((uint8_T)3U)
#define IN_init                        ((uint8_T)1U)
#define IN_move_down                   ((uint8_T)4U)
#define IN_move_up                     ((uint8_T)5U)
#define IN_planning_cal                ((uint8_T)2U)

/* Named constants for Chart: '<S5>/Chart' */                // Safete States
#define IN_both_dir_stop               ((uint8_T)1U)
#define IN_door_stop                   ((uint8_T)2U)
#define IN_down_stop                   ((uint8_T)3U)
#define IN_monitor                     ((uint8_T)4U)
#define IN_speed_stop                  ((uint8_T)5U)
#define IN_stop_button                 ((uint8_T)6U)
#define IN_top_stop                    ((uint8_T)7U)

/* Named constants for Chart: '<S6>/bottun processor ' */    // Button States
#define IN_Reset                       ((uint8_T)1U)
#define IN_door_bounce                 ((uint8_T)2U)
#define IN_door_status                 ((uint8_T)3U)
#define IN_floor_bounce                ((uint8_T)4U)
#define IN_floor_pos                   ((uint8_T)5U)
#define IN_one_bounce                  ((uint8_T)6U)
#define IN_one_press                   ((uint8_T)7U)
#define IN_stop_bounce                 ((uint8_T)8U)
#define IN_stop_press                  ((uint8_T)9U)
#define IN_three_bounce                ((uint8_T)10U)
#define IN_three_press                 ((uint8_T)11U)
#define IN_two_bounce                  ((uint8_T)12U)
#define IN_two_press                   ((uint8_T)13U)

/* Named constants for Chart: '<S6>/position processor ' */  // Position States
#define IN_between_1_2                 ((uint8_T)1U)
#define IN_between_2_3                 ((uint8_T)2U)
#define IN_floor_1                     ((uint8_T)3U)
#define IN_floor_2                     ((uint8_T)4U)
#define IN_floor_3                     ((uint8_T)5U)
#define IN_pos_detection               ((uint8_T)2U)
#define IN_read_pulse_1_2              ((uint8_T)6U)
#define IN_read_pulse_2_3              ((uint8_T)7U)

/* Block signals and states (auto storage) */
DW rtDW;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/*******************************************  Step & Init  ***********************************************/

#define floor_hight  5.0            // 400.0
#define floor_hight2 10.0           // 800.0
#define tooCloseUpToFloor2 3.0      // 200.0
#define tooCloseDownToFloor2 7.0    // 600.0
#define waitTimeAtFloor 10UL        // 100000UL
boolean_T stopOut;


/* Forward declaration for local functions */
static void pos_detection(const real_T *UnitDelay);
static void plan_handle(void);

/* Function for Chart: '<S6>/position processor ' */
static void pos_detection(const real_T *UnitDelay)
{
  if (rtDW.temporalCounter_i1_l >= 20000U) {
    rtDW.temporalCounter_i1_l = 0U;
    rtDW.speed = rtDW.pos - rtDW.last_counter;
    rtDW.last_counter = rtDW.pos;
  }

  switch (rtDW.is_pos_cal) {
   case IN_between_1_2:
    rtDW.at_floor = -1.0;

    /* Inport: '<Root>/Inport6' */
    if (rtDW.last != rtU.Inport6) {   // (rtDW.temporalCounter_i2 >= 60U) && 
      rtDW.is_pos_cal = IN_read_pulse_1_2;
      rtDW.counter++;
      rtDW.last = rtU.Inport6;
    } else {
      if (rtDW.last == rtU.Inport6) {   // (rtDW.temporalCounter_i2 >= 60U) &&
        rtDW.is_pos_cal = IN_between_1_2;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.at_floor = -1.0;
        rtDW.pos = (floor_hight - rtDW.counter) * rtDW.downward + rtDW.upward *
          rtDW.counter;
      }
    }
    break;

   case IN_between_2_3:
    rtDW.at_floor = -1.0;

    /* Inport: '<Root>/Inport6' */
    if (rtDW.last != rtU.Inport6) {    // (rtDW.temporalCounter_i2 >= 60U) &&
      rtDW.is_pos_cal = IN_read_pulse_2_3;
      rtDW.counter++;
      rtDW.last = rtU.Inport6;
    }
    break;

   case IN_floor_1:
    rtDW.at_floor = 1.0;
    if ((*UnitDelay == 2.0) || (*UnitDelay == 3.0)) {
      rtDW.upward = 1.0;
      rtDW.downward = 0.0;
      rtDW.is_pos_cal = IN_between_1_2;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.at_floor = -1.0;
      rtDW.pos = (floor_hight - rtDW.counter) * rtDW.downward + rtDW.upward *
        rtDW.counter;
    } else {
      rtDW.upward = 0.0;
      rtDW.downward = 0.0;
    }
    break;

   case IN_floor_2:
    rtDW.at_floor = 2.0;
    if (*UnitDelay == 1.0) {
      rtDW.upward = 0.0;
      rtDW.downward = 1.0;
      rtDW.is_pos_cal = IN_between_1_2;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.at_floor = -1.0;
      rtDW.pos = (floor_hight - rtDW.counter) * rtDW.downward + rtDW.upward *
        rtDW.counter;
    } else if (*UnitDelay == 3.0) {
      rtDW.upward = 1.0;
      rtDW.downward = 0.0;
      rtDW.is_pos_cal = IN_between_2_3;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.at_floor = -1.0;
      rtDW.pos = (rtDW.counter + floor_hight) * rtDW.upward + (floor_hight2 - rtDW.counter) *
        rtDW.downward;
    } else {
      rtDW.upward = 0.0;
      rtDW.downward = 0.0;
    }
    break;

   case IN_floor_3:
    rtDW.at_floor = 3.0;
    if ((*UnitDelay == 2.0) || (*UnitDelay == 1.0)) {
      rtDW.upward = 0.0;
      rtDW.downward = 1.0;
      rtDW.is_pos_cal = IN_between_2_3;
      rtDW.temporalCounter_i2 = 0U;
      rtDW.at_floor = -1.0;
      rtDW.pos = (rtDW.counter + floor_hight) * rtDW.upward + (floor_hight2 - rtDW.counter) *
        rtDW.downward;
    } else {
      rtDW.upward = 0.0;
      rtDW.downward = 0.0;
    }
    break;

   case IN_read_pulse_1_2:
    if ((rtDW.counter == floor_hight) && (rtDW.downward == 1.0)) {
      rtDW.is_pos_cal = IN_floor_1;
      rtDW.counter = 0.0;
      rtDW.at_floor = 1.0;
      rtDW.pos = 0.0;
    } else if ((rtDW.counter == floor_hight) && (rtDW.upward == 1.0)) {
      rtDW.is_pos_cal = IN_floor_2;
      rtDW.counter = 0.0;
      rtDW.at_floor = 2.0;
      rtDW.pos = floor_hight;
    } else {
      if (rtDW.counter != floor_hight) {
        rtDW.is_pos_cal = IN_between_1_2;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.at_floor = -1.0;
        rtDW.pos = (floor_hight - rtDW.counter) * rtDW.downward + rtDW.upward *
          rtDW.counter;
      }
    }
    break;

   default:
    if ((rtDW.counter == floor_hight) && (rtDW.upward == 1.0)) {
      rtDW.is_pos_cal = IN_floor_3;
      rtDW.counter = 0.0;
      rtDW.at_floor = 3.0;
      rtDW.pos = floor_hight2;
    } else if ((rtDW.counter == floor_hight) && (rtDW.downward == 1.0)) {
      rtDW.is_pos_cal = IN_floor_2;
      rtDW.counter = 0.0;
      rtDW.at_floor = 2.0;
      rtDW.pos = floor_hight;
    } else {
      if (rtDW.counter != floor_hight) {
        rtDW.is_pos_cal = IN_between_2_3;
        rtDW.temporalCounter_i2 = 0U;
        rtDW.at_floor = -1.0;
        rtDW.pos = (rtDW.counter + floor_hight) * rtDW.upward + (floor_hight2 - rtDW.counter)
          * rtDW.downward;
      }
    }
    break;
  }
}

/* Function for Chart: '<S4>/Chart' */
static void plan_handle(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  guard1 = false;
  guard2 = false;
  switch (rtDW.is_plan_handle) {
   case IN_floor1:
    rtDW.door_open_c = 1.0;
    rtDW.stop_i = 1.0;
    if (rtDW.one_pressed_m == 1.0) {
      rtDW.is_plan_handle = IN_floor1;
      rtDW.temporalCounter_i1 = 0UL;
      rtDW.one_pressed_m = 0.0;
      rtDW.door_open_c = 1.0;
      rtDW.stop_i = 1.0;
    } else if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.two_pressed_c == 1.0)) { 
      rtDW.dest = 2.0;
      rtDW.two_open = 1.0;
      guard1 = true;
    } else {
      if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.two_pressed_c == 0.0) && (rtDW.three_pressed_k == 1.0)) {    
        rtDW.dest = 3.0;
        rtDW.two_open = 0.0;
        guard1 = true;
      }
    }
    break;

   case IN_floor2:
    rtDW.door_open_c = 1.0;
    rtDW.stop_i = 1.0;
    if (rtDW.two_pressed_c == 1.0) {
      rtDW.is_plan_handle = IN_floor2;
      rtDW.temporalCounter_i1 = 0UL;
      rtDW.two_pressed_c = 0.0;
      rtDW.door_open_c = 1.0;
      rtDW.stop_i = 1.0;
    } else if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.three_pressed_k == 1.0)) {   
      rtDW.dest = 3.0;
      rtDW.is_plan_handle = IN_move_up;
      rtDW.door_open_c = 0.0;
      rtDW.stop_i = 0.0;
      rtDW.upward_b = 1.0;
      rtDW.downward_p = 0.0;
    } else {
      if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.one_pressed_m == 1.0)) {   
        rtDW.dest = 1.0;
        rtDW.is_plan_handle = IN_move_down;
        rtDW.door_open_c = 0.0;
        rtDW.stop_i = 0.0;
        rtDW.upward_b = 0.0;
        rtDW.downward_p = 1.0;
      }
    }
    break;

   case IN_floor3:
    rtDW.door_open_c = 1.0;
    rtDW.stop_i = 1.0;
    if (rtDW.three_pressed_k == 1.0) {
      rtDW.is_plan_handle = IN_floor3;
      rtDW.temporalCounter_i1 = 0UL;
      rtDW.three_pressed_k = 0.0;
      rtDW.door_open_c = 1.0;
      rtDW.stop_i = 1.0;
    } else if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.two_pressed_c == 0.0) && (rtDW.one_pressed_m == 1.0)) {  
      rtDW.dest = 1.0;
      rtDW.two_open = 0.0;
      guard2 = true;
    } else {
      if ((rtDW.temporalCounter_i1 >= waitTimeAtFloor) && (rtDW.two_pressed_c == 1.0)){   
        rtDW.dest = 2.0;
        rtDW.two_open = 1.0;
        guard2 = true;
      }
    }
    break;

   case IN_move_down:
    rtDW.door_open_c = 0.0;
    rtDW.stop_i = 0.0;
    rtDW.upward_b = 0.0;
    rtDW.downward_p = 1.0;
    if ((rtDW.at_floor == 2.0) && (rtDW.two_pressed_c == 1.0) && (rtDW.two_open ==
         1.0)) {
      rtDW.is_plan_handle = IN_floor2;
      rtDW.temporalCounter_i1 = 0UL;
      rtDW.two_pressed_c = 0.0;
      rtDW.door_open_c = 1.0;
      rtDW.stop_i = 1.0;
    } else if ((rtDW.two_pressed_c == 1.0) && (rtDW.two_open == 0.0) &&
               (rtDW.pos >= tooCloseDownToFloor2)) {
      rtDW.two_open = 1.0;
      rtDW.dest = 2.0;
      rtDW.is_plan_handle = IN_move_down;
      rtDW.door_open_c = 0.0;
      rtDW.stop_i = 0.0;
      rtDW.upward_b = 0.0;
      rtDW.downward_p = 1.0;
    } else {
      if ((rtDW.one_pressed_m == 1.0) && (rtDW.at_floor == 1.0)) {
        rtDW.is_plan_handle = IN_floor1;
        rtDW.temporalCounter_i1 = 0UL;
        rtDW.one_pressed_m = 0.0;
        rtDW.door_open_c = 1.0;
        rtDW.stop_i = 1.0;
      }
    }
    break;

   default:
    rtDW.door_open_c = 0.0;
    rtDW.stop_i = 0.0;
    rtDW.upward_b = 1.0;
    rtDW.downward_p = 0.0;
    if ((rtDW.two_pressed_c == 1.0) && (rtDW.two_open == 0.0) && (rtDW.pos <=
         tooCloseUpToFloor2)) {
      rtDW.two_open = 1.0;
      rtDW.dest = 2.0;
      rtDW.is_plan_handle = IN_move_up;
      rtDW.door_open_c = 0.0;
      rtDW.stop_i = 0.0;
      rtDW.upward_b = 1.0;
      rtDW.downward_p = 0.0;
    } else if ((rtDW.at_floor == 2.0) && (rtDW.two_pressed_c == 1.0) &&
               (rtDW.two_open == 1.0)) {
      rtDW.is_plan_handle = IN_floor2;
      rtDW.temporalCounter_i1 = 0UL;
      rtDW.two_pressed_c = 0.0;
      rtDW.door_open_c = 1.0;
      rtDW.stop_i = 1.0;
    } else {
      if ((rtDW.three_pressed_k == 1.0) && (rtDW.at_floor == 3.0)) {
        rtDW.is_plan_handle = IN_floor3;
        rtDW.temporalCounter_i1 = 0UL;
        rtDW.three_pressed_k = 0.0;
        rtDW.door_open_c = 1.0;
        rtDW.stop_i = 1.0;
      }
    }
    break;
  }

  if (guard2) {
    rtDW.is_plan_handle = IN_move_down;
    rtDW.door_open_c = 0.0;
    rtDW.stop_i = 0.0;
    rtDW.upward_b = 0.0;
    rtDW.downward_p = 1.0;
  }

  if (guard1) {
    rtDW.is_plan_handle = IN_move_up;
    rtDW.door_open_c = 0.0;
    rtDW.stop_i = 0.0;
    rtDW.upward_b = 1.0;
    rtDW.downward_p = 0.0;
  }
}

/* Model step function */
void elevator_2017b_step(void)
{
  boolean_T rtb_OR;
  boolean_T rtb_OR1;
  real_T UnitDelay;

  /* Chart: '<S6>/bottun processor ' incorporates:
   *  Inport: '<Root>/Inport'
   *  Inport: '<Root>/Inport1'
   *  Inport: '<Root>/Inport2'
   *  Inport: '<Root>/Inport3'
   *  Inport: '<Root>/Inport4'
   *  Inport: '<Root>/Inport5'
   */
  if (rtDW.temporalCounter_i1_p < 7U) {
    rtDW.temporalCounter_i1_p++;
  }

  if (rtDW.is_active_c3_elevator_2017b == 0U) {
    rtDW.is_active_c3_elevator_2017b = 1U;
    rtDW.is_c3_elevator_2017b = IN_Reset;
    rtDW.one_pressed = 0.0;
    rtDW.two_pressed = 0.0;
    rtDW.three_pressed = 0.0;
    rtDW.door_open = 0.0;
    rtDW.stop_pressed = 0.0;
  } else {
    switch (rtDW.is_c3_elevator_2017b) {
     case IN_Reset:
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      if (rtU.Inport3 == 1.0) {
        rtDW.is_c3_elevator_2017b = IN_two_bounce;
        rtDW.temporalCounter_i1_p = 0U;
      } else if (rtU.Inport4 == 1.0) {
        rtDW.is_c3_elevator_2017b = IN_three_bounce;
        rtDW.temporalCounter_i1_p = 0U;
      } else if (rtU.Inport == 1.0) {
        rtDW.is_c3_elevator_2017b = IN_door_bounce;
        rtDW.temporalCounter_i1_p = 0U;
      } else if (rtU.Inport1 == 1.0) {
        rtDW.is_c3_elevator_2017b = IN_stop_bounce;
        rtDW.temporalCounter_i1_p = 0U;
      } else if (rtU.Inport2 == 1.0) {
        rtDW.is_c3_elevator_2017b = IN_one_bounce;
        rtDW.temporalCounter_i1_p = 0U;
      } else {
        if (rtU.Inport5 == 1.0) {
          rtDW.is_c3_elevator_2017b = IN_floor_bounce;
          rtDW.temporalCounter_i1_p = 0U;
        }
      }
      break;

     case IN_door_bounce:
      if (rtU.Inport == 1.0) {   // && (rtDW.temporalCounter_i1_p >= 4U)
        rtDW.is_c3_elevator_2017b = IN_door_status;
        rtDW.door_open = 1.0;
      } else {
        if (rtU.Inport == 0.0) {
          rtDW.is_c3_elevator_2017b = IN_Reset;
          rtDW.one_pressed = 0.0;
          rtDW.two_pressed = 0.0;
          rtDW.three_pressed = 0.0;
          rtDW.door_open = 0.0;
          rtDW.stop_pressed = 0.0;
        }
      }
      break;

     case IN_door_status:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;

     case IN_floor_bounce:
      if (rtU.Inport5 == 0.0) {
        rtDW.is_c3_elevator_2017b = IN_Reset;
        rtDW.one_pressed = 0.0;
        rtDW.two_pressed = 0.0;
        rtDW.three_pressed = 0.0;
        rtDW.door_open = 0.0;
        rtDW.stop_pressed = 0.0;
      } else {
        if ((rtU.Inport5 == 1.0) && (rtDW.temporalCounter_i1_p >= 4U)) {
          rtDW.is_c3_elevator_2017b = IN_floor_pos;
        }
      }
      break;

     case IN_floor_pos:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;

     case IN_one_bounce:
      if ((rtU.Inport2 == 1.0) && (rtDW.temporalCounter_i1_p >= 4U)) {
        rtDW.is_c3_elevator_2017b = IN_one_press;
        rtDW.one_pressed = 1.0;
      } else {
        if (rtU.Inport2 == 0.0) {
          rtDW.is_c3_elevator_2017b = IN_Reset;
          rtDW.one_pressed = 0.0;
          rtDW.two_pressed = 0.0;
          rtDW.three_pressed = 0.0;
          rtDW.door_open = 0.0;
          rtDW.stop_pressed = 0.0;
        }
      }
      break;

     case IN_one_press:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;

     case IN_stop_bounce:
      if ((rtU.Inport1 == 1.0) && (rtDW.temporalCounter_i1_p >= 4U)) {
        rtDW.is_c3_elevator_2017b = IN_stop_press;
        rtDW.stop_pressed = 1.0;
      } else {
        if (rtU.Inport1 == 0.0) {
          rtDW.is_c3_elevator_2017b = IN_Reset;
          rtDW.one_pressed = 0.0;
          rtDW.two_pressed = 0.0;
          rtDW.three_pressed = 0.0;
          rtDW.door_open = 0.0;
          rtDW.stop_pressed = 0.0;
        }
      }
      break;

     case IN_stop_press:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;

     case IN_three_bounce:
      if ((rtU.Inport4 == 1.0) && (rtDW.temporalCounter_i1_p >= 4U)) {
        rtDW.is_c3_elevator_2017b = IN_three_press;
        rtDW.three_pressed = 1.0;
      } else {
        if (rtU.Inport4 == 0.0) {
          rtDW.is_c3_elevator_2017b = IN_Reset;
          rtDW.one_pressed = 0.0;
          rtDW.two_pressed = 0.0;
          rtDW.three_pressed = 0.0;
          rtDW.door_open = 0.0;
          rtDW.stop_pressed = 0.0;
        }
      }
      break;

     case IN_three_press:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;

     case IN_two_bounce:
      if ((rtU.Inport3 == 1.0) && (rtDW.temporalCounter_i1_p >= 4U)) {
        rtDW.is_c3_elevator_2017b = IN_two_press;
        rtDW.two_pressed = 1.0;
      } else {
        if (rtU.Inport3 == 0.0) {
          rtDW.is_c3_elevator_2017b = IN_Reset;
          rtDW.one_pressed = 0.0;
          rtDW.two_pressed = 0.0;
          rtDW.three_pressed = 0.0;
          rtDW.door_open = 0.0;
          rtDW.stop_pressed = 0.0;
        }
      }
      break;

     default:
      rtDW.is_c3_elevator_2017b = IN_Reset;
      rtDW.one_pressed = 0.0;
      rtDW.two_pressed = 0.0;
      rtDW.three_pressed = 0.0;
      rtDW.door_open = 0.0;
      rtDW.stop_pressed = 0.0;
      break;
    }
  }

  /* End of Chart: '<S6>/bottun processor ' */

  /* UnitDelay: '<Root>/Unit Delay' */
  UnitDelay = rtDW.UnitDelay_DSTATE;

  /* Chart: '<S6>/position processor ' */
  if (rtDW.temporalCounter_i1_l < 32767U) {
    rtDW.temporalCounter_i1_l++;
  }

  if (rtDW.temporalCounter_i2 < 63U) {
    rtDW.temporalCounter_i2++;
  }

  if (rtDW.is_active_c1_elevator_2017b == 0U) {
    rtDW.is_active_c1_elevator_2017b = 1U;
    rtDW.is_c1_elevator_2017b = IN_init;
  } else if (rtDW.is_c1_elevator_2017b == IN_init) {
    rtDW.last_counter = 0.0;
    rtDW.pos = 0.0;
    rtDW.is_c1_elevator_2017b = IN_pos_detection;
    rtDW.temporalCounter_i1_l = 0U;
    rtDW.speed = rtDW.pos - rtDW.last_counter;
    rtDW.last_counter = rtDW.pos;
    rtDW.is_pos_cal = IN_floor_1;
    rtDW.counter = 0.0;
    rtDW.at_floor = 1.0;
    rtDW.pos = 0.0;
  } else {
    if(rtDW.stop == 0.0)    // to stop changing position
      pos_detection(&UnitDelay);
  }

  /* End of Chart: '<S6>/position processor ' */

  /* Chart: '<S4>/Chart' */
  if (rtDW.temporalCounter_i1 < 131071UL) {
    rtDW.temporalCounter_i1++;
  }

  if (rtDW.is_active_c4_elevator_2017b == 0U) {
    rtDW.is_active_c4_elevator_2017b = 1U;
    rtDW.is_c4_elevator_2017b = IN_init;
  } else if (rtDW.is_c4_elevator_2017b == IN_init) {
    rtDW.two_pressed_c = 0.0;
    rtDW.three_pressed_k = 0.0;
    rtDW.is_c4_elevator_2017b = IN_planning_cal;
    rtDW.is_plan_handle = IN_floor1;
    rtDW.temporalCounter_i1 = 0UL;
    rtDW.one_pressed_m = 0.0;
    rtDW.door_open_c = 1.0;
    rtDW.stop_i = 1.0;
  } else {
    plan_handle();
    if (rtDW.two_pressed == 1.0) {
      rtDW.two_pressed_c = 1.0;
    } else if (rtDW.three_pressed == 1.0) {
      rtDW.three_pressed_k = 1.0;
    } else {
      if (rtDW.one_pressed == 1.0) {
        rtDW.one_pressed_m = 1.0;
      }
    }
  }

  /* End of Chart: '<S4>/Chart' */

  /* Logic: '<Root>/OR' */
  rtb_OR = ((rtDW.door_open != 0.0) || (rtDW.door_open_c != 0.0));

  /* Outport: '<Root>/Out2' */
  rtY.Out2 = rtb_OR;

  /* Logic: '<Root>/OR1' */
  rtb_OR1 = ((rtDW.stop_pressed != 0.0) || (rtDW.stop_i != 0.0));

  stopOut = rtb_OR1;

  /* Chart: '<S5>/Chart' */
  if (rtDW.temporalCounter_i1_b < 255U) {
    rtDW.temporalCounter_i1_b++;
  }

  if (rtDW.is_active_c2_elevator_2017b == 0U) {
    rtDW.is_active_c2_elevator_2017b = 1U;
    rtDW.is_c2_elevator_2017b = IN_monitor;
    rtDW.temporalCounter_i1_b = 0U;
  } else {
    switch (rtDW.is_c2_elevator_2017b) {
     case IN_both_dir_stop:
      if ((rtDW.temporalCounter_i1_b >= 200U) && ((rtDW.upward_b == 0.0) ||
           (rtDW.downward_p == 0.0))) {
        rtDW.is_c2_elevator_2017b = IN_monitor;
        rtDW.temporalCounter_i1_b = 0U;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.upward_b == 1.0) &&
            (rtDW.downward_p == 1.0)) {
          rtDW.is_c2_elevator_2017b = IN_both_dir_stop;
          rtDW.temporalCounter_i1_b = 0U;
          rtDW.stop = 1.0;
        }
      }
      break;

     case IN_door_stop:
      if ((rtDW.temporalCounter_i1_b >= 60U) && rtb_OR) {
        rtDW.is_c2_elevator_2017b = IN_door_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 60U) && (!rtb_OR)) {
          rtDW.is_c2_elevator_2017b = IN_monitor;
          rtDW.temporalCounter_i1_b = 0U;
        }
      }
      break;

     case IN_down_stop:
      if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.pos == floor_hight2) &&
          (rtDW.at_floor == -1.0) && (rtDW.upward_b == 1.0)) {
        rtDW.is_c2_elevator_2017b = IN_down_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 200U) && ((rtDW.at_floor != -1.0) ||
             (rtDW.downward_p == 0.0))) {
          rtDW.is_c2_elevator_2017b = IN_monitor;
          rtDW.temporalCounter_i1_b = 0U;
        }
      }
      break;

     case IN_monitor:
      if ((rtDW.temporalCounter_i1_b >= 200U) && rtb_OR && (rtDW.at_floor ==
           -1.0)) {
        rtDW.is_c2_elevator_2017b = IN_door_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else if ((rtDW.temporalCounter_i1_b >= 200U) && rtb_OR1) {
        rtDW.is_c2_elevator_2017b = IN_stop_button;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.pos == floor_hight2) &&
                 (rtDW.at_floor == -1.0) && (rtDW.upward_b == 1.0)) {
        rtDW.is_c2_elevator_2017b = IN_top_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.speed > 50.0)) {
        rtDW.is_c2_elevator_2017b = IN_speed_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.pos == 0.0) &&
                 (rtDW.at_floor == -1.0) && (rtDW.downward_p == 1.0)) {
        rtDW.is_c2_elevator_2017b = IN_down_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.upward_b == 1.0) &&
                 (rtDW.downward_p == 1.0)) {
        rtDW.is_c2_elevator_2017b = IN_both_dir_stop;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else {
        // rtDW.stop = 0.0;
      }
      break;

     case IN_speed_stop:
      if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.speed <= 50.0)) {
        rtDW.is_c2_elevator_2017b = IN_monitor;
        rtDW.temporalCounter_i1_b = 0U;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.speed > 50.0)) {
          rtDW.is_c2_elevator_2017b = IN_speed_stop;
          rtDW.temporalCounter_i1_b = 0U;
          rtDW.stop = 1.0;
        }
      }
      break;

     case IN_stop_button:
      if ((rtDW.temporalCounter_i1_b >= 60U) && rtb_OR1) {
        rtDW.is_c2_elevator_2017b = IN_stop_button;
        rtDW.temporalCounter_i1_b = 0U;
        rtDW.stop = 1.0;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 60U) && (!rtb_OR1)) {
          rtDW.is_c2_elevator_2017b = IN_monitor;
          rtDW.temporalCounter_i1_b = 0U;
        }
      }
      break;

     default:
      if ((rtDW.temporalCounter_i1_b >= 200U) && ((rtDW.at_floor != -1.0) ||
           (rtDW.upward_b == 0.0))) {
        rtDW.is_c2_elevator_2017b = IN_monitor;
        rtDW.temporalCounter_i1_b = 0U;
      } else {
        if ((rtDW.temporalCounter_i1_b >= 200U) && (rtDW.pos == floor_hight2) &&
            (rtDW.at_floor == -1.0) && (rtDW.upward_b == 1.0)) {
          rtDW.is_c2_elevator_2017b = IN_top_stop;
          rtDW.temporalCounter_i1_b = 0U;
          rtDW.stop = 1.0;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S5>/Chart' */

  /* Chart: '<S1>/Chart' */
  if (rtDW.is_active_c5_elevator_2017b == 0U) {
    rtDW.is_active_c5_elevator_2017b = 1U;
    rtDW.is_c5_elevator_2017b = IN_move;
    rtDW.upward_final = rtDW.upward_b * 0.5;
    rtDW.downward_final = rtDW.downward_p * 0.5;
  } else if (rtDW.is_c5_elevator_2017b == IN_move) {
    if (rtDW.stop == 1.0) {
      rtDW.is_c5_elevator_2017b = IN_stop;
      rtDW.upward_final = 0.0;
      rtDW.downward_final = 0.0;
    }
  } else {
    if (rtDW.stop == 0.0) {
      rtDW.is_c5_elevator_2017b = IN_move;
      rtDW.upward_final = rtDW.upward_b * 0.5;
      rtDW.downward_final = rtDW.downward_p * 0.5;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* RelationalOperator: '<S16>/Compare' incorporates:
   *  Constant: '<S16>/Constant'
   */
  rtb_OR = (rtDW.Integrator_DSTATE >= 0.001);

  /* InitialCondition: '<S15>/Initial' incorporates:
   *  Bias: '<S15>/Bias1'
   */
  if (rtDW.Initial_FirstOutputTime) {
    rtDW.Initial_FirstOutputTime = false;
    UnitDelay = 0.0;
  } else {
    UnitDelay = rtDW.Integrator_DSTATE + -0.001;
  }

  /* End of InitialCondition: '<S15>/Initial' */

  /* DiscreteIntegrator: '<S15>/Integrator' */
  if (rtb_OR && (rtDW.Integrator_PrevResetState <= 0)) {
    rtDW.Integrator_DSTATE = UnitDelay;
  }

  /* Outport: '<Root>/Out3' incorporates:
   *  Constant: '<S9>/Constant'
   *  DataTypeConversion: '<S2>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S15>/Integrator'
   *  Gain: '<S8>/Gain1'
   *  Gain: '<S8>/Gain2'
   *  Logic: '<S2>/Logical Operator'
   *  RelationalOperator: '<S2>/Relational Operator'
   *  RelationalOperator: '<S9>/Compare'
   */
  rtY.Out3 = ((rtDW.downward_final != 0.0) && (rtDW.downward_final >=
    1.0526315789473684 * rtDW.Integrator_DSTATE * 1000.0));

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  rtb_OR1 = (rtDW.Integrator_DSTATE_a >= 0.001);

  /* InitialCondition: '<S27>/Initial' incorporates:
   *  Bias: '<S27>/Bias1'
   */
  if (rtDW.Initial_FirstOutputTime_g) {
    rtDW.Initial_FirstOutputTime_g = false;
    UnitDelay = 0.0;
  } else {
    UnitDelay = rtDW.Integrator_DSTATE_a + -0.001;
  }

  /* End of InitialCondition: '<S27>/Initial' */

  /* DiscreteIntegrator: '<S27>/Integrator' */
  if (rtb_OR1 && (rtDW.Integrator_PrevResetState_j <= 0)) {
    rtDW.Integrator_DSTATE_a = UnitDelay;
  }

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<S21>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S27>/Integrator'
   *  Gain: '<S20>/Gain1'
   *  Gain: '<S20>/Gain2'
   *  Logic: '<S3>/Logical Operator'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S3>/Relational Operator'
   */
  rtY.Out1 = ((rtDW.upward_final != 0.0) && (rtDW.upward_final >=
    1.0526315789473684 * rtDW.Integrator_DSTATE_a * 1000.0));

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtDW.dest;

  /* Update for DiscreteIntegrator: '<S15>/Integrator' */
  rtDW.Integrator_DSTATE += 5.0E-5;
  rtDW.Integrator_PrevResetState = (int8_T)rtb_OR;

  /* Update for DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_DSTATE_a += 5.0E-5;
  rtDW.Integrator_PrevResetState_j = (int8_T)rtb_OR1;
}

/* Model initialize function */
void elevator_2017b_initialize(void)
{
  /* Start for InitialCondition: '<S15>/Initial' */
  rtDW.Initial_FirstOutputTime = true;

  /* Start for InitialCondition: '<S27>/Initial' */
  rtDW.Initial_FirstOutputTime_g = true;

  /* InitializeConditions for DiscreteIntegrator: '<S15>/Integrator' */
  rtDW.Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Integrator' */
  rtDW.Integrator_PrevResetState_j = 2;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

// button pins
#define btn_one  4      // inport2
#define btn_two  5      // inport3
#define btn_three 6     // inport4
#define door_btn 7      // inport
#define btn_stop  8     // inport1
// encoder pin
#define channelA 2      // inport6
#define channelB 3      // shows selected floor
// output pins
#define upwardPWM 9
#define downwardPWM 10
#define doorOpen 11


void doEncoderA(){}
void doEncoderB(){}

void setup() { 

  // button setup
  pinMode(btn_one, INPUT);
  pinMode(btn_two, INPUT);
  pinMode(btn_three, INPUT);
  pinMode(door_btn, INPUT);
  pinMode(btn_stop, INPUT);

  // encoder setup
  pinMode(channelA, INPUT_PULLUP);
  attachInterrupt(0, doEncoderA, CHANGE);
  pinMode(channelB, INPUT_PULLUP);
  attachInterrupt(1, doEncoderB, CHANGE);

  // output setup
  pinMode(upwardPWM, OUTPUT);
  pinMode(downwardPWM, OUTPUT);
  pinMode(doorOpen, OUTPUT);

  elevator_2017b_initialize();
  Serial.begin (9600);

  rtDW.last = digitalRead(channelA);  
} 

void loop() { 

  // read buttons
  rtU.Inport2 = digitalRead(btn_one);
  rtU.Inport3 = digitalRead(btn_two);
  rtU.Inport4 = digitalRead(btn_three);
  rtU.Inport1 = digitalRead(btn_stop);
  rtU.Inport  = digitalRead(door_btn);

  // read position sensor
  rtU.Inport6 = digitalRead(channelA);

  // run the model
  elevator_2017b_step();

  // check the result
  if(rtU.Inport2 == HIGH){
    rtDW.one_pressed_m = 1.0;
    Serial.println("Floor_1 button pressed!");
  }
  else if(rtU.Inport3 == HIGH){
    rtDW.two_pressed_c = 1.0;
    Serial.println("Floor_2 button pressed!");
  }
  else if(rtU.Inport4 == HIGH){
    rtDW.three_pressed_k = 1.0;
    Serial.println("Floor_3 button pressed!");
  }
  else if(rtU.Inport1 == HIGH){
    rtDW.stop_i = 1.0;
    rtDW.stop = 1.0;
    Serial.println("Stop button pressed!");
  }
  else if(rtU.Inport == HIGH){
    rtDW.door_open_c = 1.0;
    Serial.println("Door open button pressed!");
  }

  Serial.print("Position: ");
  Serial.print(rtDW.pos);

  Serial.print("   At_floor: ");
  Serial.print(rtDW.at_floor);

  Serial.print("   Destination: ");
  Serial.print(rtDW.dest);

  Serial.print("   Door open: ");
  Serial.print(rtY.Out2);

  Serial.print("   Stop: ");
  Serial.println(stopOut || rtDW.stop);

  // write outputs
  digitalWrite(doorOpen, rtY.Out2);
  analogWrite(upwardPWM, rtY.Out3);
  analogWrite(downwardPWM, rtY.Out1);

  delay(50);
}