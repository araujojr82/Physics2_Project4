#pragma once
#include <iPhysicsFactory.h>

#define EXTERN_DLL_EXPORT extern "C" __declspec(dllexport)

EXTERN_DLL_EXPORT nPhysics::iPhysicsFactory* CreateFactory();

namespace nPhysics
{
	class cPhysicsBulletFactory : public iPhysicsFactory
	{
	public:
		virtual ~cPhysicsBulletFactory();

		virtual iPhysicsWorld* CreateWorld();

		virtual iRigidBody* CreateRigidBody(const sRigidBodyDesc& desc, iShape* shape);
		//virtual iConstraint* CreateConstraint( iConstraint* constraint );

		virtual iShape* CreateBox( glm::vec3 halfExtends );
		virtual iShape* CreateCapsule( float radius, float height );
		virtual iShape* CreateSphere(float radius);
		virtual iShape* CreatePlane(const glm::vec3& normal, float planeConst);
		
		virtual iConstraint* CreateBallAndSocketConstraint( iRigidBody* rb, const glm::vec3& pivot );
		virtual iConstraint* CreateBallAndSocketConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB );
		virtual iConstraint* CreatHingeConstraint( iRigidBody* rb, const glm::vec3& pivot, const glm::vec3& axis );
		virtual iConstraint* CreatHingeConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB, const glm::vec3& axisInA, const glm::vec3& axisInB );
	};
}