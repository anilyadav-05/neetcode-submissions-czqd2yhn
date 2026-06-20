class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        stack<double>time;
        vector<pair<int,int>> cars; // {position, speed}
        int fleet =0;

     for(int i = 0; i < n; i++)
    cars.push_back({position[i], speed[i]});

     sort(cars.begin(), cars.end(), greater<pair<int,int>>());
     
     for(int i = n-1 ; i>=0 ; i--){
        double x = (double)(target - cars[i].first)/cars[i].second;
        time.push(x);
     }
     while(!time.empty()){
        double x = time.top();
        while(!time.empty() && time.top() <= x) time.pop();
        fleet++;
     }
     return fleet;
    }
};
