class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int left = 0, right = nums2.size();

        vector<int> arr;

        for(auto num: nums1) {
            left = binarySearch(nums2, left, right, num);
            if (left >= right) {
                break;
            }
            if(nums2[left] == num) {
                arr.push_back(nums2[left++]);
            }
        }

        return arr;
    }

    int binarySearch(vector<int> nums, int lo, int hi, int target) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            }
            else {
                hi = mid;
            }
        }
        return hi;
    }
};

/*
Another approach:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> intersection;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                intersection.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return intersection;
    }
};
*/