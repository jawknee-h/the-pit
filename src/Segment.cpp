#include "Segment.h"

/// Constructor.
Segment::Segment(float size)
{
	cout << "segment: constructed" << endl;

	// Setting up the body.
	// This is a debug shape which inherits from ofNode
	// and handles all of the orientation.
	body_cone.set(20, 50);
	body_cone.setResolutionRadius(3);

	// Initializing position.
	position = { 0, 0, 0 };

	// Initializing scale.
	scale_factor = size;
}

void Segment::move(ofVec3f new_pos)
{
	// Updating position variables.
	previous_position = position;
	position = new_pos;

	// Positioning and orienting the body.
	body_cone.lookAt(position, { 0, -1, 0 });
	body_cone.setPosition({ position.x, position.y, position.z });
}

void Segment::update()
{

}

void Segment::draw()
{
	body_cone.drawFaces();
}

void Segment::draw_wireframe()
{
	// nothing.
}

ofVec3f Segment::get_position()
{
	return position;
}

/// Rotates the legs:
///	amt = num of degrees to rotate
/// axis = axis to rotate around
void Segment::rotate_legs(float amt, ofVec3f axis)
{
	legs.setRotation(0, amt, axis.x, axis.y, axis.z);
}

Segment::~Segment()
{
	cout << "Segment() destructed" << endl;
}