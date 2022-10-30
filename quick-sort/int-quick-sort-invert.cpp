#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

bool check(int * arr, int n)
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
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition(int* arr, int l, int h)
{
    int x = arr[h];
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
void quickSort(int* arr, int l, int h)
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

void insertionSort(int* arr, int l, int h)
{
    int key;
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

void quickSortRc(int* A, int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p = partition(A, l, h);
        quickSortRc(A, l, p - 1);
        quickSortRc(A, p + 1, h);
    }
}

int table_based(string myText, int** tableBased)
{
    int myNumber = 0;
    for (size_t i = 0; i < myText.length(); i++)
    {
        myNumber += tableBased[i][myText[i]];
    }
    return myNumber;
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

    int* asciiIndex = new int [asciiSize];

    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        if (looper >= 64 && looper <= 90)
        {
            asciiIndex[looper] = looper - 64;
        }
        else if (looper >= 97 && looper <= 122)
        {
            asciiIndex[looper] = looper - 96;
        }
    }

    int tableBasedSize = 6;
    int** tableBased = new int* [tableBasedSize];

    for (size_t looper = 0; looper < tableBasedSize; looper++)
    {
        tableBased[looper] = new int[asciiSize]{0};
    }

    for (size_t tabloop = 0; tabloop < tableBasedSize; tabloop++)
    {
        for (size_t looper = 0; looper < asciiSize; looper++)
        {
            int mtp = 27;
            switch (tabloop)
            {
            case 0:
                mtp = pow(mtp, 5); 
                break;
            case 1:
                mtp = pow(mtp, 4); 
                break;
            case 2:
                mtp = pow(mtp, 3); 
                break;
            case 3:
                mtp = pow(mtp, 2); 
                break;
            case 4:
                mtp = pow(mtp, 1); 
                break;
            case 5:
                mtp = pow(mtp, 0); 
                break;
            default:
                break;
            }
            tableBased[tabloop][looper] = mtp * asciiIndex[looper];
            // cout << "table ke " << tabloop << "isinya " << mtp * asciiIndex[looper] << endl;
        }
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
    int* inlineArrNum = new int[arrSize];

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
    for (size_t looper = arrSize; looper -- > 0;)
    {
        inlineArrNum[looper] = table_based(inlineArr[looper], tableBased);
    }
    auto end2 = chrono::high_resolution_clock::now();
    // cout << "String to number conversion:" << chrono::duration<double>(end2 - begin2).count() << endl;

    auto begin3 = chrono::high_resolution_clock::now();
    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        int begin = markers[looper][0];
        int end = markers[looper][1];
        int counter = markers[looper][2];
        
        if (counter > 0) {
            quickSort(inlineArrNum, begin, end - 1);
        }
        
    }
    auto end3 = chrono::high_resolution_clock::now();
    
    bool checker = true;
    
    checker = check(inlineArrNum, arrSize);
    
    if (checker)
    {
        cout << chrono::duration<double>(end3 - begin3).count() << endl;
        // cout << "Total time:" << chrono::duration<double>(end3 - begin1).count() << endl;
    }
    else
    {
        cout << "Data error" << endl;
    }

    // for (size_t looper = 0; looper < arrSize; looper++)
    // {
    //     myFile << inlineArrNum[looper] << endl;
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