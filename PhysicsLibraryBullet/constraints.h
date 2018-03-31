#pragma once

#include <vector>
#include <iConstraint.h>
#include "cBulletRigidBody.h"

namespace nPhysics
{
	class cBallAndSocketConstraint : public iConstraint
	{
	public:
		cBallAndSocketConstraint( cBulletRigidBody* rb, const btVector3& pivot );
		cBallAndSocketConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB );
		virtual ~cBallAndSocketConstraint();

		// From iConstraint
		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

		virtual btTypedConstraint* GetTypedConstraint() { return mConstraint; }

	private:
		btPoint2PointConstraint * mConstraint;
		cBallAndSocketConstraint( const cBallAndSocketConstraint& other ) {}
		cBallAndSocketConstraint& operator=( const cBallAndSocketConstraint& other ) { return *this; }

	private:	
		eConstraintType mConstraintType;
	};

	class cHingeConstraint : public iConstraint
	{
	public:
		cHingeConstraint( cBulletRigidBody* rb, const btVector3& pivot, const btVector3& axis );
		cHingeConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB, const btVector3& axisInA, const btVector3& axisInB );
		virtual ~cHingeConstraint();

		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

		virtual btTypedConstraint* GetTypedConstraint() { return mConstraint; }

	private:
		btHingeConstraint* mConstraint;

		//cHingeConstraint( eConstraintType constraintType ) : mConstraintType( constraintType ) {}
		cHingeConstraint( const cHingeConstraint& other ) {}
		cHingeConstraint& operator=( const iConstraint& other ) { return *this; }

	private:
		eConstraintType mConstraintType;
	};
	
	//	CONSTRAINT_TYPE_6DOF,
	class c6DOFConstraint : public iConstraint
	{
	public:
		c6DOFConstraint( cBulletRigidBody* rb, const btTransform& frame, const bool useLinearReferenceFrame );
		c6DOFConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, cBulletRigidBody* rb, const btTransform& frameInA, const btTransform& frameInB, const bool useLinearReferenceFrameA );

		virtual ~c6DOFConstraint();

		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

		virtual btTypedConstraint* GetTypedConstraint() { return mConstraint; }

	private:
		btGeneric6DofConstraint* mConstraint;

		c6DOFConstraint( const c6DOFConstraint& other ) {}
		c6DOFConstraint& operator=( const iConstraint& other ) { return *this; }

	private:
		eConstraintType mConstraintType;
	};
	
	//CONSTRAINT_TYPE_CONE_TWIST
	class cConeTwistConstraint : public iConstraint
	{
	public:
		cConeTwistConstraint( cBulletRigidBody* rb, const btTransform& rbFrame );
		cConeTwistConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, cBulletRigidBody* rb, const btTransform& rbAFrame, const btTransform& rbBFrame );

		virtual ~cConeTwistConstraint();

		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

		virtual btTypedConstraint* GetTypedConstraint() { return mConstraint; }

	private:
		btConeTwistConstraint* mConstraint;

		cConeTwistConstraint( const cConeTwistConstraint& other ) {}
		cConeTwistConstraint& operator=( const iConstraint& other ) { return *this; }

	private:
		eConstraintType mConstraintType;
	};
}