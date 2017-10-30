#include <stdio.h>
#include <string.h>

char X[10010],Y[10100];//如果开在函数里面，请记得初始化

void reverseStr(char *str, int n){
    // 将长度为n的字符串str反转
    char temp;
    int i,j;
    for(i = 0, j = n - 1; i < j ; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void AplusB(char *A, char *B){
    int lenA = strlen(A), lenB = strlen(B);
    reverseStr(A,strlen(A));//将数字反转
    reverseStr(B,strlen(B));
    int len = lenA >= lenB ? lenA :lenB; // 取len为长度较大的值
    int carry = 0, i; // carry表示进位
    for(i = 0 ; i < len ; i++){
        if(A[i] < '0')A[i] = '0';//如果当前位不是数字，则将其变为0
        if(B[i] < '0')B[i] = '0';
        A[i] += (B[i] - '0') + carry;//将当前位上的两个数相加，并且算上低位的进位
        /*
        以上为了简便，并没有先将A里面的字符变成数值，而是只将B里面的字符变成数值再加上去。即原本应该写成
        A[i] = (A[i] - '0') + (B[i] - '0') + carry + '0'
        */
        carry = 0; //算完后需要重新将进位变为0
        if(A[i] > '9'){//如果当前位的数超过9，则需要进位
            carry = 1;
            A[i] -= 10; //因为两个个位数相加的和肯定不会到20，所以进位最多为1。如果换做乘法，请自行考虑
        }
    }
    /*
    考虑诸如 999 + 1 = 1000 的特例
    */
    if(carry){//如果最高位还有进位，再往上进的最高位必定为1
        A[len] = '1';
        len ++;//为了方便下面将这个字符串反转
    }
    reverseStr(A, len);//记得把两个反转的数，转回来
    reverseStr(B,lenB);
}

int main(){
    int n;
    scanf("%d", &n);
    /*
    F(0) = 0, F(1) = 1
    F(x+2) = F(x+1) + F(x)
    在程序中，我们可以每次将大的数加到小的数上面去，所以只需要通过两个数组即可
    */
    Y[0] = '0';
    X[0] = '1';
    if(n == 0){
        printf("%s\n",Y);
    }else{
        int i = 0,j;
        char temp;
        for(; i < n - 1; i ++){//第一次循环算的是F(2)，第二次是F(3)
            AplusB(Y,X);
            int len = strlen(Y);//因为这个时候Y的值更大，所以肯定Y的位数多
            for(j = 0; j < len; j ++){//将X和Y对换一下
                temp = X[j];
                X[j] = Y[j];
                Y[j] = temp;
            }
        }
        printf("%s\n",X);
    }
    return 0;
}
