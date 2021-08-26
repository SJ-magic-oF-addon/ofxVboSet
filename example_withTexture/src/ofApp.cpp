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
	ofSetWindowShape(1280, 720);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	********************/
	img.load("img.jpg");
	
	// VboSet.setup(NUM_PARTICLES);
	VboSet.setup(NUM_PARTICLES, img);
	Refresh_vboVerts();
	Refresh_vboColor();
	VboSet.update_vertex_color();
	
	// VboSet.setup_StaticTexture(img); // 後から設定も可
}

/******************************
1--2
|  |
0--3
******************************/
void ofApp::Refresh_vboVerts()
{
	ofVec2f ofs(100, 100);
	
	VboSet.set_vboVerts(0, ofs.x, ofs.y + SQUARE_H);
	VboSet.set_vboVerts(1, ofs.x, ofs.y);
	VboSet.set_vboVerts(2, ofs.x + SQUARE_W, ofs.y);
	VboSet.set_vboVerts(3, ofs.x + SQUARE_W, ofs.y + SQUARE_H);
}

/******************************
******************************/
void ofApp::Refresh_vboColor()
{
	ofColor col(255, 255, 255, 255);
	// ofColor col(255, 0, 0, 255); // textureの赤成分のみ抽出して表示
	VboSet.set_singleColor(col);

	// 頂点ごとに違う色をset.
	/*
	VboSet.set_vboColor(0, ofColor(255, 0, 0, 255));
	VboSet.set_vboColor(1, ofColor(0, 255, 0, 255));
	VboSet.set_vboColor(2, ofColor(0, 0, 255, 255));
	VboSet.set_vboColor(3, ofColor(255, 255, 0, 255));
	*/
	
	return;
}


/******************************
******************************/
void ofApp::update(){
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
	
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
	
	glLineWidth(1); // ofSetLineWidth(1);
	ofFill();
	img.bind(); // GPU側にimgを転送.
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
