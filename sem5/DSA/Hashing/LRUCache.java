import java.util.LinkedHashMap;

/**
 * 
 * LRUCache
 * 
 * Page replacement algorithm. 
 */


class CircularQ{
    int[] queue;
    int capacity;
    int front = 0, rear = 0;

    public CircularQ(int capacity){
        queue = new int[capacity];
        this.capacity = capacity;
    }

    private void incrementFront(){
        front = (front + 1) % capacity; 
    }

    private void incrementRear(){
        rear = (rear + 1) % capacity;
    }

}

public class LRUCache {
    int cap;

    LinkedHashMap<Integer, Integer> cache;

    public LRUCache(int capacity) {
        cap = capacity;
        cache = new LinkedHashMap<>(cap, 0.75f, true);
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        return -1;
    }

    public void put(int key, int value) {
        cache.put(key, value);
        if(cache.size() > cap){
            int LRUKey = cache.keySet().iterator().next();
            cache.remove(LRUKey);
        }
    }
}
