#include <cstdio>

void Hanio(int n, char a='a', char b='b', char c='c')
{
    if( n == 1 ){
        printf("%c -> %c\n", a, c);
        return;
    }
    Hanio(n-1, a, c, b);        //  从a->b移动n-1个盘子
    printf("%c -> %c\n", a, c); //  把剩下一个盘子从a->c
    Hanio(n-1, b, a, c);        //  把b n-1个盘子移动到c
}

int main()
{
    Hanio(3);

    return 0;
}