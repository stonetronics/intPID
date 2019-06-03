#include <Arduino.h>

union precisionInt8
{
  int16_t precision;
  int8_t bytes[2];
};


class intPID
{
  public:

  intPID(int8_t* setpointAdd, int8_t* inputAdd, int8_t* outputAdd); //adresses of the input/output value

  void setKp(float kp){this->kp = (int32_t)(kp*65536);}; //multiply the coefficients by 2^16 to allow for values |x| < 1
  void setKi(float ki){this->ki = (int32_t)(ki*65536);};
  void setKd(float kd){this->kd = (int32_t)(kd*65536);};
  void setCoefficients(float kp, float ki, float kd){setKp(kp); setKi(ki); setKd(kd);};

  void compute( void );

  private:

  int previousTime;
  int currentTime;
  int dt;

  int8_t* setpointAdd;
  int8_t* inputAdd;
  int8_t* outputAdd;

  int16_t input;
  int32_t output;
  
  int32_t kp;
  int32_t ki;
  int32_t kd;

  int8_t error;
  int8_t previousError;
  int8_t previousInput;
  int16_t integralOutput;
  int16_t differentialOutput;
};

