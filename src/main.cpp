#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Intake               motor         15              
// Piston               led           A               
// leftTop              motor         7               
// leftBot              motor         12              
// rightTop             motor         10              
// rightBot             motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
#include <string>
using namespace vex;

extern controller Controller1;

extern motor leftTop;
extern motor leftBot;
extern motor rightTop;
extern motor rightBot;

// extern drivetrain Drivetrain;

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

void test()
{
  // Drivetrain.driveFor(forward, 12, inches);
  // Drivetrain.turnFor(right, 90, degrees);
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

  // Drivetrain.setStopping(hold);
  leftTop.setStopping(hold);
  leftBot.setStopping(hold);
  rightTop.setStopping(hold);
  rightBot.setStopping(hold);
}

void move()
{
  
  //  if(Controller1.Axis3.position(pct) > 5)
  // {
  //   Drivetrain.drive(directionType::fwd, Controller1.Axis3.position(pct), velocityUnits::pct);
  // }

  // else if(Controller1.Axis3.position(pct) < -5)
  // {
  //   Drivetrain.drive(directionType::rev, Controller1.Axis3.position(pct), velocityUnits::pct);
  // }

  // if (Controller1.Axis1.position(pct) > 5)
  // {
  //   Drivetrain.turn(right, Controller1.Axis1.position(pct), velocityUnits::pct);
  // }

  // else if (Controller1.Axis1.position(pct) < -5)
  // {
  //   Drivetrain.turn(left, Controller1.Axis1.position(pct), velocityUnits::pct);
  // }


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

int pneumatic()
{
  return 0;
}

void push()
{
  Brain.Screen.print("Pushed button UP");
  Piston.set(true);
}

void retract()
{
  Brain.Screen.print("Pushed button DOWN");
  Piston.set(false);
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
       
    Controller1.ButtonUp.pressed(push);
    Controller1.ButtonDown.pressed(retract);
    Controller1.ButtonLeft.pressed(test);

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