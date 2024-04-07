class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestCount = 1;
        
        // longest increasing let's try n find
        int i = 0;
        
        while (i < nums.size() - 1) {
            int count = 1;
            while(i < nums.size() - 1 && nums[i] < nums[i + 1]) {
                count++;
                i++;
            }
            
            longestCount = max(count, longestCount);
            i++;
        }
        
        i = 0;
        while (i < nums.size() - 1) {
            int count = 1;
            while(i < nums.size() - 1 && nums[i] > nums[i + 1]) {
                count++;
                i++;
            }
            
            longestCount = max(count, longestCount);
            i++;
        }
        
        return longestCount;
        
        
    }
};