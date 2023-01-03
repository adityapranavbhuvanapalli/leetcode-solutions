class Solution {
public:
    int countDigits(int num) {
        int NUM=num, res = 0, rem;
        while(num > 0) {
            rem = num % 10;
            res += (NUM % rem == 0);
            num /= 10;
        }

        return res;
    }
};