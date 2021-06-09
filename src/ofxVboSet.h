/************************************************************
■ofVbo
	https://openframeworks.cc/documentation/gl/ofVbo/

■Media Art II 2013 第7回 : openFrameworks 3Dグラフィクス、OpenGL
	https://www.slideshare.net/tado/media-art-ii-2013

■openFrameworksの3D図形の色々な描画方法
	https://ayumu-nagamatsu.com/archives/579/

■glm	
	■glm
		https://openframeworks.cc/documentation/glm/
		
	■The new GLM syntax
		https://openframeworks.cc/learning/02_graphics/how_to_use_glm/
	
	■openFrameworks で glm を利用する
		https://qiita.com/ayumu_nagamatsu/items/f05e330fc7a3a2f6ed66
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxNoncopyable.h"

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class ofx__VBO_SET : private ofx__NON_COPYABLE{
private:
	ofVbo Vbo;
	// vector<ofVec3f> VboVerts;
	vector<glm::vec3> VboVerts;
	vector<ofFloatColor> VboColor;
	
public:
	void setup(int size);
	void set_vboVerts(int id, float _x, float _y, float _z = 0);
	void set_vboColor(int id, const ofColor& color);
	void set_singleColor(const ofColor& color);
	void setColor_perShape(int NumPerShape, int id, const ofColor& color);
	void update_vertex_color();
	void update_vertex();
	void update_color();

	void draw(int drawMode);
	void draw(int drawMode, int first, int total);
	void draw_perShape(int drawMode, int NumPerShape, int first, int total);
};
