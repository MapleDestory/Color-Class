#include <stdio.h>

#include <iostream>

#include "color.h"


auto main() -> int
{
	Color4 Color = 0xAABBCCFF;

	printf("Full: 0x%p\n", Color.RGBA());

	/*Color = Color4::F(1.0f, 0.5f, 0.6f, 1.0f);
	Color = Color4::I(255, 255, 255, 255);

	Color -= Color4::I(100, 100, 100, 100);
	

	printf("R: 0x%p\n", Color.R);
	printf("G: 0x%p\n", Color.G);
	printf("B: 0x%p\n", Color.B);
	printf("A: 0x%p\n", Color.A);

	

	printf("\n\n");

	Color += 0x50000000;

	printf("R: %i\n", Color.R);
	printf("G: %i\n", Color.G);
	printf("B: %i\n", Color.B);
	printf("A: %i\n", Color.A);

	printf("\n\n");

	uc32_t color_i = Color;
	printf("0x%p\n", color_i);

	float* color_f = Color;
	printf("R: %f\n", color_f[0]);
	printf("G: %f\n", color_f[1]);
	printf("B: %f\n", color_f[2]);
	printf("A: %f\n", color_f[3]);*/

	std::cin.get();

	return -1;
}