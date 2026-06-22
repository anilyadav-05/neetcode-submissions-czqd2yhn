class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum = 0 , costsum = 0;

       for(int i=0; i<gas.size(); i++){
          gassum += gas[i];
          costsum += cost[i];
       }
       if(costsum > gassum)return -1;
       gassum = 0 , costsum = 0;
       int start = -1;

       for(int i = 0; i<gas.size(); i++){
          gassum += gas[i];
          costsum += cost[i];
          if(costsum > gassum){
            gassum = 0 , costsum = 0;
             start = -1;
        }else{
            if(start == -1)start = i;
            
        }
       }
       return start;

    }
};
