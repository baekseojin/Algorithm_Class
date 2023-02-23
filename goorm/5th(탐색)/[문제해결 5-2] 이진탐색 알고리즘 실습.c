/*
부산소프트웨어마이스터고등학교 학생들 중 원하는 키를 가진 학생을 탐색하고자 한다. 방법은 이진탐색이며 탐색에 성공하면 탐색횟수를 출력하고, 실패하면 "실패"를 출력하고 가능하지 않다면 "불가능"을 출력하시오. (탐색에 성공할 시 키가 오름차순 또는 내림차순으로 정렬되어 있을 것이며 반드시 재귀함수를 사용하시오)

▣ 입력설명

첫 줄에 학생의 수 N명이 입력된다(2<=N<=64)

둘째 줄에 N명의 키가 입력된다. (중복되는 키는 없다고 가정한다)

셋째 줄에 탐색하고자 하는 학생의 키 K가 입력된다.(150<=K<=190)

▣ 출력설명

탐색 성공 : 탐색횟수 출력

탐색 실패 : "실패" 출력

탐색 불가능 : "불가능" 출력
*/

#include <stdio.h>
#include <stdlib.h>
int cnt;
int search1(int arr[],int start, int end, int* key)
{
   if(start <= end){
         cnt++;
         int middle = (start + end) / 2;
         if      (*key == arr[middle]) return cnt;
         else if (*key <  arr[middle]) return search1(arr, start, middle-1, key);
         else if (*key >  arr[middle]) return search1(arr, middle+1, end, key);
   }
   cnt = 0;
   return -1;
}
int search2(int arr[],int start, int end, int* key)
{
   if(start <= end){
         cnt++;
         int middle = (start + end) / 2;
         if      (*key == arr[middle]) return cnt;
         else if (*key >  arr[middle]) return search2(arr, start, middle-1, key);
         else if (*key <  arr[middle]) return search2(arr, middle+1, end, key);
   }
   return -1;
}

int main()
{
   int arr[64], arr1[64], arr2[64];
   int n, key;
   scanf("%d",&n);
   for(int i = 0; i < n; i++) {
         scanf("%d", &arr[i]);
         arr1[i] = arr[i];
         arr2[i] = arr[i];
   }
   int temp;
   for(int i = 0; i < n-1; i++)
         for(int j = 0; j < n-1-i; j++) {
               if(arr1[j] > arr1[j+1]){
                     temp = arr1[j + 1];
                     arr1[j + 1] = arr1[j];
                     arr1[j] = temp;
               }
         }
   for(int i = 0; i < n-1; i++)
         for(int j = 0; j < n-1-i; j++) {
               if(arr2[j] < arr2[j+1]){
                     temp = arr2[j + 1];
                     arr2[j + 1] = arr2[j];
                     arr2[j] = temp;
               }
         }
   scanf("%d",&key);
   for(int i = 0; i < n; i++) {
         if (arr[i] != arr1[i] && arr[i] != arr2[i]) {
               printf("불가능");
               return 0;
         }
   }
   int result;
   if((result = search1(arr, 0, n-1, &key)) != -1);
   else if((result = search2(arr, 0, n-1, &key)) != -1);
   if (result == -1) printf("실패");
   else
      printf("%d",result);
   return EXIT_SUCCESS;
}