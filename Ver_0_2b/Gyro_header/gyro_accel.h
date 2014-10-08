/* Author = helscream (Omer Ikram ul Haq)
Last edit date = 2014-10-08
Website: http://hobbylogs.me.pn/?p=47
Location: Pakistan
Ver: 0.1 beta --- Start
Ver: 0.2 beta --- Bug fixed for calculating "angle_y_accel" and "angle_x_accel" in "Gyro_header.ino" file
*/

#ifndef gyro_accel.h
  #define gyro_accel.h
  
  extern int accel_x_OC, accel_y_OC, accel_z_OC, gyro_x_OC ,gyro_y_OC, gyro_z_OC; // offset variables
  extern float temp_scalled,accel_x_scalled,accel_y_scalled,accel_z_scalled,gyro_x_scalled,gyro_y_scalled,gyro_z_scalled; //Scaled Data variables

  
  void MPU6050_ReadData();
  void MPU6050_ResetWake();
  void MPU6050_SetDLPF(int BW);
  void MPU6050_SetGains(int gyro,int accel);
  void MPU6050_OffsetCal();
 
#endif

