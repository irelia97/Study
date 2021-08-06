#include <bits/stdc++.h>
using namespace std;

bool vecLegal(vector<char>& vec)
{
    sort(vec.begin(), vec.end());
    // cout << "vec is: ";
    // for(auto c : vec)
    //     cout << c << " ";
    // cout << "\n\n";

    if( vec.size() == 1 ){
        return true;
    }else if( vec.size() == 2 ){
        return vec[0] + 3 == vec[1] || vec[0] + 6 == vec[1];
    }else if( vec.size() == 3 ){
        return vec[0] + 3 == vec[1] && vec[0] + 6 == vec[2];      
    }
    return false;
}

int main()
{
    int T;
    cin >> T;

    while( T-- )
    {
        vector<char> vecW, vecB, vecT;//    万饼条
        string str;

        vector<int> cnt(10, 0);
        bool flag = true;
        for(int i = 0; i < 7; ++i){
            cin >> str;
            //  保证147,258,369各个数字至多出现1次
            if( ++cnt[str[0] - '0'] == 2 )
                flag = false;
            if( str[1] == 'W' ) vecW.push_back(str[0]);
            else if( str[1] == 'B' ) vecB.push_back(str[0]);
            else if( str[1] == 'T' ) vecT.push_back(str[0]);
        }

        if( flag && vecLegal(vecW) && vecLegal(vecB) && vecLegal(vecT) ){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    return 0;
}