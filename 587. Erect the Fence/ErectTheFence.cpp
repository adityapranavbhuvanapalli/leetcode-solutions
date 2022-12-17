class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> upper;  // upper should be clockwise
        vector<vector<int>> lower;  // lower should be counter-clockwise
        set<vector<int>> uniq;

        // Sort the coords of trees
        sort(trees.begin(), trees.end());

        for(auto& t: trees) {
            // For upper (clockwise)
            while(upper.size() > 1 && angle(upper[upper.size()-2], upper[upper.size()-1], t) > 0)
                upper.pop_back();

            // For lower (anti clockwise)
            while(lower.size() > 1 && angle(lower[lower.size()-2], lower[lower.size()-1], t) < 0)
                lower.pop_back();

            upper.push_back(t);
            lower.push_back(t);
        }

        // Return the union of the coords in upper and lower
        for(auto& u: upper)
            uniq.insert(u);
        for(auto& l: lower)
            uniq.insert(l);
        return vector<vector<int>>(uniq.begin(), uniq.end());
    }

    int angle(vector<int>& c1, vector<int>& c2, vector<int>& c3) {
        // m = (y3-y2)(x2-x1) - (x3-x2)(y2-y1) 
        // Explanation to this is given below
        return (c3[1]-c2[1]) * (c2[0]-c1[0]) - (c3[0]-c2[0]) * (c2[1]-c1[1]);
    }
};

/*
For the optimal fence, we need to take the points that satisfy the following.
All the upper points need to be clockwise
All the lower points need to be counter clockwise

Take 3 points c1, c2, c3:
Diagram:
    c3.
     /
  c2. 
     \
    c1.

We need to find difference between slopes of the 2 lines from  c1, c2 and c2, c3:
say m = m32 - m21

m = y3-y2 _ y2-y1   
    x3-x2   x2-x1   

Ignore the denominator because we just have to calculate whether m is positive or negative
m = (y3-y2)(x2-x1) - (x3-x2)(y2-y1)

* m < 0, then it is clockwise
* m > 0, then it is counter clockwise
*/