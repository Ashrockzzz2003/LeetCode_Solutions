class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int total_time = 0;

        for(int i = 0; i < tickets.size(); i++) {
            if (i > k) {
                total_time += min(tickets[k] - 1, tickets[i]);
            } else {
                total_time += min(tickets[k], tickets[i]);
            }
        }

        return total_time;
    }
};