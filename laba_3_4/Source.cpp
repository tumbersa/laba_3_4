//3 - я — естественное слияние.
//Отсортировать двоичный файл, в котором размещена информация об абонентах(ФИО, телефон, адрес) по выбранному полю.

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

void print(vector<string>vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    cout << endl;
}
bool compare(string s1, string s2, int k) {//> true; <= false 
    bool f = false;
    switch (k) {
    case 1: {
        int n = 0;
        int i;
        for (i = 0; i < s1.length() && n < 3; i++)
        {
            if (s1[i] == ' ') n++;
        }
        string s11 = s1.substr(0, i - 1);
        cout << s11 << endl;
        n = 0;
        for (i = 0; i < s2.length() && n < 3; i++)
        {
            if (s2[i] == ' ') n++;
        }
        string s22 = s2.substr(0, i - 1);
        cout << s22 << endl;

        for (i = 0; i < s11.length() && i < s22.length() && !f; i++) {
            if (s22[i] == ' ' && s11[i] != ' ') f = true;
            else
                if (s22[i] != ' ' && s11[i] == ' ') return f;
                else
                    if (s11[i] > s22[i]) f = true;
                    else if (s11[i] < s22[i]) return f;
        }
        if (i == s22.length() && i != s11.length()) f = true;
        if (i == s22.length() && i == s11.length()) f = true;
        return f;
    }
          break;
    case 2:
    {
        int n = 0;
        int i, i2 = 0;
        for (i = 0; i < s1.length() && n < 4; i++)
        {
            if (s1[i] == ' ') n++;
            if (n == 3 && s1[i] == ' ') i2 = i;
        }
        string s11 = s1.substr(i2 + 1, i - i2 - 2);
        cout << s11 << endl;
        n = 0;
        for (i = 0; i < s2.length() && n < 4; i++)
        {
            if (s2[i] == ' ') n++;
            if (n == 3 && s2[i] == ' ') i2 = i;
        }
        string s22 = s2.substr(i2 + 1, i - i2 - 2);
        cout << s22 << endl;
        for (i = 0; i < s11.length() && i < s22.length() && !f; i++) {
            if (s11[i] > s22[i]) f = true;
            else if (s11[i] < s22[i]) return f;
        }
        if (i == s22.length() && i == s11.length()) f = true;
    }
    break;
    case 3:
    {
        int n = 0;
        int i;
        for (i = 0; i < s1.length() && n < 4; i++)
        {
            if (s1[i] == ' ') n++;
        }
        string s11 = s1.substr(i);
        cout << s11 << endl;
        n = 0;
        for (i = 0; i < s2.length() && n < 4; i++)
        {
            if (s2[i] == ' ') n++;
        }
        string s22 = s2.substr(i);
        cout << s22 << endl;

        for (i = 0; i < s11.length() && i < s22.length() && !f; i++) {
            if (s22[i] == ' ' && s11[i] != ' ') f = true;
            else
                if (s22[i] != ' ' && s11[i] == ' ') return f;
                else
                    if (s11[i] > s22[i]) f = true;
                    else if (s11[i] < s22[i]) return f;
        }
        if (i == s22.length() && i != s11.length()) f = true;
        if (i == s22.length() && i == s11.length()) f = true;
        return f;
    }
    break;
    default: cout << "The wrong number" << endl;
        return f;
    }
    return f;
}


void split(ifstream& fileL, ofstream& fileB, ofstream& fileC,int& l1,int& l2, int k) {
    string s1, s2;
 
    getline(fileL, s1);
    fileB << s1 << '\n';
    bool flag = true;//true - B; false - C
    l1 = 0;
    l2 = 1;
    while (getline(fileL, s2)) {
        cout << s1 << endl << s2 << endl << endl;
        if (!compare(s2, s1, k)) flag = !flag; {
            if (flag) {
                fileB << s2 << '\n';
                l2++;
            }
            else {
                fileC << s2 << '\n';
                l1++;
            }
        }
        cout << compare(s2, s1, k) << " " << flag << endl;
        s1 = s2;
    }

    fileL.close();

    fileC.close();

    ifstream fileC1("C.bin", ios::binary);
    int i = 0;
    if (fileC1.peek() != EOF) {
        ofstream fileL3("L.bin", ios::binary);
        while (i < l1) {
            getline(fileC1, s1);
            cout << s1 << endl;
            if (i != l1 - 1) fileL3 << s1 << '\n';
            else fileL3 << s1;
            i++;
        }
        cout << endl;
        fileC1.close();
        fileL3.close();
        ifstream fileL4("L.bin", ios::binary);
        ofstream fileC2("C.bin", ios::binary);
        i = 0;
        while ( i < l1)
        {
            getline(fileL4, s1);
            cout << s1 << endl;
            if (i != l1 - 1) fileC2 << s1 << '\n';
            else fileC2 << s1;
            i++;
        }
        cout << endl;
        fileL4.close();
    }
    ////////////


    ofstream fileL5("L.bin", ios::binary);
    fileB.close();

    i = 0;
    ifstream fileB1("B.bin", ios::binary);
    while (i<l2) {
        getline(fileB1, s1);
        cout << s1 << endl;
        if (i != l2 - 1) fileL5 << s1 << '\n';
        else fileL5 << s1;
        i++;
    }
    cout << endl;
    fileB1.close();
    fileL5.close();
    ifstream fileL6("L.bin", ios::binary);
    ofstream fileB2("B.bin", ios::binary);
    i = 0;
    while (i<l2)
    {
        getline(fileL6, s1);
        cout << s1 << endl;
        if (i != l2 - 1) fileB2 << s1 << '\n';
        else fileB2 << s1;
        i++;
    }
    cout << endl;
    fileL6.close();
}

