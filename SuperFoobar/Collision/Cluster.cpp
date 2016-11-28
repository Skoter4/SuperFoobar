#include "Cluster.h" 
#include <iostream>

Cluster::Cluster(int x_s, int y_s, int height_s, int width_s){
  x = x_s;
  y = y_s;
  height = height_s;
  width = width_s;
} 

int Cluster::begin_x(){
  return desired_x;
}

int Cluster::begin_y(){
  return desired_y;
}

int Cluster::end_x(){
  int endx = 0;
  endx = desired_x + width;
  return endx;
}

int Cluster::end_y(){
  int endy = 0;
  endy = desired_y + height;
  return endy;
}

void Cluster::set_des_x(int x){
  desired_x = x;
}

void Cluster::set_des_y(int y){
  desired_y = y;
}
