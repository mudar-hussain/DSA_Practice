class Solution {
public:
    vector<int> headChar;
    
    int find(int x){
        if(headChar[x] == -1)
            return x;
        
        return headChar[x] = find(headChar[x]);
    }
    
    void Union(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        
        if(parentX == parentY)
            return;
        
        headChar[max(parentX, parentY)] = min(parentX, parentY);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        headChar.resize(26, -1);
        for(int i = 0; i<s1.size(); i++){
            Union(s1[i]-'a', s2[i]-'a');    //create groups
        }
        
        for(int i = 0; i<baseStr.length(); i++){
            baseStr[i] = find(baseStr[i] - 'a')+'a';
        }
        
        return baseStr;
    }
};













