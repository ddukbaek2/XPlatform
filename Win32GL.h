#pragma once

#include "XGL.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 윈도우 OpenGL.
	/////////////////////////////////////////////////////////////////////////////
	class Win32GL : public XGL
	{
	private:
		//friend class SharedClass<Win32GL>;
		
	public:
		Win32GL() {}
		~Win32GL() {}

		void Clear(AttribMask attribMask) override;
		void SetClearColor(float r, float g, float b, float a) override;
		void PushMatrix() override;
		void SetMatrixMode(MatrixMode matrixMode) override;
		void Translatef(float x, float y, float z) override;
		void Scalef(float x, float y, float z) override;
		void Rotatef(float angle, float x, float y, float z) override;
		void PopMatrix() override;
		void LoadIdentity() override;
		void Begin(BeginMode beginMode) override;
		void Color4f(float r, float g, float b, float a) override;
		void Vertex3f(float x, float y, float z) override;
		void TexCoord2f(float u, float v) override;
		void End() override;
		void Flush() override;
		void SetViewport(int32_t x, int32_t y, uint32_t width, uint32_t height) override;
		void Enable() override;
		void GenTextures() override;
		void DeleteTexture() override;
		void BindTexture(uint32_t texture) override;
		void TexParameteri() override;
		void TexImage2D() override;
	};
}