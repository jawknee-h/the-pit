#pragma once

#include "ofMain.h"

class MyCamera : public ofEasyCam
{
	public:
		MyCamera();
		~MyCamera();

		void update();

		// camera movement
		void smooth_lookat(ofPoint targ_pos, float pct, bool x, bool y, bool z);

		// camera shake
		void start_shaking(float _intensity, float _shake_speed, float _transititon_rate);
		void stop_shaking(float _transition_rate);

	protected:
		ofVec3f looking_at;

		// camera shake
		float shake_t = 0; // the value being passed into the noise func
		float shake_intensity = 0;
		float shake_speed;
		float target_shake_intensity;
		float shake_ramp; // how quickly it eases in or out




	private:
};