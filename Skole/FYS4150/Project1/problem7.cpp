#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
int main() {
float a = -1.0f;
float c = -1.0f;
int N = 100;
int n = N-1;
std::vector<float> b(n, 2.0f);

float h = 1.0f/N;

vector<float> x(n);
for (int i = 0; i<n;i++) {
	x[i] = i*h;
};

float f(float x) {
	return std::expf(-10*x)
};

std::vector<float> u;

for (auto e: x) {
	u.push_back(f(e));
};

return 0;
}

