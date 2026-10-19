class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n =  gain.size() ; 
        vector<int> alti(n+1 , 0) ;
        for(int i = 1 ; i<n+1 ; i++){
            alti[i] = alti[i-1] + gain[i-1];
        }
        int hialti = INT_MIN;
        for(int i = 0 ; i<alti.size() ; i++){
            hialti = max(alti[i] , hialti);
        }
        return hialti;
    }
};