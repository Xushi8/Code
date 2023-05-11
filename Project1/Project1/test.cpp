#include <iostream>
#include<unordered_map>

using namespace std;


int main()
{
    unordered_map<int, int> umap;
    //umap.insert(2, 8);
    //umap.insert(3, 22);
    //umap.insert(1, 55);
    //umap.insert(6, 12);
    //umap.insert(5, 13);
    for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
    {
        cout << it->second << '\n';
    }
    cout << endl;

    system("pause");
    return 0;
}