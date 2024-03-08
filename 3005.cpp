class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> number_of_occurences(100, 0);
        int max_freq = 0, number_of_elements_with_max_freq = 0;

        for (int i = 0; i < nums.size(); i++) {
            number_of_occurences[nums[i] - 1]++;

            if (number_of_occurences[nums[i] - 1] > max_freq) {
                max_freq = number_of_occurences[nums[i] - 1];
                number_of_elements_with_max_freq = 0;
            }

            if (number_of_occurences[nums[i] - 1] == max_freq) {
                number_of_elements_with_max_freq++;
            }
        }

        return number_of_elements_with_max_freq*max_freq;

    }
};