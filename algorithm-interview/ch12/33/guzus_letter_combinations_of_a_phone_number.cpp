class Solution
{
public:
    vector<string> result;
    vector<vector<char>> alphabets = vector<vector<char>>({
        vector<char>(),
        vector<char>(),
        vector<char>({'a', 'b', 'c'}),
        vector<char>({'d', 'e', 'f'}),
        vector<char>({'g', 'h', 'i'}),
        vector<char>({'j', 'k', 'l'}),
        vector<char>({'m', 'n', 'o'}),
        vector<char>({'p', 'q', 'r', 's'}),
        vector<char>({'t', 'u', 'v'}),
        vector<char>({'w', 'x', 'y', 'z'}),
    });

    void dfs(string digits, string combination)
    {
        if (digits.compare("") == 0)
        {
            result.push_back(combination);
            return;
        }
        char digit = digits.front();
        digits.erase(0, 1);
        for (int i = 0; i < alphabets[digit - '0'].size(); i++)
        {
            char c = alphabets[digit - '0'][i];
            combination.push_back(c);
            dfs(digits, combination);
            combination.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() > 0)
        {
            dfs(digits, "");
        }

        return result;
    }
};