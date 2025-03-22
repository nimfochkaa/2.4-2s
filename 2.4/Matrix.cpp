#include "Matrix.h"
#include <cmath>
#include <sstream>

// Constructors
Matrix::Matrix() {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            data[i][j] = 0;
}

Matrix::Matrix(const int arr[N][N]) {
    Init(arr);
}

Matrix::Matrix(const Matrix& other) {
    *this = other;
}

int Matrix::get(int row, int col) const {
    return data[row][col];
}

void Matrix::set(int row, int col, int value) {
    data[row][col] = value;
}

void Matrix::Init(const int arr[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            data[i][j] = arr[i][j];
}

void Matrix::Read() {
    cout << "Enter " << N * N << " integers:\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> data[i][j];
}

void Matrix::Display() const {
    cout << *this;
}

string Matrix::toString() const {
    stringstream ss;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            ss << data[i][j] << ' ';
        ss << '\n';
    }
    return ss.str();
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (data[i][j] != other.data[i][j])
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

double Matrix::norm() const {
    double sum = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            sum += data[i][j] * data[i][j];
    return sqrt(sum);
}

int* Matrix::operator[](int index) {
    return data[index];
}

const int* Matrix::operator[](int index) const {
    return data[index];
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                data[i][j] = other.data[i][j];
    }
    return *this;
}

istream& operator>>(istream& in, Matrix& m) {
    for (int i = 0; i < Matrix::N; ++i)
        for (int j = 0; j < Matrix::N; ++j)
            in >> m.data[i][j];
    return in;
}

ostream& operator<<(ostream& out, const Matrix& m) {
    for (int i = 0; i < Matrix::N; ++i) {
        for (int j = 0; j < Matrix::N; ++j)
            out << m.data[i][j] << ' ';
        out << endl;
    }
    return out;
}