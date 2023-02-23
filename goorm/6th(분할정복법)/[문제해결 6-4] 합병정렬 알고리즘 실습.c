/*
부산소프트웨어마이스터고등학교 학생들을 키가 큰 순서대로 정렬하고자 한다. 방법은 합병정렬이며 정렬 과정에서의 각 단계를 출력하는 프로그램을 작성하시오.

▣ 입력설명

첫 줄에 학생의 수 N명이 입력된다(2<=N<=64)

둘째 줄에 N명의 키가 입력된다. (중복되는 키는 없다고 가정한다)

▣ 출력설명

합병정렬 과정에서의 각 단계를 출력한다.
*/
#include <stdio.h>
int sorted[100],count, n;
int list[65];
int h = 1;
void merge(int list[], int left,int mid, int right)
{
		
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid && j<=right)
    {
        if(list[i]>list[j])
        {
            sorted[k++]=list[i++];
        }
        else
        {
            sorted[k++]=list[j++];
        }
    }
    if(i>mid)
    {
        for(l=j; l<=right; l++)
        {
            sorted[k++]=list[l];
        }
    }
    else
    {
        for(l=i; l<=mid; l++)
        {
            sorted[k++]=list[l];
        }
    }
    for(l=left; l<=right; l++)
    {
        list[l]=sorted[l];
    }
		printf("%d단계 : ", h);
		for(int i=0; i<n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		h = h+1;
}

void mergesort(int list[], int left,int right)
{
		
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        mergesort(list,left,mid);
        mergesort(list,mid+1,right);
        merge(list,left,mid,right);
				
    }
}

int main()
{
    scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &list[i]);
		}
    mergesort(list,0,n-1);
    return 0;
}