#ifndef __COLOR_H__
#define __COLOR_H__

typedef unsigned char		uc8_t;
typedef unsigned short		uc16_t;
typedef unsigned int		uc32_t;
typedef unsigned long long	uc64_t;

typedef unsigned long		ucl_t;
typedef unsigned long long	ucll_t;

#if defined _WIN64
typedef unsigned long long	ucl_ptr;
#else
typedef unsigned long		ucl_ptr;
#endif

class Color4
{
public:
	
public:
	uc8_t R, G, B, A;
public:
	Color4()
		: R(0), G(0), B(0), A(0)
	{}

	~Color4()
	{
		R = 0;
		G = 0;
		B = 0;
		A = 0;
	}

	Color4(uc32_t Color)
	{
		B = static_cast<uc8_t>(Color >> 0x00);
		G = static_cast<uc8_t>(Color >> 0x08);
		R = static_cast<uc8_t>(Color >> 0x10);
		A = static_cast<uc8_t>(Color >> 0x18);
	}

	Color4(float* Color)
	{
		R = static_cast<uc8_t>(Color[0] * 255.0f);
		G = static_cast<uc8_t>(Color[1] * 255.0f);
		B = static_cast<uc8_t>(Color[2] * 255.0f);
		A = static_cast<uc8_t>(Color[3] * 255.0f);
	}

	Color4(uc8_t InR, uc8_t InG, uc8_t InB, uc8_t InA)
		: R(InR), G(InG), B(InB), A(InA)
	{}
public:
	uc32_t ABGR()
	{
		return static_cast<uc32_t>(
			(((A) & 0xFF) << 0x18) |
			(((B) & 0xFF) << 0x00) |
			(((G) & 0xFF) << 0x08) |
			(((R) & 0xFF) << 0x10));
	}
	uc32_t RGBA()
	{
		return static_cast<uc32_t>(
			(((A) & 0xFF) << 0x18) |
			(((R) & 0xFF) << 0x10) |
			(((G) & 0xFF) << 0x08) |
			(((B) & 0xFF) << 0x00));
	}
public:
	static Color4 I(uc8_t InR, uc8_t InG, uc8_t InB, uc8_t InA)
	{
		Color4 Color;
		Color.R = InR;
		Color.G = InG;
		Color.B = InB;
		Color.A = InA;
		return Color;
	}

	static Color4 F(float InR, float InG, float InB, float InA)
	{
		Color4 Color;
		Color.R = static_cast<uc8_t>(InR * 255.0f);
		Color.G = static_cast<uc8_t>(InG * 255.0f);
		Color.B = static_cast<uc8_t>(InB * 255.0f);
		Color.A = static_cast<uc8_t>(InA * 255.0f);
		return Color;
	}
public:
	Color4 operator + (const Color4& Color)
	{
		return Color4(R + Color.R, G + Color.G, B + Color.B, A + Color.A);
	}
	Color4 operator - (const Color4& Color)
	{
		return Color4(R - Color.R, G - Color.G, B - Color.B, A - Color.A);
	}
	Color4 operator * (const Color4& Color)
	{
		return Color4(R * Color.R, G * Color.G, B * Color.B, A * Color.A);
	}
	Color4 operator / (const Color4& Color)
	{
		return Color4(R / Color.R, G / Color.G, B / Color.B, A / Color.A);
	}

	Color4 operator += (const Color4& Color)
	{
		return Color4(R += Color.R, G += Color.G, B += Color.B, A += Color.A);
	}
	Color4 operator -= (const Color4& Color)
	{
		return Color4(R -= Color.R, G -= Color.G, B -= Color.B, A -= Color.A);
	}
	Color4 operator *= (const Color4& Color)
	{
		return Color4(R *= Color.R, G *= Color.G, B *= Color.B, A *= Color.A);
	}
	Color4 operator /= (const Color4& Color)
	{
		return Color4(R /= Color.R, G /= Color.G, B /= Color.B, A /= Color.A);
	}

	Color4 operator + (const uc32_t& Color)
	{
		return Color4(
			R + static_cast<uc8_t>(Color >> 0x10), 
			G + static_cast<uc8_t>(Color >> 0x08), 
			B + static_cast<uc8_t>(Color >> 0x00), 
			A + static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator - (const uc32_t& Color)
	{
		return Color4(
			R - static_cast<uc8_t>(Color >> 0x10),
			G - static_cast<uc8_t>(Color >> 0x08),
			B - static_cast<uc8_t>(Color >> 0x00),
			A - static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator * (const uc32_t& Color)
	{
		return Color4(
			R * static_cast<uc8_t>(Color >> 0x10),
			G * static_cast<uc8_t>(Color >> 0x08),
			B * static_cast<uc8_t>(Color >> 0x00),
			A * static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator / (const uc32_t& Color)
	{
		return Color4(
			R / static_cast<uc8_t>(Color >> 0x10),
			G / static_cast<uc8_t>(Color >> 0x08),
			B / static_cast<uc8_t>(Color >> 0x00),
			A / static_cast<uc8_t>(Color >> 0x18));
	}

	Color4 operator += (const uc32_t& Color)
	{
		return Color4(
			R += static_cast<uc8_t>(Color >> 0x10),
			G += static_cast<uc8_t>(Color >> 0x08),
			B += static_cast<uc8_t>(Color >> 0x00),
			A += static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator -= (const uc32_t& Color)
	{
		return Color4(
			R -= static_cast<uc8_t>(Color >> 0x10),
			G -= static_cast<uc8_t>(Color >> 0x08),
			B -= static_cast<uc8_t>(Color >> 0x00),
			A -= static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator *= (const uc32_t& Color)
	{
		return Color4(
			R *= static_cast<uc8_t>(Color >> 0x10),
			G *= static_cast<uc8_t>(Color >> 0x08),
			B *= static_cast<uc8_t>(Color >> 0x00),
			A *= static_cast<uc8_t>(Color >> 0x18));
	}
	Color4 operator /= (const uc32_t& Color)
	{
		return Color4(
			R /= static_cast<uc8_t>(Color >> 0x10),
			G /= static_cast<uc8_t>(Color >> 0x08),
			B /= static_cast<uc8_t>(Color >> 0x00),
			A /= static_cast<uc8_t>(Color >> 0x18));
	}

public:
	operator uc32_t()
	{
		return static_cast<uc32_t>(
			(((A) & 0xFF) << 0x18) | 
			(((R) & 0xFF) << 0x10) | 
			(((G) & 0xFF) << 0x08) | 
			(((B) & 0xFF) << 0x00));
	}

	operator ucl_t()
	{
		return static_cast<ucl_t>(
			(((A) & 0xFF) << 0x18) |
			(((R) & 0xFF) << 0x10) |
			(((G) & 0xFF) << 0x08) |
			(((B) & 0xFF) << 0x00));
	}

	operator void*()
	{
		return reinterpret_cast<void*>(
			(((A) & 0xFF) << 0x18) |
			(((R) & 0xFF) << 0x10) |
			(((G) & 0xFF) << 0x08) |
			(((B) & 0xFF) << 0x00));
	}

	operator float*()
	{
		float* fColor = new float[4];
		fColor[0] = static_cast<float>(R / 255.0f);
		fColor[1] = static_cast<float>(G / 255.0f);
		fColor[2] = static_cast<float>(B / 255.0f);
		fColor[3] = static_cast<float>(A / 255.0f);
		return fColor;
	}
};

#endif