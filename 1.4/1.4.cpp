//1.4.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "RealMatrix.h"

using namespace std;

//class RealMatrix {
//private:
//	int rows;
//	int cols;
//	double** arr;
//public:
//	int getRows() { return rows; }
//	int getCols() { return cols; }
//	void setRows(int r) { r = rows; }
//	void setCols(int c) { c = cols; }
//
//	void Init(int rows, int cols) {
//		this->rows = rows;
//		this->cols = cols;
//		arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				arr[i][j] = double(rand() % 100) / 10;
//			}
//		}
//	}
//	void Read() {
//
//		cout << "Enter the number of rows: ";cin >> rows;
//		cout << "Enter the number of columns: ";cin >> cols;
//		arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			arr[i] = new double[cols];
//		}
//		cout << "Enter elements of matrix: " << endl;
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//	}
//	void Display() {
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	string toString() {
//		string result = "";
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result += to_string(arr[i][j]) + " ";
//			}
//			result += "\n";
//		}
//	}
//	RealMatrix operator+(RealMatrix matrix) {
//		if (this->rows != matrix.rows && this->cols != matrix.cols) {
//			cout << "Error" << endl;
//			return RealMatrix();
//		}
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] + matrix.arr[i][j];
//			}
//		}
//		return result;
//	}
//	RealMatrix operator-(RealMatrix matrix) {
//		if (this->rows != matrix.rows && this->cols != matrix.cols) {
//			cout << "Error" << endl;
//			return RealMatrix();
//		}
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] - matrix.arr[i][j];
//			}
//		}
//		return result;
//	}
//	RealMatrix operator*(RealMatrix matrix) {
//		if (this->cols != matrix.rows) {
//			cout << "Error" << endl;
//			return RealMatrix();
//		}
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = matrix.cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[matrix.cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < matrix.cols;j++) {
//				result.arr[i][j] = 0;
//				for (int k = 0;k < cols;k++) {
//					result.arr[i][j] += arr[i][k] * matrix.arr[k][j];
//				}
//			}
//		}
//		return result;
//	}
//	RealMatrix operator/(RealMatrix matrix) {
//		if (this->rows != matrix.rows && this->cols != matrix.cols) {
//			cout << "Error" << endl;
//			return RealMatrix();
//		}
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] / matrix.arr[i][j];
//			}
//		}
//		return result;
//	}
//	RealMatrix operator+(double value) {
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] + value;
//			}
//		}
//		return result;
//	}
//	RealMatrix operator-(double value) {
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] - value;
//			}
//		}
//		return result;
//	}
//	RealMatrix operator*(double value) {
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] * value;
//			}
//		}
//		return result;
//	}
//	RealMatrix operator/(double value) {
//		RealMatrix result = RealMatrix();
//		result.rows = rows;
//		result.cols = cols;
//		result.arr = new double* [rows];
//		for (int i = 0;i < rows;i++) {
//			result.arr[i] = new double[cols];
//		}
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				result.arr[i][j] = arr[i][j] / value;
//			}
//		}
//		return result;
//	}
//	bool operator==(RealMatrix matrix) {
//		if (this->rows != matrix.rows && this->cols != matrix.cols) {
//			return false;
//		}
//		bool isEqual = true;
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				if (arr[i][j] != matrix.arr[i][j]) {
//					isEqual = false;
//					break;
//				}
//			}
//		}
//		return isEqual;
//	}
//	bool operator!=(RealMatrix matrix) {
//		return!(*this == matrix);
//	}
//	bool isSquare() {
//		return cols == rows;
//	}
//	bool isSymetric() {
//		if (isSquare()) {
//			for (int i = 0;i < rows;i++) {
//				for (int j = 0;j < cols;j++) {
//					if (arr[i][j] != arr[j][i]) {
//						return false;
//					}
//				}
//			}
//			return true;
//		}
//		return false;
//	}
//	bool isDiagonal() {
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				if (arr[i][j] != 0 && i != j) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//	bool isZero() {
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				if (arr[i][j] != 0) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//	bool isOne() {
//		for (int i = 0;i < rows;i++) {
//			for (int j = 0;j < cols;j++) {
//				if (arr[i][j] != 0 && i != j) {
//					return false;
//				}
//				if (arr[i][j] == 1 && i == j) {
//					return false;
//				}
//			}
//		}
//		return true;
//	}
//	bool isTopTriangle() {
//		if (isSquare()) {
//			for (int i = 0;i < rows;i++) {
//				for (int j = 0;j < i;j++) {
//					if (arr[i][j] != 0) {
//						return false;
//					}
//				}
//			}
//			return true;
//		}
//		return false;
//	}
//	bool isBottomTriangle() {
//		if (isSquare()) {
//			for (int i = 0;i < rows;i++) {
//				for (int j = i + 1;j < cols;j++) {
//					if (arr[i][j] != 0) {
//						return false;
//					}
//				}
//			}
//			return true;
//		}
//		return false;
//	}
//	friend ostream& operator<<(ostream& out, RealMatrix matrix);
//	friend istream& operator>>(istream& in, RealMatrix matrix);
//};
//ostream& operator<<(ostream& out, RealMatrix matrix) {
//	for (int i = 0;i < matrix.rows;i++) {
//		for (int j = 0;j < matrix.cols;j++) {
//			out << matrix.arr[i][j] << " ";
//		}
//		out << endl;
//	}
//	return out;
//}
//istream& operator>>(istream& in, RealMatrix matrix) {
//	cout << "Enter the number of rows: ";in >> matrix.rows;
//	cout << "Enter the number of columns: ";in >> matrix.cols;
//	matrix.arr = new double* [matrix.rows];
//	for (int i = 0;i < matrix.rows;i++) {
//		matrix.arr[i] = new double[matrix.cols];
//	}
//	cout << "Enter elements of matrix: " << endl;
//	for (int i = 0;i < matrix.rows;i++) {
//		for (int j = 0;j < matrix.cols;j++) {
//			in >> matrix.arr[i][j];
//		}
//	}
//	return in;
//}

int main()
{
	srand(time(nullptr));

	int choice;
	do {
		cout << "Menu:" << endl;
		cout << "1. Initialize and display first matrix" << endl;
		cout << "2. Check properties of first matrix" << endl;

		cout << "3. Initialize and display second matrix" << endl;

		cout << "4. Add matrices" << endl;
		cout << "5. Subtract matrices" << endl;
		cout << "6. Multiply matrices" << endl;
		cout << "7. Divide matrices" << endl;

		cout << "8. Enter a value" << endl;
		cout << "9. Add a value" << endl;
		cout << "10. Subtract a value" << endl;
		cout << "11. Multiply by a value" << endl;
		cout << "12. Divide by a value" << endl;

		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		int rows, cols;
		int rows2, cols2;
		double value;
		RealMatrix matrix, matrix2, result;
		switch (choice) {
		case 1:
			int rows, cols;
			cout << "Enter the number of rows: ";
			cin >> rows;

			cout << "Enter the number of columns: ";
			cin >> cols;
			RealMatrix matrix;
			matrix.Init(rows, cols);
			cout << "Initialized first matrix:" << endl;
			matrix.Display();
			break;
		case 2:
			cout << "Number of rows: " << matrix.getRows() << endl;
			cout << "Number of columns: " << matrix.getCols() << endl;
			cout << "Is square: " << (matrix.isSquare() ? "Yes" : "No") << endl;
			cout << "Is diagonal: " << (matrix.isDiagonal() ? "Yes" : "No") << endl;
			cout << "Is symmetric: " << (matrix.isSymetric() ? "Yes" : "No") << endl;
			cout << "Is zero: " << (matrix.isZero() ? "Yes" : "No") << endl;
			cout << "Is one: " << (matrix.isOne() ? "Yes" : "No") << endl;
			cout << "Is top triangle: " << (matrix.isTopTriangle() ? "Yes" : "No") << endl;
			cout << "Is bottom triangle: " << (matrix.isBottomTriangle() ? "Yes" : "No") << endl;
			break;
		case 3:
			int rows2, cols2;
			cout << "Enter the number of rows (second matrix): ";
			cin >> rows2;

			cout << "Enter the number of columns (second matrix): ";
			cin >> cols2;
			RealMatrix matrix2;
			matrix2.Init(rows2, cols2);
			cout << "Initialized second matrix:" << endl;
			matrix2.Display();
			break;
		case 4:
			result = matrix + matrix2;
			cout << "Addition result:" << endl;
			result.Display();
			break;
		case 5:
			result = matrix - matrix2;
			cout << "Subtraction result:" << endl;
			result.Display();
			break;
		case 6:
			result = matrix * matrix2;
			cout << "Multiplication result:" << endl;
			result.Display();
			break;
		case 7:
			result = matrix / matrix2;
			cout << "Division result:" << endl;
			result.Display();
			break;

		case 8:
			double value;
			cout << "Enter values: ";cin >> value;
			break;
		case 9:
			result = matrix + value;
			cout << "Addition with scalar result:" << endl;
			result.Display();
			break;
		case 10:
			result = matrix - value;
			cout << "Subtraction with scalar result:" << endl;
			result.Display();
			break;
		case 11:
			result = matrix * value;
			cout << "Multiplication by scalar result:" << endl;
			result.Display();
			break;
		case 12:
			result = matrix / value;
			cout << "Division by scalar result:" << endl;
			result.Display();
			break;
		case 0:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}

