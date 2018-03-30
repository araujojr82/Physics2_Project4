#include "shapes.h"

namespace nPhysics
{
	//Box Shape
	cBoxShape::cBoxShape( glm::vec3 halfExtends )
		: iShape( SHAPE_TYPE_BOX )
		, mHalfExtends( halfExtends )
	{

	}
	cBoxShape::cBoxShape()
		: iShape( SHAPE_TYPE_BOX )
	{

	}

	cBoxShape::cBoxShape( const cBoxShape& other )
		: iShape( SHAPE_TYPE_BOX )
	{

	}
	cBoxShape& cBoxShape::operator=( const cBoxShape& other )
	{
		return *this;
	}
	cBoxShape::~cBoxShape()
	{

	}
	bool cBoxShape::GetBoxHalfExtends( glm::vec3& halfExtendOut )
	{
		halfExtendOut = mHalfExtends;
		return true;
	}

	//Capsule Shape
	cCapsuleShape::cCapsuleShape( float radius, float height )
		: iShape( SHAPE_TYPE_CAPSULE )
		, mRadius( radius )
		, mHeight( height )
	{

	}
	cCapsuleShape::cCapsuleShape()
		: iShape( SHAPE_TYPE_CAPSULE )
	{

	}

	cCapsuleShape::cCapsuleShape( const cCapsuleShape& other )
		: iShape( SHAPE_TYPE_CAPSULE )
	{

	}
	cCapsuleShape& cCapsuleShape::operator=( const cCapsuleShape& other )
	{
		return *this;
	}
	cCapsuleShape::~cCapsuleShape()
	{

	}
	bool cCapsuleShape::GetCapsuleHeight( float& heightOut )
	{
		heightOut = mHeight;
		return true;
	}
	bool cCapsuleShape::GetCapsuleRadius( float& radiusOut )
	{
		radiusOut = mRadius;
		return true;
	}

	// Shepe Shape
	cSphereShape::cSphereShape(float radius)
		: iShape(SHAPE_TYPE_SPHERE)
		, mRadius(radius)
	{

	}
	cSphereShape::cSphereShape()
		: iShape(SHAPE_TYPE_SPHERE)
	{

	}

	cSphereShape::cSphereShape(const cSphereShape& other)
		: iShape(SHAPE_TYPE_SPHERE)
	{

	}
	cSphereShape& cSphereShape::operator=(const cSphereShape& other)
	{
		return *this;
	}
	cSphereShape::~cSphereShape()
	{

	}
	bool cSphereShape::GetSphereRadius(float& radiusOut)
	{
		radiusOut = mRadius;
		return true;
	}

	// Plane Shape
	cPlaneShape::cPlaneShape(const glm::vec3& normal, float planeConst)
		: iShape(SHAPE_TYPE_PLANE)
		, mNormal(normal)
		, mPlaneConst(planeConst)
	{

	}
	cPlaneShape::cPlaneShape()
		: iShape(SHAPE_TYPE_PLANE)
	{

	}

	cPlaneShape::cPlaneShape(const cPlaneShape& other)
		: iShape(SHAPE_TYPE_PLANE)
	{

	}
	cPlaneShape& cPlaneShape::operator=(const cPlaneShape& other)
	{
		return *this;
	}
	cPlaneShape::~cPlaneShape()
	{

	}
	bool cPlaneShape::GetPlaneNormal(glm::vec3& normalOut)
	{
		normalOut = mNormal;
		return true;
	}
	bool cPlaneShape::GetPlaneConst(float& planeConstOut)
	{
		planeConstOut = mPlaneConst;
		return true;
	}
}