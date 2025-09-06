#include <fstream>
#include <vector>
#include <cmath>

int main() {
std::vector<float> xvector;
std::vector<float> uxvector;

double x = 0.00001;
do {
	xvector.push_back(x);
	x = x + 0.1;
} while (x<10);

for (auto e: xvector) {
	float val = 1.0-(1.0-std::exp(-10.0))*e-std::exp(-10.0*e);
	uxvector.push_back(val);
}

std::ofstream outputFile("problem2.txt");

if (outputFile.is_open()) {
	if (xvector.size() == uxvector.size()) {
		for (size_t i=0; i<xvector.size();i++) {
			outputFile << xvector[i] << "," << uxvector[i] << std::endl;
		}
	};
};

outputFile.close();

return 0;
}
