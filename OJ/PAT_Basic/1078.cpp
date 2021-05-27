//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

//	原始字符串是完全由英文字母和空格组成的非空字符串
void compression(const string& str)
{
	char nowCh = str[0];
	int  i = 1, cnt = 1;
	do{
		while( i < str.size() && str[i]==nowCh ){
			++i;
			++cnt;
		}
		if( cnt == 1 ) cout << nowCh;
		else
			cout << cnt << nowCh;
		
		if( i < str.size() ) nowCh = str[i];
		cnt = 0;
	}while( i < str.size() );
}

void deCompression(const string& str)
{
	int  cnt;
	char ch;
	for(int i = 0; i < str.size(); ++i){
		int pos = i;
		while( i < str.size() && isdigit(str[i]) )
			++i;
		cnt = (pos == i ? 1 : stoi(str.substr(pos, i - pos)));
		
		ch = str[i];
		while( cnt-- )
			putchar(ch);
	}		
}

int main()
{
	ios::sync_with_stdio(false);
	
	char ch;
	string str;
	
	(cin >> ch).get();
	getline(cin, str);
	
	if( ch == 'C' ){
		compression(str);
	}else{
		deCompression(str);
	}
	
	return 0;
}
