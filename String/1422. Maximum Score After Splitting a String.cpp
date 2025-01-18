class Solution {
public:
    int maxScore(string s) {
        int countOfOnes = count(s.begin(), s.end(), '1');
        int ans = 0, countOfZeroes = 0;
        for(int i = 0; i < s.size()-1; i++){
            countOfZeroes += s[i] == '0';
            countOfOnes -= s[i] == '1';
            ans = max(ans, countOfOnes + countOfZeroes);
        }
        return ans;
    }
};