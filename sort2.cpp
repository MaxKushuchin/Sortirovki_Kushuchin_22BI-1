#include <iostream>
#include <ctime>


int pilot_replace(int array[], int start, int pivot)
{
    int i = start;
    while (i < pivot)
    {
        if (array[i] > array[pivot] && i == pivot - 1)
        {
            std::swap(array[i], array[pivot]);
            pivot--;
        }

        else if (array[i] > array[pivot])
        {
            std::swap(array[pivot - 1], array[pivot]);
            std::swap(array[i], array[pivot]);
            pivot--;
        }

        else i++;
    }
    return pivot;
}

void QuickSort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = pilot_replace(array, start, end);

        QuickSort(array, start, pivot - 1);
        QuickSort(array, pivot + 1, end);
    }
}




int main()
{

    srand(time(0));

    std::cout << "Enter the length of the array: ";
    int len;
    std::cin >> len;
    int* arr = new int[len];

    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }

    unsigned int start_time = clock();
    QuickSort(arr, 0, len - 1);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    std::cout << "Time to perform a quick sort on an array of " << len << " elements: " << search_time << " ms" << std::endl;

    delete[] arr;
    return 0;

}
