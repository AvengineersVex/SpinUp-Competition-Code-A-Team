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

bool checkClick = false;
bool checkMotor = false;

void preAuton()
{
  vexcodeInit();
}

void autonomous()
{

}

void intakeSpinFWD(){ //rename to direction toggle or smth
  
  while (true){

    if(Controller1.ButtonR1.pressing() && checkClick && checkMotor){
      checkMotor = false;
      checkClick = false;
      break;
    }

    if(Controller1.ButtonR1.pressing() && !checkClick  && !checkMotor){
      checkClick = true;
      checkMotor = true;
      break;
    }
  
  }

  if(!checkMotor) {Intake.spin(directionType::rev, 100, velocityUnits::pct);}
  if(checkMotor) {Intake.spin(directionType::fwd, 100, velocityUnits::pct);}
  // Vansh, Akhil, Sathvik and Shaurya shed blood for this
}

void setMotors()
{
  Intake.setVelocity(0, velocityUnits::pct);
}

void move()
{
  //2wd settings
  //295 mm width, 165 mm wheelbase, 2:1 gear ratio
  // //front to back 1.25 wheel size ratio

  if (Controller1.Axis3.position(pct) > 15)
  {
    leftTop.spin(forward, Controller1.Axis3.position(), velocityUnits::pct);
    // leftBot.spin(forward, Controller1.Axis3.position() * 0.8, velocityUnits::pct);
    rightTop.spin(forward, -Controller1.Axis3.position(), velocityUnits::pct);
    // rightBot.spin(forward, Controller1.Axis3.position() * 0.8, velocityUnits::pct);
  } 

  else if (Controller1.Axis3.position(pct) < -15) {
    leftTop.spin(forward, -Controller1.Axis3.position(), velocityUnits::pct);
    // leftBot.spin(reverse, Controller1.Axis3.position() * 0.8, velocityUnits::pct);
    rightTop.spin(forward, Controller1.Axis3.position(), velocityUnits::pct);
    // rightBot.spin(reverse, Controller1.Axis3.position() * 0.8, velocityUnits::pct);
  }

  if (Controller1.Axis1.position(pct) < -15)
  {
    leftTop.spin(forward, Controller1.Axis1.position(), velocityUnits::pct);
    // leftBot.spin(forward, Controller1.Axis1.position() * 0.8, velocityUnits::pct);
    rightTop.spin(reverse, Controller1.Axis1.position(), velocityUnits::pct);
    // rightBot.spin(reverse, Controller1.Axis1.position() * 0.8, velocityUnits::pct);
  }

  else if (Controller1.Axis1.position(pct) > 15)
  {
    leftTop.spin(reverse, Controller1.Axis1.position(), velocityUnits::pct);
    // leftBot.spin(reverse, Controller1.Axis1.position() * 0.8, velocityUnits::pct);
    rightTop.spin(forward, Controller1.Axis1.position(), velocityUnits::pct);
    // rightBot.spin(forward, Controller1.Axis1.position() * 0.8, velocityUnits::pct);
  }

  // leftTop.spin(forward, Controller1.Axis2.position(), pct);
}

void intakeStop() {
  Intake.stop(hold);
}

void usercontrol(void)
{
  setMotors();

  // Controller1.ButtonR2.pressed(intakeRev);
  while(true)
  {
    //intake code should go here

    move();

    // intakeSpinFWD();
    Controller1.ButtonR2.pressed(intakeStop);

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