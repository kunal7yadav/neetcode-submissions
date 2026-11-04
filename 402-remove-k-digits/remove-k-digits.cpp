class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<int>st;
        for(int i = 0 ; i<n ; i++){
            while(k>0 && st.size()>0 && st.top()>s[i]){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k>0 && st.size()>0){
            st.pop();
            k--;
        }
        stack<int>helper;
        while(st.size()>0){
            int x = st.top();
            st.pop();
            helper.push(x);
        }
        string ans = "";
        while(helper.size()>0){
            if(ans.size()==0 && helper.top()=='0'){
                helper.pop();
                continue;
            }
            ans+=helper.top();
            helper.pop();
        }
        if(ans.size()==0) return "0";
        return ans;

    }
};