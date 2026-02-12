import java.util.*;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
       
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int h : happiness) {
            maxHeap.add(h);
        }

        long ans = 0; 
        int turns = 0;

        for (int i = 0; i < k; i++) {
            if (maxHeap.isEmpty()) break;
            
            int top = maxHeap.poll();
            
          
            int currentHappiness = Math.max(0, top - turns);
            
            if (currentHappiness == 0) break; 
            
            ans += currentHappiness;
            turns++;
        }

        return ans;
    }
}