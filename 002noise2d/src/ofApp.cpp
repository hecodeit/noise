#include "ofApp.h"
#define NUM_NOISE_OCTAVES 5

float fbm(float x) {
    float v = 0.0;
    float a = 0.5;
    float shift = float(100);
    for (int i = 0; i < NUM_NOISE_OCTAVES; ++i) {
        v += a * ofSignedNoise(x);
        x = x * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

float fbm(glm::vec2 x) {
    float v = 0.0;
    float a = 0.5;
    glm::vec2 shift = glm::vec2(100);
    // Rotate to reduce axial bias
    glm::mat2 rot = glm::mat2(cos(0.5), sin(0.5), -sin(0.5), cos(0.50));
    for (int i = 0; i < NUM_NOISE_OCTAVES; ++i) {
        v += a * ofNoise(x);
        x = rot * x * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    
    img.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);
    
    ofPixels pixels = img.getPixels();
        
        for(int x = 0; x < ofGetWidth(); x++) {
            for(int y = 0; y < ofGetHeight(); y++) {
                
    //            float bright = ofMap(ofRandomf(),0,1,0,255);
                float bright = ofMap(fbm(glm::vec2(x/160.f,y/160.f)),0,1,0,255);
                pixels.setColor(x, y, ofColor(bright));
            }
        }
        
        img.setFromPixels(pixels);
}

//--------------------------------------------------------------
void ofApp::update(){

    t = ofGetElapsedTimef();

    trailx = int(t*200.f)%(ofGetWidth());
    traily = ofGetHeight()/2;
    traily += fbm(t*1)*400;
    
    if(trailx<prevX){
        trail.clear();
    }else{
        trail.addVertex(trailx,traily);
    }
    

    prevX = trailx;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    img.draw(0,0);
    
    ofSetLineWidth(2);
    ofSetColor(255, 177);
//    ofClear(71, 255);
    trail.draw();
    
    ofSetLineWidth(1);
    ofDrawLine(0,ofGetHeight()/2,ofGetWidth(),ofGetHeight()/2);
    

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
