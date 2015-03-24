class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
        {
            return 0;
        }
        if(s.size() == 1)
        {
            return 1;
        }
        int i = 0;
        int j = 0;
        int max = 0;
        unordered_map<char, bool> map;
        while(i < s.size() && j < s.size())
        {
            if(map[s[j]] == false)
            {
                map[s[j]] = true;
                int temp = j - i + 1;
                if (temp > max)
                    max = temp;
                j++;
            }
            else if(map[s[j]] == true)
            {
                int temp = j - i;
                if (temp > max)
                    max = temp;
                map[s[i]] = false;
                i++;
            }
        }
        return max;
    }
};