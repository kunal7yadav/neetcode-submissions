class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int move = 0 ;
        sort(nums.begin() , nums.end());
        // if(n%2==0) medi =  (nums[n/2 - 1] + nums[n/2]) / 2; 
        int medi = nums[n/2];
        for(int i = 0 ; i<n ; i++){
            move+=abs(nums[i]-medi);
        }
        return move;
    }
};