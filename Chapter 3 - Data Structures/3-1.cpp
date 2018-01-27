#include <iostream>
#include <string>

using namespace std;

/*
    A common problem for compilers and text editors is determining whether the
    parentheses in a string are balanced and properly nested. For example, the string
    ((())())() contains properly nested pairs of parentheses, which the strings )()( and
    ()) do not. Give an algorithm that returns true if a string contains properly nested
    and balanced parentheses, and false if otherwise. For full credit, identify the position
    of the first offending parenthesis if the string is not properly nested and balanced.
*/

int main()
{
    // the idea to increment and decrement the variables below when left or right parentheses occur
    // (and to maintain a variable that keeps track of the last seen parentheses) is bad because of this example - "((())())()"

    // maybe it has something to do with grammars?

    // will get back to this

    int leftParenthesesCount = 0;
    int rightParenthesesCount = 0;
    string test;
    cin >> test;
    for (int i = 0; i < test.length(); i++)
    {

    }
    return 0;
}
