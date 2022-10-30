#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <list>

using namespace std;

void driver(string inFile)
{
    string myText;
    ifstream myReadFile(inFile);

    vector<string> datas;

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

    // create ascii table with empty value for counter
    int asciiSize = 128;
    int *asciiOne = new int[asciiSize]{0};

    // initiate small dynamic array
    list<string> aData, bData, cData, dData, eData, fData, gData, hData, iData, jData, kData, lData, mData, nData, oData, pData, qData, rData, sData, tData, uData, vData, wData, xData, yData, zData;

    // copy data from big array to smaller array
    for (size_t i = 0; i < arrSize; i++)
    {
        // get the ascii value of first character
        int asciiValue = int(toupper(fileData[i][0]));

        switch (asciiValue)
        {
        case 65:
            aData.push_back(fileData[i]);
            break;
        case 66:
            bData.push_back(fileData[i]);
            break;
        case 67:
            cData.push_back(fileData[i]);
            break;
        case 68:
            dData.push_back(fileData[i]);
            break;
        case 69:
            eData.push_back(fileData[i]);
            break;
        case 70:
            fData.push_back(fileData[i]);
            break;
        case 71:
            gData.push_back(fileData[i]);
            break;
        case 72:
            hData.push_back(fileData[i]);
            break;
        case 73:
            iData.push_back(fileData[i]);
            break;
        case 74:
            jData.push_back(fileData[i]);
            break;
        case 75:
            kData.push_back(fileData[i]);
            break;
        case 76:
            lData.push_back(fileData[i]);
            break;
        case 77:
            mData.push_back(fileData[i]);
            break;
        case 78:
            nData.push_back(fileData[i]);
            break;
        case 79:
            oData.push_back(fileData[i]);
            break;
        case 80:
            pData.push_back(fileData[i]);
            break;
        case 81:
            qData.push_back(fileData[i]);
            break;
        case 82:
            rData.push_back(fileData[i]);
            break;
        case 83:
            sData.push_back(fileData[i]);
            break;
        case 84:
            tData.push_back(fileData[i]);
            break;
        case 85:
            uData.push_back(fileData[i]);
            break;
        case 86:
            vData.push_back(fileData[i]);
            break;
        case 87:
            wData.push_back(fileData[i]);
            break;
        case 88:
            xData.push_back(fileData[i]);
            break;
        case 89:
            yData.push_back(fileData[i]);
            break;
        case 90:
            zData.push_back(fileData[i]);
            break;
        default:
            break;
        }

        // count each letter
        asciiOne[asciiValue] += 1;
    }

    // initiate second ascii table
    int *asciiTwo = new int[asciiSize]{0};

    // store begin position in second ascii table
    int begin = 0;
    for (size_t i = 0; i < asciiSize; i++)
    {
        if (i == 65)
        {
            // if first character is A then begin from 0
            asciiTwo[i] = begin;
            // set begin to the size of A
            begin += asciiOne[i];
        }
        else
        {
            // if first character is not A then begin from the size of previous char
            asciiTwo[i] = begin;
            // set begin to the size of previous char + current char
            begin += asciiOne[i];
        }
    }

    // move a
    for (string item : aData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move b
    for (string item : bData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move c
    for (string item : cData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move d
    for (string item : dData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move e
    for (string item : eData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move f
    for (string item : fData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move g
    for (string item : gData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move h
    for (string item : hData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move i
    for (string item : iData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move j
    for (string item : jData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move k
    for (string item : kData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move l
    for (string item : lData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move m
    for (string item : mData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move n
    for (string item : nData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move o
    for (string item : oData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move p
    for (string item : pData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move q
    for (string item : qData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move r
    for (string item : rData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move s
    for (string item : sData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move t
    for (string item : tData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move u
    for (string item : uData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move v
    for (string item : vData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move w
    for (string item : wData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move x
    for (string item : xData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move y
    for (string item : yData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
    }

    // move z
    for (string item : zData)
    {
        int asciiValue = int(toupper(item[0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = item;
        asciiTwo[asciiValue] += 1;
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
    /*cout << "2m" << endl;
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