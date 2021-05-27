//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int add, data, next;
	node(int a=0, int d=0, int n=0):
		add(a), data(d), next(n){}
}Node;

int main()
{
//	ios::sync_with_stdio(false);
	
	int firstAdd, N, K;
	cin >> firstAdd >> N >> K;
	
	int add, data, next;
	unordered_map<int, pair<int,int>> um;
	for(int i = 0; i < N; ++i){
		scanf("%d %d %d", &add, &data, &next);
		um[add] = make_pair(data, next);
	}
	
	vector<Node> v1, v2, v3;
	add = firstAdd;
	while( add != -1 ){
		auto& e = um[add];
		int data = e.first;
		if( data < 0 )
			v1.emplace_back(Node(add, data, e.second));
		else if( data <= K )
			v2.emplace_back(Node(add, data, e.second));
		else
			v3.emplace_back(Node(add, data, e.second)); 
			
		add = e.second;
	}
	vector<Node> vec;
	vec.insert(vec.end(), v1.begin(), v1.end());
	vec.insert(vec.end(), v2.begin(), v2.end());
	vec.insert(vec.end(), v3.begin(), v3.end());
	
	int i = 0;
	for(; i < vec.size() - 1; ++i){
		vec[i].next = vec[i+1].add;
		printf("%05d %d %05d\n", vec[i].add, vec[i].data, vec[i].next);
	}
	printf("%05d %d -1\n", vec[i].add, vec[i].data);
	
	return 0;
}
