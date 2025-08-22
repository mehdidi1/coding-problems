#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <tuple>
#include <vector>

// Main entry point
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a,b,c;
        std::cin >> a;
        int m;
        std::cin >> m >> b >> c;
        for(char cr : c) {
            char temp = b.front();
            b.erase(b.begin());
            if (cr == 'V'){
               a.insert(a.begin(),temp); 
            
            }
            else {
                
               a.insert(a.end(),temp); 
            }
        
        }
        std::cout << a << std::endl;
        
    }
    return 0;
}
