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
    int i, temp;
    input = fopen("test.txt","r");   
	i = 0;
	
    while(i < N)
    {
        fscanf(input,"%s",&bd[i].FIO.second_name);
        fscanf(input,"%s",&bd[i].FIO.first_name);
        fscanf(input,"%s",&bd[i].FIO.two_name);
        fscanf(input,"%d",&bd[i].brithday.day);
        fscanf(input,"%d",&bd[i].brithday.month);
        fscanf(input,"%d",&bd[i].brithday.year);
        fscanf(input,"%d",&bd[i].year_o);
        for(int j = 0; j < 3; j++){
			fscanf(input,"%d",&bd[i].att.mark[j]);
		}
        fscanf(input,"%d",&bd[i].ob);
        for(int j = 0; j < 3; j++){
			fscanf(input,"%d",&bd[i].vstup.mark[j]);
		}
        i++;
    }
    fclose(input);
}

void ShowData(Student *bd, int N){
    for(int i = 0; i < N; i++){
    		cout << "Ф.И.О: " << " ";
       		cout << bd[i].FIO.second_name << " ";
       		cout << bd[i].FIO.first_name << " ";
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | Дата рождения: " << " ";
       		cout << bd[i].brithday.day << ".";
       		cout << bd[i].brithday.month << ".";
       		cout << bd[i].brithday.year << " ";
       		cout << " | Год окончания школы: " << " ";
       		cout << bd[i].year_o << " ";
       		cout << " | Оценки в аттестате: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].att.mark[j] << " ";
			}
			cout << " | Общежитие: " << " ";
       		if (bd[i].ob == 1){
       			cout << "Да ";
			} else {
				cout << "Нет ";
			}
       		cout << " | Оценки вступительных экзаменов: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].vstup.mark[j] << " ";
			}
			cout << endl;
	}
}

int Num_One(Student *bd, int N){
	int count = 0;
	FILE *output;
    output = fopen("test.txt","w");   
    ofstream fz ("test.txt");
    
    for(int i = 0; i < N; i++){
    	if((bd[i].brithday.year <= 2002) && ((bd[i].att.mark[0] + bd[i].att.mark[1] + bd[i].att.mark[2])/3 == 5)){
    			
    	}
       	else {
       		cout << "Ф.И.О: " << " ";
			fz << bd[i].FIO.second_name << " ";
       		cout << bd[i].FIO.second_name << " ";
       		fz << bd[i].FIO.first_name << " ";
       		cout << bd[i].FIO.first_name << " ";
       		fz << bd[i].FIO.two_name << " ";
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | Дата рождения: " << " ";
			fz << bd[i].brithday.day << " ";
       		cout << bd[i].brithday.day << " ";
			fz << bd[i].brithday.month << " ";
			cout << bd[i].brithday.month << ".";
       		fz << bd[i].brithday.year << ".";
       		cout << bd[i].brithday.year << " ";
       		cout << " | Год окончания школы: " << " ";
			fz << bd[i].year_o << " ";
       		cout << bd[i].year_o << " ";
       		cout << " | Оценки в аттестате: " << " ";
       		for(int j = 0; j < 3; j++){
				fz << bd[i].att.mark[j] << " ";
				cout << bd[i].att.mark[j] << " ";
			}
       		fz << bd[i].ob << " ";
       		cout << " | Общежитие: " << " ";
       		if (bd[i].ob == 1){
       			cout << "Да ";
			} else {
				cout << "Нет ";
			}
			cout << " | Оценки вступительных экзаменов: " << " ";
       		for(int j = 0; j < 3; j++){
				fz << bd[i].vstup.mark[j] << " ";
				cout << bd[i].vstup.mark[j] << " ";
			}
			fz << "\n";	
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
			cout << "Ф.И.О: " << " ";
       		cout << bd[i].FIO.second_name << " ";
       		cout << bd[i].FIO.first_name << " ";
       		cout << bd[i].FIO.two_name << " ";
       		cout << " | Дата рождения: " << " ";
       		cout << bd[i].brithday.day << ".";
       		cout << bd[i].brithday.month << ".";
       		cout << bd[i].brithday.year << " ";
       		cout << " | Год окончания школы: " << " ";
       		cout << bd[i].year_o << " ";
       		cout << " | Оценки в аттестате: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].att.mark[j] << " ";
			}
			cout << " | Общежитие: " << " ";
       		if (bd[i].ob == 1){
       			cout << "Да ";
			} else {
				cout << "Нет ";
			}
			cout << " | Оценки вступительных экзаменов: " << " ";
       		for(int j = 0; j < 3; j++){
				cout << bd[i].vstup.mark[j] << " ";
			}
			cout << endl;
		}
	}
}

