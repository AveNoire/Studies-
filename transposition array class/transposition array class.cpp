#include <iostream>
#include <vector>
#include <cstdlib>

class Matrix {
private:
	int rows;
	int cols;
	std::vector<std::vector<int>> data;
public:
	void setMatrix(int rowValue, int colValue) {
		rows = rowValue;
		cols = colValue;
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		data.resize(rowValue, std::vector<int>(colValue));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				data[i][j] = std::rand() % 100;
			}
		}
	}
	void printMatrix() {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				std::cout << data[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
	void transpositionMatrix() {
		std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				transposed[j][i] = data[i][j];
			}
		}

		data = std::move(transposed);
		std::swap(rows, cols);

	}
};

int main()
{
	Matrix arr;
	arr.setMatrix(2, 3);
	arr.printMatrix();
	std::cout << std::endl;
	arr.transpositionMatrix();
	arr.printMatrix();
	return 0;
}

