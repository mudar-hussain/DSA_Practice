class Solution {
    public int trap(int[] height) {
        int [] ngl = getNgl(height);
        int[] ngr = getNgr(height);
        int ans = 0;
        for(int i = 0; i<height.length; i++){
            ans = ans + Math.max(Math.min(ngl[i], ngr[i]) - height[i], 0);
        }
        return ans;
    }
    private int[] getNgl(int[] height){
        int[] ngl = new int[height.length];
        int maxi = 0;
        for(int i = 0; i<height.length; i++){
            ngl[i] = maxi;
            maxi = Math.max(maxi, height[i]);
        }
        return ngl;
    }
    private int[] getNgr(int[] height){
        int[] ngr = new int[height.length];
        int maxi = 0;
        for(int i = height.length-1; i>=0; i--){
            ngr[i] = maxi;
            maxi = Math.max(maxi, height[i]);
        }
        return ngr;
    }
}