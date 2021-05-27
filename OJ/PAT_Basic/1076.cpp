//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
//	ios::sync_with_stdio(false);
	
	int N;
	(cin >> N).get();
	
	map<char, int> m = { make_pair('A',1), make_pair('B',2), 
			make_pair('C',3), make_pair('D',4) };
			
	string str;
	while( N-- ){
		getline(cin, str);
		int index = str.find('T');
		char ch = str[index - 2];
		printf("%d", m[ch]);
	}
	
	return 0;
}
