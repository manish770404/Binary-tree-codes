class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        unordered_map<int, unordered_map<int, int>> count;
        for (auto &p : pick)
        {
            count[p[0]][p[1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (auto &c : count[i])
            {
                if (c.second > i)
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};