#include "Manager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

Manager::Manager() {
	cout << "�����������ɹ�!" << endl;
	init();
}

void Manager::init() {
	PATH = "StudentScore.dat";
	cout << "��ʼ���ɹ�!" << endl;
}

int Manager::insert()
{
	cout << "����������ʼ����ѧ���ɼ���������" << endl;
	cout << "0:Ĭ�ϴ�StudentScore.dat���롣" << endl;
	cout << "1:���Զ���·�����롣" << endl;
	cout << "2:�ֶ����롣" << endl;
	int input = getinput();
	switch (input) {
	case 0:
		loadDataBase(PATH);
		break;
	case 1:
		cout << "���������·��:" << endl;
		cin >> path;
		loadDataBase(path);
		break;
	case 2:
		append();
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
		cout << columns[i]<<setw(8) << "    ";
	}
	cout << endl;
	int j = 0;
	while (j < info.class_students) {
		cout <<setprecision(3) <<setiosflags(ios::left) << setw(10) << setfill(' ');
		cout << id[j] <<" ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(9) << setfill(' ');
		cout << name[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(4) << setfill(' ');
		cout << gender[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << class_name[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << normal_work_score[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(15) << setfill(' ');
		cout << normal_experiment_score[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setw(13) << setfill(' ');
		cout << normal_experiment_score[j] << "      ";
		cout << setprecision(3) << setiosflags(ios::left) << setfill(' ');
		cout << test_score[j] << "      ";
		j++;
		cout << endl;
	}
	return 0;
}

int Manager::search()
{
	cout << "�������ѯ��ʽ��" << endl;
	cout << "1:��ѧ�Ų�ѯ\n2:��������ѯ\n3:���Ա��ѯ\n4:���༶���Ʋ�ѯ\n5:��ƽʱ�ɼ�����ҵ����ѯ\n6:��ƽʱ�ɼ���ʵ�飩��ѯ\n7:��ƽʱ�ɼ������棩��ѯ\n8:�����Գɼ���ѯ\n";
	int input = getinput();
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
	cout << "��������Ҫ�޸ĵ�ѧ����ѧ�ţ�";
	int input = getinput();
	findWith(input, id, info.class_students);
	cout << "���޸ĵ�ѡ��Ϊ��\n" << "1:ѧ��\n2:����\n3:�Ա�\n4:�༶����\n5:ƽʱ�ɼ�����ҵ��\n6:ƽʱ�ɼ���ʵ�飩\n7:ƽʱ�ɼ������棩\n8:���Գɼ�\n" << "�������ֽ���ѡ��";
	while (true)
	{
		int input = getinput();
		switch (input) {
		case 0:
			return 1;
		case 1:
			cout << "�����µ�ѧ�ţ�";
			int new_id;
			cin >> new_id;
			id[search_result[0] - 1] = new_id;
			showInfo(search_result[0] - 1);
			break;
		case 2:
		{
			cout << "�����µ�������";
			string new_name;
			cin >> new_name;
			name[search_result[0] - 1] = new_name;
			showInfo(search_result[0] - 1);
			break;
		}
		case 3:
			if (gender[search_result[0] - 1] == "��") {
				gender[search_result[0] - 1] = "Ů";
			}
			else {
				gender[search_result[0] - 1] = "��";
			}
			showInfo(search_result[0] - 1);
			break;
		case 4:
		{
			cout << "�����µİ༶��";
			string new_class;
			cin >> new_class;
			class_name[search_result[0] - 1] = new_class;
			showInfo(search_result[0] - 1);
			break;
		}

		case 5: {
			cout << "�����µ�ƽʱ�ɼ�����ҵ����";
			float new_score;
			cin >> new_score;
			normal_work_score[search_result[0] - 1] = new_score;
			showInfo(search_result[0] - 1);
			break;
		}

		case 6: {
			cout << "�����µ�ƽʱ�ɼ���ʵ�飩��";
			float new_score;
			cin >> new_score;
			normal_experiment_score[search_result[0] - 1] = new_score;
			showInfo(search_result[0] - 1);
			break;
		}

		case 7: {
			cout << "�����µ�ƽʱ�ɼ������棩��";
			float new_score;
			cin >> new_score;
			normal_report_score[search_result[0] - 1] = new_score;
			showInfo(search_result[0] - 1);
			break;
		}

		case 8: {
			cout << "�����µĿ��Գɼ���";
			float new_score;
			cin >> new_score;
			test_score[search_result[0] - 1] = new_score;
			showInfo(search_result[0] - 1);
			break;
		}
		}
	}
	return 0;
}

int Manager::append()
{
	int tmp;
	string tmp1;
	float tmp2;
	cout << "���ѧ����Ϣ��" << endl;
	cout << "������ѧ�ţ�";
	cin >> tmp;
	id[info.class_students] = tmp;
	cout << "������������";
	cin >> tmp1;
	name[info.class_students] = tmp1;
	cout << "�������Ա�";
	cin >> tmp1;
	if (tmp1 != "Ů" && tmp1 != "��") {
		cout << "������Ա������Ϊ��ѡΪ���С���";
		gender[info.class_students] = "��";
	}
	gender[info.class_students] = "��";
	cout << "������༶��";
	cin >> tmp1;
	class_name[info.class_students] = tmp1;
	cout << "������ƽʱ�ɼ�����ҵ����";
	cin >> tmp2;
	normal_work_score[info.class_students] = tmp2;
	cout << "������ƽʱ�ɼ���ʵ�飩��";
	cin >> tmp2;
	normal_experiment_score[info.class_students] = tmp2;
	cout << "������ƽʱ�ɼ������棩��";
	cin >> tmp2;
	normal_report_score[info.class_students] = tmp2;
	cout << "�����뿼�Գɼ���";
	cin >> tmp2;
	test_score[info.class_students] = tmp2;
	final_score[info.class_students]= 0.2 * normal_work_score[info.class_students] + 0.15 * normal_experiment_score[info.class_students] + 0.05 * normal_report_score[info.class_students] + 0.6 * test_score[info.class_students];
	info.class_students += 1;
	cout << "������ɣ���5�������롣";
	return 0;
}

int Manager::remove()
{
	search();
	cout << "����r���ɾ����";
	char input;
	cin >> input;
	if (input == 'r') {
		for (int i = 0; i < info.class_students; i++) {
			if (search_result[i] != 0) {
				cout << (i - 1) << endl;
				clearAtIdx(i-1);
				info.class_students -= 1;
				cout << info.class_students << endl;
			}
		}
	}
	return 0;
}

int Manager::storage()
{
	out.open("data.dat", ios::out);
	out << "�γ����ƣ�     " << info.class_name << endl;
	out << "�γ̱�ţ�     " << info.class_number << endl;
	out << "���ε�λ��     " << info.class_host << endl;
	out << "�ڿν�ʦ��     " << info.class_teacher << endl;
	out << "ѡ��������     " << info.class_students << endl;
	out << head << endl;
	for (int i = 0; i < 8; i++) {
		out << columns[i] << "      ";
	}
	out << endl;
	for (int i = 0; i < info.class_students; i++) {
		out << id[i] << "      ";
		out << name[i] << "     ";
		out << gender[i] << "      ";
		out << class_name[i] << "      ";
		out << normal_report_score[i] << "      ";
		out << normal_experiment_score[i] << "      ";
		out << normal_report_score[i] << "      ";
		out << test_score[i] << "      ";
		out << endl;
	}
	out.close();
	cout << "����ɹ���";
	return 0;
}

int Manager::analize()
{
	cout << "��߷�Ϊ��" << getMax(final_score) << endl;
	cout << "��ͷ�Ϊ��" << getMin(final_score) << endl;
	cout << "ƽ����Ϊ��" << getAverage(final_score) << endl;
	cout << "������Ϊ��" << getGoodRate(final_score) << endl;
	cout << "������Ϊ��" << getPassRate(final_score) << endl;
	cout << "0~9������" << getFractionalSegment(final_score, 0, 9);
	cout << "10~19������" << getFractionalSegment(final_score, 10, 19)<<endl;
	cout << "20~29������" << getFractionalSegment(final_score, 20, 29)<<endl;
	cout << "30~39������" << getFractionalSegment(final_score, 30, 39)<<endl;
	cout << "40~49������" << getFractionalSegment(final_score, 40, 49)<<endl;
	cout << "50~59������" << getFractionalSegment(final_score, 50, 59)<<endl;
	cout << "60~69������" << getFractionalSegment(final_score, 60, 69)<<endl;
	cout << "70~79������" << getFractionalSegment(final_score, 70, 79)<<endl;
	cout << "80~89������" << getFractionalSegment(final_score, 80, 89)<<endl;
	cout << "90~100������" << getFractionalSegment(final_score, 90, 100)<<endl;
	rank(final_score, studentRank);
	for (int i = 0; i < info.class_students; i++) {
		showInfo(studentRank[i]);
	}
	return 0;
}

int Manager::save()
{
	return 0;
}

void Manager::loadDataBase(string path)
{
	in.open(path, ios::in);

	readInfo();
	readStudentInfo();

	if (findError()) {
		cout << "��ѧ����ͬ��ѧ�������飡";
		has_same_id = true;
	}
	else {
		cout << "ѧ����Ϣ������";
		cout << "����ɹ���" << endl;
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
	//�����õ�
	//cout << info.class_name<<endl << info.class_number<<endl << info.class_host<<endl << info.class_teacher<<endl << info.class_students << endl;
	return true;
}

bool Manager::readStudentInfo() {
	in >> head;
	for (int i = 0; i < 8; i++) {
		in >> columns[i];
	}
	//�����õ�
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

		//�����ܳɼ�
		final_score[j] = 0.2 * normal_work_score[j] + 0.15 * normal_experiment_score[j] + 0.05 * normal_report_score[j] + 0.6 * test_score[j];
		j++;
		//�����õ�
		//cout << j;
	}
	in.close();

	return true;
}


int Manager::getinput()
{
	int input;
	cin >> input;
	//if (type == 1) {
	//	return input;
	//}

	//if (type == 0) {
	//	if (input > 8 && input < 1) {
	//		cout << "������1~8�ڵ�����" << endl;
	//		getinput(0)
	//	}
	//}
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
				cout << "��ͬ��ѧ�ţ�" << id[i] << endl;;
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

void Manager::showInfo(int idx)
{
	cout << "ѧ��:" << id[idx] << "  ";
	cout << "����:" << name[idx] << "  ";
	cout << "�Ա�:" << gender[idx] << "  ";
	cout << "�༶����:" << class_name[idx] << "  ";
	cout << "ƽʱ�ɼ�����ҵ��:" << normal_work_score[idx] << "  ";
	cout << "ƽʱ�ɼ���ʵ�飩:" << normal_experiment_score[idx] << "  ";
	cout << "ƽʱ�ɼ������棩:" << normal_report_score[idx] << "  ";
	cout << "���Գɼ�:" << test_score[idx] << "  ";
	cout << "���ճɼ���" << final_score[idx] << endl;
}

template<typename T>
int Manager::findWith(T* array, int size) {
	cout << "�������ѯ�����ݣ�";
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
		cout << "δ�鵽���ѧ����" << endl;
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
		cout << "δ�鵽���ѧ��,���������룡" << endl;
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

