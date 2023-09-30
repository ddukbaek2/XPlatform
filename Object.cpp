#include "Object.h"
#include "RandomIdentifier.h"


namespace XPlatform
{
	Object::Object()
	{
		m_ObjectID = RandomIdentifier::GetSharedInstance()->CreateRandomNumber();
	}

	Object::Object(uint64_t objectID)
	{
		m_ObjectID = objectID;
	}

	Object::~Object()
	{
		RandomIdentifier::GetSharedInstance()->DestroyRandomNumber(m_ObjectID);
	}

	uint64_t Object::GetObjectID()
	{
		return m_ObjectID;
	}
}
