# DateTime Class in C++

This project contains a custom `DateTime` class implemented in C++ that models date and time values with various operations and utilities.

## Features

- Represents date and time with year, month, day, hour, minute, and second fields.
- Supports leap year calculation and month day counts.
- Overloaded operators for:
  - Comparison (`==`, `!=`, `<`, `<=`, `>`, `>=`)
  - Arithmetic (`+`, `-`, `+=`, `-=`)
  - Increment/decrement (`++`, `--`)
  - Assignment (`=`)
- Input and output streaming support (`>>`, `<<`).
- Date and time normalization handled in arithmetic operations.
- Provides basic date/time difference calculation.

## Usage

Include the header and source files in your project and create `DateTime` objects:

```cpp
#include "datetime.h"
#include <iostream>

int main() {
    DateTime dt1(0, 30, 14, 15, 7, 2025); // 2025-07-15 14:30:00
    DateTime dt2;
    std::cout << "Enter date and time (year month day hour minute second): ";
    std::cin >> dt2;

    if (dt1 < dt2) {
        std::cout << dt1 << " is earlier than " << dt2 << std::endl;
    }
}
