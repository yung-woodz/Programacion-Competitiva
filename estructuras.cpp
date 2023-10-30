#include<bits/stdc++.h>

using namespace std;

bool compareInterval(pair<int,int> i1, pair<int,int> i2){
    return(i1.second < i2.first);
}

int main(){

    int a[10];

    vector<int> a2;

    /*Si el vector es estatico, se puede declarar un valor a un espacio
    a2[1] = 16;*/

    vector <pair<int,int> > arr;

    a2.push_back(5);

    arr.push_back(make_pair(5,3));

    sort(a, a+10);
    sort(a2.begin(), a2.end()/*, greater<int>() de menor a mayor*/);

    


}