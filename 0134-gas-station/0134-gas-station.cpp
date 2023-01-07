class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(),0))
            return -1;
        
        int remainingFuel = 0;
        int ansInd = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            remainingFuel += (gas[i]-cost[i]);
            
            if(remainingFuel < 0)
            {
                ansInd = i+1;
                remainingFuel = 0;
            }
        }
        return ansInd;
        
    }
};