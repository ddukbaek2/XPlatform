#pragma once


namespace XPlatform
{
	class Object
	{
	private:
	public:
		Object();
		virtual ~Object();

		static void Destroy(Object* object);
		static void DestroyImmediate(Object* object);
	};
}