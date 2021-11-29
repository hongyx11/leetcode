#include <iostream>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int helper(int *a, int * vis, int numSize, int k, int curSum, int curidx, int target){
    if(k == 1) return 1;
    int tempcurSum = curSum;
    if(curSum == target) return helper(a, vis, numSize, k-1, 0, numSize-1, target);
    for(int i=curidx; i >=0; i--){
        if( vis[i] == 0 && curSum + a[i] <= target ) {
            vis[i] = 1;
            if(helper(a, vis, numSize, k, curSum + a[i], i-1, target)) return 1;
            vis[i] = 0;
        }
    }
    return 0;
}

bool canPartitionKSubsets(int* a, int numSize, int k){
    int vis[20];
    memset(vis, 0, sizeof(int) * 20);
    int totalSum = 0;
    qsort(a, numSize, sizeof(int), cmp);
    for(int i=0; i<numSize; i++) totalSum += a[i];
    if(totalSum % k != 0) return 0;
    int target = totalSum / k;
    if(a[numSize-1] > target) return 0;
    return helper(a, vis, numSize, k, 0, numSize-1, target);
}

int main(){
    int a[4] = {1,2,3,4};
    int k = 4;
    int numSize = 4;
    int res = canPartitionKSubsets(a, numSize, k);
    printf("res %d \n", res);
    return 0;
}
