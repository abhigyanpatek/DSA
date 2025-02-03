class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), openBrackets = 0, closedBrackets = 0, unlocked1 = 0, unlocked2 = 0;
        if(n&1) return false;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') unlocked1++;
            else if(s[i] == '(') openBrackets++;
            else {
                if(openBrackets--);
                else if(unlocked1--);
                else return false;
            }

            if(locked[n-i-1] == '0') unlocked2++;
            else if(s[n-i-1] == ')') closedBrackets++;
            else {
                if(closedBrackets--);z
                else if(unlocked2--);
                else return false;
            }
        }
        return true;
    }
};