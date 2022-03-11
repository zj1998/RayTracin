#pragma once
#include "vec.h"

void write_color(std::ostream &os, const color &c) {
	std::cout << static_cast<int>(255.999 * c.x()) << ' '
		<< static_cast<int>(255.999 * c.y()) << ' '
		<< static_cast<int>(255.999 * c.z()) << '\n';
}
