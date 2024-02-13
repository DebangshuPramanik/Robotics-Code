#include "main.h"
#include "../../include/sMechanismHeaders/ePID.hpp"

//Helper Functions
void setDrive(int left, int right){
    leftFront = -left;  //These are all motors listed inside this function. 
    leftMiddle = -left; //Left and right sides are opposite sided because relative to the bot's center.
    leftBack = -left;   //the two sides need to spin in opposite directions to move the bot in the same direction with same input. 
    rightFront = right;
    rightMiddle = right;
    rightBack = right;
}
void resetDriveEncoders(){ //Tares all motors for positional autonomous uses.
    leftFront.tare_position();
    leftMiddle.tare_position();
    leftBack.tare_position();
    rightFront.tare_position();
    rightMiddle.tare_position();
    rightBack.tare_position();
}
double averageMotorPosition(){ //Returns the average drivetrain position of the bot.
    return ((-(leftFront.get_position() + leftMiddle.get_position() + leftBack.get_position())
         + rightFront.get_position() + rightMiddle.get_position() + rightBack.get_position())/6); 
}
double leftDriveAvgPosition(){ //Returns average drive position of the left driveTrain. 
   return((-(leftFront.get_position() + leftMiddle.get_position() + leftBack.get_position()))/3);
} //negative sign because leftDrive motors are set to negative above. 
double rightDriveAvgPosition(){ //Returns average drive position of the right driveTrain. 
   return((rightFront.get_position() + rightMiddle.get_position() + rightBack.get_position())/3);
} //no negative because rightDrive motors are set to positive above.

//Autonomous functions
void translate(double distance){ //distance is + if going forward and - if going backward. Units for distance are in inches
    drivePID(distance);
}
void rotate(int degrees){ //Units are what is mentioned in the parameter. + is right turn, - is left turn, of the mentioned degrees
    turnPID(degrees);
}
void uTurn(){
    turnPID(180);
}

//Driver Control Functions
void setArcadeDrive(){ //Sets up Arcade drive
   int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);           //Sets up drive joystick
   int driveDirection = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  //Sets up turn joystick
   if(abs(driveDirection)<10){
    driveDirection = 0; //Sets degree of left joystick movement to 0 if joystick isn't being moved that much.
   }

   //Caps drive axes at maximum and minimum voltages
   if(driveDirection < -127){
      driveDirection = -127;
   }
   else if(driveDirection > 127){
      driveDirection = 127;
   }
   if(turn > 127){
      turn = 127;
   }
   else if(turn < -127){
      turn = -127;
   }
  
   //Sets drive assuming there is no turn
   setDrive(driveDirection,driveDirection);
       
   //Driver wants to turn (Turning deadzone done implicitly)
   if(turn>10){ //turn right
     setDrive(driveDirection + turn, driveDirection); 
     if(abs(driveDirection) < 10){
        setDrive(turn,-turn); //If complaints multiply turn by 3/4
     }
   }
    if(turn<-10){ //turn left
    setDrive(driveDirection, driveDirection + turn); 
     if(abs(driveDirection) < 10){
        setDrive(-turn, turn); //If complaints multiply turn by 3/4
     }
   }
   bool uTUrnButton = controller.get_digital(pros::E_CONTROLLER_DIGITAL_B); //U Turn Button...
   if(uTUrnButton){
      uTurn();
   }
   pros::delay(5);
}