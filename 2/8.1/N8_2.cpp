#include <string.h>
#include <tchar.h>
#include <conio.h>
#include <locale>
#include <stdio.h>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <iostream>
 
using namespace std;
 
struct Student{
    struct{
       	char first_name[15];
    	char second_name[15];
    	char two_name[15];
    } FIO;
    struct{
         int day,month,year;
    } brithday;
    int year_o;
    struct{
      	int mark[3];
    } att;
	int ob;
    struct{
      	int mark[3];
    } vstup;
};

void GetData(Student *bd, int N){
	FILE *input;
    int i = 0, temp;
    input = fopen("test.bin","rb");
    while(i < N)
    {
    	fread(&bd[i].FIO.second_name, sizeof(string), 1, input);
        fread(&bd[i].FIO.first_name, sizeof(string), 1, input);
        fread(&bd[i].FIO.two_name, sizeof(string), 1, input);
        fread(&bd[i].brithday.day, sizeof(int), 1, input);
        fread(&bd[i].brithday.month, sizeof(int), 1, input);
        fread(&bd[i].brithday.year, sizeof(int), 1, input);      
        fread(&bd[i].year_o, sizeof(int), 1, input);
        for(int j = 0; j < 3; j++){
        	fread(&bd[i].att.mark[j], sizeof(int), 1, input);
		}
		fread(&bd[i].ob, sizeof(int), 1, input);
        for(int j = 0; j < 3; j++){
        	fread(&bd[i].vstup.mark[j], sizeof(int), 1, input);
		}
        i++;
    }
    fclose(input);
}

void ShowData(Student *bd, int N){
    for(int i = 0; i < N; i++){
    		cout << "�.�.�: " << " ";
       		cout << bd[i].FIO.second_name << " ";
       		cout << bd[i].FIO.first_name << " ";
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | ���� ��������: " << " ";
       		cout << bd[i].brithday.day << ".";
       		cout << bd[i].brithday.month << ".";
       		cout << bd[i].brithday.year << " ";
       		cout << " | ��� ��������� �����: " << " ";
       		cout << bd[i].year_o << " ";
       		cout << " | ������ � ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].att.mark[j] << " ";
			}
			cout << " | ���������: " << " ";
       		if (bd[i].ob == 1){
       			cout << "�� ";
			} else {
				cout << "��� ";
			}
       		cout << " | ������ ������������� ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].vstup.mark[j] << " ";
			}
			cout << endl;
	}
}

int Num_One(Student *bd, int N){
	int count = 0;
	FILE *output;
    output = fopen("test.bin","wb");
    
    for(int i = 0; i < N; i++){
    	if((bd[i].brithday.year <= 2002) && ((bd[i].att.mark[0] + bd[i].att.mark[1] + bd[i].att.mark[2])/3 == 5)){
    			
    	}
       	else {
       		cout << "�.�.�: " << " ";
			fwrite(&bd[i].FIO.second_name, sizeof(string), 1, output);
       		cout << bd[i].FIO.second_name << " ";
       		fwrite(&bd[i].FIO.first_name, sizeof(string), 1, output);       		    		
       		cout << bd[i].FIO.first_name << " ";
       		fwrite(&bd[i].FIO.two_name, sizeof(string), 1, output);      		
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | ���� ��������: " << " ";
			fwrite(&bd[i].brithday.day, sizeof(int), 1, output);
       		cout << bd[i].brithday.day << " ";
			fwrite(&bd[i].brithday.month, sizeof(int), 1, output);
			cout << bd[i].brithday.month << ".";
       		fwrite(&bd[i].brithday.year, sizeof(int), 1, output);     		    	
       		cout << bd[i].brithday.year << " ";
       		cout << " | ��� ��������� �����: " << " ";
			fwrite(&bd[i].year_o, sizeof(int), 1, output);
       		cout << bd[i].year_o << " ";
       		cout << " | ������ � ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				fwrite(&bd[i].att.mark[j], sizeof(int), 1, output);
				cout << bd[i].att.mark[j] << " ";
			}
       		fwrite(&bd[i].ob, sizeof(int), 1, output);
       		cout << " | ���������: " << " ";
       		if (bd[i].ob == 1){
       			cout << "�� ";
			} else {
				cout << "��� ";
			}
			cout << " | ������ ������������� ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				fwrite(&bd[i].vstup.mark[j], sizeof(int), 1, output);
				cout << bd[i].vstup.mark[j] << " ";
			}
			cout << endl;	
       		count++;
		}
	}
    fclose(output);  
	return count;
}

void Num_Two(Student *bd, int N){
    for(int i = 0; i < N; i++){
    	int flag = 0;
    	for(int j = 0; j < 3; j++){
			if (bd[i].vstup.mark[j] == 3)
				flag++;
		}
		if (flag == 1){
			cout << "�.�.�: " << " ";
       		cout << bd[i].FIO.second_name << " ";
       		cout << bd[i].FIO.first_name << " ";
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | ���� ��������: " << " ";
       		cout << bd[i].brithday.day << ".";
       		cout << bd[i].brithday.month << ".";
       		cout << bd[i].brithday.year << " ";
       		cout << " | ��� ��������� �����: " << " ";
       		cout << bd[i].year_o << " ";
       		cout << " | ������ � ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].att.mark[j] << " ";
			}
			cout << " | ���������: " << " ";
       		if (bd[i].ob == 1){
       			cout << "�� ";
			} else {
				cout << "��� ";
			}
			cout << " | ������ ������������� ���������: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].vstup.mark[j] << " ";
			}
			cout << endl;
		}
	}
}

