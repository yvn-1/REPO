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
	u[0]=0;
	for (int i = 1; i<n; i++) {
		long double m = a/b[i-1];
		b[i] = b[i] - m*c;
		u[i] = u[i] - m*u[i-1];
	};
	v[n-1] = u[n-1] / b[n-1];
	for (int i = n-2; i >= 0; i--) {
		v[i] = (u[i]-c*v[i+1])/b[i];
	};
	std::vector<long double> exact;
	for (auto e: x) {
		double long val = 1-(1-std::expl(-10.0L))*e-std::expl(-10*e);
		exact.push_back(val);
	};
	std::vector<double long> error;
	long double max_error = 0;
	for (int i =0; i< size(exact);i++) {
		double long err = std::log10l(std::abs((exact[i]-v[i])/exact[i]));
		if (err>max_error) {
			max_error = err;
		};
		error.push_back(err);
	};
	

	std::string filename = "problem8c"+std::to_string(N)+".txt";
	std::ofstream file(filename);
	file << std::scientific << std::setprecision(32);
	file << max_error << std::endl;
	file.close();
};

int main() {
	solve(10);
	solve(100);
	solve(1000);
	solve(10000);
	solve(100000);
	solve(1000000);
	solve(10000000);
}

