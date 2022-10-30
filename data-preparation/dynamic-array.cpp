#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

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
    vector<string> aData, bData, cData, dData, eData, fData, gData, hData, iData, jData, kData, lData, mData, nData, oData, pData, qData, rData, sData, tData, uData, vData, wData, xData, yData, zData;

    // copy data from big array to smaller array
    for (size_t i = 0; i < arrSize; i++)
    {
        // get the ascii value of first character
        int asciiValue = int(toupper(fileData[i][0]));

        ////me: insert the word into the suitable array char, e.g., if it starts with "A",
        ////me: insert it in "A" array.
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
    int loopSize = aData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(aData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = aData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move b
    loopSize = bData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(bData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = bData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move c
    loopSize = cData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(cData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = cData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move d
    loopSize = dData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(dData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = dData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move e
    loopSize = eData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(eData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = eData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move f
    loopSize = fData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(fData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = fData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move g
    loopSize = gData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(gData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = gData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move h
    loopSize = hData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(hData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = hData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move i
    loopSize = iData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(iData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = iData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move j
    loopSize = jData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(jData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = jData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move k
    loopSize = kData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(kData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = kData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move l
    loopSize = lData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(lData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = lData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move m
    loopSize = mData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(mData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = mData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move n
    loopSize = nData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(nData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = nData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move o
    loopSize = oData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(oData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = oData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move p
    loopSize = pData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(pData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = pData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move q
    loopSize = qData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(qData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = qData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move r
    loopSize = rData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(rData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = rData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move s
    loopSize = sData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(sData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = sData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move t
    loopSize = tData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(tData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = tData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move u
    loopSize = uData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(uData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = uData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move v
    loopSize = vData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(vData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = vData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move w
    loopSize = wData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(wData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = wData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move x
    loopSize = xData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(xData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = xData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move y
    loopSize = yData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(yData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = yData[i];
        asciiTwo[asciiValue] += 1;
    }

    // move z
    loopSize = zData.size();

    for (size_t i = 0; i < loopSize; i++)
    {
        int asciiValue = int(toupper(zData[i][0]));
        int indexValue = asciiTwo[asciiValue];

        fileData[indexValue] = zData[i];
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