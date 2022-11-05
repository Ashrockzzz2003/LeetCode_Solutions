class Solution {
public:
    int find_peri(vector<int>& A){
        int size = A.size();
        while(size >= 3 && A[size - 2] + A[size - 3] <= A[size - 1]){
            size--;
        }

        if(size < 3){
            return 0;
        }

        return A[size - 1] + A[size - 2] + A[size - 3];
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return find_peri(nums);
    }
};
