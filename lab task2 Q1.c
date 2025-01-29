#include <stdio.h>

int main() {
    int n;
    printf("enter n=");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<=n-1;i++){
        printf("enter %d",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<=n-1;i++){
        printf("%d",arr[i]);
    }
    int av;
    printf("enter av=");
    scanf("%d",&av);
    int sum=0;
  for(int i=0;i<=av-1;i++){
      sum=sum+arr[i];
  }
  float average=sum/(av);
  printf("the average =%f",average);
    return 0;
}