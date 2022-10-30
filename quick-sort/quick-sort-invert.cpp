#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

bool check(string * arr, int n)
{
   int i, j;
   bool result = true;;
   for (i = 0; i < n-1; i++)
   {
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           result = false;
           break;
        }
     }
 
     // IF no two elements were swapped
     // by inner loop, then break
     if (result)
     {
         return result;
     }
   }

   return result;
}

// A utility function to swap two elements
void swap(string* a, string* b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition(string* arr, int l, int h)
{
    string x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSort(string* arr, int l, int h)
{
    // Create an auxiliary stack
    int* stack = new int[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void insertionSort(string* arr, int l, int h)
{
    string key;
    int i, j;
    for (i = l; i < h; i++)
    {
        key = arr[i];
        j = i - 1;
 
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSortRc(string* A, int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSortRc(A, l, p - 1);
        quickSortRc(A, p + 1, h);
    }
}

void driver(string inFile)
{
    string myText;
    ifstream myReadFile(inFile);
    // ofstream myFile(outFile);

    vector<string> datas;

    // create ascii table with empty value for counter
    int asciiSize = 128;
    int** markers = new int* [asciiSize];

    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        markers[looper] = new int[3]{ 0 };
    }

    // put textfile data to vector
    // this step should not be timed
    while (getline(myReadFile, myText))
    {
        datas.push_back(myText);
    }

    myReadFile.close();

    int arrSize = datas.size();
    string* newArr = new string[arrSize];
    string* inlineArr = new string[arrSize];

    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        newArr[looper] = datas[looper];
    }

    // start counting each word by the first letter
    auto begin1 = chrono::high_resolution_clock::now();
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        markers[int(newArr[looper][0])][1] += 1;
    }

    // add begin and end for each array
    for (size_t looper = 0; looper < asciiSize; looper++)
    {

        if (looper == 0) {
            markers[looper][0] = 0;
            markers[looper][1] = markers[looper][1];
        }
        else {
            markers[looper][0] = markers[looper - 1][1];
            markers[looper][1] = markers[looper][0] + markers[looper][1];
        }
    }

    for (size_t looper = arrSize; looper -- > 0;)
    {
        int ascii = int(newArr[looper][0]);
        int start = markers[ascii][0];
        int count = start + markers[ascii][2];
        inlineArr[count] = newArr[looper];
        markers[ascii][2] += 1;
    }
    auto end1 = chrono::high_resolution_clock::now();
    // cout << "Data preparation:" << chrono::duration<double>(end1 - begin1).count() << endl;
        
    auto begin2 = chrono::high_resolution_clock::now();
    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        int begin = markers[looper][0];
        int end = markers[looper][1];
        int counter = markers[looper][2];

        if (counter > 0) {
            quickSort(inlineArr, begin, end - 1);
        }
    }
    auto end2 = chrono::high_resolution_clock::now();
    
    bool checker = true;
    
    checker = check(inlineArr, arrSize);
    
    if (checker)
    {
        cout << chrono::duration<double>(end2 - begin2).count() << endl;
        // cout << "Total time:" << chrono::duration<double>(end2 - begin1).count() << endl;
    }
    else
    {
        cout << "Data error" << endl;
    }

    // for (size_t looper = 0; looper < arrSize; looper++)
    // {
    //     myFile << inlineArr[looper] << endl;
    // }

    // myFile.close();
}


int main()
{

    cout << "1k" << endl;
    driver("../1k.txt");
    cout << "10k" << endl;
    driver("../10k.txt");
    cout << "100k" << endl;
    driver("../100k.txt");
    cout << "1m" << endl;
    driver("../1m.txt");
    // cout << "2m" << endl;
    // driver("../2m.txt");
    // cout << "3m" << endl;
    // driver("../3m.txt");
    // cout << "10m" << endl;
    // driver("../10m.txt");

    system("pause");
}