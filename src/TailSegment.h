#pragma once

#include "ofMain.h"
#include "Segment.h"

class TailSegment : public Segment
{
	public:
		TailSegment(float size);
		void draw() override;
		void draw_wireframe() override;

	private:
		ofxAssimpModelLoader tail;
};