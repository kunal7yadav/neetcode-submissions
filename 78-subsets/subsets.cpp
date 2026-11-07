class Solution {
public:
void helper(vector<int>ans , vector<int>original , vector<vector<int>>&finalans , int idx ){
    if(idx==original.size()){
        finalans.push_back(ans);
        return;
    }
    helper(ans , original , finalans, idx+1);
    ans.push_back(original[idx]);
    helper(ans, original , finalans , idx+1);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>finalans;
        helper(ans , nums , finalans , 0);
        return finalans;
        
    }
};