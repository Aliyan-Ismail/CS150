/**
 *  @author Put your name here
 *  @date Put the date here
 *  @file h18.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cctype>
using namespace std;

string STUDENT = "aismail9"; // Add your Canvas/occ-email ID

#include "h18.h"

// Place your function here
string clean(string& str)
{
    string result;
    for (char ch : str)
    {
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || isdigit(ch))
        {
            if (!islower(ch))
            {
                result += tolower(ch);
            }
            else
            {
                result += ch;
            }
        }
    }
    return result;
}

vector<Word> spellCheck(istream& in, const vector<string>& dictionary, const vector<string>& excluded)
{
    vector <Word> result;
    
    while (in)
    {
        pos_type currentPos = in.tellg();
        if (currentPos == -1) break;
        string word;
        in >> word >> ws;
        word = clean(word);
        bool cont = false;
        
        for (int i = 0, len = result.size(); i < len; i++)
        {
            if (word == result.at(i).word)
            {
                result.at(i).positions.push_back(currentPos);
                cont = true;
                break;
            }
        }
        
        if (cont) continue;
        
        for (int i = 0, len = excluded.size(); i < len; i++)
        {
            if (word == excluded.at(i))
            {
                cont = true;
                break;
            }
        }
        
        if (cont) continue;
        
        for (int i = 0, len = dictionary.size(); i < len; i++)
        {
            if (word == dictionary.at(i))
            {
                cont = true;
                break;
            }
        }
        
        if (cont) continue;
        
        vector<pos_type> newPositions{currentPos};
        Word newWord{word, newPositions};
        result.push_back(newWord);
    }
    return result;
}


/////////////// STUDENT TESTING ////////////////////
vector<string> fileToWords(const string& filename);
#include <sstream>
#include <iomanip>
int run()
{
    cout << "Student testing" << endl;
    // vector<string> dictionary = fileToWords("words");
    // vector<string> ignore = fileToWords("excluded.txt");
    // istringstream words("Now is the tyme for all good studunts to "
    //     "come to the aiid of their ai!id classmaates.");
    // vector<Word> misspelled = spellCheck(words, dictionary, ignore);
    // cout << "Misspelled words" << endl;
    // int i{1};
    // for (const auto& e : misspelled)
    // {
    //     cout << setw(4) << i++ << ". " << e.word << ", [ ";
    //     for (auto pos : e.positions)
    //         cout << pos << " ";
    //     cout << "]" << endl;
    // }

    return 0;
}