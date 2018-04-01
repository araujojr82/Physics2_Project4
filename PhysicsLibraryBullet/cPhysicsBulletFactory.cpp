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

	iConstraint* cPhysicsBulletFactory::Create6DOFConstraint( iRigidBody* rb, const glm::quat& rotation, const glm::vec3 translation, bool useLinearReferenceFrame )
	{
		btQuaternion btRotation = btQuaternion( ( btScalar )rotation.x, ( btScalar )rotation.y, ( btScalar )rotation.z, ( btScalar )rotation.w );
		btVector3 btTranslation = btVector3( ( btScalar )translation.x, ( btScalar )translation.y, ( btScalar )translation.z );
		btTransform frame = btTransform( btRotation, btTranslation );

		return new c6DOFConstraint( ( cBulletRigidBody* )rb, frame, useLinearReferenceFrame );
	}

	iConstraint* cPhysicsBulletFactory::Create6DOFConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::quat& rotationA, const glm::vec3 translationA, 
															  const glm::quat& rotationB, const glm::vec3 translationB, const bool useLinearReferenceFrameA )
	{
		btQuaternion btRotationA = btQuaternion( ( btScalar )rotationA.x, ( btScalar )rotationA.y, ( btScalar )rotationA.z, ( btScalar )rotationA.w );
		btVector3 btTranslationA = btVector3( ( btScalar )translationA.x, ( btScalar )translationA.y, ( btScalar )translationA.z );
		btTransform frameA = btTransform( btRotationA, btTranslationA );
		
		btQuaternion btRotationB = btQuaternion( ( btScalar )rotationB.x, ( btScalar )rotationB.y, ( btScalar )rotationB.z, ( btScalar )rotationB.w );
		btVector3 btTranslationB = btVector3( ( btScalar )translationB.x, ( btScalar )translationB.y, ( btScalar )translationB.z );
		btTransform frameB = btTransform( btRotationB, btTranslationB );

		return new c6DOFConstraint( ( cBulletRigidBody* )rbA, ( cBulletRigidBody* )rbB, frameA, frameB, useLinearReferenceFrameA );
	}

	iConstraint* cPhysicsBulletFactory::CreateConeTwistConstraint( iRigidBody* rb, const glm::quat& rotation, const glm::vec3 translation )
	{
		btQuaternion btRotation = btQuaternion( ( btScalar )rotation.x, ( btScalar )rotation.y, ( btScalar )rotation.z, ( btScalar )rotation.w );
		btVector3 btTranslation = btVector3( ( btScalar )translation.x, ( btScalar )translation.y, ( btScalar )translation.z );
		btTransform frame = btTransform( btRotation, btTranslation );

		return new cConeTwistConstraint( ( cBulletRigidBody* )rb, frame );
	}

	iConstraint* cPhysicsBulletFactory::CreateConeTwistConstraint( iRigidBody* rbA, iRigidBody* rbB, const glm::quat& rotationA, const glm::vec3 translationA, 
																   const glm::quat& rotationB, const glm::vec3 translationB )
	{
		btQuaternion btRotationA = btQuaternion( ( btScalar )rotationA.x, ( btScalar )rotationA.y, ( btScalar )rotationA.z, ( btScalar )rotationA.w );
		btVector3 btTranslationA = btVector3( ( btScalar )translationA.x, ( btScalar )translationA.y, ( btScalar )translationA.z );
		btTransform frameA = btTransform( btRotationA, btTranslationA );

		btQuaternion btRotationB = btQuaternion( ( btScalar )rotationB.x, ( btScalar )rotationB.y, ( btScalar )rotationB.z, ( btScalar )rotationB.w );
		btVector3 btTranslationB = btVector3( ( btScalar )translationB.x, ( btScalar )translationB.y, ( btScalar )translationB.z );
		btTransform frameB = btTransform( btRotationB, btTranslationB );

		return new cConeTwistConstraint( ( cBulletRigidBody* )rbA, ( cBulletRigidBody* )rbB, frameA, frameB );
	}
	
}