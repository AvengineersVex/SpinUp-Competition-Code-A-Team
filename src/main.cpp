// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// leftBot              motor         12              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// leftTop              motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    7, 12, 18, 10   
// Intake               motor         15              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    7, 12, 18, 10   
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    7, 10           
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    7, 10           
// Controller1          controller                    
// Intake               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3            
// Controller1          controller                    
// Intake               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3            
// Controller1          controller                    
// Intake               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3            
// Controller1          controller                    
// Intake               motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       A Team Programming                                        */
/*    Created:      Tue Oct 11 2022                                           */
/*    Description:  VEX Spin Up 2022                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <string>
using namespace vex;

extern controller Controller1;

extern motor leftTop;
extern motor leftBot;
extern motor rightTop;
extern motor rightBot;

extern motor Intake;

competition Competition = competition();

bool isMotorSpinning = false;
bool isClockwise = false;

void preAuton()
{
  vexcodeInit();
}

void autonomous()
{

}

// void intakeSpinFWD(){ //rename to direction toggle or smth
  
//   // while (true){

//   //   if(Controller1.ButtonR1.pressing() && checkClick && checkMotor){
//   //     checkMotor = false;
//   //     checkClick = false;
//   //     break;
//   //   }

//   //   if(Controller1.ButtonR1.pressing() && !checkClick  && !checkMotor){
//   //     checkClick = true;
//   //     checkMotor = true;
//   //     break;
//   //   }
  
//   // }

//   // if(!checkMotor) {Intake.spin(directionType::rev, 100, velocityUnits::pct);}
//   // if(checkMotor) {Intake.spin(directionType::fwd, 100, velocityUnits::pct);}
//   // // Vansh, Akhil, Sathvik and Shaurya shed blood for this




// }

void setMotors()
{
  Intake.setVelocity(0, velocityUnits::pct);
  rightBot.setReversed(true);
  

  leftTop.setStopping(hold);
  leftBot.setStopping(hold);
  rightTop.setStopping(hold);
  rightBot.setStopping(hold);
}

void move()
{
  leftTop.spin(forward, Controller1.Axis3.position(pct), percent);
  leftBot.spin(forward, Controller1.Axis3.position(pct) * 0.8, percent);
  rightTop.spin(forward, Controller1.Axis3.position(pct), percent);
  rightBot.spin(forward, Controller1.Axis3.position(pct) * 0.8, percent);

  if (Controller1.Axis1.position() > 0)
  {
    leftTop.spin(forward, Controller1.Axis1.position(pct), percent);
    leftBot.spin(forward, Controller1.Axis1.position(pct) * 0.8 , percent);
    rightTop.spin(forward, -Controller1.Axis1.position(pct), percent);
    rightBot.spin(forward, -Controller1.Axis1.position(pct) * 0.8, percent);
  }
  else if (Controller1.Axis1.position() < 0)
  {
    leftTop.spin(forward, -Controller1.Axis1.position(pct), percent);
    leftBot.spin(forward, -Controller1.Axis1.position(pct) * 0.8 , percent);
    rightTop.spin(forward, Controller1.Axis1.position(pct), percent);
    rightBot.spin(forward, Controller1.Axis1.position(pct) * 0.8, percent);
  }
}

void intakeStop() 
{
  Intake.stop(hold);
}

void intakeStart() 
{
  Intake.spin(forward, 100, velocityUnits::pct);
}

void intakeReverse()
{
  Intake.spin(forward, -100, velocityUnits::pct);
}

void usercontrol(void)
{
  setMotors();

  // Controller1.ButtonR2.pressed(intakeRev);
  while(true)
  {
    //intake code should go here

    move();

    Controller1.ButtonX.pressed(intakeStart);
    Controller1.ButtonB.pressed(intakeReverse);
    Controller1.ButtonY.pressed(intakeStop);
    Controller1.ButtonA.pressed(intakeStop);
   
    wait(20, msec);
  }
}

int main() {

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  preAuton();

  while (true)
  {
    wait(100, msec);
  }
}