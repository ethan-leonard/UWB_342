#include <iostream>
#include <cmath>
#include "time_span.h"

// Recalculate time from total seconds
void TimeSpan::recalculateTime(int seconds) {
    // Convert total seconds to hours, minutes, and seconds
    hours_ = seconds / 3600; 
    int temp = seconds % 3600;  
    minutes_ = temp / 60;
    seconds_ = temp % 60;

    // Reset range for seconds (-59 to 59)
    if (seconds_ >= 60 || seconds_ <= -60) {
        minutes_ += seconds_ / 60;
        seconds_ %= 60;
    }

    // Reset range for minutes (-59 to 59)
    if (minutes_ >= 60 || minutes_ <= -60) {
        hours_ += minutes_ / 60;
        minutes_ %= 60;
    }
}

// Converts double to int
int convertToInt(double number) {
    return static_cast<int>(std::round(number));
}

// Default constructor
TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}

// Other constructors 
TimeSpan::TimeSpan(double hours, double minutes, double seconds) {
    // Connvert time to seconds
    double temp = hours*3600.00 + minutes*60.00 + seconds;
    // Make seconds an int
    int sec = convertToInt(temp);
    recalculateTime(sec);
}

TimeSpan::TimeSpan(double minutes, double seconds) {
    // Connvert time to seconds
    double temp = minutes*60.00 + seconds;
    // Make seconds an int
    int sec = convertToInt(temp);
    recalculateTime(sec);
}

TimeSpan::TimeSpan(double seconds) {
    // Make seconds an int
    int sec = convertToInt(seconds); 
    recalculateTime(sec);
}   

// Getters
int TimeSpan::hours() const {
    return hours_;
}

int TimeSpan::minutes() const {
    return minutes_;
}

int TimeSpan::seconds() const {
    return seconds_;
}

// Operators
TimeSpan TimeSpan::operator+(const TimeSpan &obj) const {
    int total = (hours_ + obj.hours_)*3600 + (minutes_ + obj.minutes_)*60 + (seconds_ + obj.seconds_);
    return TimeSpan(total);
}

TimeSpan TimeSpan::operator-(const TimeSpan &obj) const {
    int total = (hours_ - obj.hours_)*3600 + (minutes_ - obj.minutes_)*60 + (seconds_ - obj.seconds_);
    return TimeSpan(total);
}

TimeSpan TimeSpan::operator-() const {
    TimeSpan temp = TimeSpan((-1)*hours_, (-1)*minutes_, (-1)*seconds_);
    return temp;
}

TimeSpan &TimeSpan::operator+=(const TimeSpan &obj) {
    hours_ += obj.hours_;
    minutes_ += obj.minutes_;
    seconds_ += obj.seconds_;
    return *this;
}

TimeSpan &TimeSpan::operator-=(const TimeSpan &obj) {
    hours_ -= obj.hours_;
    minutes_ -= obj.minutes_;
    seconds_ -= obj.seconds_;
    return *this;
}


bool TimeSpan::operator==(const TimeSpan &obj) const {
    if (obj.seconds_ == seconds_ && obj.minutes_ == minutes_ && obj.hours_ == hours_) {
        return true;
    } else {
        return false;
    }
}

bool TimeSpan::operator!=(const TimeSpan &obj) const {
    if (obj.seconds_ != seconds_ || obj.minutes_ != minutes_ || obj.hours_ != hours_) {
        return true;
    } else {
        return false;
    }
}

bool TimeSpan::operator>(const TimeSpan &obj) const {
    if (hours_ != obj.hours_) {
        return hours_ > obj.hours_;
    } else if (minutes_ != obj.minutes_) {
        return minutes_ > obj.minutes_;
    } else {
        return seconds_ > obj.seconds_;
    }
}

bool TimeSpan::operator<(const TimeSpan &obj) const {
        if (hours_ != obj.hours_) {
        return hours_ < obj.hours_;
    } else if (minutes_ != obj.minutes_) {
        return minutes_ < obj.minutes_;
    } else {
        return seconds_ < obj.seconds_;
    }
}  

bool TimeSpan::operator>=(const TimeSpan &obj) const {
    if (hours_ != obj.hours_) {
        return hours_ >= obj.hours_;
    } else if (minutes_ != obj.minutes_) {
        return minutes_ >= obj.minutes_;
    } else {
        return seconds_ >= obj.seconds_;
    }
}

bool TimeSpan::operator<=(const TimeSpan &obj) const {
        if (hours_ != obj.hours_) {
        return hours_ <= obj.hours_;
    } else if (minutes_ != obj.minutes_) {
        return minutes_ <= obj.minutes_;
    } else {
        return seconds_ <= obj.seconds_;
    }
}

// Stream Input and Output
std::istream &operator>>(std::istream &in, TimeSpan &obj) {
    int hours, minutes, seconds;
    in >> hours >> minutes >> seconds;
    obj = TimeSpan(hours, minutes, seconds);
    return in;
}

std::ostream &operator<<(std::ostream &out, const TimeSpan &obj) {
    out << "Hours: " << obj.hours_ << ", Minutes: " << obj.minutes_ << ", Seconds: " << obj.seconds_;
    return out;
}
