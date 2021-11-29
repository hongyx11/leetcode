#ifndef HEADER_H
#define HEADER_H


#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
# define umap unordered_map;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right):
    val(x), left(left), right(right) {}
};


#endif 