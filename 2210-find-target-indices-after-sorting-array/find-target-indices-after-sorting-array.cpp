class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int> v;
        int xcount = 0 ; 
        int ycount = 0 ; 
        for(int i = 0 ;i<nums.size() ; i++){
            if(nums[i]==target) ycount++;
            else if(nums[i]<target) xcount++;
        }
        for(int i = xcount ;i<xcount+ycount ; i++){
            v.push_back(i);
        }
            
        
        
       
        return v;
    }
};