#include "CSpeed.h"

CSpeed::CSpeed()
{
	speedX = 0;
	speedY = 0;
}

CSpeed::CSpeed(float speedComponentX, float speedComponentY)
{
	speedX = speedComponentX;
	speedY = speedComponentY;
}

CSpeed::~CSpeed() {}

float CSpeed::GetSpeedX()
{
	return speedX;
}

float CSpeed::GetSpeedY()
{
	return speedY;
}

void CSpeed::SetSpeedX(float newSpeedX)
{
	speedX = newSpeedX;
}

void CSpeed::SetSpeedY(float newSpeedY)
{
	speedY = newSpeedY;
}

void CSpeed::Update(float elapsedTime) {}

void CSpeed::Print()
{
	cout << "CSpeed(" << speedX << ", " << speedY << ")";
}
