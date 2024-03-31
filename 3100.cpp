class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int emptyBottles = numBottles, bottlesDrunk = numBottles;
        numBottles = 0;
        
        while (!(numBottles == 0 && emptyBottles < numExchange)) {
            if (emptyBottles >= numExchange) {
                // perform exchange
                emptyBottles -= numExchange;
                numExchange++;
                numBottles++;
            } else if (numBottles > 0) {
                bottlesDrunk += numBottles;
                emptyBottles += numBottles;
                numBottles = 0;
            }
        }
        
        return bottlesDrunk;
        
    }
};