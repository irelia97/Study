//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int getN(int num)
{
	string snum = to_string(num);
	int size = snum.size();

	for(int i = 1; i <= 9; ++i){
		string s = to_string(i * num * num);
		if( s.substr(s.size() - size, size) == snum )
			return i;
	}	
	return -1;
}

int main()
{
	int M;
	cin >> M;
	
	int x;
	for(int i = 0; i < M; ++i){
		cin >> x;
		int ret = getN(x);
		if( ret != -1 ){
			cout << ret << " " << ret * x * x <<endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}
