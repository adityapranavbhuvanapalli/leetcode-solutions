class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> answer;
        int count, sum;

        // Sorting the array
        sort(nums.begin(), nums.end());

        // Processing each query
        for(auto& query: queries) {
            count = 0;
            sum = 0;

            // Find the prefix sum until the sum is just greater than the query
            for(auto& num: nums) {
                sum += num;
                if(sum > query)
                    break;
                count++;
            }
            answer.push_back(count);
        }

        return answer;
    }
};