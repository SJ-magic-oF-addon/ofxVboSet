/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetBackgroundAuto(true);
	
	ofSetWindowTitle("vbo_set");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(WINDOW_W, WINDOW_H);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	********************/
	img.load("img.png");
	
	VboSet.setup(NUM_PARTICLES, true);
	Refresh_vboVerts();
	Refresh_vboColor();
	VboSet.update_vertex_color();
	
	Refresh_vboTexCoords();
	VboSet.update_TexCoords();
}

/******************************
1--2
|  |
0--3
******************************/
void ofApp::Refresh_vboVerts()
{
	ofVec2f ofs(100, 100);
	
	for(int i = 0; i < NUM_SQUARES; i++){
		VboSet.set_vboVerts(i * 4 + 0, ofs.x + SQUARE_W * i, ofs.y + SQUARE_H);
		VboSet.set_vboVerts(i * 4 + 1, ofs.x + SQUARE_W * i, ofs.y);
		VboSet.set_vboVerts(i * 4 + 2, ofs.x + SQUARE_W * i + SQUARE_W, ofs.y);
		VboSet.set_vboVerts(i * 4 + 3, ofs.x + SQUARE_W * i + SQUARE_W, ofs.y + SQUARE_H);
	}
}

/******************************
******************************/
void ofApp::Refresh_vboColor()
{
	ofColor col(255, 255, 255, 255);
	// ofColor col(255, 0, 0, 255); // textureの赤成分のみ抽出して表示
	VboSet.set_singleColor(col);
	
	/*
	// 頂点ごとに違う色をset.
	for(int i = 0; i < NUM_SQUARES; i++){
		VboSet.set_vboColor(i * 4 + 0, ofColor(255, 0, 0, 255));
		VboSet.set_vboColor(i * 4 + 1, ofColor(0, 255, 0, 255));
		VboSet.set_vboColor(i * 4 + 2, ofColor(0, 0, 255, 255));
		VboSet.set_vboColor(i * 4 + 3, ofColor(255, 255, 0, 255));
	}
	*/
	
	return;
}

/******************************
******************************/
void ofApp::Refresh_vboTexCoords()
{
	for(int i = 0; i < NUM_SQUARES; i++){
		VboSet.set_TexCoords(i * 4 + 0, 0, img.getHeight());
		VboSet.set_TexCoords(i * 4 + 1, 0, 0);
		VboSet.set_TexCoords(i * 4 + 2, img.getWidth(), 0);
		VboSet.set_TexCoords(i * 4 + 3, img.getWidth(), img.getHeight());
	}
}


/******************************
******************************/
void ofApp::update(){
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(0);
	
	/********************
	ここを ofSetColor(255, 0, 0, 255); としても、赤成分の抽出にはならない.
	つまり、shader側が、下記codeのように、gl_Color を反映していない、と言うこと。
		void main(){
			vec2 Coord = gl_TexCoord[0].xy;
			vec4 color = texture2DRect( texture_0, Coord );
			gl_FragColor = color * gl_Color; // gl_Color = ofSetColor();
		}
		
	->赤成分抽出したい場合 : Refresh_vboColor() を参照
	********************/
	ofSetColor(255, 255, 255, 255);
	
	// glLineWidth(1); // ofSetLineWidth(1);
	// ofFill();
	img.bind(0); // GPU側にimgを転送.
	VboSet.draw(GL_QUADS);
	img.unbind();
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
