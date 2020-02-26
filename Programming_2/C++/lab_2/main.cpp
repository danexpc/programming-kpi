#include <iostream>
#include "MyString.h"
#include "Text.h"
using namespace std;


int main() {
    char* arr = new char[4]{'f', 'g', 'h', '\0'};
    MyString str1(arr);
    MyString str2("     wef        ef  sd    ");
    MyString str3(" erv  dgdfd fvsd ");
    MyString str4(" edsg fvsd ");

    Text txt(vector<MyString>{str1, str2, str3});
    //txt.PrintText();
    txt.AddLine(str4);
    //txt.PrintText();
    txt.DeleteLine(3);
    //txt.PrintText();
    txt.deleteExtraSpace();
    txt.deleteBeginEndSpace();
    //txt.PrintText();
    cout << txt.TheShortestLine() << endl;
    cout << txt.PercentConsonantLetter();
    txt.Clear();
    txt.PrintText();
    return 0;
}
