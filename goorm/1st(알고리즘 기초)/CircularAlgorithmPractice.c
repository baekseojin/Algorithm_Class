/*
    [알고리즘 기초] 순환 알고리즘 실습
    10진수 n을 입력받아 2진수로 변환하여 출력하는 프로그램을 작성하고자 한다. 함수 f를 작성하여 제출하시오. (반드시 재귀함수 사용할 것)
*/

#include <stdio.h>
void f(int n)
{
    if(n>1) f(n/2);
    printf("%d", n%2);
}

int main() {
    int n;
	scanf("%d",&n);
	f(n);
	return 0;
}
