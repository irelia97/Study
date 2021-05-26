//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	string d;
	int N;
	cin >> d >> N;
	
	while( --N ){
		string t;
		int  size = 0;
		char thisCh = d[0];
		for(int i = 0; i < d.size(); )
		{
			while( i < d.size() && d[i] == thisCh ){
				++size;
				++i;
			}
			t += thisCh;
			t += size + '0';
			size = 0;
			if( i < d.size() )
				thisCh = d[i];
		}
		d = t;
	}
	cout << d;
	
	return 0;
}
