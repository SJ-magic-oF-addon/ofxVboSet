/************************************************************
************************************************************/
#include "ofxVboSet.h"

/************************************************************
************************************************************/

/******************************
******************************/
void ofx__VBO_SET::setup(int size){
	/********************
	std::vectorのresizeとassignの違い (C++)
		https://minus9d.hatenablog.com/entry/2021/02/07/175159
	********************/
	VboVerts.assign(size, ofVec3f(0, 0, 0)); // VboVerts.resize(size);
	VboColor.resize(size);
	
	Vbo.setVertexData(&VboVerts[0], VboVerts.size(), GL_DYNAMIC_DRAW);
	Vbo.setColorData(&VboColor[0], VboColor.size(), GL_DYNAMIC_DRAW);
}

/******************************
******************************/
void ofx__VBO_SET::setup(int size, ofImage& tex_img){
	/********************
	std::vectorのresizeとassignの違い (C++)
		https://minus9d.hatenablog.com/entry/2021/02/07/175159
	********************/
	VboVerts.assign(size, ofVec3f(0, 0, 0)); // VboVerts.resize(size);
	VboColor.resize(size);
	
	Vbo.setVertexData(&VboVerts[0], VboVerts.size(), GL_DYNAMIC_DRAW);
	Vbo.setColorData(&VboColor[0], VboColor.size(), GL_DYNAMIC_DRAW);
	
	/********************
	********************/
	setup_StaticTexture(tex_img);
}

/******************************
座標軸
	texture image上で、左上原点, 右に+x, 下に+y.
******************************/
void ofx__VBO_SET::setup_StaticTexture(ofImage& img){
	VboTexCoords.resize(4);
	
	VboTexCoords[0] = glm::vec2(0, img.getHeight());
	VboTexCoords[1] = glm::vec2(0, 0);
	VboTexCoords[2] = glm::vec2(img.getWidth(), 0);
	VboTexCoords[3] = glm::vec2(img.getWidth(), img.getHeight());
	
	Vbo.setTexCoordData(&VboTexCoords[0], VboTexCoords.size(), GL_STATIC_DRAW);
	Vbo.updateTexCoordData(&VboTexCoords[0], VboTexCoords.size());
}

/******************************
******************************/
void ofx__VBO_SET::set_vboVerts(int id, float _x, float _y, float _z){
	/********************
	********************/
	if(VboVerts.size() <= id) return;
	
	/********************
	********************/
	// VboVerts[id].set(_x, _y, _z);
	VboVerts[id] = glm::vec3(_x, _y, _z);
}

/******************************
******************************/
void ofx__VBO_SET::set_vboColor(int id, const ofColor& color){
	/********************
	********************/
	if(VboColor.size() <= id) return;

	/********************
	********************/
	VboColor[id].set( double(color.r)/255, double(color.g)/255, double(color.b)/255, double(color.a)/255 );
}

/******************************
******************************/
void ofx__VBO_SET::set_singleColor(const ofColor& color){
	/********************
	********************/
	for(int i = 0; i < VboColor.size(); i++) { VboColor[i].set( double(color.r)/255, double(color.g)/255, double(color.b)/255, double(color.a)/255); }
}

/******************************
description
	shape(e.g. GL_QUADS = 四角形)ごとに色をset
******************************/
void ofx__VBO_SET::setColor_perShape(int NumPerShape, int id, const ofColor& color){
	/********************
	********************/
	if(VboColor.size() < (id + 1) * NumPerShape) return;
	
	/********************
	********************/
	for(int i = 0; i < NumPerShape; i++){
		VboColor[id * NumPerShape + i].set( double(color.r)/255, double(color.g)/255, double(color.b)/255, double(color.a)/255);
	}
}

/******************************
description
	CPU -> GPU
******************************/
void ofx__VBO_SET::update_vertex_color(){
	update_vertex();
	update_color();
}

/******************************
description
	CPU -> GPU
******************************/
void ofx__VBO_SET::update_vertex(){
	Vbo.updateVertexData(&VboVerts[0], VboVerts.size());
}

/******************************
description
	CPU -> GPU
******************************/
void ofx__VBO_SET::update_color(){
	Vbo.updateColorData(&VboColor[0], VboColor.size());
}

/******************************
******************************/
void ofx__VBO_SET::draw(int drawMode){
	Vbo.draw(drawMode, 0, VboVerts.size());
}

/******************************
******************************/
void ofx__VBO_SET::draw(int drawMode, int first, int total){
	/********************
	********************/
	if(VboVerts.size() < first + total) return;
	
	/********************
	********************/
	Vbo.draw(drawMode, first, total);
}

/******************************
******************************/
void ofx__VBO_SET::draw_perShape(int drawMode, int NumPerShape, int first, int total){
	/********************
	********************/
	if(VboVerts.size() < (first + total) * NumPerShape) return;
	
	/********************
	********************/
	Vbo.draw(drawMode, first * NumPerShape, total * NumPerShape);
}
