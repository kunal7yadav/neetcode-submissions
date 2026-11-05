class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ne = 0 ; 
        int po = 0 ;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]<0) ne++;
            else if(nums[i]>0) po++;
        }
        int mx = max(ne , po);
        return mx;
        
    }
};