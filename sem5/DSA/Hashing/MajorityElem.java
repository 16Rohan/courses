import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class MajorityElem {

}

class Solution3 {
    public List<Integer> majorityElement(int[] nums) {
        Set<Integer> katze = new HashSet<>();
        Map<Integer, Integer> seen = new HashMap<>();
        int n = nums.length;
        for (int x : nums) {
            if (!seen.containsKey(x)) {
                seen.put(x, 1);
            } else if (seen.containsKey(x)) {
                seen.put(x, seen.get(x) + 1);
            }
        }

        for (int x : nums) {
            if (seen.get(x) > (n / 3))
                katze.add(x);
        }
        
        List<Integer> ret = new ArrayList<>(katze);

        return ret;
    }
}

class Solution {
    public int majorityElement(int[] nums) {
        // Using Boyer Moore's Voting algoithm
        int candidate = 0, lead = 0;
        for (int i : nums) {
            if (lead == 0) {
                candidate = i;
                lead += 1;
            } else if (i == candidate)
                lead += 1;
            else {
                lead -= 1;
            }
        }
        if (lead > 0)
            return candidate;
        return -1;
    }
}

class Solution2 {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int x : nums) {
            if (hm.containsKey(x)) {
                hm.put(x, hm.get(x) + 1);
            } else {
                hm.put(x, 1);
            }
        }

        for (int x : hm.keySet()) {
            if (hm.get(x) > nums.length / 2)
                return x;
        }

        return -1;
    }
}