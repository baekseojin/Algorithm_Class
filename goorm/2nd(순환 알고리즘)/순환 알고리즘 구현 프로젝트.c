/* 
  프로젝트 개요

  (1) 프로젝트 이름 : 재귀함수로 엘리베이터 구현하기
  (2) 이 프로젝트를 하게 된 이유 : 양면에 거울이 설치된 엘리베이터에서 자신의 모습이 반복적으로 보이는 현상이
    재귀함수를 호출하는 현상과 비슷하다고 생각해서 한 번 재귀함수로 엘리베이터가 비치는 모습을 표현하고 싶었다.
  (3) 내가 제출하고 싶었던 결과물 : 만약 사용자가 5라는 정수를 입력하면 가로 5칸, 세로 5칸의 엘레베이터를 출력하고, 그 안에
    가로 4칸 세로 4칸의 엘레베이터, 가로3 세로3, 가로2 세로2, 그 안에 가로 1칸 세로 1칸의 엘레베이터를 출력하는 것이 나의 목표였다.
*/

/*

  * 규칙 찾아보기 *

  - 1칸 짜리 엘리베이터를 만들 때
  ┌ ─ ┐ (0,0) (0,1) (0,2)    (0,0) = ┌ , (0,1) = ─ , (0,2) = ┐  
  │   │ (1,0)       (1,2)    (1,0) = │ , (1,1) =   , (1,2) = │
  └ ─ ┘ (2,0) (2,1) (2,2)    (2,0) = └ , (2,1) = ─ , (2,2) = ┘

  - 3칸 짜리 엘리베이터를 만들 때
  ┌ ─ ─ ─ ┐ (0,0) (0,1) (0,2) (0,3) (0,4)    
  │       │ (1,0)                   (1,4)
  │       │ (2,0)                   (2,4)
  │       │ (3,0)                   (3,4)
  └ ─ ─ ─ ┘ (4,0) (4,1) (4,2) (4,3) (4,4)

  - 5칸 짜리 엘리베이터를 만들 때
  ┌ ─ ─ ─ ─ ─ ┐ (0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6)
  │           │ (1,0)                               (1,6)
  │           │ (2,0)                               (2,6)
  │           │ (3,0)                               (3,6)
  │           │ (4,0)                               (4,6)  
  │           │ (5,0)                               (5,6)  
  └ ─ ─ ─ ─ ─ ┘ (6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6)
  
*/

// 코드
#include <stdio.h>


int elevator(int k) {
  if(k==0) return 0; // 만약 전달인자가 0이면 0을 리턴하고 자기를 호출한 곳으로 이동
  
  // 맨 윗줄 출력 코드
  for(int i=0; i<k+2; i++) { // 만약 k=5이면, 반복문을 7번 돌림 (가로줄 5개와 양 옆 귀퉁이 1개씩 출력하기 위해서)
    if(i==0) {
      printf("┌ "); // 만약 i가 0이면 왼쪽 귀퉁이 출력
    }
    else if(i == (k+1)) { // 만약 i가 0이 아니고 k보다 1 크면 오른쪽 귀퉁이 출력
      printf("┐\n");
    }
    else { // 둘 다 아니면 가로줄 출력
      printf("─ ");
    }
  }
  
  // 중간 공간 출력 코드(2차원 배열 생성)
  for(int i=1; i<=k; i++) {  
    for(int j=0; j<=k+1; j++) {
      if(j==0) {
        printf("│ "); // 만약 j가 0이면 세로줄 출력 
      }
      else if(j==k+1) {
        printf("│\n"); // j가 0이 아니고 k보다 1 크다면 세로줄 출력
      }
      else {
        printf("  "); // 둘 다 아니면 공백 출력
      }
    }
  }

  // 맨 밑줄 출력 코드
  for(int i=0; i<k+2; i++) {
    if(i==0) {
      printf("└ "); // 만약 i가 0이면 왼쪽 귀퉁이 출력
    }
    else if(i==(k+1)) { 
      printf("┘\n"); // 만약 i가 0이 아니고 k보다 1 크다면 오른쪽 귀퉁이 출력
    }
    else {
      printf("─ "); // 둘 다 아니면 가로줄 출력
    }
  }
  elevator(k-1); // 재귀함수, 또 다른 elevator 함수를 호출하는데 전달인자(k)에 -1을 해서 elevator 함수를 출력한다. 
// 이 코드가 실행되면 elevator(4)가 실행되면서 또 엘리베이터를 출력하고, elevator(3)을 호출한다. elevator(3)은 다시 elevator(2)를 호출, elevator(2) -> elevator(1)을 차례대로 호출하고, elevator(0)을 호출할 때 반환값인 0을 반환한다. 이후 본인을 호출한 곳으로 다시 돌아가면서 main 함수로 돌아간다!
}

