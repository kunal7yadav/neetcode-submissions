class Solution {
public:
    int dayNumber(string s) {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int month = (s[0] - '0') * 10 + (s[1] - '0');
        int day   = (s[3] - '0') * 10 + (s[4] - '0');

        int total = 0;
        for (int i = 0; i < month - 1; i++) { 
            total += days[i];
        }
        return total + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        int a1 = dayNumber(arriveAlice);
        int a2 = dayNumber(leaveAlice);
        int b1 = dayNumber(arriveBob);
        int b2 = dayNumber(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (end < start) return 0;    
        return end - start + 1;
    }
};