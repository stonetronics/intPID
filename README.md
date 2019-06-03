# intPID
PID code for integer PID control; written in arduino

this code implements a PID control loop with measured input, setpoint and output. Sample time is obtained automatically by the millis() function. Coefficients kp, ki and kd can be set on the fly.
The PID control is done in Integer, which is a lot faster than the original Arduino PID library which uses float.

The usage example is a mpu6050 together with an arduino on a breadboard, with an rc servo attached to the roll axis. The setup levels the breadboard around the roll axis.

