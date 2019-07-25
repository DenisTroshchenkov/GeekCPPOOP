#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

class Fraction {
public:
    Fraction(int num = 0, int den = 1) {
        if (den == 0) {
            throw "denuminator cant be zero!";
        }
        m_numerator = num;
        m_denominator = den;
    }
   
    friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    friend std::istream& operator>> (std::istream &in, Fraction &fraction);
    friend Fraction operator* (const Fraction &s_f1, const Fraction &s_f2);

    void reduction() {
        int p = m_numerator;
        int q = m_denominator;
        for(int i=1; i<=m_numerator && i<=m_denominator; i++) {
            if(!(m_numerator%i) && !(m_denominator%i)) {
                p=m_numerator/i;
                q=m_denominator/i;
            }
        }
        m_numerator = p;
        m_denominator = q;
    }

private:
    int m_numerator;
    int m_denominator;
};

std::istream& operator>> (std::istream &in, Fraction &fraction) {
    in >> fraction.m_numerator;
    in >> fraction.m_denominator;
    return in;
}

std::ostream& operator<< (std::ostream &out, const Fraction &fraction) {
    out <<  fraction.m_numerator << "/" << fraction.m_denominator;
    return out;
}

Fraction operator* (const Fraction &s_f1, const Fraction &s_f2) {
    Fraction f(s_f1.m_numerator * s_f2.m_numerator, s_f1.m_denominator * s_f2.m_denominator);
    f.reduction();
    return f;
}

std::ostream& endll(std::ostream &os) { 

    return os << '\n'; 
}

void task1() {
    std::cout << "Task1:\n";
    Fraction f1;
    std::cout << "Enter fraction 1: ";
    std::cin >> f1;

    Fraction f2;
    std::cout << "Enter fraction 2: ";
    std::cin >> f2;

    std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
}

void task2() { 
    std::cout << "Task2:\n";
    std::vector<std::string> lines;
    std::string line;
    std::cin.clear();
    while (1)
    {
        std::cout << "Enter text: ";
        getline(std::cin, line);
        if (!line.length()){
            break;
        }
        lines.push_back(line);
    }
   
    for(int i = 0; i < lines.size(); ++i) {
        std::cout << std::setw(10);
        if (!(i % 2)) { 
            std::cout << std::left << lines[i];
        } else {
            std::cout << std::right << lines[i] << "\n";
        } 
    }
    std::cout << "\n";
}

void task3() {
    std::cout << "Task3:\n";
    bool f;
    std::string number;
    do {
        f = true;
        std::cout << "Enter number:\n";
        getline(std::cin, number);
        for (int i = 0; i < number.length(); ++i) {
            if (!isdigit(number[i])) {
                f = false;
                break;
            }
        }
        f ? std::cout << "is number\n" : std::cout << "not number\n";

    } while (!f);
     
}

void task4() {
    std::cout.clear();
    std::cout << "Test4" << endll;
}

int main() {
    task1();   
    task2();
    task3();
    task4();
    return 0;
}
