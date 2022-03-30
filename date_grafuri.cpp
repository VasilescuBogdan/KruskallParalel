#include <fstream>
#include <random>
#include <time.h>

#define NrNoduriMinim 10000
#define NrNoduriMaxim 100000
#define CostMaxim 10

int main(){
    std::ofstream f("data6.in");
    int m, n;

    srand(time(0));
    // generam numarul de noduri
    n = rand() % (NrNoduriMaxim - NrNoduriMinim) + NrNoduriMinim + 1;
    f << n << " ";
    // generam numarul de muchii
    m = rand() % (n * n - n) + n + 1;
    f << m << std::endl;

    // generam muchiile
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (m == 0){
                break;
            } 
            int cost;
            if (rand() % 2 == 0){
                cost = 0; // nu avem muchie
            } else {
                cost = rand() % CostMaxim + 1; // cost apartine intervalului [1, CostMaxim]
            }
            if (cost > 0){
                f << i << " " << j << " " << cost << std::endl;
                --m;
            }
        }
        if (m == 0){
            break;
        }
    }
    
    f.close();
    return 0;
}