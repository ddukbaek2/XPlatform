#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	class Object
	{
	private:
		uint64_t m_ObjectID;

	public:
		Object();
		Object(uint64_t ObjectID);
		virtual ~Object();

		uint64_t GetObjectID();
	};
}