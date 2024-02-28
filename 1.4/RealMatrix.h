//RealMatrix.h
#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
class RealMatrix {
private:
    int rows;
    int cols;
    double** arr;
public:
    int getRows();
    int getCols();
    void setRows(int r);
    void setCols(int c);

    void Init(int rows, int cols);
    void Read();
    void Display();
    string toString();

    RealMatrix operator+(RealMatrix matrix);
    RealMatrix operator-(RealMatrix matrix);
    RealMatrix operator*(RealMatrix matrix);
    RealMatrix operator/(RealMatrix matrix);
    RealMatrix operator+(double value);
    RealMatrix operator-(double value);
    RealMatrix operator*(double value);
    RealMatrix operator/(double value);
    bool operator==(RealMatrix matrix);
    bool operator!=(RealMatrix matrix);

    bool isSquare();
    bool isSymetric();
    bool isDiagonal();
    bool isZero();
    bool isOne();
    bool isTopTriangle();
    bool isBottomTriangle();

    friend ostream& operator<<(std::ostream& out, const RealMatrix matrix);
    friend istream& operator>>(std::istream& in, RealMatrix matrix);
};

