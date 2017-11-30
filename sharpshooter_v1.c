#pragma config(Sensor, in1,    angler,         sensorPotentiometer)
#pragma config(Sensor, in2,    rangeSelector,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  fire,           sensorDigitalIn)
#pragma config(Sensor, dgtl2,  shortDis,       sensorDigitalIn)
#pragma config(Sensor, dgtl3,  longDis,        sensorDigitalIn)
#pragma config(Sensor, dgtl4,  center,         sensorDigitalIn)
#pragma config(Motor,  port1,           flywheel0,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           flywheel1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           flywheel2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           flywheel3,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//Needs to save coefficient history
float a = 1;
float b = 2;
float c = 3;
float INITIALPOT = 0;
float DEGPERTICK = 265/4095;
int NOMINALPOWER = 127;
float distance = 10;
int shotsTaken = 0;
int rampTime = 3000;
float learningRate = .5;

float getAngle()
{
	(SensorValue[angler] - INITIALPOT) * DEGPERTICK;
}

void toAngle(float angle)
{
		int currentAngle = getAngle();

}
void setMotors(int power)
{
	motor[flywheel0] = power;
	motor[flywheel1] = power;
	motor[flywheel2] = power;
	motor[flywheel3] = power;
}

void rampMotors(int power)
{
	dPower = power - motor[flywheel0];
	clearTimer(T1);
	time1[T1];
	int lastTime = 0;
	while(time1[T1] < rampTime)
	{
		powerRate = dpower/rampTime;
		setMotors(motor[flywheel0] + (time1[T1] - lastTime) * powerRate);
		lastTime = time1[T1];
	}
}

float calcAngle(float dist)
{
	return a * dist * dist + b * dist + c;
}

void updateCoef(int error)
{
	a = a + a * learningRate * error;
	b = b + b * learningRate * error;
	c = c + c * learningRate * error;
}

task main()
{
	while (true)
	{
		setMotors(NOMINALPOWER);
		if(SensorValue[shortDis]==1)
		{
			updateCoef(1);
			toAngle(calcAngle(distance));
			shotsTaken++;
		}
		if(SensorValue[longDis]==1)
		{
			updateCoef(-1);
			toAngle(calcAngle(distance));
			shotsTaken++;
		}
		if(SensorValue[center]==1)
		{
			updateCoef(0);
			toAngle(calcAngle(distance));
			shotsTaken++;
		}

	}

}
