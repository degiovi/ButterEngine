#pragma once
#include <glm/gtc/matrix_transform.hpp>

namespace Butter
{
	template<typename T>
	class Mat2D
	{
	public:


		Mat2D()
		{
			Mat2D(1, 1);
		}

		Mat2D(int in_width, int in_height)
		{

			List<T> rows(in_width);
			data.assign(in_height, rows);
			
		}

		Mat2D(List<List<T>> in_data)
			: data(in_data)
		{
		}

		~Mat2D()
		{
		}

		void Set(int x, int y, T value)
		{
			data[x][y] = value;
		}

		T* Get(int x, int y)
		{
			return &data[x][y];
		}

		void Print() 
		{
			for (List<T> row : data) {

				for (T & val : row)
				{
					val.Print();
				}
			}
		}

	private:
		List<List<T>> data;
	};


	class Vector2
	{
	public:
		
		Vector2(float in_x, float in_y)
			: x(in_x), y(in_y)
		{
		}

		inline const float GetX() const { return x; }
		inline const float GetY() const { return y; }

		inline const void SetX(float in_x) { x = in_x; }
		inline const void SetY(float in_y) { y = in_y; }

		inline const void Print() const { BTR_INFO("Vector2 (X: {0}, Y: {1})", x, y); }

	private:
		float x = 0.0f;
		float y = 0.0f;
	};

	class Vector3
	{
	public:

		Vector3()
			: x(0.0f), y(0.0f), z(0.0f)
		{
		}

		Vector3(float in_x, float in_y, float in_z)
			: x(in_x), y(in_y), z(in_z)
		{
		}

		inline const float GetX() const { return x; }
		inline const float GetY() const { return y; }
		inline const float GetZ() const { return z; }

		inline const void SetX(float in_x) { x = in_x; }
		inline const void SetY(float in_y) { y = in_y; }
		inline const void SetZ(float in_z) { z = in_z; }

		inline const void Print() const { BTR_INFO("Vector3 (X: {0}, Y: {1}, Z: {2})", x, y, z); }

		Vector3 operator+(const Vector3& v) 
		{
			Vector3 result;
			result.x = this->x + v.x;
			result.y = this->y + v.y;
			result.z = this->z + v.z;
			return result;
		}

		Vector3 operator*(const Vector3& v)
		{
			Vector3 result;
			result.x = this->x * v.x;
			result.y = this->y * v.y;
			result.z = this->z * v.z;
			return result;
		}

		Vector3 operator*(const float& f)
		{
			Vector3 result;
			result.x = this->x * f;
			result.y = this->y * f;
			result.z = this->z * f;
			return result;
		}

		Vector3* operator=(const Vector3& v)
		{
			this->x = v.x;
			this->y = v.y;
			this->z = v.z;
			return this;
		}

		float operator[](int index)
		{
			if (index == 0)
				return this->x;
			else if (index == 1)
				return this->y;
			else
				return this->z;
		}

		bool operator==(const Vector3& v)
		{
			return this->x == v.x && this->y == v.y && this->z == v.z;
		}

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

	private:

	};

	class Vector4
	{
	public:

		Vector4()
			: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
		{
		}

		Vector4(float in_x, float in_y, float in_z, float in_w)
			: x(in_x), y(in_y), z(in_z), w(in_w)
		{
		}

		inline const float GetX() const { return x; }
		inline const float GetY() const { return y; }
		inline const float GetZ() const { return z; }
		inline const float GetW() const { return w; }

		inline const void SetX(float in_x) { x = in_x; }
		inline const void SetY(float in_y) { y = in_y; }
		inline const void SetZ(float in_z) { z = in_z; }
		inline const void SetW(float in_w) { w = in_w; }

		inline const void Print() const { BTR_INFO("Vector4 (X: {0}, Y: {1}, Z: {2}, W: {3})", x, y, z, w); }

	private:
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;
	};

	class Plane
	{
	public:
		Plane()
			: TL(Vector3()), TR(Vector3()), BL(Vector3()), BR(Vector3())
		{
		}

		Plane(Vector3 tl, Vector3 tr, Vector3 bl, Vector3 br)
			: TL(tl), TR(tr), BL(bl), BR(br)
		{
		}
		Vector3 TL, TR, BL, BR;

	};
}