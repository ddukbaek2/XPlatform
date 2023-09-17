#pragma once
#include "Win32Application.h"
#include "SharedClass.h"


namespace XPlatform
{
	class Win32GL : public IGL, public SharedClass<Win32GL>
	{
	private:
		friend class SharedClass<Win32GL>;
		Win32GL() {}

	public:
		void Clear(AttribMask attribMask);
		void SetClearColor(float r, float g, float b, float a);
		void PushMatrix();
		void SetMatrixMode(MatrixMode matrixMode);
		void Translatef(float x, float y, float z);
		void Scalef(float x, float y, float z);
		void Rotatef(float angle, float x, float y, float z);
		void PopMatrix();
		void LoadIdentity();
		void Begin(BeginMode beginMode);
		void Color4f(float r, float g, float b, float a);
		void Vertex3f(float x, float y, float z);
		void TexCoord2f(float u, float v);
		void End();
		void Flush();
		void SetViewport(int x, int y, int width, int height);
		void Enable();
		void GenTextures();
		void DeleteTexture();
		void BindTexture(unsigned int texture);
		void TexParameteri();
		void TexImage2D();
	};
}