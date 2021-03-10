#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "structs_and_classes.h"

class bone
{
private:
	std::string& mFileName;
	std::vector<triangle>& mFacet;
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;
	double mOffset;

public:
	// 초기화(main에 있는 vector에 내용이 자동으로 추가됨)
	bone(std::string& fileName, std::vector<triangle>& facet, double offset);
	
	void draw(); // 그리는 함수
	void move(); // 이동 함수
	void rotate(); // 회전 함수
};