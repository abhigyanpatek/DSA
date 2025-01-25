class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> count(n);
        for(auto& shift: shifts){
            if(shift[2] == 1) {
                count[shift[0]]++;
                if(shift[1]+1 < n) count[shift[1]+1]--;
            }else{
                count[shift[0]]--;
                if(shift[1]+1 < n) count[shift[1]+1]++;
            }
        }
        for(int i = 0; i < n; i++){
            if(i > 0) count[i] += count[i-1];
            s[i] = ((s[i]-'a'+count[i])%26 + 26)%26 + 'a';
        }
        return s;
    }
};