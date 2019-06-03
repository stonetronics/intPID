#include "intPID.h"

intPID::intPID(int8_t* setpointAdd, int8_t* inputAdd, int8_t* outputAdd)
{
  this->setpointAdd = setpointAdd;
  this->inputAdd = inputAdd;
  this->outputAdd = outputAdd;

  kp = 1;
  ki = 0;
  kd = 0;

  currentTime = millis();
  previousTime = currentTime;

  integralOutput = 0;
  differentialOutput = 0;
  previousError = 0;
}


void intPID::compute( void )
{

  
  //memory operation for input
  input = (*inputAdd);

  //compute dt
  currentTime = millis();
  dt = currentTime - previousTime;
  previousTime = currentTime;

  //compute pid
  error = (*setpointAdd) - (*inputAdd);
  integralOutput += error * dt;
  differentialOutput = (error - previousError) / dt;
  previousError = error;
  output = error * kp + integralOutput * ki + differentialOutput * kd;
  output >>= 16; // divide by 256 again

 /* Serial.print("input ");
  Serial.print(input);
  Serial.print("  dt:");
  Serial.print(dt);
  Serial.print("  error ");
  Serial.print(error);
  Serial.print("  differentialOutput ");
  Serial.println(differentialOutput);*/

  //memory operation for output
  (*outputAdd) = (int8_t) output;
}

