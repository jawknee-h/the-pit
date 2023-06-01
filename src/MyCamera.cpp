#include "MyCamera.h"

//--------------------------------------------------------------
MyCamera::MyCamera()
{
	cout << "MyCamera() constructed" << endl;
}

//--------------------------------------------------------------
// Smoothly look at target
//	- targ_pos  =  the position to look at
//	- pct  =  how much closer to the target position to go each frame
//	- x  =  whether to track the x position
//	- y  =  whether to track the y position
//	- z  =  whether to track the z position
//--------------------------------------------------------------
void MyCamera::smooth_lookat(ofPoint targ_pos, float pct, bool x, bool y, bool z)
{
	// Lerping towards the target position on each axis, if enabled.
	if (x)
	{
		looking_at.x = ofLerp(looking_at.x, targ_pos.x, pct);
	}
	if (y)
	{
		looking_at.y = ofLerp(looking_at.y, targ_pos.y, pct);
	}
	if (z)
	{
		looking_at.z = ofLerp(looking_at.z, targ_pos.z, pct);
	}
	
	// Applying.
	lookAt(looking_at);
}

//--------------------------------------------------------------
void MyCamera::update()
{
	// Always shaking at shake_speed, by shake_intensity.
	shake_t += ofGetLastFrameTime() * shake_speed;

	shake_intensity = ofLerp(shake_intensity, target_shake_intensity, shake_ramp);

	float x_offset = ofMap(ofNoise(shake_t), 0, 1, -shake_intensity, shake_intensity);
	float y_offset = ofMap(ofNoise(shake_t + 12.32), 0, 1, -shake_intensity, shake_intensity);
	float z_offset = ofMap(ofNoise(shake_t + 4.11), 0, 1, -shake_intensity, shake_intensity);

	rollDeg(z_offset);
	tiltDeg(x_offset);
	panDeg(y_offset);
}

//--------------------------------------------------------------
// Start shaking the camera at the passed in values
//  - _intensity  =  the maximum number of degrees the camera can be rotated by per frame
// - _shake_speed  =  how quickly to shake the camera
// - _transititon_rate  =  how quickly to ease into the shaking
//--------------------------------------------------------------
void MyCamera::start_shaking(float _intensity, float _shake_speed, float _transition_rate)
{
	target_shake_intensity = _intensity;
	shake_speed = _shake_speed;
	shake_ramp = _transition_rate;
}

//--------------------------------------------------------------
// Stop shaking the camera
//  - _transititon_rate  =  how quickly to stop the shaking - 1 will stop it instantly.
//--------------------------------------------------------------
void MyCamera::stop_shaking(float _transition_rate)
{
	target_shake_intensity = 0;
	shake_ramp = _transition_rate;
}

//--------------------------------------------------------------
MyCamera::~MyCamera()
{
	cout << "MyCamera() destructed" << endl;
}