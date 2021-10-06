/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 MWPM
 *  @file h01.cpp
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

string STUDENT = "aismail9";  // Add your Canvas login name
extern string ASSIGNMENT;


/**
 * Write a program that adds and subtracts time.
 * It should ask the user for two input values —
 * a time (like 3:57) and duration (such as 1:05).
 * Then, print the sum (here 5:02) and difference (2:52)
 * @return 0 for success.
 */
int run()
{
    // Input - Time in hours
    // Input - Time in minutes
    // Input - Duration hours
    // Input - Duration minutes
    // Output - After time in hours
    // Output - After time in minutes
    // Output - Before time in hours
    // Output - Before time in minutes
    // Calculate - After time -> initial time + duration
    // Calculate - Before time -> initial time - duration

    // Mockup
    // Heading
    // Title and introduction
    cout << STUDENT << "-" << ASSIGNMENT << ": ";
    cout << "Time on My Hands" << endl;
    cout << string(50, '-') << endl;
    cout << "Give me a time (such as 3:57) and a duration"
        << " (such as 1:05), and I'll tell you the sum"
        << " (that is, the time that follows the given time"
        << " by the given duration), and difference (the time that"
        << " precedes the given time by that duration)" << endl;

    // Prompt and Input
    cout << "Time: ";
    int timeHours;
    char discard;
    int timeMin;
    cin >> timeHours;
    cin >> discard;
    cin >> timeMin;

    int initialTime = (timeHours * 60) + timeMin;

    cout << "Duration: ";
    int durationHours;
    char discard2;
    int durationMin;
    cin >> durationHours;
    cin >> discard2;
    cin >> durationMin;

    int durationTime = ((durationHours * 60) + durationMin);

    // Processing
    int after = initialTime + durationTime;
    int before = abs(initialTime - durationTime + 2160);



    // Output
    cout << setfill('0');
    cout << durationTime / 60 << discard << setw(2) << durationTime % 60
        << " hours after, and before, "
        << initialTime / 60 << discard << setw(2) << initialTime % 60 << " is ["
        << ((((after / 60) % 12) + 11) % 12) + 1 << discard << setw(2) << after % 60 << ", "
        << ((((before / 60) % 12) + 11) % 12) + 1 << discard << setw(2) << before % 60 << "]" << endl;


    return 0;
}
