//RealMatrix.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "RealMatrix.h"

using namespace std;


int RealMatrix::getRows() { return rows; }
int RealMatrix::getCols() { return cols; }
void RealMatrix::setRows(int r) { r = rows; }
void RealMatrix::setCols(int c) { c = cols; }

void RealMatrix::Init(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;
	arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			arr[i][j] = double(rand() % 100) / 10;
		}
	}
}
void RealMatrix::Read() {

	cout << "Enter the number of rows: ";cin >> rows;
	cout << "Enter the number of columns: ";cin >> cols;
	arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		arr[i] = new double[cols];
	}
	cout << "Enter elements of matrix: " << endl;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			cin >> arr[i][j];
		}
	}

}
void RealMatrix::Display() {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
string RealMatrix::toString() {
	string result = "";
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result += to_string(arr[i][j]) + " ";
		}
		result += "\n";
	}
	return result;
}
RealMatrix RealMatrix::operator+(RealMatrix matrix) {
	if (this->rows != matrix.rows && this->cols != matrix.cols) {
		cout << "Error" << endl;
		return RealMatrix();
	}
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] + matrix.arr[i][j];
		}
	}
	return result;
}
RealMatrix RealMatrix::operator-(RealMatrix matrix) {
	if (this->rows != matrix.rows && this->cols != matrix.cols) {
		cout << "Error" << endl;
		return RealMatrix();
	}
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] - matrix.arr[i][j];
		}
	}
	return result;
}
RealMatrix RealMatrix::operator*(RealMatrix matrix) {
	if (this->cols != matrix.rows) {
		cout << "Error" << endl;
		return RealMatrix();
	}
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = matrix.cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[matrix.cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < matrix.cols;j++) {
			result.arr[i][j] = 0;
			for (int k = 0;k < cols;k++) {
				result.arr[i][j] += arr[i][k] * matrix.arr[k][j];
			}
		}
	}
	return result;
}
RealMatrix RealMatrix::operator/(RealMatrix matrix) {
	if (this->rows != matrix.rows && this->cols != matrix.cols) {
		cout << "Error" << endl;
		return RealMatrix();
	}
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] / matrix.arr[i][j];
		}
	}
	return result;
}
RealMatrix RealMatrix::operator+(double value) {
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] + value;
		}
	}
	return result;
}
RealMatrix RealMatrix::operator-(double value) {
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] - value;
		}
	}
	return result;
}
RealMatrix RealMatrix::operator*(double value) {
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] * value;
		}
	}
	return result;
}
RealMatrix RealMatrix::operator/(double value) {
	RealMatrix result = RealMatrix();
	result.rows = rows;
	result.cols = cols;
	result.arr = new double* [rows];
	for (int i = 0;i < rows;i++) {
		result.arr[i] = new double[cols];
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			result.arr[i][j] = arr[i][j] / value;
		}
	}
	return result;
}
bool RealMatrix::operator==(RealMatrix matrix) {
	if (this->rows != matrix.rows && this->cols != matrix.cols) {
		return false;
	}
	bool isEqual = true;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] != matrix.arr[i][j]) {
				isEqual = false;
				break;
			}
		}
	}
	return isEqual;
}
bool RealMatrix::operator!=(RealMatrix matrix) {
	return!(*this == matrix);
}
bool RealMatrix::isSquare() {
	return cols == rows;
}
bool RealMatrix::isSymetric() {
	if (isSquare()) {
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < cols;j++) {
				if (arr[i][j] != arr[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool RealMatrix::isDiagonal() {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] != 0 && i != j) {
				return false;
			}
		}
	}
	return true;
}
bool RealMatrix::isZero() {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
bool RealMatrix::isOne() {
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			if (arr[i][j] != 0 && i != j) {
				return false;
			}
			if (arr[i][j] == 1 && i == j) {
				return false;
			}
		}
	}
	return true;
}
bool RealMatrix::isTopTriangle() {
	if (isSquare()) {
		for (int i = 0;i < rows;i++) {
			for (int j = 0;j < i;j++) {
				if (arr[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
bool RealMatrix::isBottomTriangle() {
	if (isSquare()) {
		for (int i = 0;i < rows;i++) {
			for (int j = i + 1;j < cols;j++) {
				if (arr[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
	return false;
}
ostream& operator<<(ostream& out, const RealMatrix matrix) {
	for (int i = 0;i < matrix.rows;i++) {
		for (int j = 0;j < matrix.cols;j++) {
			out << matrix.arr[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
istream& operator>>(istream& in, RealMatrix matrix) {
	cout << "Enter the number of rows: ";in >> matrix.rows;
	cout << "Enter the number of columns: ";in >> matrix.cols;
	matrix.arr = new double* [matrix.rows];
	for (int i = 0;i < matrix.rows;i++) {
		matrix.arr[i] = new double[matrix.cols];
	}
	cout << "Enter elements of matrix: " << endl;
	for (int i = 0;i < matrix.rows;i++) {
		for (int j = 0;j < matrix.cols;j++) {
			in >> matrix.arr[i][j];
		}
	}
	return in;
}