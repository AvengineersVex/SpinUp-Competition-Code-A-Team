using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor Intake;
extern motor leftTop;
extern motor leftBot;
extern motor rightTop;
extern motor rightBot;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );