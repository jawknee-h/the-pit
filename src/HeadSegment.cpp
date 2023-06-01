#include "HeadSegment.h"

//--------------------------------------------------------------
HeadSegment::HeadSegment(float size) : Segment(size)
{
	cout << "HeadSegment::HeadSegment(): Constructed" << endl;

	// Setting up the models.
	head.loadModel("isopod/isopod_head.dae");
	head.setScale(size, size, size);
	head.setScaleNormalization(false);

	legs.loadModel("isopod/isopod_legs.dae");
	legs.setScale(size, size, size);
	legs.setScaleNormalization(false);

	// Initializing position.
	position = { 0, 0, 0 };
}

//--------------------------------------------------------------
void HeadSegment::draw()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();
		head.drawFaces();
		legs.drawFaces();
	body_cone.restoreTransformGL();
}

//--------------------------------------------------------------
void HeadSegment::draw_wireframe()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();
		head.drawWireframe();
		legs.drawWireframe();
	body_cone.restoreTransformGL();
}