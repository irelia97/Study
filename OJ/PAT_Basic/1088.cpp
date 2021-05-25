//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int x, cnt = 0, num = -1;
	for(int i = 1; i <= N; ++i){
		if( (x=(i/2 + i/3 +i/5)) > num  ){
			num = x;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
