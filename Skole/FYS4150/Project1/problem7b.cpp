#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>

long double f(long double x) {return 100.0L * std::expl(-10.0L*x);};

void solve(int N) {
	long double a = -1.0L;
	long double c = -1.0L;
	int n = N-1;
	std::vector<long double> b(n, 2.0L);
	std::vector<long double> v(n);

	long double h = 1.0L/N;
	
	std::vector<long double> x(n);
	for (int i = 0; i<n;i++) {
		x[i] = i*h;
	};

	std::vector<long double> u(n);
	
	//Fill g values
	for (int i = 0; i < n; i++) {
		u[i] = h*h*f(x[i]);
	};
	

	//Implements the algorithm as stated in the answer sheet
	for (int i = 1; i<n; i++) {
		long double m = a/b[i-1];
		b[i] = b[i] - m*c;
		u[i] = u[i] - m*u[i-1];
	};
	v[0] = 0;
	v[n-1] = u[n-1] / b[n-1];
	for (int i = n-2; i > 0; i--) {
		v[i] = (u[i]-c*v[i+1])/b[i];
	};

	//Writes to txt to be read in python
	std::string filename = "problem7"+std::to_string(N)+".txt";
	std::ofstream file(filename);
	file << std::scientific << std::setprecision(32);
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

