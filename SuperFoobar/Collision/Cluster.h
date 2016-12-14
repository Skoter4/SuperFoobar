/*
* FILENAME:       Cluster.h
* PROGRAMMERS:	 Ludvig Danielsson 951221-7937 MED3
*                Alexander Eriksson 950405-9552 MED3
*                Martin Allander 951218-6215 Y2b
*                Tobias Nilsson 950103-6736 MED3
*                Tomas Widfeldt 940121-2015 MED3
* DATE:         2016-12-14
*
* DESCRIPTION:
* This file declares the class Cluster, which works as a memeber-storer. In this file we 
* store the input-members when creating different objects, aswell as defines functions
* to access and change these members values. 
*/


#pragma once
#include <memory>

class Cluster {

public:

	Cluster(int x_s, int y_s, int height_s, int width_s);
	Cluster() = default;
	~Cluster() = default;

	/*
	* FUNCTION: get_x();
	*
	* Returns the variable x.
	*/
	int get_x();

	/*
	* FUNCTION: get_y();
	*
	* Returns the variable y.
	*/
	int get_y();

	/*
	* FUNCTION: get_width();
	*
	* Returns the variable width.
	*/
	int get_width();

	/*
	* FUNCTION: get_height();
	*
	* Returns the variable height.
	*/
	int get_height();

	/*
	* FUNCTION: get_des_x();
	*
	* Returns the variable des_x. 
	*/
	int get_des_x();

	/*
	* FUNCTION: get_des_y();
	*
	* Returns the variable des_y.
	*/
	int get_des_y();

	/*
	* FUNCTION: set_des_x(int);
	*
	* Set des_x-pos to the new value int.
	*/
	void set_des_x(int x);

	/*
	* FUNCTION: set_des_y(int);
	*
	* Set des_y-pos to the new value int.
	*/
	void set_des_y(int y);

	/*
	* FUNCTION: set_x(int);
	*
	* Set x-pos to the new value int.
	*/
	void set_x(int);

	/*
	* FUNCTION: set_y(int);
	*
	* Set y-pos to the new value int.
	*/
	void set_y(int);

	/*
	* FUNCTION: set_width(int);
	*
	* Set the width to the new value int.
	*/
	void set_width(int);

	/*
	* FUNCTION: set_height(int);
	*
	* Set the height to the new value int.
	*/
	void set_height(int);


private:

	//Memeberdeclarations
	int x;
	int y;
	int height;
	int width;
	int desired_x = 0;
	int desired_y = 0;
};