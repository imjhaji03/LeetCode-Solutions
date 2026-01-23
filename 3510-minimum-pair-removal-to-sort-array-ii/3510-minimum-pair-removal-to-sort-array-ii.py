class Solution:
    def minimumPairRemoval(self, nums: list[int]) -> int:
        n = len(nums)
        temp = [int(x) for x in nums]
        
        min_pair_set = SortedList()
        next_index = [i + 1 for i in range(n)]
        prev_index = [i - 1 for i in range(n)]
        
        bad_pairs = 0
        for i in range(n - 1):
            if temp[i] > temp[i+1]:
                bad_pairs += 1
            min_pair_set.add((temp[i] + temp[i+1], i))
            
        operations = 0
        
        while bad_pairs > 0:
            pair_sum, first = min_pair_set.pop(0)
            second = next_index[first]
            
            first_left = prev_index[first]
            second_right = next_index[second]
            
            if temp[first] > temp[second]:
                bad_pairs -= 1
                
            if first_left >= 0:
                if temp[first_left] > temp[first] and \
                   temp[first_left] <= temp[first] + temp[second]:
                    bad_pairs -= 1
                elif temp[first_left] <= temp[first] and \
                     temp[first_left] > temp[first] + temp[second]:
                    bad_pairs += 1
                    
            if second_right < n:
                if temp[second_right] >= temp[second] and \
                   temp[second_right] < temp[first] + temp[second]:
                    bad_pairs += 1
                elif temp[second_right] < temp[second] and \
                     temp[second_right] >= temp[first] + temp[second]:
                    bad_pairs -= 1
            
            if first_left >= 0:
                min_pair_set.remove((temp[first_left] + temp[first], first_left))
                min_pair_set.add((temp[first_left] + temp[first] + temp[second], first_left))
                
            if second_right < n:
                min_pair_set.remove((temp[second] + temp[second_right], second))
                min_pair_set.add((temp[first] + temp[second] + temp[second_right], first))
                prev_index[second_right] = first
                
            next_index[first] = second_right
            temp[first] += temp[second]
            
            operations += 1
            
        return operations