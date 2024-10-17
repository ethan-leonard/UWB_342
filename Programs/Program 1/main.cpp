#include <iostream>
#include <sstream>
#include "time_span.h"
using namespace std;

// Checker function to compare expected values with actual values
bool CheckValues(TimeSpan time, int hours, int minutes, int seconds)
{
    if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds() != seconds)) {
        return false;
    }
    return true;
}

// Tests 0 case
bool TestZeros()
{
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

// Tests for decimal seconds
bool TestFloatSeconds()
{
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

// Tests for negative minutes
bool TestNegativeMinute()
{
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

// Tests for negative hours
bool TestNegativeHour()
{
    TimeSpan ts(-1, 30, 0);
    return CheckValues(ts, 0, -30, 0);
}

// Tests the adding function
bool TestAdd()
{
    TimeSpan ts1, ts2(5), ts3(7, 0), ts4(4, 0, 0);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 4, 7, 5);
}

// Tests the += operator
bool TestAddInPlace()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1))) {
        return false;
    }
    ts1 += ts2;
    if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1))) {
        return false;
    }
    return true;
}

// Tests subtraction
bool TestSubtract()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    TimeSpan result = ts1 - ts2;
    return CheckValues(result, 4, 5, 6);
}

// Tests the -= operator 
bool TestSubtractInPlace()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    ts1 -= ts2;
    return CheckValues(ts1, 4, 5, 6);
}

// Tests the == operator
bool TestEquality()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(5, 6, 7);
    return ts1 == ts2;
}

// Tests the != operator
bool TestInequality()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    return ts1 != ts2;
}

// Tests the >, <, >=, and <= operators
bool TestComparison()
{
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    return (ts1 > ts2) && (ts2 < ts1) && (ts1 >= ts2) && (ts2 <= ts1);
}

// Tests the ostream operator
bool TestOStream()
{
    TimeSpan ts(1, 2, 3);
    std::stringstream ss;
    ss << ts;
    return ss.str() == "Hours: 1, Minutes: 2, Seconds: 3";
}

// Tests the istream operator
bool TestIStream()
{
    TimeSpan ts;
    std::stringstream ss("4 5 6");
    ss >> ts;
    return CheckValues(ts, 4, 5, 6);
}

// main
int main()
{
    cout << "Testing TimeSpan Class" << endl;
    if (!TestZeros()) cout << "Failed: TestZeros" << endl;
    if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
    if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
    if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
    if (!TestAdd()) cout << "Failed: TestAdd" << endl;
    if (!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
    if (!TestSubtract()) cout << "Failed: TestSubtract" << endl;
    if (!TestSubtractInPlace()) cout << "Failed: TestSubtractInPlace" << endl;
    if (!TestEquality()) cout << "Failed: TestEquality" << endl;
    if (!TestInequality()) cout << "Failed: TestInequality" << endl;
    if (!TestComparison()) cout << "Failed: TestComparison" << endl;
    cout << "Testing Complete" << endl;
    return 0;
}