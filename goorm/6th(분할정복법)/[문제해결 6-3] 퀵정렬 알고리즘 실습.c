/*
부산소프트웨어마이스터고등학교 학생들을 키가 큰 순서대로 정렬하고자 한다. 방법은 퀵정렬이며 정렬 과정에서의 각 단계를 출력하는 프로그램을 작성하시오.

▣ 입력설명

첫 줄에 학생의 수 N명이 입력된다(2<=N<=64)

둘째 줄에 N명의 키가 입력된다. (중복되는 키는 없다고 가정한다)

▣ 출력설명

퀵정렬 과정에서의 각 단계를 출력한다.
*/

#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int n;
int list[65];
int j=0;
int partition(int list[], int left, int right) {
	int pivot, temp, low, high;
	low = left;
	high = right+1;
	pivot = list[left];
	do {
		do {
			low++;
		}while(list[low]>pivot && low<=right);
		do {
			high--;
		}while(list[high]<pivot);
		if(low<high) {
			swap(list[low], list[high], temp);
		}
	}while(low<high);
	swap(list[left], list[high], temp);
	return high;
}

void quicksort(int list[], int left, int right) {
	if(left<right) {
		j++;
		int q = partition(list, left, right);
		printf("%d단계 : ", j);
		for(int i=0; i<n; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		quicksort(list, left, q-1);
		quicksort(list, q+1, right);
	}
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d ", &list[i]);
	}
	quicksort(list, 0, n-1);
	return 0;
}
