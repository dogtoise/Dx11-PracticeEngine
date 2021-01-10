#pragma once


class Values
{
public:
	const static float PI;
	const static float PI_TIMES_TWO;
	const static D3DXVECTOR3 ZeroVec3;
	const static D3DXVECTOR3 OneVec3;
	const static D3DXVECTOR3 LeftVec;
	const static D3DXVECTOR3 RightVec;
	const static D3DXVECTOR3 DownVec;
	const static D3DXVECTOR3 UpVec;
	const static D3DXVECTOR3 FwdVec;
	const static D3DXVECTOR3 ScreenSize;

	const static D3DXVECTOR2 ZeroVec2;
	const static D3DXVECTOR2 OneVec2;
	const static D3DXVECTOR2 UVLT; // left top
	const static D3DXVECTOR2 UVLB; // left bottom
	const static D3DXVECTOR2 UVRB; // right bottom
	const static D3DXVECTOR2 UVRT; // right top

	const static D3DXCOLOR Red;
	const static D3DXCOLOR Blue;
	const static D3DXCOLOR Green;
	const static D3DXCOLOR Magenta;
	const static D3DXCOLOR Black;
	const static D3DXCOLOR White;
	const static D3DXCOLOR ClearColor;

	const static D3DXMATRIX Identity;
};

class DxMath
{
public:
	// example : D3DXMATRIX m = DxMath::Translation(position)
	static D3DXMATRIX Translation(const D3DXVECTOR3& position)
	{
		D3DXMATRIX m;
		D3DXMatrixTranslation(&m, position.x, position.y, position.z);
		return m;
	}

	static D3DXMATRIX Translation(const float& x, const float& y, const float& z)
	{
		return Translation(D3DXVECTOR3(x, y, z));
	}
	static D3DXMATRIX TranslationX(const float& x)
	{
		return Translation(x, 0, 0);
	}
	static D3DXMATRIX TranslationY(const float& y)
	{
		return Translation(0, y, 0);
	}
	static D3DXMATRIX TranslationZ(const float& z)
	{
		return Translation(0, 0, z);
	}

	static D3DXMATRIX Scaling(const D3DXVECTOR3& size)
	{
		D3DXMATRIX m;
		D3DXMatrixScaling(&m, size.x, size.y, size.z);
		return m;
	}
	static D3DXMATRIX Scaling(const float& x, const float& y, const float& z)
	{
		return Scaling(D3DXVECTOR3(x, y, z));
	}
	static D3DXMATRIX ScalingX(const float& x)
	{
		return Scaling(x, 0, 0);
	}
	static D3DXMATRIX ScalingY(const float& y)
	{
		return Scaling(0, y, 0);
	}
	static D3DXMATRIX ScalingZ(const float& z)
	{
		return Scaling(0, 0, z);
	}


	static D3DXMATRIX RotationInDegree(const float& rotation)
	{
		D3DXMATRIX m;
		D3DXMatrixRotationZ(&m, (float)D3DXToRadian(rotation));
		return m;
	}

	static D3DXMATRIX RotationInRadian(const float& rotation)
	{
		D3DXMATRIX m;
		D3DXMatrixRotationZ(&m, rotation);
		return m;
	}

	// 결과값 : -180 ~ 180
	static float GetAngle(const D3DXVECTOR3& a, const D3DXVECTOR3& b)
	{
		float cosAngle = acosf(D3DXVec3Dot(&a, &b) / (D3DXVec3Length(&a) * D3DXVec3Length(&b)));
		cosAngle = D3DXToDegree(cosAngle);

		// 외적의 z성분으로 방향이 결정된다.
		float angle = (a.x * b.y - a.y * b.x > 0.0f) ? cosAngle : -cosAngle;
		return angle;
	}


	// Dot product of two D3DXVECTOR2's
	static float DotProduct(const D3DXVECTOR2 &a, const D3DXVECTOR2 &b)
	{
		return a.x*b.x + a.y*b.y;
	}

	// Dot product of two D3DXVECTOR3's
	static float DotProduct(const D3DXVECTOR3 &a, const D3DXVECTOR3 &b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}


	// Swap two D3DXVECTOR2's
	static void SwapVec(D3DXVECTOR2 &a, D3DXVECTOR2 &b)
	{
		D3DXVECTOR2 tmp(a);

		a = b;
		b = tmp;
	}

	// Swap two D3DXVECTOR3's
	static void SwapVec(D3DXVECTOR3 &a, D3DXVECTOR3 &b)
	{
		D3DXVECTOR3 tmp(a);

		a = b;
		b = tmp;
	}

