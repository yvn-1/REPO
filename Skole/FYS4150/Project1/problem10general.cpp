#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <chrono>

long double f(long double x) {return 100.0L * std::expl(-10L*x);};

void solve(int N) {
	int n = N-1;
	std::vector<long double> a(n,-1.0L);
	std::vector<long double> c(n,-1.0L);
	std::vector<long double> b(n, 2.0L);
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

	auto t1 = std::chrono::high_resolution_clock::now();
	u[0]=0;
	for (int i = 1; i<n; i++) {
		long double m = a[i]/b[i-1];
		b[i] = b[i] - m*c[i];
		u[i] = u[i] - m*u[i-1];
	};
	v[n-1] = u[n-1] / b[n-1];
	for (int i = n-2; i >= 0; i--) {
		v[i] = (u[i]-c[i]*v[i+1])/b[i];
	};
	auto t2 = std::chrono::high_resolution_clock::now();
	double timing = std::chrono::duration<double>(t2-t1).count();

	std::string filename = "problem10general"+std::to_string(N)+".txt";
	std::ofstream file(filename, std::ios::app);
	file << std::scientific << std::setprecision(32);

	file << timing << std::endl;
	file.close();
};

int main() {

	for (int i = 0; i<10; i++) {
		solve(10);
		solve(100);
		solve(1000);
		solve(10000);
		solve(100000);
		solve(1000000);
		solve(10000000);
	};
}

