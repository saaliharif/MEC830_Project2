//MEC825 Project 2 Task 1
//This task uses a joystick module to control a robot. The robot's task is to successfully navigate 3 waypoints.   

#include <AccelStepper.h>
int Constant;
int x=0;
int y=0; 
const int X_pin = 0; // Analog Pin 0 controls Joystick X-output 
const int Y_pin = 1; // Analog Pin 1 controls Joystick Y-output

AccelStepper StepperMotor2(AccelStepper::FULL4WIRE, 2,4,5,3);
AccelStepper StepperMotor1(AccelStepper::FULL4WIRE, 9,7,6,8);

void setup()
{  
    StepperMotor1.setAcceleration(190);
    StepperMotor1.setMaxSpeed(1200);
    
    StepperMotor2.setAcceleration(190);
    StepperMotor2.setMaxSpeed(1200);
}

void loop()
{
    y = analogRead(X_pin);
    x = analogRead(Y_pin);
    Serial.print("X: ");
    Serial.println(x);
    Serial.print("Y: ");
    Serial.println(y);
    Serial.println();

Constant=650;

if(y>1000){
    StepperMotor2.setSpeed(Constant);
    StepperMotor1.setSpeed(-Constant); 
    StepperMotor1.runSpeed();
    StepperMotor2.runSpeed();
      }
        //Joystick is moved up, Robot moves forwards
      
if(y<4){
    StepperMotor2.setSpeed(-Constant);
    StepperMotor1.setSpeed(Constant); 
    StepperMotor1.runSpeed();
    StepperMotor2.runSpeed();
        //Joystick is moved down, Robot moves backwards
      }
    
if(y>5){
        if(y<999){
      //Controls stepper motors to do nothing
      }
    }

if(x>1000){
    StepperMotor2.setSpeed(-Constant);
    StepperMotor1.setSpeed(-Constant); 
    StepperMotor1.runSpeed();
    StepperMotor2.runSpeed();
      }
        //Joystick is moved right, Robot turns right
      
if(x<4){
    StepperMotor2.setSpeed(Constant);
    StepperMotor1.setSpeed(Constant); 
    StepperMotor1.runSpeed();
    StepperMotor2.runSpeed();
        //Joystick is moved left, Robot turns left
      }
    
if(x>5){
        if(x<999){
       //Controls stepper motors to do nothing
      }
    }
}
