//
//  walker.cpp
//  003randomWalk
//
//  Created by Felix He on 2020/2/22.
//

#include "walker.hpp"

walker::walker(){
    x = 0;
    y = 0;
}

void walker::update(){
    int choice = int(ofRandom(4));
    
    if (choice == 0) x++;
    else if (choice == 1) x--;
    else if (choice == 2) y++;
    else if (choice == 3) y--;
    
    int rangeWidth = (ofGetWidth()/2) - 50;
    int rangeHeight = (ofGetHeight()/2) - 50;
    
    x = constrain(x, -rangeWidth, rangeWidth);
    y = constrain(y, -rangeHeight, rangeHeight);
}

void walker::draw() {
    ofSetColor(0,20);
    ofDrawRectangle(x, y, 1, 1);
}

int walker::constrain(int input, int min, int max) {
    
    if(input < min){
        return min;
    }
    else if(input > max){
        return max;
    }
    else{
        return input;
    }
}
