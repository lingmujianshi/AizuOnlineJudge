//ALDS1_4_B Search - Binary Search
#include <iostream>
#include <vector>
using namespace std;

int binaryceach(vector<int>& V, int key)
{
    int left = 0;
    int right = V.size();
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (V[mid] == key)
            return 1;
        else if (key < V[mid])
            right = mid;
        else
            left = mid+1;
    }
    return 0;
}

int main()
{
    vector<int> S, T;
    int n, q, t;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        S.push_back(t);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        T.push_back(t);
    }
    
    int sum = 0;
    for (auto a : T)
    {
        sum += binaryceach(S, a);
    }
    cout << sum << endl;

    return 0;
}