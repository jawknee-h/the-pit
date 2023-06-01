#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Setting up models.
	scene_flesh4.loadModel("scene/models/scene_flesh42.obj");
	scene_flesh3.loadModel("scene/models/scene_flesh3.obj");
	scene_eye.loadModel("scene/models/scene_eye2.obj");
	scene_bone1.loadModel("scene/models/scene_bone12.obj");

	scene_flesh4.setScale(10, 10, 10);
	scene_flesh3.setScale(10, 10, 10);
	scene_eye.setScale(10, 10, 10);
	scene_bone1.setScale(10, 10, 10);

	// Disabling normalized scale so that models are actually the scale I EXPORTED THEM AS....
	scene_flesh4.setScaleNormalization(false);
	scene_flesh3.setScaleNormalization(false);
	scene_eye.setScaleNormalization(false);
	scene_bone1.setScaleNormalization(false);

	// Loading textures.
	ofDisableArbTex();
	ofLoadImage(flesh4_texture, "scene/images/flesh_image_light.jpg");
	ofLoadImage(flesh3_texture, "scene/images/flesh_image_dark.jpg");
	ofLoadImage(eye_texture, "scene/images/eye_image.jpg");
	ofLoadImage(bone1_texture, "scene/images/bone_image.png");

	// Enabling tiling.
	flesh4_texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
	flesh3_texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
	eye_texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
	bone1_texture.setTextureWrap(GL_REPEAT, GL_REPEAT);

	// Setting up lights
	light.setPointLight();
	light.setDiffuseColor(ofFloatColor(0.46, 0.4, 0.46));
	light.setPosition({ 2, 843, 0 });

	light2.setPointLight();
	light2.setDiffuseColor({ 1.0, 1.0, 1.0 });
	light2.setSpecularColor({ 1.0, 1.0, 1.0 });
	light2.setPosition({ 107, 468, 109 });

	light1.setPointLight();
	light1.setDiffuseColor(ofFloatColor(0.18, 0.12, 0.124));
	light1.setPosition({ 500, 700, 500 });

	// Setting up camera
	cam.setPosition({ 236.54, 147.29, -28.79 });
	cam.setTarget({ 0, 0, 0 });
	cam.setFov(60);

	// Creating the small beetles
	const int NUM_BEETLES = 15;
	for (int i = 0; i < NUM_BEETLES; i++)
	{
		const int speed = ofRandom(500, 200);
		const int segments = ofRandom(3, 5);
		const int spacing = segments / 3;
		const int size = ofRandom(1, 1.2);
		const int start_time = ofRandom(0, 200);

		Centipede* b = new Centipede(speed, spacing, segments, size, start_time);
		beetles.push_back(b);
	}

	// Loading ambient background sound
	if (!ambient_sound.load("audio/bell.wav")) cout << "sound failed to load" << endl;
	ambient_sound.play();
	ambient_sound.setLoop(true);

	string credits_message = R"(
      .:;¦\¯`¯'¯'\\    ’¦\¯¯``¯;\\  ____     ’             .:;¦\¯`'¯`’¯\ 
      .:;¦;\',_, .:;\;  ’¦;\_,     ',\¯`' ¯`'\\'   ’;/¯`'¯`'¯/¦.:;'¦;¦ -   --:;¦'
      .:;¦ .;\\¯` .:;'\ ’¦:;¦¦¯`  .:;'¦'\       ',\  '¦   -  .:;¦;'¦/¯\/    -.:;'/¦'
