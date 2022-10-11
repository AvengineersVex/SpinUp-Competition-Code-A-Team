/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\85547                                            */
/*    Created:      Tue Oct 11 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

extern controller Controller1;
extern motor RightDriveSmart;
extern motor LeftDriveSmart;

competition Competition = competition();

void usercontrol(void)
{
  RightDriveSmart.setVelocity(0.0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0.0, velocityUnits::pct);

  RightDriveSmart.spin(directionType::fwd);
  LeftDriveSmart.spin(directionType::rev);

  while(true)
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

    wait(20, msec);
  }

}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Competition.drivercontrol(usercontrol);
}