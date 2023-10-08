#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기반 오브젝트 : 해당 오브젝트로 생성하는 객체는 모두 다 new 를 통한 힙메모리 할당이다.
	/////////////////////////////////////////////////////////////////////////////
	class Object : public std::enable_shared_from_this<Object>
	{
	private:
		uint64_t m_ObjectID;

	public:
		Object();
		Object(uint64_t ObjectID);
		virtual ~Object();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();

	public:
		uint64_t GetObjectID();

		template<typename T> inline typename std::enable_if<std::is_base_of<Object, T>::value, Ref<T>>::type GetRef()
		{
			auto shared = this->shared_from_this();
			return std::static_pointer_cast<T>(shared);
		};
	};
}
