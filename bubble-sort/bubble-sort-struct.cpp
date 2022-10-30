#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

struct Datas {
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;
};

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

void swap(Datas* xp, Datas* yp)
{
    Datas temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(Datas* arr, int limit)
{
    int i, j;
    for (i = 0; i < limit - 1; i++)
    {
        for (j = 0; j < limit - i - 1; j++)
        {
            if (arr[j].one > arr[j + 1].one)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].one == arr[j + 1].one && arr[j].two > arr[j + 1].two)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three > arr[j + 1].three)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four > arr[j + 1].four)
            { 
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four == arr[j + 1].four && arr[j].five > arr[j + 1].five)
            { 
                swap(&arr[j], &arr[j + 1]);
            }
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four == arr[j + 1].four && arr[j].five == arr[j + 1].five && arr[j].six > arr[j + 1].six)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void driver(string inFile)
{
    string myText;
    ifstream myReadFile(inFile);
    // ofstream myFile(outFile);

    vector<string> datas;

    // put textfile data to vector
    // this step should not be timed
    while (getline(myReadFile, myText))
    {
        datas.push_back(myText);
    }

    myReadFile.close();

    int arrSize = datas.size();
    Datas * newArr = new Datas[arrSize];

    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        newArr[looper].one = datas[looper][0];
        newArr[looper].two = datas[looper][1];
        newArr[looper].three = datas[looper][2];
        newArr[looper].four = datas[looper][3];
        newArr[looper].five = datas[looper][4];
        newArr[looper].six = datas[looper][5];
    }

    auto begin1 = chrono::high_resolution_clock::now();
    bubble_sort(newArr, arrSize);
    auto end1 = chrono::high_resolution_clock::now();

    string* boolArr = new string[arrSize];
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        boolArr[looper] = string(1, newArr[looper].one) + newArr[looper].two + newArr[looper].three + newArr[looper].four + newArr[looper].five + newArr[looper].six;
    }

    bool checker = true;

    checker = check(boolArr, arrSize);

    if (checker)
    {
        cout << chrono::duration<double>(end1 - begin1).count() << endl;
    }
    else
    {
        cout << "Data error" << endl;
    }

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
    // cout << "2m" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     driver("../2m.txt");
    // }
    // cout << "3m" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     driver("../3m.txt");
    // }
    // cout << "10m" << endl;
    // for (size_t i = 0; i < 10; i++)
    // {
    //     driver("../10m.txt");
    // }

    system("pause");
}