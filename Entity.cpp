#include "Entity.h"

Entity::Entity(int identifier) : id(identifier)
{
	ptrSystemsManager = &(SystemsManager::GetInstance());
}

Entity::~Entity() {}

int Entity::GetId()
{
	return id;
}

void Entity::AddComponent(IComponent* newComponent)
{
	if(newComponent)
	{
		for(unsigned i=0; i<components.size(); i++)
		{
			if(components[i] == newComponent)
			{
				return;
			}
		}
		components.push_back(newComponent);
		if(ptrSystemsManager)
		{
			ptrSystemsManager->RegisterComponent(id, newComponent);
		}
	}
}

void Entity::RemoveComponent(IComponent* targetComponent)
{
	if(targetComponent)
	{
		for(unsigned i=0; i<components.size(); i++)
		{
			if(components[i] == targetComponent)
			{
				if(ptrSystemsManager)
				{
					ptrSystemsManager->UnregisterComponent(id, targetComponent);
				}
				components.erase(components.begin()+i);
				return;
			}
		}
	}
}

void Entity::Print()
{
	cout << "Entity ID = " << id << endl;
	cout << "Components = [ ";
	for(unsigned i=0; i<components.size(); i++)
	{
		components[i]->Print();
		if(i != (components.size()-1))
		{
			cout << ", ";
		}
	}
	cout << " ]" << endl;
}
