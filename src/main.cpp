// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// PistonL              led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// PistonR              led           B               
// catapult             motor         9               
// Roller               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// PistonL              led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// PistonR              led           B               
// catapultLeft         motor         9               
// Roller               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// PistonL              led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// PistonR              led           B               
// catapultRight        motor         9               
// Roller               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// PistonL              led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// PistonR              led           B               
// catapultRight        motor         9               
// Roller               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// PistonL              led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// PistonR              led           B               
// catapultRight        motor         9               
// Roller               motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "vex.h"
#include <string>
using namespace vex;

extern controller Controller1;

extern motor leftTop;
extern motor leftBot;
extern motor rightTop;
extern motor rightBot;
extern motor catapult;

extern motor Intake;
extern motor Roller;

competition Competition = competition();

void preAuton()
{
  vexcodeInit();
}

void autonomous()
{
  Roller.spinFor(reverse,50,degrees);
}

void setMotors()
{
  Intake.setVelocity(0, velocityUnits::pct);  

  // Drivetrain.setStopping(hold);
  leftTop.setStopping(brake);
  leftBot.setStopping(brake);
  rightTop.setStopping(brake);
  rightBot.setStopping(brake);
  Roller.setStopping(hold);

  catapult.setStopping(hold);
}

void move()
{

  leftTop.spin(forward, Controller1.Axis3.position(pct), percent);
  leftBot.spin(forward, Controller1.Axis3.position(pct), percent);
  rightTop.spin(reverse, Controller1.Axis3.position(pct), percent);
  rightBot.spin(reverse, Controller1.Axis3.position(pct), percent);

  if (Controller1.Axis1.position() > 0)
  {
    leftTop.spin(forward, Controller1.Axis1.position(pct), percent);
    leftBot.spin(forward, Controller1.Axis1.position(pct), percent);
    rightTop.spin(forward, Controller1.Axis1.position(pct), percent);
    rightBot.spin(forward, Controller1.Axis1.position(pct), percent);
  }
  else if (Controller1.Axis1.position() < 0)
  {
    leftTop.spin(forward, Controller1.Axis1.position(pct), percent);
    leftBot.spin(forward, Controller1.Axis1.position(pct), percent);
    rightTop.spin(forward, Controller1.Axis1.position(pct), percent);
    rightBot.spin(forward, Controller1.Axis1.position(pct), percent);
  }
}

void catapultOn()
{
  catapult.spin(reverse, 40, percent);
}

void catapultOff()
{
  catapult.stop();
}

void intakeStop() 
{
  Intake.stop(hold);
}

void intakeForward() 
{
  Intake.spin(forward, 100, velocityUnits::pct);
}

void intakeReverse()
{
  Intake.spin(forward, -100, velocityUnits::pct);
}

void rollerOn()
{
  Roller.spin(forward, 100, pct);
}

void rollerOff()
{
  Roller.stop();
}

int pneumatic()
{
  return 0;
}

void push()
{
  // Brain.Screen.print("Pushed button UP");
  PistonL.set(true);
  PistonR.set(true);
}

void retract()
{
  // Brain.Screen.print("Pushed button DOWN");
  PistonL.set(false);
  PistonR.set(false);
}

void usercontrol(void)
{
  setMotors();

  // Controller1.ButtonR2.pressed(intakeRev);
  while(true)
  {
    //intake code should go here

    move();

    Controller1.ButtonB.pressed(intakeReverse);
    Controller1.ButtonY.pressed(intakeStop);
    Controller1.ButtonA.pressed(intakeStop);
    Controller1.ButtonX.pressed(intakeForward);
       
    Controller1.ButtonR2.pressed(push);
    Controller1.ButtonR1.pressed(retract);

    Controller1.ButtonLeft.pressed(rollerOn);
    Controller1.ButtonRight.pressed(rollerOff);

    Controller1.ButtonL2.pressed(catapultOff);
    Controller1.ButtonL1.pressed(catapultOn);

    Controller1.ButtonUp.pressed(autonomous);

    wait(15, msec);
    pneumatic();

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