#include "main.h"

//Helper functions
void setDrive(int left, int right);
void resetDriveEncoders();
double averageMotorPosition();
double leftDriveAvgPosition();
double rightDriveAvgPosition();

//Driver control functions
void setArcadeDrive();

//Autonomous functions
void translate(double units);
void rotate(int degrees);
void uTurn();