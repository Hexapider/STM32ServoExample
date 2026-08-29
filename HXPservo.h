/*
 * HXPservo.h
 *
 *  Created on: 19 Aug 2026
 *      Author: Khang
 */

#ifndef INC_HXPSERVO_H_
#define INC_HXPSERVO_H_
#include "HXPservoConfig.h"
#ifdef __cplusplus
class ServoController
{
public:
    void begin();
    void write(ServoName_t name, ServoAngle_t angle);
    void writeAll(const ServoAngle_t angles[SERVO_COUNT]);
    void writeMicroseconds(ServoName_t name, uint16_t us);
private:
    uint16_t angleToPulse(ServoName_t name, ServoAngle_t angle) const;
};
extern ServoController Servo;
#endif
#ifdef __cplusplus
extern "C"
{
#endif
void Servo_Init(void);
void Servo_write(ServoName_t name, ServoAngle_t angle);
void Servo_writeAll(const ServoAngle_t angles[SERVO_COUNT]);
void Servo_writeMicroseconds(ServoName_t name, uint16_t us);
#ifdef __cplusplus
}
#endif
#endif /* INC_HXPSERVO_H_ */
