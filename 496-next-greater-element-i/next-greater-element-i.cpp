class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int nge[n];
        stack<int> st;
        nge[n-1] = -1;
        st.push(nums2[n-1]);
        for(int i = n-1 ; i>=0 ; i--){
            while(st.size()>0 && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.size()==0) nge[i]=-1;
            else nge[i] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        int i = 0 ,  j = 0 ;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                ans.push_back(nge[j]);
                i++;
                j=0;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};