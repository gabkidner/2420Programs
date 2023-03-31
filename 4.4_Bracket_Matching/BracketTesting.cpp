#include <iostream>
#include "BracketCheck.h"

using namespace std;

bool check(string , string , bool );

int main()
{
    check ("Easy", "()", true);
    check ("Not Matched", "(}", false);
    check ("Mixed but valid", "({}[])", true);
    check ("Too Many Closing", "({}[])]", false);
    check ("Not Matched", "({)(})", false);
    check ("Too Many Opening", "{()", false);
    check ("Code", "if (num == 7) { cout << num; }", true);
    check ("Bad Code", "if (num == 7)  cout << num; }", false);
    check ("Tons of them", "if((num+02){})(({}}", false);
    check ("Hard", "(({({[]})})){{{([[()]])}}}", true);

    return 0;
}

bool check(string name, string expression, bool shouldBe){
    BracketCheck b(expression);
    if(shouldBe == b.isBalanced()){
        cout << "Passed: " << name << endl;
        return true;
    }
    else{
        cout << "Failed: " << name << " " << b << endl;
    }

    return false;
}
