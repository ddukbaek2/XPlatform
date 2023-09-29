#include "RandomIdentifier.h"


namespace XPlatform
{
	RandomIdentifier::RandomIdentifier() : SharedClass()
	{
		// 랜덤 목록 초기화.
		m_RandomNumbers.clear();

		// 64비트 랜덤 엔진 초기화.
		m_RandomEngine = std::mt19937_64(std::random_device{}());
		m_Distribution = std::uniform_int_distribution<uint64_t>(0, UINT64_MAX);
	}

	RandomIdentifier::~RandomIdentifier()
	{
	}

	uint64_t RandomIdentifier::CreateRandomNumber()
	{
		uint64_t randomNumber = 0;
		do
		{
			randomNumber = m_Distribution(m_RandomEngine);
		} 
		while (std::find(m_RandomNumbers.begin(), m_RandomNumbers.end(), randomNumber) == m_RandomNumbers.end());
		
		m_RandomNumbers.push_back(randomNumber);
		return randomNumber;
	}

	void RandomIdentifier::DestroyRandomNumber(uint64_t randomNumber)
	{
		auto it = std::find(m_RandomNumbers.begin(), m_RandomNumbers.end(), randomNumber);
		if (it == m_RandomNumbers.end())
			return;

		m_RandomNumbers.erase(it);
	}
}