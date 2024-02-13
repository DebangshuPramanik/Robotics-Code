#include "main.h"
#include "../../include/pros/motors.h"

//Helper functions
void setCata(int power){
    catapultMotor = power;
}

//Catapult functions
void spamCata(){ //Useful for throwing all the preload triballs to the opponents' side.
    int catapultPower;
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 1){
         catapultPower = 127;
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1){
        catapultPower = -127;
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) == 0){
        catapultPower = 0;
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 0){
        catapultPower = 0;
    }
    setCata(catapultPower);
}

void midfieldCata(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) == 1){
        catapultMotor.move_absolute(360,100); //Fires 
        catapultMotor.tare_position();//Resets position after firing
    } //We will use this function when we connect our intake to our catapult.
}

//Autonomous Functions
 void fireCata(int seconds){ //Fires catapult 
        int time = 0;
        while(time<seconds*1000){
           setCata(127);
           time +=10;
           pros::delay(10);
        }
 }