#pragma config(Sensor, in7,    r_Sensor,       sensorLineFollower)
#pragma config(Sensor, in8,    l_Sensor,       sensorLineFollower)
#pragma config(Sensor, dgtl8,  bump,           sensorTouch)
#pragma config(Sensor, dgtl11, l_Sensor_LED,   sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, r_Sensor_LED,   sensorLEDtoVCC)
#pragma config(Motor,  port8,           r_Motor,       tmotorServoContinuousRotation, openLoop, driveRight)
#pragma config(Motor,  port9,           l_Motor,       tmotorServoContinuousRotation, openLoop, reversed, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int LINE_THRESHOLD = 1900; //Values above this on line followers are "on the line"
int mode = 0;
int duration = 0.1;
int nominal_speed = 50;
int F = 0;
int R = 1;
int L = -1;



task main()
{
	while (true)
	{
		if (SensorValue[l_Sensor] > LINE_THRESHOLD)
		{SensorValue[l_Sensor_LED] = 1;} else {SensorValue[l_Sensor_LED] = 0;}
		if (SensorValue[r_Sensor] > LINE_THRESHOLD)
		{SensorValue[r_Sensor_LED] = 1;} else {SensorValue[r_Sensor_LED] = 0;}
		switch (mode)
		{
			case 0:
				//----Begin Remote Control
				if (abs(vexRT[Ch2]) > 12.7) //If the axis is out of the middle deadzone
				{
					motor[r_Motor] = vexRT[Ch2]; //Set the axis value to the motor
				}
				else //If we're in the deadzone
				{
					motor[r_Motor] = 0; //Stop the robot
				}

				if ( abs(vexRT[Ch3]) > 12.7 ) //See above comments for explanation
				{
					motor[l_Motor] = vexRT[Ch3];
				}
				else
				{
					motor[l_Motor] = 0;
				}
				//----End Remote Control
			break;
			case 1:

			break;
		}

	}
}