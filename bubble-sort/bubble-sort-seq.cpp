#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

bool check(string *arr, int n)
{
    int i, j;
    bool result = true;
    ;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
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

void swap(string *xp, string *yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(string *arr, int limit)
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
    string *newArr = new string[arrSize];

    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        newArr[looper] = datas[looper];
    }

    auto begin1 = chrono::high_resolution_clock::now();
    bubble_sort(newArr, arrSize);
    auto end1 = chrono::high_resolution_clock::now();

    bool checker = true;

    checker = check(newArr, arrSize);

    if (checker)
    {
        cout << chrono::duration<double>(end1 - begin1).count() << endl;
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
    /*cout << "2m" << endl;
    driver("../2m.txt");
    cout << "3m" << endl;
    driver("../3m.txt");*/
    // cout << "10m" << endl;
    // driver("../10m.txt");

    system("pause");
}