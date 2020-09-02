#pragma once
#include "SBase.h"
#include "CTransform.h"
#include "CSpeed.h"

class SMovement : public SBase
{
private:
	vector<vector<CTransform*>> transforms;
	vector<vector<CSpeed*>> speeds;
	bool AcceptsComponent(IComponent*) override;
	bool DiscriminateComponent(int entityIndex, IComponent*) override;
	bool AbandonComponent(int entityIndex, IComponent*) override;
	void AbandonAllComponents(int entityIndex) override;
public:
	~SMovement() override;
	void ProgressComponents(float elapsedTime) override;
	string GetPurpose() override;
};
