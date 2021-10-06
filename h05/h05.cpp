/**
 *  @author Aliyan Ismaill
 *  @date Spring 2021 WPM
 *  @file h05.cpp
 */
#include <string>
using namespace std;

string STUDENT = "aismail9";  // Add your Canvas login name

/**
 * Country end in letter e or o? Feminine prefix->la (space)
 * Otherwise? Masculine prefix->le (space)
 * With these exceptions
 * Belize Cambodge Mexique Mozambique Zaire Zimbabwe (all le)
 * Starts with a vowel? prefix l' (no space)
 * Plural? prefix is les (space)
 * Israel, Madagascar, Sri Lanka, Singapore, Monaco,
 * Cuba and Cyprus have no prefix.
*/

// Write your function here
string toFrenchGender(const string& country)
{
    string result;
    string mas = "le ";
    string fem = "la ";
    string vowel = "l'";
    string plural = "les ";
    int firstWord = country.find_first_of(" \t\n");

    if (country == "Belize" || country == "Cambodge" || country == "Mexique" || country == "Mozambique" || country == "Zaire" || country == "Zimbabwe")
    {
        result = mas + country;
    }
    else if (country == "Israel" || country == "Madagascar" || country == "Sri Lanka" || country == "Singapore" || country == "Monaco" || country == "Cuba" || country == "Cyprus")
    {
        result = country;
    }
    else if (country == "Honduras")
    {
        result = mas + country;
    }
    else if (country.substr(country.size() - 2, 2) == "es" || country.substr(country.size() - 2, 2) == "is" || country.substr(country.size() - 2, 2) == "as" || country.substr(country.size() - 2, 2) == "os" || country.substr(0, firstWord) == "iles")
    {
        result = plural + country;
    }
    else if (country.substr(0, 1) == "A" || country.substr(0, 1) == "E" || country.substr(0, 1) == "I" || country.substr(0, 1) == "O" || country.substr(0, 1) == "U")
    {
        result = vowel + country;
    }
    else if (country.substr(country.size() - 1, 1) == "e" || country.substr(country.size() - 1, 1) == "o")
    {
        result = fem + country;
    }
    else {
        result = mas + country;
    }

    return result;
}


/////////////// Optional Student Code /////////////////
int run()
{
    // You may add any code you like
    // It will be displayed with make run
    return 0;
}
