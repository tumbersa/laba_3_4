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
bool compare(string s1,string s2,int k) {//> true; <= false 
    bool f = false;
    switch (k) {
    case 1: {
        int n = 0;
        int i;
        for (i = 0; i < s1.length() && n < 3; i++)
        {
            if (s1[i] == ' ') n++;
        }
        string s11 = s1.substr(0, i-1);
        cout << s11<<endl;
        n = 0;
        for (i = 0; i < s2.length() && n < 3; i++)
        {
            if (s2[i] == ' ') n++;
        }
        string s22 = s2.substr(0, i - 1);
        cout << s22<<endl;
        
        for (i = 0; i < s11.length() && i < s22.length() && !f; i++) {
            if (s22[i] == ' ' && s11[i] != ' ') f = true;
            else
                if (s22[i] != ' ' && s11[i] == ' ') return f;
                else 
                if (s11[i] > s22[i]) f = true;
                else if (s11[i] < s22[i]) return f;
        }
        if (i == s22.length() && i!= s11.length()) f = true;
        if (i == s22.length() && i == s11.length()) f = true;
        return f;
    }
    break;
    case 2:
    {
        int n = 0;
        int i,i2=0;
        for (i = 0; i < s1.length() && n < 4; i++)
        {
            if (s1[i] == ' ') n++;
            if (n == 3&& s1[i]==' ') i2 = i;
        }
        string s11 = s1.substr(i2+1, i - i2 - 2);
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
    default: cout << "The wrong number"<<endl;
        return f;
    }
    return f;
}


void split(ifstream& fileL, ofstream& fileB, ofstream& fileC,int k) {
    vector <string> temp;
    string s;
    while (getline(fileL, s)) {
       // getline(fileL, s);
        temp.push_back(s);
    }
    print(temp);
   
    bool flag = true,flag2= true;//true - B; false - C
    fileB << temp[0] << '\n';
    for (int i = 1; i < temp.size(); i++) {
        if (!compare(temp[i], temp[i - 1], k)) flag = !flag;{
            if (flag) fileB << temp[i] << '\n';
            else fileC << temp[i] << '\n';
        }
        cout << compare(temp[i], temp[i-1], k) <<" "<<flag<< endl;
        
    }
    fileC.close();
    temp.clear();
    ifstream fileC1("C.bin", ios::binary);
    if (fileC1.peek()!= EOF) {
        while (getline(fileC1, s)) {
            temp.push_back(s);
        }
        fileC1.close();
        ofstream fileC2("C.bin", ios::binary);
        for (int i = 0; i < temp.size() - 1; i++)
        {
            fileC2 << temp[i] << '\n';
        }
        fileC2 << temp[temp.size() - 1];
        print(temp);
    }
    ////////////
    fileB.close();
    temp.clear();
    ifstream fileB1("B.bin", ios::binary);
    while (getline(fileB1, s)) {
        temp.push_back(s);
    }
    fileB1.close();
    ofstream fileB2("B.bin", ios::binary);
    for (int i = 0; i < temp.size() - 1; i++)
    {
        fileB2 << temp[i] << '\n';
    }
    fileB2 << temp[temp.size() - 1];
    print(temp);
}

void naturalMerge(ofstream& fileL, ifstream& fileB, ifstream& fileC, int k) {
    cout << "Merge" << endl;
    vector <string> temp1;
    string s;
    while (!fileB.eof()) {
        getline(fileB, s);
        temp1.push_back(s);
    }
    print(temp1);
    vector <string> temp2;
    while (!fileC.eof()) {
        getline(fileC, s);
        temp2.push_back(s);
    }
    print(temp2);

    int i = 1, j = 1;
    bool flag = true,flag2=true;
    vector <string> temp11, temp22;
    temp11.push_back(temp1[0]);
    temp22.push_back(temp2[0]);
    while (i < temp1.size() && j < temp2.size()) {

        while (flag)
            if (compare(temp1[i], temp1[i - 1], k)&& i != temp1.size())
            {
                temp11.push_back(temp1[i]);
                i++;
                if (i == temp1.size()) flag = false;
            }
            else flag = false;
        print(temp11);
        flag = true;
        //if (i == temp1.size()) break;

        while (flag)
            
            if (compare(temp2[j], temp2[j - 1], k) && j != temp2.size())
            {
                temp22.push_back(temp2[j]);
                j++;
                if (j == temp2.size()) flag = false;
            }
            else flag = false;
        
        print(temp22);
        flag = true;

        int i2 = 0, j2 = 0;
        while (i2 != temp11.size() && j2 != temp22.size()) {
            if (compare(temp11[i2], temp22[j2],k)) {
                if (i + j + 2 >= temp1.size() + temp2.size() && (i2== temp11.size() && j2 == temp22.size()-1 ||
                    i2 == temp11.size()-1 && j2 == temp22.size())) fileL << temp22[j2];
                else fileL << temp22[j2] << '\n';
                j2++;
            }
            else {
                if (i + j + 2 >= temp1.size() + temp2.size() && (i2 == temp11.size() && j2 == temp22.size() - 1 ||
                    i2 == temp11.size() - 1 && j2 == temp22.size())) fileL << temp11[i2] ;
                else fileL << temp11[i2] << '\n';
                i2++;
            }
        }
        if (i2 == temp11.size()) 
            while (j2 < temp22.size()) {
                if (i + j + 2 >= temp1.size() + temp2.size() && (i2 == temp11.size() && j2 == temp22.size() - 1 ||
                    i2 == temp11.size() - 1 && j2 == temp22.size())) fileL << temp22[j2] ;
                else fileL << temp22[j2] << '\n';
                j2++;
            }
        if (j2 == temp22.size())
            while (i2 < temp11.size()) {
                if (i + j + 2 >= temp1.size() + temp2.size() && (i2 == temp11.size() && j2 == temp22.size() - 1 ||
                    i2 == temp11.size() - 1 && j2 == temp22.size())) fileL << temp11[i2] ;
                else fileL << temp11[i2] << '\n';
                i2++;
            }
        temp11.clear(); temp22.clear();
       
        if (i < temp1.size())
            temp11.push_back(temp1[i]);
        i++;
       
        if (j<temp2.size())
            temp22.push_back(temp2[j]);
        j++;
        
    }
    print(temp1);
    if (j >= temp2.size() && i <= temp1.size()) {
        fileL << '\n';
        for (int i2 = i - 1; i2 < temp1.size(); i2++)
            if (i2 != temp1.size() - 1) fileL << temp1[i2] << '\n';
            else fileL << temp1[i2];
    }


    fileL.close(); fileB.close(); fileC.close();
    ifstream fL("L.bin", ios::binary);
    ofstream fB("B.bin", ios::binary);
    ofstream fC("C.bin", ios::binary);
    split(fL,fB,fC,k);
    fC.close();
    ifstream fileC1("C.bin", ios::binary);
    if (fileC1.peek() == EOF) { return;}
    else {
        ofstream fL2("L.bin", ios::binary);
        ifstream fB2("B.bin", ios::binary);
        naturalMerge(fL2,fB2,fileC1,k);
    }
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
	ofstream fileL("L.bin",ios::binary);
    if (!fileL.is_open()) {
        cout << "Cannot open file L!" << endl;
        return 1;
    }
    string s = "Петров Александр Иванович +79502234424 ул.Карла Маркса д.1";
    //fileL.write(s.c_str(), sizeof(s));
    fileL << s<<'\n';
    s = "Петрав Александр Ивановичъ +79502234423 ул.Карла Маркса д.2";
    fileL << s << '\n';
    s = "Петрова Александр Иванович +79502634424 ул.Карла Маркса д.1 кв.5";
    fileL << s << '\n';
    s = "Петров Алек Иванович +79602634424 ул.Карл Маркс д.1 кв.6";
    fileL << s << '\n';
    s = "Петров Александр Иванович +79502644424 ул.Карла Маркса д.1 кв.4";
    fileL << s ;
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
    //fileL2.read(&s1[0], sizeof(s1));
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

    split(fileL3, fileB, fileC,k);
    fileL3.close();
    fileB.close();
    fileC.close();
    ofstream fileL4("L.bin", ios::binary);
    ifstream fileB1("B.bin", ios::binary);
    ifstream fileC1("C.bin", ios::binary);
    naturalMerge(fileL4, fileB1, fileC1, k);
    fileL4.close();
    fileB1.close();
    fileC1.close();

    //ifstream fL("L.bin", ios::binary);
    //ofstream fB("B.bin", ios::binary);
    //ofstream fC("C.bin", ios::binary);

   

    //split(fL,fB,fC,k);

   
    //fC.close();
    //ifstream fC1("C.bin", ios::binary);
   
    //fL.close();
    //fB.close();
    //fC1.close();
    //ofstream fileL5("L.bin", ios::binary);
    //ifstream fileB5("B.bin", ios::binary);
    //ifstream fileC5("C.bin", ios::binary);

    //naturalMerge(fileL5, fileB5, fileC5, k);
    //fileL5.close();
    //fileB5.close();
    //fileC5.close();
    //

    //ifstream fL22("L.bin", ios::binary);
    //ofstream fB22("B.bin", ios::binary);
    //ofstream fC22("C.bin", ios::binary);


    //

    //split(fL22, fB22, fC22, k);

    //fC22.close();
    //fL22.close();
    //fB22.close();



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
