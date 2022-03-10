# include<iostream>
using namespace std;
int main() {
	const int  pic_width = 256;
	const int pic_height = 256;

	cout << "P3\n" << pic_width << " " << pic_height << "\n255\n";

	for (int i = 0; i < pic_width; ++i) {
		for (int j = 0; j < pic_height; ++j) {
			auto r = double(i) / (pic_width-1);
			auto g = double(j) /(pic_height-1);
			auto b = 0.0;
			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';

		}
	}





}
