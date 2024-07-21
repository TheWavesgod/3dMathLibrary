#pragma once

#include <math.h>
#include <iostream>

namespace TM
{
	class vec3
	{
	public:
		vec3()
		{
			x = y = z = 0.0f;
		}

		vec3(const vec3& cpy) : x(cpy.x), y(cpy.y), z(cpy.z) {}

		vec3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

		float x, y, z;


		vec3 operator -() const { return vec3(-x, -y, -z); }

		vec3 operator +(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }

		vec3 operator -(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }

		vec3 operator *(float n) const { return vec3(x * n, y * n, z * n); }

		vec3 operator /(float n) const
		{
			float oneOverN = 1.0f / n;
			return vec3(x * oneOverN, y * oneOverN, z * oneOverN);
		}

		vec3 operator +=(const vec3& v)
		{
			x += v.x; y += v.y; z += v.z;
			return *this;
		}

		vec3 operator -=(const vec3& v)
		{
			x -= v.x; y -= v.y; z -= v.z;
			return *this;
		}

		vec3 operator *=(float n)
		{
			x *= n; y *= n; z *= n;
			return *this;
		}

		vec3 operator /=(float n)
		{
			float oneOverN = 1.0f / n;
			x *= oneOverN; y *= oneOverN; z *= oneOverN;
			return *this;
		}

		float operator *(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }

		inline float length() const { return sqrt(x * x + y * y + z * z); }

		void normalize()
		{
			float mag = x * x + y * y + z * z;
			if (mag > 0)
			{
				float  oneOverMag = 1.0f / sqrt(mag);
				x *= oneOverMag;
				y *= oneOverMag;
				z *= oneOverMag;
			}
		}

		inline float dot(const vec3& v) const { return x * v.x + y * v.y + z * v.z; }
		inline vec3 cross(const vec3& v) const { return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x - v.y - y * v.x); }

		void print() const { std::cout << "[ " << x << ", " << y << ", " << z << " ]\n"; }
	};

	inline vec3 operator *(float k, const vec3& v)
	{
		return vec3(k * v.x, k * v.y, k * v.z);
	}

	inline float Distance(const vec3& a, const vec3& b)
	{
		return vec3(a - b).length();
	}

	inline vec3 Cross(const vec3& a, const vec3& b)
	{
		return vec3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x - b.y - a.y * b.x
		);
	}
}


