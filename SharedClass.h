#pragma once


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 공유 클래스.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> class SharedClass
	{
	protected:
		//SharedClass() {}
	public:
		SharedClass() {}
		virtual ~SharedClass() {}

		static T* GetSharedInstance()
		{
			// C++11 이후 함수 안에서 선언한 static 변수의 초기화는 원자성 보장.
			static T instance;
			return &instance;
		}

		SharedClass(const SharedClass&) = delete;
		void operator = (const SharedClass&) = delete;
	};
}