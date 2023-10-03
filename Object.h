#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 기반 오브젝트 : 해당 오브젝트로 생성하는 객체는 모두 다 new 를 통한 힙메모리 할당이다.
	/////////////////////////////////////////////////////////////////////////////
	class Object
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
	};


	//template<typename TObject> class Reference
	//{
	//private:
	//	static std::unordered_map<uint64_t, uint32_t> m_References;
	//	
	//private:
	//	Object* m_Target;

	//public:
	//	Reference(const Reference<TObject>& reference)
	//	{
	//		m_Target = reference.m_Target;
	//		Increase();
	//	}

	//	Reference(Object* target)
	//	{
	//		m_Target = target;
	//		Increase();
	//	}

	//	~Reference()
	//	{
	//		Decrease();
	//		m_Target = nullptr;
	//	}

	//	TObject* Get()
	//	{
	//		return m_Target;
	//	}

	//	static std::shared_ptr<TObject> Create()
	//	{
	//		return Reference<TObject>(new TObject());
	//	}


	//private:
	//	void Increase()
	//	{
	//		if (m_Target == nullptr)
	//			return;

	//		auto objectID = m_Target->GetObjectID();
	//		auto it = m_References.find(objectID);
	//		auto referenceCount = 1;
	//		if (it == m_References.end())
	//		{
	//			m_References.emplace(objectID, referenceCount);
	//		}
	//		else
	//		{
	//			referenceCount += m_References[objectID];
	//			m_References[objectID] = referenceCount;
	//		}
	//	}

	//	void Decrease()
	//	{
	//		if (m_Target == nullptr)
	//			return;

	//		auto objectID = m_Target->GetObjectID();
	//		auto it = m_References.find(objectID);
	//		if (it == m_References.end())
	//		{
	//			// 관리되지 않은 객체.
	//			// 혹은 이미 파괴된 객체.
	//		}
	//		else
	//		{
	//			auto referenceCount = m_References[objectID];
	//			--referenceCount;
	//			if (referenceCount < 0)
	//				referenceCount = 0;

	//			if (referenceCount <= 0)
	//			{
	//				Destroy(this);
	//				//m_References[objectID] = referenceCount;
	//				//m_References.erase(objectID);
	//			}
	//		}
	//	}

	//public:
	//	static void Destroy(Reference<TObject>& object)
	//	{
	//		auto objectID = object.GetObjectID();
	//		auto it = m_References.find(objectID);
	//		if (it == m_References.end())
	//			return;

	//		// 참조가 사라지면...
	//		// 정리타이밍 때 객체를 아예 파괴한다.
	//		m_References[objectID] = 0;
	//		//m_References.erase(objectID);
	//	}

	//	static void DestroyImmediate(Reference<TObject>& object)
	//	{
	//		auto objectID = object.GetObjectID();
	//		auto it = m_References.find(objectID);
	//		if (it == m_References.end())
	//			return;

	//		// 제거.
	//		m_References.erase(objectID);

	//		// 실제 객체의 즉시 파괴.
	//		SAFE_DELETE(object.m_Target);
	//	}
	//};
}
