//
// Created by 廖洲洲 on 2020/12/28.
//
#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(k<=0 || k>input.size())
            return result;
//        sort(input.begin(),input.end());
//        十大排序算法：选择排序，插入排序，冒泡排序，归并排序，希尔排序，快速排序，堆排序，计数排序，基数排序，桶排序
//        bubble_sort(input);
//        selection_sort(input);
//        insertion_sort(input);
        shell_sort(input);
        return vector<int>({input.begin(),input.begin()+k});
    }
    void exchange(vector<int> &input,int pos1,int pos2){
        if(pos1<0||pos2<0||pos1>=input.size()||pos2>=input.size())
            return;
        int tmp;
        tmp=input[pos1];
        input[pos1]=input[pos2];
        input[pos2]=tmp;
        return;
    }
    void bubble_sort(vector<int> &input){
        if(input.size()==0)
            return;
        for(int i=0;i<input.size()-1;i++){
            for(int j=0;j<input.size()-i-1;j++){
                if(input[j]>input[j+1]){
                    exchange(input,j,j+1);
                }
            }
        }
        return;
    }
    void selection_sort(vector<int> &input){
        for(int i=0;i<input.size()-1;i++){
            int min=i;
            for(int j=i+1;j<input.size();j++){
                if(input[j]<input[min]){
                    min=j;
                }
            }
            exchange(input,min,i);
        }
        return;
    }
    void insertion_sort(vector<int> &input){
        for(int i=1;i<input.size();i++){
            int j=i-1;
            int tmp=input[i];
            while(j>=0&&input[j]>tmp){
                input[j+1]=input[j];
                j--;
            }
            input[j+1]=tmp;
        }
    }
    void shell_sort(vector<int> &input){
        int gap,i,j;
        for(gap=input.size()>>1;gap>0;gap=gap>>1){
            for(i=gap;i<input.size();i+=gap){
                int tmp=input[i];
                j=i-gap;
                while (j>=0&&input[j]>tmp){
                    input[j+gap]=input[j];
                    j-=gap;
                }
                input[j+gap]=tmp;
            }
        }
        return;
    }
};
