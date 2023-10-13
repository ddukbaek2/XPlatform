#pragma once

#include "Vector3.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 매트릭스.
	/////////////////////////////////////////////////////////////////////////////
	struct Matrix16
	{
		union
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

		static void SetMatrixTranslation(Matrix16& matrix, Vector3& vec);
		static void SetMatrixScale(Matrix16& matrix, Vector3& vec);
		static void SetMatrixRotation(Matrix16& matrix, Vector3& vec);

		static Matrix16 GetMatrixIdentity();
		static Matrix16 GetMatrixInverse(Matrix16& matrix);
		static Vector3 GetMatrixTranslation(const Matrix16& matrix);
		static Vector3 GetMatrixScale(const Matrix16& matrix);
		static Vector3 GetMatrixRotation(const Matrix16& matrix);
	};
}
