#include <bits/stdc++.h>
using namespace std;

int main()
{
	string A, B;
	getline(cin, A);
	getline(cin, B);
	
	unordered_set<char> s;
	for(auto c : A + B)
		s.insert(c);
	
	for(auto c : A + B){
		if( s.empty() )
			break;
		auto it = s.find(c);
		if( it != s.end() ){
			putchar(c);
			s.erase(*it);
		}
	}
	
	return 0;
}
