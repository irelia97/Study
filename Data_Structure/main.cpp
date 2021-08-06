#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    if( a == "" && b == "" )
        return string("0");

    if( a.size() > b.size() ) b = string(a.size()-b.size(),'0') + b;
    if( b.size() > a.size() ) a = string(b.size()-a.size(),'0') + a;
    string res(a.size(), '0');

    int addBit = 0;
    for(int i = a.size() - 1; i >= 0; --i){
        int t = (a[i]-'0') + (b[i]-'0') + addBit;
        addBit = t > 1 ? 1 : 0;
        res[i] = (t % 2) + '0';
    }
    if( addBit == 1 )
        res = string("1") + res;

    return res;
}

string subStr_match(const string& S, const string& T)
{
    vector<int> m(128, 0);
    for(auto& c : T)
        m[c]++;
    
    int cnt = T.size();
    int front = 0, rear = 0;
    int head  = 0;
    int minLen = INT_MAX;
    while( rear < S.size() ){
        if( m[S[rear++]]-- > 0 )
            cnt--;
        while( front < rear && cnt == 0 ){
            if( rear - front < minLen ){
                head = front;
                minLen = rear - front;
            }
            if( m[S[front++]]++ == 0 )
                cnt++;
        }
    }
    return minLen == INT_MAX ? "" : S.substr(head, minLen);
}

int main()
{
    string S("ADOBECODEBANC"), T("ABC");
    string sub = subStr_match(S, T);

    cout << sub;

    return 0;
}