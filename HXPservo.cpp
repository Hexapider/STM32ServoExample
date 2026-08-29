/*
 * HXPservo.cpp
 *
 *  Created on: 19 Aug 2026
 *      Author: Khang
 */
#include "HXPservo.h"
typedef struct
{
    TIM_HandleTypeDef* htim;
    uint32_t channel;
    uint16_t pulseMin;
    uint16_t pulseMax;
    uint16_t angleMax;
    uint16_t pulseRange;
    float    invAngleMax;
} ServoInfo_t;
static ServoInfo_t servoTable[SERVO_COUNT] = {
#define X(name, timer, channel, pmin, pmax, amax) { &timer, channel, pmin, pmax, amax },
    SERVO_LIST
#undef X
};
ServoController Servo;
void ServoController::begin()
{
    for (uint8_t i = 0; i < SERVO_COUNT; i++)
    {
        servoTable[i].pulseRange  = servoTable[i].pulseMax - servoTable[i].pulseMin;
        servoTable[i].invAngleMax = 1.0f / (float)servoTable[i].angleMax;
        HAL_TIM_PWM_Start(servoTable[i].htim, servoTable[i].channel);
    }
}
uint16_t ServoController::angleToPulse(ServoName_t name, ServoAngle_t angle) const
{
    const ServoInfo_t* s = &servoTable[name];
    if (angle > s->angleMax) angle = s->angleMax;
    float ratio = (float)angle * s->invAngleMax;
    return s->pulseMin + (uint16_t)(ratio * (float)s->pulseRange);
}
void ServoController::write(ServoName_t name, ServoAngle_t angle)
{
    if (name >= SERVO_COUNT) return;
    uint16_t pulse = angleToPulse(name, angle);
    __HAL_TIM_SET_COMPARE(servoTable[name].htim, servoTable[name].channel, pulse);
}
void ServoController::writeAll(const ServoAngle_t angles[SERVO_COUNT])
{
    uint16_t pulses[SERVO_COUNT];
    for (uint8_t i = 0; i < SERVO_COUNT; i++)
    {
        pulses[i] = angleToPulse((ServoName_t)i, angles[i]);
    }
    for (uint8_t i = 0; i < SERVO_COUNT; i++)
    {
        __HAL_TIM_SET_COMPARE(servoTable[i].htim, servoTable[i].channel, pulses[i]);
    }
}
void ServoController::writeMicroseconds(ServoName_t name, uint16_t us)
{
    if (name >= SERVO_COUNT) return;
    const ServoInfo_t* s = &servoTable[name];
    if (us < s->pulseMin) us = s->pulseMin;
    if (us > s->pulseMax) us = s->pulseMax;
    __HAL_TIM_SET_COMPARE(s->htim, s->channel, us);
}
extern "C" void Servo_Init(void)
{
    Servo.begin();
}
extern "C" void Servo_write(ServoName_t name, ServoAngle_t angle)
{
    Servo.write(name, angle);
}
extern "C" void Servo_writeAll(const ServoAngle_t angles[SERVO_COUNT])
{
    Servo.writeAll(angles);
}
extern "C" void Servo_writeMicroseconds(ServoName_t name, uint16_t us)
{
    Servo.writeMicroseconds(name, us);
}




