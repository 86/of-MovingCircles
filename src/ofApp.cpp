#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(64);
    ofBackground(120, 120, 120);
    ofSetFrameRate(20);
    setInit();
}

//--------------------------------------------------------------
void ofApp::update(){
    resetForce();
    updateForce();
    updatePos();
    checkBounds();
    updateRad();
    updateCol();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        ofColor color = ofColor::fromHsb(hue[i],sat[i],brt[i],alp[i]);
        ofSetColor( color );
        ofCircle(pos[i].x, pos[i].y, rad[i]);
    }
    ofDrawBitmapStringHighlight("Moving Circles", 20, 20);
}

//--------------------------------------------------------------
void ofApp::setInit(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        pos[i].set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        vel[i].set(ofRandom(-20, 20),ofRandom(-20, 20));
        frc[i].set(0, 0);
        rad[i] = ofRandom(20, 120);
        inv[i] = 1;
        hue[i] = ofRandom(110, 100);
        sat[i] = ofRandom(180, 140);
        brt[i] = ofRandom(200, 220);
        alp[i] = ofRandom(180, 250);
    }
}

//--------------------------------------------------------------
void ofApp::resetForce(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        frc[i].set(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::updateForce(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        frc[i] = frc[i] - vel[i] * friction;
        frc[i].x += ofRandom(-1, 1);
        frc[i].y += ofRandom(-1, 1);
    }
}

//--------------------------------------------------------------
void ofApp::updatePos(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        vel[i] += frc[i];
        pos[i] += vel[i];
    }
}

//--------------------------------------------------------------
void ofApp::checkBounds(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (pos[i].x < 0 || pos[i].x > ofGetWidth()) {
            vel[i].x *= -1;
        }
        if (pos[i].y < 0 || pos[i].y > ofGetHeight()) {
            vel[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::updateRad(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        if (rad[i] > 120) {
            inv[i] = -1;
        } else if (rad[i] < 20 ) {
            inv[i] = 1;
        }
        rad[i] = rad[i] + 2 * inv[i];
    }
}

//--------------------------------------------------------------
void ofApp::updateCol(){
    for (int i = 0; i < CIRCLE_NUM; i++) {
        alp[i] = alp[i] + 1 * inv[i];
        hue[i] = hue[i] + 0.1 * inv[i];
        sat[i] = sat[i] + 0.1 * inv[i];
        brt[i] = brt[i] + 0.1 * inv[i];
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
