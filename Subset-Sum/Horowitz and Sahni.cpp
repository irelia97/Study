//	T = O(2^(n/2)), S = O(2^(n/2)) 
#include <bits/stdc++.h>
using namespace std;

const int maxSize = 16;

typedef struct Number{
	int num;
	bitset<4> bits;
	
	Number(int m, int b) : num(m), bits(b){}
	static bool cmp(const Number& n1, const Number& n2){ return n1.num < n2.num; }
	static int findPos(int num, vector<Number>& S)
	{
		int left = 0, right = S.size() - 1;
		while( left <= right ){
			int mid = (left + right) / 2;
			if( S[mid].num == num )
				return mid;
			else if( S[mid].num < num )
				left  = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
}Num;

int main()
{
	int target = 9;
	vector<int> vec{1, 5, 3, 2, 8, 6, 2, 9};
	vector<int> vec1(vec.begin(),   vec.begin()+4);
	vector<int> vec2(vec.begin()+4, vec.begin()+8);
	clog << "vec1 is: ";
	for(auto x : vec1)
		cout << x << " ";
	clog << endl;
	clog << "vec2 is: ";
	for(auto x : vec2)
		cout << x << " ";
	clog << endl << endl;	
	
	
	clog << "target is " << target << endl << endl;	
	vector<Num> S1, S2;
	for(int k = 0; k < maxSize; ++k){
		bitset<4> s(k);
		int sum1 = 0, sum2 = 0;
		for(int i = 0; i < 4; ++i){
			sum1 += s[i] * vec1[i];
			sum2 += s[i] * vec2[i];
		}
		S1.emplace_back(sum1, k);
		if( target - sum2 > 0 )
			S2.emplace_back(target - sum2, k);
	}
	sort(S1.begin(), S1.end(), Num::cmp);
	sort(S2.begin(), S2.end(), Num::cmp);
	
	clog << "S1 is: ";
	for(auto& x : S1)
		printf("%2d ", x.num);
	clog << endl;
	clog << "S2 is: ";
	for(auto& x : S2)
		printf("%2d ", x.num);
	clog << endl << endl;
	
	//	find
	int pos = 0, index = 1;
	for(int i = 0; i < S1.size(); ++i){
		if( (pos = Num::findPos(S1[i].num, S2)) != -1 ){
			clog << "Answer" << index++ << ":\n";
			clog << "S1[" << i+1 << "]: "   << S1[i].bits << endl;
			clog << "S2[" << pos+1 << "]: " << S2[pos].bits << endl << endl;
		}
	}
	clog << "END";
	
	return 0;
}
