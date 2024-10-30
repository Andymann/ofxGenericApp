#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxMidi.h"





class myButton : public ofxDatGuiButton{
public:
	myButton(string pLabel):ofxDatGuiButton(pLabel){}
};

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;


		vector<string> getMidiInputs();
		vector<string> getMidiOutputs();

		static const int COL_BG_WINDOW = 0x303030;
		static const int COL_BG_BUTTON = 0x304030;
		static const int COL_BG_LABEL = 0x303030;
		static const int COL_DROPDOWN = 0x304030;
		static const int COL_PINK = 0xFF00FF;
		static const int COL_GREEN = 0x00FF00;

		const string LBL_SELECTMIDIIN = "Select Mid IN:";
		const string LBL_SELECTMIDIOUT = "Select Midi OUT";
		const string LBL_NOMIDIIN = "-- No Midi in --";
		const string LBL_NOMIDIOUT = "No Midi OUT";


		const string TITLE = "ofxGenericApp";
		const string VERSION = "v0.1";
		int iWIDTH;
		int iHEIGHT;

		ofxMidiIn midiIn;
		ofxMidiOut midiOut;

		void buildGui();
		ofTrueTypeFont font;

		ofxDatGui *leftGui;
		ofxDatGui *centerGui;
		ofxDatGui *rightGui;
		ofxDatGui *bottomGui;

		ofxDatGuiDropdown* cmbMidiIn;
		ofxDatGuiDropdown* cmbMidiOut;
		ofxDatGuiButton* btnTest1;
		ofxDatGuiButton* btnTest2;
		myButton* btnTest3;

		ofxDatGuiLabel *lblBottom;
		ofxDatGuiLabel *lblMidiIn;
		ofxDatGuiLabel *lblMidiOut;

		ofxDatGuiBreak *padding1;
		
};

/*
class myCustomTheme : public ofxDatGuiTheme{
public:
    myCustomTheme(){
        font.size = 12;
		layout.upperCaseLabels = false;
        //font.file = "path/to/font.ttf";
        init();
    }
};
*/

class myLabelTheme : public ofxDatGuiTheme{
public:
    myLabelTheme(){
        font.size = 10;
		font.file = OF_TTF_MONO;
		layout.height *=1.0;
		color.background = ofApp::COL_BG_LABEL;
		layout.upperCaseLabels = false;
		layout.vMargin = 2.0f;
		stripe.visible=false;
        init();
    }
};

class myDropdownTheme : public ofxDatGuiTheme{
public:
    myDropdownTheme(){
        font.size = 16;
		font.file = OF_TTF_MONO;
		layout.height *=1.0;
		color.background = hex(ofApp::COL_DROPDOWN);
		layout.upperCaseLabels = false;
		layout.vMargin = 2.0f;
		stripe.visible=false;
        init();
    }
};

class myButtonTheme : public ofxDatGuiTheme{
public:
    myButtonTheme(){
        font.size = 16;
		font.file = OF_TTF_MONO;
		layout.height *=1.0;
		layout.upperCaseLabels = false;
		layout.vMargin = 2.0f;
		stripe.visible=true;
		stripe.button = ofColor::fromHex(0xFF00FF);
        init();
    }
};

class myPaddingTheme : public ofxDatGuiTheme{
public:
    myPaddingTheme(){
		color.background = ofColor::fromHex(ofApp::COL_BG_WINDOW);
        init();
    }
};