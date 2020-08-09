#include "ofApp.h"

// https://karthikkaranth.me/blog/generating-random-points-in-a-sphere/
static ofVec3f sphericalCoordinates() {
    float u = ofRandom(1.0);
    float v = ofRandom(1.0);
    float theta = u * 2.0 * PI;
    float phi = acos(2.0 * v - 1.0);
    float r = cbrt(ofRandom(1.0));
    float sinTheta = sin(theta);
    float cosTheta = cos(theta);
    float sinPhi = sin(phi);
    float cosPhi = cos(phi);
    float x = r * sinPhi * cosTheta;
    float y = r * sinPhi * sinTheta;
    float z = r * cosPhi;
    return ofVec3f(x,y,z);
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    cam.setupPerspective();
//    ofDisableAlphaBlending();
    
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
//    mesh.setUsage(GL_DYNAMIC_DRAW);
    
    unsigned w = 2048;
    unsigned h = 2048;
    
//    for (int i = 0; i < 500000; i++) {
//        mesh.addVertex(sphericalCoordinates()*300);
//        mesh.addColor(ofFloatColor(0.0, 0.0, 0.0, 0.7)); // alpha white
//    }
    for (int i = 0; i < w*h; i++) {
      mesh.addVertex(ofVec3f(
        ofRandom(-1.0, 1.0),
        ofRandom(-1.0, 1.0),
        ofRandom(-1.0, 1.0))
      );
    }
    
    shader.load("shader");
    
//    cam.setDistance(8);
    cam.setPosition(ofVec3f(0.0, 0.0 ,2.5));
    cam.setNearClip(0.5);
    cam.setFarClip(10.0);
    ofEnablePointSprites();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofSetColor(0);
    
    cam.begin();
        shader.begin();
            shader.setUniform1f("time", ofGetElapsedTimef());
            shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            mesh.draw();
            mesh.getVbo().draw(GL_POINTS, 0, mesh.getVertices().size());
            ofDisableBlendMode();
        shader.end();
    cam.end();
    
//    ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        // It's strange that we can compare the int key to a character like `s`, right?  Well, the super short
        // explanation is that characters are represented by numbers in programming.  `s` and 115 are the same
        // thing.  If you want to know more, check out the wiki for ASCII.
        glReadBuffer(GL_FRONT);  // HACK: only needed on windows, when using ofSetAutoBackground(false)
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".jpg");
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
