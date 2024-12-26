#include <iostream>

using namespace std;
double sum(double scores[], int s_size);
double average(double s_sum, int s_size);


int main() {
	double scores[5];

	for (int i = 0; i < 5; i++) {
		cout << "학생의 점수를 입력하시오: ";
		cin >> scores[i];
	}
	double total = sum(scores, 5);
	cout << "학생들의 점수 총합 : " << total << endl;
	cout << "학생들의 점수 평균 : " << average(total, 5) << endl;

	
	return 0;
}

double sum(double scores[], int s_size) {
	double s_sum = 0;
	for (int i = 0; i < s_size; i++) {
		s_sum += scores[i];
	}
	return s_sum;
}

double average(double s_sum, int s_size) {
		return (s_sum / s_size);
}