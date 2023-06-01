#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class Segment
{
	public:
		Segment(float size);
		~Segment();

		void move(ofVec3f position);
		virtual void draw();
		virtual void draw_wireframe();
		virtual void update();
		virtual void rotate_legs(float amt, ofVec3f axis);
		ofVec3f get_position();

	protected:
		ofConePrimitive body_cone;
		ofxAssimpModelLoader legs;

		ofVec3f position;
		ofVec3f previous_position;
		float scale_factor;
};