#include <bits/stdc++.h>
using namespace std;

#define SWAP(a, b) { a ^= b ^= a ^= b; }
void vecTurn(vector<int>& nums, int start, int end){
    cout << "start is " << start << ", end is " << end << endl;
    while( start < end ){
        SWAP(nums[start], nums[end])
        start++;
        end--;
    }
    for(auto x : nums)
        cout << x << " ";
    cout << endl;
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if( k != 0 ){
        vecTurn(nums, 0, nums.size()-k-1);
        vecTurn(nums, nums.size()-k, nums.size()-1);
        vecTurn(nums, 0, nums.size()-1);
    }
}

int main()
{
    vector<int> vec{1,2,3,4,5,6,7};
    int k = 3;

    rotate(vec, k);

    int i = 1, j = 5;
    cout << i << ", " << j << endl;

    unordered_set<int> us;
    us.insert(1);

    return 0;
}