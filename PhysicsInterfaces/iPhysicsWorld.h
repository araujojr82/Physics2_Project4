#pragma once
#include <vector>
#include "iRigidBody.h"
#include "iConstraint.h"

namespace nPhysics
{
	class iPhysicsWorld
	{
	public:
		virtual ~iPhysicsWorld() {}

		virtual void TimeStep(float deltaTime) = 0;
		
		virtual void AddRigidBody(iRigidBody* rigidBody) = 0;
		virtual void RemoveRigidBody(iRigidBody* rigidBody) = 0;

		virtual void AddConstraint( iConstraint* constraint ) = 0;
		virtual void RemoveConstraint( iConstraint* constraint ) = 0;

	};
}