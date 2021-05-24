#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
	if( num < 2 )
		return false;
	for(int i = 2; i <= sqrt(num); ++i)
		if( num % i == 0 )
			return false;
	return true;
}

int main()
{
	string N;
	int L, K;
	bool isFind = false;
	
	cin >> L >> K >> N;
	for(int i = 0; i + K <= N.size(); ++i){
		int num = stoi(N.substr(i, K));
		if( isPrime(num) ){
			isFind = true;
			string res = to_string(num);
			cout << string(K - res.size(), '0') + res;
			break;
		}
	}
	if( !isFind )
		cout << "404";
	
	return 0;
}
