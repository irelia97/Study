//	T = O(2^(n/2)), S = O(2^(n/4)) 
#include <bits/stdc++.h>
using namespace std;

const int maxSize = 8;

typedef struct Number{
	int num;
	bitset<3> bits;
	
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

typedef struct node{
	int sum;
	int index1;
	int index2;
	node(int s, int i1, int i2):sum(s), index1(i1), index2(i2){}
	
	bool operator<(const node& ano) const { return sum > ano.sum; }
}Node;

void printVec(const vector<int>& vec, const string info)
{
	clog << info;
	for(auto x : vec)
		printf("%2d ", x);
	clog << endl;	
}

void printS(const vector<Num>& Vn, const string info)
{
	clog << info;
	for(auto x : Vn)
		printf("%2d ", x.num);
	clog << endl;	
}

void printQueue(priority_queue<Node>& pq, const string info)
{
	clog << info;
	while( !pq.empty() )
	{
		cout << pq.top().sum << ", ";
		cout << pq.top().index1 << ", " << pq.top().index2 << endl;
		pq.pop();
	}
	clog << endl;	
}

void fourWay_merge(vector<Num>& SL1, vector<Num>& SR1, vector<Num>& SL2,
	vector<Num>& SR2, int target, vector<string>& answer);

int main()
{
	int target = 16;
	clog << "target is " << target << endl;
	vector<int> vec{1, 5, 4, 2, 8, 6, 9, 2, 7, 3, 1, 10};
	vector<int> vec1(vec.begin(),   vec.begin()+3);
	vector<int> vec2(vec.begin()+3, vec.begin()+6);
	vector<int> vec3(vec.begin()+6, vec.begin()+9);
	vector<int> vec4(vec.begin()+9, vec.begin()+12);
	
	printVec(vec1, "vec1 is: ");	
	printVec(vec2, "vec2 is: ");
	printVec(vec3, "vec3 is: ");
	printVec(vec4, "vec4 is: ");	
	
	vector<Num> SL1, SR1, SL2, SR2;
	for(int k = 0; k < maxSize; ++k){
		bitset<3> s(k);
		int sum[4] {0};
		for(int i = 0; i < 3; ++i){
			sum[0] += s[i] * vec1[i];
			sum[1] += s[i] * vec2[i];
			sum[2] += s[i] * vec3[i];
			sum[3] += s[i] * vec4[i];
		}
		SL1.emplace_back(sum[0], k);
		SR1.emplace_back(sum[1], k);
		SL2.emplace_back(sum[2], k);
		SR2.emplace_back(sum[3], k);
	}

	sort(SR1.begin(), SR1.end(), Num::cmp);
	sort(SR2.begin(), SR2.end(), Num::cmp);
	
	clog << endl;
	printS(SL1, "SL1 is: \n");
	printS(SR1, "SR1 is: \n");
	printS(SL2, "SL2 is: \n");
	printS(SR2, "SR2 is: \n");
	clog << endl;
	
	vector<string> answer;
	fourWay_merge(SL1, SR1, SL2, SR2, target, answer);	

	clog << "target is " << target << endl;
	printVec(vec1, "vec1 is: ");	
	printVec(vec2, "vec2 is: ");
	printVec(vec3, "vec3 is: ");
	printVec(vec4, "vec4 is: ");	
	clog << "\nFinal answer is:\n";
	for(auto& ans : answer)
		cout << ans << endl;
	
	return 0;
}

void fourWay_merge(vector<Num>& SL1, vector<Num>& SR1, vector<Num>& SL2,
	vector<Num>& SR2, int target, vector<string>& answer)
{
	priority_queue<Node> pq1;
	priority_queue<Node> pq2;
	
	for(int i = 0; i < SL1.size(); ++i)
		pq1.push(Node(SL1[i].num + SR1[0].num, i, 0));
	for(int i = 0; i < SL2.size(); ++i)
		if( target - SL2[i].num - SR2[SR2.size() - 1].num > 0 )
			pq2.push(Node(target - SL2[i].num - SR2[SR2.size() - 1].num, 
				i, SR2.size() - 1));
						
	int cnt = 1;
	while( !pq1.empty() && !pq2.empty() ){
		Node n1 = pq1.top();
		Node n2 = pq2.top();
		if( n1.sum <= n2.sum ){
			pq1.pop();
			int i = n1.index1;
			int j = n1.index2;
			if( j != SR1.size() - 1 )
				pq1.push(Node(SL1[i].num + SR1[j+1].num, i, j+1));
		}else if( n1.sum >= n2.sum ){
			pq2.pop();
			int i = n2.index1;
			int j = n2.index2;
			if( j != 0 )
				pq2.push(Node(target - SL2[i].num - SR2[j-1].num, i, j-1));	
		}
		if( n1.sum == n2.sum ){
			clog << "Answer" << cnt << ": \n";
			clog << "n1: " << n1.sum << ", " << n1.index1 << ", " << n1.index2 << endl;
			clog << "n2: " << n2.sum << ", " << n2.index1 << ", " << n2.index2 << endl;
			clog << endl;
			
			string s[4];
			s[0] = SL1[n1.index1].bits.to_string();
			s[1] = SR1[n1.index2].bits.to_string();
			s[2] = SL2[n2.index1].bits.to_string();
			s[3] = SR2[n2.index2].bits.to_string();
			for(auto& str : s)
				reverse(str.begin(), str.end());
			
			answer.emplace_back(s[0] + " " + s[1] + " " + s[2] + " " + s[3]);
		}
	}
}
