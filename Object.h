#pragma once

#include <map>
#include <string>
#include <functional>
#include <cstdint>


/////////////////////////////////////////////////////////////////////////////
// @ 내부 인스턴스 생성기에 오브젝트를 상속받은 객체들 추가.
/////////////////////////////////////////////////////////////////////////////
#define RegisterObject(CLASS) \
    namespace { \
        struct __##CLASS##Register__ { \
            __##CLASS##Register__() { \
				SetObjectCreator(L#CLASS, []() -> Object* { return new CLASS(); });\
            } \
        }; \
    } \
    static __##CLASS##Register__ g_##CLASS##RegisterInstance;


/////////////////////////////////////////////////////////////////////////////
// @ 오브젝트를 상속받은 객체들 생성.
/////////////////////////////////////////////////////////////////////////////
#define CreateInstance(CLASS) (CLASS*)Object::Instantiate(L#CLASS)


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 : CreateInstance 로 생성되는 모든 라이브러리 객체들의 기본 클래스.
	/////////////////////////////////////////////////////////////////////////////
	class Object
	{
	private:
		uint64_t m_ReferenceCount;
		uint64_t m_InstanceID;
		
	public:
		Object();
		virtual ~Object();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();

	public:
		uint64_t GetReferenceCount();
		uint64_t GetInstanceID();

	public:
		static Object* Instantiate(const std::wstring& className);
		static void Destroy(Object* object);
		static void DestroyImmediate(Object* object);
	};

	typedef std::function<Object* (void)> ObjectCreateLambda;
	void SetObjectCreator(std::wstring className, ObjectCreateLambda lambda);
}