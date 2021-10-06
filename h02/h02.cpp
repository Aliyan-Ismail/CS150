/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 MWPM
 *  @file h02.cpp
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

string STUDENT = "aismail9";  // Add your Canvas login name
extern string ASSIGNMENT;

/**
 * A government research lab has concluded that an artificial sweetener
 * commonly used in diet soda will cause death in laboratory mice.
 * A friend of yours is desperate to lose weight but cannot give up soda.
 * Your friend wants to know how much diet soda it is possible to drink
 * without dying as a result. Write a program to supply the answer.
 * @return 0 for success.
 */
int run()
{
    // Input - Amount of artificial sweetener needed to kill a mouse
    // Input - Weight of the mouse
    // Input - Weight of the dieter
    // Output - Lethal dose in grams
    // Output - Lethal dose in cans
    // Given - Diet soda contains one tenth of 1% of artifical sweetener
    // Given - Weight of a can of soda is 350 grams
    // Given - One pound is 454 grams
    // Calculate: Dieter weight in grams -> dieter weight * 454
    // Calculate: Lethal grams -> dieter weight in grams / mouse weight in grams * mouse lethal dose
    // Calculate: Lethal cans -> lethal grams / (soda grams * sweetener amount)

    // Mockup
    // Heading
    cout << STUDENT << "-" << ASSIGNMENT << ": ";
    cout << "A Lethal Dose" << endl;
    cout << string(50, '-') << endl;

    // Prompt & Input
    cout << "Weight of the mouse in grams: ";
    int mouseWeight;
    cin >> mouseWeight;

    cout << "Lethal dose for the mouse (in grams): ";
    int lethalAmt;
    cin >> lethalAmt;

    cout << "Desired weight for the dieter (in pounds): ";
    int dieterWeight;
    cin >> dieterWeight;


    // Processing
    const double SWEET_PER_SODA = 0.001;
    const int SODA_WEIGHT = 350;
    const int POUND = 454;

    double dieterGrams = dieterWeight * POUND;
    double lethalGrams = (dieterGrams / mouseWeight) * lethalAmt;
    double lethalCans = lethalGrams / (SODA_WEIGHT * SWEET_PER_SODA);

    // Output Line
    cout << "Lethal dose in grams, cans is [" << int(round(lethalGrams)) << fixed << ", " << int(round(lethalCans)) << fixed << "]" << endl;


    return 0;
}
