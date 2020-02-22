//
//  walker.hpp
//  003randomWalk
//
//  Created by Felix He on 2020/2/22.
//

#ifndef walker_hpp
#define walker_hpp

#include "ofMain.h"

class walker{
public:
    walker();
    
    void update();
    void draw();
    
    int constrain(int, int, int);
    
    int x, y;
    
};

#endif /* walker_hpp */