void naturalMerge(ofstream& fileL, ifstream& fileB, ifstream& fileC,int&l1,int& l2, int k) {
    cout << "Merge" << endl;
    
   
    string x1, x2, y1, y2;
    int i = 0, j = 0;//temp2 l1- C; temp1 l2 -B
    getline(fileB,x2);
    getline(fileC, y2);
    x1 = x2; y1 = y2;
    cout << x2 << endl << y2<<endl;
    while (i < l2 && j < l1) {
        if (compare(y2, x2, k)) {
            if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                fileL << x2;
            else fileL << x2 << '\n';
            x1 = x2;
            i++;
            if (i != l2) {
                getline(fileB,x2);
                if (compare(x1, x2, k)) {
                    if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                        fileL << y2;
                    else fileL << y2 << '\n';
                    y1 = y2;
                    j++;
                    if (j != l1) {
                        getline(fileC,y2);
                        while (!compare(y1, y2, k)) {
                            if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                                fileL << y2;
                            else fileL << y2 << '\n';
                            j++;
                            y1 = y2;
                            if (j != l1) getline(fileC, y2);
                            else break;
                        }
                    }
                    else break;
                }
            }
        }
        else
            if (!compare(y2, x2, k)) {
                if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                    fileL << y2;
                else fileL << y2 << '\n';
                y1 = y2;
                j++;
                if (j != l1) {
                    getline(fileC, y2);
                    if (compare(y1, y2, k)) {
                        if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                            fileL << x2;
                        else fileL << x2 << '\n';
                        x1 = x2;
                        i++;
                        if (i != l2) {
                            getline(fileB, x2);
                            while (!compare(x1, x2, k)) {
                                if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                                    fileL << x2;
                                else fileL << x2 << '\n';
                                i++;
                                x1 = x2;
                                if (i != l2) getline(fileB, x2);
                                else break;
                            }
                        }
                        else break;
                    }
                }
            }


    }
    if (j >= l1 && i < l2)
        while (i != l2) {
            if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                fileL << x2;
            else fileL << x2 << '\n';
            cout << x2 << endl;
            getline(fileB, x2);          
            i++;
        }
    if (i >= l2 && j < l1)
        while (j != l1) {
            cout << y2 << endl;
            if (i == l2 && j == l1 - 1 || i == l2 - 1 && j == l1)
                fileL << y2;
            else fileL << y2 << '\n';
            getline(fileC, y2);     
            j++;
        }

    fileL.close(); fileB.close(); fileC.close();
    ifstream fL("L.bin", ios::binary);
    ofstream fB("B.bin", ios::binary);
    ofstream fC("C.bin", ios::binary);
    l1 = 0, l2 = 0;
    split(fL, fB, fC,l1,l2, k);
    fC.close();
    ifstream fileC1("C.bin", ios::binary);
    if (fileC1.peek() == EOF) { return; }
    else {
        ofstream fL2("L.bin", ios::binary);
        ifstream fB2("B.bin", ios::binary);
        naturalMerge(fL2, fB2, fileC1,l1,l2, k);
    }
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    ofstream fileL("L.bin", ios::binary);
    if (!fileL.is_open()) {
        cout << "Cannot open file L!" << endl;
        return 1;
    }
    string s = "Петров Александр Иванович +79502234424 ул.Карла Маркса д.1";

    fileL << s << '\n';
    s = "Петрав Александр Ивановичъ +79502234423 ул.Карла Маркса д.2";
    fileL << s << '\n';
    s = "Петрова Александр Иванович +79502634424 ул.Карла Маркса д.1 кв.5";
    fileL << s << '\n';
    s = "Петров Алек Иванович +79602634424 ул.Карл Маркс д.1 кв.6";
    fileL << s << '\n';
    s = "Петров Александр Иванович +79502644424 ул.Карла Маркса д.1 кв.4";
    fileL << s;
    fileL.close();

    vector <string> ot;
    ifstream fileL2("L.bin", ios::binary);
    if (!fileL2.is_open()) {
        cout << "Cannot open file L!" << endl;
        return 1;
    }
    string s1;
    while (!fileL2.eof()) {
        getline(fileL2, s1);
        ot.push_back(s1);
    }

    fileL2.close();
    cout << "Before" << endl;
    print(ot);

    ofstream fileB("B.bin", ios::binary);
    if (!fileB.is_open()) {
        cout << "Cannot open file B!" << endl;
        return 1;
    }

    ofstream fileC("C.bin", ios::binary);
    if (!fileB.is_open()) {
        cout << "Cannot open file C!" << endl;
        return 1;
    }

    ifstream fileL3("L.bin", ios::binary);
    if (!fileL3.is_open()) {
        cout << "Cannot open file L3!" << endl;
        return 1;
    }
    ///
    int k = 1;
    int l1 = 0, l2 = 0;
    split(fileL3, fileB, fileC,l1,l2, k);
    fileL3.close();
    fileB.close();
    fileC.close();
    ofstream fileL4("L.bin", ios::binary);
    ifstream fileB1("B.bin", ios::binary);
    ifstream fileC1("C.bin", ios::binary);
    naturalMerge(fileL4, fileB1, fileC1,l1,l2, k);
    fileL4.close();
    fileB1.close();
    fileC1.close();


    ot.clear();
    ifstream fileL22("L.bin", ios::binary);
    if (!fileL22.is_open()) {
        cout << "Cannot open file L!" << endl;
        return 1;
    }
    while (!fileL22.eof()) {
        getline(fileL22, s1);
        ot.push_back(s1);
    }

    fileL22.close();
    cout << "After" << endl;
    print(ot);


    ifstream fC11("C.bin", ios::binary);
    if (fileC1.peek() == EOF) { cout << "Empty file C" << endl; }


    return 0;
}
