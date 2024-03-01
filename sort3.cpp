#include <iostream>
#include <ctime>


int FindSmallestPos(int array[], int start, int length)
{
    int small = start;

    for (int i = start; i < length; i++)
    {
        if (array[i] < array[small])
            small = i;
    }
    return small;
}


void SelectionSort(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int small = FindSmallestPos(array, i, length);
        std::swap(array[i], array[small]);
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
    SelectionSort(arr, len);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    std::cout << "Time to perform a selection sort on an array of " << len << " elements: " << search_time << " ms" << std::endl;

    delete[] arr;
    return 0;

}
