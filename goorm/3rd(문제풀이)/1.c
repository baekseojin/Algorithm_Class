#include <stdio.h>

int main() {
	int n,m,i,sum=0;
	scanf("%d %d", &n, &m); // 15, 3 입력 
	for(i=1; i<=n; i++) {
		if(i%m==0) {
			sum += i;
		}
		else {
			;
		}
	}
	printf("%d", sum);
	return 0;
}