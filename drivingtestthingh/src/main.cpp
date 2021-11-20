/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\sprin                                            */
/*    Created:      Sun Nov 14 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftFront            motor         20              
// LeftBack             motor         10              
// RightFront           motor         9               
// Rightback            motor         1               
// leftarm              motor         2               
// rightarm             motor         5               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
float autonSpeed=75;
using namespace vex;



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!

  vexcodeInit();
  float speed =1;
  float stop = 1;
  bool auton=true;
  leftarm.resetPosition();
  rightarm.resetPosition();

  if (auton) {
    //oposite side of goal on platform auton
  
    spinArm(-660,75);
    moveForward(44);
    spinArm(650,50);
    vex::task::sleep( 500 );
    autonSpeed=60;
    moveForward(-10);
    turnFor(-50);
    autonSpeed=50;
    spinArm(-650,50);
    moveForward(42);
    spinArm(650,50);  
    moveForward(-50);
  

  //  moveForward(40);

  }

  while(1==1){

  if (Controller1.ButtonA.pressing()){
    speed = .4;
  }
  if (Controller1.ButtonB.pressing()){
    speed = 1;
  }

  Rightback.spin(directionType::fwd,Controller1.Axis2.value()*speed,velocityUnits::pct);
  RightFront.spin(directionType::fwd,Controller1.Axis2.value()*speed,velocityUnits::pct);
  LeftFront.spin(directionType::fwd,Controller1.Axis3.value()*speed,velocityUnits::pct);
  LeftBack.spin(directionType::fwd,Controller1.Axis3.value()*speed,velocityUnits::pct);

    if (Controller1.ButtonL1.pressing()) { //up
      leftarm.spin(directionType::fwd, 100, velocityUnits::pct);
      rightarm.spin(directionType::fwd, 100, velocityUnits::pct);

      stop=1;
    }

    else if(Controller1.ButtonL2.pressing()) { //down
      leftarm.spin(directionType::rev, 40*stop, velocityUnits::pct);
      rightarm.spin(directionType::rev, 40*stop, velocityUnits::pct);

    if(leftarm.position(deg)<-680){
      stop = 0;

    }

    }

    else {
      leftarm.setStopping(brakeType::hold);      
      leftarm.spin(directionType::rev, 0, velocityUnits::pct);
      rightarm.setStopping(brakeType::hold);      
      rightarm.spin(directionType::rev, 0, velocityUnits::pct);
    }

  
  }
  }
 
 
  

