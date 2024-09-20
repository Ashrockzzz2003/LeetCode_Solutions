class Solution {
public:
    string shortestPalindrome(string s) {
        // We can find the longest palindrome substring
        // from the right end as we are only allowed
        // to add chars to the front.
        int n = s.length();

        if (n == 0) return s;

        int l = 0;
        for(int r = n - 1; r >= 0; r--) {
            if (s[l] == s[r]) l++;
        }

        if (l == n) return s;

        string non_palindromic_from_right = s.substr(l);
        string rev_non_palindromic_from_right = string(non_palindromic_from_right.rbegin(), non_palindromic_from_right.rend());

        return rev_non_palindromic_from_right + shortestPalindrome(s.substr(0, l)) + non_palindromic_from_right;
    }
};
