//
// author: SongZhui
// date: 2022-4-16
// A-star.cc 
//

#include "./A-star.h"
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ofstream;

// 欧拉距离
int a_star::Euler_distance(){
    int res = pow(pow(this->end.x-this->start.x,2)+pow(this->end.y-this->start.y,2),0.5);
    return res;
}
 // 重载
int a_star::Euler_distance(point start,point end){
    int res = pow(pow(end.x-start.x,2)+pow(end.y-start.y,2),0.5);
    return res;
}

// 规划路径
void a_star::plan_path(){
    vector<point> res;
    vector<point> pos;
    point cur;
    while(true){
        pos = this->get_near_node(this->open_list[this->open_list.size()-1]); 
        cur = f(pos);
        this->map[cur.x][cur.y] = 2;
        this->open_list.push_back(cur);
        this->log(cur);
        if(cur.x == this->end.x && cur.y == this->end.y || this->Euler_distance(cur,this->end)<=2){
            std::cout << "GET PAHT"<<std::endl;   
            break;
        }
        else if(cur.x == 1000 && cur.y == 1000){
            std::cout << "NOT FIND PATH"<<std::endl; 
            break;
        } 
        pos.clear();
    }
}

// 获取相邻的节点
vector<point> a_star::get_near_node(point cur){
    
    vector<point> pos;
    point up_right;    
    point right;
    point down_right;
    point down;
    point up;
    point up_left;
    point left;
    point down_left;
    
    if(cur.x+1 <= map_size&&cur.y+1 <= map_size&&this->map[cur.x+1][cur.y+1]!=1){
        up_right.x = cur.x + 1;        
        up_right.y = cur.y + 1;
        up_right.value = 20;
        this->open_list.push_back(up_right);
        pos.push_back(up_right);
    }
    if(cur.x-1 >= 0 && cur.y-1 >= 0&&map[cur.x-1][cur.y-1]!=1){
        down_left.y = cur.y-1;
        down_left.x = cur.x-1;
        down_left.value = 20;
        this->open_list.push_back(down_left);
        pos.push_back(down_left);
    }
    if(cur.x+1<=1000&&cur.y-1>=0&&map[cur.x+1][cur.y-1]!=1){
        down_right.x = cur.x + 1;
        down_right.y = cur.y - 1; 
        down_right.value = 20;
        this->open_list.push_back(down_right);
        pos.push_back(down_right);
    }
    if(cur.x-1>=0&&cur.y+1<=map_size&&map[cur.x-1][cur.y+1]!=1){
        up_left.y = cur.y+1;
        up_left.x = cur.x-1;    
        up_left.value = 20;
        this->open_list.push_back(up_left);
        pos.push_back(up_left);
    }
    if(cur.y+1 <= map_size&&map[cur.x][cur.y+1]!=1){
        up.value = 10;
        up.y = cur.y+1;
        up.x = cur.x;
        this->open_list.push_back(up);
        pos.push_back(up);
    }
    if(cur.x+1 <= map_size&&map[cur.x+1][cur.y]!=1){
        right.x = cur.x + 1;
        right.y = cur.y;
        right.value = 10;
        this->open_list.push_back(right);
        pos.push_back(right);
    }
    if(cur.x-1>=0&&map[cur.x-1][cur.y]!=1){
        left.y = cur.y;
        left.x = cur.x-1;    
        left.value = 10;
        this->open_list.push_back(left);
        pos.push_back(left);
    }
    if(cur.y-1>=0&&map[cur.x][cur.y-1]!=1){
        down.y = cur.y-1;
        down.x = cur.x;
        down.value = 10;
        this->open_list.push_back(down);
        pos.push_back(down);
    }
    return pos;
}

// costing
point a_star::f(vector<point> cur){
    // problem
    int res = 0;
    for(long unsigned int i = 0; i < cur.size();i++){
        res  = cur[i].value + 10*this->Euler_distance(cur[i], this->end);
        cur[i].value = res;
        for(int j = 0; j < i;j++){
            for (int k = 0; k < i - j; k++){
                if (cur[k].value > cur[k+i].value){
                    point p = cur[k];
                    cur[k] = cur[k+1];
                    cur[k+1] = p;
                }
            }
        }
    }
    std::cout<<cur[0].x<<" "<<cur[0].y<<" "<<cur[0].value<<std::endl;
    return cur[0];
}

// 日志
bool a_star::log(vector <point> res){
    if (in){
        for (int i=0; i<res.size(); i++){
            in<<res[i].x<<","<<res[i].y<<","<<res[i].value<<"\n";
        }
        return true;
    }
    else{
        std::cerr << "write log file error!!!" <<std::endl;
        return false;
    }
    in.close();
    return false;
}

// 日志
bool a_star::log(point cur){
    if (in){
        in<<cur.x<<","<<cur.y<<","<<cur.value<<"\n";
        return true;
    }
    else{
        std::cerr << "write log file error!!!" <<std::endl;
        return false;
    }
    in.close();
    return false;
}
