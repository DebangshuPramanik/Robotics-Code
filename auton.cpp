#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void autonomous() {
     translate(12.5);
     translate(-12.5);
}

//Assuming we are starting on the side of the goal we will be scoring under. 
void offensiveStart(){

}
//Assuming we are starting on the side of the goal our opponent will be scoring under. 
void defensiveStart(){

}

void programmingSkills(){ //Assumming start on the center of the tile with the goal corner and PVC pipe corner.
     translate(-24);
     rotate(90);    ///****Reverse and push in alliance-colored triballs into 'opponent' goal.*********
     translate(12);

     translate(36); 
     rotate(45);     //**********Reverse from goal to loading bar************
     translate(2);

     fireCata(30); //*********Fire cata at full power for 100 seconds************

     rotate(-135);
     translate(72); //***********Get through the corridor and then slight left. Then push in some triballs???**********
     rotate(-45); 
     translate(36 * sqrt(2));

     rotate(-45);
     translate(-12);
     translate(12);
     translate(-12); //*********Stuff in triballs on the right side of the goal. Then move towards the PVC pipe. 
     rotate(-30);
     translate(13.5);
     translate(-13.5);
     
     rotate(-60);
     translate(24);
     rotate(90);
     translate(24);
     translate(-24);
     rotate(-90);
     translate(24);  //**********Ram the center of the goal.***********
     rotate(90);
     translate(24);
     translate(-24);
     rotate(-90);

     translate(24);
     rotate(90);
     translate(48);
     rotate(90);
     translate(12);  //********Ram the left side of the goal.***********
     translate(-12);
     rotate(-30);
     translate(18);
     translate(-18);
     rotate(60);
     translate(18);
}