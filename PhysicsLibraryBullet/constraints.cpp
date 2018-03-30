#include "constraints.h"

namespace nPhysics
{
	cBallAndSocketConstraint::cBallAndSocketConstraint( cBulletRigidBody* rb, const btVector3& pivot )
		: iConstraint( CONSTRAINT_TYPE_BALL_AND_SOCKET )
	{
		mConstraint = new btPoint2PointConstraint( *rb->GetBulletBody(), pivot );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cBallAndSocketConstraint::cBallAndSocketConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB )
		: iConstraint( CONSTRAINT_TYPE_BALL_AND_SOCKET )
	{
		mConstraint = new btPoint2PointConstraint( *rbA->GetBulletBody(), *rbB->GetBulletBody(), pivotInA, pivotInB );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cBallAndSocketConstraint::~cBallAndSocketConstraint()
	{
		if( mConstraint )
		{
			delete mConstraint;
			mConstraint = 0;
		}
	}

	iRigidBody* cBallAndSocketConstraint::GetRigidBodyA()
	{
		if( !mConstraint ) return 0;
																				// Not sure about this method
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* cBallAndSocketConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		// Not sure about this method
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );

	}

	cHingeConstraint::cHingeConstraint( cBulletRigidBody* rb, const btVector3& pivot, const btVector3& axis )
		: iConstraint( CONSTRAINT_TYPE_HINGE )
	{
		mConstraint = new btHingeConstraint( *rb->GetBulletBody(), pivot, axis );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cHingeConstraint::cHingeConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB, const btVector3& axisInA, const btVector3& axisInB )
		: iConstraint( CONSTRAINT_TYPE_HINGE )
	{
		mConstraint = new btHingeConstraint( *rbA->GetBulletBody(), *rbB->GetBulletBody(), pivotInA, pivotInB, axisInA, axisInB );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cHingeConstraint::~cHingeConstraint()
	{
		if( mConstraint )
		{
			delete mConstraint;
			mConstraint = 0;
		}
	}

	iRigidBody* cHingeConstraint::GetRigidBodyA()
	{
		if( !mConstraint ) return 0;
		// Not sure about this method
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* cHingeConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		// Not sure about this method
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );

	}



}