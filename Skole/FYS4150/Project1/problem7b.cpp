#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

long double f(long double x) {return 100.0L * std::expl(-10L*x);};

void solve(int N) {
	long double a = -1.0f;
	long double c = -1.0f;
	int n = N-1;
	std::vector<long double> b(n, 2.0f);
	std::vector<long double> v(n);

	long double h = 1.0f/N;
	
	std::vector<long double> x(n);
	x[0] = 0;
	for (int i = 0; i<n;i++) {
		x[i] = (i+1)*h;
	};

	std::vector<long double> u(n);

	for (int i = 0; i < n; i++) {
		u[i] = h*h*f(x[i]);
	};

	for (int i = 1; i<n; i++) {
		long double m = a/b[i-1];
		b[i] = b[i] - m*c;
		u[i] = u[i] - m*u[i-1];
	};
	v[0] = 0;
	v[n-1] = u[n-1] / b[n-1];
	for (int i = n-2; i >= 0; i--) {
		v[i] = (u[i]-c*v[i+1])/b[i];
	};
	std::string filename = "problem7"+std::to_string(N)+".txt";
	std::ofstream file(filename);
	for (int i = 0; i < n; i++) {
		file << x[i] << "," << v[i] <<std::endl;
	};
	file.close();
};

int main() {
	solve(10);
	solve(100);
	solve(1000);
	solve(10000);
	solve(100000);
}

