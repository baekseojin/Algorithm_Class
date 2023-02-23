#include <stdio.h>
int main() {
	int a,b,age,gender;
	scanf("%d-%d", &a, &b);
	age = a/10000; // 몫나누기로 앞 2자리 떼어내기
	gender = b/1000000; // 몫나누기로 앞 1자리 떼어내기
	if(gender==1 || gender==2) { // 1900년생
		if(gender==1) { // 남자면
			printf("%d M", 2019-(1900+age)+1);
		}
		else { // 여자면
			printf("%d W", 2019-(1900+age)+1);
		}
	}
	else { // 2000년생
		if(gender==3) { // 남자면
			printf("%d M", 2019-(2000+age)+1);
		}
		else { // 여자면
			printf("%d W", 2019-(2000+age)+1);
		}
	}
	return 0;
}