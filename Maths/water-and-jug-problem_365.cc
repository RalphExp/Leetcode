class Solution {
public:
    int gcd(int a, int b) {
        while (a && b) {
            a %= b;
            swap(a, b);
        }
        return a ?: b;
    }

    bool canMeasureWater(int jug1, int jug2, int target) {
        return jug1 + jug2 >= target && !(target % gcd(jug1, jug2));
    }
};
