using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Intake;
extern led PistonL;
extern motor leftTop;
extern motor leftBot;
extern motor rightTop;
extern motor rightBot;
extern led PistonR;
extern motor catapult;
extern motor Roller;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );