#include "ofApp.h"

static ofVec3f randomPointOnSphere()
{
    float lambda = ofRandom(0, 100.0f);
    float u = ofRandom(-1.0f, 1.0f);
    float phi = ofRandom( 2.0 * PI );
    
    ofVec3f p;
    p.x = pow(lambda, 1/3) * sqrt(1.0 - u * u) * cos(phi);
    p.y = pow(lambda, 1/3) * sqrt(1.0 - u * u) * sin(phi);
    p.z = pow(lambda, 1/3) * u;
    
    return p;
}

// https://karthikkaranth.me/blog/generating-random-points-in-a-sphere/

float randn(){
    float u=0,v=0;
    while(u==0){
        u=ofRandom(1.0);
    }
    while(v==0){
        v=ofRandom(1.0);
    }
    return sqrt(-2.0*log(u))*cos(2.0*PI*v);
}

static ofVec3f normallyDistributed() {
    float u = ofRandom(1.0);
    float x1 = randn();
    float x2 = randn();
    float x3 = randn();

    float mag = sqrt(x1*x1 + x2*x2 + x3*x3);
    x1 /= mag; x2 /= mag; x3 /= mag;

    // Math.cbrt is cube root
    float c = cbrt(u);

    return ofVec3f(x1*c, x2*c, x3*c);
}

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
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
    
//    ofVec3f top(100.0, 50.0, 0.0);
//    ofVec3f left(50.0, 150.0, 0.0);
//    ofVec3f right(150.0, 150.0, 0.0);
//
//    mesh.addVertex(top);
//    mesh.addVertex(left);
//    mesh.addVertex(right);
    
    
    
//    for (int i = 0; i < 500000; i++) {
//      mesh.addVertex(ofVec3f(
//        ofRandom(-100.0, 100.0),
//        ofRandom(-100.0, 100.0),
//        ofRandom(-100.0, 100.0))
//      );
//    }
    
    for (int i = 0; i < 500000; i++) {
        mesh.addVertex(normallyDistributed()*400);
        mesh.addColor(ofFloatColor(0.0, 0.0, 0.0, 0.8)); // alpha white
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    cam.begin();
    mesh.draw();
    cam.end();
    
    ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
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
