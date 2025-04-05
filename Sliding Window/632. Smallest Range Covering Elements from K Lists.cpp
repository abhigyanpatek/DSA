typedef pair<int, pair<int,int>> p;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<p, vector<p>, greater<p>> minHeap;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i][0]);
            minHeap.push({nums[i][0], {i, 0}});
        }
        vector<int> ans(2);
        int d = INT_MAX;
        while(minHeap.size() == n){
            int mini = minHeap.top().first; 
            int x = minHeap.top().second.first;
            int y = minHeap.top().second.second;
            minHeap.pop();
            if(maxi - mini < d){
                d = maxi - mini;
                ans[0] = mini;
                ans[1] = maxi;
                if(d == 0) return ans;
            }
            if(y < nums[x].size()-1){
                maxi = max(maxi, nums[x][y+1]);
                minHeap.push({nums[x][y+1], {x, y+1}});
            }
        }
        return ans;
    }
};