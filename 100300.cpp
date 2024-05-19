class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        int digit_count = to_string(nums[0]).size();
        vector<vector<int>> freq_digits(digit_count, vector<int>(10, 0));

        for (int num : nums) {
            string s = to_string(num);
            for (int i = 0; i < digit_count; ++i) {
                freq_digits[i][s[i] - '0']++;
            }
        }

        long long total_differece_sum = 0;
        for (int i = 0; i < digit_count; ++i) {
            long long digit_contribution = 0;
            for (int d = 0; d < 10; ++d) {
                for (int d2 = 0; d2 < 10; ++d2) {
                    if (d != d2) {
                        digit_contribution += freq_digits[i][d] * freq_digits[i][d2];
                    }
                }
            }
            total_differece_sum += digit_contribution / 2;
        }

        return total_differece_sum;
    }
};