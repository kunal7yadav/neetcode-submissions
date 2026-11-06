class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" ") return true;
        int n = s.length();
        string ws ;
        for(int i = 0 ; i<n ; i++){
            if(s[i]>='a' && s[i]<='z') ws.push_back(s[i]);
            else if(s[i]>='A' && s[i]<='Z'){
                char sh = tolower(s[i]);
                ws.push_back(sh);
            }
            else if(s[i]>=48 && s[i]<=57) ws.push_back(s[i]);
            else continue;
        }
        // if(ws.length()==1) return false;
        int i = 0 , j = ws.length()-1;
        while(i<j){
            if(ws[i]==ws[j]){
                i++;
                j--;
            }
            else{
                return false ;
                break;
            }
        }
        return true;

    }
};