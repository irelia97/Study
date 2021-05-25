//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> vec(N+1);

	for(int i = 1; i <= N; ++i)
		cin >> vec[i];
		
	vector<int> goodMan(N+1, 1);	//goodMan[i]==1表示i号是好人 
	int i, j;
	for(i = 1; i <= N-1; ++i){
		//	标记i号为狼 
		goodMan[i] = -1;
		for(j = i+1; j <= N; ++j){
			//	标记j号为狼 
			goodMan[j] = -1;
			//	记录说谎次数，狼人数量 
			int liesCnt = 0, wolfCnt = 0;
			
			for(int k = 1; k <= N; ++k){
				//	vec[k]表示k号认为：abs(vec[k])号是狼人(vec[k]<0) or 好人(vec[k]>0) 
				//	goodMan[abs(vec[k])]abs(vec[k])到底是狼人(-1) or 好人(1)
				//	若乘积为负说明说谎 
				if( goodMan[abs(vec[k])] * vec[k] < 0 ){
					liesCnt++;
					//	k号恰好标记为狼人 
					if( k == i || k == j )
						wolfCnt++;
				}
			}
			if( liesCnt == 2 && wolfCnt == 1 ){
				cout << i << " " << j;
				return 0;
			}
			goodMan[j] = 1;
		}
		goodMan[i] = 1;
	}
	cout << "No Solution";
	
	return 0;
}
