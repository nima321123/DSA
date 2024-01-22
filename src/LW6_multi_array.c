#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct MultiArray 
{
    int *data;
    int *shape;
};

/**
 * Indexing multi array using an index array
 * 
 * array [2][1] = get_data(array, [2, 1])
*/
int get_data(struct MultiArray * array, int * indexes)
{
    int row = indexes[0];
    int col = indexes[1];
    int num_cols = array->shape[1]; //mxn, the second element is the #columns
    int linear_index = row * num_cols + col; //use the formula
    return array->data[linear_index];
}

int main()
{
    // set random seed to current time
    srand(time(NULL));
    
    struct MultiArray * array = malloc(sizeof (struct MultiArray));

    // create 3x4 array
    array->data = malloc(3*4*sizeof(int));

    // assign random data (0 -> 9)
    for (int i = 0; i < 3*4; i++)
    {
        array->data[i] = rand() % 10;
        //printf("array->data[%d] = %d", i, array->data[i]);
    }

    // assign shape
    array->shape = malloc(2*sizeof(int));
    array->shape[0] = 3;
    array->shape[1] = 4;

    //print the 2D array
    for (int i = 0; i < ((array->shape[0])*(array->shape[1])); i++){
        printf("%d ", array->data[i]);
        if ((i+1) % 4 == 0) printf("\n");
    }

    int indexes[] = {2, 0};
    int out = get_data(array, indexes);
    printf("\narray[%d][%d] = %d", indexes[0], indexes[1], out);

    return 0;
}

