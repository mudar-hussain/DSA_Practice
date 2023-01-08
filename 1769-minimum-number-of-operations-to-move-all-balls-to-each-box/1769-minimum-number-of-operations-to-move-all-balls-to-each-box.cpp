class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> v(n,0);
        for(int i = 0; i<n; i++){
            int movement = 0;
            for(int j = 0; j<n; j++){
                if(boxes[j] == '1'){
                    movement += abs(j-i);
                }
            }
            v[i] = movement;
        }
        return v;
    }
};