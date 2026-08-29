# STM32ServoExample
An example of servo control using STM32.
Two header files are written in C++.
To add a servo, go to the HXPServoConfig.h file and add an entry to SERVO_LIST following this format:
X(<servo name>, <timer>, <channel>, <min pulse>, <max pulse>, <max angle>) \
