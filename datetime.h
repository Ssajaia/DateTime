#include <iostream>
#pragma once

class DateTime {
public:
    DateTime(int second,int minute, int hour,int day, int month,int year  );
    DateTime(int second,int minute, int hour);
    DateTime(){};
    std::ostream& display(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream& os, const DateTime& dt){return dt.display(os);};
    friend std::istream& operator>>(std::istream& is, DateTime& dt);

    DateTime& operator=(const DateTime& other);
    bool operator==(const DateTime& other) const;
    bool operator!=(const DateTime& other) const;
    bool operator<(const DateTime& other) const;
    bool operator<=(const DateTime& other) const;
    bool operator>(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
    DateTime operator+(const DateTime& other) const;
    DateTime operator-(const DateTime& other) const;
    DateTime& operator+=(const DateTime& other);
    DateTime& operator-=(const DateTime& other);
    DateTime& operator++();
    DateTime& operator--();
    DateTime& operator/(const DateTime& other);

    int year=0;
    int month=0;
    int day=0;
    int hour=0;
    int minute=0;
    int second=0;
};
