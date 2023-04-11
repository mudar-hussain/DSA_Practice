class Solution {
    unordered_map<int, string> um;
public:
    string intToRoman(int num) {
    um[1] = "I";
    um[4] = "IV";
    um[5] = "V";
    um[9] = "IX";
    um[10] = "X";
    um[40] = "XL";
    um[50] = "L";
    um[90] = "XC";
    um[100] = "C";
    um[400] = "CD";
    um[500] = "D";
    um[900] = "CM";
    um[1000] = "M";
        int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans = "";
        for(int i = 0; num>0 && i<13; i++){
            if(num>=values[i]){
                ans += um[values[i]];
                num -= values[i];
                i--;
            }
        }
        return ans;
    }
};