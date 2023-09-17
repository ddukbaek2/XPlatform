#pragma once

template<typename T> class SharedClass
{
protected:
	SharedClass() {}

public:
	static T* GetSharedInstance()
	{
		static T instance;
		return &instance;
	}

	SharedClass(SharedClass const&) = delete;
	void operator=(SharedClass const&) = delete;
};