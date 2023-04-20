#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#include <math.h>
#define max_element 100000                      // Максимальный элемент массива
double wtime()
{
 struct timeval t;
 gettimeofday(&t, NULL);
 return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
int getrand(int min, int max)
{
 return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}
// Функция создает массив, заполняет его случайными числами и возвращает указатель на него, аргументом является количество элементов в этом массиве
uint32_t* getArray(int size)                                              
{
    uint32_t* array = (uint32_t*)calloc(size,sizeof(uint32_t));
    for (int i = 0;i < size;i++)
        array[i] = getrand(0,max_element+1);
    return array;
}
// Функция сортировки подсчетом: На вход получает массив для сортировки, максимальный элемент массива, количество элементов в массиве. Возвращает отсортированный массив
void CountSort(uint32_t* array, int maxelement, int size)
{
    uint32_t* countarray = (uint32_t*)calloc(maxelement+1,sizeof(uint32_t));
    for (int i = 0;i < size;i++)                          // Заполняет массив подсчета количеством повторяющихся элементов
        ++countarray[array[i]];
    int s = 0;
    for (int i = 0;i < maxelement+1;i++)
        for (int j = 0;j < countarray[i];j++)
            array[s++] = i;
    free(countarray);
}
void InsertionSort(uint32_t* array, int size)
{
int i, j, temp;
for (i = 1; i < size; i++)
{
    temp = array[i];
    for (j = i - 1; j >= 0; j--)
    {
        if (array[j] < temp)
            break;
  
        array[j + 1] = array[j];
        array[j] = temp;
    }
}
}
void Merge(uint32_t* array, int low, int mid, int high)
{
    uint32_t* mergearray = (uint32_t*)calloc(high - low + 1,sizeof(uint32_t));
    for (int i = low; i <= high; i++)
        mergearray[i - low] = array[i];
    int lowLeft = low - low;
    int lowRight = mid - low + 1;
    int i = low;
    while ((lowLeft <= mid - low) && (lowRight <= high - low))
        {
            if (mergearray[lowLeft] <= mergearray[lowRight])
            {
                array[i] = mergearray[lowLeft];
                lowLeft++;    
            } else
            {
                array[i] = mergearray[lowRight];
                lowRight++;
            }
            i++;
        }
    while (lowLeft <= mid - low)
        {
            array[i] = mergearray[lowLeft];
            lowLeft++;
            i++;
        }
    while (lowRight <= high - low)
        {
            array[i] = mergearray[lowRight];
            lowRight++;
            i++;
        }
    free(mergearray);
}
void MergeSort(uint32_t* array, int low, int high)
{
    
    if (low < high)
        {
            int mid = (int)floor((low + high) / 2);
            MergeSort(array, low, mid);
            MergeSort(array, mid + 1, high);
            Merge(array, low, mid, high);
        }

}
int main()
{
    // int G = 0;
    int N = 0;                                           // Количество элементов в массиве
    FILE* data = fopen("sort.dat", "w+t");
    double time;
    // uint32_t* countarray = getArray(N);
    // for (N = 50000;N<=1000000;N+=50000)
    //     {
    //         fprintf(data, "%d\t",N);
    //         time = wtime();
    //         CountSort(countarray, max_element, N);
    //         fprintf(data,"%f\t",(wtime()-time));
    //         countarray = (uint32_t*) realloc(countarray,sizeof(uint32_t)*(N));
    //     }

    //  uint32_t* countarray = getArray(N);
    // uint32_t* insertarray = getArray(N);
    // uint32_t* mergarray = getArray(N);
    // for (N = 50000;N<=1000000;N+=50000)
    //     {
    //         fprintf(data, "%d\t",N);
    //         time = wtime();
    //         CountSort(countarray, max_element, N);
    //         fprintf(data,"%f\t",(wtime()-time));
    //         time = wtime();
    //         InsertionSort(insertarray, N);
    //         fprintf(data,"%f\t",(wtime()-time));
    //         time = wtime();
    //         MergeSort(mergarray,0,N-1);
    //         fprintf(data,"%f\n",(wtime()-time));
    //         G++;
    //     }
    
    
        for (N = 10000; N <= 150000; N += 10000)
    {
        fprintf(data, "%d   ", N);
        
        uint32_t* countarray = getArray(N);
        time = wtime();
        CountSort(countarray, max_element, N);
        fprintf(data, "\t%f", (wtime() - time));
        
        uint32_t* insertarray = getArray(N);
        time = wtime();
        InsertionSort(insertarray, N);
        fprintf(data, "\t%f", (wtime() - time));
        
        uint32_t* mergarray = getArray(N);
        time = wtime();
        MergeSort(mergarray, 0, N - 1);
        fprintf(data, "\t%f\n", (wtime() - time));
        
    }
    
    
    
    return 0;
}

