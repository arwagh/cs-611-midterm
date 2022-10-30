#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <stack>
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
    stack<string> zeroData, oneData, twoData, threeData, fourData, fiveData, sixData, sevenData, eightData, nineData, tenData,
        aData, bData, cData, dData, eData, fData, gData, hData, iData, jData, kData, lData, mData, nData, oData, pData, qData, rData, sData, tData, uData, vData, wData, xData, yData, zData;

    // copy data from big array to smaller array
    for (size_t i = 0; i < arrSize; i++)
    {
        // get the ascii value of first character
        int asciiValue = int(toupper(fileData[i][0]));

        switch (asciiValue)
        {
        case 48:
            zeroData.push(fileData[i]);
            break;
        case 49:
            oneData.push(fileData[i]);
            break;
        case 50:
            twoData.push(fileData[i]);
            break;
        case 51:
            threeData.push(fileData[i]);
            break;
        case 52:
            fourData.push(fileData[i]);
            break;
        case 53:
            fiveData.push(fileData[i]);
            break;
        case 54:
            sixData.push(fileData[i]);
            break;
        case 55:
            sevenData.push(fileData[i]);
            break;
        case 56:
            eightData.push(fileData[i]);
            break;
        case 57:
            nineData.push(fileData[i]);
            break;
        case 58:
            tenData.push(fileData[i]);
            break;
        case 65:
            aData.push(fileData[i]);
            break;
        case 66:
            bData.push(fileData[i]);
            break;
        case 67:
            cData.push(fileData[i]);
            break;
        case 68:
            dData.push(fileData[i]);
            break;
        case 69:
            eData.push(fileData[i]);
            break;
        case 70:
            fData.push(fileData[i]);
            break;
        case 71:
            gData.push(fileData[i]);
            break;
        case 72:
            hData.push(fileData[i]);
            break;
        case 73:
            iData.push(fileData[i]);
            break;
        case 74:
            jData.push(fileData[i]);
            break;
        case 75:
            kData.push(fileData[i]);
            break;
        case 76:
            lData.push(fileData[i]);
            break;
        case 77:
            mData.push(fileData[i]);
            break;
        case 78:
            nData.push(fileData[i]);
            break;
        case 79:
            oData.push(fileData[i]);
            break;
        case 80:
            pData.push(fileData[i]);
            break;
        case 81:
            qData.push(fileData[i]);
            break;
        case 82:
            rData.push(fileData[i]);
            break;
        case 83:
            sData.push(fileData[i]);
            break;
        case 84:
            tData.push(fileData[i]);
            break;
        case 85:
            uData.push(fileData[i]);
            break;
        case 86:
            vData.push(fileData[i]);
            break;
        case 87:
            wData.push(fileData[i]);
            break;
        case 88:
            xData.push(fileData[i]);
            break;
        case 89:
            yData.push(fileData[i]);
            break;
        case 90:
            zData.push(fileData[i]);
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
            while (!zeroData.empty())
            {
                int asciiValue = int(zeroData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = zeroData.top();
                asciiTwo[asciiValue] += 1;
                zeroData.pop();
            }
        });

    // move 1
    thread oneThread(
        [&]
        {
            while (!oneData.empty())
            {
                int asciiValue = int(oneData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = oneData.top();
                asciiTwo[asciiValue] += 1;
                oneData.pop();
            }
        });

    // move 2
    thread twoThread(
        [&]
        {
            while (!twoData.empty())
            {
                int asciiValue = int(twoData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = twoData.top();
                asciiTwo[asciiValue] += 1;
                twoData.pop();
            }
        });

    // move 3
    thread threeThread(
        [&]
        {
            while (!threeData.empty())
            {
                int asciiValue = int(threeData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = threeData.top();
                asciiTwo[asciiValue] += 1;
                threeData.pop();
            }
        });

    // move 4
    thread fourThread(
        [&]
        {
            while (!fourData.empty())
            {
                int asciiValue = int(fourData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fourData.top();
                asciiTwo[asciiValue] += 1;
                fourData.pop();
            }
        });

    // move 5
    thread fiveThread(
        [&]
        {
            while (!fiveData.empty())
            {
                int asciiValue = int(fiveData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fiveData.top();
                asciiTwo[asciiValue] += 1;
                fiveData.pop();
            }
        });

    // move 6
    thread sixThread(
        [&]
        {
            while (!sixData.empty())
            {
                int asciiValue = int(sixData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sixData.top();
                asciiTwo[asciiValue] += 1;
                sixData.pop();
            }
        });

    // move 7
    thread sevenThread(
        [&]
        {
            while (!sevenData.empty())
            {
                int asciiValue = int(sevenData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sevenData.top();
                asciiTwo[asciiValue] += 1;
                sevenData.pop();
            }
        });

    // move 8
    thread eightThread(
        [&]
        {
            while (!eightData.empty())
            {
                int asciiValue = int(eightData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = eightData.top();
                asciiTwo[asciiValue] += 1;
                eightData.pop();
            }
        });

    // move 9
    thread nineThread(
        [&]
        {
            while (!nineData.empty())
            {
                int asciiValue = int(nineData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = nineData.top();
                asciiTwo[asciiValue] += 1;
                nineData.pop();
            }
        });

    // move 10
    thread tenThread(
        [&]
        {
            while (!tenData.empty())
            {
                int asciiValue = int(tenData.top()[0]);
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = tenData.top();
                asciiTwo[asciiValue] += 1;
                tenData.pop();
            }
        });

    // move a
    thread aThread(
        [&]
        {
            while (!aData.empty())
            {
                int asciiValue = int(toupper(aData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = aData.top();
                asciiTwo[asciiValue] += 1;
                aData.pop();
            }
        });

    // move b
    thread bThread(
        [&]
        {
            while (!bData.empty())
            {
                int asciiValue = int(toupper(bData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = bData.top();
                asciiTwo[asciiValue] += 1;
                bData.pop();
            }
        });

    // move c
    thread cThread(
        [&]
        {
            while (!cData.empty())
            {
                int asciiValue = int(toupper(cData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = cData.top();
                asciiTwo[asciiValue] += 1;
                cData.pop();
            }
        });

    // move d
    thread dThread(
        [&]
        {
            while (!dData.empty())
            {
                int asciiValue = int(toupper(dData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = dData.top();
                asciiTwo[asciiValue] += 1;
                dData.pop();
            }
        });

    // move e
    thread eThread(
        [&]
        {
            while (!eData.empty())
            {
                int asciiValue = int(toupper(eData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = eData.top();
                asciiTwo[asciiValue] += 1;
                eData.pop();
            }
        });

    // move f
    thread fThread(
        [&]
        {
            while (!fData.empty())
            {
                int asciiValue = int(toupper(fData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = fData.top();
                asciiTwo[asciiValue] += 1;
                fData.pop();
            }
        });

    // move g
    thread gThread(
        [&]
        {
            while (!gData.empty())
            {
                int asciiValue = int(toupper(gData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = gData.top();
                asciiTwo[asciiValue] += 1;
                gData.pop();
            }
        });

    // move h
    thread hThread(
        [&]
        {
            while (!hData.empty())
            {
                int asciiValue = int(toupper(hData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = hData.top();
                asciiTwo[asciiValue] += 1;
                hData.pop();
            }
        });

    // move i
    thread iThread(
        [&]
        {
            while (!iData.empty())
            {
                int asciiValue = int(toupper(iData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = iData.top();
                asciiTwo[asciiValue] += 1;
                iData.pop();
            }
        });

    // move j
    thread jThread(
        [&]
        {
            while (!jData.empty())
            {
                int asciiValue = int(toupper(jData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = jData.top();
                asciiTwo[asciiValue] += 1;
                jData.pop();
            }
        });

    // move k
    thread kThread(
        [&]
        {
            while (!kData.empty())
            {
                int asciiValue = int(toupper(kData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = kData.top();
                asciiTwo[asciiValue] += 1;
                kData.pop();
            }
        });

    // move l
    thread lThread(
        [&]
        {
            while (!lData.empty())
            {
                int asciiValue = int(toupper(lData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = lData.top();
                asciiTwo[asciiValue] += 1;
                lData.pop();
            }
        });

    // move m
    thread mThread(
        [&]
        {
            while (!mData.empty())
            {
                int asciiValue = int(toupper(mData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = mData.top();
                asciiTwo[asciiValue] += 1;
                mData.pop();
            }
        });

    // move n
    thread nThread(
        [&]
        {
            while (!nData.empty())
            {
                int asciiValue = int(toupper(nData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = nData.top();
                asciiTwo[asciiValue] += 1;
                nData.pop();
            }
        });

    // move o
    thread oThread(
        [&]
        {
            while (!oData.empty())
            {
                int asciiValue = int(toupper(oData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = oData.top();
                asciiTwo[asciiValue] += 1;
                oData.pop();
            }
        });

    // move p
    thread pThread(
        [&]
        {
            while (!pData.empty())
            {
                int asciiValue = int(toupper(pData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = pData.top();
                asciiTwo[asciiValue] += 1;
                pData.pop();
            }
        });

    // move q
    thread qThread(
        [&]
        {
            while (!qData.empty())
            {
                int asciiValue = int(toupper(qData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = qData.top();
                asciiTwo[asciiValue] += 1;
                qData.pop();
            }
        });

    // move r
    thread rThread(
        [&]
        {
            while (!rData.empty())
            {
                int asciiValue = int(toupper(rData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = rData.top();
                asciiTwo[asciiValue] += 1;
                rData.pop();
            }
        });

    // move s
    thread sThread(
        [&]
        {
            while (!sData.empty())
            {
                int asciiValue = int(toupper(sData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = sData.top();
                asciiTwo[asciiValue] += 1;
                sData.pop();
            }
        });

    // move t
    thread tThread(
        [&]
        {
            while (!tData.empty())
            {
                int asciiValue = int(toupper(tData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = tData.top();
                asciiTwo[asciiValue] += 1;
                tData.pop();
            }
        });

    // move u
    thread uThread(
        [&]
        {
            while (!uData.empty())
            {
                int asciiValue = int(toupper(uData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = uData.top();
                asciiTwo[asciiValue] += 1;
                uData.pop();
            }
        });

    // move v
    thread vThread(
        [&]
        {
            while (!vData.empty())
            {
                int asciiValue = int(toupper(vData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = vData.top();
                asciiTwo[asciiValue] += 1;
                vData.pop();
            }
        });

    // move w
    thread wThread(
        [&]
        {
            while (!wData.empty())
            {
                int asciiValue = int(toupper(wData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = wData.top();
                asciiTwo[asciiValue] += 1;
                wData.pop();
            }
        });

    // move x
    thread xThread(
        [&]
        {
            while (!xData.empty())
            {
                int asciiValue = int(toupper(xData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = xData.top();
                asciiTwo[asciiValue] += 1;
                xData.pop();
            }
        });

    // move y
    thread yThread(
        [&]
        {
            while (!yData.empty())
            {
                int asciiValue = int(toupper(yData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = yData.top();
                asciiTwo[asciiValue] += 1;
                yData.pop();
            }
        });

    // move z
    thread zThread(
        [&]
        {
            while (!zData.empty())
            {
                int asciiValue = int(toupper(zData.top()[0]));
                int indexValue = asciiTwo[asciiValue];

                fileData[indexValue] = zData.top();
                asciiTwo[asciiValue] += 1;
                zData.pop();
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
    tenThread.join();
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
    }
*/
    system("pause");
}