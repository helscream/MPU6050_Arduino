/* Author = helscream (Omer Ikram ul Haq)
Last edit date = 2014-10-08
Website: http://hobbylogs.me.pn/?p=47
Location: Pakistan
Ver: 0.1 beta --- Start
Ver: 0.2 beta --- Bug fixed for calculating "angle_y_accel" and "angle_x_accel" in "Gyro_header.ino" file
*/


#include <Wire.h>
#include "gyro_accel.h"
// Defining constants
#define dt 20                       // time difference in milli seconds
#define rad2degree 57.3              // Radian to degree conversion
#define Filter_gain 0.95             // e.g.  angle = angle_gyro*Filter_gain + angle_accel*(1-Filter_gain)
// *********************************************************************
//    Global Variables
// *********************************************************************
unsigned long t=0; // Time Variables
float angle_x_gyro=0,angle_y_gyro=0,angle_z_gyro=0,angle_x_accel=0,angle_y_accel=0,angle_z_accel=0,angle_x=0,angle_y=0,angle_z=0;
// *********************************************************************
// Main Code
void setup(){
  Serial.begin(115200);
  Wire.begin();
  MPU6050_ResetWake();
  MPU6050_SetGains(0,1);// Setting the lows scale
  MPU6050_SetDLPF(0); // Setting the DLPF to inf Bandwidth for calibration
  MPU6050_OffsetCal();
  MPU6050_SetDLPF(6); // Setting the DLPF to lowest Bandwidth
  
  
  
  Serial.print("gyro_x_scalled");
  Serial.print("\tgyro_y_scalled");
  Serial.print("\tgyro_z_scalled");
  
  Serial.print("\taccel_x_scalled");
  Serial.print("\taccel_y_scalled");
  Serial.print("\taccel_z_scalled");
  
  Serial.print("\tangle_x_gyro");
  Serial.print("\tangle_y_gyro");
  Serial.print("\tangle_z_gyro");
  
  Serial.print("\tangle_x_accel");
  Serial.print("\tangle_y_accel");
  Serial.print("\tangle_z_accel");
  
  Serial.print("\tangle_x");
  Serial.print("\tangle_y");
  Serial.print("\tangle_z");
  
  Serial.println("\tLoad");

  
    
  t=millis(); 
}
void loop(){
  t=millis(); 
  
  MPU6050_ReadData();
 
  angle_x_gyro = (gyro_x_scalled*((float)dt/1000)+angle_x);
  angle_y_gyro = (gyro_y_scalled*((float)dt/1000)+angle_y);
  angle_z_gyro = (gyro_z_scalled*((float)dt/1000)+angle_z);

  angle_z_accel = atan(accel_z_scalled/(sqrt(accel_y_scalled*accel_y_scalled+accel_x_scalled*accel_x_scalled)))*(float)rad2degree;
  angle_y_accel = -atan(accel_y_scalled/(sqrt(accel_y_scalled*accel_y_scalled+accel_z_scalled*accel_z_scalled)))*(float)rad2degree;
  angle_x_accel = atan(accel_x_scalled/(sqrt(accel_x_scalled*accel_x_scalled+accel_z_scalled*accel_z_scalled)))*(float)rad2degree;

  angle_x = Filter_gain*angle_x_gyro+(1-Filter_gain)*angle_x_accel;
  angle_y = Filter_gain*angle_y_gyro+(1-Filter_gain)*angle_y_accel;
  angle_z = Filter_gain*angle_z_gyro+(1-Filter_gain)*angle_z_accel;
  

  Serial.print(gyro_x_scalled);
  Serial.print("\t");
  Serial.print(gyro_y_scalled);
  Serial.print("\t");
  Serial.print(gyro_z_scalled);
  Serial.print("\t");


  Serial.print(accel_x_scalled);
  Serial.print("\t");
  Serial.print(accel_y_scalled);
  Serial.print("\t");
  Serial.print(accel_z_scalled);
  Serial.print("\t");
 
  Serial.print(angle_x_gyro);
  Serial.print("\t");
  Serial.print(angle_y_gyro);
  Serial.print("\t");
  Serial.print(angle_z_gyro);
  Serial.print("\t"); 
   
  Serial.print(angle_x_accel);
  Serial.print("\t");
  Serial.print(angle_y_accel);
  Serial.print("\t");
  Serial.print(angle_z_accel);
  Serial.print("\t"); 


  Serial.print(angle_x);
  Serial.print("\t");
  Serial.print(angle_y);
  Serial.print("\t");
  Serial.print(angle_z);
  Serial.print("\t");
  
   

  Serial.println(((float)(millis()-t)/(float)dt)*100);

  
  while((millis()-t) < dt){ // Making sure the cycle time is equal to dt
  // Do nothing
  }
  

}




  
