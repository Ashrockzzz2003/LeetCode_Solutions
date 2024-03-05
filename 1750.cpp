class Solution {
public:
    int minimumLength(string s) {
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int start_index = 0, end_index = s.length() - 1;

        while (start_index < end_index && s[start_index] == s[end_index]) {
            char current_char = s[start_index];

            // "a" and "aa" in the beginning means the same
            while (start_index <= end_index && s[start_index] == current_char) {
                start_index++;
            }
            
            // "a" and "aa" in the end also in beginning means the same
            while (start_index <= end_index && s[end_index] == current_char) {
                end_index--;
            }
        }

        // If it comes out, whatever that could be deleted is now deleted.

        return end_index + 1 - start_index;
    }
};