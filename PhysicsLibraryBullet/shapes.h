#pragma once
//#include <glm\game_math.h>
//#include <Physics\Interfaces\iShape.h>

#include <vector>
#include <iShape.h>

namespace nPhysics
{
	class cBoxShape : public iShape
	{
	public:
		cBoxShape( glm::vec3 halfExtends );

		virtual ~cBoxShape();

		virtual bool GetBoxHalfExtends( glm::vec3& halfExtendOut );

	private:
		cBoxShape();
		cBoxShape( const cBoxShape& other );
		cBoxShape& operator=( const cBoxShape& other );

		glm::vec3 mHalfExtends;
	};

	class cCapsuleShape : public iShape
	{
	public:
		cCapsuleShape( float radius, float height );

		virtual ~cCapsuleShape();

		virtual bool GetCapsuleHeight( float& heightOut );
		virtual bool GetCapsuleRadius( float& radiusOut );

	private:
		cCapsuleShape();
		cCapsuleShape( const cCapsuleShape& other );
		cCapsuleShape& operator=( const cCapsuleShape& other );

		float mRadius;
		float mHeight;
	};

	class cSphereShape : public iShape
	{
	public:
		cSphereShape(float radius);

		virtual ~cSphereShape();

		virtual bool GetSphereRadius(float& radiusOut);

	private:
		cSphereShape();
		cSphereShape(const cSphereShape& other);
		cSphereShape& operator=(const cSphereShape& other);

		float mRadius;
	};

	class cPlaneShape : public iShape
	{
	public:
		cPlaneShape(const glm::vec3& normal, float planeConst);
		
		virtual ~cPlaneShape();

		virtual bool GetPlaneNormal(glm::vec3& normalOut);
		virtual bool GetPlaneConst(float& planeConstOut);

	private:
		cPlaneShape();
		cPlaneShape(const cPlaneShape& other);
		cPlaneShape& operator=(const cPlaneShape& other);

		glm::vec3 mNormal;
		float mPlaneConst;
	};
}