class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        // Magically Reducing Run Time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int iNeedCircle = 0, iNeedSquare = 0;

        for(int i = 0; i < students.size(); i++) {
            students[i] == 1 ? iNeedSquare++ : iNeedCircle++;
        }

        for(int i = 0; i < sandwiches.size(); i++) {
            if (sandwiches[i] == 0 && iNeedCircle == 0) {
                return iNeedSquare;
            }

            if (sandwiches[i] == 1 && iNeedSquare == 0) {
                return iNeedCircle;
            }

            sandwiches[i] == 1 ? iNeedSquare-- : iNeedCircle--;
        }

        // If we reach here, then everybody got what they needed.
        return 0;
    }
};