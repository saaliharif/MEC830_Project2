#include <AccelStepper.h>
#include <MultiStepper.h>

MultiStepper steppers;
int x=0;
int y=0; 
int j;
int a = 0;
int b= 0;
int counter=0;
float c;
const int trig=13;
const int echo=12;


long duration, distance, positions[2];

AccelStepper StepperMotor2(AccelStepper::FULL4WIRE, 2,4,5,3);
AccelStepper StepperMotor1(AccelStepper::FULL4WIRE, 9,7,6,8);

void setup()
{  
  c=500.0;
    StepperMotor1.setMaxSpeed(c);
    StepperMotor1.setSpeed(c);
    StepperMotor1.setAcceleration(100.0);

    StepperMotor2.setMaxSpeed(c);
    StepperMotor2.setSpeed(c);
    StepperMotor2.setAcceleration(100.0);
    
    pinMode(trig, OUTPUT);   
    pinMode(echo, INPUT);
    
    steppers.addStepper(StepperMotor1);
    steppers.addStepper(StepperMotor2);
    
    Serial.begin(9600);
}
void loop()
{
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW); 
    duration = pulseIn(echo, HIGH);
    distance = duration*(0.034/2);
    Serial.println(distance);
    j=300;


        StepperMotor1.setCurrentPosition(0);
        StepperMotor2.setCurrentPosition(0);
        
    if(distance>=13){
      Serial.print("moving");
      Serial.println();

        StepperMotor1.setCurrentPosition(0);
        StepperMotor2.setCurrentPosition(0);
        a=350;
        b=-350;
        positions[0] = a;
        positions[1] = -a;

        steppers.moveTo(positions);
        steppers.runSpeedToPosition(); 
    }
        if(distance<=12){
          right();
          straight();
          left();
          straight2();
          left();
          straight();
          right();
          straight3();
          stop();
        }   
}

void right(){                 //Robot turns right
            counter++;
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);            
            a=-1840;
            positions[0] = a;
            positions[1] = a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition();      
}

void left(){                  //Robot turns left
            counter++;
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);            
            a=1840;
            positions[0] = a;
            positions[1] = a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition();       
            
}
void straight(){                  //Robot goes around obstacle
            counter++;
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);            
            a=3000;
            positions[0] = a;
            positions[1] = -a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition();            
}

void straight2(){                  //Robot goes straight past obstacle
            counter++;
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);            
            a=6000;
            positions[0] = a;
            positions[1] = -a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition();   
  
}

void straight3(){                  //Robot goes past finish line
            counter++;
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);            
            a=100000;
            positions[0] = a;
            positions[1] = -a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition();     
  
}

void stop(){
  while(1){
              
            }

}



            
