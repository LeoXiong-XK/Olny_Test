﻿#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "main.h"
#include<algorithm>
#include<Windows.h>
#include "auxiliary_func.h"
#include <ctype.h>

using namespace std;
#define BUF_LEN 723
int SendDataPacket(const void *dist_pack, const void *angle_pack, unsigned int packetsize) {

	uint8_t pkt_header[2];
	uint8_t wait_send_buf[32];
	uint8_t checksum = 0;
	pkt_header[0] = 0x55;
	pkt_header[1] = 0xaa;
	//serial.write(pkt_header, 2);
	for (int i = 0; i < 8; ++i) {
		wait_send_buf[i * 4] = (*((uint16_t*)dist_pack + i))&0xff;
		wait_send_buf[i*4+1] = ((*((uint16_t*)dist_pack + i)) & 0xff00)>>8;
		wait_send_buf[i * 4 + 2] = (*((uint16_t*)angle_pack + i)) & 0xff;
		wait_send_buf[i * 4 + 3] = ((*((uint16_t*)angle_pack + i )) & 0xff00)>>8;
	}
	for (int i = 0; i < sizeof(wait_send_buf);i++) {
		printf("wait_data:0x%x\n",wait_send_buf[i]);
	}
	//serial.write(wait_send_buf, packetsize * 2);
	for (size_t pos = 0; pos < sizeof(wait_send_buf); ++pos) {
		checksum ^= wait_send_buf[pos];
	}
	//std::cout << "SendDataPacket finished!" << std::endl;
	return 0;
}
uint64_t timestamps = 0x14733;

