#include <iostream>
#include <fstream>

struct muchie{
    int i,j,cost;
};

void InversareMuchie(muchie &muchie1, muchie &muchie2){
    // inversare cost
    muchie1.cost = muchie1.cost + muchie2.cost;
    muchie2.cost = muchie1.cost - muchie2.cost;
    muchie1.cost = muchie1.cost - muchie2.cost;

    // inversare i
    muchie1.i = muchie1.i + muchie2.i;
    muchie2.i = muchie1.i - muchie2.i;
    muchie1.i = muchie1.i - muchie2.i;

    // inversare j
    muchie1.j = muchie1.j + muchie2.j;
    muchie2.j = muchie1.j - muchie2.j;
    muchie1.j = muchie1.j - muchie2.j;
}

int main()
{
    int n , m , *t;
    
    muchie *x;
    
    std::ifstream fi("data6.in");
    std::ofstream fo("data6.out");
    
    fi >> n >> m;
    
    x = new muchie[m];
    t = new int[n];

    for(int i = 0; i < m; ++i){
        fi >> x[i].i >> x[i].j >> x[i].cost;
    }
    
    //sortare tablou x[] după campul cost
    for(int i = 0; i < m; ++i){
        for(int j = i; j < m; ++j){
            if (x[i].cost > x[j].cost){
                InversareMuchie(x[i], x[j]);
            }
        }
    }

    //initializare reprezentanti
    for(int i = 1; i <= n; ++i){
        t[i] = i;
    }
    
    //determinare APM
    int S = 0;
    
    for(int i = 0; i < m; ++i){
        if(t[x[i].i] != t[x[i].j]){ // extremitatile fac parte din subrabori diferiti
            S += x[i].cost;
            
            fo << x[i].i << " - " << x[i].j << std::endl;
            
            //reunim subarborii
            int ai = t[x[i].i], aj = t[x[i].j];
            for(int j = 1; j <= n; ++j){
                if(t[j] == aj){
                    t[j] = ai;
                }
            }
        }
    }
    fo << S;

    delete[] x, t;
    
    fi.close();
    fo.close();
    
    return 0;
}