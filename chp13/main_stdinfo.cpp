// main_Student_info.cpp
#include <algorithm>

#include <ios>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Student_info.h"
#include "Grad.h"

using namespace std;

int main() {
	vector<Student_info> students; // Vore 객체에 해당하는 기록을 읽고 처리
	Student_info  record;
	string::size_type maxlen = 0;

	//데이터를 읽고 저장
	while (record.read(cin)) {
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	// 학생 기록을 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	// 이름과 점수를 출력
	for (vector<Grad>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].getName()
			<< string(maxlen + 1 - students[i].getName().size(), ' ');

		try {
			double final_grade = students[i].grade(); // Student_info::grade()
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;

		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}