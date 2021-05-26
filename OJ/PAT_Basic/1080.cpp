//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

typedef struct score{
	int Gp, Gm, Gf, G;
	score():Gp(-1), Gm(-1), Gf(-1){}
}Sc;

bool cmp(const pair<string, Sc>& p1, 
	const pair<string, Sc>& p2)
{
	return p1.second.G == p2.second.G ? 
		p1.first < p2.first : p1.second.G > p2.second.G;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int P, M, N;
	cin >> P >> M >> N;
	
	string no;
	int score;
	unordered_map<string, Sc> um;
	while( P-- ){
		cin >> no >> score;
		if( score >= 200 )
			um[no].Gp = score;
	}
	
	while( M-- ){
		cin >> no >> score;
		if( um.find(no) != um.end() )
			um[no].Gm = score;
	}
	while( N-- ){
		cin >> no >> score;
		if( um.find(no) != um.end() )
			um[no].Gf = score;
	}
	
	vector<pair<string, Sc>> vec;
	for(auto& e : um){
		auto& s = e.second;
		s.G = s.Gm > s.Gf ? round(0.4*s.Gm + 0.6*s.Gf) : s.Gf;
		if( s.Gp >= 200 && s.G >= 60 )
			vec.emplace_back(e);
	}
	sort(vec.begin(), vec.end(), cmp);
	
	for(auto& v : vec){
		auto& s = v.second;
		cout << v.first << " " << s.Gp << " " << s.Gm
			 << " " << s.Gf << " " << s.G  << endl;
	}
	
	return 0;
}
