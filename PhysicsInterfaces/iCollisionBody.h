#pragma once

#include "eObjectType.h"

namespace nPhysics
{
	class iCollisionBody
	{
	public:

		virtual ~iCollisionBody() {}

		virtual eObjectType getType() = 0;
	};
}