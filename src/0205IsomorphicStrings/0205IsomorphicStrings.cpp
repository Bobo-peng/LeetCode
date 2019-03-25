class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_arr[256] = {0};
        int t_arr[256] = {0};
        if(s.size() != t.size())
            return false;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s_arr[s[i]] != t_arr[t[i]])
                return false;
          s_arr[s[i]] = i + 1;//i+1表示第i个位置更新
          t_arr[t[i]] = i + 1;
        }
        return true;
    }
};