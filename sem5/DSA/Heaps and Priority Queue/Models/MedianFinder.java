package Models;

import java.util.ArrayList;
import java.util.List;

public class MedianFinder {

    List<Integer> arl;
    public MedianFinder() {
        arl = new ArrayList<>();
    }   
    
    public void addNum(int num) {
        this.arl.add(num);
    }
    
    public double findMedian() {
        int len = this.arl.size();
        if(len % 2 != 0){
            return this.arl.get(len/2);
        }
        else{
            return this.arl.get(len/2) + this.arl.get(len/2 - 1);
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
}
