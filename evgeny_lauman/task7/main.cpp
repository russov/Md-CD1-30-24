#include "Figure.h"

int main()
{
	const int count_ptr = 3;
	const Sphere s_ptr[count_ptr]{ Sphere{1}, Sphere{2}, Sphere{3} };
	const Cylinder c_ptr[count_ptr]{ Cylinder{1,5}, Cylinder{2,10}, Cylinder{3,7} };
	const Pyramid p_ptr[count_ptr]{ Pyramid{23,5}, Pyramid{10,1}, Pyramid{5,5} };
	const Pointers<Sphere> sphere_ptr{ s_ptr, count_ptr };
	const Pointers<Cylinder> cylinder_ptr{ c_ptr, count_ptr };
	const Pointers<Pyramid> pyramid_ptr{ p_ptr, count_ptr };
	for (auto i = 0; i < count_ptr; i++)
	{
		sphere_ptr[i].printVolume();
		s_ptr[i].printVolume();
		cylinder_ptr[i].printVolume();
		c_ptr[i].printVolume();
		pyramid_ptr[i].printVolume();
		p_ptr[i].printVolume();
	}
}