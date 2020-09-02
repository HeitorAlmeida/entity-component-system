#pragma once
#include "SBase.h"

class SUpdate : public SBase
{
private:
	vector<vector<IComponent*>> updaters;
	bool AcceptsComponent(IComponent*) override;
	bool DiscriminateComponent(int entityIndex, IComponent*) override;
	bool AbandonComponent(int entityIndex, IComponent*) override;
	void AbandonAllComponents(int entityIndex) override;
public:
	~SUpdate() override;
	void ProgressComponents(float elapsedTime) override;
	string GetPurpose() override;
};
