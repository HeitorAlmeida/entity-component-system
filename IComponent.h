#pragma once

class IComponent
{
public:
	virtual ~IComponent() {}
	virtual void Update(float elapsedTime) = 0;
	virtual void Print() = 0;
};
