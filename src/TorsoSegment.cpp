#include "TorsoSegment.h"

//--------------------------------------------------------------
TorsoSegment::TorsoSegment(float size) : Segment(size)
{
	cout << "TorsoSegment::TorsoSegment(): Constructed" << endl;

	// Setting up the models.
	body.loadModel("isopod/isopod_body.dae");
	body.setScale(size, size, size);
	body.setScaleNormalization(false);

	legs.loadModel("isopod/isopod_legs.dae");
	legs.setScale(size, size, size);
	legs.setScaleNormalization(false);

	// Setting up the material.
	ofLoadImage(body_texture, "scene/images/bone_image.png");
	body_material.setDiffuseColor(ofFloatColor(1.0, 0.0, 0.0));
	body_material.setEmissiveColor(ofFloatColor(1.0, 0.0, 0.0));
	body_material.setShininess(0);
	body_material.setAmbientColor(ofFloatColor(1.0, 1.0, 1.0));

	// Initializing position.
	position = { 0, 0, 0 };
}

//--------------------------------------------------------------
void TorsoSegment::update()
{
}

//--------------------------------------------------------------
void TorsoSegment::draw()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();
		body.drawFaces();
		legs.drawFaces();
	body_cone.restoreTransformGL();
}

//--------------------------------------------------------------
void TorsoSegment::draw_wireframe()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();

	body.drawWireframe();

	legs.drawWireframe();

	body_cone.restoreTransformGL();
}