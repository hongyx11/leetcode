#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

int translate(char * word, int *map){
    int res = 0;
    for(int i=0; i<strlen(word); i++){
        res = 10 * res + map[(int)word[i] - (int)'A'];
    }
    return res;
}

bool addvalue(char ** words, int wordsSize, char * result, int *map){
    int leftVal = 0, rightVal = 0;
    for(int i=0; i<wordsSize; i++){
        leftVal += translate(words[i], map);
    }
    rightVal = translate(result, map);
    return leftVal == rightVal;
}


class Solution {
public:
    set<char> firstletterset;
    int translate(string& word, unordered_map<char, int>& cmap){
        int val = 0;
        for(int i=0; i<word.size(); i++){
            val = 10 * val + cmap[word[i]];
        }
        return val;
    }
    bool addvalue(vector<string>& words, string result, unordered_map<char,int>& cmap){
        int leftval = 0, rightval = 0;
        for(int i=0; i<words.size(); i++) leftval += translate(words[i], cmap);
        rightval = translate(result, cmap);
        return leftval == rightval;
    }
    bool helper(unordered_map<char, int>& cmap, vector<char>& mapkey, int sidx, 
        vector<string>& words, string result){
            if(sidx == cmap.size()) return addvalue(words, result, cmap);
            char curchar = mapkey[sidx];
            int startnum = firstletterset.find(curchar) == firstletterset.end() ? 0 : 1;
            int i;
            for(i=startnum; i<10; i++){

                bool taken = false;
                for(auto it = cmap.begin(); it != cmap.end(); it++){
                    if(it->second == i){
                        taken = true;
                    }
                }
                if(!taken){
                    cmap[curchar] = i;
                    if(helper(cmap, mapkey, sidx+1, words, result)) return true;
                    cmap[curchar] = -1;
                }
            }
            return false;
        }

    bool isSolvable(vector<string>& words, string result) {
        for(auto x : words) firstletterset.insert(x[0]);
        firstletterset.insert(result[0]);
        unordered_map<char, int> cmap;
        for(size_t i=0; i<words.size(); i++){
            for(size_t j=0; j<words[i].size(); j++){
                cmap[words[i][j]] = -1;
            }
        }
        for(size_t i=0; i<result.size(); i++) cmap[result[i]] = -1;
        vector<char> mapkey;
        for(auto it=cmap.begin(); it != cmap.end(); it++) mapkey.push_back(it->first);
        return helper(cmap, mapkey, 0, words, result);
    }
};


int main(){
    vector<string> words;
    words.push_back("SEND");
    words.push_back("MORE");
    string result = "MONEY";
    Solution s1 = Solution();
    bool res = s1.isSolvable(words, result);
    cout << res << endl;
    return 0;
}