#include "vex.h"

using namespace vex;

extern controller Controller1;
extern motor RightDriveSmart;
extern motor LeftDriveSmart;
extern motor Intake;

void setMotors()
{
  RightDriveSmart.setVelocity(0.0, velocityUnits::pct);
  LeftDriveSmart.setVelocity(0.0, velocityUnits::pct);
  Intake.setVelocity(0, velocityUnits::pct);
}

void intakeSpin(bool intakeClickState, bool intakeMotorState)
{

  if(Controller1.ButtonR1.pressing() && intakeClickState)
  {
    intakeMotorState = !intakeMotorState;
    intakeClickState = false;
  }
  if(!Controller1.ButtonR1.pressing()) intakeClickState = true;

  if(intakeMotorState) Intake.spin(directionType::fwd, 100, velocityUnits::pct);
  if(!intakeMotorState) Intake.spin(directionType::fwd, 0, velocityUnits::pct);
}

void intakeRev()
{
  if (Intake.direction() == directionType::fwd)
  {
    Intake.setReversed(true);
  }

  if (Intake.direction() == directionType::rev)
  {
    Intake.setReversed(false);
  }
}

void move()
{
  if(abs(Controller1.Axis3.position()) > 20)
  {
    RightDriveSmart.spin(directionType::fwd, Controller1.Axis3.position() + 27, velocityUnits::pct );
    LeftDriveSmart.spin(directionType::rev, Controller1.Axis3.position() + 27, velocityUnits::pct);
  }

  if(abs(Controller1.Axis1.position()) > 0) 
  {
    RightDriveSmart.spin(directionType::fwd, Controller1.Axis1.position(), velocityUnits::pct);
    LeftDriveSmart.spin(directionType::rev, Controller1.Axis1.position(), velocityUnits::pct);
  }
}