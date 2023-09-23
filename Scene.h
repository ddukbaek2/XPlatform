#pragma once
#include "XPlatform.h"
#include "Object.h"
#include "String.h"
#include "Node.h"


namespace XPlatform
{
	class Scene : public Object
	{
	protected:
		std::wstring m_Name;
		bool m_IsVisible;
		Node* m_Root;

	public:
		void SetVisible(bool visible);
		bool IsVisible();

	protected:
		void OnCreate() override;
		void OnDestroy() override;
	};

	RegisterObject(Scene);
}