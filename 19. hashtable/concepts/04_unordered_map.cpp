#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

class Student{
public:
    string first_name;
    string last_name;
    string roll_no;

    Student(string f, string l, string no){
        first_name = f;
        last_name = l;
        roll_no = no;
    }

    bool operator==(const Student &s) const{
        return roll_no == s.roll_no?true:false;
     }
};

class HashFn{
public:
    size_t operator()(const Student &s) const{
        return s.first_name.length() + s.last_name.length();
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<Student, int, HashFn> student_map;

    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    //add student - marks to hashmap
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    //find marks of student 4
    cout << student_map[s4] << "\n";

    //iterate over all students
    for (auto s:student_map){
        cout << s.first.first_name << " " << s.first.roll_no << "\n" << "Marks " << s.second << "\n";
    }

    return 0;
}