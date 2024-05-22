class Solution {
private:
    bool isPalindrome(string s) {
        int left_index = 0, right_index = s.length() - 1;
        while (left_index < right_index) {
            if (s[left_index] != s[right_index]) return false;
            left_index++;
            right_index--;
        }

        return true;
    }

    void searchPartitions(string& s, int start_index, int length, vector<string> buffer, vector<vector<string>>& all_partitions) {
        if (start_index == s.length()) {
            all_partitions.push_back(buffer);
            return;
        }

        if ((start_index + length) > s.length()) return;

        searchPartitions(s, start_index, length + 1, buffer, all_partitions);

        if (isPalindrome(s.substr(start_index, length)) == true) {
            buffer.push_back(s.substr(start_index, length));
            searchPartitions(s, start_index + length, 1, buffer, all_partitions);
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> all_partitions;
        vector<string> buffer;

        searchPartitions(s, 0, 1, buffer, all_partitions);

        return all_partitions;
    }
};