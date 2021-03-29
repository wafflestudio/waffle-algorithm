/*
0ms, 6.4MB
time complexity: O(n)
space complexity: O(n)
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;
        
        for (char c : s) {
            switch(c) {
                case '(':
                case '[':
                case '{':
                    bracket_stack.push(c);
                    break;
                case ')':{
                    if (bracket_stack.empty()) return false;
                    
                    if (bracket_stack.top() == '(') { bracket_stack.pop(); }
                    else { return false; }
                    break;
                }
                case ']':{
                    if (bracket_stack.empty()) return false;
                    
                    if (bracket_stack.top() == '[') { bracket_stack.pop(); }
                    else { return false; }
                    break;
                }
                case '}':{
                    if (bracket_stack.empty()) return false;
                    
                    if (bracket_stack.top() == '{') { bracket_stack.pop(); }
                    else { return false; }
                    break;
                }
                default: return false;
            }
        }
        
        
        return bracket_stack.empty();
    }
};