#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void setInit();
    void resetForce();
    void updateForce();
    void updatePos();
    void checkBounds();
    
    void updateRad();
    void updateCol();
    
    static const int CIRCLE_NUM = 100;
    ofVec2f pos[CIRCLE_NUM];
    ofVec2f vel[CIRCLE_NUM];
    ofVec2f frc[CIRCLE_NUM];
    
    float friction = 0.01;

    float rad[CIRCLE_NUM];
    float inv[CIRCLE_NUM];
    float alp[CIRCLE_NUM];
    float hue[CIRCLE_NUM];
    float sat[CIRCLE_NUM];
    float brt[CIRCLE_NUM];

};
