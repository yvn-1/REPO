#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main() {
//Initialize vectors for x and u(x)
std::vector<float> xvector;
std::vector<float> uxvector;

//Initialize x to populate x vector
double x = 0;
do {
	xvector.push_back(x);
	x = x + 0.01;
} while (x<1.01);

//Populate u(x) vector using each of the values in x vector
for (auto e: xvector) {
	float val = 1.0-(1.0-std::exp(-10.0))*e-std::exp(-10.0*e);
	uxvector.push_back(val);
}

//Open a file for the output and specify scientific notation with three decimals
std::ofstream outputFile("problem2.txt");
outputFile << std::scientific << std::setprecision(3);

//Check that output file is open, then that the vectors are the same size (one to one relation), 
//and then write to file with the format x,u(x) in each row
if (outputFile.is_open()) {
	if (xvector.size() == uxvector.size()) {
		for (size_t i=0; i<xvector.size();i++) {
			outputFile << xvector[i] << "," << uxvector[i] << std::endl;
		}
	};
};

//Close the file and end program
outputFile.close();

return 0;
}
