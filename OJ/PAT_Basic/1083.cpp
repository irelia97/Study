//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int x, N;
	cin >> N;
	
	map<int, int> m;
	for(int i = 1; i <= N; ++i){
		cin >> x;
		m[abs(x - i)]++;
	}
	for(auto it = m.rbegin(); it != m.rend(); ++it)
		if( it->second != 1 )
			cout << it->first << " " << it->second << endl;
	
	return 0;
}
