#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Person
{
	// this are the attributes 
    char satu;
    char dua;
    char tiga;
    char empat;
    char lima;
    char enam;

	// string name;
	// int roll_no;
	// int age;
    // int weight;
	
}Student;  // declare the student variable

/* our Comperator function
 (<) sorts in ascending order, replace with (>) for descending order **/

bool compare( Student a, Student b){
	/** to use another attribute for sorting, just replace 'age' with it eg. (a.roll_no < b.roll_no)
	 the return value determines which student will go first in the sorted array **/
	if(a.satu < b.satu)
		return 1;
	else 
		return 0;
}

bool compareKedua(Student a, Student b){
    if(a.dua < b.dua)
		return 1;
	else 
		return 0;
}

bool compareKetiga(Student a, Student b){
    if(a.tiga < b.tiga)
		return 1;
	else 
		return 0;
}

int compare_a(const void *data1, const void*data2)
{
  return ((Student*)data2)->satu - ((Student*)data1)->satu;
}

void swap(string* xp, string* yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(string* arr, int limit)
{
    int i, j;
    for (i = 0; i < limit - 1; i++)
    {
        for (j = 0; j < limit - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
	int i,n;
    n = 6;
	// cout<< "Enter number of students :";    // to determine the size of array
	// cin>> n;
	
	// we set the array to the number of students
    Student s_array[6];

    const char* colour[6]
        = { "apples", "aplong", "bakrie", "ancure", "cncure","bncure"};
  //string* mines[2] = {"huruf", "abjad"};
  
  for (int i = 0 ; i < 6 ; i++){
    s_array[i].satu = colour[i][0];
    s_array[i].dua = colour[i][1];
    s_array[i].tiga = colour[i][2];
    s_array[i].empat = colour[i][3];
    s_array[i].lima = colour[i][4];
    s_array[i].enam = colour[i][5];
  }
	
	// cout<<"Enter Name \n\n";
	//for loop to collect input
	// for(i=0;i<n;i++){
	// 	cout<<"---------\n";   
	// 	cin>>s_array[i].satu;
	// 	cin>>s_array[i].dua;
	// 	cin>>s_array[i].tiga;
	// 	cin>>s_array[i].empat;
    //     cin>>s_array[i].lima;
    //     cin>>s_array[i].enam;
	// }
	
    sort(s_array, s_array+n, compare);

    // qsort(s_array, 6, sizeof (s_array[0]), compare_a);

    // for(i=0;i<n;i++){
	// 	cout<<s_array[i].satu <<"   " ;
	// 	cout<<s_array[i].dua << "  ";
	// 	cout<<s_array[i].tiga << "  ";
    //     cout<<s_array[i].empat << "  ";
    //     cout<<s_array[i].lima << "  ";
	// 	cout<<s_array[i].enam << endl;
	// }

    // sort(s_array, s_array+n, compareKedua);

    for(i=0;i<n;i++){
		cout<<s_array[i].satu <<"   " ;
		cout<<s_array[i].dua << "  ";
		cout<<s_array[i].tiga << "  ";
        cout<<s_array[i].empat << "  ";
        cout<<s_array[i].lima << "  ";
		cout<<s_array[i].enam << endl;
	}
    
    // sort(s_array, s_array+n, compareKetiga);

    // for(i=0;i<n;i++){
	// 	cout<<s_array[i].satu <<"   " ;
	// 	cout<<s_array[i].dua << "  ";
	// 	cout<<s_array[i].tiga << "  ";
    //     cout<<s_array[i].empat << "  ";
    //     cout<<s_array[i].lima << "  ";
	// 	cout<<s_array[i].enam << endl;
	// }
	// sort(s_array, s_array+n, compareKedua);
	 /** this is the sort function
	its first & second parameter tells it the range of the array we want sorted
	and the third one is our comparator function **/
	
	// cout<<"\nHere is the sorted list of Students :\n";
	// //for loop to print the output
	// for(i=0;i<n;i++){
	// 	cout<<s_array[i].satu <<"   " ;
	// 	cout<<s_array[i].dua << "  ";
	// 	cout<<s_array[i].tiga << "  ";
    //     cout<<s_array[i].empat << "  ";
    //     cout<<s_array[i].lima << "  ";
	// 	cout<<s_array[i].enam << endl;
	// }
}