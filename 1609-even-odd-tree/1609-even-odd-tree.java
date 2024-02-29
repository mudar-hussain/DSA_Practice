/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> que = new LinkedList<>();
        que.add(root);
        que.add(null);
        int res = 1;
        int curr = 0;
        int prev = -1;
        while(que.size()>1){
            if(res%2 == 0){
                prev = Integer.MAX_VALUE;
            }else{
                prev = Integer.MIN_VALUE;
            }
            while(que.peek() != null){
                TreeNode temp = que.poll();
                if(temp.val%2 != res%2 ||
                  res%2 == 0 && prev <= temp.val ||
                  res%2 != 0 && prev >= temp.val){
                    return false;
                }
                if(temp.left != null){
                    que.add(temp.left);
                }
                if(temp.right != null){
                    que.add(temp.right);
                }
                prev = temp.val;
            }
            que.poll();
            res++;
            que.add(null);
        }
        return true;
    }
}