void Write (Student *mas, int k, Student *bd, int N){
	FILE *output;
    output = fopen("test.txt","w");   
    ofstream fz ("test.txt");
	for(int i = 0; i < N; i++){
		fz << bd[i].FIO.second_name << " ";       		
    	fz << bd[i].FIO.first_name << " ";     		
    	fz << bd[i].FIO.two_name << " ";      		
    	fz << bd[i].brithday.day << " ";
		fz << bd[i].brithday.month << " ";
    	fz << bd[i].brithday.year << " ";       		
    	fz << bd[i].year_o << " ";
    	for(int j = 0; j < 3; j++){
			fz << bd[i].att.mark[j] << " ";
		}
    	fz << bd[i].ob << " ";
    	for(int j = 0; j < 3; j++){
			fz << bd[i].vstup.mark[j] << " ";
		}
		fz << "\n";	
	}
	for(int i = 0; i < k; i++){
    	fz << mas[i].FIO.second_name << " ";       		
    	fz << mas[i].FIO.first_name << " ";     		
    	fz << mas[i].FIO.two_name << " ";      		
    	fz << mas[i].brithday.day << " ";
		fz << mas[i].brithday.month << " ";
    	fz << mas[i].brithday.year << " ";       		
    	fz << mas[i].year_o << " ";
    	for(int j = 0; j < 3; j++){
			fz << mas[i].att.mark[j] << " ";
		}
    	fz << mas[i].ob << " ";
    	for(int j = 0; j < 3; j++){
			fz << mas[i].vstup.mark[j] << " ";
		}
		fz << "\n";
	}
	fclose(output);
}

void add_new (Student *mas, int k){
	for (int i = 0; i < k; i++){
		cout << "Введите фамилию: ";
		cin >> mas[i].FIO.second_name;
		cout << "Введите имя: ";
        cin >> mas[i].FIO.first_name;
        cout << "Введите отчество: ";
        cin >> mas[i].FIO.two_name;
        cout << "Введите дату рождения 01 01 2000: ";
        cin >> mas[i].brithday.day;
        cin >> mas[i].brithday.month;
        cin >> mas[i].brithday.year;
        cout << "Введите год окончания школы: ";
        cin >> mas[i].year_o;
        cout << "Введите оценки в аттестате: ";
        for(int j = 0; j < 3; j++){
			cin >> mas[i].att.mark[j];
		}
		cout << "Введите нуждается ли в общежитии (1- да, 0 - нет): ";
        cin >> mas[i].ob;
        cout << "Введите оценки вступительных экзаменов: ";
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
    num = fopen("num.txt","r");   
    fscanf(num,"%d", &N);
    fclose(num);
    
	Student *bd = new Student[N];
	GetData(bd, N);
	while (q != -1){
		cout << "Выберите действие: " << endl;
		cout << "1 - Распечатать всю таблицу " << endl;
		cout << "2 - Удалить абитуриентов, которые старше семнадцати лет, имеющим отличный аттестат и вывести остальных" << endl;
		cout << "3 - Распечатать список абитуриентов, получивших на вступительных экзаменах одну оценку 3 " << endl;
		cout << "4 - Добавить новых" << endl;
		cout << "-1 - ВЫХОД" << endl;
		cin >> q;
		if (q == 1){
			num = fopen("num.txt","r");   
    		fscanf(num,"%d", &N);
    		fclose(num);
			ShowData(bd, N);
		} else if (q == 2){
			count = Num_One(bd, N);
			num = fopen("num.txt","w");
			ofstream fz("num.txt");
			fz << count;
    		fclose(num);
		} else if (q == 3){
			Num_Two(bd, N);
		} else if (q == 4){
			int k;
			cout << "Введите кол-во: ";
			cin >> k;
			Student *mas = new Student[k];
			add_new(mas, k);
			Write(mas, k, bd, N);
			num = fopen("num.txt","w");
			ofstream fz("num.txt");
			count = N + k;
			fz << count;
    		fclose(num);
		} else if (q == -1){
			cout << "Нажмите любую клавишу..." << endl;
		}
		getch();
		system("cls");
	}
}
