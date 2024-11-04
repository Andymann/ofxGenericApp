#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    iWIDTH = ofGetScreenWidth()/3;
    iHEIGHT = ofGetScreenHeight()/3;
    ofSetWindowShape( iWIDTH, iHEIGHT);
    ofSetWindowTitle(TITLE + " " + VERSION);
    ofSetBackgroundColor( COL_BG_WINDOW );
    ofSetFrameRate(30); //ofSetVerticalSync(true);
    ofSetEscapeQuitsApp(true); 
    buildGui();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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

vector<string> ofApp::getMidiInputs(){
    vector<string> opts = {midiIn.getInPortList()};
    opts.push_back( LBL_NOMIDIIN );
    return opts;
}

vector<string> ofApp::getMidiOutputs(){
    vector<string> opts = {midiOut.getOutPortList()};
    opts.push_back( LBL_NOMIDIOUT );
    return opts;
}

void ofApp::buildGui(){

    leftGui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
    leftGui->setWidth( iWIDTH/2 -GUIPADDING );

    rightGui = new ofxDatGui( ofxDatGuiAnchor::TOP_RIGHT );
    rightGui->setWidth( iWIDTH/2 -GUIPADDING);

    lblMidiIn = leftGui->addLabel( LBL_SELECTMIDIIN );
    lblMidiIn->setTheme(new myLabelTheme());

    
    cmbMidiIn = leftGui->addDropdown("Midi in", getMidiInputs() );
    cmbMidiIn->setTheme(new myDropdownTheme());

    //leftGui->addBreak()->setTheme(new myPaddingTheme() );
    //leftGui->addBreak()->setHeight(20.0f);
    padding1 = leftGui->addBreak();
    padding1->setTheme(new myPaddingTheme() );
    padding1->setHeight( 0./*12 * GUIPADDING*/ );

    lblMidiOut = leftGui->addLabel( LBL_SELECTMIDIOUT );
    lblMidiOut->setTheme(new myLabelTheme());

    cmbMidiOut = leftGui->addDropdown("Midi Out", getMidiOutputs() );
    cmbMidiOut->setTheme(new myDropdownTheme());

    btnTest1 = rightGui->addButton("Rechts");
    btnTest1->setTheme(new myButtonTheme() );

    btnTest3 = ((myButton * )rightGui->addButton("btnTest3"));
    btnTest3->setTheme(new myButtonTheme() );

    

    bottomGui = new ofxDatGui( ofxDatGuiAnchor::BOTTOM_LEFT );
    bottomGui->setWidth(iWIDTH);
    lblBottom = bottomGui->addLabel("lblBottom");
    lblBottom->setTheme(new myLabelTheme());
}
