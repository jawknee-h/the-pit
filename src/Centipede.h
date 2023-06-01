#pragma once

#include "ofMain.h"
#include "Segment.h"
#include "TorsoSegment.h"
#include "HeadSegment.h"
#include "TailSegment.h"

class Centipede
{
	public:
		void update();
		void draw();
		void draw_wireframe();

		void randomize_path(int num_points, bool return_to_pit);
		void set_path(vector<ofPoint> points);
		float get_length_along_path();
		float get_total_path_length();
		void draw_path_debug();

		ofVec3f get_head_pos();

		void oscillate_legs(Segment *segment, float amt_x, float amt_y, float amt_z, float wiggle_speed, int offset);

		Centipede(int _move_speed, int _segment_spacing, int _num_of_segments, float _segment_size, float _start_time);
		~Centipede();

	private:
		ofPolyline spline;

		float t;
		float move_speed;
		int segment_spacing;
		int num_of_segments;
		float segment_size;
		float start_time;
		
		vector<Segment*> body;
};