void Write (Student *mas, int k, Student *bd, int N){
	FILE *output;
    output = fopen("test.bin","wb");
	for(int i = 0; i < N; i++){
		fwrite(&bd[i].FIO.second_name, sizeof(string), 1, output);
		fwrite(&bd[i].FIO.first_name, sizeof(string), 1, output);       		    		
    	fwrite(&bd[i].FIO.two_name, sizeof(string), 1, output);      		
    	fwrite(&bd[i].brithday.day, sizeof(int), 1, output);
		fwrite(&bd[i].brithday.month, sizeof(int), 1, output);
    	fwrite(&bd[i].brithday.year, sizeof(int), 1, output);     		
    	fwrite(&bd[i].year_o, sizeof(int), 1, output);
    	for(int j = 0; j < 3; j++){
    		fwrite(&bd[i].att.mark[j], sizeof(int), 1, output);
		}
		fwrite(&bd[i].ob, sizeof(int), 1, output);
    	for(int j = 0; j < 3; j++){
    		fwrite(&bd[i].vstup.mark[j], sizeof(int), 1, output);
		}
	}
	
	for(int i = 0; i < k; i++){
		fwrite(&mas[i].FIO.second_name, sizeof(string), 1, output);
		fwrite(&mas[i].FIO.first_name, sizeof(string), 1, output);       		    		
    	fwrite(&mas[i].FIO.two_name, sizeof(string), 1, output);      		
    	fwrite(&mas[i].brithday.day, sizeof(int), 1, output);
		fwrite(&mas[i].brithday.month, sizeof(int), 1, output);
    	fwrite(&mas[i].brithday.year, sizeof(int), 1, output);     		
    	fwrite(&mas[i].year_o, sizeof(int), 1, output);
    	for(int j = 0; j < 3; j++){
    		fwrite(&bd[i].att.mark[j], sizeof(int), 1, output);
		}
		fwrite(&bd[i].ob, sizeof(int), 1, output);
    	for(int j = 0; j < 3; j++){
    		fwrite(&bd[i].vstup.mark[j], sizeof(int), 1, output);
		}
	}
	fclose(output);
}

void add_new (Student *mas, int k){
	for (int i = 0; i < k; i++){
		cout << "������� �������: ";
		cin >> mas[i].FIO.second_name;
		cout << "������� ���: ";
        cin >> mas[i].FIO.first_name;
        cout << "������� ��������: ";
        cin >> mas[i].FIO.two_name;
        cout << "������� ���� �������� 01 01 2000: ";
        cin >> mas[i].brithday.day;
        cin >> mas[i].brithday.month;
        cin >> mas[i].brithday.year;
        cout << "������� ��� ��������� �����: ";
        cin >> mas[i].year_o;
        cout << "������� ������ � ���������: ";
        for(int j = 0; j < 3; j++){
			cin >> mas[i].att.mark[j];
		}
		cout << "������� ��������� �� � ��������� (1- ��, 0 - ���): ";
        cin >> mas[i].ob;
        cout << "������� ������ ������������� ���������: ";
        for(int j = 0; j < 3; j++){
			cin >> mas[i].vstup.mark[j];
		}
	}
}

int main()
{
	setlocale(LC_ALL,"Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);  
    
	int N, count, q;
	FILE *num;
    num = fopen("num.bin","rb");  
	fread(&N, sizeof(int), 1, num); 
    fclose(num);
    
	Student *bd = new Student[N];
	GetData(bd, N);
	while (q != -1){
		cout << "�������� ��������: " << endl;
		cout << "1 - ����������� ��� ������� " << endl;
		cout << "2 - ������� ������������, ������� ������ ���������� ���, ������� �������� �������� � ������� ���������" << endl;
		cout << "3 - ����������� ������ ������������, ���������� �� ������������� ��������� ���� ������ 3 " << endl;
		cout << "4 - �������� �����" << endl;
		cout << "-1 - �����" << endl;
		cin >> q;
		if (q == 1){
			num = fopen("num.bin","rb");  
			fread(&N, sizeof(int), 1, num); 
    		fclose(num);
    		GetData(bd, N);
			ShowData(bd, N);
		} else if (q == 2){
			count = Num_One(bd, N);
			num = fopen("num.bin","wb");
			fwrite(&count, sizeof(int), 1, num);
    		fclose(num);
		} else if (q == 3){
			Num_Two(bd, N);
		} else if (q == 4){
			int k;
			cout << "������� ���-��: ";
			cin >> k;
			Student *mas = new Student[k];
			add_new(mas, k);
			Write(mas, k, bd, N);
			num = fopen("num.bin","wb");
			count = N + k;
			fwrite(&count, sizeof(int), 1, num);
    		fclose(num);
		} else if (q == -1){
			cout << "������� ����� �������..." << endl;
		}
		getch();
		system("cls");
	}
}
