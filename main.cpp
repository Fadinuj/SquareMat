//fadiujedat062@gmail.com//
#include "SquareMat.hpp"
#include <iostream>

using namespace Square;

// Helper functions
double** createMatrix(int size);
void freeMatrix(double** matrix, int size);

int main() {
    const int size = 2;

    // Create two 2x2 matrices
    double** values1 = createMatrix(size);
    double** values2 = createMatrix(size);

    // Initialize values
    values1[0][0] = 1; values1[0][1] = 2;
    values1[1][0] = 3; values1[1][1] = 4;

    values2[0][0] = 5; values2[0][1] = 6;
    values2[1][0] = 7; values2[1][1] = 8;

    SquareMat mat1(size, values1);
    SquareMat mat2(size, values2);

    std::cout << "Matrix 1:\n" << mat1;
    std::cout << "Matrix 2:\n" << mat2;

    std::cout << "\nAddition (mat1 + mat2):\n" << (mat1 + mat2);
    std::cout << "\nSubtraction (mat1 - mat2):\n" << (mat1 - mat2);
    std::cout << "\nMatrix multiplication (mat1 * mat2):\n" << (mat1 * mat2);
    std::cout << "\nScalar multiplication (mat1 * 3):\n" << (mat1 * 3);
    std::cout << "\nScalar multiplication (3 * mat1):\n" << (3 * mat1);
    SquareMat mat1_squared = mat1 ^ 2;
    std::cout << "\nMatrix mat1 ^ 2:\n" << mat1_squared;
    std::cout << "\nElement-wise multiplication (mat1 % mat2):\n" << (mat1 % mat2);
    std::cout << "\nModulo by scalar (mat2 % 3):\n" << (mat2 % 3);
    std::cout << "\nScalar division (mat2 / 2):\n" << (mat2 / 2);
    std::cout << "\nNegation (-mat1):\n" << (-mat1);
    std::cout << "\nTranspose (~mat1):\n" << (~mat1);
    std::cout << "\nDeterminant (!mat1): " << !mat1 << "\n";

    // Compound assignments
    SquareMat temp1 = mat1;
    temp1 += mat2;
    std::cout << "\nCompound += (mat1 += mat2):\n" << temp1;

    temp1 = mat1;
    temp1 -= mat2;
    std::cout << "\nCompound -= (mat1 -= mat2):\n" << temp1;

    temp1 = mat1;
    temp1 *= mat2;
    std::cout << "\nCompound *= (mat1 *= mat2):\n" << temp1;

    temp1 = mat1;
    temp1 *= 2;
    std::cout << "\nCompound *= scalar (mat1 *= 2):\n" << temp1;

    temp1 = mat1;
    temp1 /= 2;
    std::cout << "\nCompound /= scalar (mat1 /= 2):\n" << temp1;

    temp1 = mat2;
    temp1 %= mat1;
    std::cout << "\nCompound %= matrix (mat2 %= mat1):\n" << temp1;

    temp1 = mat2;
    temp1 %= 3;
    std::cout << "\nCompound %= scalar (mat2 %= 3):\n" << temp1;

    // Increment/decrement
    temp1 = mat1;
    ++temp1;
    std::cout << "\nPre-increment (++mat1):\n" << temp1;

    temp1 = mat1;
    temp1++;
    std::cout << "\nPost-increment (mat1++):\n" << temp1;

    temp1 = mat1;
    --temp1;
    std::cout << "\nPre-decrement (--mat1):\n" << temp1;

    temp1 = mat1;
    temp1--;
    std::cout << "\nPost-decrement (mat1--):\n" << temp1;

    // Comparison (by sum of elements)
    std::cout << "\nComparison (mat1 == mat2): " << (mat1 == mat2 ? "true" : "false") << "\n";
    std::cout << "Comparison (mat1 != mat2): " << (mat1 != mat2 ? "true" : "false") << "\n";
    std::cout << "Comparison (mat1 < mat2): " << (mat1 < mat2 ? "true" : "false") << "\n";
    std::cout << "Comparison (mat1 <= mat2): " << (mat1 <= mat2 ? "true" : "false") << "\n";
    std::cout << "Comparison (mat1 > mat2): " << (mat1 > mat2 ? "true" : "false") << "\n";
    std::cout << "Comparison (mat1 >= mat2): " << (mat1 >= mat2 ? "true" : "false") << "\n";

    // Indexing
    std::cout << "\nElement access mat1[1][0]: " << mat1[1][0] << "\n";

    // Clean up
    freeMatrix(values1, size);
    freeMatrix(values2, size);

    return 0;
}

// Create a dynamic matrix
double** createMatrix(int size) {
    double** matrix = new double*[size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new double[size];
    return matrix;
}

// Free dynamic matrix memory
void freeMatrix(double** matrix, int size) {
    for (int i = 0; i < size; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
