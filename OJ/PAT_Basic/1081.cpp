//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

bool isLegal(char ch)
{
	return isdigit(ch) || isalpha(ch) || ch=='.';
}

int main()
{
	ios::sync_with_stdio(false);
	
	int N;
	(cin >> N).get();
	
	string password;
	while( N-- ){
		getline(cin, password);
		if( password.size() < 6 ){
			cout << "Your password is tai duan le." << endl;
			continue;
		}
		
		bool haveDigit = false, haveAlpha = false;
		bool legal = true;
		for(auto ch : password){
			if( !isLegal(ch) ){
				legal = false;
				break;
			}
			if( isdigit(ch) ) haveDigit = true;
			if( isalpha(ch) ) haveAlpha = true;		
		}
		if( !legal ){
			cout << "Your password is tai luan le." << endl;
		}else if( haveAlpha && !haveDigit ){
			cout << "Your password needs shu zi." << endl;
		}else if( !haveAlpha && haveDigit ){
			cout << "Your password needs zi mu." << endl;
		}else{
			//	题目保证不存在只有小数点的输入
			//	因此不可能既没有字母又没有数字	 
			cout << "Your password is wan mei." << endl;
		}
	}
	
	return 0;
}
