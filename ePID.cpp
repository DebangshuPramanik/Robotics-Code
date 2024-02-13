#include "main.h"

double kP;
double kI;  //PID constants declared globally because they need to be used globally.
double kD;

void setPIDConstants(double newKP, double newKI, double newKD){ //Sets PID Constants
    kP = newKP;
    kI = newKI;
    kD = newKD;
}

//Real PID
void drivePID(double distance){ //distance is in inches
  resetDriveEncoders(); //Resets encoder values to 0, so that the motors now travel the desire distance. 
  
  distance *= 90/M_1_PI;  //Conversion of the entered distance into motor encoder units: degrees. ==> (inches)(1 rev/4pi inches)(360 deg/1 rev)
  int drivePower = 2; //Initializes drivePower. 
  double error;
  double prevError = distance;
  double integral = 0.0; //******* Remaining PID Constants Declared *************
  double derivative;
  setPIDConstants(0.5, 0.01, 0.3); //Actually sets PID constants to their desired values. 
  while(drivePower != 0){
      error = distance - averageMotorPosition();
      integral += error;
      if(integral > 5000){
        integral = 5000;
      }
      if(error <= 0 || error > 8000){
        integral = 0.0;
      }
      derivative = error - prevError;
      prevError = error;
      drivePower = int((kP * error) + (kI * integral) + (kD * derivative));
      setDrive(drivePower, drivePower);
      pros::delay(15); //Sets delay Time 
  }
}
void turnPID(int degrees){ //Turning units is in degrees.| + is to the right, - is to the left. 
    resetDriveEncoders(); //Resets encoder values so that the bot clearly turns the desired distance
    int drivePower = 2;   //********* Turn Related variables declared ************
    int turnConstant = 2; //wheel turn = turnConstant * robot Turn //TurnConstant is always positive
    int destination = degrees * turnConstant;

    double turnError;
    double prevError = degrees;
    double turnIntegral = 0.0; //******* Remaining PID Constants Declared *************
    double derivative;
    setPIDConstants(0.5, 0.01, 0.3); //Actually sets PID constants to their desired values. 

    double position;
    if(degrees < 0){
        position = rightDriveAvgPosition();
    }                                       //********* Position Related variables declared ************
    else if(degrees > 0){
        position = leftDriveAvgPosition();
    }
//While loop started to execute the actual turnPID itself. 
    while(drivePower != 0){
        turnError = destination - position;
        turnIntegral += turnError;
        if(turnIntegral > 5000){
            turnIntegral = 5000;
        }
        derivative = turnError - prevError;
        prevError = turnError;
        drivePower = int((kP * turnError) + (kI * turnIntegral) + (kD * derivative));
        if(destination/-1 == abs(destination)){ //If destination/turning degrees is negative/ 
            setDrive(-drivePower, drivePower);
        }
        else{
            setDrive(drivePower, -drivePower);
        }
        pros::delay(15); //Sets delay time.
    } 
}