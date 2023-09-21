#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	template <typename T> T* Clone(const T* original)
	{
		static_assert(std::is_base_of<Object, T>::value, "T must be a subclass of Object");
		return dynamic_cast<T*>(original->Clone());
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

	Object Object::Clone()
	{
		return Object();
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