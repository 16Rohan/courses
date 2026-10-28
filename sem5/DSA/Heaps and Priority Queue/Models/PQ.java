import java.util.*;

// Find the kth larges element in the array 

public class PQ {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> (a == b) ? 0 : (a > b ? 1 : -1) );
        // a - b is MAX Heap, b - a is MIN Heap
        
        for(int i = 0; i < nums.length; i++){
            if(i < k) pq.add(nums[i]);
            else if(nums[i] > pq.peek()){
                pq.poll();
                pq.add(nums[i]);
            }
        }

        return pq.peek();
        
    }       
}   
