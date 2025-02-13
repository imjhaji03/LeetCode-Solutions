class Solution {
    public int minOperations(int[] nums, int k) {
        int count=0;
        PriorityQueue<Long> pq=new PriorityQueue<>();

        for(int i=0;i<nums.length;i++){
            pq.add((long)nums[i]);
        }
        while(pq.size()>=2 && pq.peek()<(long)k){
            long x=pq.poll(); //smallest
            long y=pq.poll();  //largest
            pq.add((long)x*2+y);
            count++;
        }
        return count;
        
    }
}