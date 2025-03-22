#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
    static const int N = 3; 
    int data[N][N];

public:
    Matrix();                          
    Matrix(const int arr[N][N]);        
    Matrix(const Matrix& other);       

    int get(int row, int col) const;
    void set(int row, int col, int value);

    void Init(const int arr[N][N]);
    void Read();
    void Display() const;
    string toString() const;

    Matrix operator-(const Matrix& other) const;         
    bool operator==(const Matrix& other) const;           
    bool operator!=(const Matrix& other) const;
    double norm() const;                                   

    int* operator[](int index);                           
    const int* operator[](int index) const;

    Matrix& operator=(const Matrix& other);               

    // Friend input/output
    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& out, const Matrix& m);
};