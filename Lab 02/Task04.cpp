#include"iostream"
using namespace std;

int* resizeArray(int* oldArr, int oldSize, int newSize) {
    if(oldSize == newSize) {
        return oldArr;
    }

    int * newArr = new int[oldSize + newSize];
    for (int i=0; i<oldSize; i++) {
        newArr[i] = oldArr[i];
    }

    delete[] oldArr;
    return newArr;
}

int main() {
    int months;
    float total = 0;
    float avg;

    cout << "Enter months: ";  cin>>months;

    int * expense = new int[months];
    for(int i=0; i<months; i++) {
        cout << "Enter expense of month " << i+1 << ": ";
        cin >> expense[i];
        total += expense[i];
    }

    string choise;
    cout << "\nDo you want to add more months(yes/no)? ";  cin >> choise;

    int new_months;
    if(choise == "yes") {
        cout << "Enter additional months: ";  cin >> new_months;

        expense = resizeArray(expense, months, new_months);

        for(int i=months; i<(months + new_months); i++) {
        cout << "Enter expense of month " << i+1 << ": ";
        cin >> expense[i];
        total += expense[i];
        }

        months += new_months;
    }

    cout << "\nTotal Expense: " << total << endl;
    cout << "Average Expense: " << total / months << endl;

    delete[] expense;
}
