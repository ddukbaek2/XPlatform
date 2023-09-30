#include <cmath>

#include "Matrix16.h"


namespace XPlatform
{
	void SetMatrixTranslation(Matrix16& matrix, Vector3& vec)
	{
		matrix.Array[0][3] = vec.X;
		matrix.Array[1][3] = vec.Y;
		matrix.Array[2][3] = vec.Z;
	}

	void SetMatrixScale(Matrix16& matrix, Vector3& vec)
	{
		matrix.Array[0][0] = vec.X;
		matrix.Array[1][1] = vec.Y;
		matrix.Array[2][2] = vec.Z;
	}

	void SetMatrixRotation(Matrix16& matrix, Vector3& vec)
	{
		auto cos_rx = cos(vec.X), sin_rx = sin(vec.X);
		auto cos_ry = cos(vec.Y), sin_ry = sin(vec.Y);
		auto cos_rz = cos(vec.Z), sin_rz = sin(vec.Z);

		matrix.Array[0][0] = cos_ry * cos_rz;
		matrix.Array[0][1] = -cos_ry * sin_rz;
		matrix.Array[0][2] = sin_ry;

		matrix.Array[1][0] = sin_rx * sin_ry * cos_rz + cos_rx * sin_rz;
		matrix.Array[1][1] = -sin_rx * sin_ry * sin_rz + cos_rx * cos_rz;
		matrix.Array[1][2] = -sin_rx * cos_ry;

		matrix.Array[2][0] = -cos_rx * sin_ry * cos_rz + sin_rx * sin_rz;
		matrix.Array[2][1] = cos_rx * sin_ry * sin_rz + sin_rx * cos_rz;
		matrix.Array[2][2] = cos_rx * cos_ry;
	}

	Matrix16 GetMatrixIdentity()
	{
		Matrix16 matrix;
		for (auto y = 0; y < 4; ++y)
		{
			for (auto x = 0; x < 4; ++x)
			{
				if (x == y)
					matrix.Array[y][x] = 1.0f;
				else
					matrix.Array[y][x] = 0.0f;

			}
		}

		return matrix;
	}

	Matrix16 GetMatrixInverse(Matrix16& matrix)
	{
		// 고민중...
		return matrix;
	}

	Vector3 GetMatrixTranslation(const Matrix16& matrix)
	{
		Vector3 vec;
		vec.X = matrix.Array[0][3];
		vec.Y = matrix.Array[1][3];
		vec.Z = matrix.Array[2][3];

		return vec;
	}

	Vector3 GetMatrixScale(const Matrix16& matrix)
	{
		Vector3 vec;
		vec.X = sqrt(matrix.Array[0][0] * matrix.Array[0][0] + matrix.Array[0][1] * matrix.Array[0][1] + matrix.Array[0][2] * matrix.Array[0][2]);
		vec.Y = sqrt(matrix.Array[1][0] * matrix.Array[1][0] + matrix.Array[1][1] * matrix.Array[1][1] + matrix.Array[1][2] * matrix.Array[1][2]);
		vec.Z = sqrt(matrix.Array[2][0] * matrix.Array[2][0] + matrix.Array[2][1] * matrix.Array[2][1] + matrix.Array[2][2] * matrix.Array[2][2]);

		return vec;
	}

	Vector3 GetMatrixRotation(const Matrix16& matrix)
	{
		Vector3 vec;
		vec.X = asin(matrix.Array[0][2]);
		vec.Y = atan2(-matrix.Array[1][2], matrix.Array[2][2]);
		vec.Z = atan2(-matrix.Array[0][1], matrix.Array[0][0]);

		return vec;
	}
}
