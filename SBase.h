#pragma once
#include "ISystem.h"
#include <vector>
#include <string>

class SBase : public ISystem
{
protected:
	vector<int> entityIds;
	vector<int> totalEntityComponents;
	int GetEntityIndex(int entityId) override;
	bool AcceptsComponent(IComponent*) = 0;
	bool DiscriminateComponent(int entityIndex, IComponent*) = 0;
	bool AbandonComponent(int entityIndex, IComponent*) = 0;
	void AbandonAllComponents(int entityIndex) = 0;
public:
	~SBase() override;
	void RegisterComponent(int entityId, IComponent*) override;
	void ProgressComponents(float elapsedTime) = 0;
	void UnregisterComponent(int entityId, IComponent*) override;
	void UnregisterEntity(int entityId) override;
	string GetPurpose() = 0;
};
