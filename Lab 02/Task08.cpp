#include"iostream"
using namespace std;

int main() {
    int days;
    int times;
    int hottestDay;
    int coolestDay;
    float hottestAvg = 0.0;
    float coolestAvg = 0.0;

    cout<<"Enter days: ";  cin>>days;
    cout<<"Enter times: "; cin>>times;

    float * avg = new float[days]{0.0};

    int ** temp = new int*[days];
    for(int i=0; i<days; i++) {
        temp[i] = new int[times];

        cout << "Day " << i+1 << endl;
        for(int j=0; j<times; j++) {
            cout << "Temperature at time " << j+1 <<  ": ";   cin>>temp[i][j];
            avg[i] += temp[i][j];
        }
        avg[i] = avg[i] / times;

        if(hottestAvg < avg[i]) {
            hottestAvg = avg[i];
            hottestDay = i+1;
        }
        if(coolestAvg > avg[i] || i == 0) {
            coolestAvg = avg[i];
            coolestDay = i+1;
        }
    }

    cout << "\n---------------- Daily Averages ----------------\n";
    for(int i=0; i<days; i++) {
        cout << "Day " << i+1 << ": " << avg[i] << endl;
    }

    cout<<"\nDay "  << hottestDay << " is the Hottest Day with hottest average temperaure of " << hottestAvg << endl;
    cout<<"Day "  << coolestDay << " is the Coolest Day with coolestDay average temperaure of " << coolestAvg << endl;

    for(int i=0; i<days; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;
}
