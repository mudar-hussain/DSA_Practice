class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long ans = 0;
        bool neg = false;
        while(s[i] == ' ') i++;
        if(s[i] == '-') {
            neg = true;
            i++;
        }else if(s[i] == '+') i++;
        while(i<n){
            if(s[i] < '0' || s[i] > '9') break;
            ans = ans*10 + (s[i] - '0');
            
            if(neg && (-1)*ans<=INT_MIN) return INT_MIN;
            if(!neg && ans>=INT_MAX) return INT_MAX;
            i++;
            
        }
        if(neg) return (int)(-1)*ans;
        return (int)ans;
    }
};