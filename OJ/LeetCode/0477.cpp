class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int bitCnt[32] {0};
        for(auto x : nums){
            int index = 0;
            while( x ){
                bitCnt[index++] += x & 1;
                x >>= 1;			
            }
        }
        int ret = 0;
        for(auto cnt : bitCnt)
            ret += cnt * (nums.size() - cnt);
        
        return ret;
    }
};
