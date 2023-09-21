#pragma once


namespace XPlatform
{
	class Object
	{
	private:
		unsigned int m_ReferenceCount;

	public:
		Object();
		virtual ~Object();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();

	public:
		static void Destroy(Object* object);
		static void DestroyImmediate(Object* object);
	};
}