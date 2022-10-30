#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <list>
#include <thread>

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
    list<string> zeroData, oneData, twoData, threeData, fourData, fiveData, sixData, sevenData, eightData, nineData,
        aData, bData, cData, dData, eData, fData, gData, hData, iData, jData, kData, lData, mData, nData, oData, pData, qData, rData, sData, tData, uData, vData, wData, xData, yData, zData;

    // copy data from big array to smaller array
    for (size_t i = 0; i < arrSize; i++)
    {
        // get the ascii value of first character
        int asciiValue = int(toupper(fileData[i][0]));

        switch (asciiValue)
        {
        case 48:
            zeroData.push_back(fileData[i]);
            break;
        case 49:
            oneData.push_back(fileData[i]);
            break;
        case 50:
            twoData.push_back(fileData[i]);
            break;
        case 51:
            threeData.push_back(fileData[i]);
            break;
        case 52:
            fourData.push_back(fileData[i]);
            break;
        case 53:
            fiveData.push_back(fileData[i]);
            break;
        case 54:
            sixData.push_back(fileData[i]);
            break;
        case 55:
            sevenData.push_back(fileData[i]);
            break;
        case 56:
            eightData.push_back(fileData[i]);
            break;
        case 57:
            nineData.push_back(fileData[i]);
            break;
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

    // move 0
    thread zeroThread(
        [&]
        {
            for (string item : zeroData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 1
    thread oneThread(
        [&]
        {
            for (string item : oneData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 2
    thread twoThread(
        [&]
        {
            for (string item : twoData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 3
    thread threeThread(
        [&]
        {
            for (string item : threeData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 4
    thread fourThread(
        [&]
        {
            for (string item : fourData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 5
    thread fiveThread(
        [&]
        {
            for (string item : fiveData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 6
    thread sixThread(
        [&]
        {
            for (string item : sixData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 7
    thread sevenThread(
        [&]
        {
            for (string item : sevenData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 8
    thread eightThread(
        [&]
        {
            for (string item : eightData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 9
    thread nineThread(
        [&]
        {
            for (string item : nineData)
            {
                int asciiValue = int(item[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });
    // move a
    thread aThread(
        [&]
        {
            for (string item : aData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move b
    thread bThread(
        [&]
        {
            for (string item : bData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move c
    thread cThread(
        [&]
        {
            for (string item : cData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move d
    thread dThread(
        [&]
        {
            for (string item : dData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move e
    thread eThread(
        [&]
        {
            for (string item : eData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move f
    thread fThread(
        [&]
        {
            for (string item : fData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move g
    thread gThread(
        [&]
        {
            for (string item : gData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move h
    thread hThread(
        [&]
        {
            for (string item : hData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move i
    thread iThread(
        [&]
        {
            for (string item : iData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move j
    thread jThread(
        [&]
        {
            for (string item : jData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move k
    thread kThread(
        [&]
        {
            for (string item : kData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move l
    thread lThread(
        [&]
        {
            for (string item : lData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move m
    thread mThread(
        [&]
        {
            for (string item : mData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move n
    thread nThread(
        [&]
        {
            for (string item : nData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move o
    thread oThread(
        [&]
        {
            for (string item : oData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move p
    thread pThread(
        [&]
        {
            for (string item : pData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move q
    thread qThread(
        [&]
        {
            for (string item : qData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move r
    thread rThread(
        [&]
        {
            for (string item : rData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move s
    thread sThread(
        [&]
        {
            for (string item : sData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move t
    thread tThread(
        [&]
        {
            for (string item : tData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move u
    thread uThread(
        [&]
        {
            for (string item : uData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move v
    thread vThread(
        [&]
        {
            for (string item : vData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move w
    thread wThread(
        [&]
        {
            for (string item : wData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move x
    thread xThread(
        [&]
        {
            for (string item : xData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move y
    thread yThread(
        [&]
        {
            for (string item : yData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    // move z
    thread zThread(
        [&]
        {
            for (string item : zData)
            {
                int asciiValue = int(toupper(item[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = item;
                asciiTwo[asciiValue] += 1;
            }
        });

    zeroThread.join();
    oneThread.join();
    twoThread.join();
    threeThread.join();
    fourThread.join();
    fiveThread.join();
    sixThread.join();
    sevenThread.join();
    eightThread.join();
    nineThread.join();
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

    auto end1 = chrono::high_resolution_clock::now();
    cout << chrono::duration<double>(end1 - begin1).count() << endl;
}

int main()
{

    cout << "1k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../1k_2ed_dataset.txt");
    }
    cout << "10k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../10k_2ed_dataset.txt");
    }
    cout << "100k" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../100k_2ed_dataset.txt");
    }
    cout << "1m" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        driver("../1m_2ed_dataset.txt");
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
    }
*/
    system("pause");
}