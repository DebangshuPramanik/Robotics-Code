#include "main.h"

//Helper Functions
void setIntake(int power){
  intakeMotor = power;    
}

//Intake Functions
void setIntakeMotor(){                       
  int intakePower;
  if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)==1){
    intakePower = 127;
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)==1){
    intakePower = -127;
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)==0){
    intakePower = 0;
  }
  else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)==0){
    intakePower = 0;
  }
  setIntake(intakePower);
}

//Autonomous functions
void runIntakeFor(int seconds, int direction){ //Direction is either 1 or -1
  int time = 0;
  while(time < seconds * 1000){
     setIntake(127 * direction);
     time +=10;
     pros::delay(10);
  }
}
void inTriball(){
  runIntakeFor(1, 1);
}
void outTriball(){
  runIntakeFor(1, -1);
}