void uint64_timestamp_convert(uint64_t time, uint8_t* result) {
	for (int i = 0; i < sizeof(uint64_t); ++i) {
		result[i] = (time >> (sizeof(uint64_t) * i)) & 0xff;
	}
}
uint8_t buf[723] = { 0x55,0xaa,01,0x02,0x02,0x03,0x03,0x04,0x04,0x05,0x05,0x06,0x06,0x07,0x07,0x08,0x08,0x09,0x09,0x0A,0x0A,0x0B,0x0B,0x0C,0x0C,0x0D,0x0D,0x0E,0x0E,0x0F,0x0F,0x10,0x10,0x11,0x11,0x12,0x12,0x13,0x13,0x14,0x14,0x15,0x15,0x16,0x16,0x17,0x17,0x18,0x18,0x19,0x19,0x1A,0x1A,0x1B,0x1B,0x1C,0x1C,0x1D,0x1D,0x1E,0x1E,0x1F,0x1F,0x20,0x20,0x21,0x21,0x22,0x22,0x23,0x23,0x24,0x24,0x25,0x25,0x26,0x26,0x27,0x27,0x28,0x28,0x29,0x29,0x2A,0x2A,0x2B,0x2B,0x2C,0x2C,0x2D,0x2D,0x2E,0x2E,0x2F,0x2F,0x30,0x30,0x31,0x31,0x32,0x32,0x33,0x33,0x34,0x34,0x35,0x35,0x36,0x36,0x37,0x37,0x38,0x38,0x39,0x39,0x3A,0x3A,0x3B,0x3B,0x3C,0x3C,0x3D,0x3D,0x3E,0x3E,0x3F,0x3F,0x40,0x40,0x41,0x41,0x42,0x42,0x43,0x43,0x44,0x44,0x45,0x45,0x46,0x46,0x47,0x47,0x48,0x48,0x49,0x49,0x4A,0x4A,0x4B,0x4B,0x4C,0x4C,0x4D,0x4D,0x4E,0x4E,0x4F,0x4F,0x50,0x50,0x51,0x51,0x52,0x52,0x53,0x53,0x54,0x54,0x55,0x55,0x56,0x56,0x57,0x57,0x58,0x58,0x59,0x59,0x5A,0x5A,0x5B,0x5B,0x5C,0x5C,0x5D,0x5D,0x5E,0x5E,0x5F,0x5F,0x60,0x60,0x61,0x61,0x62,0x62,0x63,0x63,0x64,0x64,0x65,0x65,0x66,0x66,0x67,0x67,0x68,0x68,0x69,0x69,0x6A,0x6A,0x6B,0x6B,0x6C,0x6C,0x6D,0x6D,0x6E,0x6E,0x6F,0x6F,0x70,0x70,0x71,0x71,0x72,0x72,0x73,0x73,0x74,0x74,0x75,0x75,0x76,0x76,0x77,0x77,0x78,0x78,0x79,0x79,0x7A,0x7A,0x7B,0x7B,0x7C,0x7C,0x7D,0x7D,0x7E,0x7E,0x7F,0x7F,0x80,0x80,0x81,0x81,0x82,0x82,0x83,0x83,0x84,0x84,0x85,0x85,0x86,0x86,0x87,0x87,0x88,0x88,0x89,0x89,0x8A,0x8A,0x8B,0x8B,0x8C,0x8C,0x8D,0x8D,0x8E,0x8E,0x8F,0x8F,0x90,0x90,0x91,0x91,0x92,0x92,0x93,0x93,0x94,0x94,0x95,0x95,0x96,0x96,0x97,0x97,0x98,0x98,0x99,0x99,0x9A,0x9A,0x9B,0x9B,0x9C,0x9C,0x9D,0x9D,0x9E,0x9E,0x9F,0x9F,0xA0,0xA0,0xA1,0xA1,0xA2,0xA2,0xA3,0xA3,0xA4,0xA4,0xA5,0xA5,0xA6,0xA6,0xA7,0xA7,0xA8,0xA8,0xA9,0xA9,0xAA,0xAA,0xAB,0xAB,0xAC,0xAC,0xAD,0xAD,0xAE,0xAE,0xAF,0xAF,0xB0,0xB0,0xB1,0xB1,0xB2,0xB2,0xB3,0xB3,0xB4,0xB4,0xB5,0xB5,0xB6,0xB6,0xB7,0xB7,0xB8,0xB8,0xB9,0xB9,0xBA,0xBA,0xBB,0xBB,0xBC,0xBC,0xBD,0xBD,0xBE,0xBE,0xBF,0xBF,0xC0,0xC0,0xC1,0xC1,0xC2,0xC2,0xC3,0xC3,0xC4,0xC4,0xC5,0xC5,0xC6,0xC6,0xC7,0xC7,0xC8,0xC8,0xC9,0xC9,0xCA,0xCA,0xCB,0xCB,0xCC,0xCC,0xCD,0xCD,0xCE,0xCE,0xCF,0xCF,0xD0,0xD0,0xD1,0xD1,0xD2,0xD2,0xD3,0xD3,0xD4,0xD4,0xD5,0xD5,0xD6,0xD6,0xD7,0xD7,0xD8,0xD8,0xD9,0xD9,0xDA,0xDA,0xDB,0xDB,0xDC,0xDC,0xDD,0xDD,0xDE,0xDE,0xDF,0xDF,0xE0,0xE0,0xE1,0xE1,0xE2,0xE2,0xE3,0xE3,0xE4,0xE4,0xE5,0xE5,0xE6,0xE6,0xE7,0xE7,0xE8,0xE8,0xE9,0xE9,0xEA,0xEA,0xEB,0xEB,0xEC,0xEC,0xED,0xED,0xEE,0xEE,0xEF,0xEF,0xF0,0xF0,0xF1,0xF1,0xF2,0xF2,0xF3,0xF3,0xF4,0xF4,0xF5,0xF5,0xF6,0xF6,0xF7,0xF7,0xF8,0xF8,0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,0xFC,0xFD,0xFD,0xFE,0xFE,0xFF,0xFF,0x00,0x00,0x01,0x01,0x02,0x02,0x03,0x03,0x04,0x04,0x05,0x05,0x06,0x06,0x07,0x07,0x08,0x08,0x09,0x09,0x0A,0x0A,0x0B,0x0B,0x0C,0x0C,0x0D,0x0D,0x0E,0x0E,0x0F,0x0F,0x10,0x10,0x11,0x11,0x12,0x12,0x13,0x13,0x14,0x14,0x15,0x15,0x16,0x16,0x17,0x17,0x18,0x18,0x19,0x19,0x1A,0x1A,0x1B,0x1B,0x1C,0x1C,0x1D,0x1D,0x1E,0x1E,0x1F,0x1F,0x20,0x20,0x21,0x21,0x22,0x22,0x23,0x23,0x24,0x24,0x25,0x25,0x26,0x26,0x27,0x27,0x28,0x28,0x29,0x29,0x2A,0x2A,0x2B,0x2B,0x2C,0x2C,0x2D,0x2D,0x2E,0x2E,0x2F,0x2F,0x30,0x30,0x31,0x31,0x32,0x32,0x33,0x33,0x34,0x34,0x35,0x35,0x36,0x36,0x37,0x37,0x38,0x38,0x39,0x39,0x3A,0x3A,0x3B,0x3B,0x3C,0x3C,0x3D,0x3D,0x3E,0x3E,0x3F,0x3F,0x40,0x40,0x41,0x41,0x42,0x42,0x43,0x43,0x44,0x44,0x45,0x45,0x46,0x46,0x47,0x47,0x48,0x48,0x49,0x49,0x4A,0x4A,0x4B,0x4B,0x4C,0x4C,0x4D,0x4D,0x4E,0x4E,0x4F,0x4F,0x50,0x50,0x51,0x51,0x52,0x52,0x53,0x53,0x54,0x54,0x55,0x55,0x56,0x56,0x57,0x57,0x58,0x58,0x59,0x59,0x5A,0x5A,0x5B,0x5B,0x5C,0x5C,0x5D,0x5D,0x5E,0x5E,0x5F,0x5F,0x60,0x60,0x61,0x61,0x62,0x62,0x63,0x63,0x64,0x64,0x65,0x65,0x66,0x66,0x67,0x67,0x68,0x68,0x69,0x68 };

