[문제해결 1-2] 알고리즘 수행시간

1. 알고리즘 수행시간 1
- 다음 코드의 수행 시간을 빅오표기법으로 나타내시오.
(
    #include <stdio.h>
    int main()
    {
        int n=0;
        int a=1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            printf("%d ",i);
        }
        return 0;
    }
)

=> O(n)


2. 알고리즘 수행시간 2
- 다음 코드의 수행 시간을 빅오표기법으로 나타내시오.
(
    #include <stdio.h>
    int main()
    {
        int n=0;
        int a=1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                printf("%d ",j);
            }
            printf("%d ",i);
        }
        return 0;
    }
)

=> O(n^2)


3. 알고리즘 수행시간 3
- 다음 코드의 수행 시간을 빅오표기법으로 나타내시오.
(
    #include <stdio.h>
    int main()
    {
        int n=0;
        int a=1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                for(int k=1; k<=n; k++)
                {
                    printf("%d ",k);
                }
                printf("%d ",j);
            }
            printf("%d ",i);
        }
        return 0;
    }
)

=> O(n^3)


4. 알고리즘 수행시간 4
▶ 다음 빅오표기법에 따른 수행시간들 중에서 시간이 큰순으로 나열하시오. (ex. 1-2-3-4-5-6-7-8)

1. O(n³)

2. O(n)

3. O(1)

4. O(n!)

5. O(n²)

6. O(logn)

7. O(2ⁿ)

8. O(nlogn)

=> 4-7-1-5-8-2-6-3


5. 알고리즘 수행시간 5
- 다음 코드의 수행 시간을 빅오표기법으로 나타내시오.
(
    #include <stdio.h>
    int main()
    {
        int n=0;
        int a=1;
        scanf("%d",&n);
        for(int i=1; i<n-1; i++)
        {
            for(int j=1; j<=n-2; j++)
            {
                for(int k=1; k<n; k++)
                {
                    printf("%d ",k);
                }
                printf("%d ",j);
            }
            printf("%d ",i);
        }
        return 0;
    }
)

=> O(n^3)