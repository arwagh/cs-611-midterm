
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <list>
#include <algorithm>

using namespace std;

string findSubstr(std::string const &str, int n)
{
    if (str.length() < n)
    {
        return str;
    }

    return str.substr(0, n);
}

void prepDataset2(string inFile)
{
    string myText;
    ifstream myReadFile(inFile);

    vector<string> datas;

    // put textfile data to vector
    // this step should not be timed
    while (getline(myReadFile, myText))
    {
        // cout << string(typeid(myText).name()) << endl;
        myText.erase(remove(myText.begin(), myText.end(), '_'), myText.end()); // remove A from string
        // cout << substring << endl;
        if (myText.size() > 6)
        {
            string substring = findSubstr(myText, 6);
            cout << substring << endl;
            datas.push_back(substring);
        }
        else if (myText.size() < 6)
        {
            int left = 6 - myText.size();
            char ch = '@';
            for (int i = 0; i < left; i++)
            {
                myText.push_back(ch);
            }
            cout << myText << endl;
            datas.push_back(myText);
        }
        else
        {
            cout << myText << endl;
            datas.push_back(myText);
        }
    }
    myReadFile.close();

    // write
    fstream my_file;
    my_file.open("1k_2ed_dataset.txt", ios::out);
    for (int i = 0; i < 1000; i++)
    {
        my_file << datas[i];
        my_file << "\n";
    }

    my_file.close();
    // write
    my_file.open("10k_2ed_dataset.txt", ios::out);
    for (int i = 0; i < 10000; i++)
    {
        my_file << datas[i];
        my_file << "\n";
    }

    my_file.close();

    // write
    my_file.open("100k_2ed_dataset.txt", ios::out);
    for (int i = 0; i < 100000; i++)
    {
        my_file << datas[i];
        my_file << "\n";
    }

    my_file.close();

    // write
    my_file.open("1m_2ed_dataset.txt", ios::out);
    for (int i = 0; i < 1000000; i++)
    {
        my_file << datas[i];
        my_file << "\n";
    }

    my_file.close();
}
int main()
{
    prepDataset2("../TestData/Twitter_10000000.txt");
    system("pause");
}