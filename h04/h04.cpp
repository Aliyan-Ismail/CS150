/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 WPM
 *  @file h04.cpp
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string STUDENT = "aismail9";  // Add your Canvas login name
extern string ASSIGNMENT;

// Add your function declaration here
string getStatus(double gpa, int credits, int hCredits);

/**
 * Students must have completed at least 180 credits with a GPA of at least
2.0 to graduate. A student who does not meet both of these constraints
should receive a return value of "not graduating".
Students who do have enough credits to graduate and sufficiently high
GPAs will receive one of four return values depending on the GPA and
number of honors credits:
All students with GPAs between 2.0 and 3.6 receive a return value of
"graduating".
Students with fewer than 15 honors credits receive a return of "cum
laude" if their GPA is at least 3.6 but less than 3.8, and a return of
"magna cum laude" if their GPA is at least 3.8.
Students with 15 or more honors credits receive a return of "magna
cum laude" if their GPA is at least 3.6 but less than 3.8, and a return of
"summa cum laude" if their GPA is at least 3.8.
 * @return 0 for success.
 */
int run()
{
	// DON'T CHANGE ANYTHING IN THIS FUNCTION
    cout << STUDENT << "-" << ASSIGNMENT << "-Graduation Calculator" << endl;
	cout << "-----------------------------------------" << endl;

	cout << "Enter gpa, total credits and honors credits: ";
	double gpa;
	int credits, honorsCredits;
	cin >> gpa >> credits >> honorsCredits;

	// You will write this function
	string result = getStatus(gpa, credits, honorsCredits);

	cout << "Result is [\"" << result << "\"]" << endl;

    return 0;
}

// Implement your function here
string getStatus(double gpa, int credits, int hCredits)
{
	string output;
	if (gpa >= 2.0 && credits >= 180)
	{
		if (gpa >= 2.0 && gpa < 3.6)
		{
			output = "graduating";
		}
		else if (hCredits < 15 && (gpa >= 3.6 && gpa < 3.8))
		{
			output = "cum laude";
		}
		else if (hCredits < 15 && gpa >= 3.8)
		{
			output = "magna cum laude";
		}
		else if (hCredits >= 15 && (gpa >= 3.6 && gpa < 3.8))
		{
			output =  "magna cum laude";
		}
		else if (hCredits >= 15 && gpa >= 3.8)
		{
			output = "summa cum laude";
		}
		
	}
	else
	{
		output = "not graduating";
	}
	return output;
}