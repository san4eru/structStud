#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstring>
#include <string>
	
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
    char group[10];
    int year_p;
    struct{
      	char dis[3][15];
      	char mark[3][19];
    } sem1;
    struct{
      	char dis[3][15];
      	char mark[3][19];
    } sem2;
};

void GetData(Student *bd,int N){
	
    for (int i = 0; i < N; i++){
    	cout << "Фамилия: ";
        cin >> bd[i].FIO.first_name;
        cout << "Имя: ";
		cin >> bd[i].FIO.second_name;
        cout << "Отчество: ";
		cin >> bd[i].FIO.two_name;
        cout << "Дата рождения (01 01 2000): ";
		cin >> bd[i].brithday.day;
        cin >> bd[i].brithday.month;
        cin >> bd[i].brithday.year;
        cout << "Год поступления: ";
		cin >> bd[i].year_p;
        cout << "Группа (БИСО-04-18): ";
        cin >> bd[i].group;
        cout << "1 семестр" << endl;
        for (int j = 0; j < 3; j++){
        	cout << "Название дисциплины: ";
        	cin >> bd[i].sem1.dis[j];
			cout << "Оценка: ";
			cin >> bd[i].sem1.mark[j];
		}
		cout << "2 семестр" << endl;
        for (int j = 0; j < 3; j++){
        	cout << "Название дисциплины: ";
        	cin >> bd[i].sem2.dis[j];
			cout << "Оценка: ";
			cin >> bd[i].sem2.mark[j];
		}
    }
}


void ShowData(Student *bd, int N){
        cout << "                   ФИО студента" << setw(50 - strlen("                   ФИО студента")) << "|";
        cout << " Дата рождения " << "|";
        cout << " Год поступления " << "|";
        cout << "   Группа   "<<  "|";
        cout << " Дисциплины и оценки в 1-ом семестре " << "|";
        cout << " Дисциплины и оценки в 2-ом семестре " << "|" << endl;
        
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
 		
        for (int i=0; i < N; i++){
            cout << "  " <<bd[i].FIO.first_name << " " << bd[i].FIO.second_name << " " << bd[i].FIO.two_name << setw(46 - strlen(bd[i].FIO.second_name) - strlen(bd[i].FIO.first_name) - strlen(bd[i].FIO.two_name)) <<  "|";
            
			int lg_d = bd[i].brithday.day, lg_m = bd[i].brithday.month;
            if ((lg_d <= 9) && (lg_m <= 9)){
            	cout << "     " << bd[i].brithday.day << "." << bd[i].brithday.month << "." << bd[i].brithday.year << setw(3) <<  "|";
			} else if (((lg_d > 9) && (lg_m <= 9)) || ((lg_d <= 9) && (lg_m > 9))){
				cout << "    " << bd[i].brithday.day << "." << bd[i].brithday.month << "." << bd[i].brithday.year << setw(3) <<  "|";
			} else {
				cout << "   " << bd[i].brithday.day << "." << bd[i].brithday.month << "." << bd[i].brithday.year << setw(3) <<  "|";
			}
            
            cout << "       " << bd[i].year_p << setw(7) <<  "|";
            cout << " " << bd[i].group <<  " |";
			cout << " " << bd[i].sem1.dis[0] << " --> ";
			cout << bd[i].sem1.mark[0] << setw(32 - strlen(bd[i].sem1.mark[0]) - strlen(bd[i].sem1.dis[0])) << " |";
			cout << " " << bd[i].sem2.dis[0] << " --> ";
			cout << bd[i].sem2.mark[0] << setw(32 - strlen(bd[i].sem2.mark[0]) - strlen(bd[i].sem2.dis[0])) << " |" << endl;
            for (int j = 1; j < 3; j++){
				cout << setw(50) << "|" << setw(16) << "|" << setw(18) << "|" << setw(14) << "| " << bd[i].sem1.dis[j] << " --> ";
				cout << bd[i].sem1.mark[j] << setw(32 - strlen(bd[i].sem1.mark[j]) - strlen(bd[i].sem1.dis[j])) << " |";
				
				cout << " " << bd[i].sem2.dis[j] << " --> ";
				cout << bd[i].sem2.mark[j] << setw(32 - strlen(bd[i].sem2.mark[j]) - strlen(bd[i].sem2.dis[j])) << " |" << endl;	
			}
        	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
       cout << endl;
}

void Sort(Student *bd,int N){
	Student sort[0];
	for (int i = 0; i < N-1; i++){
	    for (int g = i+1; g < N; g++){
	        if(bd[i].brithday.year > bd[g].brithday.year){
	            sort[0] = bd[i];
	            bd[i] = bd[g];
	            bd[g] = sort[0];
	            continue;
	        }
	        if(bd[i].brithday.year == bd[g].brithday.year && bd[i].brithday.month > bd[g].brithday.month){
	            sort[0] = bd[i];
	            bd[i] = bd[g];
	            bd[g] = sort[0];
	            continue;
	        }
	        if (bd[i].brithday.year == bd[g].brithday.year && bd[i].brithday.month == bd[g].brithday.month && bd[i].brithday.day > bd[g].brithday.day){
            	sort[0] = bd[i];
            	bd[i] = bd[g];
            	bd[g] = sort[0];
        	}
    	}
	}
}

int main(){
    setlocale(LC_ALL,"");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	
	const int N = 5;
    Student *bd = new Student[10];
    
	GetData(bd, N); 
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t                                                                              Список группы:" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    ShowData(bd, N);
    Sort(bd, N);
    cout << endl << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; 
	cout << "\t                                                               Список группы упорядоченный по дате рождения :" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	ShowData(bd, N);
}
