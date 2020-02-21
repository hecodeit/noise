#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void speedChanged();
    
        ofxFloatSlider yFactor;
        ofxFloatSlider speed;
        ofxFloatSlider freq;
        ofxButton isNoise;
        ofxButton isSignedNoise;
        ofxButton isRandom;
        ofxButton isSinA;
        ofxButton isSinB;
        ofxButton isModA;
        ofxButton isModB;
        ofxPanel gui;
    
        float preSpeed;
        float x, prevX, y;
        float radius,initTime,t;
    
        ofPolyline trail;
    
        // these are two "contexts" we can draw into -- opengl (the normal one) and cairo
        ofPtr<ofCairoRenderer> cairo;
        ofPtr<ofBaseRenderer> opengl;
        // useful for drawing the cairo surface onscreen
        ofTexture tex;
};
