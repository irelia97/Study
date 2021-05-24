//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	multimap<int, int> mm;
	int no1, no2;
	for(int i = 0; i < N; ++i){
		cin >> no1 >> no2;
		mm.insert( make_pair(no1, no2) );
		mm.insert( make_pair(no2, no1) );
	}
	
	for(int i = 0; i < M; ++i){
		cin >> N;
		unordered_set<int> s;
		for(int k = 0; k < N; ++k){
			cin >> no1;
			s.insert(no1);
		}
		
		bool isFind = false;
		for(auto x : s){
			auto it = mm.find(x);
			if( it != mm.end() ){
				int size = mm.count(x);
				for(int k = 0; k < size; ++k){
					if( s.find(it->second) != s.end() ){
						cout << "No" << endl;
						isFind = true;
						break;
					}
					++it;
				}
			}
			if( isFind )
				break; 
		}
		if( !isFind )
			cout << "Yes" << endl;
	}

	return 0;
}
