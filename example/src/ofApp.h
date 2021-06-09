/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxVboSet.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	enum{
		NUM_SQUARES = 9,
	};
	enum{
		SQUARE_W = 100,
		SQUARE_H = 100,
	};
	
	ofx__VBO_SET VboSet;
	int draw_id = 0;
	
	void Refresh_vboVerts();
	void Refresh_vboColor();
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
