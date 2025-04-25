//fadiujedat062@gmail.com//
#include "SquareMat.hpp"
#include <iostream>

namespace Square{
        // Allocates dynamic memory for a square matrix of given size
    void SquareMat::allocateMemory(int size)
    {
        matrix = new double*[size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[size];
        }
    }

    // Constructor: creates a square matrix of size x size and copies values from given 2D array
    SquareMat::SquareMat(int size, double** values)
    {
        if (size <= 0) {
            throw std::invalid_argument("Matrix size must be positive");
        }
        this->size = size;
        allocateMemory(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = values[i][j];
            }
        }
    }

    // Copy constructor: creates a deep copy of another SquareMat
    SquareMat::SquareMat(const SquareMat& other)
    {
        this->size = other.size;
        allocateMemory(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

    // Frees the memory allocated for the matrix
    void SquareMat::freeMemory() 
    {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;
    }

    // Destructor: frees the memory when the object is destroyed
    SquareMat::~SquareMat() 
    {
        freeMemory();
    }

    // Returns the dimension (size) of the square matrix
    int SquareMat::getSize() const
    {
        return size;
    }

    // Prints the matrix to the standard output
    void SquareMat::print() const
    {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Assignment operator: replaces the content of this matrix with another matrix
    SquareMat& SquareMat::operator=(const SquareMat& other) 
    {
        if (this == &other) {
            return *this; 
        }
        
        freeMemory();
        this->size = other.size;
        allocateMemory(size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }

    // Operator + : returns a new matrix that is the sum of this and another matrix
    SquareMat SquareMat::operator+(const SquareMat& other) const
    {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix size must match for addition");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = this->matrix[i][j] + other.matrix[i][j];
            }
        }

        SquareMat sum(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return sum;
    }

    // Operator - : subtracts another matrix from this matrix, element-wise
    SquareMat SquareMat::operator-(const SquareMat other) const {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for subtraction.");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = this->matrix[i][j] - other.matrix[i][j];
            }
        }

        SquareMat diff(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return diff;
    }

    // Operator * : performs standard matrix multiplication
    SquareMat SquareMat::operator*(const SquareMat other) const {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for multiplication.");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    result[i][j] += this->matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        SquareMat product(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return product;
    }

    // Unary minus operator: negates all elements in the matrix
    SquareMat SquareMat::operator-() const {
        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = -matrix[i][j];
            }
        }

        SquareMat negated(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return negated;
    }

    // Operator * : multiplies all matrix elements by a scalar
    SquareMat SquareMat::operator*(double scalar) const {
        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = matrix[i][j] * scalar;
            }
        }

        SquareMat scaled(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return scaled;
    }

    // Operator ^ : raises matrix to a positive integer power
    SquareMat SquareMat::operator^(int power) const {
        if (power < 0) {
            throw std::invalid_argument("Negative powers are not supported.");
        }
    
        // Create identity matrix
        double** identity = new double*[size];
        for (int i = 0; i < size; ++i) {
            identity[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                identity[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    
        SquareMat result(size, identity);
    
        for (int i = 0; i < size; ++i) {
            delete[] identity[i];
        }
        delete[] identity;
    
        if (power == 0) return result;
        if (power == 1) return SquareMat(*this); 
    
        result = *this;
        for (int i = 1; i < power; ++i) {
            result = result * (*this);
        }
    
        return result;
    }
    

    // Operator % : element-wise multiplication of two matrices
    SquareMat SquareMat::operator%(const SquareMat other) const {
        if (this->size != other.size) {
            throw std::invalid_argument("Matrix sizes must match for element-wise multiplication.");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = this->matrix[i][j] * other.matrix[i][j];
            }
        }

        SquareMat product(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return product;
    }

    // Operator % : modulo each element of matrix by an integer scalar
    SquareMat SquareMat::operator%(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Cannot modulo by zero.");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = static_cast<int>(matrix[i][j]) % scalar;
            }
        }

        SquareMat modded(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return modded;
    }

    // Operator / : divides all matrix elements by a scalar
    SquareMat SquareMat::operator/(double scalar) const {
        if (scalar == 0.0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }

        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = matrix[i][j] / scalar;
            }
        }

        SquareMat divided(size, result);

        for (int i = 0; i < size; ++i) {
            delete[] result[i];
        }
        delete[] result;

        return divided;
    }

    // Operator ~ : returns the transpose of the matrix
    SquareMat SquareMat::operator~() const {
        double** result = new double*[size];
        for (int i = 0; i < size; ++i) {
            result[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                result[i][j] = matrix[j][i];
            }
        }

        SquareMat transposed(size, result);

        for (int i = 0; i < size; ++i) delete[] result[i];
        delete[] result;

        return transposed;
    }

    // Operator ! : calculates the determinant of the matrix recursively
    double SquareMat::operator!() const {
        if (size == 1) return matrix[0][0];
        if (size == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        double det = 0;
        for (int col = 0; col < size; ++col) {
            double** minor = new double*[size - 1];
            for (int i = 0; i < size - 1; ++i)
                minor[i] = new double[size - 1];

            for (int i = 1; i < size; ++i) {
                int subCol = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    minor[i - 1][subCol++] = matrix[i][j];
                }
            }

            SquareMat subMatrix(size - 1, minor);
            double cofactor = ((col % 2 == 0) ? 1 : -1) * matrix[0][col] * !subMatrix;
            det += cofactor;

            for (int i = 0; i < size - 1; ++i) delete[] minor[i];
            delete[] minor;
        }

        return det;
    }

    // Operator += : adds another matrix to this one in-place
    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for operator+=.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] += other.matrix[i][j];

        return *this;
    }

    // Operator -= : subtracts another matrix from this one in-place
    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for operator-=.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] -= other.matrix[i][j];

        return *this;
    }

    // Operator *= : multiplies this matrix with another and stores the result
    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for operator*=.");

        SquareMat product = (*this) * other;
        *this = product;
        return *this;
    }

    // Operator *= : multiplies each matrix element by a scalar in-place
    SquareMat& SquareMat::operator*=(double scalar) {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] *= scalar;

        return *this;
    }

    // Operator /= : divides each matrix element by a scalar in-place
    SquareMat& SquareMat::operator/=(double scalar) {
        if (scalar == 0.0)
            throw std::invalid_argument("Division by zero is not allowed.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] /= scalar;

        return *this;
    }

    // Operator %= : element-wise modulo with another matrix
    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes must match for operator%=.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j) {
                int a = static_cast<int>(matrix[i][j]);
                int b = static_cast<int>(other.matrix[i][j]);
                if (b == 0)
                    throw std::invalid_argument("Modulo by zero in matrix element.");
                matrix[i][j] = a % b;
            }

        return *this;
    }

    // Operator %= : modulo each matrix element by a scalar
    SquareMat& SquareMat::operator%=(int scalar) {
        if (scalar == 0)
            throw std::invalid_argument("Modulo by zero is not allowed.");

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] = static_cast<int>(matrix[i][j]) % scalar;

        return *this;
    }

    // Pre-decrement operator --mat
    SquareMat SquareMat::operator--() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] -= 1;

        return *this;
    }

    // Post-decrement operator mat--
    SquareMat SquareMat::operator--(int) {
        SquareMat temp(*this);
        --(*this);
        return temp;
    }

    // Pre-increment operator ++mat
    SquareMat SquareMat::operator++() {
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                matrix[i][j] += 1;

        return *this;
    }

    // Post-increment operator mat++
    SquareMat SquareMat::operator++(int) {
        SquareMat temp(*this);
        ++(*this);
        return temp;
    }

    // Operator [] : allows direct element access by row (modifiable)
    double* SquareMat::operator[](int row) {
        if (row < 0 || row >= size)
            throw std::out_of_range("Row index out of bounds.");
        return matrix[row];
    }

    // Operator [] : allows direct element access by row (read-only)
    const double* SquareMat::operator[](int row) const {
        if (row < 0 || row >= size)
            throw std::out_of_range("Row index out of bounds.");
        return matrix[row];
    }

    // Helper: returns the sum of all elements in the matrix
    double SquareMat::sumElements() const {
        double sum = 0;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                sum += matrix[i][j];
        return sum;
    }

    // Operator == : checks if the sum of elements of both matrices are equal
    bool SquareMat::operator==(const SquareMat& other) const {
        return this->sumElements() == other.sumElements();
    }

    // Operator != : checks if matrices are not equal by sum
    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    // Operator < : compares matrices by sum of elements
    bool SquareMat::operator<(const SquareMat& other) const {
        return this->sumElements() < other.sumElements();
    }

    // Operator > : compares matrices by sum of elements
    bool SquareMat::operator>(const SquareMat& other) const {
        return this->sumElements() > other.sumElements();
    }

    // Operator <= : compares matrices by sum of elements
    bool SquareMat::operator<=(const SquareMat& other) const {
        return !(*this > other);
    }

    // Operator >= : compares matrices by sum of elements
    bool SquareMat::operator>=(const SquareMat& other) const {
        return !(*this < other);
    }

    // Operator << : prints the matrix to an output stream
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j)
                os << mat.matrix[i][j] << " ";
            os << std::endl;
        }
        return os;
    }

    // Operator * : allows scalar multiplication from the left (e.g., 2 * matrix)
    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }

    
    
    
    
    
    
    

}