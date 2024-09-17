class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for(auto &time: timePoints) {
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3));
            minutes.push_back(hour*60 + minute);
        }

        sort(minutes.begin(), minutes.end());
        
        int min_diff = minutes[1] - minutes[0];
        for(int i = 1; i < minutes.size() - 1; i++) min_diff = min(min_diff, minutes[i + 1] - minutes[i]);

        min_diff = min(min_diff, 24*60 - minutes[minutes.size() - 1] + minutes[0]);

        return min_diff;
    }
};