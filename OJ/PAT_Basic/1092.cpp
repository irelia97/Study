//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	int x = 0;
	vector<int> vec(N+1, 0);
	for(int i = 0; i < M; ++i){
		for(int k = 1; k <= N; ++k){
			cin >> x;
			vec[k] += x;
		}
	}
	
	int maxSales = -1, maxNo = 1;
	vector<int> res;
	for(int k = 1; k <= N; ++k){
		if( vec[k] > maxSales ){
			maxSales = vec[k];
			maxNo = k;
			res.clear();
			res.push_back(k);
		}else if( vec[k] == maxSales ){
			res.push_back(k);
		}	
	}
	
	cout << maxSales << endl << res[0];
	for(int i = 1; i < res.size(); ++i)
		cout << " " << res[i];

	return 0;
}
