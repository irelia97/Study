//	https://github.com/irelia97/Study/tree/master/OJ/PAT_Basic
#include <bits/stdc++.h>
using namespace std;

void numAdd(string& A, string& B, const string& N)
{
	int size = A.size() > B.size() ? A.size() : B.size();
	if( A.size() != size ) A = string(size - A.size(), '0') + A;
	if( B.size() != size ) B = string(size - B.size(), '0') + B;
	
	int  carry = 0;
	bool haveCarry = false;
	for(int i = size - 1; i >= 0; --i){
// 		cout << "A[i] is " << A[i] << endl;
// 		cout << "B[i] is " << A[i] << endl;
		int t = (A[i] - '0') + (B[i] - '0');
		if( haveCarry ){
			t += carry;
			haveCarry = false;
		}
		
		int mod = N[i] - '0';
		if( mod == 0 ) mod = 10;
		if( t >= mod ){
			carry = t / mod;
			haveCarry = true;
		}
		
		A[i] = (t % mod) + '0';
	}
	if( haveCarry )
		A = '1' + A;
	
	int zeroCnt = 0;
	for(int i = 0; i < A.size(); ++i, ++zeroCnt)
		if( A[i] != '0' )
			break;
			
	A = A.substr(zeroCnt, A.size() - zeroCnt);
    	if( A == "" )
		A = "0";
}

int main()
{
	ios::sync_with_stdio(false);
	
	string N;
	string num1, num2;
	
	cin >> N >> num1 >> num2;
	numAdd(num1, num2, N);
	
	cout << num1;
	
	return 0;
}
