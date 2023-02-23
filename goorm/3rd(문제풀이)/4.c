#include <stdio.h>
int main() {
	int n,i;
	int arr[101]={};
	int max=0, min=100;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &arr[i]); 
		if(arr[i]>max) {
			max = arr[i]; 
		}
		if(arr[i]<min) { 
			min = arr[i];
		}
		else {
			;
		}
	}
	printf("%d", max-min);
	return 0;
}