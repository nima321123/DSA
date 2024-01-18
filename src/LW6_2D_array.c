#include <stdlib.h>
#include <time.h>

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
                if (two_array[i][j] > temp) temp = two_array[i][j];
            }
        }
        return max_val;
    }
    
    if (strcmp(func, "min") == 0){
        int min_val = two_array[0][0];
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                if (two_array[i][j] < temp) temp = two_array[i][j];
            }
        }
        return min_val;
    }
    
    if (strcmp(func, "sum") == 0)){
        int sum_val = two_array[0][0];
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                sum_val += two_array[i][j];
            }
        }
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
    // allocate 1d array

    // return the reduced array
}


/**
 * Write transpose function to transpose NxM array -> MxN array
*/
int ** transpose(int ** two_array, int N, int M)
{
    // allocate MxN array

    // return the transposed array
}

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
            printf("array[%d][%d] = %d\n", i, j, two_array[i][j]);
        }
    }

    int reduced = reduce(two_array, "max");

    int * reduced_axis = reduce_with_axis(two_array, "max", 1);

    int ** transposed_array = transpose(two_array, N, M);

    return 0;
}