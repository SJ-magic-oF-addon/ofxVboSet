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
	Refresh_vboVerts();
	Refresh_vboColor();
	VboSet.update_vertex_color();
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
		VboSet.set_vboVerts(i * 4 + 0, ofs.x + SQUARE_W * i,		ofs.y + SQUARE_H);
		VboSet.set_vboVerts(i * 4 + 1, ofs.x + SQUARE_W * i,		ofs.y);
		VboSet.set_vboVerts(i * 4 + 2, ofs.x + SQUARE_W * (i + 1),	ofs.y);				// ofs.x + SQUARE_W * (i + 1) - 1 ではないので、注意
		VboSet.set_vboVerts(i * 4 + 3, ofs.x + SQUARE_W * (i + 1),	ofs.y + SQUARE_H);	// ofs.x + SQUARE_W * (i + 1) - 1 ではないので、注意
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
				col = ofColor(255, 0, 0, 255);		// Red
				break;
				
			case 1:
				col = ofColor(0, 255, 0, 255);		// Green
				break;
				
			case 2:
				col = ofColor(0, 0, 255, 255);		// Blue
				break;
				
			case 3:
				col = ofColor(255, 255, 0, 255);	// Yellow
				break;
				
			case 4:
				col = ofColor(0, 255, 255, 255);	// Cian
				break;
				
			case 5:
				col = ofColor(255, 0, 255, 255);	// Pink
				break;
				
			case 6:
				col = ofColor(255, 100, 0, 255);	// Orange
				break;
				
			case 7:
				col = ofColor(100, 0, 255, 255);	// purple
				break;
				
			case 8:
				col = ofColor(0, 100, 255, 255);	// sky blue
				break;
				
			case 9:
				col = ofColor(255, 255, 255, 255);	// white
				break;
				
			default:
				break;
		}
		
		VboSet.setColor_perShape(4, i, col);
	}
}


/******************************
******************************/
void ofApp::update(){
	Refresh_vboVerts();
	Refresh_vboColor();
	
	VboSet.update_vertex_color();
	// VboSet.update_vertex();
	// VboSet.update_color();
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(30);
	ofSetColor(255);
	
	switch(draw_id){
		case 0:
			glLineWidth(1); // ofSetLineWidth(1);
			ofFill();
			VboSet.draw(GL_QUADS);
			break;
			
		case 1:
			glLineWidth(1);
			ofNoFill();
			VboSet.draw(GL_QUADS);
			break;
			
		case 2:
			glLineWidth(10);
			ofNoFill();
			VboSet.draw(GL_QUADS);
			break;
			
		case 3:
			glPointSize(2);
			VboSet.draw(GL_POINTS);
			break;
			
		case 4:
			glPointSize(10);
			VboSet.draw(GL_POINTS);
			break;
			
		case 5:
			glLineWidth(1);
			ofFill();
			VboSet.draw_perShape(GL_QUADS, 4, 1, 2);
			break;
			
		case 6:
			glLineWidth(10);
			ofFill();
			VboSet.draw_perShape(GL_QUADS, 4, 1, 2);
			break;
			
		case 7:
			ofFill();
			VboSet.draw(GL_QUADS, 1, 8);
			break;
			
		case 8:
			ofSetColor(255, 0, 0);
			glLineWidth(10); // ofSetLineWidth(1);
			ofFill();
			ofDrawRectangle(100, 100, 100, 100);
			break;
			
		case 9:
			ofSetColor(255, 0, 0);
			glLineWidth(10); // ofSetLineWidth(1);
			ofNoFill();
			ofDrawRectangle(100, 100, 100, 100);
			break;
	}
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			draw_id = key - '0';
			break;
	}
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
