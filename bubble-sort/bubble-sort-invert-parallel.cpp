#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

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

    // move a
    thread aThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 97)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // aThread.join();

    // move b
    thread bThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 98)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // bThread.join();

    // move c
    thread cThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 99)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // cThread.join();

    // move d
    thread dThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 100)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // dThread.join();

    // move e
    thread eThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 101)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // eThread.join();

    // move f
    thread fThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 102)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // fThread.join();

    // move g
    thread gThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 103)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // gThread.join();

    // move h
    thread hThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 104)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // hThread.join();

    // move i
    thread iThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 105)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // iThread.join();

    // move j
    thread jThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 106)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // jThread.join();

    // move k
    thread kThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 107)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // kThread.join();

    // move l
    thread lThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 108)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // lThread.join();

    // move m
    thread mThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 109)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // mThread.join();

    // move n
    thread nThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 110)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // nThread.join();

    // move o
    thread oThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 111)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // oThread.join();

    // move p
    thread pThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 112)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // pThread.join();

    // move q
    thread qThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 113)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // qThread.join();

    // move r
    thread rThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 114)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // rThread.join();

    // move s
    thread sThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 115)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // sThread.join();

    // move t
    thread tThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 116)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // tThread.join();

    // move u
    thread uThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 117)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // uThread.join();

    // move v
    thread vThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 118)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // vThread.join();

    // move w
    thread wThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 119)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // wThread.join();

    // move x
    thread xThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 120)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // xThread.join();

    // move y
    thread yThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 121)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    // yThread.join();

    // move z
    thread zThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 122)
                {
                    markers[int(newArr[looper][0])][1] += 1;
                }
            }
        }
    );

    aThread.join();
    bThread.join();
    cThread.join();
    dThread.join();
    eThread.join();
    fThread.join();
    gThread.join();
    hThread.join();
    iThread.join();
    jThread.join();
    kThread.join();
    lThread.join();
    mThread.join();
    nThread.join();
    oThread.join();
    pThread.join();
    qThread.join();
    rThread.join();
    sThread.join();
    tThread.join();
    uThread.join();
    vThread.join();
    wThread.join();
    xThread.join();
    yThread.join();
    zThread.join();

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

    // move a
    thread aFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 97)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // aFillerThread.join();

    // move b
    thread bFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 98)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // bFillerThread.join();

    // move c
    thread cFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 99)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // cFillerThread.join();

    // move d
    thread dFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 100)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // dFillerThread.join();

    // move e
    thread eFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 101)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // eFillerThread.join();

    // move f
    thread fFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 102)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // fFillerThread.join();

    // move g
    thread gFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 103)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // gFillerThread.join();

    // move h
    thread hFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 104)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // hFillerThread.join();

    // move i
    thread iFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 105)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // iFillerThread.join();

    // move j
    thread jFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 106)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // jFillerThread.join();

    // move k
    thread kFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 107)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // kFillerThread.join();

    // move l
    thread lFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 108)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // lFillerThread.join();

    // move m
    thread mFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 109)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // mFillerThread.join();

    // move n
    thread nFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 110)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // nFillerThread.join();

    // move o
    thread oFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 111)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // oFillerThread.join();

    // move p
    thread pFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 112)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // pFillerThread.join();

    // move q
    thread qFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 113)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // qFillerThread.join();

    // move r
    thread rFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 114)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // rFillerThread.join();

    // move s
    thread sFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 115)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // sFillerThread.join();

    // move t
    thread tFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 116)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // tFillerThread.join();

    // move u
    thread uFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 117)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // uFillerThread.join();

    // move v
    thread vFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 118)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // vFillerThread.join();

    // move w
    thread wFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 119)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // wFillerThread.join();

    // move x
    thread xFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 120)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // xFillerThread.join();

    // move y
    thread yFillerThread(
        [&] {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(newArr[looper][0]) == 121)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    // yFillerThread.join();

    // move z
    thread zFillerThread(
        [&] {
            for (size_t looper = arrSize; looper -- > 0;)
            {
                if (int(newArr[looper][0]) == 122)
                {
                    int ascii = int(newArr[looper][0]);
                    int start = markers[ascii][0];
                    int count = start + markers[ascii][2];
                    inlineArr[count] = newArr[looper];
                    markers[ascii][2] += 1;
                }
            }
        }
    );

    aFillerThread.join();
    bFillerThread.join();
    cFillerThread.join();
    dFillerThread.join();
    eFillerThread.join();
    fFillerThread.join();
    gFillerThread.join();
    hFillerThread.join();
    iFillerThread.join();
    jFillerThread.join();
    kFillerThread.join();
    lFillerThread.join();
    mFillerThread.join();
    nFillerThread.join();
    oFillerThread.join();
    pFillerThread.join();
    qFillerThread.join();
    rFillerThread.join();
    sFillerThread.join();
    tFillerThread.join();
    uFillerThread.join();
    vFillerThread.join();
    wFillerThread.join();
    xFillerThread.join();
    yFillerThread.join();
    zFillerThread.join();

    auto end1 = chrono::high_resolution_clock::now();
    // cout << "Data preparation:" << chrono::duration<double>(end1 - begin1).count() << endl;
    
    auto begin2 = chrono::high_resolution_clock::now();
    thread aSortThread(
        [&] {
            bubble_sort(inlineArr, markers[97]);
        }
    );

    thread bSortThread(
        [&] {
            bubble_sort(inlineArr, markers[98]);
        }
    );

    thread cSortThread(
        [&] {
            bubble_sort(inlineArr, markers[99]);
        }
    );

    thread dSortThread(
        [&] {
            bubble_sort(inlineArr, markers[100]);
        }
    );

    thread eSortThread(
        [&] {
            bubble_sort(inlineArr, markers[101]);
        }
    );

    thread fSortThread(
        [&] {
            bubble_sort(inlineArr, markers[102]);
        }
    );

    thread gSortThread(
        [&] {
            bubble_sort(inlineArr, markers[103]);
        }
    );

    thread hSortThread(
        [&] {
            bubble_sort(inlineArr, markers[104]);
        }
    );

    thread iSortThread(
        [&] {
            bubble_sort(inlineArr, markers[105]);
        }
    );

    thread jSortThread(
        [&] {
            bubble_sort(inlineArr, markers[106]);
        }
    );

    thread kSortThread(
        [&] {
            bubble_sort(inlineArr, markers[107]);
        }
    );

    thread lSortThread(
        [&] {
            bubble_sort(inlineArr, markers[108]);
        }
    );

    thread mSortThread(
        [&] {
            bubble_sort(inlineArr, markers[109]);
        }
    );

    thread nSortThread(
        [&] {
            bubble_sort(inlineArr, markers[110]);
        }
    );

    thread oSortThread(
        [&] {
            bubble_sort(inlineArr, markers[111]);
        }
    );

    thread pSortThread(
        [&] {
            bubble_sort(inlineArr, markers[112]);
        }
    );

    thread qSortThread(
        [&] {
            bubble_sort(inlineArr, markers[113]);
        }
    );

    thread rSortThread(
        [&] {
            bubble_sort(inlineArr, markers[114]);
        }
    );

    thread sSortThread(
        [&] {
            bubble_sort(inlineArr, markers[115]);
        }
    );

    thread tSortThread(
        [&] {
            bubble_sort(inlineArr, markers[116]);
        }
    );

    thread uSortThread(
        [&] {
            bubble_sort(inlineArr, markers[117]);
        }
    );

    thread vSortThread(
        [&] {
            bubble_sort(inlineArr, markers[118]);
        }
    );

    thread wSortThread(
        [&] {
            bubble_sort(inlineArr, markers[119]);
        }
    );

    thread xSortThread(
        [&] {
            bubble_sort(inlineArr, markers[120]);
        }
    );

    thread ySortThread(
        [&] {
            bubble_sort(inlineArr, markers[121]);
        }
    );

    thread zSortThread(
        [&] {
            bubble_sort(inlineArr, markers[122]);
        }
    );

    aSortThread.join();
    bSortThread.join();
    cSortThread.join();
    dSortThread.join();
    eSortThread.join();
    fSortThread.join();
    gSortThread.join();
    hSortThread.join();
    iSortThread.join();
    jSortThread.join();
    kSortThread.join();
    lSortThread.join();
    mSortThread.join();
    nSortThread.join();
    oSortThread.join();
    pSortThread.join();
    qSortThread.join();
    rSortThread.join();
    sSortThread.join();
    tSortThread.join();
    uSortThread.join();
    vSortThread.join();
    wSortThread.join();
    xSortThread.join();
    ySortThread.join();
    zSortThread.join();
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
    driver("../1k.txt");
    cout << "10k" << endl;
    driver("../10k.txt");
    cout << "100k" << endl;
    driver("../100k.txt");
    // cout << "1m" << endl;
    // driver("../1m.txt");
    cout << "1m" << endl;
    driver("../1m.txt");
    cout << "2m" << endl;
    driver("../2m.txt");
    cout << "3m" << endl;
    driver("../3m.txt");
    cout << "10m" << endl;
    driver("../10m.txt");

    system("pause");
}