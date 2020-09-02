#pragma once
#include "IComponent.h"
#include "ISystem.h"
#include <vector>

class SystemsManager
{
private:
	vector<ISystem*> systems;
	SystemsManager();
public:
	~SystemsManager();
	static SystemsManager& GetInstance()
	{
		static SystemsManager instance;
		return instance;
	}
	void AddSystem(ISystem*);
	void RegisterComponent(int entityId, IComponent*);
	void ProgressComponents(float elapsedTime);
	void UnregisterComponent(int entityId, IComponent*);
	void UnregisterEntity(int entityId);
	SystemsManager(const SystemsManager& otherManager) = delete;
	SystemsManager& operator=(const SystemsManager& otherManager) = delete;
};