¦\ ¯¯¯¯\.:;'¦;      ';¦''\;/     .:;'/_;\,      ,\ ¦\   -  -:;\/;/\_____/:;¦
¦:;\ ____\/_____/¦';/_____/ ¯¯'¦;      ;¦'¦:;\_____/:;¦¦¯`'¯`'¦¦:;'¦
¦.:;¦¦¯`'`':;¦¦¯`'¯¯`'¦;¦';'¦¦¯`'¯`'¦¦  .:;/____;/¦¦:;'¦¦¯`'¯`'¦¦.:;¦;      ;¦;'/'
;\:;¦      ;’¦;       ;¦;¦';¦:     ';¦ .:;'¦¦¯`'¯`'¦¦;'¦;\;'¦;      ;¦;/\¦L_ .:;'¦/’ 
.:;\¦L_   ;'¦L_  .:;¦/'';'¦L_   .'¦¯¯;¦;      ;¦;¦:;'\¦L_ .:;'¦/'       ¯     
         ¯¯     ¯¯   ’ ’    ¯¯   .:;¦L_ .:;'¦/          ¯¯               ’
                        ’                    ¯¯  '’                           ’'
;¦\\¯`¯'¯'\\:;¦¯`'¯`'¯¦    .:;¦\¯`'¯``\.:;'¦\¯`’¯`’\ ,'¯`'¯`'¯/'¦¯`'¯`'¯'¦' ,'¯`'¯`'¯/'¦¯`'¯`'¯'¦' 
;¦:;\',_, .:;\/    - :;'/¦   '.:;¦;¦ -  -.:;\;'¦;¦  - .:;’¦¦;_,    ;¦;¦_____¦' ¦;_,    ;¦;¦_____¦' 
;¦ .:;\\¯` .:;'      -  ¯\  .:;¦/   -:;''/\:;\/ -  -:;'/¦¦\¯`      '¯_\ ::::’¦ ¦\¯`      '¯_\ ::::’¦ 
;'\ .:;'¦;      ';¦\  -  - :;\’:;'/  - -;’/.:;\ -  - .:;/;¦;\     .:;'\.:;¦¯¯`’¯¦;\     .:;'\.:;¦¯¯`’¯¦
 .:;\;/_____/¦;¦_____¦'/____/  .:;'¦____/:;'¦:;\_____\/____/'¦:;\_____\/____/'¦
  .:;'¦¦¯`'¯¯`;¦'¦;¦¦¯`'¯`''¦¦¦¦¯`'.:;¦.:;/\;'¦¦¯`':;¦.:;/'\ :'¦¦¯`'¯`'¯`'¯¯`'¦¦;¦\ :'¦¦¯`'¯`'¯`'¯¯`'¦¦;¦
  .:;'¦;       ;'¦'¦;¦;    .:;'¦;   .:;¦;'/.:;\¦;  .:;¦;'’/  ;'\'’¦;              ;¦;¦;'\'’¦;              ;¦;¦
  .:;’¦L_  .:;;¦/;¦L_  .:;¦¦L_.:;'¦/  .:;'¦L_:;'¦/   '.:;\¦L_           ;'¦/'.:;\¦L_           ;'¦/'
          ¯¯¯         ¯¯       ¯            ¯     '          ¯¯¯¯¯¯  '          ¯¯¯¯¯¯  '

     the_pit.cpp
                                                                 
         ,,    
       ' ||    
      \\ ||/\\
      || || || 
      || || || 
      || \\ |/ 
      |;   _/  
      /     

      jawknee.h
 c++ && openframeworks
)";
	cout << credits_message << endl;

	ofSystemAlertDialog("Press SPACEBAR to play or restart the scene!! :)");
	reset_scene();
}

//--------------------------------------------------------------
void ofApp::update()
{
	// Updating the centipede and all beetles
	centipede_1.update();

	for (Centipede* b : beetles)
	{
		b->update();
	}

	manage_events(centipede_1.get_length_along_path());

	// Updating and moving camera.
	cam.update();
	cam.setFov(cam.getFov() + 2 * ofGetLastFrameTime()); // increasing FOV gradually
	cam.dolly( -7 * ofGetLastFrameTime());
	cam.boom(-1 * ofGetLastFrameTime());
	cam.rollDeg(0.8 * ofGetLastFrameTime());


	float spe = 0.002;
	light.setPosition({
		0,
		ofMap(cos(ofGetElapsedTimeMillis() * spe), -1, 1, -100, 100),
		ofMap(sin(ofGetElapsedTimeMillis() * spe), -1, 1, -100, 100)
		});
	light.setAmbientColor({1.0, 1.0, 1.0});
	light.setDiffuseColor({ 0.08, 0.0, 0.01 });
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofEnableDepthTest();
	ofEnableLighting();
	cam.begin();

		// Drawing the scene.
		light.enable();
		light2.enable();
			draw_scene();
		light2.disable();
		light.disable();

		// Drawing the creatures.
		light1.enable();
			draw_creatures();
		light1.disable();

	cam.end();
	ofDisableLighting();
	ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	reset_scene();
}

