//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int target = 9;
	vector<int> vec1{1, 3, 5, 8, 10};
	vector<int> vec2{1, 2, 3, 4, 6};
	
	vector<pair<int,int>> result;
	for(int i = 0, j = vec2.size() - 1; i < vec1.size() && j >= 0; )
	{
		if( vec1[i]+vec2[j] == target ){
			int i1 = i, j1 = j;
			while( i1 < vec1.size() && vec1[i]==vec1[i1] )
				++i1;
			while( j1 >= 0 && vec2[j] == vec2[j1] )
				--j1;
			for(int i2 = i; i2 < i1; ++i2)
				for(int j2 = j; j2 > j1; --j2)
					result.push_back( make_pair(i2+1, j2+1) );
			
			i = i1;
			j = j1;
		}else if( vec1[i]+vec2[j] > target ){
			--j;
		}else{
			++i;
		}
	}
	for(auto& p : result)
		cout << p.first << " " << p.second << endl;
	
	return 0;
}
