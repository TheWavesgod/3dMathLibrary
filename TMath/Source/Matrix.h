#pragma once

#include <stdexcept>
#include <cassert>
#include <array>
#include "vector.h"

namespace TM
{
	template <size_t N>
	class Matrix
	{
	public:
		Matrix()
		{
			for (auto& row : data)
			{
				row.fill(0.0f);
			}
		}

		float* operator [](size_t row)
		{
			if (row >= N) { throw std::out_of_range("Row index out of range"); }
			return data[row].data();
		}

		const float* operator [](size_t row) const
		{
			if (row >= N) { throw std::out_of_range("Row index out of range"); }
			return data[row].data();
		}

		Matrix<N> operator *(const Matrix<N>& m) const 
		{
			Matrix<N> result;
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < N; ++j)
				{
					for (size_t k = 0; k < N; ++k)
					{
						result.data[i][j] += data[i][k] * m.data[k][j];
					}
				}
			}
			return result;
		}

		vector<N> operator* (const vector<N> vec) const
		{
			vector<N> result;
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t k = 0; k < N; ++k)
				{
					result[i] += vec[k] * data[i][k];
				}
			}
			return result;
		}

	private:
		std::array<std::array<float, N>, N> data;
	};

	using mat2 = Matrix<2>;
	using mat3 = Matrix<3>;
	using mat4 = Matrix<4>;

	template <size_t N>
	Matrix<N> toMat4(const vector<3> axis, float radians)
	{
		static_assert(N == 4);
		Matrix<N> result;
		if constexpr (N == 4)
		{

		}
		return result;
	}

	mat4 Scale(const vec3& scaleVec)
	{
		mat4 result;
		result[0][0] = scaleVec.x;
		result[1][1] = scaleVec.y;
		result[2][2] = scaleVec.z;
		result[3][3] = 1.0f;
		return result;
	}

	float determinant(const mat2& m)
	{
		return m[0][0] * m[1][1] - m[0][1] * m[1][0];
	}


	float determinant(const mat3& m)
	{
		return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
			+ m[0][1] * (m[1][2] * m[2][0] - m[1][0] * m[2][2])
			+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	}


	mat3 inverse(const mat3& m)
	{
		float det = determinant(m);
		assert(fabs(det) > 0.0000001f);

		float oneOverDet = 1.0f / det;
		mat3 r;

		for (size_t i = 0; i < 3; ++i)
		{
			for (size_t j = 0; j < 3; ++j)
			{
				r[i][j] = m[i][j];
			}
		}
	}
}

