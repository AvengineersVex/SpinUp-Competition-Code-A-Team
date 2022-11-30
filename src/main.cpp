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
// Drivetrain           drivetrain    7, 10           
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <string>
using namespace vex;

extern controller Controller1;
extern motor RightDriveSmart;
extern motor LeftDriveSmart;

competition Competition = competition();

void usercontrol(void)
{
  // RightDriveSmart.setVelocity(0.0, velocityUnits::pct);
  // LeftDriveSmart.setVelocity(0.0, velocityUnits::pct);

  while(true)
  {
    // if (Controller1.Axis1.position() != 0) {
    //   Brain.Screen.print(Controller1.Axis1.position() + '\n');
    // }
    // if (Controller1.Axis3.position() != 0)
    // {
    //   LeftDriveSmart.spin(directionType::fwd, Controller1.Axis3.position(), velocityUnits::pct);
    //   RightDriveSmart.spin(directionType::fwd, Controller1.Axis3.position(), velocityUnits::pct);
      
    // }

    // else if (Controller1.Axis2.position() != 0 && Controller1.Axis2.position(pct) > 5)
    // {
    //   LeftDriveSmart.spin(directionType::fwd, Controller1.Axis2.position(), velocityUnits::pct);
    //   RightDriveSmart.spin(directionType::fwd, Controller1.Axis2.position(), velocityUnits::pct);
    
      
    // }

    // // else
    // {
    //   LeftDriveSmart.stop(brake);
    //   RightDriveSmart.stop(brake);
    // }


    if(Controller1.Axis3.position()>0)
    {
      Drivetrain.setDriveVelocity(Controller1.Axis3.position(), velocityUnits::pct);
      Drivetrain.drive(forward);
    }

    else if(Controller1.Axis3.position()<0)
    {
      Drivetrain.setDriveVelocity(Controller1.Axis3.position(), velocityUnits::pct);
      Drivetrain.drive(reverse);
    }

     if(Controller1.Axis1.position()>0)
    {
      Drivetrain.turn(leftController1.Axis3.position(), velocityUnits::pct);
      Drivetrain.drive(forward);
    }

    wait(20, msec);
  }

}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Competition.drivercontrol(usercontrol);
}