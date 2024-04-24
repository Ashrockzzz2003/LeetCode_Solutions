class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) {
            return n;
        }

        int one = 0, two = 1, three = 1;

        // 0 1 1
        // 1 1 2
        // 1 2 4

        for (int i = 3; i <= n; i++) {
            int oldie = one;
            one = two;
            two = three;
            three = oldie + one + two;
        }

        return three;

    }
};