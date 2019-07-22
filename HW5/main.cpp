#include <iostream>
#include <string>

template <class T>
class Pair1 {
public:
    Pair1(T first = T(), T second = T()): m_first(first), m_second(second) {}
    T first() const {
        return m_first;
    }
    T second() const {
        return m_second;
    }

    void set_first(T first) {
        m_first = first;
    }

    void set_second(T second) {
        m_second = second;
    }

private:
    T m_first;
    T m_second;
};


template <class T, class U>
class Pair {
public:
    Pair(T first = T(), U second = U()): m_first(first), m_second(second) {}
    T first() const {
        return m_first;
    }
    U second() const {
        return m_second;
    }

    void set_first(T first) {
        m_first = first;
    }

    void set_second(U second) {
        m_second = second;
    }

private:
    T m_first;
    U m_second;
};

template <class T>
class StringValuePair: public Pair<std::string, T> {
public:
    StringValuePair(std::string first = "", T second = T()): Pair<std::string, T>(first, second) {} 
};

void task1() {
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task2() { 
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task3() {
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}



int main() {
    task1();
    task2();
    task3();
    return 0;
}