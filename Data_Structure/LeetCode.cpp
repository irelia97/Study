#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(const string& num)
{
    int ret = 0, p = 1;
    for(int i = num.size() - 1; i >=0; --i){
        ret += (num[i] - '0') * p;
        p *= 2;
    }
    return ret;
}

int main()
{
    string str = "He ll   owo  rld";

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str << endl;

    str = "1001";
    cout << binaryToDecimal(str) << "\n";

    int x = 05LU, y = 0x30ULL;
    printf("x = %#o, y = %#x\n", x, y); // x = 05, y = 0x30

    printf("dofaismfis");
    printf("\r12345");

    cout << INT_MAX << endl;

    return 0;
}