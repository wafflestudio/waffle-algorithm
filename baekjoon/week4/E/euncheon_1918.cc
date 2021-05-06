/**
 * 0ms, 2020KB
 * time complexity: O(n)
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
  cin.tie(NULL);
  cin.sync_with_stdio(false);

  string input;
  string output = "";
  stack<char> op_stack;

  cin >> input;

  for (char c : input) {
    switch (c) {
      case '+':
      case '-':
        while (!op_stack.empty() && op_stack.top() != '(') {
          output += op_stack.top();
          op_stack.pop();
        }
        op_stack.push(c);
        break;
      case '*':
      case '/':
        while (!op_stack.empty() && op_stack.top() != '(' &&
               (op_stack.top() == '*' || op_stack.top() == '/')) {
          output += op_stack.top();
          op_stack.pop();
        }
        op_stack.push(c);
        break;
      case '(':
        op_stack.push(c);
        break;
      case ')': {
        while (op_stack.top() != '(') {
          output += op_stack.top();
          op_stack.pop();
        }
        op_stack.pop();
        break;
      }
      default:
        output += c;
    }
  }

  while (!op_stack.empty()) {
    output += op_stack.top();
    op_stack.pop();
  }

  cout << output << endl;
  return 0;
}