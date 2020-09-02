#pragma once
#include "IComponent.h"
#include <iostream>

using namespace std;

class CSpeed : public IComponent
{
private:
	float speedX;
	float speedY;
public:
	CSpeed();
	CSpeed(float, float);
	~CSpeed() override;

	float GetSpeedX();
	float GetSpeedY();
	void SetSpeedX(float);
	void SetSpeedY(float);

	void Update(float elapsedTime) override;
	void Print() override;
};
