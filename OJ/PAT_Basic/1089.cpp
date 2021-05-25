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
		
	vector<int> goodMan(N+1, 1);	//goodMan[i]==1��ʾi���Ǻ��� 
	int i, j;
	for(i = 1; i <= N-1; ++i){
		//	���i��Ϊ�� 
		goodMan[i] = -1;
		for(j = i+1; j <= N; ++j){
			//	���j��Ϊ�� 
			goodMan[j] = -1;
			//	��¼˵�Ѵ������������� 
			int liesCnt = 0, wolfCnt = 0;
			
			for(int k = 1; k <= N; ++k){
				//	vec[k]��ʾk����Ϊ��abs(vec[k])��������(vec[k]<0) or ����(vec[k]>0) 
				//	goodMan[abs(vec[k])]abs(vec[k])����������(-1) or ����(1)
				//	���˻�Ϊ��˵��˵�� 
				if( goodMan[abs(vec[k])] * vec[k] < 0 ){
					liesCnt++;
					//	k��ǡ�ñ��Ϊ���� 
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
