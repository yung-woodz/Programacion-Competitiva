#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>> n;
    int resultado = 0;

    for(int i = 1 ; i < n+1 ; i++)
        resultado = resultado + i;
    cout<<resultado;

}