#define _CRT_SECURE_NO_WARNINGS

//This program uses the write and read functions.
#include <iostream>

using namespace std;

struct imu_info {
	uint64_t time;	//微秒
	float z_angvel;

	//for debug
	float yaw;
	float pitch;
	float roll;
	uint64_t eslam_time_ms;
	uint64_t hoslam_time_ms;
	int32_t l_enc, r_enc;
	int16_t acc_data[3];
};

//struct imu_info {
//	uint64_t time;	//微秒
//	float z_angvel;
//
//	//for debug
//	float yaw;
//	uint64_t eslam_time_ms;
//	uint64_t hoslam_time_ms;
//	int32_t l_enc, r_enc;
//	int16_t acc_data[6];
//};

int get_imu_data()
{
	const int data_num = 20000;

	FILE* data_file;
	if ((data_file = fopen("20210129-030135.imuex2", "rb+")) == NULL)
	{
		cout << "open error! " << endl;
	}

	//
	FILE *fpWrite1 = fopen("slip_data_0129_3.txt", "w");
	if (fpWrite1 == NULL)
	{
		return 0;
	}

	imu_info *data;

	data = new imu_info[data_num];

	fread(data, sizeof(imu_info), data_num, data_file);

	for (int i = 0; i < data_num; i++)
	{
		/*cout << i << endl;
		cout << data[i].time << endl;
		cout << data[i].angle << endl;
		cout << data[i].l_enc << endl;
		cout << data[i].r_enc << endl;
		cout << data[i].original_data[3] << endl;
		cout << data[i].original_data[4] << endl;
		cout << data[i].original_data[5] << endl;*/

		fprintf(fpWrite1, "%I64u %f %f %f %d %d %hd %hd %hd\n",
			data[i].time,
			data[i].yaw * 3.1415926 / 180,
			data[i].pitch * 3.1415926 / 180,
			data[i].roll * 3.1415926 / 180,
			data[i].l_enc,
			data[i].r_enc,
			data[i].acc_data[0],
			data[i].acc_data[1],
			data[i].acc_data[2]
		);
	}

	delete[] data;

	fclose(data_file);
	fclose(fpWrite1);

	return 0;
}