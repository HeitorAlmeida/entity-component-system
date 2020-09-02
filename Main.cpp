
#include <iostream>
#include "Entity.h"
#include "SystemsManager.h"
#include "SMovement.h"
#include "SUpdate.h"
#include <sstream>

void PrintPresentationTitle(string title)
{
	cout << endl;
	cout << "**************************************************************************" << endl;
	cout << "********* " << title << " *********" << endl;
	cout << "**************************************************************************" << endl;
}

void PrintOperation(string operation)
{
	cout << endl;
	cout << "******" << operation << "******" << endl;
	cout << endl;
}

int main()
{
	SystemsManager& systemsManager = SystemsManager::GetInstance();
	SMovement systemMovement;
	SUpdate systemUpdate;
	systemsManager.AddSystem(&systemMovement);
	systemsManager.AddSystem(&systemUpdate);

	float timeStep = 5.0;
	ostringstream ss;
	ss << timeStep;
	string stepDuration(ss.str());

	PrintPresentationTitle("ECS Simple Usage");

	PrintOperation("Creating first entity.");
	Entity entity1(25);
	entity1.Print();

	PrintOperation("Adding transform and speed components to first entity.");
	CTransform transform1;
	CSpeed speed1(1, 1);
	entity1.AddComponent(&transform1);
	entity1.AddComponent(&speed1);
	entity1.Print();

	PrintOperation("Advancing "+stepDuration+" seconds.");
	systemsManager.ProgressComponents(timeStep);
	entity1.Print();

	PrintOperation("Removing transform component from first entity.");
	entity1.RemoveComponent(&transform1);
	entity1.Print();

	PrintOperation("Adding one more speed component to first entity.");
	CSpeed speed2(0.5, 2);
	entity1.AddComponent(&speed2);
	entity1.Print();

	PrintOperation("Advancing "+stepDuration+" seconds.");
	systemsManager.ProgressComponents(timeStep);
	entity1.Print();

	PrintOperation("Adding once again transform component to first entity.");
	entity1.AddComponent(&transform1);
	entity1.Print();

	PrintOperation("Advancing "+stepDuration+" seconds.");
	systemsManager.ProgressComponents(timeStep);
	entity1.Print();

	PrintOperation("Creating second entity and adding components to it.");
	Entity entity2(19);
	CTransform transform2;
	CSpeed speed3(-1, -3);
	entity2.AddComponent(&transform2);
	entity2.AddComponent(&speed3);
	entity2.Print();

	PrintOperation("Advancing "+stepDuration+" seconds.");
	systemsManager.ProgressComponents(timeStep);
	entity1.Print();
	entity2.Print();

	return 0;
}
