#include "Manager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

Manager::Manager() {
	cout << "管理器创建成功!" << endl;
	init();
}

void Manager::init() {
	PATH = "StudentScore.dat";
	cout << "初始化成功!" << endl;
}

int Manager::insert()
{
	//手动输入时使用
	string tmp;
	cout << "************开始读入学生成绩************" << endl;
	cout << "*                                      *" << endl;
	cout << "*    0:默认从StudentScore.dat读入。    *" << endl;
	cout << "*    1:从自定义路径读入。              *" << endl;
	cout << "*    2:手动输入。                      *" << endl;
	cout << "*                                      *" << endl;
	cout << "****************************************" << endl;
	int input = getinput(0,2);
	switch (input) {
	case 0:
		loadDataBase(PATH);
		break;
	case 1:
		cout << "请输入你的路径:" << endl;
		cin >> path;
		loadDataBase(path);
		break;
	case 2:
		cout << "输入课程名称：";
		cin >> tmp;
		info.class_name = tmp;
		cout << "输入课程编号";
		cin >> tmp;
		info.class_number = tmp;
		cout << "输入开课单位：：";
		cin >> tmp;
		info.class_host = tmp;
		cout << "输入授课教师：";
		cin >> tmp;
		info.class_teacher = tmp;
		cout << "按5输入学生信息。" << endl;
		break;
	default:
		break;
	}
	return 0;
}

