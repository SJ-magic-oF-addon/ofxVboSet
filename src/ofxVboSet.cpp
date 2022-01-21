/************************************************************
************************************************************/
#include "ofxVboSet.h"

/************************************************************
************************************************************/

/******************************
******************************/
void ofx__VBO_SET::setup(int size, bool _b_UseTexture){
	/********************
	********************/
	b_UseTexture = _b_UseTexture;
	
	/********************
	std::vectorのresizeとassignの違い (C++)
		https://minus9d.hatenablog.com/entry/2021/02/07/175159
	********************/
	VboVerts.assign(size, ofVec3f(0, 0, 0)); // VboVerts.resize(size);
	VboColor.resize(size);
	if(b_UseTexture) VboTexCoords.resize(size);
	
	/********************
	How to choose between GL_STREAM_DRAW or GL_DYNAMIC_DRAW?
		https://stackoverflow.com/questions/8281653/how-to-choose-between-gl-stream-draw-or-gl-dynamic-draw
		contents
			STREAM
				You should use STREAM_DRAW when the data store contents will be modified once and used at most a few times.
			
			STATIC
				Use STATIC_DRAW when the data store contents will be modified once and used many times.
			
			DYNAMIC
				Use DYNAMIC_DRAW when the data store contents will be modified repeatedly and used many times.
			
			The usage flag is a hint, not a enforcement. Or in other words: Things don't break if you use a "wrong" flag. 
			So I suggest you try all 3: STATIC_DRAW, STREAM_DRAW and DYNAMIC_DRAW and choose the one that gives you best performance – and it's very likely that they will tie.
		
	■	GL_DYNAMIC_DRAW, GL_STATIC_DRAW, と言うのは、コンパイラに対する最適化のためのhintであって、「GL_STATIC_DRAW にしたら書き換えられない」と言う訳ではない。
		「書き換えの頻度」に応じてusage flagを選択する。
	********************/
	Vbo.setVertexData(&VboVerts[0], VboVerts.size(), GL_DYNAMIC_DRAW);
	Vbo.setColorData(&VboColor[0], VboColor.size(), GL_DYNAMIC_DRAW);
	if(b_UseTexture) Vbo.setTexCoordData(&VboTexCoords[0], VboTexCoords.size(), GL_STATIC_DRAW);
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
void ofx__VBO_SET::shift_y_val_of_vboVerts(){
	for(int i = 0; i < VboVerts.size() - 1; i++){
		VboVerts[i].y = VboVerts[i + 1].y;
	}
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
******************************/
void ofx__VBO_SET::set_TexCoords(int id, float _x, float _y){
	/********************
	********************/
	if(VboTexCoords.size() <= id) return;
	
	/********************
	********************/
	VboTexCoords[id] = glm::vec2(_x, _y);
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
description
	CPU -> GPU
******************************/
void ofx__VBO_SET::update_TexCoords(){
	if(b_UseTexture) Vbo.updateTexCoordData(&VboTexCoords[0], VboTexCoords.size());
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
