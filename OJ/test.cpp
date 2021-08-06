#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> nums(n, vector<int>(n));
    int i = 0, j = 0;
    int x = 1;

    while( x <= n*n ){
        while( j < n && nums[i][j] == 0 )
            nums[i][j++] = x++;
        i++, j--;

        while( i < n && nums[i][j] == 0 )
            nums[i++][j] = x++;
        i--, j--;

        while( j>= 0 && nums[i][j] == 0 )
            nums[i][j--] = x++;
        i--, j++;

        while( i>= 0 && nums[i][j] == 0 )
            nums[i--][j] = x++;
        i++, j++;
    }

    for(int i = 0; i < nums.size(); ++i){
        for(auto x : nums[i])
            cout << x  << " ";
        cout << "\n";
    }

    return 0;
}