#include "ofApp.h"
// ------------------------------------------------------------
static ofVec3f randomPointOnSphere()
{
    float lambda = ofRandom(1.0f);
    float u = ofRandom(-1.0f, 1.0f);
    float phi = ofRandom( 2.0 * PI );
    
    ofVec3f p;
    p.x = pow(lambda, 1/3) * sqrt(1.0 - u * u) * cos(phi);
    p.y = pow(lambda, 1/3) * sqrt(1.0 - u * u) * sin(phi);
    p.z = pow(lambda, 1/3) * u;
    
    return p;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetColor(255);
    ofFill();
    ofSetSphereResolution(2);
    
    for(int i=0; i<10000; i++){
        points.push_back(randomPointOnSphere()*200);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    cam.begin();
    for(int i=0; i<points.size(); i++){
//        ofVertex(randomPointOnSphere()*100);
        ofDrawSphere(points[i], 1);
    }
    cam.end();
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
