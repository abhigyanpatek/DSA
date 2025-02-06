class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count = __builtin_popcount(num2), x = num1;
        for(int i = 31; i >= 0 && count; i--) {
            if(num1 & (1 << i)) {
                x |= 1 << i;
                count--;
            }
        }

        for(int i = 0; i < 32 && count; i++) {
            if(!(x & (1 << i))) {
                x |= 1 << i;
                count--;
            }
        }
        return x;
    }
};