#include <iostream>
#include <cmath>
#include <string>

class Figure {
public:
    Figure() {}
    virtual int area() const = 0;
};

class Parallelogram: virtual public Figure {
public:
    Parallelogram(int h = 0, int a = 0):m_h(h), m_a(a) {}
    
    int area() const {
        return m_h * m_a;
    }
private:
    int m_h;
    int m_a;
};

class Circle: virtual public Figure {
public:
    Circle(int r = 0):m_r(r) {}
    int area() const {
        return M_PI * pow(m_r, 2);
    } 
private:
    int m_r;
};


class Rectangle: public Parallelogram {
public:
    Rectangle(int a = 0, int b = 0):m_a(a), m_b(b){}
    int area() const {
        return m_a * m_b;
    }
private:
    int m_a;
    int m_b;
};

class Square: public Parallelogram {
public:
    Square(int a):m_a(a) {}
    int area() const {
        return pow(m_a,2); 
    }
private:
    int m_a;
};

class Rhombus: public Parallelogram {
public:
    Rhombus(int d1 = 0, int d2 = 0):m_d1(d1), m_d2(d2) {}
    int area() const {
        return 0.5 * m_d1 * m_d2;
    }
private:
    int m_d1;
    int m_d2;
};

class Car {
public:
    Car(std::string company = "", std::string model = ""): m_company(company), m_model(model) {
        std::cout << "Car company" << m_company << std::endl;
        std::cout << "Car model" << m_model << std::endl;
    }
protected:
    std::string m_company;
    std::string m_model;
};


class PessengerCar: virtual public Car {
public:
    PessengerCar(std::string company = "", std::string model = ""): Car(company, model) {
        std::cout << "PC company" << m_company << std::endl;
        std::cout << "PC model" << m_model << std::endl;
    }
};

class Bus: virtual public Car {
public:
    Bus(std::string company = "", std::string model = ""): Car(company, model) {
        std::cout << "Bus company" << m_company << std::endl;
        std::cout << "Bus model" << m_model << std::endl;
    }
};

class Minivan: public PessengerCar, public Bus {
public:
    Minivan(std::string company = "", std::string model = ""): PessengerCar(company, model), Bus(company, model),
      Car(company, model) {
        std::cout << "MV company" << m_company << std::endl;
        std::cout << "MV model" << m_model << std::endl;
      }
};

class Fraction {
public:
    Fraction() {}
    virtual void print()const = 0;
};

class SimpleFraction: virtual public Fraction {
public:
    SimpleFraction(int num = 0, int den = 1) {
        if (den == 0) {
            throw "denuminator cant be zero!";
        }
        m_numerator = num;
        m_denominator = den;
    }

    SimpleFraction operator- () const {
        return SimpleFraction(-m_numerator, m_denominator);
    }

    void print() const {
        std::cout << "SimpleFraction: " << m_numerator << "/" << m_denominator << std::endl;

    }
   
