/*
부산소프트웨어마이스터고등학교 학생들 중 원하는 키를 가진 학생을 탐색하고자 한다. 방법은 순차탐색이며 탐색을 성공하면 탐색횟수를 출력하고, 실패하면 "실패"를 출력하시오. (반드시 함수 사용)

▣ 입력설명

첫 줄에 학생의 수 N명이 입력된다(2<=N<=64)

둘째 줄에 N명의 키가 입력된다. (중복되는 키는 없다고 가정한다)

셋째 줄에 탐색하고자 하는 학생의 키 K가 입력된다.(150<=K<=190)

▣ 출력설명

탐색 성공 : 탐색횟수 출력

탐색 실패 : "실패" 출력
*/

#include <stdio.h>
int n, key, result, count=0;
int arr[65] = {};

int search() {
	for(int i=0; i<n; i++) {
		count++;
		if(arr[i] == key) {
			return count;
		}
	}
	return -1;
}

int main() {
	scanf("%d\n", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d ", &key);
	result = search();
	if(result==-1) printf("실패");
	else printf("%d", result);
	return 0;
}