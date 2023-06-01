#include "Centipede.h"

/// Constructor.
Centipede::Centipede(int _move_speed, int _segment_spacing, int _num_of_segments, float _segment_size, float _start_time)
{
	cout << "centipede: constructed" << endl;

	// Initializing variables.
	start_time = _start_time;
	t = 9999;
	move_speed = _move_speed;
	segment_spacing = _segment_spacing;
	num_of_segments = _num_of_segments;
	segment_size = _segment_size;

	// Creating the body of the centipede.
	for (int i = 0; i < num_of_segments; i++)
	{
		// Creating a head as the first segment..
		if (i == 0)
		{
			HeadSegment* hs = new HeadSegment{segment_size};
			body.push_back(hs);
		}
		// Creating a tail as the last segment..
		else if (i == num_of_segments-1)
		{
			TailSegment* ts = new TailSegment{ segment_size };
			body.push_back(ts);
		}
		// Creating a torso for the rest of the segments.
		else
		{
			TorsoSegment* ts = new TorsoSegment{segment_size};
			body.push_back(ts);
		}
	}
}

// Destructor to clean up after ourselves
// helps to prevent memory leak
Centipede::~Centipede()
{
	cout << "Centipede(): destroying all the segments" << endl;

	for (Segment* s : body)
	{
		delete s; // give the memory back!
	}
}

void Centipede::update()
{
	// Moving all of the segments of the body.
	for (int i = 0; i < body.size(); i++)
	{
		// Finding the new position to move to as a base.
		ofVec3f new_pos = spline.getPointAtLength(t - (i * segment_spacing));

		// Adding the wave-like motion to the base position using sine
		// - Calculating an offset and adding it to the y of the position
		float frequency = float(segment_spacing) / 100;
		float amplitude = 90;
		float animation_speed = 0.01;
		float offset = t * animation_speed;

		float y_offset = amplitude * sin(i * frequency - offset);

		new_pos = {
			new_pos.x,
			new_pos.y + y_offset,
			new_pos.z
		};

		// Applying the movement.
		body[i]->move(new_pos);

		// Moving the legs
		//oscillate_legs(40, 40, 40, 0.02, i);
		oscillate_legs(body[i], 40, 40, 40, 0.02, i);
	}

	t += move_speed * ofGetLastFrameTime();
}

/// Move legs:
/// segment  =  pointer to the Segment which you want to rotate the legs for
/// amt_x  =  maxmimum degrees to rotate on x axis
/// amt_y  =  maximum degrees to rotate on y axis
/// amt_z  =  maximum degrees to rotate on z axis
/// wiggle_speed  =  how fast to oscillate
/// offset  =  the offset for the sine function. Allows different legs to be out of phase
void Centipede::oscillate_legs(Segment* segment, float amt_x, float amt_y, float amt_z, float wiggle_speed, int offset)
{
	// Calculating rotation for each axis
	float z_rotation_deg = ofMap(
		sin((ofGetElapsedTimeMillis() * wiggle_speed) + offset),
		-1, 1,
		-amt_z, amt_z
	);
	float y_rotation_deg = ofMap(
		sin((1326 + ofGetElapsedTimeMillis() * wiggle_speed) + offset),
		-1, 1,
		-amt_y, amt_y
	);
	float x_rotation_deg = ofMap(
		sin((1326 + ofGetElapsedTimeMillis() * wiggle_speed) + offset),
		-1, 1,
		-amt_x, amt_x
	);
	
	// Applying rotation
	segment->rotate_legs(z_rotation_deg, { 0, 0, 1 });
	segment->rotate_legs(y_rotation_deg, { 0, 1, 0 });
	segment->rotate_legs(x_rotation_deg, { 1, 0, 0 });
}

void Centipede::draw()
{
	// Drawing all the body segments.
	for (int i = 0; i < body.size(); i++)
	{
		body[i]->draw();
	}
}

void Centipede::draw_wireframe()
{
	// Drawing all the body segments.
	for (int i = 0; i < body.size(); i++)
	{
		body[i]->draw_wireframe();
	}
}

/// Generating a random path, which will stay within the bounds of the scene
/// num_points  ==  how many points should be added to the path
/// return_to_pit  ==  whether the path should lead back into the pit at the end
void Centipede::randomize_path(int num_points, bool return_to_pit)
{
	// Clearing the path before adding anything new.
	spline.clear();

	// A few points at the start so that the path will always come out of the pit.
	spline.curveTo(0, -1000, 0);
	spline.curveTo(0, -400, 0);
	spline.curveTo(0, 0, 0);

	// Generating random points which will remain inside the bounds of the
	// bowl shaped scene. Dynamically changing the range of possible x and z values
	// based on the y value generated. Put simply, points with a lower y
	// will have a smaller range for x and z values and points with
	// a higher y will have a wider range for x and z values because
	// the bowl gets wider at the top so there is more space.
	for (int i = 0; i < num_points; i++)
	{
		const float y = ofRandom(200, 500);
		const float range = ofMap(
			y,
			200, 500, // vertical range
			200, 500 // horizontal range
		);
		const float x = ofRandom(-range, range);
		const float z = ofRandom(-range, range);

		// Adding the point to the spline.
		spline.curveTo({x, y, z});
	}

	// Adding points to the path which lead back into the pit
	if (return_to_pit)
	{
		spline.curveTo(0, 0, 0);
		spline.curveTo(0, -400, 0);
		spline.curveTo(0, -1000, 0);
	}
	// Adding a point to the path which is high up in the sky, offscreen.
	else
	{
		spline.curveTo({ 0, 500, 0 });
	}
	
	// Smoothing the path.
	const float smoothShape = 1;
	const int smoothSize = 500;
	spline = spline.getSmoothed(smoothShape, smoothSize);

	// Resetting the playhead back to the start of the path.
	t = start_time;
}

/// Manually set the points in the spline path.
void Centipede::set_path(vector<ofPoint> points)
{
	// Clearing the path to begin with
	spline.clear();

	// Adding the points passed in to the path.
	for (int i = 0; i < points.size(); i++)
	{
		spline.curveTo(points[i]);
	}

	// Smoothing the path.
	spline = spline = spline.getSmoothed(1, 500);

	// Resetting the playhead back to the start of the path.
	t = start_time;
}

/// Return the current position of the head of the centipede (the first segment).
ofVec3f Centipede::get_head_pos()
{
	return body[0]->get_position();
}

/// Return how far the head of the centipede currently is along the path.
float Centipede::get_length_along_path()
{
	return t;
}

/// Return the total length of the path.
float Centipede::get_total_path_length()
{
	return spline.getLengthAtIndex(spline.size()-1);
}

/// Draw the spline path.
void Centipede::draw_path_debug()
{
	spline.draw();
}