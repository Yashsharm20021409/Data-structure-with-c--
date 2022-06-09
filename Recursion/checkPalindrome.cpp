#include <iostream>
using namespace std;

// bool checkPalindrome(string str, int i, int j)
// {

//     // base case
//     if (i > j)
//     {
//         return true;
//     }

//     if (str[i] != str[j])
//     {
//         return false;
//     }
//     else
//     {
//         return checkPalindrome(str, i + 1, j - 1);
//     }
// }

// optimize code by using single pointer

bool checkPalindrome(string str, int i)
{

    // base case
    if (i > str.length()-1-i)
    {
        return true;
    }

    if (str[i] != str[str.length()-1-i])
    {
        return false;
    }
    else
    {
        return checkPalindrome(str, i + 1);
    }
}

int main()
{
    string str = "abbaa";

    // bool isPalindrome = checkPalindrome(str, 0, str.length() - 1);

    // optimize the code by using single pointer
    bool isPalindrome = checkPalindrome(str, 0);

    cout << endl;
    if (isPalindrome)
    {
        cout << "String is Palindrome" << endl;
    }
    else
    {
        cout << "String is not a palindrome" << endl;
    }
}