class Solution {
public:
    int minOperations(int k) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int add_one = sqrt(k);

        if (add_one*add_one == k) {
            return 2*add_one - 2;
        }

        if (add_one * (add_one + 1) >= k) {
            return 2*add_one - 1;
        }

        return 2*add_one;
    }
};