//
// author: SongZihui
// date: 2022-4-16
// a-star.h
//
#ifndef _a_star_h
#define _a_star_h

#define map_size 1000

#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ofstream;

// 点
typedef struct point{
    int x = 0;
    int y = 0;
    unsigned int value;
}point;

class a_star{

public:

  // 构造函数
  a_star(point start, point end, vector<point> barrier){
      this->start = start;
      this->end = end;
      this->barrier = barrier;
      // 初始化障碍
      for(int i=0;i < barrier.size();i++){
          map[barrier[i].x][barrier[i].y] = 1;
      }
      map[end.x][end.y] = 1;
      map[start.x][start.y] = 1;
      // 先加入起点
      open_list.push_back(start);
      in.open("../../../../src/script/log.csv");
      in<<"x"<<","<<"y"<<","<<"value"<<"\n";
  }

  // 析构函数
  ~a_star(){
      ofstream wall;
      wall.open("../../../../src/script/wall.csv");
      if(wall){
        wall << "x"<<","<<"y"<<"\n";
        for(int i=0; i < this->barrier.size(); i++){
            wall<<this->barrier[i].x<<","<<this->barrier[i].y<<"\n";
        }
      }
      else{
          std::cout<<"write error!!!"<<std::endl;
      }
    
  }

public:
  // 获取路径
  void plan_path();
private:
  // 日志
  bool log(vector <point> res);

  // 重载日志
  bool log(point cur);

  // 获取相邻的节点
  vector<point> get_near_node(point cur);
  
  // 欧拉距离
  int Euler_distance();
  
  // 重载
  int Euler_distance(point start,point end);

  // 花费
  point f(vector<point> cur);
private:
  // 日志
  ofstream in;
  // 地图
  int map[map_size][map_size];
  // 起点
  point start;
  // 终点
  point end;
  // 障碍
  vector<point> barrier; 
  // 未遍历的
  vector<point> open_list;    
  // 已遍历的
  vector<point> close_list;
  // 路径
  int path[map_size];
};

#endif 
