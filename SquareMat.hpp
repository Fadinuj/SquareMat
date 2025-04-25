#ifndef SQUARE_MAT_HPP
#define SQUARE_MAT_HPP

#include <iostream>
#include <stdexcept>

namespace Square {
    class SquareMat {
    private:
        double** matrix;
        int size;

        void allocateMemory(int size);
        void copyFrom(const SquareMat& other);
        void freeMemory();

    public:
        // Constructor with size and values
        SquareMat(int size, double** values);

        // Copy constructor
        SquareMat(const SquareMat& other);

        // Destructor
        ~SquareMat();

        // Assignment operator
        SquareMat& operator=(const SquareMat& other);

        // Matrix addition: mat1 + mat2
        SquareMat operator+(const SquareMat& other) const;

        // Matrix subtraction: mat1 - mat2
        SquareMat operator-(const SquareMat other) const;

        // Matrix multiplication: mat1 * mat2
        SquareMat operator*(const SquareMat other) const;

        // Scalar multiplication: mat * scalar
        SquareMat operator*(double num) const;

        // Unary minus: -mat
        SquareMat operator-() const;

        // Matrix power: mat ^ pow (pow is non-negative integer)
        SquareMat operator^(int pow) const;

        // Element-wise multiplication: mat1 % mat2
        SquareMat operator%(const SquareMat other) const;

        // Element-wise modulo with scalar: mat % num
        SquareMat operator%(int num) const;

        // Scalar division: mat / num
        SquareMat operator/(double num) const;

        // Transpose: ~mat
        SquareMat operator~() const;

        // Compound addition assignment: mat += other
        SquareMat& operator+=(const SquareMat& other);

        // Compound subtraction assignment: mat -= other
        SquareMat& operator-=(const SquareMat& other);

        // Compound matrix multiplication assignment: mat *= other
        SquareMat& operator*=(const SquareMat& other);

        // Compound scalar multiplication assignment: mat *= scalar
        SquareMat& operator*=(double scalar);

        // Compound scalar division assignment: mat /= scalar
        SquareMat& operator/=(double scalar);

        // Compound element-wise multiplication assignment: mat %= other
        SquareMat& operator%=(const SquareMat& other);

        // Compound modulo with scalar assignment: mat %= scalar
        SquareMat& operator%=(int scalar);

        // Pre-increment: ++mat (adds 1 to all elements)
        SquareMat operator++();

        // Post-increment: mat++ (adds 1 to all elements)
        SquareMat operator++(int);

        // Pre-decrement: --mat (subtracts 1 from all elements)
        SquareMat operator--();

        // Post-decrement: mat-- (subtracts 1 from all elements)
        SquareMat operator--(int);

        // Element access (modifiable): mat[i][j]
        double* operator[](int row);

        // Element access (read-only): mat[i][j]
        const double* operator[](int row) const;

        // Determinant: !mat
        double operator!() const;
        double sumElements() const;

        // Equality comparison: mat1 == mat2 (sum of elements)
        bool operator==(const SquareMat& other) const;

        // Inequality comparison: mat1 != mat2
        bool operator!=(const SquareMat& other) const;

        // Less than: mat1 < mat2 (based on sum of elements)
        bool operator<(const SquareMat& other) const;

        // Greater than: mat1 > mat2
        bool operator>(const SquareMat& other) const;

        // Less than or equal: mat1 <= mat2
        bool operator<=(const SquareMat& other) const;

        // Greater than or equal: mat1 >= mat2
        bool operator>=(const SquareMat& other) const;

        // Output operator: cout << mat
        friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

        // Scalar multiplication from the left: scalar * mat
        friend SquareMat operator*(double scalar, const SquareMat& mat);

        // Print matrix to standard output
        void print() const;

        // Return the matrix size (dimension)
        int getSize() const;
    };
}

#endif // SQUARE_MAT_HPP
