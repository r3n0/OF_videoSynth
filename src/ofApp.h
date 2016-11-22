#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void stripePattern();
    void draw2d();

    ofxPanel gui;
    ofxIntSlider
                countX,
                stroke,
                imageAlpha,
                videoAlpha,
                cameraAlpha,
                ksectors;
    ofxFloatSlider
                    stepX,
                    twistX,
                    posY,
                    kangle,
                    kx,
                    ky;
    ofxVec2Slider size;
    ofxVec2Slider scale;
    ofxColorSlider colorinche, fondo;
    ofxToggle relleno, typo, kenabled;
    ofxGuiGroup mixer, kaleidos;


    ofTexture image;
    ofVideoPlayer videito;
    ofFbo fbo;
    ofShader shader;
    ofVideoGrabber camera;


    bool showGui;

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
