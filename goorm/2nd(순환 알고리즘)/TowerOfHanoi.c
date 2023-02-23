/*
하노이탑 심화문제
- 다음 코드를 실행했을 때 출력결과를 작성하시오.
*/

#include <stdio.h>

int count,count1;

void hanoi(int n,char a, char b, char c)

{

    if(n<=1)

    {

        printf("%d : %c -> %c\n",n,a,c);

    }

    else

    {

        hanoi(n-1,a,c,b);

        count1++;

        printf("%d : %c -> %c\n",n,a,c);

        hanoi(n-3,b,a,c);

    }

    count++;

}

int main()

{

    int n=4;

    hanoi(n,'A','B','C');

    printf("%d %d",count,count1);

    return 0;

}
/* 
출력 결과 => (
1 : A -> B
2 : A -> C
-1 : B -> C
3 : A -> B
0 : C -> B
4 : A -> C
1 : B -> C
7 3
)

*/