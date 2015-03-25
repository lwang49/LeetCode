class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hashmap;
        vector<int> results;
        for(int i = 0; i < numbers.size(); i++)
        {
            hashmap[numbers[i]] = i;
        }
        for(int i = 0; i < numbers.size();i++)
        {
            int gap = target - numbers[i];
            if(hashmap.find(gap) != hashmap.end() && hashmap[gap] != i)
            {   
                if(hashmap[gap] > i)
                {
                    results.push_back(i + 1);
                    results.push_back(hashmap[gap] + 1);
                }
                else
                {
                    results.push_back(hashmap[gap] + 1);
                    results.push_back(i + 1);
                }
                
            }
        }
        return results;
    }
};