    friend SimpleFraction operator+ (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend SimpleFraction operator- (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend SimpleFraction operator* (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend SimpleFraction operator/ (const SimpleFraction &s_f1, const SimpleFraction &s_f2);

    friend bool operator== (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend bool operator!= (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend bool operator<  (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend bool operator>  (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend bool operator<= (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
    friend bool operator>= (const SimpleFraction &s_f1, const SimpleFraction &s_f2);
private:
    int m_numerator;
    int m_denominator;
};

class MixedFraction: virtual public Fraction {
public:
    MixedFraction(int whole = 0, int num = 0, int den = 1) {
         if (den == 0) {
            throw "denuminator cant be zero!";
        }
        m_numerator = num;
        m_denominator = den;
        m_whole = whole;
    }

    MixedFraction operator- () const {
        return MixedFraction(-m_whole, m_numerator, m_denominator);
    }

     void print() const {
        std::cout << "MixedFraction: " << m_whole << " " << m_numerator << "/" << m_denominator << std::endl;

    }

    friend MixedFraction operator+ (const MixedFraction &s_f1, const MixedFraction &s_f2);
    friend MixedFraction operator- (const MixedFraction &s_f1, const MixedFraction &s_f2);
    friend MixedFraction operator* (const MixedFraction &s_f1, const MixedFraction &s_f2);
    friend MixedFraction operator/ (const MixedFraction &s_f1, const MixedFraction &s_f2);
 
    friend bool operator== (const MixedFraction &s_f1, const MixedFraction &s_f2);   
    friend bool operator!= (const MixedFraction &s_f1, const MixedFraction &s_f2); 
    friend bool operator< (const MixedFraction &s_f1, const MixedFraction &s_f2); 
    friend bool operator> (const MixedFraction &s_f1, const MixedFraction &s_f2); 
    friend bool operator<= (const MixedFraction &s_f1, const MixedFraction &s_f2); 
    friend bool operator>= (const MixedFraction &s_f1, const MixedFraction &s_f2);
private:
    int m_numerator;
    int m_denominator;
    int m_whole;
};

int get_int_part(int& num, int& den) {
    int intPart = 0;
    if(num >= den) {
        intPart += (num / den);
        num %= den;
    }
    return intPart;
}

int find_lcm(int a, int b) {
    int tmp;
    tmp=a*b;
    while (a!=0 && b!=0){
        (a>b) ? a=a%b : b=b%a;
    }
    return tmp/(a+b);
}

SimpleFraction operator+ (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    int lcm = find_lcm(s_f1.m_denominator, s_f2.m_denominator);
    int num =( s_f1.m_numerator*(lcm / s_f1.m_denominator) + s_f2.m_numerator*(lcm / s_f2.m_denominator));
    return SimpleFraction(num, lcm);
}

SimpleFraction operator- (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    int lcm = find_lcm(s_f1.m_denominator, s_f2.m_denominator);
    int num =( s_f1.m_numerator*(lcm / s_f1.m_denominator) - s_f2.m_numerator*(lcm / s_f2.m_denominator));
    return SimpleFraction(num, lcm);
}

SimpleFraction operator* (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return SimpleFraction(s_f1.m_numerator * s_f2.m_numerator, s_f1.m_denominator * s_f2.m_denominator);
}

SimpleFraction operator/ (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return SimpleFraction(s_f1.m_numerator * s_f2.m_denominator, s_f1.m_denominator * s_f2.m_numerator);
}

bool operator== (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return (s_f1.m_numerator / s_f1.m_denominator) == (s_f2.m_numerator / s_f2.m_denominator);
}

bool operator!= (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return !(s_f1 == s_f2);
}

bool operator< (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return (s_f1.m_numerator / s_f1.m_denominator) < (s_f2.m_numerator / s_f2.m_denominator);
}

bool operator> (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return !(s_f1 < s_f1) && s_f1 != s_f2;
}

bool operator>= (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return !(s_f1 < s_f2);
}

bool operator<= (const SimpleFraction &s_f1, const SimpleFraction &s_f2) {
    return !(s_f1 > s_f2);
}

MixedFraction operator+ (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    int lcm = find_lcm(m_f1.m_denominator, m_f2.m_denominator);
    int num =( ((m_f1.m_whole * m_f1.m_denominator) + m_f1.m_numerator)*(lcm / m_f1.m_denominator) + ((m_f2.m_whole * m_f2.m_denominator) + m_f2.m_numerator)*(lcm / m_f2.m_denominator));
    int whole = get_int_part(num, lcm);
    return MixedFraction(whole, num, lcm);
}

MixedFraction operator- (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    int lcm = find_lcm(m_f1.m_denominator, m_f2.m_denominator);
    int num =( ((m_f1.m_whole * m_f1.m_denominator ) + m_f1.m_numerator )*(lcm / m_f1.m_denominator) - ((m_f2.m_whole * m_f1.m_denominator) + m_f2.m_numerator)*(lcm / m_f2.m_denominator));
    int whole = get_int_part(num, lcm);
    return MixedFraction(whole, num, lcm);
}

MixedFraction operator* (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return MixedFraction(m_f1.m_whole * m_f2.m_whole, m_f1.m_numerator * m_f2.m_numerator, m_f1.m_denominator * m_f2.m_denominator);
}

MixedFraction operator/ (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    int num = m_f1.m_numerator * m_f2.m_denominator * m_f1.m_whole;
    int den = m_f1.m_denominator * m_f2.m_numerator * m_f2.m_whole;
    int whole = get_int_part(num, den);
    return MixedFraction(whole, num, den);
}

bool operator== (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return (m_f1.m_whole + m_f1.m_numerator / m_f1.m_denominator) == (m_f2.m_whole + m_f2.m_numerator / m_f2.m_denominator);
}

bool operator!= (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return !(m_f1 == m_f2);
}

bool operator< (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return (m_f1.m_whole + m_f1.m_numerator / m_f1.m_denominator) < (m_f2.m_whole + m_f2.m_numerator / m_f2.m_denominator);
}

bool operator> (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return !(m_f1 < m_f2) && !(m_f1 == m_f2);
}

bool operator<= (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return !(m_f1 > m_f2);
}

bool operator>= (const MixedFraction &m_f1, const MixedFraction &m_f2) {
    return !(m_f1 < m_f2);
}


void task1() {
   std::cout << "task1:\n";
   Parallelogram parallelogram(2,3);
   std::cout << "Parallelogram: " << parallelogram.area() << std::endl;
   Circle circle(5);
   std::cout << "circle: " << circle.area() << std::endl;
   Rectangle rectangle(8,3);
   std::cout << "Recatangle: " << rectangle.area() << std::endl;
   Square square(10);
   std::cout << "Square: " << square.area() << std::endl;
   Rhombus rhombus(2,22);
   std::cout << "Rhombus: " << rhombus.area() << std::endl;
   std::cout << "\n";
}

void task2() {
    std::cout << "task2:\n";
    Car car("C1", "M1");
    PessengerCar pessenger_car("C2, M2");
    Bus bus("C3", "M3");
    Minivan minivan("C4", "M4");
    std::cout << "\n";
}

void task3() {
    std::cout << "task3:\n";
    SimpleFraction sf1(2,3);
    SimpleFraction sf2(4,5);
    SimpleFraction sf3 = sf1 + sf2;
    sf3.print();


    MixedFraction mf1(1,2,3);
    MixedFraction mf2(5,8,12);
    MixedFraction mf3 = mf1 + mf2;
    mf3.print();
    std::cout << "\n";
}

int main () {
    task1();
    task2();
    task3();
    return 0;
}

