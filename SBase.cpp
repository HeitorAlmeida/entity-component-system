#include "SBase.h"

SBase::~SBase() { cout << "SBase destructor" << endl; }

int SBase::GetEntityIndex(int entityId)
{
	for(unsigned i=0; i<entityIds.size(); i++)
	{
		if(entityIds[i] == entityId)
		{
			return i;
		}
	}
	return -1;
}

void SBase::RegisterComponent(int entityId, IComponent* component)
{
	if(AcceptsComponent(component))
	{
		int entityIndex = GetEntityIndex(entityId);
		string systemPurpose = GetPurpose();
		if(entityIndex == -1)
		{
			if(DiscriminateComponent(-1, component))
			{
				entityIds.push_back(entityId);
				totalEntityComponents.push_back(1);
				cout << "Component registered by system of " << systemPurpose << "." << endl;
			}
			else
			{
				cout << "Component rejected by system of " << systemPurpose << "." << endl;
			}
		}
		else
		{
			if(DiscriminateComponent(entityIndex, component))
			{
				totalEntityComponents[entityIndex]++;
				cout << "Component registered by system of " << systemPurpose << "." << endl;
			}
			else
			{
				cout << "Component rejected by system of " << systemPurpose << "." << endl;
			}
		}
	}
}

void SBase::UnregisterComponent(int entityId, IComponent* component)
{
	if(AcceptsComponent(component))
	{
		int entityIndex = GetEntityIndex(entityId);
		if(entityIndex > -1)
		{
			string systemPurpose = GetPurpose();
			if(AbandonComponent(entityIndex, component))
			{
				totalEntityComponents[entityIndex]--;
				cout << "Component unregistered from system of " << systemPurpose << "." << endl;
				if(totalEntityComponents[entityIndex] == 0)
				{
					UnregisterEntity(entityId);
				}
			}
			else
			{
				cout << "Trying to unregister a component not registered in system of " << systemPurpose << "." << endl;
			}
		}
	}
}

void SBase::UnregisterEntity(int entityId)
{
	int entityIndex = GetEntityIndex(entityId);
	if(entityIndex > -1)
	{
		entityIds.erase(entityIds.begin()+entityIndex);
		AbandonAllComponents(entityIndex);
	}
}
