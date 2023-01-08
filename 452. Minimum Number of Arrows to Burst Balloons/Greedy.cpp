class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1, boundary;

        sort(points.begin(), points.end());
        
        boundary = points[0][1]; 
        for(auto& point: points) {
            // If point lies within right boundary, then update the boundary with min possible right boundary
            // otherwise it means that new arrow is required.
            if(point[0] <= boundary) 
                boundary = min(boundary, point[1]);
            else {
                count++;
                boundary = point[1];
            }
        }

        return count;
    }
};