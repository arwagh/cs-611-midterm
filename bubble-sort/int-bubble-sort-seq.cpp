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

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int* arr, int limit)
{
    int i, j;
    for (i = 0; i < limit - 1; i++)
    {
        for (j = 0; j < limit - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
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
        inlineArrNum[looper] = table_based(newArr[looper], tableBased);
    }
    auto end1 = chrono::high_resolution_clock::now();
    // cout << "String to number conversion:" << chrono::duration<double>(end1 - begin1).count() << endl;
    
    auto begin2 = chrono::high_resolution_clock::now();
    bubble_sort(inlineArrNum, arrSize);
    auto end2 = chrono::high_resolution_clock::now();

    bool checker = true;
    
    checker = check(inlineArrNum, arrSize);

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
    //     myFile << inlineArrNum[looper] << endl;
    // }

    // myFile.close();
}


int main()
{
    cout << "1k" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
        driver("../1k.txt");
    // }
    cout << "10k" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
        driver("../10k.txt");
    // }
    cout << "100k" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
        driver("../100k.txt");
    // }
    cout << "1m" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
        driver("../1m.txt");
    // }
    system("pause");
}