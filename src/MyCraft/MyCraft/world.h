#pragma once

#include "GL/glew.h"
#include "block.h"
#include "skyBox.h"
#include "cubeRender.h"
#include "blockFactory.h"
#include "chunk/chunk.h"
#include "tree.h"
#include "robot.h"

#include <vector>
#include<unordered_map>

const int WIDTH = 100;

// 创建区块的半径与移除区块的半径
const int CREATE_RADIUS = 4;
const int DESTROY_RADIUS = 6;

class World
{
private:
	CubeRender* cubeRender;
	TreeRender* treeRender;
	RobotRender* robotRender;

	bool picked = false;
	glm::vec3 pickedBlock;

	SkyBox skyBox;	// 天空盒对象
	std::vector<Chunk*> chunks;	// 要渲染的区块

	int chunked(int x);
	Chunk *findChunk(int x, int z);	// 用chunk坐标寻找chunk

	void drawWireCube(int x, int y, int z, glm::mat4 matrix);// 绘制线框

	//世界物体材质
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];

public:
	World();
	~World();

	// 修改需要绘制的线框位置
	void pick_block(int x, int y, int z);
	void unpick_block();

	BlockType get_block(int x, int y, int z);

	// 放一个 Block 在指定坐标中
	void put_block(int x, int y, int z, BlockType type);

	void remove_block(int x, int y, int z);

	int highest(int x, int z);

	// 从文件中加载世界数据, 创建相应的方块对象
	void Load();

	// 初始化世界生成，准备着色器，纹理等
	void init();

	// 渲染整个世界
	void render(glm::mat4 matrix, glm::vec3 cameraPos);

	//设置世界物体反射材质
	void SetAmbientMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);
};