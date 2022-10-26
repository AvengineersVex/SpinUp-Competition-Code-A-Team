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

using namespace vex;

extern controller Controller1;
extern motor RightDriveSmart;
extern motor LeftDriveSmart;
extern motor Intake;

competition Competition = competition();

void set_motors()
{
  RightDriveSmart.setVelocity(0.0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0.0, velocityUnits::pct);
  Intake.setVelocity(0, velocityUnits::pct);
}

void move()
{
  if(abs(Controller1.Axis3.position()) > 20)
  {
    RightDriveSmart.setVelocity(Controller1.Axis3.position() + 27, velocityUnits::pct);
    LeftDriveSmart.setVelocity(Controller1.Axis3.position() + 27, velocityUnits::pct);
  }

  if(abs(Controller1.Axis1.position()) > 0) 
  {
    RightDriveSmart.setVelocity(Controller1.Axis1.position(), velocityUnits::pct);
    LeftDriveSmart.setVelocity(Controller1.Axis1.position(), velocityUnits::pct);
  }
}

void usercontrol(void)
{
  set_motors();

  while(true)
  {
    //intake code should go here

    move();

    wait(20, msec);
  }
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Competition.drivercontrol(usercontrol);
}