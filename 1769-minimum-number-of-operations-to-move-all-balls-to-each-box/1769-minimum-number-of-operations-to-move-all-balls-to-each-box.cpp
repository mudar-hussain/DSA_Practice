class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int leftOnes = 0;
        int leftMovement = 0;
        int rightOnes = 0;
        int rightMovement = 0;
        vector<int> v(n);
        for(int i = 0; i<n; i++){
            if(boxes[i] == '1'){
                rightOnes++;
                rightMovement += i;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(boxes[i] == '1'){
                rightOnes--;
                rightMovement -= i;
            }
            v[i] = abs(leftMovement - leftOnes*i) + abs(rightMovement - rightOnes*i);
            
            if(boxes[i] == '1'){
                leftOnes++;
                leftMovement += i;
            }
        }
        
        return v;
        
        
        
    }
};