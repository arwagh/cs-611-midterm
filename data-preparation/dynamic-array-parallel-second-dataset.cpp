#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
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
    vector<string> zeroData, oneData, twoData, threeData, fourData, fiveData, sixData, sevenData, eightData, nineData,
        aData, bData, cData, dData, eData, fData, gData, hData, iData, jData, kData, lData, mData, nData, oData, pData, qData, rData, sData, tData, uData, vData, wData, xData, yData, zData;

    // copy data from big array to smaller array
    thread zeroMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 48)
                {
                    zeroData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread oneMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 49)
                {
                    oneData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread twoMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 50)
                {
                    twoData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread threeMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 51)
                {
                    threeData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread fourMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 52)
                {
                    fourData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread fiveMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 53)
                {
                    fiveData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread sixMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 54)
                {
                    sixData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread sevenMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 55)
                {
                    sevenData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread eightMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 56)
                {
                    eightData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread nineMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 57)
                {
                    nineData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread aMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 97)
                {
                    aData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread bMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 98)
                {
                    bData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread cMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 99)
                {
                    cData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread dMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 100)
                {
                    dData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread eMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 101)
                {
                    eData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread fMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 102)
                {
                    fData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread gMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 103)
                {
                    gData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread hMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 104)
                {
                    hData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread iMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 105)
                {
                    iData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread jMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 106)
                {
                    jData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread kMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 107)
                {
                    kData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread lMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 108)
                {
                    lData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread mMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 109)
                {
                    mData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread nMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 110)
                {
                    nData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread oMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 111)
                {
                    oData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread pMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 112)
                {
                    pData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread qMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 113)
                {
                    qData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread rMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 114)
                {
                    rData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread sMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 115)
                {
                    sData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread tMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 116)
                {
                    tData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread uMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 117)
                {
                    uData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread vMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 118)
                {
                    vData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread wMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 119)
                {
                    wData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread xMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 120)
                {
                    xData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread yMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 121)
                {
                    yData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    thread zMoveThread(
        [&]
        {
            for (size_t looper = 0; looper < arrSize; looper++)
            {
                if (int(fileData[looper][0]) == 122)
                {
                    zData.push_back(fileData[looper]);
                    asciiOne[int(fileData[looper][0])] += 1;
                }
            }
        });

    zeroMoveThread.join();
    oneMoveThread.join();
    twoMoveThread.join();
    threeMoveThread.join();
    fourMoveThread.join();
    fiveMoveThread.join();
    sixMoveThread.join();
    sevenMoveThread.join();
    eightMoveThread.join();
    nineMoveThread.join();
    aMoveThread.join();
    bMoveThread.join();
    cMoveThread.join();
    dMoveThread.join();
    eMoveThread.join();
    fMoveThread.join();
    gMoveThread.join();
    hMoveThread.join();
    iMoveThread.join();
    jMoveThread.join();
    kMoveThread.join();
    lMoveThread.join();
    mMoveThread.join();
    nMoveThread.join();
    oMoveThread.join();
    pMoveThread.join();
    qMoveThread.join();
    rMoveThread.join();
    sMoveThread.join();
    tMoveThread.join();
    uMoveThread.join();
    vMoveThread.join();
    wMoveThread.join();
    xMoveThread.join();
    yMoveThread.join();
    zMoveThread.join();

    // initiate second ascii table
    int *asciiTwo = new int[asciiSize]{0};

    // store begin position in second ascii table
    int begin = 0;
    for (size_t i = 0; i < asciiSize; i++)
    {
        if (i == 48)
        {
            // if first character is 0 then begin from 0
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
            for (size_t i = 0; i < zeroData.size(); i++)
            {
                int asciiValue = int(toupper(zeroData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = zeroData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 0
    thread oneThread(
        [&]
        {
            for (size_t i = 0; i < oneData.size(); i++)
            {
                int asciiValue = int(toupper(oneData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = oneData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 2
    thread twoThread(
        [&]
        {
            for (size_t i = 0; i < twoData.size(); i++)
            {
                int asciiValue = int(toupper(twoData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = twoData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 3
    thread threeThread(
        [&]
        {
            for (size_t i = 0; i < threeData.size(); i++)
            {
                int asciiValue = int(toupper(threeData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = threeData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 4
    thread fourThread(
        [&]
        {
            for (size_t i = 0; i < fourData.size(); i++)
            {
                int asciiValue = int(toupper(fourData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fourData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 5
    thread fiveThread(
        [&]
        {
            for (size_t i = 0; i < fiveData.size(); i++)
            {
                int asciiValue = int(toupper(fiveData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fiveData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 6
    thread sixThread(
        [&]
        {
            for (size_t i = 0; i < sixData.size(); i++)
            {
                int asciiValue = int(toupper(sixData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sixData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 7
    thread sevenThread(
        [&]
        {
            for (size_t i = 0; i < sevenData.size(); i++)
            {
                int asciiValue = int(toupper(sevenData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sevenData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 8
    thread eightThread(
        [&]
        {
            for (size_t i = 0; i < eightData.size(); i++)
            {
                int asciiValue = int(toupper(eightData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = eightData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move 9
    thread nineThread(
        [&]
        {
            for (size_t i = 0; i < nineData.size(); i++)
            {
                int asciiValue = int(toupper(nineData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = nineData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // move a
    thread aThread(
        [&]
        {
            for (size_t i = 0; i < aData.size(); i++)
            {
                int asciiValue = int(toupper(aData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = aData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // aThread.join();

    // move b
    thread bThread(
        [&]
        {
            for (size_t i = 0; i < bData.size(); i++)
            {
                int asciiValue = int(toupper(bData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = bData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // bThread.join();

    // move c
    thread cThread(
        [&]
        {
            for (size_t i = 0; i < cData.size(); i++)
            {
                int asciiValue = int(toupper(cData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = cData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // cThread.join();

    // move d
    thread dThread(
        [&]
        {
            for (size_t i = 0; i < dData.size(); i++)
            {
                int asciiValue = int(toupper(dData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = dData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // dThread.join();

    // move e
    thread eThread(
        [&]
        {
            for (size_t i = 0; i < eData.size(); i++)
            {
                int asciiValue = int(toupper(eData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = eData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // eThread.join();

    // move f
    thread fThread(
        [&]
        {
            for (size_t i = 0; i < fData.size(); i++)
            {
                int asciiValue = int(toupper(fData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // fThread.join();

    // move g
    thread gThread(
        [&]
        {
            for (size_t i = 0; i < gData.size(); i++)
            {
                int asciiValue = int(toupper(gData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = gData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // gThread.join();

    // move h
    thread hThread(
        [&]
        {
            for (size_t i = 0; i < hData.size(); i++)
            {
                int asciiValue = int(toupper(hData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = hData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // hThread.join();

    // move i
    thread iThread(
        [&]
        {
            for (size_t i = 0; i < iData.size(); i++)
            {
                int asciiValue = int(toupper(iData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = iData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // iThread.join();

    // move j
    thread jThread(
        [&]
        {
            for (size_t i = 0; i < jData.size(); i++)
            {
                int asciiValue = int(toupper(jData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = jData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // jThread.join();

    // move k
    thread kThread(
        [&]
        {
            for (size_t i = 0; i < kData.size(); i++)
            {
                int asciiValue = int(toupper(kData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = kData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // kThread.join();

    // move l
    thread lThread(
        [&]
        {
            for (size_t i = 0; i < lData.size(); i++)
            {
                int asciiValue = int(toupper(lData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = lData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // lThread.join();

    // move m
    thread mThread(
        [&]
        {
            for (size_t i = 0; i < mData.size(); i++)
            {
                int asciiValue = int(toupper(mData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = mData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // mThread.join();

    // move n
    thread nThread(
        [&]
        {
            for (size_t i = 0; i < nData.size(); i++)
            {
                int asciiValue = int(toupper(nData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = nData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // nThread.join();

    // move o
    thread oThread(
        [&]
        {
            for (size_t i = 0; i < oData.size(); i++)
            {
                int asciiValue = int(toupper(oData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = oData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // oThread.join();

    // move p
    thread pThread(
        [&]
        {
            for (size_t i = 0; i < pData.size(); i++)
            {
                int asciiValue = int(toupper(pData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = pData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // pThread.join();

    // move q
    thread qThread(
        [&]
        {
            for (size_t i = 0; i < qData.size(); i++)
            {
                int asciiValue = int(toupper(qData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = qData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // qThread.join();

    // move r
    thread rThread(
        [&]
        {
            for (size_t i = 0; i < rData.size(); i++)
            {
                int asciiValue = int(toupper(rData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = rData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // rThread.join();

    // move s
    thread sThread(
        [&]
        {
            for (size_t i = 0; i < sData.size(); i++)
            {
                int asciiValue = int(toupper(sData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // sThread.join();

    // move t
    thread tThread(
        [&]
        {
            for (size_t i = 0; i < tData.size(); i++)
            {
                int asciiValue = int(toupper(tData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = tData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // tThread.join();

    // move u
    thread uThread(
        [&]
        {
            for (size_t i = 0; i < uData.size(); i++)
            {
                int asciiValue = int(toupper(uData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = uData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // uThread.join();

    // move v
    thread vThread(
        [&]
        {
            for (size_t i = 0; i < vData.size(); i++)
            {
                int asciiValue = int(toupper(vData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = vData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // vThread.join();

    // move w
    thread wThread(
        [&]
        {
            for (size_t i = 0; i < wData.size(); i++)
            {
                int asciiValue = int(toupper(wData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = wData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // wThread.join();

    // move x
    thread xThread(
        [&]
        {
            for (size_t i = 0; i < xData.size(); i++)
            {
                int asciiValue = int(toupper(xData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = xData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // xThread.join();

    // move y
    thread yThread(
        [&]
        {
            for (size_t i = 0; i < yData.size(); i++)
            {
                int asciiValue = int(toupper(yData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = yData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // yThread.join();

    // move z
    thread zThread(
        [&]
        {
            for (size_t i = 0; i < zData.size(); i++)
            {
                int asciiValue = int(toupper(zData[i][0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = zData[i];
                asciiTwo[asciiValue] += 1;
            }
        });

    // zThread.join();
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