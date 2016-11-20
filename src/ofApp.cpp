#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Video Synth");
    ofSetWindowShape(1280, 720);
    //ofSetFullscreen(true);
    ofSetFrameRate(60);

    gui.setup("Parameters", "settings.xml");
    gui.add(countX.setup("countX", 50, 0, 400));
    gui.add(stepX.setup("stepX", 20, 0, 10));
    gui.add(twistX.setup("twistX", 5, -10, 10));
    gui.add(stroke.setup("stroke", 2, 0, 5));
    gui.add(scale.setup(
                "scale",
                ofVec2f(2,2),
                ofVec2f(0,0),
                ofVec2f(10,10)
                ));
    gui.add(posY.setup("posY", 10, -200, 200));
    gui.add(colorinche.setup(
                "color",
                ofColor::black,
                ofColor(0,0,0,0),
                ofColor::white
                ));
    gui.add(relleno.setup("relleno", false));
    gui.add(typo.setup("tipo", false));
    gui.add(fondo.setup(
                "fondo",
                ofColor::black,
                ofColor(0,0,0),
                ofColor::white
                ));
    gui.loadFromFile("settings.xml");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(fondo);

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    //-----
    /*
    ofSetColor(ofColor::black);
    ofSetLineWidth(5);
    ofDrawLine(-200,-100,-200,0);
    ofDrawRectangle(-100, -100,100,100);
    ofDrawTriangle(100,-100,0,0,200,0);
    ofDrawCircle(250, -50, 50);
    ofSetCircleResolution(40);
    ofNoFill();
    ofDrawCircle(350, -50, 50);
    */
    stripePattern();
    //-----
    ofPopMatrix();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::stripePattern(){
    ofSetColor(colorinche);
    ofSetLineWidth(stroke);
    if(relleno) ofFill(); else ofNoFill();
    for (int i = -countX; i<countX; i++){
        ofPushMatrix();
        ofTranslate(i * stepX, 0);
        //ofDrawLine(40,30,30,32);
        ofScale(scale -> x, scale -> y);
        ofRotate(i * twistX);
        if(typo){
            ofDrawTriangle(0,posY,-50,posY + 100,50,posY + 100);
        } else{
            ofDrawRectangle(0-50,posY, 100,100);
        }
        ofPopMatrix();
    }
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

//--------------------------------------------------------------
void ofApp::exit(){
    gui.saveToFile("settings.xml"); //guarda el último estado de la app en el archivithie
}
