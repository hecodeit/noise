#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    lineLenght = 100;
    ani = 0.f;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,177);
    ofFill();
    ofSetLineWidth(2);
    
    cam.begin();
    for(float a=TWO_PI/360; a<TWO_PI; a+=TWO_PI/360){
        float r=50;
        float rb = 200;
        
        float xoff = ofMap(cos(a), -1, 1, -10, 10);
        float yoff = ofMap(sin(a), -1, 1, -10, 10);
        
        ofPolyline line;
        for(int i=0; i<lineLenght; i++){
            // 1d
            float zoff = ofMap(ofNoise((float)i/lineLenght , xoff, yoff, ani), 0, 1, -40, 40) * sin((float)i/lineLenght*PI);
            float rr = zoff;

            // grid
//            float zoff = ((rb-r)/lineLenght * i + r) * cos(a) / 64.f;
//            float woff = ((rb-r)/lineLenght * i + r) * sin(a) / 64.f;
//            float rr = ofMap(ofNoise(zoff, woff, ani), 0, 1, -10, 10);
            
            float x = ((rb-r)/lineLenght * i + r) * cos(a);
            float y = ((rb-r)/lineLenght * i + r) * sin(a);
            line.addVertex(x,y,rr);
//            ofDrawEllipse(x, y, rr, 1, 1);
        }
        line.draw();
    }
    
    ani += 0.01;
    cam.end();
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
