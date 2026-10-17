class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        vector<int> psum(nums.size());
        psum[0]=nums[0];
        for(int i = 1 ; i<nums.size() ; i++){
            psum[i]= nums[i]+ psum[i-1];
        }
        // if(psum[0]==0) return 0 ;
        // if(psum[psum.size()-2]==0) return psum.size()-1;
        
        vector<int> ssum(nums.size());
        ssum[nums.size()-1]=nums[nums.size()-1];
        for(int i = nums.size()-2 ; i>=0 ; i--){
            ssum[i]= nums[i]+ ssum[i+1];
        }

        for(int i = 0 ; i<nums.size() ; i++){
            psum[i]-=ssum[i];
            if(psum[i]==0) return i; 
        }

        return -1;

    }
};