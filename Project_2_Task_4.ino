#include <AccelStepper.h>
#include <MultiStepper.h>

// Task 3

MultiStepper steppers;
int x=0;
int y=0; 
int j;
int a = 0
int b= 0;
int counter=0;
float c;
const int trig=13;
const int echo=12;



AccelStepper StepperMotor2(AccelStepper::FULL4WIRE, 2,4,5,3);
AccelStepper StepperMotor1(AccelStepper::FULL4WIRE, 9,7,6,8);

void setup()
{  
  c=500.0;
    StepperMotor1.setMaxSpeed(c);
    StepperMotor1.setSpeed(c);
    StepperMotor1.setAcceleration(100.0);
    //StepperMotor1.moveTo(j);
    
    
    StepperMotor2.setMaxSpeed(c);
    StepperMotor2.setSpeed(c);
    StepperMotor2.setAcceleration(100.0);
    //StepperMotor2.moveTo(j);
    
    pinMode(trig, OUTPUT);   
    pinMode(echo, INPUT);
    
    steppers.addStepper(StepperMotor1);
    steppers.addStepper(StepperMotor2);
    
    Serial.begin(9600);
}
void loop()
{

    long duration, distance, positions[2];

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
        
    if(distance>=10){

        StepperMotor1.setCurrentPosition(0);
        StepperMotor2.setCurrentPosition(0);
        a=350;
        b=-350;
        positions[0] = a;
        positions[1] = -a;
       
        steppers.moveTo(positions);
        steppers.runSpeedToPosition(); 
        
    }
        if(distance<=9){
            counter++;
            
            StepperMotor1.setCurrentPosition(0);
            StepperMotor2.setCurrentPosition(0);
            
            if(counter == 1){ //Robot turns right
            a=-1800;
            }
            
            if(counter == 2){ //Robot turns right
            a=-1800;
            }

            if(counter == 3){ //Robot turns right
            a=-1800;
            }
            
            if(counter == 4){ // Robot Stops Moving
            while(1){   
              
            }
            // Robot Stops Moving
            }
            positions[0] = a;
            positions[1] = a;
            steppers.moveTo(positions);
            steppers.runSpeedToPosition(); // This function stops movements until steppers are in place
        }    
}




            
