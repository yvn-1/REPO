#include <fstream>
#include <vector>

int main() {
std::vector<float> xvector;
std::vector<float> uxvector;

double x = 0.0;
do {
	xvector.push_back(x);
	x = x + 0.1;
} while (x<10);

for (auto e: xvector) {
	uxvector.push_back(e);
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
