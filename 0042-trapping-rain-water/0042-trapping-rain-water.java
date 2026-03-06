class Solution {
    public int trap(int[] height) {
        int leftmost[] = new int[height.length];
        leftmost[0] = height[0];

        for(int i = 1; i < height.length; i++){
            leftmost[i] = Math.max(height[i], leftmost[i-1]);
        }
        
        int rightmost[] = new int[height.length];
        rightmost[height.length-1] = height[height.length-1];

        for(int i = height.length-2; i >= 0; i--){
            rightmost[i] = Math.max(height[i], rightmost[i+1]);
        }

        int trappedwater = 0;
        for(int i = 0; i < height.length; i++){
            int waterlevel = Math.min(rightmost[i], leftmost[i]);
            trappedwater += (waterlevel - height[i]) * 1;
        }

        return trappedwater;
    }
}