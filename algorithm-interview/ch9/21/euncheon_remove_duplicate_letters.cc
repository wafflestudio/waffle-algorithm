/*
Solution using stack
n: input length, m: the number of unique characters in string
time complexity: O(n^2)
space complexity: O(n)
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> letters_set;
        vector<char> letters_stack;
        vector<int> left_letters(26, 0);
        string result = "";
        
        for (char c : s) {
            left_letters[c-'a'] += 1;
        }
        
        for (char c : s) {
            left_letters[c-'a'] -= 1;
            
            if (letters_set.find(c) != letters_set.end()){
                continue;
            }
            
            while(not letters_stack.empty()) {
                char top = letters_stack.back();
                
                if(c < top && left_letters[top-'a'] > 0){
                    letters_set.erase(top);
                    letters_stack.pop_back();
                }
                else {
                    break;
                }
            }
            letters_stack.push_back(c);
            letters_set.insert(c);
        }
        
        result = string{letters_stack.begin(), letters_stack.end()};
        
        return result;
    }
};