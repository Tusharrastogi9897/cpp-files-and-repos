/*
Q. Consider an -element array, , where each index  in the array contains a reference to an array of  integers (where the value of  varies from array to array). See the Explanation section below for a diagram.
Given , you must answer  queries. Each query is in the format i j, where  denotes an index in array  and  denotes an index in the array located at . For each query, find and print the value of element  in the array at location  on a new line.

You are given two numbers at the start. The first tells you how many rows of data there will be, and the second tells you how many pieces of data you are going to be pulling from it.
The next rows are the variable-length arrays (data). Each row starts with a number that tells you how long that row is. Then, the numbers following that are the actual data.
The rows after that are sort of like the coordinates for the data you are supposed to output. The first number tells you what row it is in, and the second tells you what column it is in.

Example:
2 1
5 3 4 2 5 1
7 9 6 8 4 6 7 0
1 2

The "2 1" tells us we have two rows of data and one question about it.
The next two rows are that data. We have 5 important numbers in the first row and 7 in the next, with one number at the start telling us so:
5 3 4 2 5 1 (The five pieces of data are "3 4 2 5 1")
7 9 6 8 4 6 7 0 ("9 6 8 4 6 7 0")
Since we start everything with zero in programming, you could say that the 3 in that data is the 0th number in the 0th row. 5 is the 3rd number in the 0th row. 8 is the 2nd number in the 1st row.
The last line, "1 2", is the question. It is asking you to print out the second number in the first row. (Don't forget that we start counting at zero!) In this case, that is 8. If you printed out an 8 in response to this example problem, you would be correct.

Example 2:
2 3
5 3 4 2 5 1
7 9 6 8 4 6 7 0
1 2
0 0
0 4

This is the exact same as the first problem, but it has three questions now.
The solution would be:
8 3 1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void input_arrays(int n, vector <vector <int>> &arrays){
    int size_of_array {}, temp {};
    for(int i {0}; i < n; i++){
        cin>>size_of_array;
        vector <int> temp_array;
        for(int j {0}; j < size_of_array; j++){
            cin>>temp;
            temp_array.push_back(temp);
        }
        arrays.push_back(temp_array);
    }
}

void input_queries(int n, vector <vector <int>> &queries){
    int temp;
    for (int i {0}; i < n; i++){
        vector <int> temp_array;        
        for(int j {0}; j < 2; j++){
            cin>>temp;
            temp_array.push_back(temp);
        }
        queries.push_back(temp_array);
    }
}

int main() {
    int no_of_array {}, no_of_query {};
    cin>>no_of_array>>no_of_query;
    
    vector <vector <int>> arrays, queries;
    input_arrays(no_of_array, arrays);
    
    input_queries(no_of_query, queries);
    
    for(int m{0}; m < no_of_query; m++){
        int i {queries[m][0]}, j {queries[m][1]};
        cout<<arrays[i][j]<<endl;
    }
    
    return 0;
}