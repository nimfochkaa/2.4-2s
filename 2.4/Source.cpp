#include <iostream>
#include "Matrix.h"
using namespace std;

#pragma pack(push, 1)
class PackedMatrix {
    Matrix m;
};
#pragma pack(pop)

int main() {
    int arr[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Matrix m1(arr);
    Matrix m2 = m1;
    Matrix m3;

    cout << "Enter a matrix:\n";
    m3.Read();

    cout << "\nMatrix m1:\n" << m1;
    cout << "\nMatrix m3:\n" << m3;

    cout << "\nSubtraction m1 - m3:\n" << (m1 - m3);
    cout << "\nNorm of m1: " << m1.norm() << endl;

    cout << "\nMatrix m1 as string:\n" << m1.toString();

    cout << "\nIs m1 equal to m2? " << (m1 == m2 ? "Yes" : "No") << endl;

    cout << "\nAccess m1[1][2]: " << m1[1][2] << endl;

    cout << "\nSize without #pragma pack: " << sizeof(Matrix) << " bytes" << endl;
    cout << "Size with #pragma pack(1): " << sizeof(PackedMatrix) << " bytes\n";

    return 0;
}