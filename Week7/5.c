#include <stdio.h>

int main(){
    int n, i , j, m;
    scanf("%d",&n);
    m = 2 * n - 1;
    for(i = 0; i < m; i ++){
        for(j = 0 ; j < m; j ++){
            if((i < n && (j >= n - 1 - i&& j <= n - 1 + i)) || (i >= n && (j >= n - 1 - (m - 1 - i) && j <= n - 1 + (m - 1 - i)))){
                printf(".|.");
            }else{
                printf("---");
            }
        }
        printf("\n");
    }
    return 0;
}
