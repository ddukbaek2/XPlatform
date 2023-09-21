#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	Object::Object()
	{
		m_ReferenceCount = 1;
	}

	Object::~Object()
	{
		OnDestroy();
	}

	void Object::OnCreate()
	{
	}

	void Object::OnDestroy()
	{
	}

	void Object::Destroy(Object* object)
	{
		if (object == nullptr)
			return;

		SAFE_DELETE(object);
	}

	void Object::DestroyImmediate(Object* object)
	{
		if (object == nullptr)
			return;

		SAFE_DELETE(object);
	}
}