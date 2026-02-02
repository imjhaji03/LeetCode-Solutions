class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        n = len(nums)
        k_min = SortedList()
        remaining = SortedList()
        
        current_sum = 0
        target_size = k - 1
        
        for i in range(1, min(dist + 2, n)):
            k_min.add((nums[i], i))
            current_sum += nums[i]
            
            if len(k_min) > target_size:
                val, idx = k_min.pop(-1)
                current_sum -= val
                remaining.add((val, idx))
        
        ans = nums[0] + current_sum
        
        for i in range(dist + 2, n):
            out_pair = (nums[i - dist - 1], i - dist - 1)
            
            if out_pair in k_min:
                k_min.remove(out_pair)
                current_sum -= out_pair[0]
                if remaining:
                    val, idx = remaining.pop(0)
                    k_min.add((val, idx))
                    current_sum += val
            else:
                remaining.remove(out_pair)
                
            new_pair = (nums[i], i)
            k_min.add(new_pair)
            current_sum += new_pair[0]
            
            if len(k_min) > target_size:
                val, idx = k_min.pop(-1)
                current_sum -= val
                remaining.add((val, idx))
                
            ans = min(ans, nums[0] + current_sum)
            
        return ans