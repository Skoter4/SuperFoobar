//#include "../Block-filer/Block.h"
#include "Cluster.h"
#include <iostream>
using namespace std;

Cluster::Cluster(int x_s, int y_s, int height_s, int width_s) {
	x = x_s;
	y = y_s;
	height = height_s;
	width = width_s;
	desired_x = x_s;
	desired_y = y_s;
}


int Cluster::get_x()
{
	return x;
}

int Cluster::get_y()
{
	return y;
}

int Cluster::get_height()
{
	return height;
}

int Cluster::get_width()
{
	return width;
}

int Cluster::get_des_x()
{
	return desired_x;
}

int Cluster::get_des_y()
{
	return desired_y;
}

void Cluster::set_des_x(int x) {
	desired_x = x;
}

void Cluster::set_des_y(int y) {
	desired_y = y;
}

void Cluster::set_x(int new_x)
{
	x = new_x;
}

void Cluster::set_y(int new_y)
{
	y = new_y;
}

void Cluster::set_width(int width_set)
{
	width = width_set;
}

void Cluster::set_height(int height_set)
{
	height = height_set;
}

