class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(arr.begin(), arr.end());
        // 77, 89, 90, 91, 92

        arr[0] = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr[arr.size() - 1];
    }
};