/*
Implement  structures:

* struct Workshop having the following members:

The workshop's start time.
The workshop's duration.
The workshop's end time.

* struct Available_Workshops having the following members:

An integer,  (the number of workshops the student signed up for).
An array of type Workshop array having size .

Implement  functions:

* Available_Workshops* initialize (int start_time[], int duration[], int n)
Creates an Available_Workshops object and initializes its elements using the elements in the  and  parameters (both are of size ). Here,  and  are the respective start time and duration for the  workshop. This function must return a pointer to an Available_Workshops object.

* int CalculateMaxWorkshops(Available_Workshops* ptr)
Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.
*/

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int n;
    Workshops * workshops; 
};

Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* res;
    res = new Available_Workshops;
    res -> n = n;
    
    res -> workshops = new Workshops[n];
        
    for(int i{0}; i<n; i++){
        Workshops new_workshop;
        new_workshop.start_time = start_time[i];
        new_workshop.duration = duration[i];
        new_workshop.end_time = start_time[i] + duration[i];
        res -> workshops[i] = new_workshop;
    }

    return res;
}

int CalculateMaxWorkshops(Available_Workshops * ptr){
    // Sorting the workshop array with respect to their endtime
    sort(ptr->workshops, (ptr->workshops)+ptr->n, 
        [](Workshops &a,Workshops &b){
         return a.end_time < b.end_time;
        });
        
    int cur_end {};
    int max_workshop {};
    for(auto i {ptr->workshops}; i != (ptr->workshops)+ptr->n; ++i){
        if(i->start_time >= cur_end){
            max_workshop++;
            cur_end = i->end_time;
        }
    }
    return max_workshop;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
