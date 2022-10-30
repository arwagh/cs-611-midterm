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
    string* fileData = new string[arrSize];
    
    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        fileData[looper] = datas[looper];
    }

    // start counting each word by the first letter
    auto begin1 = chrono::high_resolution_clock::now();

    // store data size into variable
    int asciiSize = 128;

    // initiate first ascii table
    int* asciiOne = new int[asciiSize] {0};

    for (size_t i = 0; i < arrSize; i++)
    {
        // get the ascii value of first character
        int asciiValue = int(toupper(fileData[i][0]));
        // count each letter
        asciiOne[asciiValue] += 1;
    }

    // initiate second ascii table
    int* asciiTwo = new int[asciiSize] {0};

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

    bool unfinished = true;
    int beginLoop = 0;

    while (unfinished)
    {
        for (size_t i = beginLoop; i < arrSize; i++)
        {
            // get the data
            string tempOne = fileData[i];
            int asciiValueOne = int(toupper(tempOne[0]));
            int indexValue = asciiTwo[asciiValueOne];
            int asciiCounter = asciiOne[asciiValueOne];

            // stop condition if z already finish
            if (indexValue == arrSize)
            {
                unfinished = false;
                break;
            }

            string tempTwo = fileData[indexValue];
            int asciiValueTwo = int(toupper(tempTwo[0]));

            // check if the string already in correct location
            if (indexValue == beginLoop && asciiCounter > 0)
            {
                // add counter and increment begin position
                asciiTwo[asciiValueOne] += 1;
                asciiOne[asciiValueOne] -= 1;
                
                beginLoop += 1;

                break;
            }
            else if (asciiCounter > 0)
            {
                // swap the string to correct location
                fileData[i] = tempTwo;
                fileData[indexValue] = tempOne;

                // add counter
                asciiTwo[asciiValueOne] += 1;
                asciiOne[asciiValueOne] -= 1;
                break;
            }
        }
        
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

    system("pause");
}