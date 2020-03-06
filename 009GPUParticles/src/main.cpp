#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
	ofGLFWWindowSettings settings;
    settings.setGLVersion(3, 3); //we define the OpenGL version we want to use
    settings.setSize(640, 640);
    ofCreateWindow(settings);
    
    
    ofRunApp(new ofApp());

}
