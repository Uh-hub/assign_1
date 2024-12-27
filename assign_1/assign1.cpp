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
		cout << "학생의 점수를 입력하시오: ";
		cin >> scores[i];
	}

	while (1==1) {
		cout << "원하는 정렬 방법을 입력하시오(오름차순 : 1 / 내림차순 : 2) : ";
		cin >> num;
		if (num == 1) {
			//오름차순으로 정렬하는 경우
			for (int i = 0; i < scores_size; i++) {
				//scores 배열 내에서 최소값의 인덱스를 min 함수에서 받아
				//해당 score과 배열 맨앞자리부터 순서대로 교체
				int min_idx = min(scores, scores_size, i);
				tmp = scores[i];
				scores[i] = scores[min_idx];
				scores[min_idx] = tmp;
			}
			cout << "학생들의 성적 오름차순 정렬 결과 : ";
			//오름차순으로 정렬된 scores 배열을 출력
			for (int i = 0; i < scores_size; i++) {
				cout << scores[i] << " ";
			}
			cout << endl;
			break;

		}
		else if (num == 2) {
			//내림차순으로 정렬하는 경우
			for (int i = 0; i < scores_size; i++) {
				//scores 배열 내에서 최대값의 인덱스를 max 함수에서 받아
				//해당 score과 배열 맨앞자리부터 순서대로 교체
				int max_idx = max(scores, scores_size, i);
				tmp = scores[i];
				scores[i] = scores[max_idx];
				scores[max_idx] = tmp;
			}
			cout << "학생들의 성적 내림차순 정렬 결과 : ";
			//내림차순으로 정렬된 scores 배열을 출력
			for (int i = 0; i < scores_size; i++) {
				cout << scores[i] << " ";
			}
			cout << endl;
			break;

		}
		else {
			cout << "1 또는 2만 입력 가능합니다" << endl;
		}
	}
	
	//학생들의 점수 총합과 평균을 출력
	double total = sum(scores, scores_size);
	cout << "학생들의 점수 총합 : " << total << endl;
	cout << "학생들의 점수 평균 : " << average(total, scores_size) << endl;

	
	return 0;
}

//sum : 학생들의 점수 총합 계산
double sum(double scores[], int s_size) {
	double s_sum = 0;
	for (int i = 0; i < s_size; i++) {
		s_sum += scores[i];
	}
	return s_sum;
}

//average : 학생들의 점수 총합을 받아 평균 계산
double average(double s_sum, int s_size) {
		return (s_sum / s_size);
}

//min : 오름차순에 쓰이는 함수로, 배열의 범위 내에서 가장 작은 값의 인덱스를 반환
int min(double scores[], int s_size, int idx) {
	int min_idx = idx;
	for (int i = idx + 1; i < s_size; i++) {
		if (scores[i] < scores[min_idx]) {
			min_idx = i;
		}
	}
	return min_idx;
}

//max : 내림차순에 쓰이는 함수로, 배열의 범위 내에서 가장 큰 값의 인덱스를 반환
int max(double scores[], int s_size, int idx) {
	int max_idx = idx;
	for (int i = idx + 1; i < s_size; i++) {
		if (scores[i] > scores[max_idx]) {
			max_idx = i;
		}
	}
	return max_idx;
}