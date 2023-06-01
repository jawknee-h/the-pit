#pragma once

#include "ofMain.h"
#include "Segment.h"

class TorsoSegment : public Segment
{
	public:
		TorsoSegment(float size);
		void update() override;
		void draw() override;
		void draw_wireframe() override;

	private:
		ofxAssimpModelLoader body;
		ofTexture body_texture;
		ofMaterial body_material;
};