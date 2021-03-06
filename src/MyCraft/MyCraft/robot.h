#pragma once
#define N_ROBOT 4
#include "GL/glew.h"
#include "GL/glut.h"
#include <random>
#include <map>
#include <iostream>
#include <string>


class Robot {
public:
	float size;
	float speed;

	float x, y, z;
	int random_t;//向这一方向最多走的步数
	unsigned int count;//当前向某一方向走的步数
	float vangle;    // 速度偏角
	bool move;

	// 构造函数
	Robot();
	Robot(int x, int y, int z, float s = 1);

	// 设置坐标
	void setLocation(float x, float y, float z);
	void randomMove();

};



class RobotRender {
public:
	Robot robotList[N_ROBOT];
	GLint lid;
	GLint createList();
	void DrawRobot(Robot& robot);
	RobotRender();
};

