#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

float a = -1.0f;
float c = -1.0f;
int N;
int n = N-1;
std::vector<float> b(n, 2.0f);

float h = 1.0f/N;

float x[N];
for (int i = 0; i<N;i++) {
	x[i] = i*h;
};

float f(x) {
	return std::exp(-10*x)
};

std::vector<float> u;

for (e: x) {
	u.push_back(f(e));
};
