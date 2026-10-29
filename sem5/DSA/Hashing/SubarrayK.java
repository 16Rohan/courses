import java.util.*;

public class SubarrayK {

}

class Solution {
    /**
     * @param nums
     * @param k
     * @return r
     */
    public int subarraySun(int[] nums, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        hm.put(0, 1);
        int prefixsum = 0, result = 0;
        for (int i : nums) {
            prefixsum += i;
            if (hm.containsKey(prefixsum - k)) {
                result += hm.get(prefixsum - k);
            }
            hm.put(prefixsum, hm.getOrDefault(prefixsum, 0) + 1);
        }

        return result;
    }
}