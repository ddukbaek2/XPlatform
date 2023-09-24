#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	///////////////////////////////////////////////////////////////////////////////
	//// @ 오브젝트 관리버퍼 반환.
	///////////////////////////////////////////////////////////////////////////////
	//auto& GetSharedAllObjects()
	//{
	//	static std::vector<Object*> sharedAllObjects;
	//	return sharedAllObjects;
	//}

	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트 생성기 반환.
	/////////////////////////////////////////////////////////////////////////////
	auto& GetSharedObjectCreator()
	{
		static std::map<std::wstring, ObjectCreateLambda> sharedObjectCreator;
		return sharedObjectCreator;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 오브젝트를 상속받은 객체들 생성 람다함수 셋팅.
	/////////////////////////////////////////////////////////////////////////////
	void SetObjectCreator(std::wstring className, ObjectCreateLambda lambda)
	{
		auto& sharedObjectCreator = GetSharedObjectCreator();
		auto it = sharedObjectCreator.find(className);

		if (it != sharedObjectCreator.end())
			return;

		sharedObjectCreator[className] = lambda;
	}

	//void CheckAllReferences()
	//{
	//	auto& sharedAllObjects = GetSharedAllObjects();
	//	auto it = sharedAllObjects.begin();
	//	while (it != sharedAllObjects.end())
	//	{	
	//		auto sharedObject = *it;
	//		if (sharedObject == nullptr)
	//		{
	//			it = sharedAllObjects.erase(it);
	//		}
	//		else if (sharedObject->GetReferenceCount() <= 0)
	//		{
	//			//sharedObject->OnDestroy();
	//			SAFE_DELETE(sharedObject);
	//			it = sharedAllObjects.erase(it);
	//		}

	//		++it;
	//	}
	//}

	Object::Object()
	{
		m_InstanceID = 0;
	}

	Object::~Object()
	{
		// 레퍼런스카운트가 0이되어 삭제처리 되면 OnDestroy() 호출.
		OnDestroy();
	}

	void Object::OnCreate()
	{
	}

	void Object::OnDestroy()
	{
	}

	//uint64_t Object::GetReferenceCount()
	//{
	//	return m_ReferenceCount;
	//}

	uint64_t Object::GetInstanceID()
	{
		return m_InstanceID;
	}

	Object* Object::Instantiate(const std::wstring& className)
	{
		auto& sharedObjectCreator = GetSharedObjectCreator();
		auto object = sharedObjectCreator[className]();

		//auto& sharedAllObjects = GetSharedAllObjects();
		//sharedAllObjects.push_back(object);
		//++object->m_ReferenceCount;
		object->OnCreate();
		return object;
	}

	//void Object::Destroy(Object* object)
	//{
	//	if (object == nullptr)
	//		return;

	//	//--object->m_ReferenceCount;
	//	//SAFE_DELETE(object);
	//}

	//void Object::DestroyImmediate(Object* object)
	//{
	//	if (object == nullptr)
	//		return;

	//	//auto& sharedAllObjects = GetSharedAllObjects();
	//	//sharedAllObjects.erase(std::remove(sharedAllObjects.begin(), sharedAllObjects.end(), object), sharedAllObjects.end());
	//	object->OnDestroy();
	//	SAFE_DELETE(object);
	//}
}