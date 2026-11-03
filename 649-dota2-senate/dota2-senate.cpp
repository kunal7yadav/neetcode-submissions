class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int>q ; 
        queue<int>r;
        queue<int>d;
        for(int i = 0 ; i<n ; i++){
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        if(d.size()==0) return "Radiant";
        else if(r.size()==0) return "Dire";
        while(r.size()>0 && d.size()>0){
            if(senate[q.front()]=='R'){
                int x = q.front();
                q.pop();
                q.push(x);
                senate[d.front()]='X';
                d.pop();
                int y = r.front();
                r.pop();
                r.push(y);
            }
            else if(senate[q.front()]=='D'){
                int x = q.front();
                q.pop();
                q.push(x);
                senate[r.front()]='X';
                r.pop();
                int y = d.front();
                d.pop();
                d.push(y);
            }
            else{
                q.pop();
            }
            
            
        }
        if(r.size()>0) return "Radiant";
        else return "Dire";
    }
};