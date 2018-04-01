#pragma once
#include "iRigidBody.h"
#include "sRigidBodyDesc.h"
#include "iShape.h"
#include "iPhysicsWorld.h"
#include "iConstraint.h"

namespace nPhysics
{
	class iPhysicsFactory
	{
	public:
		virtual ~iPhysicsFactory() {}

		virtual iPhysicsWorld* CreateWorld() = 0;

		virtual iRigidBody* CreateRigidBody(const sRigidBodyDesc& desc, iShape* shape) = 0;
		
		virtual iShape* CreateBox( glm::vec3 halfExtends ) = 0;
		virtual iShape* CreateCapsule( float radius, float height ) = 0;
		virtual iShape* CreateSphere(float radius) = 0;
		virtual iShape* CreatePlane(const glm::vec3& normal, float planeConst) = 0;

		virtual iConstraint* CreateBallAndSocketConstraint( iRigidBody* rb, const glm::vec3& pivot ) = 0;
		virtual iConstraint* CreateBallAndSocketConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB ) = 0;
		virtual iConstraint* CreatHingeConstraint( iRigidBody* rb, const glm::vec3& pivot, const glm::vec3& axis ) = 0;
		virtual iConstraint* CreatHingeConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB, const glm::vec3& axisInA, const glm::vec3& axisInB ) = 0;

		virtual iConstraint* Create6DOFConstraint( iRigidBody* rb, const glm::quat& rotation, const glm::vec3 translation, bool useLinearReferenceFrame ) = 0;
		virtual iConstraint* Create6DOFConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::quat& rotationA, const glm::vec3 translationA, const glm::quat& rotationB, const glm::vec3 translationB, const bool useLinearReferenceFrameA ) = 0;
		virtual iConstraint* CreateConeTwistConstraint( iRigidBody* rb, const glm::quat& rotation, const glm::vec3 translation ) = 0;
		virtual iConstraint* CreateConeTwistConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::quat& rotationA, const glm::vec3 translationA, const glm::quat& rotationB, const glm::vec3 translationB ) = 0;

	};
}