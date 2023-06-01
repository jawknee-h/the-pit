#pragma once

#include "ofMain.h"
#include "Segment.h"

class HeadSegment : public Segment
{
	public:
		HeadSegment(float size);
		void draw() override;
		void draw_wireframe() override;

	private:
		ofxAssimpModelLoader head;
};