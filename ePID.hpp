#include "main.h"

void setPIDConstants(double newKP, double newKI, double newKD); //Sets PID Constants

//Real PID
void drivePID(double distance);  //Hopefully makes robot move an accurate distance during auton
void turnPID(int degrees);   //Hopefully makes robot turn an accurate amount during auton