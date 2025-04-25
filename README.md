# SquareMat Project

This project implements a `SquareMat` class — a class for square matrices with full operator overloading in C++.  
It supports matrix arithmetic, scalar operations, element-wise operations, comparison operations, and matrix properties such as transpose and determinant.

---

## Features

- Matrix addition (`+`), subtraction (`-`), multiplication (`*`)
- Scalar multiplication and division
- Element-wise multiplication (`%`) and modulo by scalar
- Matrix power operator (`^`)
- Transpose (`~`) and determinant (`!`)
- Pre/post increment (`++`) and decrement (`--`)
- Compound assignments (`+=`, `-=`, `*=`, `/=`, `%=`) 
- Comparison operators (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- Access elements via `[i][j]`
- Full exception handling for invalid operations
- Full memory management (no memory leaks - verified with Valgrind)

---

## File Structure

| File | Description |
|-----|-------------|
| `SquareMat.hpp` | Header file with class declaration and documentation |
| `SquareMat.cpp` | Implementation file for SquareMat methods |
| `main.cpp` | Example usage and demonstration of matrix operations |
| `tests.cpp` | Full unit tests using doctest framework |
| `Makefile` | Compilation and execution automation |

---

## Requirements

- C++17 or higher
- [doctest](https://github.com/doctest/doctest) single-header testing framework (already included in project folder)

---

## How to Compile and Run

```bash
# Compile the main program
make

# Run the main executable
make run

# Compile and run tests
make test

# Clean all compiled files
make clean
```

---

## How to Test

Unit tests are written in `tests.cpp` using the `doctest` framework.

To run tests:

```bash
make test
```

This will compile the tests and execute them automatically, verifying all operator implementations.

---

## Notes

- No memory leaks: verified using `valgrind`.
- All matrix operations are deeply validated on all matrix elements.
- The project uses a clean modular code structure with clear documentation.

---

## Author

- Developed by: Fadi Nujedat  
- Email: fadinujedat062@gmail.com