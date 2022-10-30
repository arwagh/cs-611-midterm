#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int table_based(string myText, int **tableBased)
{
    int myNumber = 0;
    for (size_t i = 0; i < myText.length(); i++)
    {
        cout << "i" << i << endl;
        cout << "myText[i]" << myText[i] << endl;
        cout << "tableBased[i][myText[i]]" << tableBased[i][myText[i]] << endl;
        myNumber += tableBased[i][myText[i]];
    }
    return myNumber;
}

void driver(string inFile)
{
    string myText;
    ifstream myReadFile(inFile);

    vector<string> datas;

    int asciiSize = 128;

    int *asciiIndex = new int[asciiSize];

    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        if (looper >= 64 && looper <= 90)
        {
            asciiIndex[looper] = looper - 64;
            cout << "looper" << endl;
            cout << looper << endl;
            cout << "asciiIndex[looper]" << endl;
            cout << asciiIndex[looper] << endl;
        }
        else if (looper >= 97 && looper <= 122)
        {
            asciiIndex[looper] = looper - 96;
            cout << "looper" << endl;
            cout << looper << endl;
            cout << "asciiIndex[looper]" << endl;
            cout << asciiIndex[looper] << endl;
        }
    }

    int tableBasedSize = 6;
    int **tableBased = new int *[tableBasedSize];

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
    string *fileData = new string[arrSize];

    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        fileData[looper] = datas[looper];
    }

    // start counting each word by the first letter
    auto begin1 = chrono::high_resolution_clock::now();
    int *fileDataNum = new int[arrSize];

    for (size_t looper = 0; looper < arrSize; looper++)
    {
        fileDataNum[looper] = table_based(fileData[looper], tableBased);
    }
    auto end1 = chrono::high_resolution_clock::now();
    cout << chrono::duration<double>(end1 - begin1).count() << endl;
}

int main()
{

    cout << "1k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../1k.txt");
    }
    cout << "10k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../10k.txt");
    }
    cout << "100k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../100k.txt");
    }
    cout << "1m" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../1m.txt");
    }
    /*
    cout << "2m" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../2m.txt");
    }
    cout << "3m" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../3m.txt");
    }
    cout << "10m" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../10m.txt");
    }*/

    system("pause");
}