//
// Created by 廖洲洲 on 2020/10/2.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        int **c=(int **)malloc((n+1)*sizeof(int *));
        for(int i=0;i<=n;i++)
            c[i]=(int *)malloc((n+1)*sizeof(int));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                c[i][j]=0;
        for(int i=1;i<=n;i++)
            c[i][1]=i;
        int tmp;
        for(int i=2;i<=n;i++){
            for(int j=2;j<=i;j++){
                for(int m=1;m<=i-j+1;m++){
                    tmp=c[i-m][j-1]*m;
                    if(tmp>c[i][j]) {
                        c[i][j] = tmp;
                    }
                }
            }
        }
        tmp=0;
        for(int j=2;j<=n;j++){
            if(c[n][j]>tmp)
                tmp=c[n][j];
        }
        for(int i=0;i<n;i++)
            free(c[i]);
        free(c);
        return tmp;
    }
};

class Solution2 {
public:
    int cuttingRope(int n) {
        if(n<=1)
            return 0;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        int *product=(int *)malloc((n+1)*sizeof(int));
        product[0]=0;
        product[1]=1;
        product[2]=2;
        product[3]=3;
        int max;
        int tmp;
        for(int i=4;i<=n;i++){
            max=0;
            for(int j=1;j<i;j++){
                tmp=product[j]*product[i-j];
                if(tmp>max){
                    max=tmp;
                }
            }
            product[i]=max;
        }
        max=product[n];
        free(product);
        return max;
    }
};