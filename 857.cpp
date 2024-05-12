class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        double min_total_cost = DBL_MAX;
        double current_total_quality = 0;

        vector<pair<double, int>> wage_to_quality_ratio;

        for(int i = 0; i < n; i++) {
            wage_to_quality_ratio.push_back({((double) wage[i] / (double) quality[i]), quality[i]});
        }

        sort(wage_to_quality_ratio.begin(), wage_to_quality_ratio.end());

        priority_queue<int> highest_quality_workers;

        for(int i = 0; i < n; i++) {
            highest_quality_workers.push(wage_to_quality_ratio[i].second);
            current_total_quality += wage_to_quality_ratio[i].second;

            if (highest_quality_workers.size() > k) {
                current_total_quality -= highest_quality_workers.top();
                highest_quality_workers.pop();
            }

            if (highest_quality_workers.size() == k) {
                min_total_cost = min(min_total_cost, current_total_quality * wage_to_quality_ratio[i].first);
            }
        }

        return min_total_cost;

    }
};