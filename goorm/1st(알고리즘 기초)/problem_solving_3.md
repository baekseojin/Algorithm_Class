1. 순환 알고리즘 1
- 다음 코드의 실행결과를 작성하시오.
(
    #include <stdio.h>
    int f(int a)

    {

        if(a==1) return 1;

        else return a*f(a-1);

    }

    int main()

    {

        int a=5;

        printf("%d",f(a));

        return 0;

    }
)

=> 120


2. 순환 알고리즘 2
- 다음 코드의 실행결과를 작성하시오.
(
    #include <stdio.h>
    int f(int a)

    {

        if(a==1) return 1;

        if(a==0) return 1;

        return f(a-1)+f(a-2);

    }

    int main()

    {

        int a=5;

        printf("%d",f(a));

        return 0;

    }
)

=> 8


3. 순환 알고리즘 3
- 다음 코드의 실행결과를 작성하시오.
(
    #include <stdio.h>
    void hanoi(int n,char a, char b, char c)

    {

        if(n==1)

        {

            printf("%d : %c -> %c\n",n,a,c);

        }

        else

        {

            hanoi(n-1,a,c,b);

            printf("%d : %c -> %c\n",n,a,c);

            hanoi(n-1,b,a,c);

        }

    }

    int main()

    {

        int n=3;

        hanoi(n,'A','B','C');

        return 0;

    }
)

=> 
( 1 : A -> C
2 : A -> B
1 : C -> B
3 : A -> C
1 : B -> A
2 : B -> C
1 : A -> C )