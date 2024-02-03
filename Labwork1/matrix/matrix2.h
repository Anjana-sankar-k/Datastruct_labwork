#include<iostream>
using namespace std;

class Matrix {
private:
    int** matrix;
    int rows, cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix = new int*[rows];
        for(int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Overloaded >> operator for input
    friend istream& operator>>(istream& in, Matrix& mat) {
        cout << "Enter the matrix elements:" << endl;
        for(int i = 0; i < mat.rows; ++i) {
            for(int j = 0; j < mat.cols; ++j) {
                cout << "Enter the element at position (" << i << "," << j << "): ";
                in >> mat.matrix[i][j];
            }
        }
        return in;
    }

    // Overloaded << operator for output
    friend ostream& operator<<(ostream& out, const Matrix& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for(int j = 0; j < mat.cols; ++j) {
                out << mat.matrix[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols) {
            throw invalid_argument("Matrix dimensions do not match for addition");
        }

        Matrix result(m1.rows, m1.cols);

        for (int i = 0; i < m1.rows; ++i) {
            for (int j = 0; j < m1.cols; ++j) {
                result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }

        return result;
    }

    friend Matrix operator-(const Matrix& m1, const Matrix& m2) {
        if (m1.rows != m2.rows || m1.cols != m2.cols) {
            throw invalid_argument("Matrix dimensions do not match for subtraction");
        }

        Matrix result(m1.rows, m1.cols);

        for (int i = 0; i < m1.rows; ++i) {
            for (int j = 0; j < m1.cols; ++j) {
                result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
            }
        }

        return result;
    }

    friend Matrix operator*(const Matrix& m1, const Matrix& m2) {
        if (m1.cols != m2.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication");
        }

        Matrix result(m1.rows, m2.cols);

        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < m1.cols; k++) {
                    result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }

        return result;
    }
};

