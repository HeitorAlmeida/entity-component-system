# entity-component-system
A bare-bones entity component system game engine.

Entity Component System

	Author: Heitor Almeida
	May 25th 2020


	Overview

	There are many approaches to creating Entity Component Systems, and in this work I've implemented an architecture in which the components are mainly data holders and do not directly speak to each other, which means that one component added to a certain entity does not directly change the state of other components added to this or any other entity. The state of any component is only changed by the systems responsible for dealing with that component.

	I chose this approach because, as a long time Unity developer, I've witnessed several instances in which the interference with one component's data, directly from another, causes hard to track bugs due to the fact that the system responsible for the management of the component that was targeted may rely on a continuous behavior of the component's data. The responsible system ends up being surprised by the interference and, by trying to handle it, creates erratic behavior observed and unexpected by the user of the ECS. Considering this possibly problematic scenario, I thought it could be interesting to try a more safe approach as I developed my own ECS.


	In Depth

	The Entity class holds no data, aside from a single ID used by the many systems to group components and their respective entity owners together. This class is concrete and not meant to be extended, though extending it is possible and not harmful to the environment.

	The components share a common interface, IComponent. It's an abstract class, meant to be extended, and establishes that components should hold the ID of their Entity owner, that they should have an Update and a Print method. The Update method is like Unity's Monobehaviours' Update: the main feature of the ECS, given that the existence of this function allows the user of the ECS to create components with custom functionality. There is a system responsible for running the Update method of every component attached to every entity at a given time. By overriding the Update method in his own IComponent subclasses, the user can create custom functionality that is performed with maximum frequency.

	The systems share a common interface, ISystem. It's an abstract class, meant to be extended. Systems register components and group them under their respective entity IDs. When a component is attached to an Entity, the Entity tries to register the new component on every system in the environment. This is done through a singleton SystemsManager class that is supposed to be fed with an instance of every system supported by the engine, beforehand. The systems that deal with a particular component type accept its registration, while the others reject it.

	As a simple example, I've implemented the component classes CTrasnform and CSpeed, along with the system class SMovement. An Entity that has, attached to it, a transform component and an speed component, can have the position described by its transform altered by the movement system with basis on its other speed component. The movement system, when called to process the components that it is responsible for, will take a time interval and calculate the offset that the speed should produce, adding this offset to the position described by the transform. This is how a system processes the information contained in components and updates them.


	Contact

	For feedback or questions related to this work, reach me at:
	
	heitorcorr@gmail.com
