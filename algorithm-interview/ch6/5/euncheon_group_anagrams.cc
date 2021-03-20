#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

class MySolution {
public:
    string getKey(string a) {
        string key = string(78, '0');
        for (char ch : a) {
            int idx = ch - 'a';
            if (key[idx] == '9') {
                key[idx] = '0';
                if (key[idx+1] == '9'){
                    key[idx+1] = '0';
                    key[idx+2] = '1';
                }
                else {
                    key[idx+1] += 1;
                }
            }
            else {
                key[idx] += 1;
            }
        }
        
        return key;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > answer;
        unordered_map<string, int> key_and_index;
        int cnt_subvecs = 0;

        for (string s : strs) {
            string key = getKey(s);
            auto iter = key_and_index.find(key);
            if (iter == key_and_index.end()) {
                vector<string> temp_vec;
                answer.push_back(temp_vec);
                answer[cnt_subvecs].push_back(s);
                key_and_index.insert(make_pair(key, cnt_subvecs++));
            }
            else {
                int idx = iter->second;
                answer[idx].push_back(s);
            }
        }
        return answer;
    }
};

// https://leetcode.com/problems/group-anagrams/discuss/296470/49.-Group-Anagrams-C%2B%2B
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        unordered_map<string, int> key_value;
        //sort each string, and make it the key. 
        for(int i=0; i<strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            if(key_value.find(key)!=key_value.end()){
                //key is in the map: find the entrance in the group and push
                int location = key_value[key];
                group[location].push_back(strs[i]);
            }else{
                //key is not in the map: make new entrance in the group, and store its location in the map
                vector<string> temp(1, strs[i]);
                group.push_back(temp);
                
                int location = group.size()-1;
                key_value[key] = location;                
            }
        }
        return group;
    }
};