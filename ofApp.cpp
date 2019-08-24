#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {


	for (int i = 0; i < 50; i++) {

		auto location = glm::vec2(ofRandom(ofGetWidth()), ((int)ofRandom(ofGetHeight() + ofGetFrameNum()) % (ofGetHeight() + 100) - 50));
		auto scale = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 1, 3);

		ofPushMatrix();
		ofTranslate(location);
		ofRotate(ofRandom(360) + ofGetFrameNum() * ofRandom(3));

		ofBeginShape();
		for (auto deg = 0; deg < 360; deg += 1) {

			ofVertex(this->make_point(deg * DEG_TO_RAD) * scale);
		}
		ofEndShape(true);

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
//Reference by https://twitter.com/shiffman/status/1095764239665512453
glm::vec2 ofApp::make_point(float theta) {

	float x = 16 * (pow(sin(theta), 3));
	float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
	return glm::vec2(x, -y);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}