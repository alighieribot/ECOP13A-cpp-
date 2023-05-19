#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;
    static int count;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {
        count++;
    }

    static int getCount() {
        return count;
    }

    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    Complex operator+(const Complex& other) const {
        double newReal = real + other.real;
        double newImaginary = imaginary + other.imaginary;
        return Complex(newReal, newImaginary);
    }

    Complex operator-(const Complex& other) const {
        double newReal = real - other.real;
        double newImaginary = imaginary - other.imaginary;
        return Complex(newReal, newImaginary);
    }

    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imaginary * other.imaginary;
        double newImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(newReal, newImaginary);
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
        double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(newReal, newImaginary);
    }

    double modulus() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    void print() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int Complex::count = 0;

class LongInt {
private:
    int digits[30];

public:
    LongInt() {
        for (int i = 0; i < 30; i++) {
            digits[i] = 0;
        }
    }

    void readFromKeyboard() {
        for (int i = 0; i < 30; i++) {
            cin >> digits[i];
        }
    }

    void print() const {
        for (int i = 0; i < 30; i++) {
            cout << digits[i];
        }
        cout << endl;
    }

    LongInt operator+(const LongInt& other) const {
        LongInt result;
        int carry = 0;
        for (int i = 29; i >= 0; i--) {
            int sum = digits[i] + other.digits[i] + carry;
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }
        return result;
    }

    LongInt operator-(const LongInt& other) const {
        LongInt result;
        int borrow = 0;
        for (int i = 29; i >= 0; i--) {
            int diff = digits[i] - other.digits[i] - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits[i] = diff;
        }
        return result;
    }
};

class RightTriangle {
private:
    int sides[3];

public:
    RightTriangle(int a, int b, int c) {
        sides[0] = a;
        sides[1] = b;
        sides[2] = c;
    }

    bool isValid() const {
        return (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) ||
               (sides[1] * sides[1] + sides[2] * sides[2] == sides[0] * sides[0]) ||
               (sides[2] * sides[2] + sides[0] * sides[0] == sides[1] * sides[1]);
    }

    static void printAllPossibleTriangles() {
        for (int a = 1; a < 200; a++) {
            for (int b = 1; b < 200; b++) {
                for (int c = 1; c < 200; c++) {
                    RightTriangle triangle(a, b, c);
                    if (triangle.isValid()) {
                        cout << "Side lengths: " << a << ", " << b << ", " << c << endl;
                    }
                }
            }
        }
    }
};

int main() {
    int option;
    do {
        cout << "Menu:" << endl;
        cout << "1. Complex Numbers" << endl;
        cout << "2. Long Integers" << endl;
        cout << "3. Right Triangles" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1: {
                Complex c1(3, 4);
                Complex c2(1, -2);

                Complex sum = c1 + c2;
                Complex diff = c1 - c2;
                Complex prod = c1 * c2;
                Complex div = c1 / c2;

                cout << "Complex Numbers:" << endl;
                cout << "c1: ";
                c1.print();
                cout << "c2: ";
                c2.print();
                cout << "Sum: ";
                sum.print();
                cout << "Difference: ";
                diff.print();
                cout << "Product: ";
                prod.print();
                cout << "Division: ";
                div.print();
                cout << "Modulus of c1: " << c1.modulus() << endl;
                cout << "Modulus of c2: " << c2.modulus() << endl;
                cout << "Number of Complex objects instantiated: " << Complex::getCount() << endl;

                cout << endl;
                break;
            }
            case 2: {
                LongInt num1;
                LongInt num2;

                cout << "Enter the first Long Integer (30 digits): ";
                num1.readFromKeyboard();
                cout << "Enter the second Long Integer (30 digits): ";
                num2.readFromKeyboard();

                LongInt sum = num1 + num2;
                LongInt diff = num1 - num2;

                cout << "Long Integers:" << endl;
                cout << "num1: ";
                num1.print();
                cout << "num2: ";
                num2.print();
                cout << "Sum: ";
                sum.print();
                cout << "Difference: ";
                diff.print();

                cout << endl;
                break;
            }
            case 3: {
                RightTriangle::printAllPossibleTriangles();
                cout << endl;
                break;
            }
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                cout << endl;
                break;
        }
    } while (option != 0);

    return 0;
}
