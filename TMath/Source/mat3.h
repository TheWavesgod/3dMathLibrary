#pragma once

namespace TM
{
	class vec3;

	class mat3
	{
	public:
		mat3()
		{
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					mat[i][j] = 0.0f;
				}
			}
		}


		float* operator [](int row) { return mat[row]; }
		const float* operator [](int row) const { return mat[row]; }

	private:
		float mat[3][3];
	};

	mat3 operator *(const mat3& a, const mat3& b);
	vec3 operator *(const mat3& m, const vec3& v);
}

