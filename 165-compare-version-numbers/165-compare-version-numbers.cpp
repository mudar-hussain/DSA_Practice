class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        string v1 = "0", v2 = "0";
        int i = 0, j = 0;
        while(i<n1 || j<n2){
            
            while(i<n1 && version1[i] != '.'){
                v1 += version1[i];
                i++;
            }
            
            while(j<n2 && version2[j] != '.'){
                v2 += version2[j];
                j++;
            }
            int x = stoi(v1);
            int y = stoi(v2);
            if(x<y) return -1;
            else if(x>y) return 1;
            v1 = "0";
            v2 = "0";
            i++; j++;
        }
        return 0;
    }
};