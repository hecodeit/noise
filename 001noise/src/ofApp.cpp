#include "ofApp.h"

void ofApp::speedChanged(){
    trail.clear();
}

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    gui.setup();
    gui.add(yFactor.setup("y amnt", 100, 50, 200));
    gui.add(speed.setup("x speed (px/s)", 100, 1, 500));
    gui.add(freq.setup("frequency (hz)", 1, 0, 10));
    gui.add(isNoise.setup("ofNoise(t)"));
    gui.add(isSignedNoise.setup("ofSignedNoise(t)"));
    gui.add(isRandom.setup("ofRandom(-1,1)"));
    gui.add(isSinA.setup("sin(TWO_PI*t)"));
    gui.add(isSinB.setup("(sin(TWO_PI*t))/2"));
    gui.add(isModA.setup("modulo(t,1)"));
    gui.add(isModB.setup("modulo(t,1)*2-1"));
    
    radius = 3;
    
    preSpeed = speed;
    
    ofSetVerticalSync(false);
    ofEnableAlphaBlending();
    //----------------------------------------------------------- allocate the cairo renderer
    cairo = ofPtr<ofCairoRenderer>(new ofCairoRenderer);
    cairo->setup("", ofCairoRenderer::IMAGE, false, false);     // allocate for 2d graphics
    cairo->setLineSmoothing(1);
    tex.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    opengl = ofGetCurrentRenderer();                            // grab the current renderer
    
    ofSetCurrentRenderer(cairo);
    cairo_set_line_join(cairo->getCairoContext(), CAIRO_LINE_JOIN_ROUND);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if( fabs(speed - preSpeed) > 0.00001f ){
        speedChanged();
    }
    preSpeed = speed;
    
    t = ofGetElapsedTimef();
    if(trail.size()==0){
        initTime = t;
    }
    t = t - initTime;
    
    x = int(t*speed)%(ofGetWidth());
    
    
    y = ofGetHeight()/2;
    if(isNoise){
        y += ofNoise(t*freq)*yFactor;
    }
    else if(isSignedNoise){
        y += ofSignedNoise(t*freq)*yFactor;
    }
    else if(isRandom){
        y += ofRandom(-1,1)*yFactor;
    }
    else if(isSinA){
        y += sin(t*freq*TWO_PI)*yFactor;
    }
    else if(isSinB){
        y += (sin(t*freq*TWO_PI)+1)*.5*yFactor;
    }
    else if(isModA){
        y += fmod(t*freq,1)*yFactor;
    }
    else if(isModB){
        y += (fmod(t*freq,1)*2-1)*yFactor;
    }
    
    
    if(x<prevX){
        trail.clear();
    }else{
        trail.addVertex(x,y);
    }
    prevX = x;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    ofSetCurrentRenderer(cairo);
    ofEnableAntiAliasing();
    ofEnableAlphaBlending();
    ofClear(71, 255);
    ofSetLineWidth(2);
    ofSetColor(255, 177);
//    ofEnableSmoothing();
    trail.draw();
//    ofDisableSmoothing();

    //--------------------------------------------------------  draw into opengl
    ofSetCurrentRenderer(opengl);
    tex.loadData(cairo->getImageSurfacePixels());
    ofSetColor(255,255,255);
    tex.draw(0,0);
    
    ofDrawCircle(x,y,radius);
    
    ofSetLineWidth(1);
    ofDrawLine(0,ofGetHeight()/2,ofGetWidth(),ofGetHeight()/2);
    
    ofSetColor(255, 177);
    ofDrawLine(0,ofGetHeight()/2 - 1 * yFactor,ofGetWidth(),ofGetHeight()/2 - 1 * yFactor);
    ofDrawLine(0,ofGetHeight()/2 + 1 * yFactor,ofGetWidth(),ofGetHeight()/2 + 1 * yFactor);

    
    gui.draw();
    
    ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate(),0),ofGetWidth()-80,20);
    ofDrawBitmapString("t:" + ofToString(t,2),ofGetWidth()-80,35);
    ofDrawBitmapString("x:" + ofToString(x,2),ofGetWidth()-80,50);
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
