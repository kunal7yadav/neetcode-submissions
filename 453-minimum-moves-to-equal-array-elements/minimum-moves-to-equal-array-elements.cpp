class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = nums[0];
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mn = min(mn, nums[i]);
        }

        return sum - (long long)n * mn;
    }
};