/*
 * HXP_ServoConfig.h
 *
 *  Created on: 19 Aug 2026
 *      Author: Khang
 */

#ifndef INC_HXPSERVOCONFIG_H_
#define INC_HXPSERVOCONFIG_H_
#include "main.h"
#include "gpio.h"
#include "tim.h"
typedef uint16_t ServoAngle_t;
#define SERVO_LIST \
		X(SERVO_FR_COXA,  htim2, TIM_CHANNEL_1, 1000, 2000, 180) \
//		    X(SERVO_FR_FEMUR, htim2, TIM_CHANNEL_2, 1000, 2000, 180) \
//		    X(SERVO_FR_TIBIA, htim2, TIM_CHANNEL_3, 1000, 2000, 180) \
//		    X(SERVO_CR_COXA,  htim2, TIM_CHANNEL_4, 1000, 2000, 180) \
//		    X(SERVO_CR_FEMUR, htim2, TIM_CHANNEL_5, 1000, 2000, 180) \
//		    X(SERVO_CR_TIBIA, htim2, TIM_CHANNEL_6, 1000, 2000, 180) \
//		    X(SERVO_RR_COXA,  htim3, TIM_CHANNEL_1, 1000, 2000, 180) \
//		    X(SERVO_RR_FEMUR, htim3, TIM_CHANNEL_2, 1000, 2000, 180) \
//		    X(SERVO_RR_TIBIA, htim3, TIM_CHANNEL_3, 1000, 2000, 180) \
//		    X(SERVO_FL_COXA,  htim3, TIM_CHANNEL_4, 1000, 2000, 180) \
//		    X(SERVO_FL_FEMUR, htim3, TIM_CHANNEL_5, 1000, 2000, 180) \
//		    X(SERVO_FL_TIBIA, htim3, TIM_CHANNEL_6, 1000, 2000, 180) \
//		    X(SERVO_CL_COXA,  htim4, TIM_CHANNEL_1, 1000, 2000, 180) \
//		    X(SERVO_CL_FEMUR, htim4, TIM_CHANNEL_2, 1000, 2000, 180) \
//		    X(SERVO_CL_TIBIA, htim4, TIM_CHANNEL_3, 1000, 2000, 180) \
//		    X(SERVO_RL_COXA,  htim4, TIM_CHANNEL_4, 1000, 2000, 180) \
//		    X(SERVO_RL_FEMUR, htim4, TIM_CHANNEL_5, 1000, 2000, 180) \
//		    X(SERVO_RL_TIBIA, htim4, TIM_CHANNEL_6, 1000, 2000, 180)
typedef enum {
#define X(name, timer, channel, pmin, pmax, amax) name,
    SERVO_LIST
#undef X
    SERVO_COUNT
} ServoName_t;
#endif /* INC_HXPSERVOCONFIG_H_ */
