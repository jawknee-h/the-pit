#include "TailSegment.h"

/// Constructor.
TailSegment::TailSegment(float size) : Segment(size)
{
	cout << "tailsegment: constructed" << endl;

	// Setting up the model.
	tail.loadModel("isopod/isopod_head.dae");
	tail.setScale(size, size, -size);
	tail.setScaleNormalization(false);

	legs.loadModel("isopod/isopod_legs.dae");
	legs.setScale(size, size, size);
	legs.setScaleNormalization(false);

	// Initializing position.
	position = { 0, 0, 0 };
}

void TailSegment::draw()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();
	tail.drawFaces();
	legs.drawFaces();
	body_cone.restoreTransformGL();
}

void TailSegment::draw_wireframe()
{
	// Drawing the model with the orientation of the body_cone.
	body_cone.transformGL();
	tail.drawWireframe();
	legs.drawWireframe();
	body_cone.restoreTransformGL();
}