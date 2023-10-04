#include "InitializeScene.h"
#include "Object.h"
#include "SceneManager.h"


//namespace XPlatform
//{
//	const char g_VertexShader[256] = R"(
//		void main() {
//			gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
//		}
//	)";


//	/////////////////////////////////////////////////////////////////////////////
//	// @ 생성됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnCreate()
//	{
//		//m_RootNode = CreateInstance(Node);
//		//CreateInstance(Component);
//	}
//
//	/////////////////////////////////////////////////////////////////////////////
//	// @ 파괴됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnDestroy()
//	{
//		//m_RootNode.reset();
//		//Object::Destroy(m_RootNode);
//	}
//
//	/////////////////////////////////////////////////////////////////////////////
//	// @ 일시정지됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnPause()
//	{
//	}
//
//	/////////////////////////////////////////////////////////////////////////////
//	// @ 재개됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnResume()
//	{
//	}
//
//	/////////////////////////////////////////////////////////////////////////////
//	// @ 갱신됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnUpdate(float deltaTime)
//	{
//	}
//
//	/////////////////////////////////////////////////////////////////////////////
//	// @ 출력됨.
//	/////////////////////////////////////////////////////////////////////////////
//	void ApplicationEventHandler::OnRender(Reference<IGL> gl)
//	{
//		// 사각형 출력.
//		gl->Clear(IGL::AttribMask::GL_COLOR_BUFFER_BIT);
//		gl->LoadIdentity();
//
//		// glDrawArrays
//
//		gl->Begin(IGL::BeginMode::GL_QUADS);
//		gl->Vertex3f(-0.5f, -0.5f, 0.0f); // 좌하.
//		gl->Color4f(1.0f, 0.0f, 0.0f, 1.0f);
//		gl->Vertex3f(0.5f, -0.5f, 0.0f); // 우하.
//		gl->Color4f(1.0f, 0.0f, 1.0f, 1.0f);
//		gl->Vertex3f(0.5f, 0.5f, 0.0f); // 우상.
//		gl->Color4f(1.0f, 0.0f, 0.0f, 1.0f);
//		gl->Vertex3f(-0.5f, 0.5f, 0.0f); // 좌상.
//		gl->Color4f(1.0f, 1.0f, 0.0f, 1.0f);
//		gl->End();
//		gl->Flush();
//	}
//}

void InitializeScene::OnCreate()
{
	Base::OnCreate();
}

void InitializeScene::OnDestroy()
{
	Base::OnDestroy();
}

void InitializeScene::OnRender(Ref<IGL> gl)
{
		// 사각형 출력.
		gl->Clear(IGL::AttribMask::GL_COLOR_BUFFER_BIT);
		gl->LoadIdentity();

		// glDrawArrays

		gl->Begin(IGL::BeginMode::GL_QUADS);
		gl->Vertex3f(-0.5f, -0.5f, 0.0f); // 좌하.
		gl->Color4f(1.0f, 0.0f, 0.0f, 1.0f);
		gl->Vertex3f(0.5f, -0.5f, 0.0f); // 우하.
		gl->Color4f(1.0f, 0.0f, 1.0f, 1.0f);
		gl->Vertex3f(0.5f, 0.5f, 0.0f); // 우상.
		gl->Color4f(1.0f, 0.0f, 0.0f, 1.0f);
		gl->Vertex3f(-0.5f, 0.5f, 0.0f); // 좌상.
		gl->Color4f(1.0f, 1.0f, 0.0f, 1.0f);
		gl->End();
		gl->Flush();
}