//--------------------------------------------------------------
void ofApp::draw_creatures()
{
	centipede_1.draw_wireframe();

	for (Centipede* b : beetles)
	{
		b->draw();
	}
}

//--------------------------------------------------------------
// Draw the terrain in the scene.
//--------------------------------------------------------------
void ofApp::draw_scene()
{
	flesh4_texture.bind();
		scene_flesh4.drawFaces();
	flesh4_texture.unbind();

	eye_texture.bind();
		scene_eye.drawFaces();
	eye_texture.unbind();

	flesh3_texture.bind();
		scene_flesh3.drawFaces();
	flesh3_texture.unbind();

	bone1_texture.bind();
		scene_bone1.drawFaces();
	bone1_texture.unbind();
}

//--------------------------------------------------------------
void ofApp::draw_scene_wireframe()
{
	scene_flesh4.drawWireframe();

	scene_eye.drawWireframe();

	scene_flesh3.drawWireframe();

	scene_bone1.drawWireframe();
}

//--------------------------------------------------------------
// Resets everything so that it starts again in sync.
//--------------------------------------------------------------
void ofApp::reset_scene()
{
	// Resetting the paths of the creatures.
	centipede_1.set_path(centipede_path);

	for (Centipede* b : beetles)
	{
		b->randomize_path(2, false);
	}

	// Resetting the camera settings.
	cam.stop_shaking(1);
	cam.setPosition({ 236.54, 147.29, -28.79 });
	cam.setTarget({ 0, 0, 0 });
	cam.setFov(60);

	// restarting the sound from the beginning
	ambient_sound.setPosition(0.0);
}

//--------------------------------------------------------------
// Stop and start things like screenshake at given times,
// a bit like an animation player.
//--------------------------------------------------------------
void ofApp::manage_events(float current_frame)
{
	const int tolerance = 10;

	const int keyframe_0 = -790; // light tremors as small worms spawn
	const int keyframe_1 = 270; // large tremors as centipede exits pit
	const int keyframe_2 = 1180; // smaller tremors once centipede has exited the pit
	const int keyframe_3 = 1474; // large tremors as centipede swoops past camera
	const int keyframe_4 = 2384; // smaller tremors once centipede has passed
	const int keyframe_5 = centipede_1.get_total_path_length() - 752; // large tremors as centipede re-enters pit
	const int keyframe_6 = centipede_1.get_total_path_length() + 69; // tremors fade once centipede has burrowed

	// if the current length along path is close enough to the keyframe..
	if (current_frame > keyframe_0 && current_frame  < keyframe_0 + tolerance)
	{
		//cout << "KEYFRAME 0" << endl;
		cam.start_shaking(0.3, 20, 0.01);
	}
	else if (current_frame > keyframe_1 && current_frame < keyframe_1 + tolerance)
	{
		//cout << "KEYFRAME 1" << endl;
		cam.start_shaking(0.7, 20, 0.1);
	}
	else if (current_frame > keyframe_2 && current_frame < keyframe_2 + tolerance)
	{
		//cout << "KEYFRAME 2" << endl;
		cam.start_shaking(0.1, 20, 0.15);
	}
	else if (current_frame > keyframe_3 && current_frame < keyframe_3 + tolerance)
	{
		//cout << "KEYFRAME 3" << endl;
		cam.start_shaking(1.0, 20, 0.2);
	}
	else if (current_frame > keyframe_4 && current_frame < keyframe_4 + tolerance)
	{
		//cout << "KEYFRAME 4" << endl;
		cam.start_shaking(0.2, 20, 0.07);
	}
	else if ((current_frame > keyframe_5 && current_frame < keyframe_5 + tolerance))
	{
		//cout << "KEYFRAME 5" << endl;
		cam.start_shaking(0.8, 20, 0.2);
	}
	else if (abs(current_frame - keyframe_6) < tolerance)
	{
		//cout << "KEYFRAME 6" << endl;
		cam.stop_shaking(0.01);
	}
}