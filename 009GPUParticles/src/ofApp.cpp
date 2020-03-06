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

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofDisableAlphaBlending();
    
    cam.setupPerspective();
    
    
    // 1,000,000 particles
    unsigned w = 1024;
    unsigned h = 1024;
    
    particles.init(w, h);
    
    particles.loadShaders("update", "draw");
    
    // initial positions
    // use new to allocate 4,000,000 floats on the heap rather than
    // the stack
    
    
    float* particlePosnsB = new float[w * h * 4];
    for (unsigned y = 0; y < h; ++y){
        for (unsigned x = 0; x < w; ++x){
            unsigned idx = y * w + x;
            particlePosnsB[idx * 4] = ofRandom(-1.0, 1.0); // particle x
            particlePosnsB[idx * 4 + 1] = ofRandom(-1.0, 1.0); // particle y
            particlePosnsB[idx * 4 + 2] = ofRandom(-1.0, 1.0); // particle z
            particlePosnsB[idx * 4 + 3] = 0.f; // dummy
        }
    }
    particles.loadDataTexture(0, particlePosnsB);
    delete[] particlePosnsB;
    
    
    float* particlePosns = new float[w * h * 4];
    for (unsigned y = 0; y < h; ++y){
        for (unsigned x = 0; x < w; ++x){
            ofVec3f p = randomPointOnSphere();
            unsigned idx = y * w + x;
            particlePosns[idx * 4] = p.x; // particle x
            particlePosns[idx * 4 + 1] = p.y; // particle y
            particlePosns[idx * 4 + 2] = p.z; // particle z
            particlePosns[idx * 4 + 3] = 0.f; // dummy
        }
    }
    particles.loadDataTexture(1, particlePosns);
    delete[] particlePosns;
    
    // listen for update event to set additonal update uniforms
    ofAddListener(particles.updateEvent, this, &ofApp::onParticlesUpdate);
    
    cam.setPosition(ofVec3f(0.0, 0.0 ,2.5));
    cam.setNearClip(0.5);
    cam.setFarClip(10);
    
    showTex = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    particles.update();
}

// set any update uniforms in this function
void ofApp::onParticlesUpdate(ofShader& shader)
{
    timer += 0.01;
    shader.setUniform1f("timer", timer);
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    particles.draw();
    ofDisableBlendMode();
    cam.end();
    
    if(showTex){
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);
        particles.fbos[1].getTextureReference(0).draw(0,0);
        ofDrawBitmapStringHighlight("Position", 0,14);
        particles.fbos[1].getTextureReference(1).draw(512,0);
        ofDrawBitmapStringHighlight("Velocity", 512,14);
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
//        particles.save("particles.txt");
        ofSaveScreen("savedScreenshot_"+ofGetTimestampString()+".jpg");
    }
    if(key==' '){
        showTex = !showTex;
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
