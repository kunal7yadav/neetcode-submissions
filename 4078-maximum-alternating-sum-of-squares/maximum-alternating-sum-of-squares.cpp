class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq(nums.size()) ; 
        for(int i = 0; i<nums.size();i++){
            sq[i]= nums[i]*nums[i];
        }
        sort(sq.begin() , sq.end());
        
        long long score = 0 ;
        for(int i = 0 ; i<sq.size()/2; i++){
            score-=sq[i];
        }
        for(int i = sq.size()/2 ; i<sq.size(); i++){
            score+=sq[i];
       }
       return score;
    }
    
};