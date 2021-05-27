//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string num)
{
	int i = 0, j = num.size() - 1;
	while( i <= j )
		if( num[i++] != num[j--] )
			return false;
	return true;
}

//	N和N的逆转数相加 
void numAdd(string& A, const string& B)
{
	int size = A.size();
	bool haveCarry = false;
	
	for(int i = size - 1; i >= 0; --i){
		int t = (A[i] - '0') + (B[i] - '0');
		if( haveCarry ){
			t += 1;
			haveCarry = false;
		}
		
		if( t >= 10 )
			haveCarry = true;
		A[i] = (t % 10) + '0';
	}
	if( haveCarry )
		A = '1' + A;
}

int main()
{
	ios::sync_with_stdio(false);
	
	string N;
	cin >> N;
	
	int cnt = 0;
	while( cnt < 10 && !isPalindrome(N) )
	{
		string ano(N.rbegin(), N.rend());
		cout << N << " + " << ano << " = ";
		numAdd(N, ano);
		cout << N << endl;
		++cnt;
	}
	if( isPalindrome(N) ){
		cout << N << " is a palindromic number.";
	}else{
		cout << "Not found in 10 iterations.";
	}
	
	return 0;
}
