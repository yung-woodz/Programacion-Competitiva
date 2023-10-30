#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int n, long long s) {
    int i = 0, j = 0; // Punteros para rastrear el rango del subarreglo.
    long long sum = 0; // Suma actual del subarreglo.
    vector<int> result;

    while (j <= n) {
        if (sum < s) {
            // Si la suma actual es menor que s, avanzamos el puntero j.
            sum += arr[j];
            j++;
        } else if (sum == s) {
            // Si la suma actual es igual a s, encontramos un subarreglo que suma s.
            // Agregamos los índices al resultado.
            result.push_back(i + 1); // +1 porque los índices son 1-based.
            result.push_back(j);
            return result; // Terminamos la búsqueda.
        } else {
            // Si la suma actual es mayor que s, avanzamos el puntero i.
            sum -= arr[i];
            i++;
        }
    }

    // Si no se encuentra ningún subarreglo, agregamos -1 al resultado.
    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
}

};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}