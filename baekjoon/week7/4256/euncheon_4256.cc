#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> preorder(1001);
vector<int> inorder(1001);

void print_postorder(int left, int right, int root_idx) {
  for (int i = left; i < right; i++)
  {
    if (inorder[i] == preorder[root_idx]) {
      int root_idx_left_subtree = root_idx + 1;
      int root_idx_right_subtree = root_idx + 1 + i - left; 
      // i - left is size of the left subtree
      print_postorder(left, i, root_idx_left_subtree);
      print_postorder(i+1, right, root_idx_right_subtree);

      cout << preorder[root_idx] << " ";
    }
  }
  
}

int main(void) {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num_testcases;
  cin >> num_testcases;

  while (num_testcases--) {
    int num_nodes;
    cin >> num_nodes;
    
    for (int i = 0; i < num_nodes; i++) {
      cin >> preorder[i];
    }
    for (int i = 0; i < num_nodes; i++) {
      cin >> inorder[i];
    }

    print_postorder(0, num_nodes, 0);
    cout << endl;
  }

  return 0;
}