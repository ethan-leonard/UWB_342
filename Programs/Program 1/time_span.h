#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

#include <iostream>

class TimeSpan {
    private:
        // Vars
        int hours_;
        int minutes_;
        int seconds_;

    public:
        // Constructors
        TimeSpan();
        TimeSpan(double hours, double minutes, double seconds);
        TimeSpan(double minutes, double seconds);
        TimeSpan(double minutes);

        // Setters and Getters
        int hours() const;
        int minutes() const;
        int seconds() const;

        void set_time(int hours, int minutes, int seconds);

        // Function to convert seconds into time values
        void recalculateTime(int seconds);

        // Operators 
        TimeSpan operator+(const TimeSpan &obj) const;
        TimeSpan operator-(const TimeSpan &obj) const;
        TimeSpan operator-() const;
        TimeSpan &operator+=(const TimeSpan &obj);
        TimeSpan &operator-=(const TimeSpan &obj);

        bool operator==(const TimeSpan &obj) const;
        bool operator!=(const TimeSpan &obj) const;
        bool operator<(const TimeSpan &obj) const;
        bool operator<=(const TimeSpan &obj) const;
        bool operator>(const TimeSpan &obj) const;
        bool operator>=(const TimeSpan &obj) const;

        // Stream Input & Output
        friend std::istream &operator>>(std::istream &in, TimeSpan &obj);
        friend std::ostream &operator<<(std::ostream &out, const TimeSpan &obj);
};

#endif