int Manager::brouse()
{
	cout << head << endl;
	for (int i = 0; i < 8; i++) {
		cout<<setw(15)<<setfill(' ') << setiosflags(ios::left) << columns[i];
	}
	cout << "最终成绩";
	cout << endl;
	int j = 0;
	while (j < info.class_students) {
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << id[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << name[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << gender[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << class_name[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(16) << setfill(' ');
		cout << normal_work_score[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(16) << setfill(' ');
		cout << normal_experiment_score[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(16) << setfill(' ');
		cout << normal_report_score[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << test_score[j] ;
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << final_score[j] ;
		j++;
		cout << endl;
	}
	return 0;
}

int Manager::search()
{
	cout << "*************请输入查询方式*************" << endl;
	cout << "*                                      *" << endl;
	cout << "*            1:按学号查询              *" << endl;
	cout << "*            2:按姓名查询              *" << endl;
	cout << "*            3:按性别查询              *" << endl;
	cout << "*            4:按班级名称查询          *" << endl;
	cout << "*            5:按平时成绩（作业）查询  *" << endl;
	cout << "*            6:按平时成绩（实验）查询  *" << endl;
	cout << "*            7:按平时成绩（报告）查询  *" << endl;
	cout << "*            8:按考试成绩查询          *" << endl;
	cout << "*                                      *" << endl;
	cout << "****************************************" << endl;
	int input = getinput(1,8);
	switch (input) {
	case 1:
		findWith(id, info.class_students);
		break;
	case 2:
		findWith(name, info.class_students);
		break;
	case 3:
		findWith(gender, info.class_students);
		break;
	case 4:
		findWith(class_name, info.class_students);
		break;
	case 5:
		findWith(normal_work_score, info.class_students);
		break;
	case 6:
		findWith(normal_experiment_score, info.class_students);
		break;
	case 7:
		findWith(normal_report_score, info.class_students);
		break;
	case 8:
		findWith(test_score, info.class_students);
		break;
	}
	return 0;
}

int Manager::change()
{
	cout << "请输入需要修改的学生的学号：";
	int input = getinput(0,0);
	if (!findWith(input, id, info.class_students)) {
		return 0;
	};
	//cout << "可修改的选项为：\n" << "1:学号\n2:姓名\n3:性别\n4:班级名称\n5:平时成绩（作业）\n6:平时成绩（实验）\n7:平时成绩（报告）\n8:考试成绩\n" << "输入数字进行选择：";
	cout << "**************可修改的选项**************" << endl;
	cout << "*                                      *" << endl;
	cout << "*           1:学号                     *" << endl;
	cout << "*           2:姓名                     *" << endl;
	cout << "*           3:性别                     *" << endl;
	cout << "*           4:班级名称                 *" << endl;
	cout << "*           5:平时成绩（作业）         *" << endl;
	cout << "*           6:平时成绩（实验）         *" << endl;
	cout << "*           7:平时成绩（报告）         *" << endl;
	cout << "*           8:考试成绩                 *" << endl;
	cout << "*                                      *" << endl;
	cout << "****************************************" << endl;
	while (true)
	{
		int input = getinput(0,8);
		switch (input) {
		case 0:
			return 1;
		case 1:
			cout << "输入新的学号：";
			int new_id;
			new_id = getinput(0, 0);
			id[search_result[0] - 1] = new_id;
			break;
		case 2:
		{
			cout << "输入新的姓名：";
			string new_name;
			new_name = getstrinput();
			name[search_result[0] - 1] = new_name;
			break;
		}
		case 3:
			if (gender[search_result[0] - 1] == "男") {
				gender[search_result[0] - 1] = "女";
			}
			else {
				gender[search_result[0] - 1] = "男";
			}
			break;
		case 4:
		{
			cout << "输入新的班级：";
			string new_class;
			new_class =getinput(0,0);
			class_name[search_result[0] - 1] = new_class;
			break;
		}

		case 5: {
			cout << "输入新的平时成绩（作业）：";
			float new_score;
			new_score = getinput(0.0f,100.0f);
			normal_work_score[search_result[0] - 1] = new_score;
			break;
		}

		case 6: {
			cout << "输入新的平时成绩（实验）：";
			float new_score;
			new_score = getinput(0.0f, 100.0f);;
			normal_experiment_score[search_result[0] - 1] = new_score;
			break;
		}

		case 7: {
			cout << "输入新的平时成绩（报告）：";
			float new_score;
			new_score = getinput(0.0f, 100.0f);;
			normal_report_score[search_result[0] - 1] = new_score;
			break;
		}

		case 8: {
			cout << "输入新的考试成绩：";
			float new_score;
			new_score = getinput(0.0f, 100.0f);;
			test_score[search_result[0] - 1] = new_score;
			break;
		}
		}
			  final_score[search_result[0] - 1] = 0.2 * normal_work_score[search_result[0] - 1] + 0.15 * normal_experiment_score[search_result[0] - 1] + 0.05 * normal_report_score[search_result[0] - 1] + 0.6 * test_score[search_result[0] - 1];
			  showInfo(search_result[0] - 1);
			  changed = true;
	}
	return 0;
}

int Manager::append()
{
	int tmp;
	string tmp1;
	float tmp2;
	//不超过最大学生数
	if (!(info.class_students < max_student_num)) {
		cout << "已达到最大学生数，不能输入！" << endl;
		return 0;
	}
	cout << "添加学生信息：" << endl;
	//学号不能重复，用函数处理
	getId(&tmp);
	id[info.class_students] = tmp;
	cout << "请输入姓名：";
	cin >> tmp1;
	name[info.class_students] = tmp1;
	cout << "请输入性别：";
	cin >> tmp1;
	if (tmp1 != "女" && tmp1 != "男") {
		cout << "输入的性别错误，已为你选为“男”。";
		gender[info.class_students] = "男";
	}
	gender[info.class_students] = "男";
	cout << "请输入班级：";
	cin >> tmp1;
	class_name[info.class_students] = tmp1;
	cout << "请输入平时成绩（作业）：";
	tmp2 = getinput(0.0f, 100.0f);
	normal_work_score[info.class_students] = tmp2;
	cout << "请输入平时成绩（实验）：";
	tmp2 = getinput(0.0f, 100.0f);
	normal_experiment_score[info.class_students] = tmp2;
	cout << "请输入平时成绩（报告）：";
	tmp2 = getinput(0.0f, 100.0f);
	normal_report_score[info.class_students] = tmp2;
	cout << "请输入考试成绩：";
	tmp2 = getinput(0.0f, 100.0f);
	test_score[info.class_students] = tmp2;
	
	final_score[info.class_students]= 0.2 * normal_work_score[info.class_students] + 0.15 * normal_experiment_score[info.class_students] + 0.05 * normal_report_score[info.class_students] + 0.6 * test_score[info.class_students];
	//选课学生数自动加一
	info.class_students += 1;
	cout << "输入完成"<<endl;

	changed = true;

	return 0;
}

int Manager::remove()
{
	search();
	cout << "输入r完成删除。";
	char input;
	cin >> input;
	if (input == 'r') {
		for (int i = 0; i < info.class_students; i++) {
			if (search_result[i] != 0) {
				//测试用的
				//cout << (i - 1) << endl;
				clearAtIdx(i-1);
				info.class_students -= 1;
				//测试用的
				//cout << info.class_students << endl;
			}
		}
	}
	changed = true;
	return 0;
}

int Manager::storage()
{
	if (!changed) {
		cout << "请先修改再保存。" << endl;
		return 0;
	}
	out.open("data.dat", ios::out);
	out << "课程名称：     " << info.class_name << endl;
	out << "课程编号：     " << info.class_number << endl;
	out << "开课单位：     " << info.class_host << endl;
	out << "授课教师：     " << info.class_teacher << endl;
	out << "选课人数：     " << info.class_students << endl;
	out << head << endl;
	for (int i = 0; i < 8; i++) {
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << columns[i] << "      ";
	}
	out << endl;
	for (int i = 0; i < info.class_students; i++) {
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << id[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << name[i] << "     ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << gender[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << class_name[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << normal_report_score[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << normal_experiment_score[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(10) << setfill(' ');
		out << normal_report_score[i] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(14) << setfill(' ');
		out << test_score[i] << "      ";
		out << endl;
	}
	out.close();
	cout << "保存成功！"<<endl;
	return 0;
}

int Manager::analysize()
{
	cout << "最高分为：" << getMax(final_score) << endl;
	cout << "最低分为：" << getMin(final_score) << endl;
	cout << "平均分为：" << getAverage(final_score) << endl;
	cout << "优秀率为：" << getGoodRate(final_score) << endl;
	cout << "及格率为：" << getPassRate(final_score) << endl;
	cout << "0~9人数：" << getFractionalSegment(final_score, 0, 9)<<endl;
	cout << "10~19人数：" << getFractionalSegment(final_score, 10, 19)<<endl;
	cout << "20~29人数：" << getFractionalSegment(final_score, 20, 29)<<endl;
	cout << "30~39人数：" << getFractionalSegment(final_score, 30, 39)<<endl;
	cout << "40~49人数：" << getFractionalSegment(final_score, 40, 49)<<endl;
	cout << "50~59人数：" << getFractionalSegment(final_score, 50, 59)<<endl;
	cout << "60~69人数：" << getFractionalSegment(final_score, 60, 69)<<endl;
	cout << "70~79人数：" << getFractionalSegment(final_score, 70, 79)<<endl;
	cout << "80~89人数：" << getFractionalSegment(final_score, 80, 89)<<endl;
	cout << "90~100人数：" << getFractionalSegment(final_score, 90, 100)<<endl;

	//对学生进行排名
	rank(final_score, studentRank);
	cout << head << endl;
	for (int i = 0; i < 8; i++) {
		cout << columns[i] << setw(8) << "    ";
	}
	cout << "最终成绩";
	cout << endl;
	int j = 0;
	while (j < info.class_students) {
		cout << setprecision(3) << setiosflags(ios::left) << setw(10) << setfill(' ');
		cout << id[studentRank[j]] << " ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(9) << setfill(' ');
		cout << name[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(4) << setfill(' ');
		cout << gender[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << class_name[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << normal_work_score[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << normal_experiment_score[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(18) << setfill(' ');
		cout << normal_experiment_score[studentRank[j]] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(9) << setfill(' ');
		cout << test_score[studentRank[j]] << "      ";
		cout << final_score[studentRank[j]];
		j++;
		cout << endl;
	}

	//若为true,则可以保存
	analysized = true;

	return 0;
}

int Manager::save()
{
	if (!analysized) {
		cout << "还没有进行统计！" << endl;
		return 0;
	}
	out.open("analysized_data.dat", ios::out);
	out << "课程名称：     " << info.class_name << endl;
	out << "课程编号：     " << info.class_number << endl;
	out << "开课单位：     " << info.class_host << endl;
	out << "授课教师：     " << info.class_teacher << endl;
	out << "选课人数：     " << info.class_students << endl;
	out << "最高分为：" << getMax(final_score) << endl;
	out << "最低分为：" << getMin(final_score) << endl;
	out << "平均分为：" << getAverage(final_score) << endl;
	out << "优秀率为：" << getGoodRate(final_score) << endl;
	out << "及格率为：" << getPassRate(final_score) << endl;
	out << "0~9人数：" << getFractionalSegment(final_score, 0, 9) << endl;
	out << "10~19人数：" << getFractionalSegment(final_score, 10, 19) << endl;
	out << "20~29人数：" << getFractionalSegment(final_score, 20, 29) << endl;
	out << "30~39人数：" << getFractionalSegment(final_score, 30, 39) << endl;
	out << "40~49人数：" << getFractionalSegment(final_score, 40, 49) << endl;
	out << "50~59人数：" << getFractionalSegment(final_score, 50, 59) << endl;
	out << "60~69人数：" << getFractionalSegment(final_score, 60, 69) << endl;
	out << "70~79人数：" << getFractionalSegment(final_score, 70, 79) << endl;
	out << "80~89人数：" << getFractionalSegment(final_score, 80, 89) << endl;
	out << "90~100人数：" << getFractionalSegment(final_score, 90, 100) << endl;
	for (int i = 0; i < 8; i++) {
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << columns[i] << "      ";
	}
	out << "最终成绩";
	rank(final_score, studentRank);
	out << endl;
	for (int i = 0; i < info.class_students; i++) {
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << id[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << name[studentRank[i]] << "     ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << gender[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << class_name[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << normal_report_score[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		out << normal_experiment_score[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(10) << setfill(' ');
		out << normal_report_score[studentRank[i]] << "      ";
		out << setprecision(3) << setiosflags(ios::left) << setw(14) << setfill(' ');
		out << test_score[studentRank[i]] << "      ";
		out << final_score[studentRank[i]];
		out << endl;
	}
	out.close();
	cout << "保存成功！";
	return 0;
}

void Manager::loadDataBase(string path)
{
	in.open(path, ios::in);

	readInfo();
	readStudentInfo();

	if (findError()) {
		cout << "有学号相同的学生，请检查！";
		has_same_id = true;
	}
	else {
		cout << "学生信息正常。";
		cout << "读入成功！" << endl;
	}
}

bool Manager::readInfo() {
	string tmp1 = "0";
	string spsace = "      ";
	string tmp2 = "0";
	in >> tmp1 >> info.class_name;
	in >> tmp1 >> info.class_number;
	in >> tmp1 >> info.class_host;
	in >> tmp1 >> info.class_teacher;
	in >> tmp1 >> info.class_students;
	//测试用的
	//cout << info.class_name<<endl << info.class_number<<endl << info.class_host<<endl << info.class_teacher<<endl << info.class_students << endl;
	return true;
}

bool Manager::readStudentInfo() {
	in >> head;
	for (int i = 0; i < 8; i++) {
		in >> columns[i];
	}
	//测试用的
	/*for (int i = 0; i < 8; i++) {
		cout << columns[i]<<"   ";
	}*/
	int j = 0;
	while (j < info.class_students) {
		in >> id[j];
		in >> name[j];
		in >> gender[j];
		in >> class_name[j];
		in >> normal_work_score[j];
		in >> normal_report_score[j];
		in >> normal_experiment_score[j];
		in >> test_score[j];

		//计算总成绩
		final_score[j] = 0.2 * normal_work_score[j] + 0.15 * normal_experiment_score[j] + 0.05 * normal_report_score[j] + 0.6 * test_score[j];
		//检查负分或大于100分的
		if (normal_work_score[j] < 0 || normal_report_score[j] < 0 || normal_experiment_score[j] < 0 || test_score[j] < 0 || normal_work_score[j] > 100 || normal_report_score[j] > 100 || normal_experiment_score[j] > 100 || test_score[j] > 100) {
			cout << "有分数为负或大于100的情况，已为你删除该学生。" << endl;
			info.class_students -= 1;
			continue;
		}
		j++;
		//测试用的
		//cout << j;
	}
	in.close();

	return true;
}

//max=0表示输入的数可以无穷大
int Manager::getinput(int min,int max)
{
	int input;
	//cin >> input;

	while (!(cin >> input) || (input<min||input>max) && !(max == 0))
	{
		while (getchar() != '\n');
		cin.clear();
		if (max != 0) {
			cout << "只能输入" << min << "~" << max << "之间的数，请重新输入！" << endl;
		}
		else {
			cout << "请输入数字！" << endl;
		}
	}

	return input;
}

float Manager::getinput(float min, float max)
{
	float input;
	//cin >> input;
	while (!(cin >> input) || (input<min || input>max)&&!(max==0))
	{
		while (getchar() != '\n');
		cin.clear();
		if (max != 0) {
			cout << "只能输入" << min << "~" << max << "之间的数，请重新输入！" << endl;
		}
		else {
			cout << "请输入数字！" << endl;
		}
	}

	return input;
}

string Manager::getstrinput() {
	string input;
	cin >> input;
	return input;
}

bool Manager::findError()
{
	for (int i = 0; i < info.class_students; i++) {
		for (int j = i + 1; j < info.class_students - i; j++) {
			if (id[i] == id[j]) {
				cout << "相同的学号：" << id[i] << endl;;
				return true;
			}
		}
	}
	return false;
}

void Manager::clearAtIdx(int idx)
{
	for (int i = idx; i < info.class_students; i++) {
		id[idx] = id[idx + 1];
		name[idx] = name[idx+1];
		gender[idx] = gender[idx+1];
		class_name[idx] = class_name[idx+1];
		normal_work_score[idx] = normal_work_score[idx+1];
		normal_experiment_score[idx] = normal_experiment_score[idx+1];
		normal_report_score[idx] = normal_report_score[idx+1];
		test_score[idx] = test_score[idx+1];
		final_score[idx] = final_score[idx+1];
	}

}

void Manager::clearResult()
{
	int round = sizeof(search_result) / sizeof(int);
	for (int i = 0; i < round; i++) {
		search_result[i] = 0;
	}
}

void Manager::append(int idx)
{
	int round = sizeof(search_result) / sizeof(int);
	for (int i = 0; i < round; i++) {
		if (search_result[i] == 0) {
			search_result[i] = idx;
			break;
		}
	}
}

void Manager::getId(int*tmp)
{
	cout << "请输入学号：";
	*tmp = getinput(0, 0);
	for (int i = 0; i < info.class_students; i++) {
		if (id[i] == *tmp) {
			cout << "学号不能重复！" << endl;
			getId(tmp);
		}
	}
}

void Manager::showInfo(int idx)
{
	cout << "学号:" << id[idx] << "  ";
	cout << "姓名:" << name[idx] << "  ";
	cout << "性别:" << gender[idx] << "  ";
	cout << "班级名称:" << class_name[idx] << "  ";
	cout << "平时成绩（作业）:" << normal_work_score[idx] << "  ";
	cout << "平时成绩（实验）:" << normal_experiment_score[idx] << "  ";
	cout << "平时成绩（报告）:" << normal_report_score[idx] << "  ";
	cout << "考试成绩:" << test_score[idx] << "  ";
	cout << "最终成绩：" << final_score[idx] << endl;
}

template<typename T>
int Manager::findWith(T* array, int size) {
	cout << "请输入查询的数据：";
	T msg;
	cin >> msg;
	clearResult();
	for (int i = 0; i < size; i++) {
		if (array[i] == msg) {
			showInfo(i);
			append(i + 1);
		}
	}
	if (search_result[0] == 0) {
		cout << "未查到相关学生。" << endl;
	}
	return 1;
}

template<typename T>
int Manager::findWith(T data, T* array, int size)
{
	clearResult();
	for (int i = 0; i < size; i++) {
		if (array[i] == data) {
			showInfo(i);
			append(i + 1);
		}
	}
	if (search_result[0] == 0) {
		cout << "未查到相关学生,请重新输入！" << endl;
		return 0;
	}
	return 1;
}

float Manager::getMax(float arr[]){
	float max = arr[0];
	for (int i = 1; i < info.class_students; i++) {
		if (max < arr[i])max = arr[i];
	}
	return max;
}
float Manager::getMin(float arr[]){
	float min = arr[0];
	for (int i = 1; i < info.class_students; i++) {
		if (min <arr[i])min = arr[i];
	}
	return min;
}
float Manager::getAverage(float arr[]){
	float sum = 0;
	for (int i = 0; i < info.class_students; i++)sum += arr[i];
	return sum / info.class_students;
}
float Manager::getGoodRate(float arr[]){
	float num = 0;
	for (int i = 0; i < info.class_students; i++)if (arr[i] >= 80)num++;
	return num / info.class_students;
}
float Manager::getPassRate(float arr[]){
	float num = 0;
	for (int i = 0; i < info.class_students; i++)if (arr[i] >= 60)num++;
	return num / info.class_students;
}
int Manager::getFractionalSegment(float arr[], float min, float max) {
	int num = 0;
	for (int i = 0; i < info.class_students;i++) {
		if (arr[i] >= min && arr[i] <= max)num++;
	}
	return num;
}
void Manager::rank(float arr[],int rank[]) {
	int max = 0;
	for (int i = 0; i < info.class_students; i++) {
		rank[i] = i;
	}
	for (int i = 0; i < info.class_students; i++) {
		for (int j = i + 1; j < info.class_students; j++) {
			if (arr[rank[j]] > arr[rank[i]]) {
				max = rank[j];
				rank[j] = rank[i];
				rank[i] = max;
			}
		}
	}
}

