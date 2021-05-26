//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

struct Player{
	string ID;
	double dist;
	Player(string n, double s):ID(n), dist(s){}
};

int main()
{
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	string ID;
	double x, y;
	Player best("", 150), worst("", -1.0);
	while( N-- ){
		cin >> ID >> x >> y;
		double d = sqrt(x*x + y*y);
		if( best.dist  - d > 1e-6 ){
			best.ID = ID;
			best.dist = d;
		}
		if( d - worst.dist > 1e-6 ){
			worst.ID = ID;
			worst.dist = d;
		}
	}
	cout << best.ID << " " << worst.ID;
	
	return 0;
}
