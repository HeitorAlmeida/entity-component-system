#pragma once
#include "IComponent.h"
#include <iostream>

using namespace std;

class ISystem
{
protected:
	virtual int GetEntityIndex(int entityId) = 0;
	virtual bool AcceptsComponent(IComponent*) = 0;
	virtual bool DiscriminateComponent(int entityIndex, IComponent*) = 0;
	virtual bool AbandonComponent(int entityIndex, IComponent*) = 0;
	virtual void AbandonAllComponents(int entityIndex) = 0;
public:
	virtual ~ISystem() {}
	virtual void RegisterComponent(int entityId, IComponent*) = 0;
	virtual void ProgressComponents(float elapsedTime) = 0;
	virtual void UnregisterComponent(int entityId, IComponent*) = 0;
	virtual void UnregisterEntity(int entityId) = 0;
	virtual string GetPurpose() = 0;
};
