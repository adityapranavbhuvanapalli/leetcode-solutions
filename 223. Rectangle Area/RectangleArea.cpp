class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2-ax1)*(ay2-ay1);    // Area of a
        int areaB = (bx2-bx1)*(by2-by1);    // Area of b

        // If rectangles do not intersect, return total area
        if(ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1 || ay1 >= by2)    
            return areaA + areaB;

        // If rectangles intersect return sum of areas - intersected area
        int areaIntersected = (min(ax2, bx2) - max(ax1, bx1)) * (min(ay2, by2) - max(ay1, by1));
        return (areaA + areaB) - areaIntersected;
    }
};