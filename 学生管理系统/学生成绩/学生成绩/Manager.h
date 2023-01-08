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
	int analysize();
	int save();

private:
	ifstream in;
	ofstream out;

	//Ĭ��·��
	string PATH;
	//�Զ���·��
	string path;
	//���ѧ����
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

	//ѧ����ѧ��
	int id[max_student_num];
	//ѧ��������
	string name[max_student_num];
	//ѧ�����Ա�
	string gender[max_student_num];
	//ѧ���İ༶
	string class_name[max_student_num];
	//ѧ����ƽʱ��
	float normal_work_score[max_student_num];
	//ѧ����ʵ�鷢��
	float normal_experiment_score[max_student_num];
	//ѧ���ı����
	float normal_report_score[max_student_num];
	//ѧ���Ŀ��Գɼ�
	float test_score[max_student_num];
	//ѧ�������ճɼ�
	float final_score[max_student_num];

	//��ʼ������
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

	//��������������ʱ�����е��±�
	int search_result[max_student_num];
	//ѧ�����±���ʽ������
	int studentRank[max_student_num];

	//���ض�λ�ü�������
	void loadDataBase(string path);
	//���ر�ͷ
	bool readInfo();
	//����ѧ����Ϣ
	bool readStudentInfo();

	//��ȡmin~max�����룬���maxΪ0����������
	int getinput(int min,int max);
	//ͬ��
	float getinput(float min, float max);
	//��ȡstring����
	string getstrinput();
	//�������ѧ����ͬ��ѧ�������򷵻�true�����򷵻�false
	bool findError();
	//���λ���ض��±��ѧ������
	void clearAtIdx(int idx);
	//�������������ֵ��Ϊ0
	void clearResult();
	//������������������
	void append(int idx);
	//�ӿ���̨��ȡ���ظ���ѧ��
	void getId(int*);
	//չʾ�±�Ϊidx��ѧ����Ϣ
	void showInfo(int idx);

	//�ڴ�СΪsize������array�����������������search_result
	template<typename T>
	int findWith(T* array,int size);
	//�ڴ�СΪsize������array������data�����������search_result
	template<typename T>
	int findWith(T data, T* array, int size);

	//��ȡ���ֵ
	float getMax(float[]);

	//��ȡ��Сֵ
	float getMin(float[]);

	//��ȡƽ��ֵ
	float getAverage(float[]);

	//��ȡ������
	float getGoodRate(float[]);

	//��ȡ������
	float getPassRate(float[]);

	//��ȡ������min~max��������������
	int getFractionalSegment(float[],float min, float max);

	//��float����������򣬲�������õ��±걣����int������
	void rank(float[],int[]);
};

