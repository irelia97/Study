//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int A, B;
	cin >> A >> B;
	
	int C = A * B;
	string res;
	while( C ){
		res += (C % 10) + '0';
		C /= 10;
	}
	cout << stoi(res);
	
	return 0;
}
