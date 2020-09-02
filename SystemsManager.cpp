#include "SystemsManager.h"

SystemsManager::SystemsManager() {}

SystemsManager::~SystemsManager()
{
	cout << "SystemsManager destructor" << endl;
}

void SystemsManager::AddSystem(ISystem* system)
{
	if(system)
	{
		systems.push_back(system);
	}
}

void SystemsManager::RegisterComponent(int entityId, IComponent* component)
{
	for(unsigned i=0; i<systems.size(); i++)
	{
		systems[i]->RegisterComponent(entityId, component);
	}
}

void SystemsManager::ProgressComponents(float elapsedTime)
{
	for(unsigned i=0; i<systems.size(); i++)
	{
		systems[i]->ProgressComponents(elapsedTime);
	}
}

void SystemsManager::UnregisterComponent(int entityId, IComponent* component)
{
	for(unsigned i=0; i<systems.size(); i++)
	{
		systems[i]->UnregisterComponent(entityId, component);
	}
}

void SystemsManager::UnregisterEntity(int entityId)
{
	for(unsigned i=0; i<systems.size(); i++)
	{
		systems[i]->UnregisterEntity(entityId);
	}
}
