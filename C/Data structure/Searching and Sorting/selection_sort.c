
                                //SELECTION SORT
#include <stdio.h>
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int count=0;
void selectionSort(int arr[], int n)
{
	int i, j, min;
	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[min])
                min = j;
        }
		swap(&arr[min], &arr[i]);
	}

}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int i,n;
    printf("\nEnter size of array to be sorted: ");
    scanf("%d",&n);
    int array[n];
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("\nArray elements without applying Insertion sort: ");
    printArray(array, n);
    selectionSort(array,n);
	printf("\nSorted array: ");
	printArray(array, n);
	printf("\nTotal number of comparison: %d",count);
	return 0;
}
