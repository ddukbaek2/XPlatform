#pragma once

template<typename T> class SharedClass
{
protected:
	SharedClass() {}

public:
	virtual ~SharedClass() {}

	static T* GetSharedInstance()
	{
		static T instance;
		return &instance;
	}

	SharedClass(SharedClass const&) = delete;
	void operator=(SharedClass const&) = delete;
};