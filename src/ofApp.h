#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void stripePattern();

    ofxPanel gui;
    ofxIntSlider countX, stroke;
    ofxFloatSlider stepX, twistX, posY;
    ofxVec2Slider size;
    ofxVec2Slider scale;
    ofxColorSlider colorinche, fondo;
    ofxToggle relleno, typo;

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
    void exit();

};
