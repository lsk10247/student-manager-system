#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Manager
{
public:
	Manager();

	//九种操作
	int insert();
	int brouse();
	int search();
	int change();
	int append();
	int remove();
	int storage();
	int analysize();
	int save();

private:
	ifstream in;
	ofstream out;

	//默认路径
	string PATH;
	//自定义路径
	string path;
	//最大学生数
	static const int max_student_num = 100;
	//成绩表的开头
	string head;
	//栏目
	string columns[8];

	bool has_same_id;
	//有无对数据进行修改
	bool changed;
	//是否进行过分析
	bool analysized;

	//学生的学号
	int id[max_student_num];
	//学生的名字
	string name[max_student_num];
	//学生的性别
	string gender[max_student_num];
	//学生的班级
	string class_name[max_student_num];
	//学生的平时分
	float normal_work_score[max_student_num];
	//学生的实验发分
	float normal_experiment_score[max_student_num];
	//学生的报告分
	float normal_report_score[max_student_num];
	//学生的考试成绩
	float test_score[max_student_num];
	//学生的最终成绩
	float final_score[max_student_num];

	//初始化函数
	void init();

	//课程信息
	struct Info
	{
		string class_name;
		string class_number;
		string class_host;
		string class_teacher;
		int class_students;
	}info;

	//搜索结果，保存的时数组中的下标
	int search_result[max_student_num];
	//学生以下标形式的排名
	int studentRank[max_student_num];

	//从特定位置加载数据
	void loadDataBase(string path);
	//加载表头
	bool readInfo();
	//加载学生信息
	bool readStudentInfo();

	//获取min~max的输入，如果max为0，则无上限
	int getinput(int min,int max);
	//同上
	float getinput(float min, float max);
	//获取string输入
	string getstrinput();
	//检测有无学号相同的学生，有则返回true，否则返回false
	bool findError();
	//清除位于特定下标的学生数据
	void clearAtIdx(int idx);
	//将搜索结果所有值变为0
	void clearResult();
	//在搜索结果中添加数据
	void append(int idx);
	//从控制台获取不重复的学号
	void getId(int*);
	//展示下标为idx的学生信息
	void showInfo(int idx);

	//在大小为size的数组array中搜索，结果保存于search_result
	template<typename T>
	int findWith(T* array,int size);
	//在大小为size的数组array中搜索data，结果保存于search_result
	template<typename T>
	int findWith(T data, T* array, int size);

	//获取最大值
	float getMax(float[]);

	//获取最小值
	float getMin(float[]);

	//获取平均值
	float getAverage(float[]);

	//获取优良率
	float getGoodRate(float[]);

	//获取及格率
	float getPassRate(float[]);

	//获取数组中min~max数据数量并返回
	int getFractionalSegment(float[],float min, float max);

	//对float数组进行排序，并将排序好的下标保存于int数组中
	void rank(float[],int[]);
};

