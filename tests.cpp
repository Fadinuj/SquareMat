//fadiujedat062@gmail.com//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "SquareMat.hpp"

using namespace Square;

// Helper to create a matrix
double** fillMatrix(int size, std::initializer_list<double> values) {
    double** mat = new double*[size];
    auto it = values.begin();
    for (int i = 0; i < size; ++i) {
        mat[i] = new double[size];
        for (int j = 0; j < size; ++j)
            mat[i][j] = *it++;
    }
    return mat;
}

// Free a matrix
void freeMatrix(double** mat, int size) {
    for (int i = 0; i < size; ++i)
        delete[] mat[i];
    delete[] mat;
}

TEST_CASE("Addition") {
    double** a = fillMatrix(2, {1, -2, 4.5, 0});
    double** b = fillMatrix(2, {0, 3, -4.5, 7});
    SquareMat m1(2, a), m2(2, b);
    SquareMat r = m1 + m2;

    CHECK(r[0][0] == 1);
    CHECK(r[0][1] == 1);
    CHECK(r[1][0] == 0);
    CHECK(r[1][1] == 7);

    freeMatrix(a, 2); freeMatrix(b, 2);
}

TEST_CASE("Subtraction") {
    double** a = fillMatrix(2, {5, 8, -2, 6});
    double** b = fillMatrix(2, {1, -3, 2, 6});
    SquareMat m1(2, a), m2(2, b);
    SquareMat r = m1 - m2;

    CHECK(r[0][0] == 4);
    CHECK(r[0][1] == 11);
    CHECK(r[1][0] == -4);
    CHECK(r[1][1] == 0);

    freeMatrix(a, 2); freeMatrix(b, 2);
}

TEST_CASE("Matrix multiplication") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    double** b = fillMatrix(2, {2, 0, 1, 2});
    SquareMat m1(2, a), m2(2, b);
    SquareMat r = m1 * m2;

    CHECK(r[0][0] == 4);
    CHECK(r[0][1] == 4);
    CHECK(r[1][0] == 10);
    CHECK(r[1][1] == 8);

    freeMatrix(a, 2); freeMatrix(b, 2);
}

TEST_CASE("Scalar multiplication and division") {
    double** a = fillMatrix(2, {-1, 3, 0.5, -2});
    SquareMat m(2, a);

    SquareMat r = m * -2;
    CHECK(r[0][0] == 2);
    CHECK(r[0][1] == -6);
    CHECK(r[1][0] == -1);
    CHECK(r[1][1] == 4);

    SquareMat d = m / 0.5;
    CHECK(d[0][0] == -2);
    CHECK(d[1][1] == -4);

    freeMatrix(a, 2);
}

TEST_CASE("Unary minus and transpose") {
    double** a = fillMatrix(2, {10, 20, 30, 40});
    SquareMat m(2, a);
    SquareMat neg = -m;
    SquareMat tr = ~m;

    CHECK(neg[0][0] == -10);
    CHECK(neg[1][1] == -40);
    CHECK(tr[0][1] == 30);
    CHECK(tr[1][0] == 20);

    freeMatrix(a, 2);
}

TEST_CASE("Power operator ^2") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    SquareMat m(2, a);
    SquareMat p = m ^ 2;

    CHECK(p[0][0] == 7);
    CHECK(p[0][1] == 10);
    CHECK(p[1][0] == 15);
    CHECK(p[1][1] == 22);

    freeMatrix(a, 2);
}

TEST_CASE("Determinant") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    SquareMat m(2, a);
    CHECK((!m) == -2);
    freeMatrix(a, 2);
}

TEST_CASE("Modulo operations") {
    double** a = fillMatrix(2, {3, 2, 4, 5});
    double** b = fillMatrix(2, {8, 5, 9, 13});
    SquareMat m1(2, a);
    SquareMat m2(2, b);

    m2 %= m1;

    CHECK(static_cast<int>(m2[0][0]) == 2); // 8 % 3
    CHECK(static_cast<int>(m2[0][1]) == 1); // 5 % 2
    CHECK(static_cast<int>(m2[1][0]) == 1); // 9 % 4
    CHECK(static_cast<int>(m2[1][1]) == 3); // 13 % 5

    freeMatrix(a, 2); freeMatrix(b, 2);
}

TEST_CASE("Compound assignments") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    double** b = fillMatrix(2, {5, 6, 7, 8});
    SquareMat m1(2, a), m2(2, b);

    m1 += m2;
    CHECK(m1[0][0] == 6);
    m1 = SquareMat(2, a);
    m1 -= m2;
    CHECK(m1[1][1] == -4);
    m1 = SquareMat(2, a);
    m1 *= m2;
    CHECK(m1[1][0] == 43);
    m1 = SquareMat(2, a);
    m1 *= 3;
    CHECK(m1[0][1] == 6);
    m2 = SquareMat(2, b);
    m2 /= 2;
    CHECK(m2[1][1] == 4);

    freeMatrix(a, 2); freeMatrix(b, 2);
}

TEST_CASE("Increment and Decrement") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    SquareMat m(2, a);

    ++m;
    CHECK(m[0][0] == 2);
    m = SquareMat(2, a);
    m++;
    CHECK(m[0][0] == 2);
    m = SquareMat(2, a);
    --m;
    CHECK(m[1][1] == 3);
    m = SquareMat(2, a);
    m--;
    CHECK(m[1][1] == 3);

    freeMatrix(a, 2);
}

TEST_CASE("Comparisons and access") {
    double** a = fillMatrix(2, {1, 2, 3, 4});
    double** b = fillMatrix(2, {1, 2, 3, 4});
    double** c = fillMatrix(2, {5, 5, 5, 5});
    SquareMat m1(2, a), m2(2, b), m3(2, c);

    CHECK(m1 == m2);
    CHECK(m1 != m3);
    CHECK(m1 < m3);
    CHECK(m3 > m1);
    CHECK(m1 <= m2);
    CHECK(m3 >= m1);
    CHECK(m1[0][0] == 1);
    CHECK(m1[1][1] == 4);

    freeMatrix(a, 2); freeMatrix(b, 2); freeMatrix(c, 2);
}
