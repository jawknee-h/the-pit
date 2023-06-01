#pragma once

#include "ofMain.h"
#include "Centipede.h"
#include "ofxAssimpModelLoader.h"
#include "MyCamera.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		void draw_scene();
		void draw_scene_wireframe();
		void draw_creatures();

		void manage_events(float current_frame);
		void reset_scene();
		
		

	private:
		Centipede centipede_1{
			300, // speed
			12, // spacing
			70, // segments
			5.0, // size
			-800 // start time
		};

		// The path that the large centipede will follow while flying.
		vector<ofPoint> centipede_path = {
			{0, -1000, 0},
			{0, -400, 0},

			{20, -50, 0}, // exiting pit
			{100, 300, 100},
			{-250, 200, 0},

			{100, 120, 30}, // first swoop
			{200, 100, 0},
			{150, 100, -150},

			{0, 80, -50}, // second swoop
			{10, 150, 100},
			{100, 300, 500},

			{0, 0, 0}, // returning to pit
			{0, -800, 0},
			{0, -1000, 0}
		};

		ofxAssimpModelLoader scene_flesh4;
		ofTexture flesh4_texture;
		ofxAssimpModelLoader scene_eye;
		ofTexture eye_texture;
		ofxAssimpModelLoader scene_flesh3;
		ofTexture flesh3_texture;
		ofxAssimpModelLoader scene_bone1;
		ofTexture bone1_texture;

		ofLight light;
		ofLight light1;
		ofLight light2;

		MyCamera cam;

		vector<Centipede*> beetles;

		ofSoundPlayer ambient_sound;
};
