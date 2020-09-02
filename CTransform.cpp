#include "CTransform.h"

const float CTransform::MAX_POS_COORDINATE = 100000;

CTransform::CTransform()
{
		x = 0;
		y = 0;
}

CTransform::CTransform(float posX, float posY)
{
	SetPosX(posX);
	SetPosY(posY);
}

CTransform::~CTransform() {}

float CTransform::GetPosX()
{
	return x;
}

float CTransform::GetPosY()
{
	return y;
}

void CTransform::SetPosX(float newPosX)
{
		x = (newPosX > MAX_POS_COORDINATE) ? MAX_POS_COORDINATE : newPosX;
		x = (x < -MAX_POS_COORDINATE) ? -MAX_POS_COORDINATE : x;
}

void CTransform::SetPosY(float newPosY)
{
		y = (newPosY > MAX_POS_COORDINATE) ? MAX_POS_COORDINATE : newPosY;
		y = (y < -MAX_POS_COORDINATE) ? -MAX_POS_COORDINATE : y;
}

void CTransform::AddOffsetX(float offsetX)
{
	SetPosX(x + offsetX);
}

void CTransform::AddOffsetY(float offsetY)
{
	SetPosY(y + offsetY);
}

void CTransform::Update(float elapsedTime) {}

void CTransform::Print()
{
	cout << "CTransform(" << x << ", " << y << ")";
}
