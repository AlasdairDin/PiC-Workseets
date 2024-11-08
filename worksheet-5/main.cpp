// Worksheet 5

#include "cipher.hpp"
#include <iostream>

using namespace std;
//-----------------------------------------------------------------
// Task 1 - Implement the name_to_initials function
// This function should return the user’s initials (i.e., the first letter of each word in their name) with no spaces.

// You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus spaces.
// You don’t need to worry about punctuated names like Augusta Ada King-Noel, Conan O’Brien, or David J. Malan!

//But the user’s input might be sloppy! In which case there might be one or more spaces at the start and/or end
// of the user’s input or even multiple spaces in a row. You should correctly provide Initials in these cases.
//-----------------------------------------------------------------

std::string name_to_initials(std::string name)
{
    std::string output = " ";

    if (name[0] != ' ')
        output += name[0];

    for (int i = 0; i < name.length() - 1; i++)
    {
        if (name[i] == ' ' && name[i + 1] != ' ')
        {
            output += name[i + 1];
        }
    }
    name = output;

    return name;
}

//-----------------------------------------------------------------
// Task 2 - Caesar Cypher
// Implement the set_shift and encode functions

// Set shift provides you with the shift value from the web interface.
// You should use this value to set your own variable that can be used in the encode function to
// indicate how many latters to shift. (Hint: think about the scope of this variable to ensure it can be used)

// The encode function recieves a the message from the web interface to be encoded and should return the encoded output.
//-----------------------------------------------------------------

int shift;
void set_shift(unsigned int value)
{
    std::cout << value << '\n';
    shift = value;
}
string encode(string message)
{
    string encodedmessage = "";
    for (int i = 0; i != message.length(); i++)
    {
        int conversion = int(message[i]);
        if (conversion >= 65 && conversion <= 90)
        {
            conversion = conversion - 65;
            conversion = conversion + shift;
            conversion = conversion % 26;
            conversion = conversion + 65;
            conversion = char(conversion);
            encodedmessage.push_back(conversion);
        }
        else if (conversion >= 97 && conversion <= 122)
        {
            conversion = conversion - 97;
            conversion = conversion + shift;
            conversion = conversion % 26;
            conversion = conversion + 97;
            conversion = char(conversion);
            encodedmessage.push_back(conversion);
        }
        else
        {
            encodedmessage.push_back(message[i]);
        }
    }
    return encodedmessage;
}

//-----------------------------------------------------------------
// Task 3 - Substitution Cypher
// Implement substitution_set and substitution_encode functions

// substitution_set provides a substituion string from the web interface.
// You should use this string to set your own variable that can be used in the substitution_encode function to
// indicate what letters are substituded for what. (Hint: think about the scope of this variable to ensure it can be used)

// The substitution_encode function recieves a the string message from the web interface to be encoded and should return the substituted/cyphered output.
//-----------------------------------------------------------------

string letters = "abcdefghijklmnopqrstuvwxyz";

void substitution_set(string sub)
{
    cout << sub << '\n';
    for (int i = 0; i < sub.length(); i++)
    {
        letters[i] = sub[i];
    }
}

string substitution_encode(string message)
{
    for (int i = 0; i < message.length(); i++)
    {
        int asciiNum = int(message[i]);

        if (asciiNum >= 97 && asciiNum <= 122)
        {
            asciiNum = asciiNum - 97;
            message[i] = letters[asciiNum];
        }
        else if (asciiNum >= 65 && asciiNum <= 90)
        {
            asciiNum = asciiNum - 65;
            message[i] = letters[asciiNum];
        }
    }
    return message;
}

//Nothing to do here, main just runs the project which is defined elsewhere for you...
// run() will call your functions as appropriate.
int main(int argc, char **argv)
{
    run(argc, argv);
}
