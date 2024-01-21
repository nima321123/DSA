#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

/**
 * Write reduce function where func is one of "max", "min", "sum"
 * Return func(array)
*/
int reduce(int ** two_array, const char * func)
{
    if (strcmp(func, "max") == 0){
        int max_val = two_array[0][0];
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                if (two_array[i][j] > max_val) max_val = two_array[i][j];
            }
        }
        printf("\nMax = %d\n", max_val);
        return max_val;
    }
    
    if (strcmp(func, "min") == 0){
        int min_val = two_array[0][0];
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                if (two_array[i][j] < min_val) min_val = two_array[i][j];
            }
        }
        printf("\nMin = %d\n", min_val);
        return min_val;
    }
    
    if (strcmp(func, "sum") == 0){
        int sum_val = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                sum_val += two_array[i][j];
            }
        }
        printf("\nSum = %d\n", sum_val);
        return sum_val;
    }
}

/**
 * Write reduce function by axis where func is one of "max", "min", "sum"
 * The return value should be 1-dimensional array
 * Return func(array, axis)
*/
int * reduce_with_axis(int ** two_array, const char * func, int axis)
{
    int* result0 = malloc(4 * sizeof(int));
    int* result1 = malloc(3 * sizeof(int));
    if (strcmp(func, "max") == 0){
        if (axis == 1){ //row
            int max = 0;
            
            for (int i = 0; i < 3; i++){ //row
                max = two_array[i][0];
                for (int j = 0; j < 4; j++){ //column
                    if (two_array[i][j] > max)  max = two_array[i][j];
                }
                result1[i] = max;
            }
            for (int i = 0; i < 3; i++){
            printf("%d ", result1[i]);}
    
            return result1;

        }
        else if (axis == 0){//column
            int max = 0;
            int index = 0;
            for (int j = 0; j < 4; j ++){
                
                max = two_array[0][j];
                for (int i = 0; i < 3; i++){
                    if (two_array[i][j] > max) max = two_array[i][j];
                }
                result0[index] = max;
                index++;
            }
            for (int i = 0; i < 4; i++ ){
            printf("%d ", result0[i]);
            }
            return result0;
            
        }
    }
    else if (strcmp(func, "min") == 0){
        if (axis == 1){ //row
            int min = 0;
            
            for (int i = 0; i < 3; i++){ //row
                min = two_array[i][0];
                for (int j = 0; j < 4; j++){ //column
                    if (two_array[i][j] < min)  min = two_array[i][j];
                }
                result1[i] = min;
            }
            for (int i = 0; i < 3; i++){
            printf("%d ", result1[i]);}
            return result1;
        }
        else if (axis == 0){//column
            int min;
            int index = 0;
            for (int j = 0; j < 4; j++){
                min = two_array[0][j];
                for (int i = 0; i < 3; i++){
                    if (two_array[i][j] < min) min = two_array[i][j];
                }
                result0[index] = min;
                index++;
            }
            for (int i = 0; i < 4; i++ ){
            printf("%d ", result0[i]);
            }
            
        }
    }
    
    else if (strcmp(func, "sum") == 0){
        if (axis == 1){ //row
            int sum = 0;
            
            for (int i = 0; i < 3; i++){ //row
                sum = 0;
                for (int j = 0; j < 4; j++){ //column
                sum += two_array[i][j];
                }
                result1[i] = sum;
            }
            for (int i = 0; i < 3; i++){
            printf("%d ", result1[i]);}
            return result1;
            
        }
        else if (axis == 0){//column
            int sum;
            int index = 0;
            for (int j = 0; j < 4; j ++){
                sum = 0;
                for (int i = 0; i < 3; i++){
                sum += two_array[i][j];
                }
                result0[index] = sum;
                index++;
            }
            for (int i = 0; i < 4; i++ ){
            printf("%d ", result0[i]);
            }
            return result0;   
        }
    }
    
    
    
    
}

/**
 * Write transpose function to transpose NxM array -> MxN array

int ** transpose(int ** two_array, int N, int M)
{
    // allocate MxN array

    // return the transposed array
}*/

int main()
{
    // set random seed to current time
    srand(time(NULL));

    int N = 3, M = 4;
    // allocate NxM array
    int ** two_array = malloc(N * sizeof(int *)); // allocate N x (int *)
    for (int i = 0; i < N; i++)
    {
        two_array[i] = malloc(M * sizeof(int)); // allocate M x (int)

        // set random value (0->9) for each element of array
        for (int j = 0; j < M; j++)
        {
            two_array[i][j] = rand() % 10;
            printf("%d ", two_array[i][j]);
        }
        printf("\n");
    }
    char* response = malloc(3 * sizeof(char));
    printf("Enter the function you want to use: ");
    scanf("%s", response);
    int reduced = reduce(two_array, response);

    
    printf("Enter the function you want to use: ");
    scanf("%s", response);
    int axis;
    printf("Enter the axis you want to use: (0 for column, 1 for row)");
    scanf("%d", &axis);
    int * reduced_axis = reduce_with_axis(two_array, response, axis);

    //int ** transposed_array = transpose(two_array, N, M);

    return 0;
}