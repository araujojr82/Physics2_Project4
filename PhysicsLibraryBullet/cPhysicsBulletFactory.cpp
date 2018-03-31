#include "cPhysicsBulletFactory.h"
#include "cBulletRigidBody.h"
#include "cPhysicsBulletWorld.h"
#include "shapes.h"

EXTERN_DLL_EXPORT nPhysics::iPhysicsFactory* CreateFactory()
{
	return new nPhysics::cPhysicsBulletFactory();
}

namespace nPhysics
{	
	cPhysicsBulletFactory::~cPhysicsBulletFactory() {}

	iPhysicsWorld* cPhysicsBulletFactory::CreateWorld()
	{	
		cPhysicsBulletWorld* thePhysicsWorld = new cPhysicsBulletWorld();

		thePhysicsWorld->buildBulletWorld();

		return thePhysicsWorld;
	}

	iRigidBody* cPhysicsBulletFactory::CreateRigidBody(const sRigidBodyDesc& desc, iShape* shape)
	{
		return new cBulletRigidBody(desc, shape);
	}

	iShape* cPhysicsBulletFactory::CreateBox( glm::vec3 halfExtends )
	{
		return new cBoxShape( halfExtends );
	}
	iShape* cPhysicsBulletFactory::CreateCapsule( float radius, float height )
	{
		return new cCapsuleShape( radius, height );
	}

	iShape* cPhysicsBulletFactory::CreateSphere(float radius)
	{
		return new cSphereShape(radius);
	}
	iShape* cPhysicsBulletFactory::CreatePlane(const glm::vec3& normal, float planeConst)
	{
		return new cPlaneShape(normal, planeConst);
	}

	iConstraint* cPhysicsBulletFactory::CreateBallAndSocketConstraint( iRigidBody* rb, const glm::vec3& pivot )
	{
		btVector3 btPivot = btVector3( ( btScalar )pivot.x, ( btScalar )pivot.y, ( btScalar )pivot.z );

		return new cBallAndSocketConstraint( ( cBulletRigidBody* )rb, btPivot );
	}

	iConstraint* cPhysicsBulletFactory::CreateBallAndSocketConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB )
	{
		btVector3 pivotA = btVector3( ( btScalar )pivotInA.x, ( btScalar )pivotInA.y, ( btScalar )pivotInA.z );
		btVector3 pivotB = btVector3( ( btScalar )pivotInB.x, ( btScalar )pivotInB.y, ( btScalar )pivotInB.z );

		return new cBallAndSocketConstraint( (cBulletRigidBody*) rbA, ( cBulletRigidBody* )rbB, pivotA, pivotB );
	}

	iConstraint* cPhysicsBulletFactory::CreatHingeConstraint( iRigidBody* rb, const glm::vec3& pivot, const glm::vec3& axis )
	{
		btVector3 btPivot = btVector3( ( btScalar )pivot.x, ( btScalar )pivot.y, ( btScalar )pivot.z );
		btVector3 btAxis = btVector3( ( btScalar )axis.x, ( btScalar )axis.y, ( btScalar )axis.z );

		return new cHingeConstraint( ( cBulletRigidBody* )rb, btPivot, btAxis );
	}

	iConstraint* cPhysicsBulletFactory::CreatHingeConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::vec3& pivotInA, const glm::vec3& pivotInB, const glm::vec3& axisInA, const glm::vec3& axisInB )
	{
		btVector3 pivotA = btVector3( ( btScalar )pivotInA.x, ( btScalar )pivotInA.y, ( btScalar )pivotInA.z );
		btVector3 pivotB = btVector3( ( btScalar )pivotInB.x, ( btScalar )pivotInB.y, ( btScalar )pivotInB.z );
		btVector3 axisA = btVector3( ( btScalar )axisInA.x, ( btScalar )axisInA.y, ( btScalar )axisInA.z );
		btVector3 axisB = btVector3( ( btScalar )axisInB.x, ( btScalar )axisInB.y, ( btScalar )axisInB.z );

		return new cHingeConstraint( ( cBulletRigidBody* )rbA, ( cBulletRigidBody* )rbB, pivotA, pivotB, axisA, axisB );
	}
	
}