#include <iostream>
#include <memory>

class Date {
public:
    Date(int day = 1, int month = 1, int year = 1990): m_day(day), m_month(month), m_year(year)
    {}
    friend std::ostream& operator<< (std::ostream& out, const Date& date); 
    friend bool operator< (const Date& date1, const Date& date2);
    friend bool operator> (const Date& date1, const Date& date2);
    friend bool operator<= (const Date& date1, const Date& date2);
    friend bool operator>= (const Date& date1, const Date& date2);
    friend bool operator== (const Date& date1, const Date& date2);
    friend bool operator!= (const Date& date1, const Date& date2);

    void set_day(int day) {
        m_day = day;
    }
    void set_month(int month) {
        m_month = month;
    }
    void set_year(int year) {
        m_year = year;
    }
private:
    int m_day;
    int m_month;
    int m_year;
};


std::ostream& operator<< (std::ostream& out, const Date& date) {
    out << date.m_day << "/" << date.m_month << "/" << date.m_year;
    return out;
}

bool operator== (const Date& date1, const Date& date2) {
    return date1.m_day == date2.m_day && date1.m_month == date2.m_month && date1.m_year == date2.m_year;
}
bool operator!= (const Date& date1, const Date& date2) {
    return !(date1 == date2);
}

bool operator< (const Date& date1, const Date& date2) {
    return date1.m_year < date2.m_year || (date1.m_year == date2.m_year && (date1.m_month < date2.m_month ||
      (date1.m_month == date2.m_month && date1.m_day < date1.m_day))); 
}

bool operator<= (const Date& date1, const Date& date2) {
    return date1 < date2 || date1 == date2;
}

bool operator> (const Date& date1, const Date& date2) {
    return !(date1 <= date2);
}

bool operator>= (const Date& date1, const Date& date2) {
    return date1 > date2 || date1 == date2;
}

std::shared_ptr<Date> comare(std::shared_ptr<Date> date1, std::shared_ptr<Date> date2) {
    return date1 < date2 ? date2 : date1;
}

void swapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2) {
    std::shared_ptr<Date> tmp = date2;
    date2 = std::move(date1);
    date1 = std::move(tmp);
}

void task1() {
    std::cout << "task1\n";
    std::unique_ptr<Date> today(new Date);
    std::unique_ptr<Date> date;
    today->set_day(1);
    today->set_month(8);
    today->set_year(2019);
    std::cout << *today << std::endl;
    date = std::move(today);
    if (date) 
        std::cout << "date not null\n";
    else 
        std::cout << "date is null\n"; 

    if (today)
        std::cout << "today not null\n";
    else 
        std::cout << "today is null\n";
}

void task2() {
    std::cout << "task2:\n";
    std::shared_ptr<Date> date1(new Date(1, 30, 1991));
    std::shared_ptr<Date> date2(new Date(2, 18, 2001));
    std::shared_ptr<Date> date3 = comare(date1, date2);
    std::cout << *date3 << std::endl;
    swapDate(date1, date2);
    std::cout << "date1: " << *date1 << std::endl;
    std::cout << "date2: " << *date2 << std::endl;
 }

int main() {
    task1();
    task2();
}
