#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

////word data structure, it has 6 elements which are: char 0 to char 5.
struct Datas
{
    char one;
    char two;
    char three;
    char four;
    char five;
    char six;
};

////me: NOTE ... don't understand the goal of this function
////me: this array takes 2 arguments: the new array "loopArr"
////me: and the number of words
bool check(string *arr, int n)
{
    int i, j;
    bool result = true;
    ;
    ////me: loop the the words with variable "i"
    for (i = 0; i < n - 1; i++)
    {
        ////me: loop again through the words with variable "j"
        for (j = 0; j < n - i - 1; j++)
        {
            ////me: if word 1 is greater than word 2, swap them
            if (arr[j] > arr[j + 1])
            {
                ////me: swap, set result to false
                ////me: then break the inner loop
                swap(arr[j], arr[j + 1]);
                result = false;
                break;
            }
        }
        ////me: after looping through the inner loop
        ////me: if the "result" is true, which will happen if there was no swap at all
        ////me: return true, which will break the inner loop*

        // IF no two elements were swapped
        // by inner loop, then break
        if (result)
        {
            return result;
        }
    }

    return result;
}

////me: it takes two arguments: which are 2 Dates (2 words)
////me: in short: make word 1 word 2, and word 2 word 1 (swap)
void swap(Datas *xp, Datas *yp)
{
    Datas temp = *xp;
    *xp = *yp;
    *yp = temp;
}

////me: bubble sort function takes 2 arguments: the array of words
void bubble_sort(Datas *arr, int limit)
{
    int i, j;
    ////me: loop through all the words of the array (arr), with variable "i"
    for (i = 0; i < limit - 1; i++)
    {
        ////me: loop again through the same loop, with variable "j"
        for (j = 0; j < limit - i - 1; j++)
        {
            ////me: if the char 1 of word 1, is greater than char 0 of word 2, call swap function
            ////me: (note: refer to swap function)
            if (arr[j].one > arr[j + 1].one)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            ////me: if char 1 of word 1 and char 1 of word 2 are equal
            ////me: AND char 2 of word 1 is greater than char 2 of word 2
            /// me: swap word 1 and word 2
            if (arr[j].one == arr[j + 1].one && arr[j].two > arr[j + 1].two)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            ////me: if char 1 and char 2 of word 1 and word 2 are equal,
            ////me: AND char 3 of word 1 is greater than char 3 of word 2,
            ////me: swap word 1 and word 2
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three > arr[j + 1].three)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            ////me: if char 1, char 2 and char 3 of word 1 and word 2 are equal,
            ////me: AND char 4 of word 1 is greater than char 4 of word 2,
            ////me: swap word 1 and word 2
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four > arr[j + 1].four)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            ////me: if char 1, char 2, char 3 and char 4 of word 1 and word 2 are equal,
            ////me: AND char 5 of word 1 is greater than char 5 of word 2,
            ////me: swap word 1 and word 2
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four == arr[j + 1].four && arr[j].five > arr[j + 1].five)
            {
                swap(&arr[j], &arr[j + 1]);
            }
            ////me: if char 1, char 2, char 3, char 4 and char 5 of word 1 and word 2 are equal,
            ////me: AND char 6 of word 1 is greater than char 6 of word 2,
            ////me: swap word 1 and word 2
            if (arr[j].one == arr[j + 1].one && arr[j].two == arr[j + 1].two && arr[j].three == arr[j + 1].three && arr[j].four == arr[j + 1].four && arr[j].five == arr[j + 1].five && arr[j].six > arr[j + 1].six)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
////me: read txt dataset file, then write the results in txt file
void driver(string inFile, string outFile)
{
    ////me: reading dataset txt file
    string myText;
    ifstream myReadFile(inFile);
    // ofstream myFile(outFile);

    ////me: store the content of txt file into vector names "dates"
    vector<string> datas;

    // put textfile data to vector
    // this step should not be timed
    ////me: sore each line (word) into vector "dates"
    while (getline(myReadFile, myText))
    {
        datas.push_back(myText);
    }

    ////me: close the txt file
    myReadFile.close();

    ////me: get the size (length, number of words) to variable "arrSize"
    int arrSize = datas.size();

    ////me: create a new array of tpe "Dates" with the size of the vector containing all words
    ////me: aim is: converting vector inti an array
    // me: "Dates" data structure contains 6 elements: from char 0 to char 5.
    Datas *newArr = new Datas[arrSize];

    // convert vector to array
    // this step should not be timed
    ////me: store each character in a different variable, since "Dates" structure has 6 variables:
    ////me: one, two, three,...six.
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        /*cout << "datas[looper]" << endl;
        cout << datas[looper] << endl;
        cout << "datas[looper][0]" << endl;
        cout << datas[looper][0] << endl;
        cout << "datas[looper][1]" << endl;
        cout << datas[looper][1] << endl;
        cout << "datas[looper][2]" << endl;
        cout << datas[looper][2] << endl;*/
        newArr[looper].one = datas[looper][0];
        newArr[looper].two = datas[looper][1];
        newArr[looper].three = datas[looper][2];
        newArr[looper].four = datas[looper][3];
        newArr[looper].five = datas[looper][4];
        newArr[looper].six = datas[looper][5];
    }

    ////me: calculate time of bubble sort algorithm, sending the array which contains all words,
    ////me: where each word is stored as a data structure called "Dates",
    ////me: with 6 variables correspunding to 6 charactes
    auto begin1 = chrono::high_resolution_clock::now();
    bubble_sort(newArr, arrSize);
    auto end1 = chrono::high_resolution_clock::now();

    ////me: creat an array of type string, with the size of number of words
    string *boolArr = new string[arrSize];
    ////me: loop through all the words
    for (size_t looper = 0; looper < arrSize; looper++)
    {
        ////me: store the first word in the boolArr, then add a value to it (making it 2D array*)
        ////me: which is the word (by summing all the character)
        ////me: (note: why writing the sum?)

        cout << "string(1, newArr[looper].one)" << endl;
        cout << string(1, newArr[looper].one) << endl;
        cout << "newArr[looper].two" << endl;
        cout << newArr[looper].two << endl;
        boolArr[looper] = string(1, newArr[looper].one) + newArr[looper].two + newArr[looper].three + newArr[looper].four + newArr[looper].five + newArr[looper].six;
        cout << "newArr[looper]" << endl;
        cout << boolArr[looper] << endl;
        cout << "boolArr[looper]" << endl;
        cout << boolArr[looper] << endl;
    }

    bool checker = true;

    ////me: call check function sending 2 arguments: the new array "boolArr" and the length (number of words)
    ////me:
    checker = check(boolArr, arrSize);

    if (checker)
    {
        cout << "Total time:" << chrono::duration<double>(end1 - begin1).count() << endl;
    }
    else
    {
        cout << "Data error" << endl;
    }

    // myFile.close();
}

int main()
{
    cout << "1k" << endl;
    driver("1k.txt", "bs_inline_1k.txt");
    cout << "10k" << endl;
    driver("10k.txt", "bs_inline_10k.txt");
    cout << "100k" << endl;
    driver("100k.txt", "bs_inline_100k.txt");
    cout << "1m" << endl;
    driver("1m.txt", "bs_inline_1m.txt");

    system("pause");
}