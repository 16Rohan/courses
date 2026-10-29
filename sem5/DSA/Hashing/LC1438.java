import java.util.*;

public class LC1438 {
    
}
/**
 * Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 */
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int n = nums.length;
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                int mx = 0, mn = Integer.MAX_VALUE;
                for(int k = j; k <= i; k++){
                    if(nums[k] > mx) mx = nums[k];
                    if(nums[k] < mn) mn = nums[k];
                }

                if(Math.abs(mx - mn) <= limit) res = Math.max(res, i- j + 1); 
            }   
        }

        return res;
    }
}