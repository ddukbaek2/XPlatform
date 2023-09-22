#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	std::map<std::string, std::function<Object* (void)>> g_ObjectFactory;


	template <typename T> T* Clone(const T* original)
	{
		return new T();
	}

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

	Object* Object::Clone()
	{
		return nullptr;
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