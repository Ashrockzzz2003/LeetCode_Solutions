class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        vector<int> arr;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(i == j && (i + j) == (mat.size() - 1)){
                    arr.push_back(mat[i][j]);
                }
                else if(i == j){
                    arr.push_back(mat[i][j]);
                }
                else if((i+j) == (mat.size() - 1)){
                    arr.push_back(mat[i][j]);
                }
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};
