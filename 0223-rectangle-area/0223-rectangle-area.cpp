class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        int rec1 = abs(ax1 - ax2) * abs(ay1 - ay2);
        int rec2 = abs(bx1 - bx2) * abs(by1 - by2);
        
       if (ax2 <= bx1 || bx2 <= ax1 || ay2 <= by1 || by2 <= ay1) {
            return rec1 + rec2;
        }
        pair<int, int> bottom_right = make_pair(max(ax1, bx1), max(by1, ay1));
        pair<int, int> top_left = make_pair(min(ax2, bx2), min(by2, ay2));
        

        return rec1+rec2-abs(bottom_right.first - top_left.first) *
               abs(bottom_right.second - top_left.second);
    }
};