#include <stdio.h>
int main() {
	int n,i;
	int sum=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		if(n%i==0) {
			if(i!=n) {
				if(i*2==n) {
					printf("%d = ", i);
					sum+=i;
				}
				else {
					printf("%d + ", i);
					sum+=i;
				}
					
			}
			else {
				;
			}
		}
		else {
			;
		}
	}
	printf("%d", sum);
	return 0;
}