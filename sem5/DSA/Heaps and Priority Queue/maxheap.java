import java.util.*;

class Node {
    public int val;
    public List<Node> neighbors;
}

class Solution {
    public Node cloneGraph(Node node) {
        // Your code goes here
        
        Deque<Node> bfs = new ArrayDeque<Node>();
        bfs.addLast(node);
        Set<Integer> seen = new HashSet();
        while(!bfs.isEmpty()){
            Node cur = bfs.removeFirst();
            seen.add(cur.val);

            for(Node n: cur.neighbors){
                if(!seen.contains(n.val)){
                    bfs.addFirst(n);
                }
                System.out.println(n.val);
            }
        }
        
        

        return new Node();
    }
}
