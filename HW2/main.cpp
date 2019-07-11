#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <string>

class Random {
public:
    Random(): m_current_value(0), m_is_curr_val_init(false),
      m_rand_min(0), m_rand_max(100) {}
   
    Random(int rand_max): Random() 
    {
        if (rand_max <= m_rand_min) {
            throw "Error: Max rand value <= min rand value!";
        } 
        m_rand_max = rand_max;
    }
   
    Random(int rand_min, int rand_max): Random() 
    {
        if (rand_max <= rand_min) {
            throw "Error: Max rand value <= min rand value!";
        } 
        m_rand_min = rand_min;
        m_rand_max = rand_max;
    }

    Random(const Random& random): m_current_value(random.m_current_value),
      m_is_curr_val_init(random.m_is_curr_val_init), m_rand_min(random.m_rand_min),
      m_rand_max(random.m_rand_max)
    {}
  
    static void set_seed(unsigned int seed) {
        srand(seed);
    }

    void set_max(int max) {
        m_rand_max = max;
    }
    void set_min(int min) {
        m_rand_min = min;
    }

    int Current() const {
        if (!m_current_value) {
            throw "Random value is not generate!";
        }
        return m_current_value;
    }

    int Next() const {
        if (!m_is_curr_val_init) {
            m_is_curr_val_init = true;
        }
        m_current_value = (rand() % (m_rand_max - m_rand_min))  + m_rand_min;
        return m_current_value;
    }

    void print() const {
        std::cout << "m_current_value: " << m_current_value << "\n";
        std::cout << "m_is_curr_val_init: " << m_is_curr_val_init << "\n";
        std::cout << "m_rand_min: " << m_rand_min << "\n";
        std::cout << "m_rand_max: " << m_rand_max << "\n";
    }
private:
    mutable int m_current_value;
    mutable bool m_is_curr_val_init;    
    int m_rand_min;
    int m_rand_max;
};


class Person {
public:
    Person() {}

    void set_name (std::string name) {
        m_name = name;
    }

    void set_age(int age) {
        m_age = age;
    }

    void set_sex(char sex) {
        m_sex = sex;
    }

    void set_weight(int weight) {
        m_weight = weight;
    }

private:
    std::string m_name;
    int m_age;
    char m_sex;
    int m_weight;
};

class Student: public Person {
public:
    Student() {}

    void set_stud_year (int year) {
        m_stud_year = year;
    }

    void inc_stud_year (int year) {
        m_stud_year += year;
    }

    void print() {
        std::cout << "m_stud_year: " << m_stud_year << "\n";
    }
private:
    int m_stud_year;
};

class Fruit {
public:
    Fruit() {}
    Fruit(std::string name, std::string color): m_name(name), m_color(color) {}

    std::string get_name() const {
        return m_name;
    }

    std::string get_color() const {
        return m_color;
    }

    void set_name(std::string name) {
        m_name = name;
    }

    void set_color(std::string color) {
        m_color = color;
    }

private:
    std::string m_name;
    std::string m_color;
};

class Apple: public Fruit {
public:
    Apple(): Fruit("Apple", "green") {}
    Apple(std::string color): Fruit("Aapple", color) {}
};


class Banana: public Fruit {
public:
    Banana(): Fruit("Banana", "yellow") {}
    Banana(std::string color): Fruit("Banana", color) {}
};

class GrannySmith: public Apple {
public:
    GrannySmith(): Apple("green") {
        set_name("Granny Smith apple");
    }
    GrannySmith(std::string color): Apple(color) {
        set_name("Granny Smith apple");
    }
};

void task1() {
    std::cout << "task1\n";
    Random::set_seed(time(NULL));

    Random random1(5,23);
    try {
        random1.Current();
    } catch (const char* str) {
        std::cout << str << std::endl;
    }

    std::cout << "Rand1: " << random1.Next() << "\n";
    std::cout << "Rand1: " << random1.Current() << "\n";
    std::cout << "Print Rand1:\n";
    random1.print();
    
    const Random random2(random1);
    std::cout << "Print Rand2:\n";
    random2.print();
}

void task2() {
    std::cout << "task2\n";
    Student student;
    student.set_stud_year(1900);
    student.inc_stud_year(10);
    student.print();
}

void task3() {
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.get_name() << " is " << a.get_color() << ".\n";
    std::cout << "My " << b.get_name() << " is " << b.get_color() << ".\n";
    std::cout << "My " << c.get_name() << " is " << c.get_color() << ".\n";
}


int main (int argc, char **argv) {
    task1();
    task2();
    task3();
    return 0;
}