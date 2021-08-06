#include <bits/stdc++.h>
using namespace std;

void infixToSuffix(string str, vector<string>& output)
{
    static map<char, int> op_priority{ make_pair('+', 1), make_pair('-', 1),
        make_pair('*', 2), make_pair('/', 2), make_pair('%', 2) };

    stack<char> opStk;
    //  删除str中所有空格
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    for(int i = 0; i < str.size(); ){
        char ch = str[i];
        if( isdigit(ch) ){
            int j = i + 1;  
            while( j<str.size() && isdigit(str[j]) )
                ++j;
            output.emplace_back( str.substr(i, j-i) );
            i = j;
        }else{
            //  若为符号
            if( ch == '(' ) opStk.push('(');
            else if( ch == ')' ){
                bool find = false;
                while( !opStk.empty() ){
                    if( opStk.top() == '(' ){
                        find = true;
                        opStk.pop();
                        break;
                    }
                    output.emplace_back( string(1, opStk.top()) );
                    opStk.pop();
                }
                if( !find )
                    assert("no ( match )!" == "");
            }else{
                while( !opStk.empty() && (op_priority[ch] <= op_priority[opStk.top()]) ){
                    output.emplace_back( string(1, opStk.top()) );
                    opStk.pop();
                }
                opStk.push(ch);
            }
            ++i;    //读入下一个字符
        }
    }
    //  最后清空栈
    while( !opStk.empty() ){
        output.emplace_back( string(1, opStk.top()) );
        opStk.pop();
    }
}

int calSuffix(const vector<string>& output)
{
    stack<int> nums;
    for(auto& s : output){
        if( s=="+" || s=="-" || s=="*" || s=="/" || s=="%" ){
            if( nums.size() < 2 ){
                cerr << "no more num to cal!\n";
                return 0;
            }
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();

            int t;
            if( s == "+" ) t = num1 + num2;
            else if( s == "-" ) t = num1 - num2;
            else if( s == "*" ) t = num1 * num2;
            else if( s == "/" ){
                assert(num2 != 0);
                t = num1 / num2;
            }
            else if( s == "%" ){
                assert(num2 != 0);
                t = num1 % num2;               
            }
            nums.push(t);
        }else{
            nums.push( stoi(s) );
        }
    }
    return nums.top();
}

int main()
{
    string input = "10 + 4*(5-2) - 18/  2-3  %2";
    cout << input << " = " << 10 + 4*(5-2) - 18/  2-3  %2 << endl;

    vector<string> output;
    infixToSuffix(input, output);
    for(auto& s : output)
        cout << s << " ";

    cout << "\nfinal result is " << calSuffix(output) << endl;
    return 0;
}