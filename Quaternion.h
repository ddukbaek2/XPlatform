#pragma once

#include "XPlatform.h"
#include "MathHelper.h"
#include "Vector3.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 쿼터니언.
	/////////////////////////////////////////////////////////////////////////////
	struct Quaternion
	{
		union
		{
			struct
			{
				float W;
				float X;
				float Y;
				float Z;
			};

			float Array[4];
		};

		Quaternion()
		{
			W = X = Y = Z = 0.0f;
		}

		Quaternion(float w, float x, float y, float z)
		{
			W = w;
			X = x;
			Y = y;
			Z = z;
		}

		void Normalize()
		{
			auto normalized = sqrt(W * W + X * X + Y * Y + Z * Z);
			W /= normalized;
			X /= normalized;
			Y /= normalized;
			Z /= normalized;
		}

		static Quaternion ToNormalize(Quaternion quaternion)
		{
			Quaternion result;
			result.W = quaternion.W;
			result.X = quaternion.X;
			result.Y = quaternion.Y;
			result.Z = quaternion.Z;
			result.Normalize();

			return result;
		}

		static Quaternion ToQuaternion(const Vector3& eulerAngles)
		{
			return ToQuaternion(eulerAngles.X, eulerAngles.Y, eulerAngles.Z);
		}

		static Quaternion ToQuaternion(float roll, float pitch, float yaw)
		{
			float p = pitch * 0.5;
			float y = yaw * 0.5;
			float r = roll * 0.5;

			float sinp = std::sin(p);
			float siny = std::sin(y);
			float sinr = std::sin(r);
			float cosp = std::cos(p);
			float cosy = std::cos(y);
			float cosr = std::cos(r);

			Quaternion quaternion;
			quaternion.W = cosr * cosp * cosy + sinr * sinp * siny;
			quaternion.X = sinr * cosp * cosy - cosr * sinp * siny;
			quaternion.Y = cosr * sinp * cosy + sinr * cosp * siny;
			quaternion.Z = cosr * cosp * siny - sinr * sinp * cosy;

			return quaternion;
		}

		static Vector3 ToEulerAngles(const Quaternion& quaternion)
		{
			return ToEulerAngles(quaternion.W, quaternion.X, quaternion.Y, quaternion.Z);
		}

		static Vector3 ToEulerAngles(float w, float x, float y, float z)
		{
			Vector3 eulerAngles;

			// Roll (X-axis rotation)
			auto sinRollAndcosPitch = 2.0f * (w * x + y * z);
			auto cosRollAndcosPitch = 1.0f - 2.0f * (x * x + y * y);
			eulerAngles.Z = std::atan2(sinRollAndcosPitch, cosRollAndcosPitch);

			// Pitch (Y-axis rotation)
			auto sinPitch = 2.0f * (w * y - z * x);
			if (std::abs(sinPitch) >= 1.0f)
			{
				eulerAngles.X = std::copysign(MathHelper::PI / 2, sinPitch); // Use 90 degrees if out of range
			}
			else
			{
				eulerAngles.X = std::asin(sinPitch);
			}

			// Yaw (Z-axis rotation)
			auto sinYawAndcosPitch = 2.0f * (w * z + x * y);
			auto cosYwaAndcosPitch = 1.0f - 2.0f * (y * y + z * z);
			eulerAngles.Y = std::atan2(sinYawAndcosPitch, cosYwaAndcosPitch);

			return eulerAngles;
		}
	};
}
