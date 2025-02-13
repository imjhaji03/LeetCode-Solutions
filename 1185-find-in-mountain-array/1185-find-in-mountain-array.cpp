/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakelement(MountainArray &mountainArr){
        
        int n = mountainArr.length();
        int l = 0;
        int r = n-1;

        while(l < r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                l = mid+1;
            }
            else {
                r = mid;
            }

        }
        return l;
    }

    int binarysearch(MountainArray &mountainArr, int l, int r, int target){

        while(l <= r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;

            }
            else if(target > mountainArr.get(mid)){
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return -1;
    }

    int reversebinarysearch(MountainArray &mountainArr, int l, int r, int target){

        while(l <= r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid) == target){
                return mid;

            }
            else if(target > mountainArr.get(mid)){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int idx = peakelement(mountainArr);

        int result_idx = binarysearch(mountainArr, 0, idx, target);

        if(result_idx != -1){
            return result_idx; 
        }

        result_idx = reversebinarysearch(mountainArr, idx+1, n-1, target);

        return result_idx;
    }
};