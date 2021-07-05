#include <bits/stdc++.h>
using namespace std;

bool isLeftBrackets(char ch)
{
    return ch=='(' || ch=='<' || ch=='[' || ch=='{';
}

bool isRightBrackets(char ch)
{
    return ch==')' || ch=='>' || ch==']' || ch=='}';
}

bool isMatch(char ch1, char ch2)
{
    return (ch1=='(' && ch2==')') || (ch1=='<' && ch2=='>') ||
           (ch1=='[' && ch2==']') || (ch1=='{' && ch2=='}');
}

bool bracketsMatch(const string& exp)
{
    stack<char> left_brackets;
    for(auto ch : exp){
        if( isLeftBrackets(ch) )
            left_brackets.push(ch);
        else if( isRightBrackets(ch) ){
            if( !left_brackets.empty() ){
                if( isMatch(left_brackets.top(), ch) )
                    left_brackets.pop();
                else
                    return false;
            }else{
                return false;
            }
        }
    }
    return left_brackets.empty() ? true : false;
}

int main()
{
    string expression1 = "{3*2 + {a[4]-b[5] / func(2,3)*{1,2,3}} - vector<int>}";
    string expression2 = " 3*2 + {a[4]-b[5] / func(2,3)*{1,2,3}} - vector<int>}";
    if( bracketsMatch(expression2) )
        cout << "Match!\n";
    else
        cout << "Not match!\n";

    return 0;
}