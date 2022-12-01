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
extern motor RightDriveSmart;
extern motor LeftDriveSmart;
extern motor Intake;

competition Competition = competition();

bool checkClick = false;
bool checkMotor = false;

void autonomous()
{
<<<<<<< HEAD
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
=======
>>>>>>> e38745444087a9033a8f6af47f872622a9a1c10e

}

void preAuton()
{
  vexcodeInit();
}

//-------------------------------------------------------------------------------

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

//---------------------------------------------------------------------------------


void setMotors()
{
  RightDriveSmart.setVelocity(0.0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0.0, velocityUnits::pct);
  Intake.setVelocity(0, velocityUnits::pct);
}

void move()
{
  if(abs(Controller1.Axis3.position()) > 20)
  {
    RightDriveSmart.spin(directionType::fwd, Controller1.Axis3.position() + 27, velocityUnits::pct);
    LeftDriveSmart.spin(directionType::rev, Controller1.Axis3.position() + 27, velocityUnits::pct);
  }
  
    //turn left/right
    RightDriveSmart.spin(directionType::fwd, Controller1.Axis1.position(), velocityUnits::pct);
    LeftDriveSmart.spin(directionType::rev, Controller1.Axis1.position(), velocityUnits::pct);
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

    intakeSpinFWD();
    Controller1.ButtonR2.pressed(intakeStop);

    move();

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