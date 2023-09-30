#pragma once

#include "Vector3.h"


namespace XPlatform
{
	union Matrix16
	{
		struct
		{
			float M11, M12, M13, M14;
			float M21, M22, M23, M24;
			float M31, M32, M33, M34;
			float M41, M42, M43, M44;
		};

		float Array[4][4]; // Value[y][x];
	};

	void SetMatrixTranslation(Matrix16& matrix, Vector3& vec);
	void SetMatrixScale(Matrix16& matrix, Vector3& vec);
	void SetMatrixRotation(Matrix16& matrix, Vector3& vec);

	Matrix16 GetMatrixIdentity();
	Matrix16 GetMatrixInverse(Matrix16& matrix);
	Vector3 GetMatrixTranslation(const Matrix16& matrix);
	Vector3 GetMatrixScale(const Matrix16& matrix);
	Vector3 GetMatrixRotation(const Matrix16& matrix);
}
