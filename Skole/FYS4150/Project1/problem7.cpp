#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

float f(float x) {return std::expf(-10*x);};

int main() {
	float a = -1.0f;
	float c = -1.0f;
	int N = 100;
	int n = N-1;
	std::vector<float> b(n, 2.0f);
	std::vector<float> v(n);

	float h = 1.0f/N;

	std::vector<float> x(n);
	for (int i = 0; i<n;i++) {
		x[i] = (i+1)*h;
	};

	std::vector<float> u(n);

	for (int i = 0; i < n; i++) {
		u[i] = h*h*f(e));
	};

	for (int i = 1; i<n; i++) {
		m = a/b[i-1];
		b[i] = b[i] - m*c;
		g[i] = g[i] - m*g[i-1];
	};
	v[N]=0;
	for (int i = n; i > 1; i--) {
		v[i] = (g[i]-c*v[i+1])/b[i];
	};

	return 0;
}

