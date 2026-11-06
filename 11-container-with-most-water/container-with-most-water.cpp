class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea = INT_MIN;
        int i = 0 ;
        int j = n-1 ;
        while(i<j){
            if(height[i]<height[j]){
                int area = height[i]*(j-i);
                maxarea = max(area , maxarea);
                i++;
            }
            else if(height[i]>=height[j]){
                int area = height[j]*(j-i);
                maxarea = max(area , maxarea);
                j--;
            }
        }
        
        return maxarea;
    }
};