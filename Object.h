#pragma once

#include"XPlatform.h"


/////////////////////////////////////////////////////////////////////////////
// @ 내부 인스턴스 생성기에 오브젝트를 상속받은 객체들 추가.
/////////////////////////////////////////////////////////////////////////////
#define RegisterObject(CLASS)\
    namespace {\
        struct __##CLASS##Register__ {\
            __##CLASS##Register__() {\
				SetObjectCreator(L#CLASS, []() -> Object* { return new CLASS(); });\
            }\
        };\
    }\
    static __##CLASS##Register__ g_##CLASS##RegisterInstance;


/////////////////////////////////////////////////////////////////////////////
// @ 오브젝트를 상속받은 객체들 생성.
/////////////////////////////////////////////////////////////////////////////
//#define CreateInstance(CLASS) std::shared_ptr<CLASS>((CLASS*)Object::Instantiate(L#CLASS))
#define CreateInstance(CLASS) std::shared_ptr<CLASS>((CLASS*)Object::Instantiate(L#CLASS))
//#define DestroyInstance(INSTANCE) if (INSTANCE.)


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 : CreateInstance 로 생성되는 모든 라이브러리 객체들의 기본 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class Object
	{
	private:
		uint64_t m_InstanceID;
		
	public:
		Object();
		virtual ~Object();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();

	public:
		//uint64_t GetReferenceCount();
		uint64_t GetInstanceID();

	public:
		static Object* Instantiate(const std::wstring& className);
		//static void DestroyImmediate(Object* object);

		template<typename T> static std::shared_ptr<T> Create(const std::wstring& className);
		template<typename T> static void Destroy(std::shared_ptr<T>* object);
	};

	typedef std::function<Object* (void)> ObjectCreateLambda;
	void SetObjectCreator(std::wstring className, ObjectCreateLambda lambda);

	template<typename T> inline std::shared_ptr<T> Object::Create(const std::wstring& className)
	{
		auto object = (T*)Object::Instantiate(className);
		return std::shared_ptr<T>(object);
	}

	template<typename T> inline void Object::Destroy(std::shared_ptr<T>* object)
	{
		object.reset();
		object = nullptr;
	}
}