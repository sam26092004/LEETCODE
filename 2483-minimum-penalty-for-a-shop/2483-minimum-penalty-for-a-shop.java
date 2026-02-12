class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int[] leftCount = new int[n + 1];
        int[] rightCount = new int[n + 1];

        for (int i = 0; i < n; i++) {
            leftCount[i + 1] = leftCount[i] + (customers.charAt(i) == 'N' ? 1 : 0);
        }

        for (int i = n - 1; i >= 0; i--) {
            rightCount[i] = rightCount[i + 1] + (customers.charAt(i) == 'Y' ? 1 : 0);
        }

        int ans = 0;
        int minPenalty = Integer.MAX_VALUE;

        for (int i = 0; i <= n; i++) {
            int currentPenalty = leftCount[i] + rightCount[i];
            if (currentPenalty < minPenalty) {
                minPenalty = currentPenalty;
                ans = i;
            }
        }
        
        return ans;
    }
}