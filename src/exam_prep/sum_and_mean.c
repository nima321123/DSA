#include <stdio.h>
#include <stdlib.h>

void getSumAndMean(float *a, int n, float *sum, float *mean){
    for (int i = 0; i < n; i++){
        *sum += *(a + i);
    }
    *mean = *sum / n;
}

int main()
 {
  int i, N;
  float *arr,sum=0.0,mean=0.0;
  printf("How many elements? ");
  scanf("%d",&N);
  arr=(float*)malloc(sizeof(float)*N);
  printf("Input %d float values.\n",N);
  for (i=0;i<N;i++) scanf("%f",&arr[i]);
  getSumAndMean(arr,N,&sum,&mean);
  printf("sum=%.2f,\nmean=%.2f\n",sum,mean);
  free(arr);
  return 0; 
}