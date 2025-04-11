class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        multiset<int> set;
        int i = 0, j = 0, ans = 0;
        while(j < nums.size()){
            set.insert(nums[j]);
            while(*rbegin(set)-*begin(set) > k){
                set.erase(set.find(nums[i++]));
            }
            if(*rbegin(set)-*begin(set) <= k) ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};