//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;


int main()
{
	vector<int> nums{4, 14, 2};
	
	int bitCnt[32] {0};
	for(auto x : nums){
		int index = 0;
		while( x ){
			if( x&1 )
				bitCnt[index]++;
				
			x >>= 1;
			++index;			
		}
	}
	int ret = 0;
	for(auto cnt : bitCnt)
		ret += (cnt * (nums.size() - cnt));
	
	cout << ret;
	
	return 0;
}
