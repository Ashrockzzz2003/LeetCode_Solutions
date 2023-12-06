class Solution {
public:
    int totalMoney(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        return (28*(n/7)) + (((n%7)*((n%7)+1))/2 + ((n/7)*(n%7))) + (((n/7)*((n/7)-1))/2)*7;
    }
};