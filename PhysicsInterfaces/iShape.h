#pragma once
#include "eShapeType.h"
//#include <glm\game_math.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp> // <- This includes vec3 and mat4

namespace nPhysics
{
	class iShape
	{
	public:
		virtual ~iShape() {}
		
		eShapeType GetShapeType() { return mShapeType; }

		virtual bool GetBoxHalfExtends( glm::vec3& halfExtendOut ) { return false; }
		virtual bool GetCapsuleHeight( float& heightOut ) { return false; }
		virtual bool GetCapsuleRadius( float& radiusOut ) { return false; }
		virtual bool GetSphereRadius(float& radiusOut) { return false; }
		virtual bool GetPlaneNormal(glm::vec3& normalOut) { return false; }
		virtual bool GetPlaneConst(float& planeConstOut) { return false; }

	protected:
		iShape(eShapeType shapeType)
			: mShapeType(shapeType)
		{

		}
		iShape() {}
		iShape(const iShape& other) {}
		iShape& operator=(const iShape& other) { return *this; }
	private:
		eShapeType mShapeType;
	};
}