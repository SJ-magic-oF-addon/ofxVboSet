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
	VboSet.setup(NUM_SQUARES * 4); // square
	Set_vboVerts();
	Refresh_vboColor();
}

/******************************
1--2
|  |
0--3
******************************/
void ofApp::Set_vboVerts()
{
	ofVec2f ofs(100, 100);
	
	for(int i = 0; i < NUM_SQUARES; i++){
		VboSet.VboVerts[i * 4 + 0].set(ofs.x + SQUARE_W * i,		ofs.y + SQUARE_H);
		VboSet.VboVerts[i * 4 + 1].set(ofs.x + SQUARE_W * i,		ofs.y);
		VboSet.VboVerts[i * 4 + 2].set(ofs.x + SQUARE_W * (i + 1),	ofs.y);				// ofs.x + SQUARE_W * (i + 1) - 1 だと思ったが 1pix 空いてしまったので、現物合わせ
		VboSet.VboVerts[i * 4 + 3].set(ofs.x + SQUARE_W * (i + 1),	ofs.y + SQUARE_H);	// ofs.x + SQUARE_W * (i + 1) - 1 だと思ったが 1pix 空いてしまったので、現物合わせ
	}
}

/******************************
******************************/
void ofApp::Refresh_vboColor()
{
	/*
	ofColor col(255, 0, 0, 255);
	VboSet.set_singleColor(col);
	
	return;
	*/
	
	for(int i = 0; i < NUM_SQUARES; i++){
		ofColor col(255, 255, 255, 255);
		switch(i % 10){
			case 0:
				col = ofColor(255, 0, 0, 255);
				break;
				
			case 1:
				col = ofColor(0, 255, 0, 255);
				break;
				
			case 2:
				col = ofColor(0, 0, 255, 255);
				break;
				
			case 3:
				col = ofColor(255, 255, 0, 255);
				break;
				
			case 4:
				col = ofColor(0, 255, 255, 255);
				break;
				
			case 5:
				col = ofColor(255, 0, 255, 255);
				break;
				
			default:
				break;
		}
		
		VboSet.set_Color(i, 4, col);		
	}
}


/******************************
******************************/
void ofApp::update(){
	Set_vboVerts();
	Refresh_vboColor();
	VboSet.update();
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
	ofSetColor(255);
	
	VboSet.draw(GL_QUADS);
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
