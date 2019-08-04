#include <iostream>
#include <string>
#include <sstream>

int my_div(int a, int b) {
    if ( b == 0 ) {
        throw "DevisionByZero";
    }
    return a / b;
}

class Ex {
public:
    Ex(double x = 0.0): x(x) {}
    void what() const {
        std::cerr << "Ex: value = " << x << "\n";
    } 
private:
    double x;  
};

class Bar {
public:
    Bar(): y(0) {}
    void set(double a) {
        if ( a + y > 100 ) {
            throw Ex( a + y );
        }
        y = a;
    }
private:
    double y;
};

class Robot {
public:
    Robot(int x = 0, int y = 0): off_the_field(false), x(x), y(y) {}
    bool set_position(int x, int y) {
        if (off_the_field) {
            std::ostringstream err_str;
            err_str << "OffTheField x = " << this->x << " y = " << this->y; 
            throw err_str.str();
        }
        if (x > 10 || x < 0 || y > 10 || y < 0) {
            std::ostringstream err_str;
            err_str << "IllegalCommand x = " << this->x << " y = " << this->y; 
            throw err_str.str();
        }
        this->x = x;
        this->y = y;
    }
    void go_right() try
    {
        set_position(x+1, y);
    } catch(const std::string& ex) {
        throw ex + " go right";
    }
    void go_left() try
    {
        set_position(x-1, y);
    } catch(const std::string& ex) {
        throw ex + " go left";
    }
    void go_top() try
    {
        set_position(x, y+1);
    } catch(const std::string& ex) {
        throw ex + " go top";
    }
    void go_bottom() try
    {
        set_position(x, y-1);
    } catch(const std::string& ex) {
        throw ex + " go bottom";
    }
    void print_position() {
        std::cout << "x = " << x << " y = " << y << "\n";
    }
    void off_field() {
        off_the_field = true;
    }
private:
    bool off_the_field;
    int x;
    int y;
};

void task1() {
    int a, b;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    try {
       int res = my_div(a, b);
        std::cout << "Result is: " << res << "\n";
    } catch (const char* ex) {
        std::cerr << "Error: " << ex << "\n";
    }
}

void task2() {
    Bar bar;
    int n;
    do {
        std::cout << "Enter n: ";
        std::cin >> n;
        try {
            bar.set(n);
        } catch (const Ex& ex) {
            ex.what();
        }
    } while ( n != 0);
}

void task3() {
    Robot robot;
    std::string cmd;
    while(1) {
        try {
            std::cout << "Enter command: \n";
            std::cin >> cmd;
            if (cmd == "RIGHT") {
                robot.go_right();
                robot.print_position();
            } else if ( cmd == "LEFT") {
                robot.go_left();
                robot.print_position();
            } else if ( cmd == "TOP") {
                robot.go_top();
                robot.print_position();
            } else if ( cmd == "BOTTOM") {
                robot.go_bottom();
                robot.print_position();
            } else if ( cmd == "OFF_FIELD") {
                robot.off_field();
            } else if ( cmd == "EXIT") {
                break;
            }
        } catch (const std::string& err_str) {
            std::cerr << err_str << "\n";
        }
    }
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}