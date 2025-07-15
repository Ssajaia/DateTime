#include "datetime.h"

static const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonthFor(int year, int month) {
    if (month == 2 && isLeapYear(year)) return 29;
    return daysInMonth[month - 1];
}

DateTime::DateTime(int second,int minute, int hour,int day, int month,int year){
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

DateTime::DateTime(int second,int minute, int hour){
    this->second= second;
    this->minute = minute;
    this->hour = hour;
}

std::ostream& DateTime::display(std::ostream& os) const {
    os << year << "-" << month << "-" << day << " "
       << hour << ":" << minute << ":" << second;
    return os;
}

std::istream& operator>>(std::istream& is, DateTime& dt) {
    is >> dt.year >> dt.month >> dt.day >> dt.hour >> dt.minute >> dt.second;
    return is;
}

DateTime& DateTime::operator=(const DateTime& other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
        hour = other.hour;
        minute = other.minute;
        second = other.second;
    }
    return *this;
}

bool DateTime::operator==(const DateTime& other) const {
    return year == other.year && month == other.month && day == other.day &&
           hour == other.hour && minute == other.minute && second == other.second;
}

bool DateTime::operator!=(const DateTime& other) const {
    return !(*this == other);
}

bool DateTime::operator<(const DateTime& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    if (day != other.day) return day < other.day;
    if (hour != other.hour) return hour < other.hour;
    if (minute != other.minute) return minute < other.minute;
    return second < other.second;
}

bool DateTime::operator<=(const DateTime& other) const {
    return *this < other || *this == other;
}

bool DateTime::operator>(const DateTime& other) const {
    return !(*this <= other);
}

bool DateTime::operator>=(const DateTime& other) const {
    return !(*this < other);
}

DateTime DateTime::operator+(const DateTime& other) const {
    return DateTime(second + other.second, minute + other.minute, hour + other.hour,
                    day + other.day, month + other.month, year + other.year);
}

DateTime DateTime::operator-(const DateTime& other) const {
    return DateTime(second - other.second, minute - other.minute, hour - other.hour,
                    day - other.day, month - other.month, year - other.year);
}

DateTime& DateTime::operator+=(const DateTime& other) {
    second += other.second;
    minute += other.minute;
    hour += other.hour;
    day += other.day;
    month += other.month;
    year += other.year;
    return *this;
}

DateTime& DateTime::operator-=(const DateTime& other) {
    second -= other.second;
    minute -= other.minute;
    hour -= other.hour;
    day -= other.day;
    month -= other.month;
    year -= other.year;
    return *this;
}

DateTime& DateTime::operator++() {
    ++second;
    if (second >= 60) {
        second = 0;
        ++minute;
        if (minute >= 60) {
            minute = 0;
            ++hour;
            if (hour >= 24) {
                hour = 0;
                ++day;
            }
        }
    }
    return *this;
}

DateTime& DateTime::operator--() {
    --second;
    if (second < 0) {
        second = 59;
        --minute;
        if (minute < 0) {
            minute = 59;
            --hour;
            if (hour < 0) {
                hour = 23;
                --day;
            }
        }
    }
    return *this;
}

DateTime& DateTime::operator/(const DateTime& other) {
    if (other < *this) {
        *this = DateTime(0,0,0,0,0,0);
        return *this;
    }

    int sec = other.second - second;
    int min = other.minute - minute;
    int hr  = other.hour - hour;
    int d   = other.day - day;
    int m   = other.month - month;
    int y   = other.year - year;

    if (sec < 0) {
        sec += 60;
        min -= 1;
    }
    if (min < 0) {
        min += 60;
        hr -= 1;
    }
    if (hr < 0) {
        hr += 24;
        d -= 1;
    }
    if (d < 0) {
        m -= 1;
        int prevMonth = (other.month == 1) ? 12 : other.month - 1;
        int prevYear = (other.month == 1) ? other.year - 1 : other.year;
        d += daysInMonthFor(prevYear, prevMonth);
    }
    if (m < 0) {
        m += 12;
        y -= 1;
    }
    if (y < 0) {
        y = m = d = hr = min = sec = 0;
    }

    *this = DateTime(sec, min, hr, d, m, y);
    return *this;
}
