#include "main.h"
#include "../../include/pros/motors.h"

//Catapult and intake motors initialized
pros::Motor catapultMotor(20); //Motor for catapult is green motor. Other options: red motor E_Motor_Gearset_36
                                                        //& blue motor: E_Motor_Gearset_06. true = backward and false = forward
pros::Motor intakeMotor(11);

//Drivetrain motors initialized
pros::Motor rightFront(9);
pros::Motor rightMiddle(8);
pros::Motor rightBack(10);
pros::Motor leftFront(18);
pros::Motor leftMiddle(17);
pros::Motor leftBack(19);

//Controller initialized
pros::Controller controller(pros::E_CONTROLLER_MASTER); 