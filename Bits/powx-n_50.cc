class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0)
            return 0;

        if (x == 1 || n == 0)
            return 1;

        long m = n;
        if (n < 0) {
            m = -m;
            x = 1 / x;
        }

        double res = 1;
        while (m) {
            if (m % 2)
                res *= x;
            m >>= 1;
            x *= x;
        }
        return res;
    }
};
