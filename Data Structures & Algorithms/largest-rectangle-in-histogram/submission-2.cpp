class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack< pair<int,int>>left;
    
        int area = 0;

        for(int i = 0; i<heights.size(); i++){
            
            int height = heights[i];
            int rwidth = 0;
            int lwidth;
            int x = i+1;
            while(x < heights.size() && heights[x] >= height) {
                rwidth++;
                x++;
                }

            while(!left.empty() && height < left.top().first) left.pop();
            if(left.empty()) lwidth = i;
            else lwidth = i - left.top().second -1 ;

            left.push({heights[i], i});

            int width = rwidth + lwidth + 1;
            int currarea = height * width;
            area = max(currarea , area);
        }
        return area;
    }
};
