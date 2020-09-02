#include "SMovement.h"

SMovement::~SMovement() { cout << "SMovement destructor" << endl; }

bool SMovement::AcceptsComponent(IComponent* component)
{
	if(component)
	{
		if(dynamic_cast<CTransform*>(component))
		{
			return true;
		}
		if(dynamic_cast<CSpeed*>(component))
		{
			return true;
		}
	}
	return false;
}

bool SMovement::DiscriminateComponent(int entityIndex, IComponent* component)
{
	CTransform* transform = dynamic_cast<CTransform*>(component);
	if(transform)
	{
		if(entityIndex < 0)
		{
			transforms.push_back(vector<CTransform*>(1, transform));
			speeds.push_back(vector<CSpeed*>());
		}
		else
		{
			if((unsigned)entityIndex >= transforms.size())
			{
				return false;
			}
			vector<CTransform*>& vector = transforms[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == transform)
				{
					return false;
				}
			}
			vector.push_back(transform);
		}
		return true;
	}
	CSpeed* speed = dynamic_cast<CSpeed*>(component);
	if(speed)
	{
		if(entityIndex < 0)
		{
			transforms.push_back(vector<CTransform*>());
			speeds.push_back(vector<CSpeed*>(1, speed));
		}
		else
		{
			if((unsigned)entityIndex >= speeds.size())
			{
				return false;
			}
			vector<CSpeed*>& vector = speeds[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == speed)
				{
					return false;
				}
			}
			vector.push_back(speed);
		}
		return true;
	}
	return false;
}

bool SMovement::AbandonComponent(int entityIndex, IComponent* component)
{
	CTransform* transform = dynamic_cast<CTransform*>(component);
	if(transform)
	{
		if((entityIndex > -1) && ((unsigned)entityIndex < transforms.size()))
		{
			vector<CTransform*>& vector = transforms[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == transform)
				{
					vector.erase(vector.begin()+i);
					return true;
				}
			}
		}
	}
	CSpeed* speed = dynamic_cast<CSpeed*>(component);
	if(speed)
	{
		if((entityIndex > -1) && ((unsigned)entityIndex < speeds.size()))
		{
			vector<CSpeed*>& vector = speeds[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == speed)
				{
					vector.erase(vector.begin()+i);
					return true;
				}
			}
		}
	}
	return false;
}

void SMovement::AbandonAllComponents(int entityIndex)
{
	if(entityIndex > -1)
	{
		if((unsigned)entityIndex < transforms.size())
		{
			transforms.erase(transforms.begin()+entityIndex);
		}
		if((unsigned)entityIndex < speeds.size())
		{
			speeds.erase(speeds.begin()+entityIndex);
		}
	}
}

void SMovement::ProgressComponents(float elapsedTime)
{
	CTransform* transform = NULL;
	CSpeed* speed = NULL;
	float offsetX = 0;
	float offsetY = 0;
	for(unsigned i=0; i<speeds.size(); i++)
	{
		vector<CSpeed*>& entitySpeeds = speeds[i];
		for(unsigned j=0; j<entitySpeeds.size(); j++)
		{
			speed = entitySpeeds[j];
			offsetX = speed->GetSpeedX() * elapsedTime;
			offsetY = speed->GetSpeedY() * elapsedTime;
			vector<CTransform*>& entityTransforms = transforms[i];
			for(unsigned k=0; k<entityTransforms.size(); k++)
			{
				transform = entityTransforms[k];
				transform->AddOffsetX(offsetX);
				transform->AddOffsetY(offsetY);
			}
		}
	}
}

string SMovement::GetPurpose()
{
	return "movement execution";
}
