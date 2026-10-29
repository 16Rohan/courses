import java.util.*;

class Solution {
    public int findDuplicate(int[] nums) {
        int fast = 0, slow = 0;

        do {
            fast = nums[nums[fast]];
            slow = nums[slow];

        } while (fast != slow);

        int x = 0;

        while (fast != x) {
            fast = nums[fast];
            x = nums[x];
        }

        return fast;
    }
}

class Solution2 {
    public int findDuplicate(int[] nums) {
        Set<Integer> hm = new HashSet<>();
        int dup = -1;
        for (int i : nums) {
            if (!hm.contains(i)) {
                hm.add(i);
            } else {
                dup = i;
                break;
            }
        }

        return 0;
    }
}