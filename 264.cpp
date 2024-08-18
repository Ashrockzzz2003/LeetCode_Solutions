class Solution {
public:
    int nthUglyNumber(int n) {
            int index_2 = 0, index_3 = 0, index_5 = 0;
            vector<int> ugly = {1};

            for (int i = 0; i < n - 1; i++) {
                int next_2 = ugly[index_2]*2;
                int next_3 = ugly[index_3]*3;
                int next_5 = ugly[index_5]*5;

                int next_ugly = min(next_2, next_3);
                next_ugly = min(next_ugly, next_5);

                if (next_ugly == next_2) index_2++;
                if (next_ugly == next_3) index_3++;
                if (next_ugly == next_5) index_5++;

                ugly.push_back(next_ugly);
            }

            return ugly.back();
    }
};