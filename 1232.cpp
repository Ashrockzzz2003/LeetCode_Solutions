class Solution {
public:
    bool valid(int x1, int y1, int x2, int y2, int x3, int y3){
        return (y2 - y1)*(x3 - x2) == (x2 - x1)*(y3 - y2);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool flag = true;
        for(int i = 0; i < coordinates.size() - 2; i++){
            if(!valid(coordinates[i][0], coordinates[i][1], coordinates[i+1][0], coordinates[i+1][1], coordinates[i+2][0], coordinates[i+2][1])){
                flag = false;
                break;
            }
        }

        return flag;
    }
};
