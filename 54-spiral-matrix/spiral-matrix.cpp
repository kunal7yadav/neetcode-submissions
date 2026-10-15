class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> res;
       int minr = 0 , maxr = arr.size()-1 , maxc = arr[0].size()-1 , minc = 0 ; 
       while(minc<=maxc && maxr>=minr){
            for(int j = minc ; j<=maxc ; j++){
                res.push_back(arr[minr][j]);
            }
            minr++;
            for(int j = minr ; j<=maxr ; j++){
                res.push_back(arr[j][maxc]);
            }
            maxc--;
            if(minr<=maxr){
                for(int j = maxc ; j>=minc ; j--){
                    res.push_back(arr[maxr][j]);
                }
            }
            maxr--;
            if(minc<=maxc){
                for(int i = maxr ; i>=minr ; i--){
                    res.push_back(arr[i][minc]);
                }
            }
            minc++;
        }
        return res;
    }
};