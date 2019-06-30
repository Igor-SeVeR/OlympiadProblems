#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int num;
    string name;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<Student> students;
    int num;
    while (cin >> num) {
        string name;
        cin >> name;
        students.push_back({num, name});
    }
    stable_sort(students.begin(), students.end(), [](Student a, Student b)
    {
        return a.num < b.num;
    });
    for (Student i : students)
        cout << i.num << " " << i.name << "\n";
    return 0;
}
