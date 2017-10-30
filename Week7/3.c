#include <stdio.h>
/*
a^x
考虑将x按照2进制形式拆分，设其为bx[len]，例如16，其二进制为1000，即bx[4] = 1000
那么，a^x = [(a^1) * bx[len-1]] * [(a^2) * bx[len -  2]] * [(a^4) * bx[len - 3]] * [(a^8) *bx[len - 3]] ... [(a^(2^len)) * bx[0]]
*/
int main(){
    int a,x;
    scanf("%d%d", &a, &x);
    int ans = 1, p = 10007;
    while(x > 0){
        if(x % 2 == 1)ans = ans * a % p; //判断当前这一位二进制是不是0
        a = a * a % p;//把底数变成平方
        x = x / 2;
    }
    printf("%d\n", ans);
    return 0;
}