int main() {
  int n;
  scanf("%d", &n); // 정수 입력
  elevator(n); // elevator 함수 호출
  return 0;
}

/*
  프로젝트를 계획대로 하지 못한 이유 : 2차원 배열을 써서 출력을 하려고 했으나 기호를 배열 변수에 넣는 것이 어려웠다. 유니코드를 사용하려 했으나 결과가 제대로 나오지 않았고 결국 for문을 여러 번 돌려서 엘리베이터 구조를 출력하게 되었다. 하지만 for문을 돌려서 코드를 짜다 보니 정확한 위치를 지정해주기 어려웠고 결국 계획한 바인 엘리베이터 안에 엘리베이터가 나오는 모습을 출력하지 못하고 엘리베이터들이 따로 따로 출력되었다.
*/



// 이대로 프로젝트를 끝내기 아쉬워서 다른 블로그를 참고해서 만들어본 엘리베이터 프로그램

/*
  프로젝트 설명  
  - 현재 자신의 층수(1~10)를 입력받고 두 엘리베이터의 현재 위치는 랜덤으로 주어진다(rand 함수 이용)
  - 현재 층수에 더 가까운 엘리베이터가 이동한다고 출력한다.
*/

/* 코드(전체 주석을 지우면 실행 가능)

  // 현재 위치를 입력받아 리턴하는 함수
  int Location(int number) {
    return printf("현재 당신의 위치 : %d\n", number);
  }
  int main() {
	  int floor;
	  int el_1, el_2;
	  int el_1_array[10];
	  int el_2_array[10];
	  int i = 0;
	  int result_1;
	  int result_2;

	while (1) {
		// 1~10까지의 랜덤한 숫자 생성
		el_1 = rand() % 10 + 1;
		el_2 = rand() % 10 + 1;

		printf("현재 층수 입력 : ");

		
		if (scanf("%d", &floor) == 0) { // 숫자가 아닌 문자를 입력 받을 시 오류 문구 출력
			printf("Error!\n");
			rewind(stdin);	// 입력 버퍼 지우기
			i--;
			printf("\n\n");
		}
		else {
			if (floor == 0) { // 0을 입력시 반복문 탈출
				printf("\n\n");
				break;
			}
		if (floor >= 1 && floor <= 10) {
			Location(floor);	// 현재 위치를 입력받아 리턴하는 함수호출
			printf("첫 번째 엘리베이터 : %d \t 두 번째 엘리베이터 : %d \n", el_1, el_2);
			// 엘리베이터의 정보를 배열에 저장
			el_1_array[i] = el_1;
			el_2_array[i] = el_2;

			// 두 개의 엘리베이터와 나의 위치를 계산 후 절대값을 이용하여 가까운 엘리베이터를 구함
			result_1 = floor - el_1;
			result_2 = floor - el_2;
			if (abs(result_1) < abs(result_2)) {
				printf("첫 번째 엘리베이터가 이동합니다.");
			}
			if (abs(result_2) < abs(result_1)) {
				printf("두 번째 엘리베이터가 이동합니다.");
			}
			if (abs(result_1) == abs(result_2)) {
				printf("첫 번째 엘리베이터가 이동합니다..");
			}

			printf("\n\n");
		}
		else {		// 1~10 사이의 숫자가 아닌 수를 입력시 오류 출력
			i--;
			printf("Error!!\n");
			printf("\n\n");
		}
		}
		i++;
		if (i == 10) {
			break;
		}
	}

	// 결과 출력
	printf("=====================Result=====================");
	printf("\n첫 번째 엘리베이터  : ");
	// 반복문을 이용해서 배열을 출력
	for (int j = 0; j < 10; j++) {
		if (el_1_array[j] < 1 || el_1_array[j] > 10) { // 엘리베이터의 위치를 구하는 반복문에서 배열을 꽉채우지 않고 나올시
			el_1_array[j] = ' '; // 아직 안채워진 배열은 공백으로 만듬
		}
		else {
			printf("%3d", el_1_array[j]);
		}
	}
	printf("\n두 번째 엘리베이터 : ");
	for (int j = 0; j < 10; j++) {
		if (el_2_array[j] < 1 || el_2_array[j] > 10) {
			el_2_array[j] = ' ';
		}
		else {
			printf("%3d", el_2_array[j]);
		}
	}
	printf("\n\n");

	return 0;
}

*/