//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

typedef struct School{
	double totalScore;	
	int cnt;	
	School():totalScore(0.0), cnt(0){}
}Sc;

bool cmp(const pair<string, Sc>& s1, const pair<string, Sc>& s2)
{
	if( (int)s1.second.totalScore == (int)s2.second.totalScore ){
		if( s1.second.cnt == s2.second.cnt ){
			return s1.first < s2.first;
		}else{
			return s1.second.cnt < s2.second.cnt;
		}
	}else{
		return (int)s1.second.totalScore > (int)s2.second.totalScore;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	string no, scName;
	double score;
	
	unordered_map<string, Sc> m;
	for(int i = 0; i < N; ++i){
		cin >> no >> score >> scName;
		transform(scName.begin(), scName.end(), scName.begin(), ::tolower);
		m[scName].cnt++;
		if( score > 1e-6 && no[0] == 'B' ) m[scName].totalScore += score / 1.5;
		else if( no[0] == 'A' ) m[scName].totalScore += score;
		else m[scName].totalScore += score * 1.5;
	}
	
	vector<pair<string, Sc>> vec;
	for(auto& x : m)
		vec.emplace_back( make_pair(x.first, x.second) );
		
	sort(vec.begin(), vec.end(), cmp);
	int index = 1;
	cout << vec.size() << endl;
	cout << index << " " << vec[0].first  << " " 
		 << (int)vec[0].second.totalScore << " " << vec[0].second.cnt << endl;
	for(int i = 1; i < vec.size(); ++i){
		if( (int)vec[i].second.totalScore < (int)vec[i-1].second.totalScore )
			index = i + 1;
		cout << index << " " << vec[i].first  << " " 
			 << (int)vec[i].second.totalScore << " " << vec[i].second.cnt << endl;
	}
	
	return 0;
}
