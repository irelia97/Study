//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

using uLL = unsigned long long;

int main()
{
	ios::sync_with_stdio(false);
	
	int N, M;
	
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		int min = INT_MAX, max = 0, score;
		double G1 = 0, G2 = 0;

		cin >> G2;
		uLL sumScore = 0, size = N - 3;
		for(int k = 1; k < N; ++k){
			cin >> score;
			if( score >= 0 && score <= M ){
				sumScore += score;
				if( score < min )
					min = score;
				if( score > max )
					max = score;		
			}else{
				size--;
			}
		}
		sumScore -= (max + min);
		G1 = sumScore / (double)size;
		
		cout << (int)round((G1 + G2) / 2) << endl;
	}
	
	return 0;
}
