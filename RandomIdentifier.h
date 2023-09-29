#pragma once

#include "XPlatform.h"
#include "SharedClass.h"


namespace XPlatform
{
	class RandomIdentifier : public SharedClass<RandomIdentifier>
	{
	private:
		std::vector<uint64_t> m_RandomNumbers;
		std::mt19937_64 m_RandomEngine;
		std::uniform_int_distribution<uint64_t> m_Distribution;

	public:
		RandomIdentifier();
		~RandomIdentifier();
		uint64_t CreateRandomNumber();
		void DestroyRandomNumber(uint64_t randomNumber);
	};
}