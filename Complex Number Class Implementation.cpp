#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

   
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        return Complex(
            (real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator
        );
    }
    bool operator>(const Complex& other) const {
        return (real*real + imaginary*imaginary) > (other.real*other.real + other.imaginary*other.imaginary);
    }
    void display() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
    }
    double magnitude() const {
        return sqrt(real*real + imaginary*imaginary);
    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i";
    } else {
        os << " - " << -c.imaginary << "i";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    std::cout << "Enter real part: ";
    is >> c.real;
    std::cout << "Enter imaginary part: ";
    is >> c.imaginary;
    return is;
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    Complex c3;
    std::cout << "Enter values for c3:\n";
    std::cin >> c3;
    std::cout << "\nComplex numbers:\n";
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c3 = " << c3 << std::endl;
    std::cout << "\nArithmetic operations:\n";
    std::cout << "c1 + c2 = " << c1 + c2 << std::endl;
    std::cout << "c1 - c2 = " << c1 - c2 << std::endl;
    std::cout << "c1 * c2 = " << c1 * c2 << std::endl;
    std::cout << "c1 / c2 = " << c1 / c2 << std::endl;
    std::cout << "\nMagnitude comparison:\n";
    std::cout << "c1 magnitude: " << c1.magnitude() << std::endl;
    std::cout << "c2 magnitude: " << c2.magnitude() << std::endl;
    std::cout << "c3 magnitude: " << c3.magnitude() << std::endl;
    
    if (c1 > c2) {
        std::cout << "c1 has greater magnitude than c2\n";
    } else {
        std::cout << "c1 does not have greater magnitude than c2\n";
    }
    
    if (c1 > c3) {
        std::cout << "c1 has greater magnitude than c3\n";
    } else {
        std::cout << "c1 does not have greater magnitude than c3\n";
    }
    
    return 0;
}