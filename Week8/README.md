本周任务为
1. 现有两个数A, B, *并且A和B两个数中，有且仅有一个奇数*~~，这点课上忘记声明了，很重要~~，有如下程序片段，已知k是一个很大的数，`(k>1e10)`，请将其优化成运算次数大约为log2(k)级别。
    ```c
    int i = 0;
    for(i = 0; i < k; i ++){
      if(A >= B){
        A_ = A - B;
        B_ = B + B;
      }else{
        A_ = A + A;
        B_ = B - A;
      }
      A = A_;
      B = B_;
    }
    ```
    解法：
    > 考虑到在`if`和`else`中，`A_+B_`的结果都为`A+B`保持不变，从而可以将`A_=A-B=(A-B)%(A+B)=(A-B+(A+B))%(A+B)=(A+A)%(A+B)=(A*2)%(A+B)`
    > 同时，因为A和B有且仅有一个奇数，所以易得，不论运算到何时，A和B都恰有一个数为奇数，从而一定不会出现`A==B`的情况。ps：当A==B时，`B_=(B+B)%(A+B)=0`,会导致结果错误，从而无法使用快速幂性质

    [参考程序](1.c)

2. 输入n，计算斐波那契数的第n个`fib(n)%p`，`(p = 10007)`

    解法
    >具体内容依照上课所讲，简单表示如下：  
    > <a href="http://www.codecogs.com/eqnedit.php?latex=\begin{bmatrix}&space;F(n)&&space;F(n-1))\\&space;F(n-1)&&space;F(n-2)&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;F(n-1)&space;&&space;F(n-2)\\&space;F(n-2)&space;&F(n-3)&space;\end{bmatrix}&space;*&space;\begin{bmatrix}&space;1&space;&&space;1\\&space;1&space;&&space;0&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;F(2)&space;&F(1)&space;\\&space;F(1)&space;&&space;F(0)&space;\end{bmatrix}&space;*&space;{\begin{bmatrix}&space;1&space;&&space;1\\&space;1&space;&&space;0&space;\end{bmatrix}}^{n-2}" target="_blank"><img src="http://latex.codecogs.com/gif.latex?\begin{bmatrix}&space;F(n)&&space;F(n-1))\\&space;F(n-1)&&space;F(n-2)&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;F(n-1)&space;&&space;F(n-2)\\&space;F(n-2)&space;&F(n-3)&space;\end{bmatrix}&space;*&space;\begin{bmatrix}&space;1&space;&&space;1\\&space;1&space;&&space;0&space;\end{bmatrix}&space;=&space;\begin{bmatrix}&space;F(2)&space;&F(1)&space;\\&space;F(1)&space;&&space;F(0)&space;\end{bmatrix}&space;*&space;{\begin{bmatrix}&space;1&space;&&space;1\\&space;1&space;&&space;0&space;\end{bmatrix}}^{n-2}" title="\begin{bmatrix} F(n)& F(n-1))\\ F(n-1)& F(n-2) \end{bmatrix} = \begin{bmatrix} F(n-1) & F(n-2)\\ F(n-2) &F(n-3) \end{bmatrix} * \begin{bmatrix} 1 & 1\\ 1 & 0 \end{bmatrix} = \begin{bmatrix} F(2) &F(1) \\ F(1) & F(0) \end{bmatrix} * {\begin{bmatrix} 1 & 1\\ 1 & 0 \end{bmatrix}}^{n-2}" /></a>

    [参考程序](2.c)
