#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

float f(float x) {return 100 * std::expf(-10*x);};

int main() {
	float a = -1.0f;
	float c = -1.0f;
	int N = 1000;
	int n = N-1;
	std::vector<float> b(n, 2.0f);
	std::vector<float> v(n);

	float h = 1.0f/N;
	
	std::vector<float> x(n);
	x[0] = 0;
	for (int i = 1; i<n;i++) {
		x[i] = i*h;
	};

	std::vector<float> u(n);

	for (int i = 0; i < n; i++) {
		u[i] = h*h*f(x[i]);
	};

	for (int i = 1; i<n; i++) {
		float m = a/b[i-1];
		b[i] = b[i] - m*c;
		u[i] = u[i] - m*u[i-1];
	};
	v[0] = 0;
	v[n-1] = u[n-1] / b[n-1];
	for (int i = n-2; i >= 0; i--) {
		v[i] = (u[i]-c*v[i+1])/b[i];
	};
	
	std::ofstream file("problem7.txt");
	for (int i = 0; i < n; i++) {
		file << x[i] << "," << v[i] <<std::endl;
	};
	file.close();

	return 0;
}

