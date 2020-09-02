#include "SUpdate.h"

SUpdate::~SUpdate() { cout << "SUpdate destructor" << endl; }

bool SUpdate::AcceptsComponent(IComponent* component)
{
	return (component != NULL);
}

bool SUpdate::DiscriminateComponent(int entityIndex, IComponent* component)
{
	if(component)
	{
		if(entityIndex < 0)
		{
			updaters.push_back(vector<IComponent*>(1, component));
		}
		else
		{
			if((unsigned)entityIndex >= updaters.size())
			{
				return false;
			}
			vector<IComponent*>& vector = updaters[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == component)
				{
					return false;
				}
			}
			vector.push_back(component);
		}
		return true;
	}
	return false;
}

bool SUpdate::AbandonComponent(int entityIndex, IComponent* component)
{
	if(component)
	{
		if((entityIndex > -1) && ((unsigned)entityIndex < updaters.size()))
		{
			vector<IComponent*>& vector = updaters[entityIndex];
			for(unsigned i=0; i<vector.size(); i++)
			{
				if(vector[i] == component)
				{
					vector.erase(vector.begin()+i);
					return true;
				}
			}
		}
	}
	return false;
}

void SUpdate::AbandonAllComponents(int entityIndex)
{
	if(entityIndex > -1)
	{
		if((unsigned)entityIndex < updaters.size())
		{
			updaters.erase(updaters.begin()+entityIndex);
		}
	}
}

void SUpdate::ProgressComponents(float elapsedTime)
{
	for(unsigned i=0; i<updaters.size(); i++)
	{
		vector<IComponent*>& entityUpdaters = updaters[i];
		for(unsigned j=0; j<entityUpdaters.size(); j++)
		{
			entityUpdaters[j]->Update(elapsedTime);
		}
	}
}

string SUpdate::GetPurpose()
{
	return "custom function execution";
}
