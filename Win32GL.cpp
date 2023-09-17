#include "XPlatform.h"
#include "Win32GL.h"

#include <windows.h>
#include <gl/GL.h>
#pragma comment(lib, "opengl32.lib")

namespace XPlatform
{
	void Win32GL::Clear(AttribMask attribMask)
	{
		glClear((unsigned int)attribMask);
	}

	void Win32GL::SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void Win32GL::PushMatrix()
	{
		glPushMatrix();
	}

	void Win32GL::SetMatrixMode(MatrixMode matrixMode)
	{
		glMatrixMode((unsigned int)matrixMode);
	}

	void Win32GL::Translatef(float x, float y, float z)
	{
		glTranslatef(x, y, z);
	}

	void Win32GL::Scalef(float x, float y, float z)
	{
		glScalef(x, y, z);
	}

	void Win32GL::Rotatef(float angle, float x, float y, float z)
	{
		glRotatef(angle, x, y, z);
	}

	void Win32GL::PopMatrix()
	{
		glPopMatrix();
	}
	void Win32GL::LoadIdentity()
	{
		glLoadIdentity();
	}
	void Win32GL::Begin(BeginMode beginMode)
	{
		glBegin((unsigned int)beginMode);
	}
	void Win32GL::Color4f(float r, float g, float b, float a)
	{
		glColor4f(r, g, b, a);
	}

	void Win32GL::Vertex3f(float x, float y, float z)
	{
		glVertex3f(x, y, z);
	}

	void Win32GL::TexCoord2f(float u, float v)
	{
		glTexCoord2f(u, v);
	}
	
	void Win32GL::End()
	{
		glEnd();
	}

	void Win32GL::Flush()
	{
		glFlush();
	}

	void Win32GL::SetViewport(int X, int Y, int Width, int Height)
	{
		glViewport(X, Y, Width, Height);
	}

	void Win32GL::Enable()
	{
		glEnable(GL_TEXTURE_2D);
	}

	void Win32GL::GenTextures()
	{
		unsigned int textures = 0;
		glGenTextures(1, &textures);
	}

	void Win32GL::DeleteTexture()
	{
		unsigned int textures = 0;
		glDeleteTextures(1, &textures);
	}

	void Win32GL::BindTexture(unsigned int texture)
	{
		glBindTexture((unsigned int)GL_TEXTURE_2D, texture);
	}

	void Win32GL::TexParameteri()
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void Win32GL::TexImage2D()
	{
		glTexImage2D(0, 0, 0, 0, 0, 0, 0, 0, 0);
	}
}