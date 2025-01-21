class Solution {
    bool check(char c){
        return c == 'a' || c == 'e' || c== 'i' || c == 'o' || c == 'u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n), ans;
        for(int i = 0; i < n; i++){
            prefix[i] = check(words[i].front()) && check(words[i].back());
            prefix[i] += i > 0? prefix[i-1]: 0; 
        }
        for(auto& q: queries){
            ans.push_back(prefix[q[1]]- (q[0] > 0? prefix[q[0]-1]: 0));
        }
        return ans;
    }
};