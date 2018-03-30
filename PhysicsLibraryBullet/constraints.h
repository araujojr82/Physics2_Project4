#pragma once

#include <vector>
#include <iConstraint.h>
#include "cBulletRigidBody.h"

namespace nPhysics
{
	class cHingeConstraint : public iConstraint
	{
	public:
		cHingeConstraint( cBulletRigidBody* rb, const btVector3& pivot, const btVector3& axis );
		cHingeConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB, const btVector3& axisInA, const btVector3& axisInB );
		virtual ~cHingeConstraint();

		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

	private:
		btHingeConstraint* mConstraint;

		cHingeConstraint( eConstraintType constraintType ) : mConstraintType( constraintType ) {}
		cHingeConstraint( const iConstraint& other ) {}
		cHingeConstraint& operator=( const iConstraint& other ) { return *this; }

		eConstraintType mConstraintType;
	};
	
	class iBulletConstraint : iConstraint
	{
	public:
		virtual ~iBulletConstraint() {}

	protected:
		// The constructor is protector, only accessible by the subclasses
		//iBulletConstraint( eConstraintType constraintType ) : mConstraintType( constraintType ) {}
		iBulletConstraint( const iBulletConstraint& other ) :iConstraint( other ) {};
		iBulletConstraint& operator=( const iBulletConstraint& other ) { return *this; }
	};

	class cBallAndSocketConstraint : /*public iBallAndSocketConstraint,*/ public iConstraint
	{
	public:
		cBallAndSocketConstraint( cBulletRigidBody* rb, const btVector3& pivot );
		cBallAndSocketConstraint( cBulletRigidBody* rbA, cBulletRigidBody* rbB, const btVector3& pivotInA, const btVector3& pivotInB );
		virtual ~cBallAndSocketConstraint();

		// From iConstraint
		virtual iRigidBody* GetRigidBodyA();
		virtual iRigidBody* GetRigidBodyB();

		//inline eConstraintType GetConstraintType() const { return mConstraintType; }
		// From iBulletConstraint
		virtual btTypedConstraint* GetTypedConstraint() { return mConstraint; }

	protected:
		btPoint2PointConstraint * mConstraint;
		cBallAndSocketConstraint( const cBallAndSocketConstraint& other ) : iConstraint;
		cBallAndSocketConstraint& operator=( const cBallAndSocketConstraint& other ) { return *this; }

	private:
		eConstraintType mConstraintType;
	};

}