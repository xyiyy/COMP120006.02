#include <stdio.h>

/*
主要的思路参考README.md，其余主要是快速幂的应用，这点在上一周已经提到
*/
int main(){
    int A, B, k;
    scanf("%d%d%d",&A, &B, &k);
    int p = A + B;
    int x = 2;
    while(k > 0){
        if(k % 2 == 1){
            A = A * x  % p;
            B = B * x % p;
        }
        x = x * 2 % p;
        k = k / 2;
    }
    printf("A=%d, B=%d\n",A, B);
    return 0;
}
