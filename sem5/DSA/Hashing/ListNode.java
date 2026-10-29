import java.util.PriorityQueue;

class MergeK {
}

public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        ListNode res = new ListNode(0);
        ListNode tail = res;
        for(int i = 0;i<lists.length;i++)
        {
            if (lists[i] != null) {
                pq.add(lists[i]);
            }
        }
    
        while(!pq.isEmpty()){
            ListNode t = pq.poll();
            if(t.next != null) pq.add(t.next);
            t.next = null;
            tail.next = t;
            tail = t;
        }

        return res.next;
    }
}