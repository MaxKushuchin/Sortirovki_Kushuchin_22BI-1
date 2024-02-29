#include <iostream>

//Это функция выполняет часть операций в алгоритме быстрой сортировки. Она находит правильное место для опорного элемента и разделяет массив на две части.
int pilot_replace(int array[], int start, int pivot)
{
	int i = start;
	while(i < pivot)
	{
		if(array[i] > array[pivot] && i == pivot - 1)
		{
			std::swap(array[i], array[pivot]);
			pivot --;
		}

		else if(array[i] > array[pivot])
		{
			std::swap(array[pivot - 1], array[pivot]);
			std::swap(array[i], array[pivot]);
			pivot --;
		}

		else i ++;
	}
	return pivot;
}


//Это функция реализует алгоритм быстрой сортировки. Она рекурсивно вызывает pilot_replace
void QuickSort(int array[], int start, int end)
{
	if(start < end)
	{
		int pivot = pilot_replace(array, start, end);

		QuickSort(array, start, pivot - 1);
		QuickSort(array, pivot + 1, end);
	}
}



//Это функция находит позицию наименьшего элемента в массиве, начиная с указанной позиции.
int FindSmallestPos(int array[], int start, int length)
{
	int small = start;

	for(int i = start; i < length; i++)
	{
		if(array[i] < array[small])
			small = i;
	}
	return small;
}

//Это функция реализует сортировку выбором, находя наименьший элемент и помещая его в начало массива (рекурсивно вызывает FindSmallestPos)
void SelectionSort(int array[], int length)
{
	for(int i = 0; i < length; i++)
	{
		int small = FindSmallestPos(array, i, length);
		std::swap(array[i], array[small]);
	}
}



//Это функция реализует сортировку пузырьком, последовательно сравнивая и меняя местами соседние элементы.
void BubbleSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1])
                std::swap(array[j], array[j + 1]);
        }
    }
}



int main()
{
    std::cout << "Enter the length of the array: ";
    int len;
    std::cin >> len;
    int *arr = new int[len];

    std::cout << "Fill in the array: \n";
    for (int i = 0; i < len; i++)
        std::cin >> arr[i];

    std::cout << "Input array: ";
    for (int i = 0; i < len; i++)
    std::cout << arr[i] << " ";

    QuickSort(arr, 0, len - 1);

    std::cout << "\nSorted array with Quick Sort: ";
    for (int i = 0; i < len; i++)
    std::cout << arr[i] << " ";

    SelectionSort(arr, len);

    std::cout << "\nSorted array with Selection Sort: ";
    for (int i = 0; i < len; i++)
    std::cout << arr[i] << " ";

    BubbleSort(arr, len);

    std::cout << "\nSorted array with Bubble Sort: ";
    for (int i = 0; i < len; i++)
    std::cout << arr[i] << " ";


    delete[] arr;

    return 0;

}

