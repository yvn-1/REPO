#include <fstream>
#include <vector>

vector<float> xvector;
vector<float> uxvector;

double x = 0;
do {
	xvector.push_back(x);
	x = x + 0.1
} while {x<10};

for (x: xvector) {
	uxvector.push_back(x);
}

std::ofstream outputFile("problem2.txt");

if (outputFile.is_open()) {
	if (size_of(xvector) == size_of(uxvector)) {
		for (i=0; i<size_of(xvector);i++) {
			outputFile << xvector[i] + "," + uxvector << std::endl;
		}
	};
};

outputFile.close();
