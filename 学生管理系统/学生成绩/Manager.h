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
	//������ļ���
	string filename;
	//���ѧ����
	static const int max_student_num = 100;
	//�ɼ���Ŀ�ͷ
	string head;
	//��Ŀ��
	static const int COLUMN = 8;
	//��Ŀ
	string columns[COLUMN];

	//����ͬѧ�ŵ�ѧ��
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

	//û�õ�
	struct Student {
		int id;
		string name;
		string gender;
		string class_name;
		float normal_work_score;
		float normal_experiment_score;
		float normal_report_score;
		float test_score;
		float final_score;
	};
	Student stdus[max_student_num];

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
	//��������
	bool loaded;
	//���ر�ͷ
	bool readInfo();
	//����ѧ����Ϣ
	bool readStudentInfo();

	//��ӡѧ���ɼ�������Ϣ
	void printInfo();
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
	//չʾһ��ѧ����Ϣ
	void showList(int *arr,int size);
	//ɾ��ѧ��
	void deleteStudent();

	//�ڴ�СΪsize������array�����������������search_result
	template<typename T>
	int findWith(T* array,int size);
	//�ڴ�СΪsize������array������data�����������search_result
	template<typename T>
	int findWith(T data, T* array, int size,bool showinfo);

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
	//��float����������򣬲�������õ��±걣����int������
	void rankInArray(float[], int[],int size);
};

