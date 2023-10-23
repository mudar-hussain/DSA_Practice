class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer> si = new HashSet<>();
        Set<Integer> sj = new HashSet<>();
        for(int i = 0; i<matrix.length; i++){
            for(int j = 0; j<matrix[i].length; j++){
                if(matrix[i][j] == 0){
                    si.add(i);
                    sj.add(j);
                }
            }
        }
        
        for(Integer i: si){
            for(int j = 0; j<matrix[i].length; j++){
                matrix[i][j] = 0;
            }
        }
        
        for(Integer i: sj){
            for(int j = 0; j<matrix.length; j++){
                matrix[j][i] = 0;
            }
        }
        
    }
}