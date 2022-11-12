class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c != mat.size()*(mat[0].size())){
            return mat;
        }
        else if(r == mat.size() && c == mat[0].size()){
            return mat;
        }
        else{
            vector<int> data;
            for(int i = 0; i < mat.size(); i++){
                for(int j = 0; j < mat[0].size(); j++){
                    data.push_back(mat[i][j]);
                }
            }

            vector<vector<int>> result;

            int k = 0;
            for(int i = 0; i < r; i++){
                vector<int> row;
                for(int j = 0; j < c; j++){
                    row.push_back(data[k]);
                    k++;
                }
                result.push_back(row);
            }

            return result;
        }
    }
};
