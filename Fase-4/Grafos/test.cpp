#include <iostream>
#include <set>

using namespace std;

int main() {
    set<pair<int, int> > a;
    pair<int,int> par;
    
    par.first = 6;
    par.second = 3;

    a.insert(par);
  
    par.first = 1;
    par.second = 4;

    a.insert(par);
	a.erase(a.begin());

    set<pair<int, int> >::iterator it;

    it = a.begin();

    cout << it->first << it->second << endl;


    return 0;
}
