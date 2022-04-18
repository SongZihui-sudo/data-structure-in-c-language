#include <iostream>
#include "A-star.h"
#include <vector>

using std::vector;

int main(int argc, char** argv){
    point p_a;
    p_a.x = 0;
    p_a.y = 0;
    point p_b;
    p_b.x = 5;
    p_b.y = 10;
    vector<point> barrier;
    for (int i = 0; i < 5; i++){
        point p;
        p.x = 1;
        p.y = i;
        barrier.push_back(p);
    }
    a_star *a = new a_star(p_a, p_b,barrier);
    a->plan_path();
    a->~a_star();
    return 0;
}
