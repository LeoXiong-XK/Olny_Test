#ifndef __MAIN_H__
#define __MAIN_H__
#pragma once


struct rangedata
{
	bool flag;
	float angle;
	unsigned int dist;
	unsigned int speed;
	rangedata() :
		flag(false),
		angle(0.),
		dist(0),
		speed(0) {}
};
class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		std::vector<int> number;
		for (int i = 0; i < nums.size(); i++) {
			for (std::vector<int>::const_iterator j = nums.begin() + 1; j != nums.end(); j++) {
				if (nums[i] == *j) {
					j = nums.erase(j);
				}
				else {

					j++;
				}
			}
			number.push_back(nums[i]);
		}
		return number.size();
	}
};
typedef struct {
	float lens_sum;
	int id;
	float theta;
}weighted_line_info_t;
typedef struct {
	uint16_t head_flag;
	uint32_t frame_payload;
	uint32_t frame_id;
	uint32_t request_frame_id;
	uint16_t msg_id;
	uint32_t total_size;
	uint32_t frame_position;
	uint32_t ack;
}frame_head_t;
typedef struct {
	uint32_t timstamps;
	float gyroVal;
	uint16_t odomLEncoder;
	uint16_t odomREncoder;
	uint16_t bumpMask;
	int16_t tof;
}vrepSensorFrame_t;
typedef struct{
	uint8_t BGR_B;
	uint8_t BGR_G;
	uint8_t BGR_R;
}cv_color_mode_t;
#endif //__MAIN_H__