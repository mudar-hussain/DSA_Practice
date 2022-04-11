class Solution {
public:
    int numberOfRounds(string loginTime, string logoutTime) {
        int l1 = stoi(loginTime.substr(0,2))*60 + stoi(loginTime.substr(3,2));
        int l2 = stoi(logoutTime.substr(0,2))*60 + stoi(logoutTime.substr(3,2));
        
        if(l2 == 0) l2 = 1440;
        if(l1<l2 && abs(l1-l2) < 15) return 0;
        // cout<<l1<<" "<<l2;
        while(l1%15)l1++;
        while(l2%15) l2--;
        
        // cout<<l1<<" "<<l2;
        
        if(l1>l2) {
            l1 = 1440-l1;
            return (l1+l2)/15;
        }
        
        return abs(l1-l2)/15;
        
    }
};