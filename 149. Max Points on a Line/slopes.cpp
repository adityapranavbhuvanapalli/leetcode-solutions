class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxCount = 0;
        double slope;

         
        for(int i=0; i<n-1; i++) {
            // Find slopes of every pair possible with i
            unordered_map<double,int> slopeMap;
            for(int j=0; j<n; j++) {   
                if(i == j) 
                    continue;
                slope = findSlope(points[i], points[j]);
                slopeMap[slope]++;
                // Take the max count of points with same slopes wrt i
                maxCount = max(maxCount, slopeMap[slope]);
            }
        }
        return maxCount + 1;
    }

    // Function to find slope of 2 points
    double findSlope(vector<int>& a, vector<int>& b) {
        return ((double)(b[1] - a[1]))/((double)(b[0] - a[0]));
    }
};