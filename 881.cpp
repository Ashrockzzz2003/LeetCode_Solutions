class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(people.begin(), people.end());

        int min_boats = 0;

        int start_index = 0, end_index = people.size() - 1;

        while (start_index <= end_index) {
            if (people[end_index] + people[start_index] <= limit) start_index++;

            end_index--;
            min_boats++;
        }

        return min_boats;
    }
};