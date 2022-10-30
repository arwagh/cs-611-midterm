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
    string *newArr = new string[arrSize];

    // convert vector to array
    // this step should not be timed
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        newArr[looper] = datas[looper];
    }

    // start counting each word by the first letter
    auto begin1 = chrono::high_resolution_clock::now();

    // create ascii table with empty value for counter
    int asciiSize = 128;
    int **markers = new int *[asciiSize];

    for (size_t looper = 0; looper < asciiSize; looper++)
    {
        markers[looper] = new int[3]{0};
    }

    for (size_t looper = 0; looper < arrSize; looper++)
    {
        markers[int(newArr[looper][0])][1] += 1;
    }

    // add begin and end for each array
    for (size_t looper = 0; looper < asciiSize; looper++)
    {

        if (looper == 0)
        {
            markers[looper][0] = 0;
            markers[looper][1] = markers[looper][1];
        }
        else
        {
            markers[looper][0] = markers[looper - 1][1];
            markers[looper][1] = markers[looper][0] + markers[looper][1];
        }
    }

    string *inlineArr = new string[arrSize];
    for (size_t looper = arrSize; looper-- > 0;)
    {
        int ascii = int(newArr[looper][0]);
        int start = markers[ascii][0];
        int count = start + markers[ascii][2];
        inlineArr[count] = newArr[looper];
        markers[ascii][2] += 1;
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