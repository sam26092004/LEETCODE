import java.util.*;

class Solution {

    List<String> ans = new ArrayList<>();

    public void countIpAddresses(String s, int idx, int parts, String tmp) {

      
        if (parts == 4 && idx == s.length()) {
            ans.add(tmp.substring(0, tmp.length() - 1)); 
            return;
        }

      
        if (parts == 4 || idx >= s.length()) {
            return;
        }

        for (int len = 1; len <= 3; len++) {

            if (idx + len > s.length()) break;

            String segment = s.substring(idx, idx + len);

           
            if (segment.length() > 1 && segment.charAt(0) == '0')
                continue;

            int value = Integer.parseInt(segment);

            if (value <= 255) {
                countIpAddresses(s, idx + len, parts + 1,
                        tmp + segment + ".");
            }
        }
    }

    public List<String> restoreIpAddresses(String s) {
        countIpAddresses(s, 0, 0, "");
        return ans;
    }
}
