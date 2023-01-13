#include "ExampleClass.hpp"

int ExampleClass::factorial() {
    int factorial = 1;

    for (int i = 1; i <= number; i++) {
        factorial = factorial * i;
    }

    return factorial;
}

int ExampleClass::specialSum() {
    int sum = 0;

    for (int i = 1; i <= number; i++) {
        sum = sum + i;
    }

    return sum;
}

int ExampleClass::getNumber() const {
    return number;
}

void ExampleClass::setNumber(int number) {
    ExampleClass::number = number;
}
