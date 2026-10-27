class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        int psi[n];
        psi[0]=-1;
        st.push(0);
        for(int i = 1 ; i<n ; i++){
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i); 
        }    
        st = stack<int>();

        int nsi[n];
        nsi[n-1]=n;
        st.push(n-1);
        for(int i = n-2 ; i>=0 ; i--){
            while(st.size()>0 && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }

        int maxarea = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            int height = arr[i];
            int breadth = nsi[i]-psi[i]-1;
            int area= height*breadth;
            maxarea = max(maxarea , area);
        }
        return maxarea;
    }
};