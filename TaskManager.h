#pragma once

#include "XPlatform.h"



namespace XPlatform
{
	class ITask
	{
	public:


	};

	template<typename T> class Task : public ITask
	{
	public:
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 비동기 단위 작업.
	/////////////////////////////////////////////////////////////////////////////
	class TaskManager
	{
	private:
		std::queue<std::future<int>> m_TaskQueue;
		std::mutex m_QueueMutex;

	public:
		TaskManager();
		virtual ~TaskManager();

		void StartTask(std::function<int()> onWork, std::function<void(int)> onComplete)
		{
			std::unique_lock<std::mutex> lock(m_QueueMutex);
			m_TaskQueue.push(std::async(std::launch::async, [this, onWork, onComplete]()
			{
				int result = onWork();
				onComplete(result);
				return result;
			}));
		}

		bool IsTaskCompleted(std::future<int>& task)
		{
			return task.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
		}
	};
}