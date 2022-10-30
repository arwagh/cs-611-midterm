#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

bool check(string* arr, int n)
{
    int i, j;
    bool result = true;;
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

void swap(string* xp, string* yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(string* arr, int* limit)
{
    int i, j;
    for (i = 0; i < limit[1] - limit[0] - 1; i++)
    {
        for (j = limit[0]; j < limit[1] - i - 1; j++)
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
        // cout << "ascii: " << ascii << ", start: " << start << ", count: " << count << endl;
        inlineArr[count] = newArr[looper];
        markers[ascii][2] += 1;
    }
    auto end1 = chrono::high_resolution_clock::now();
    // cout << "Data preparation:" << chrono::duration<double>(end1 - begin1).count() << endl;
    
    auto begin2 = chrono::high_resolution_clock::now();
    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        // cout << inlineArr[looper] << endl;
        bubble_sort(inlineArr, markers[looper]);
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
    //     cout << newArr[looper] << endl;
    //     cout << inlineArr[looper] << endl;
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