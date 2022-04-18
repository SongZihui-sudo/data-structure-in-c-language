#include "../A-star.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv){
    point p_a;
    p_a.x = 0;
    p_a.y = 0;
    point p_b;
    p_b.x = 10;
    p_b.y = 10;
    a_star *a = new a_star(p_a, p_b,{});
    //cout<<a->Euler_distance()<<endl;
    return 0;
}
