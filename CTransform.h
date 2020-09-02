#pragma once
#include "IComponent.h"
#include <iostream>

using namespace std;

class CTransform : public IComponent
{
private:
	float x;
	float y;
public:
	CTransform();
	CTransform(float, float);
	~CTransform() override;

	float GetPosX();
	float GetPosY();
	void SetPosX(float);
	void SetPosY(float);
	void AddOffsetX(float);
	void AddOffsetY(float);

	void Update(float elapsedTime) override;
	void Print() override;

	static const float MAX_POS_COORDINATE;
};