uint8_t Check_sum(uint8_t* num) {
	uint8_t CRC_SUM = 0;
	for (int i = 2; i < BUF_LEN -1;++i) {
		printf("%d %x\n",i,num[i]);
		CRC_SUM ^= num[i];
	}
	return CRC_SUM;
}
static int st_buf[4] = {12,34,45,67};
#define UART_BUF_LEN ((sizeof(frame_head_t)+ sizeof(vrepSensorFrame_t)+2))
void BGR_Mode_Select(uint8_t id,cv_color_mode_t& color) {
	switch (id % 3) {
	case 0:
		color.BGR_B = 128;
		color.BGR_G = 0;
		color.BGR_R = 0;
		break;
	case 1:
		color.BGR_B = 0;
		color.BGR_G = 128;
		color.BGR_R = 0;
		break;
	case 2:
		color.BGR_B = 0;
		color.BGR_G = 0;
		color.BGR_R = 128;
		break;
	default:
		break;
	}
}
uint64_t get_test_value(uint64_t& start) {
	return start;
}
#if 0
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
struct student {
	char name[10];
	int score;
};
//自定义“小于”
bool comp(const student &a, const student &b) {
	return a.score < b.score;
}
int main() {
	vector<student> vectorStudents;
	int n = 5;
	while (n--) {
		student oneStudent;
		string name;
		int score;
		cout << "please enter name and score..." << endl;
		cin >> name >> score;
		strcpy(oneStudent.name, name.c_str());
		oneStudent.score = score;
		vectorStudents.push_back(oneStudent);
	}
	cout << "===========排序前================" << endl;
	for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++) {
		cout << "name: " << it->name << " score: " << it->score << endl;
	}
	sort(vectorStudents.begin(), vectorStudents.end(), comp);
	cout << "===========排序后================" << endl;
	for (vector<student>::iterator it = vectorStudents.begin(); it != vectorStudents.end(); it++) {
		cout << "name: " << it->name << " score: " << it->score << endl;
	}
	system("pause");
	return 0;
}
#else
#include <iostream>
#include <vector>
using namespace std;


// 重载一下+号运算符
template <typename T>
vector<T> &operator +(vector<T> &v1, vector<T> &v2)
{
	v1.insert(v1.end(), v2.begin(), v2.end());
	return v1;
}
//
/*
int main()
{
	int a1[] = { 1,2,3 }, a2[] = { 4,5,6 };
	vector<int> v1(a1, a1 + 3);
	vector<int> v2(a2, a2 + 3);
	vector<int> v3 = { 7,8,9 };
	// 方法一：insert() 函数
	v1.insert(v1.end(), v2.begin(), v2.end());
	v1.insert(v1.end(), v3.begin(), v3.end());

	// 方法二：重载一下+号运算符
	//v1=v1+v2+v3;

	// 方法三：copy()函数
	//int s=(int)v1.size();
	//v1.resize(s+v2.size());
	//copy(v2.begin(),v2.end(),v1.begin()+s);
	//int s2=(int)v1.size();
	//v1.resize(s2+v3.size());
	//copy(v3.begin(),v3.end(),v1.begin()+s2);

	// 显示
	for (int i = 0; i<v1.size(); i++)
	{
		cout << "v1=" << v1[i] << endl;
	}
	system("pause");
}
*/
/*
int main() {
	int a1[3] = { 1,2,3 }, a2[3] = { 4,5,6 }, a3[3] = { 7,8,9 }, a4[3] = {10,11,12};
	std::vector<int> vec1(a1,a1 + 3);
	std::vector<int> vec2(a2, a2 + 3);
	std::vector<int> vec3(a3, a3 + 3);
	std::vector<int> vec4(a4, a4 + 3);
	std::vector<std::vector<int>> test_vec1;
	std::vector<std::vector<int>> test_vec2;
	test_vec1.push_back(vec1);
	test_vec1.push_back(vec2);
	test_vec2.push_back(vec3);
	test_vec2.push_back(vec4);
	cout << "test_vec1 size=" << test_vec1.size() << " test_vec2 size=" << test_vec2.size()<<endl;
	test_vec1.insert(test_vec1.end(), test_vec2.begin(), test_vec2.end());
	cout << "test_vec1 size=" << test_vec1.size()<<endl;
	float b = 5.5455f;

	int c = 0;
	//int d = std::floor(b);
	float a = (float)std::floor(b);
	if (b - a >= 0.5f) {
		c = std::floor(b + 0.5f);
		cout << "小数部分大于：0.5" << endl;
	}
	else {
		c = std::floor(b);
		cout << "小数部分小于：0.5" << endl;
	}
	cout << "取整：" << c << endl;
	system("pause");

}*/
void test_debug(int &a, int &b) {
	a = 10;
	b = 2;
}
int main() {
	int a1[] = { 1,2,3 };
	static DWORD t2 = 0;
	double test_a = 4.50, test_b=7.80;
	uint8_t r = 0xf8;
	uint8_t buf[8] = {0};
	int valid_in_buf = 2;
	uint8_t *p = NULL;
	uint8_t rx_buf[520] = { 0 };

	while (1) {
		p = rx_buf;
		if (p == NULL) {
			printf("New buffer failed...\r\n");
		}
		double cd = max(test_a,test_b);
		printf("cd_max:%lf\r\n",cd);
		Sleep(100);
	}
	system("pause");
}
#endif