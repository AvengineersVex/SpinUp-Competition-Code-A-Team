#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor Intake = motor(PORT15, ratio18_1, false);
led PistonL = led(Brain.ThreeWirePort.A);
motor leftTop = motor(PORT7, ratio18_1, false);
motor leftBot = motor(PORT12, ratio18_1, false);
motor rightTop = motor(PORT10, ratio18_1, false);
motor rightBot = motor(PORT18, ratio18_1, false);
led PistonR = led(Brain.ThreeWirePort.H);
motor flywheel = motor(PORT3, ratio6_1, false);
motor Roller = motor(PORT8, ratio18_1, false);
motor Indexer = motor(PORT14, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}