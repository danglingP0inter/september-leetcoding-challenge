class Solution {
public:
    //Idea is that if station A can't reach B, any station that lies between A and B, can't reach B.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //First check if any solution is possible
        int net = 0;
        int n = gas.size();
        for(int i=0;i<n;i++) {
            net += gas[i] - cost[i];
        }
        if(net<0)
            return -1;
        net = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            net += gas[i] - cost[i];
            if(net<0){
                ans = i+1;
                net = 0;
            }
        }
        
        return ans;
    }
};
