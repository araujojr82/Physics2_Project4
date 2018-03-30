#pragma once

#include "eObjectType.h"

namespace nPhysics
{
	class iCollisionBody
	{
	public:
		//enum eObjectTypes
		//{
		//	RIGID_BODY = 0,
		//	SOFT_BODY = 1
		//};

		virtual ~iCollisionBody() {}

		virtual eObjectType getType() = 0;
	};
}