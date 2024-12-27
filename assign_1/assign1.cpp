#include <iostream>

using namespace std;
double sum(double scores[], int s_size);
double average(double s_sum, int s_size);
int min(double scores[], int s_size, int idx);
int max(double scores[], int s_size, int idx);

int main() {
	double scores[5];
	int scores_size = 5;
	int num = 1;
	double tmp = 0;

	for (int i = 0; i < scores_size; i++) {
		cout << "�л��� ������ �Է��Ͻÿ�: ";
		cin >> scores[i];
	}

	while (1==1) {
		cout << "���ϴ� ���� ����� �Է��Ͻÿ�(�������� : 1 / �������� : 2) : ";
		cin >> num;
		if (num == 1) {
			//������������ �����ϴ� ���
			for (int i = 0; i < scores_size; i++) {
				//scores �迭 ������ �ּҰ��� �ε����� min �Լ����� �޾�
				//�ش� score�� �迭 �Ǿ��ڸ����� ������� ��ü
				int min_idx = min(scores, scores_size, i);
				tmp = scores[i];
				scores[i] = scores[min_idx];
				scores[min_idx] = tmp;
			}
			cout << "�л����� ���� �������� ���� ��� : ";
			//������������ ���ĵ� scores �迭�� ���
			for (int i = 0; i < scores_size; i++) {
				cout << scores[i] << " ";
			}
			cout << endl;
			break;

		}
		else if (num == 2) {
			//������������ �����ϴ� ���
			for (int i = 0; i < scores_size; i++) {
				//scores �迭 ������ �ִ밪�� �ε����� max �Լ����� �޾�
				//�ش� score�� �迭 �Ǿ��ڸ����� ������� ��ü
				int max_idx = max(scores, scores_size, i);
				tmp = scores[i];
				scores[i] = scores[max_idx];
				scores[max_idx] = tmp;
			}
			cout << "�л����� ���� �������� ���� ��� : ";
			//������������ ���ĵ� scores �迭�� ���
			for (int i = 0; i < scores_size; i++) {
				cout << scores[i] << " ";
			}
			cout << endl;
			break;

		}
		else {
			cout << "1 �Ǵ� 2�� �Է� �����մϴ�" << endl;
		}
	}
	
	//�л����� ���� ���հ� ����� ���
	double total = sum(scores, scores_size);
	cout << "�л����� ���� ���� : " << total << endl;
	cout << "�л����� ���� ��� : " << average(total, scores_size) << endl;

	
	return 0;
}

//sum : �л����� ���� ���� ���
double sum(double scores[], int s_size) {
	double s_sum = 0;
	for (int i = 0; i < s_size; i++) {
		s_sum += scores[i];
	}
	return s_sum;
}

//average : �л����� ���� ������ �޾� ��� ���
double average(double s_sum, int s_size) {
		return (s_sum / s_size);
}

//min : ���������� ���̴� �Լ���, �迭�� ���� ������ ���� ���� ���� �ε����� ��ȯ
int min(double scores[], int s_size, int idx) {
	int min_idx = idx;
	for (int i = idx + 1; i < s_size; i++) {
		if (scores[i] < scores[min_idx]) {
			min_idx = i;
		}
	}
	return min_idx;
}

//max : ���������� ���̴� �Լ���, �迭�� ���� ������ ���� ū ���� �ε����� ��ȯ
int max(double scores[], int s_size, int idx) {
	int max_idx = idx;
	for (int i = idx + 1; i < s_size; i++) {
		if (scores[i] > scores[max_idx]) {
			max_idx = i;
		}
	}
	return max_idx;
}