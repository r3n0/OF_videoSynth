#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("Video Synth");
    ofSetWindowShape(1200, 800);
    //ofSetFullscreen(true);
    ofSetFrameRate(60);
    showGui = false;
    ofLoadImage (image, "mandala.jpg");
    videito.load("esfera2.mp4");
    videito.play();
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    shader.load("kaleido");


    gui.setup("Parameters", "settings.xml");
    gui.add(countX.setup("countX", 50, 0, 400));
    gui.add(stepX.setup("stepX", 2, 0, 5));
    gui.add(stroke.setup("stroke", 2, 0, 10));
    gui.add(twistX.setup("twistX", 5, -3, 3));
    gui.add(posY.setup("posY", 10, -200, 200));
    gui.add(scale.setup(
                "scale",
                ofVec2f(2,2),
                ofVec2f(0,0),
                ofVec2f(10,10)
                ));
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

    mixer.setup("Mixer");
    mixer.setHeaderBackgroundColor(ofColor::red);
    mixer.setBorderColor(ofColor::darkRed);
    mixer.add(imageAlpha.setup("image", 50, 0, 255));
    mixer.add(videoAlpha.setup("video", 50, 0, 255));
    mixer.add(cameraAlpha.setup("camera", 50, 0, 255));

    kaleidos.setup("kaleidoscopio");
    kaleidos.setHeaderBackgroundColor(ofColor::blue);
    kaleidos.setBorderColor(ofColor::darkBlue);
    kaleidos.add(kenabled.setup("enabled", true));
    kaleidos.add(ksectors.setup("Sectores", 10, 0, 100));
    kaleidos.add(kangle.setup("Angulo", 10, -180, 180));
    kaleidos.add(kx.setup("X", 0.5, 0, 1));
    kaleidos.add(ky.setup("Y", 0.5, 0, 1));


    //gui.minimizeAll();
    gui.add(&mixer);
    gui.add(&kaleidos);
    gui.loadFromFile("settings.xml");

}

//--------------------------------------------------------------
void ofApp::update(){
    videito.update();
    if ( camera.isInitialized() ) camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
    draw2d();
    fbo.end();


    if(kenabled){
        shader.begin();
        shader.setUniform1i( "ksectors", ksectors);
        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
                             ky*ofGetHeight() );
        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
                             0.5*ofGetHeight() );
    }
    ofSetColor(255);
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());

    if ( kenabled ) shader.end();

    if(showGui) gui.draw();
}

void ofApp::draw2d(){
    ofBackground(fondo);
    ofDisableSmoothing();//<---- esto de be ir aquí porque no funciona conjuntamente con el de abajo
    ofEnableBlendMode(OF_BLENDMODE_ADD);//iniciar el modo de fusión
    ofSetColor(255, imageAlpha);
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255, videoAlpha);
    videito.draw(0, 0, ofGetWidth(), ofGetHeight());
    if ( camera.isInitialized() ) {
        ofSetColor( 255, cameraAlpha );
        camera.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    }
    ofEnableAlphaBlending();
    ofEnableSmoothing(); //<---- y aquí se activa de nuevo
    ofPushMatrix();
    //-----
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    stripePattern();
    //-----
    ofPopMatrix();
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
    if(key == 'g'){
        showGui = !showGui;
    }
    if( key == OF_KEY_RETURN){
        ofSaveScreen ("captura" + ofToString(ofRandom(0,1000), 0) + ".png");
    }
    if( key == 's'){
        ofFileDialogResult res;
        res = ofSystemSaveDialog("preset_.xml", "Guardando Preset");
        if (res.bSuccess) gui.saveToFile(res.filePath);
    }
    if (key == 'l'){
        ofFileDialogResult res;
        res = ofSystemLoadDialog("Cargando Preset");
        if (res.bSuccess) gui.loadFromFile(res.filePath);
    }
    if ( key == 'c' ) {
        camera.setDeviceID( 2 );
        camera.setDesiredFrameRate( 30 );
        camera.initGrabber( 1280, 720 );
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

//--------------------------------------------------------------
void ofApp::exit(){
    gui.saveToFile("settings.xml"); //guarda el último estado de la app en el archivithie
}
