class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double average = 0;
        for(int i = 1; i < salary.size()-1; i++){
            average += salary[i];
        }

        return (average / (salary.size() - 2));
    }
};
