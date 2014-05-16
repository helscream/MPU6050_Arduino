MPU6050_Arduino
===============

Please follow this link for better formated explanation 
http://hobbylogs.me.pn/?p=47



gyro_accel header file description
This header will only work for MPU6050 based boards using I2C address of 0x68 and it should work on both Arduino Uno and Arduino Mega. This header file requires Wire.h file before including “gyro_Accel.h” file. Moreover, before calling of the built-in functions, I2C bus must be initialized by giving this command Wire.begin();.
## Global variables
This header file will pass through these as global variables
1. int accel_x_OC				Contains the x-axis accelerometer measurement offset 
2. int accel_y_OC				Contains the y-axis accelerometer measurement offset
3. int accel_z_OC				Contains the z-axis accelerometer measurement offset
4. int gyro_x_OC				Contains the x-axis gyroscope measurement offset
5. int gyro_y_OC				Contains the y-axis gyroscope measurement offset
6. int gyro_z_OC				Contains the z-axis gyroscope measurement offset
7. float temp_scalled			Contains the absolute temperature in Celsius 
8. float accel_x_scalled			x-axis accelerometer measurement minus offset 
9. float accel_y_scalled			y-axis accelerometer measurement minus offset
10. float accel_z_scalled			z-axis accelerometer measurement minus offset
11. float gyro_x_scalled			x-axis gyroscope measurement minus offset
12. float gyro_y_scalled			y-axis gyroscope measurement minus offset
13. float gyro_z_scalled			z-axis gyroscope measurement minus offset
Functions
---------
### MPU6050_ReadData()
This function will read the only the useful data, which in this case is the accelerometer, gyroscope and temperature. After reading these variables (temp_scalled, accel_x_scalled, accel_y_scalled, accel_z_scalled, gyro_x_scalled, gyro_y_scalled and gyro_z_scalled) are updated. 

MPU6050_ResetWake()	
This function will reset the chip to its default values. It is recommended to perform a reset before setting the chip for any purpose.  

MPU6050_SetDLPF(int BW)	
This function will configure the built-in low pass filter. The int BW should contain values (0-6). The bandwidth of the filter will change according to the table given below.
- int BW		DLPF Bandwidth
- 0 or Any		Inf
- 1	        	184
- 2	        	94
- 3	        	44
- 4	        	21
- 5	        	10
- 6	       		5

If int BW is not with in (0-6), the LPF is disabled which is same as setting the Bandwidth to infinity 
MPU6050_SetGains(int gyro,int accel)	Use this function to set the maximum scale of the measurements. 

- int gyro	Max scale [degree/s]		int accel	Max scale [m/s2]
- 0	                  250		        0	          2g
- 1	                  500	          	1	          4g
- 2                   1000		        2	          8g
- 3	                  2000	        	3	          16g 
- any	              Raw value	    	any       	Raw value

The MPU6050_ReadData() 
function will use these scaling factors to calculate the output results. If values other than (0-3) are used the MPU6050_ReadData() will give raw sensor values including offset compensation factor. To get original sensor raw values set the offset variables (accel_x_OC, accel_y_OC, accel_z_OC, gyro_x_OC, gyro_y_OC and gyro_z_OC) to zero.

MPU6050_OffsetCal()	
This function will calculate the offset in both gyroscope and accelerometer. The calculated offsets are stored in accel_x_OC, accel_y_OC, accel_z_OC, gyro_x_OC, gyro_y_OC and gyro_z_OC. It is required to place the x and y axes of the MPU6050 chip horizontal and z axis perpendicular to the ground while performing this calibration. Moving the hardware during the calibration process will reduce the accuracy of the calculated offsets. The z axis is calibrated to 9.81 m/s2 (1g) and this is hardcoded in the code. So, it is a good idea to change the scaling to 4g and bandwidth to inf before calibrating the offset.

Read More on this link:
http://hobbylogs.me.pn/?p=47
