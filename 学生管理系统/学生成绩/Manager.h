#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Manager
{
public:
	Manager();

	//���ֲ���
	int insert();
	int brouse();
	int search();
	int change();
	int append();
	int remove();
	int storage();
	int analize();
	int save();

private:
	ifstream in;
	ofstream out;

	//Ĭ��·��
	string PATH;
	//�Զ���·��
	string path;
	static const int max_student_num = 100;
	//�ɼ���Ŀ�ͷ
	string head;
	//��Ŀ
	string columns[8];

	bool has_same_id;
	//���޶����ݽ����޸�
	bool changed;
	//�Ƿ���й�����
	bool analysized;

	int id[max_student_num];
	string name[max_student_num];
	string gender[max_student_num];
	string class_name[max_student_num];
	float normal_work_score[max_student_num];
	float normal_experiment_score[max_student_num];
	float normal_report_score[max_student_num];
	float test_score[max_student_num];
	float final_score[max_student_num];

	void init();

	//�γ���Ϣ
	struct Info
	{
		string class_name;
		string class_number;
		string class_host;
		string class_teacher;
		int class_students;
	}info;

	int search_result[max_student_num];
	int studentRank[max_student_num];

	void loadDataBase(string path);
	bool readInfo();
	bool readStudentInfo();

	int getinput(int min,int max);
	float getinput(float min, float max);
	string getstrinput();
	bool findError();
	void clearAtIdx(int idx);
	void clearResult();
	void append(int idx);
	void getId(int*);
	void showInfo(int idx);

	template<typename T>
	int findWith(T* array,int size);
	template<typename T>
	int findWith(T data, T* array, int size);


	float getMax(float[]);
	float getMin(float[]);
	float getAverage(float[]);
	float getGoodRate(float[]);
	float getPassRate(float[]);
	int getFractionalSegment(float[],float min, float max);
	void rank(float[],int[]);
};

