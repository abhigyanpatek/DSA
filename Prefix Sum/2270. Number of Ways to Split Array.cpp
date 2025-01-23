class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rightSum = accumulate(nums.begin(), nums.end(), 0LL), leftSum = 0, ans = 0;
        for(int i = 0; i < nums.size()-1; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            ans += leftSum >= rightSum;
        }
        return ans;
    }
};