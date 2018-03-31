#include "constraints.h"

namespace nPhysics
{
	// Ball and Socket Constraint =============================================================================================================
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
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* cBallAndSocketConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );

	}

	// Hinge Constraint =============================================================================================================
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
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* cHingeConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );
	}

	// 6 Degrees of Freedom Constraint =============================================================================================================
	c6DOFConstraint::c6DOFConstraint( cBulletRigidBody* rb, const btTransform& frame, const bool useLinearReferenceFrame )
		: iConstraint( CONSTRAINT_TYPE_6DOF )
	{
		mConstraint = new btGeneric6DofConstraint( *rb->GetBulletBody(), frame, useLinearReferenceFrame );
		mConstraint->setUserConstraintPtr( 0 );
	}	

	c6DOFConstraint::c6DOFConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, cBulletRigidBody* rb, const btTransform& frameInA, const btTransform& frameInB, const bool useLinearReferenceFrameA )
		: iConstraint( CONSTRAINT_TYPE_6DOF )
	{
		mConstraint = new btGeneric6DofConstraint( *rbA->GetBulletBody(), *rbB->GetBulletBody(), frameInA, frameInB, useLinearReferenceFrameA );
		mConstraint->setUserConstraintPtr( 0 );
	}

	c6DOFConstraint::~c6DOFConstraint()
	{
		if( mConstraint )
		{
			delete mConstraint;
			mConstraint = 0;
		}
	}

	iRigidBody* c6DOFConstraint::GetRigidBodyA()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* c6DOFConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );
	}

	// Cone Twist Constraint =============================================================================================================
	cConeTwistConstraint::cConeTwistConstraint( cBulletRigidBody* rb, const btTransform& rbFrame )
		: iConstraint( CONSTRAINT_TYPE_CONE_TWIST )
	{
		mConstraint = new btConeTwistConstraint( *rb->GetBulletBody(), rbFrame );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cConeTwistConstraint::cConeTwistConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, cBulletRigidBody* rb, const btTransform& rbAFrame, const btTransform& rbBFrame )
		: iConstraint( CONSTRAINT_TYPE_CONE_TWIST )
	{
		mConstraint = new btConeTwistConstraint( *rbA->GetBulletBody(), *rbB->GetBulletBody(), rbAFrame, rbBFrame );
		mConstraint->setUserConstraintPtr( 0 );
	}

	cConeTwistConstraint::~cConeTwistConstraint()
	{
		if( mConstraint )
		{
			delete mConstraint;
			mConstraint = 0;
		}
	}

	iRigidBody* cConeTwistConstraint::GetRigidBodyA()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyA().getUserPointer() );
	}

	iRigidBody* cConeTwistConstraint::GetRigidBodyB()
	{
		if( !mConstraint ) return 0;
		return reinterpret_cast< cBulletRigidBody* >( mConstraint->getRigidBodyB().getUserPointer() );
	}

}