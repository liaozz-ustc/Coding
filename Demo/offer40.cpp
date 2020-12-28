//
// Created by 廖洲洲 on 2020/10/5.
//

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int cmp(const void *a, const void *b);

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(arrSize<=0||k<=0){
        *returnSize=0;
        return NULL;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize=k<=arrSize?k:arrSize;
    return arr;
}

int cmp(const void *a,const void *b){
    return *(int *)b<*(int *)a;
}
int main(){
    int data[100];
    for(int i=0;i<100;i++)
        data[i]=-i;
    qsort(data,100,sizeof(int),cmp);
    //sort(data,data+100);
    for(int i=0;i<100;i++)
        cout<<data[i]<<' ';
    return 0;
}

class Solution {
public:
    multiset<int,greater<int> > inSet;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> LeastNumbers;
        if(k<1 || arr.size()<k)
            return LeastNumbers;
        for(int i=0;i<arr.size();i++){
            if(i<k){
                inSet.insert(arr[i]);
            }
            else{
                if(arr[i]<*inSet.begin()){
                    inSet.erase(inSet.begin());
                    inSet.insert(arr[i]);
                }
            }
        }
        for(int i=0;i<k;i++){
            LeastNumbers.push_back(*inSet.begin());
            inSet.erase(inSet.begin());
        }
        return LeastNumbers;
    }
};