#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<int, int> umap;
    umap.insert(pair<int, int>(2, 6));
    umap.insert(pair<int, int>(3, 4));
    umap.insert(pair<int, int>(4, 2));
    umap.insert(pair<int, int>(1, 2));
    umap.insert(pair<int, int>(6, 66));
    umap.insert(pair<int, int>(2, 2));
    umap.insert(pair<int, int>(4, 3));
    unordered_map<int, int>::iterator it = umap.begin();
    while (++it != umap.end())
    {
        cout << it->second << ' ';
    }
    it = umap.begin();
    while (it++ != umap.end())
    {
        cout << it->first << ' ';
    }
    cout << endl;

    cout << endl;

    system("pause");
    return 0;
}