	// Cross product of two D3DXVECTOR3's
	static D3DXVECTOR3 CrossProduct(const D3DXVECTOR3 &a, const D3DXVECTOR3 &b)
	{
		return D3DXVECTOR3(a.y*b.z - a.z*b.y,
			a.z*b.x - a.x*b.z,
			a.x*b.y - a.y*b.x);
	}

	// Are these two D3DXVECTOR2's nearly equal?
	static  bool NearlyEquals(const D3DXVECTOR2& a, const D3DXVECTOR2& b, float r)
	{
		D3DXVECTOR2 diff = a - b; // difference

		return (DotProduct(diff, diff) < r*r); // radius
	}

	// Are these two D3DXVECTOR3's nearly equal?
	static  bool NearlyEquals(const D3DXVECTOR3& a, const D3DXVECTOR3& b, float r)
	{
		D3DXVECTOR3 diff = a - b; // difference

		return (DotProduct(diff, diff) < r*r); // radius
	}

	static float Length(D3DXVECTOR3 vec)
	{
		return (float)sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}
	static float SqrMagnitude(D3DXVECTOR3 vec)
	{
		return Length(vec) * Length(vec);
	}
	static D3DXVECTOR3 Normalize(D3DXVECTOR3 vec)
	{
		float m = Length(vec);

		if (m > 0.0f)
			m = 1.0f / m;
		else
			m = 0.0f;
		vec.x *= m;
		vec.y *= m;
		vec.z *= m;

		return vec;
	}
	static D3DXVECTOR3 SetMagnitudeOfVector(D3DXVECTOR3 vec, float velocity)
	{

		D3DXVECTOR3 norm = Normalize(vec);
		norm.x *= velocity;
		norm.y *= velocity;
		norm.z *= velocity;

		return norm;
	}
	// get angle between two vectors
	static float GetAngleBetween(D3DXVECTOR3 vec1, D3DXVECTOR3 vec2)
	{
		float mag1 = Length(vec1);
		float mag2 = Length(vec2);
		float dotProduct = DotProduct(vec1, vec2);

		return (float)(acos(dotProduct / (mag1 * mag2)));
	}

	static float GetDist(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
	{
		D3DXVECTOR3 temp = pos1 - pos2;
		return std::abs(Length(temp));
	}
	static  D3DXVECTOR3 GetDirection(D3DXVECTOR3 vec)
	{
		return Normalize(vec);
	}

	// old
	/*static float Lerp(float value1, float value2, float amount)
	{
		return float(value1 + ((float)(value2 - value1) * amount));
	}*/
	static float Lerp(float a, float b, float lerpFactor)
	{
		float result = ((1.f - lerpFactor) * a) + (lerpFactor * b);
		return result;
	}
	static float LerpDegrees(float a, float b, float lerpFactor) // Lerps from angle a to b (both between 0.f and 360.f), taking the shortest path
	{
		float result;
		float diff = b - a;
		if (diff < -180.f)
		{
			// lerp upwards past 360
			b += 360.f;
			result = Lerp(a, b, lerpFactor);
			if (result >= 360.f)
			{
				result -= 360.f;
			}
		}
		else if (diff > 180.f)
		{
			// lerp downwards past 0
			b -= 360.f;
			result = Lerp(a, b, lerpFactor);
			if (result < 0.f)
			{
				result += 360.f;
			}
		}
		else
		{
			// straight lerp
			result = Lerp(a, b, lerpFactor);
		}

		return result;
	}

	static float LerpRadians(float a, float b, float lerpFactor) // Lerps from angle a to b (both between 0.f and PI_TIMES_TWO), taking the shortest path
	{
		float result;
		float diff = b - a;
		if (diff < -Values::PI)
		{
			// lerp upwards past PI_TIMES_TWO
			b += Values::PI_TIMES_TWO;
			result = Lerp(a, b, lerpFactor);
			if (result >= Values::PI_TIMES_TWO)
			{
				result -= Values::PI_TIMES_TWO;
			}
		}
		else if (diff > Values::PI)
		{
			// lerp downwards past 0
			b -= Values::PI_TIMES_TWO;
			result = Lerp(a, b, lerpFactor);
			if (result < 0.f)
			{
				result += Values::PI_TIMES_TWO;
			}
		}
		else
		{
			// straight lerp
			result = Lerp(a, b, lerpFactor);
		}

		return result;
	}
	static float ReliableRandom(float min, float max)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> distr(min, max);
		return distr(gen);
	}
};

