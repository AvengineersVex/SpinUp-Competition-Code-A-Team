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