#include "Object.h"
#include "RandomIdentifier.h"


namespace XPlatform
{
	Object::Object()
	{
		m_ObjectID = RandomIdentifier::GetSharedInstance()->CreateRandomNumber();
		OnCreate();
	}

	Object::Object(uint64_t objectID)
	{
		m_ObjectID = objectID;
	}

	Object::~Object()
	{
		OnDestroy();
		RandomIdentifier::GetSharedInstance()->DestroyRandomNumber(m_ObjectID);
	}

	void Object::OnCreate()
	{
	}

	void Object::OnDestroy()
	{
	}

	uint64_t Object::GetObjectID()
	{
		return m_ObjectID;
	}
}
