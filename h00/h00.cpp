/**
 *  @author Aliyan Ismail
 *  @date Spring 2021 MWPM
 *  @file h00.cpp
 */
#include <iostream>
#include <string>
using namespace std;

string STUDENT = "aismail9";  // Add your Canvas login name
extern string ASSIGNMENT;

/**
 * A metric ton is 35,273.92 ounces.
 * Write a program that will read the
 * weight of a package of breakfast cereal
 * in ounces and output the weight
 * in metric tons as well as the number of
 * boxes needed to yield one metric ton of cereal.
 * --Savitch, Absolute C++ 5th Edition, Chapter 2
 * @return 0 for success.
 */
int run()
{
    // Input - weight of a box of cereal
    // Output - weight in metric tons
    // Output - boxes in one ton
    // Given - ounces per ton -> 35,273.92
    // Calculate: weight -> weight oz / oz per ton
    // Calculate: boxes per ton -> 1.0 / weight in tons

    //Mockup
    // Heading
    cout << STUDENT << "-" << ASSIGNMENT << ": ";
    cout << "Cereal Box Calculator" << endl;
    cout << string(50, '-') << endl;

    // Prompt & Input
    cout << "Enter ounces per box of cereal: ";
    double ouncesPerBox;
    cin >> ouncesPerBox;
    // cout << 10 << endl; // dmmy data that we'll remove

    // Processing
    const double OZ_PER_TON = 35273.92;
    double weightInTons(ouncesPerBox / OZ_PER_TON);
    double boxesPerTon(1.0 / weightInTons);

    // Output Line
    cout << "Weight in metric tons, boxes per ton: [";
    cout << weightInTons << ", " << boxesPerTon << "]" << endl;

    return 0;
}

