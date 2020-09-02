#pragma once
#include "IComponent.h"
#include <vector>
#include <iostream>
#include "SystemsManager.h"

using namespace std;

class Entity
{
private:
	int id;
	vector<IComponent*> components;
	SystemsManager* ptrSystemsManager;
public:
	Entity(int);
	~Entity();
	int GetId();
	void AddComponent(IComponent*);
	void RemoveComponent(IComponent*);
	void Print();
};
