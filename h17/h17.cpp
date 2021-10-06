/**
 *  @author Put your name here
 *  @date Put the date here
 *  @file h17.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cctype>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID


#include "h17.h"

// Implement the function here
/**
 *  Opens a file and returns a vector<string> containing words.
 *  @param filename contains the path needed to open the file.
 *  @return a vector<string> of words.
 */
vector<string> fileToWords(const string& filename)
{
    ifstream in(filename);
    if (in.fail()) throw invalid_argument("Incorrect filename");
    vector<string> results;
    string line;
    while (getline(in, line))
    {
        // istringstream input(line);
        // string word;
        // while (input >> word)
        // {
        //     results.push_back(word);
        // }
        results.push_back(line);
        
    }
    return results;
}




/////////////// STUDENT TESTING ////////////////////
int run()
{
    cout << "Student testing" << endl;
    // auto v = fileToWords("excluded.txt");
    // cout << "Excluded words:" << endl;
    // for (auto e : v) cout << " -" << e << endl;
    return 0;
}