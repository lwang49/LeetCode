class Solution {
public:
    //Manacher's Algorithm
    //add # to the string and ^ and $ to both end to indicate boundary 
    string process(string s){
        int n = s.length();
        if(n == 0)
            return "^$";
        string ret = "^";
        for(int i = 0; i < s.length(); i++)
            ret += "#" + s.substr(i,1);
        ret += "#$";
        return ret;
    }
    //now we search
    string longestPalindrome(string s) {
        string T = process(s);
        int n = T.length();
        int *P = new int[n];
        int C = 0;
        int R = 0;
        for(int i = 1; i < n - 1; i++){
            int i_mirror = 2 * C - i;
            if(R > i)
                P[i] = min(R - i, P[i_mirror]);
            else
                P[i] = 0;
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
                P[i]++;
            if(P[i] + i > R)
            {
                C = i;
                R = P[i] + i;
            }
        }
        int max = 0;
        int center = 0;
        for(int i = 1; i < n - 1; i++)
        {
            if(P[i] > max)
            {
                max = P[i];
                center = i;
            }
        }
        delete[] P;
        return s.substr((center - 1 - max)/2, max);
    }
};