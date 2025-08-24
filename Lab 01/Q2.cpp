#include "iostream"
using namespace std;

class Exam{
    string name;
    string examDate;
    float * score;

public:
    void setName(string n) { name = n; }
    void setDate(string d) { examDate = d; }
    void setScore(float s) { 
        delete score;    // delete old memory
        score = new float(s);  
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << *score << endl << endl;     
    }

    ~Exam() {
        delete score;
    }
};

int main() {
    Exam e1;

    e1.setName("Areeba");
    e1.setDate("12th Aug 2025");
    e1.setScore(90);
    cout << "Exam 1\n";
    e1.displayDetails();

    Exam e2 = e1;
    cout << "Exam 2\n";
    e2.displayDetails();
}
