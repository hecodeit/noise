#include "ofApp.h"

#define NUM_NOISE_OCTAVES 4

float fbm(glm::vec3 x) {
    float v = 0.0;
    float a = 0.5;
    glm::vec3 shift = glm::vec3(100);
    for (int i = 0; i < NUM_NOISE_OCTAVES; ++i) {
        v += a * ofNoise(x);
        x = x * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    noiseMax = 1.f;
    zoff = 0.f;
    roff = 0.f;
    
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,20);
    ofFill();
//    ofSetLineWidth(1);
//    ofDrawEllipse(320, 320, 320, 320);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofBeginShape();
    
    for(float a=0; a<TWO_PI; a+=TWO_PI/90){
        float xoff = ofMap(cos(a), -1, 1, 0, noiseMax);
        float yoff = ofMap(sin(a), -1, 1, 0, noiseMax);
        float r = ofMap(fbm(glm::vec3(xoff, yoff, zoff)), 0, 1, 50, 100)+roff;
        float x = r * cos(a);
        float y = r * sin(a);
//        ofVertex(x,y);
        ofDrawEllipse(x, y, 2, 2);
    }
    ofEndShape(true);
    
    zoff += 0.01;
    roff += 0.1;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
       // It's strange that we can compare the int key to a character like `s`, right?  Well, the super short
       // explanation is that characters are represented by numbers in programming.  `s` and 115 are the same
       // thing.  If you want to know more, check out the wiki for ASCII.
       glReadBuffer(GL_FRONT);  // HACK: only needed on windows, when using ofSetAutoBackground(false)
       ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".png");
   }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
