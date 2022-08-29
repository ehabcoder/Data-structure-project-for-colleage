#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include <windows.h>
#include <ctime>
using namespace std;
int number=0;//the number of the enter wrong password
int number2=0;
int no1=0;//the

bool isAlph(string s){ //chech if string is alphabetical or not
for(int i=0; i<s.length(); i++){
    if((int(s[i])>=0&&int(s[i])<=59)||(int(s[i])>122))
        return false;
        }
    return true;
}
bool isDigit(string n){//return true if string is number;
    for(int i=0; i<n.length(); i++){
    if((int(n[i])>=0&&int(n[i])<=9)||(int(n[i])>=97&&int(n[i])<=122))
        return false;
        }
    return true;
}
double toInt(string n){
    stringstream vortex(n);
    int x=0;
    vortex>>x;
    return x;
}
int main_exit;
struct date{
    int month,day,year;
    };

struct details{
    string name;
    int id_no,age;
    int experiance;
    string address;
    string nationality;
    double phone;
    date DOB;
    int salary;
    };
//linked list
struct node{
    details emp;
    node *next;
};
node *start = NULL;

node *new_acc(node *start);
void menu(void);
void close(void);
void see(node*);
void erase(node*);
int edit(node*);
void view_list(node*);
void view_salary(node*start);
int main()
{

    char pass[25], password[25]="vortex";
    ttt:
        system("color 8");
    cout<<"\n\n\t\tEnter the password to login: "; cin>>pass;
    if (strcmp(pass,password)==0){
        cout<<"\n\nPassword Match!\nLOADING";
        for(int i=0;i<=6;i++)
        {
            Sleep(250);
            cout<<".";
        }
                system("cls");
            menu();
        }

    else{
                number++;
        if(number==3){
            system("cls");
             system("color c");
             for(int i=1;i<=30;i++){
            cout<<"\n\n\t\t\tyou have entered a wrong password many time please try after 30 sec:\n\n ";
            cout<<"\t\t\t\t\t\t********:"<<i<<":********";
           Sleep(1000);
            system("cls");}
            goto ttt;
        }
        else if(number==6){
                system("color c");
                cout<<"\t\tSorry! you can't try again .\n\t\t\t";close();
                return 0;
        }
        else{
            cout<<"\n\nWrong password!!\a\n";
            login_try:
                cout<<"Enter 1 to try again and 0 to exit:";
                cin>>main_exit;

                if (main_exit==1){
                        system("cls");
                        main();
                }

                else if (main_exit==0){
                system("cls");
                close();
                }

                else{
                cout<<"\nInvalid!";
                Sleep(1000);
                system("cls");
                goto login_try;
                }

        }
        }


                return 0;
}

void menu(void){
    int choice;
    again:
    system("cls");
    system("color 2");
    cout<<"\n\n\t\t\t________EMPLOYEES ACCOUNT SYSTEM________";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.Check the details of existing account\n\t\t4.Removing existing account\n\t\t5.View customer's list\n\t\t6.view the salary\n\t\t7.exit.\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;
    system("cls");

             switch(choice)
    {
        case 1:start = new_acc(start);
        break;
        case 2:edit(start);
        break;
        case 3:see(start);
        break;
        case 4:erase(start);
        break;
        case 5:view_list(start);
        break;
        case 6: view_salary(start);
        break;
        case 7: close();
        break;
        }
        if(choice==8)
            exit(0);
        else
        goto again;
}

void close(void){
    system("color 3");
    cout<<"\n\n\n\nThis Project was developed by Vortex team!\nthank you for your time.\n\n\n\n";
    getch();

}
//create new account
node *new_acc(node *start){
string n="1";
cout<<"\n\t\t\t\xB2\xB2\xB2 ADD EMPLOYEE\xB2\xB2\xB2\n\n";


while(n!="-1"){
if(start==NULL){
    node *ptr, *new_node;
    new_node = new node;
    cout<<"\t\t\tEnter the employee name: ";
  	x:
  	string na ; cin>>na;
  	if(!isAlph(na)||na.size()<3){
      cout<<"\t\t\tPlease enter a valid name: ";
      goto x;
    }
  else
    new_node->emp.name=na;
    cout<<"\t\t\tEnter the Experience: ";
    www:
        string qq; cin>>qq;
        if(!isDigit(qq)){
            cout<<"\t\t\tPlease enter a valid Experience: ";
      goto www;
           }
         else{
            int yyy=toInt(qq);
            new_node->emp.experiance=yyy;
         }

    cout<<"\t\t\tEnter the employee id_no: ";
  	y:
  	string n; cin>>n;
  	if(!isDigit(n)){
     cout<<"\t\t\tPlease enter a valid id: ";
      goto y;
    }
  else{
    int num = toInt(n);
    new_node->emp.id_no = num;

  }
    cout<<"\t\t\tEnter the employee age: ";
  	h:
  	string a; cin>>a;
  		if(!isDigit(a)){
     	cout<<"\t\t\tPlease enter a valid age: ";
     	 goto h;
   	 }
  else{
    int num = toInt(a);
    new_node->emp.age = num;
  }
    cout<<"\t\t\tEnter the employee address: ";
    g:
    string add; cin>>add;
    if(isDigit(add)){
        cout<<"\t\t\tPlease enter a valid address: ";
        goto g;
    }
    else
        new_node->emp.address=add;

    cout<<"\t\t\tEnter the employee nationality: ";
    t:
    string nat; cin>>nat;
    if(isDigit(nat)){
        cout<<"\t\t\tPlease enter a valid nationality: ";
        goto t;
    }
    else
        new_node->emp.nationality=nat;
    cout<<"\t\t\tEnter the employee phone: ";
    p:
        string ph; cin>>ph;
            if(isAlph(ph)||ph.size()<11){
            cout<<"\t\t\tPlease enter a valid Phone number: ";
            goto p;
        }
    else{
        double phoneN = toInt(ph);
        new_node->emp.phone = phoneN;

    }
    cout<<"\t\t\tEnter the employee date of birth: \n";
    ff:
    string d,m,y;
    cout<<"\t\t\t\tDay: "; cin>>d;
    cout<<"\t\t\t\tMonth: "; cin>>m;
    cout<<"\t\t\t\tyear: "; cin>>y;
    int dd,mm,yy; dd=toInt(d), mm=toInt(m), yy=toInt(y);
    if((!(isDigit(d)&&isDigit(m)&&isDigit(y)))||dd>31||dd<=0||mm>12||mm<=0||yy>2000){
        cout<<"\t\t\tPlease enter a valid date of birth: \n";
        goto ff;
    }
    else{
        new_node->emp.DOB.day = dd;
        new_node->emp.DOB.month = mm;
        new_node->emp.DOB.year = yy;

    }
    new_node->next = NULL;
    start = new_node;
}
else{
    node *new_node, *ptr;
    new_node = new node;
    ptr = start;

    while(ptr->next!=NULL)
        ptr=ptr->next;

    ptr->next = new_node;
    new_node->next = NULL;

    cout<<"\t\t\tEnter the employee name: ";
  	xx:
  	string naa ; cin>>naa;
  	if(!isAlph(naa)||naa.size()<3){
      cout<<"\t\t\tPlease enter a valid name: ";
      goto xx;
    }
  else
    new_node->emp.name=naa;
    cout<<"\t\t\tEnter the employee Experience: ";
       wwwo:
        string qqo; cin>>qqo;
        if(!isDigit(qqo)){
            cout<<"\t\t\tPlease enter a valid Experience: ";
      goto wwwo;
           }
         else{
            int yyyo=toInt(qqo);
            new_node->emp.experiance=yyyo;
         }
    cout<<"\t\t\tEnter the employee id_no: ";
  	yy:
  	string n; cin>>n;
  	if(!isDigit(n)){
     cout<<"\t\t\tPlease enter a valid id: ";
      goto yy;
    }
  else{
    int num = toInt(n);
    new_node->emp.id_no = num;

  }
    cout<<"\t\t\tEnter the employee age: ";
  	hh:
  	string a; cin>>a;
  		if(!isDigit(a)){
     	cout<<"\t\t\tPlease enter a valid age: ";
     	 goto hh;
   	 }
  else{
    int num = toInt(a);
    new_node->emp.age = num;
  }
    cout<<"\t\t\tEnter the employee address: ";
    gg:
    string add; cin>>add;
    if(isDigit(add)){
        cout<<"\t\t\tPlease enter a valid address: ";
        goto gg;
    }
    else
        new_node->emp.address=add;

    cout<<"\t\t\tEnter the employee nationality: ";
    tt:
    string nat; cin>>nat;
    if(isDigit(nat)){
        cout<<"\t\t\tPlease enter a valid nationality: ";
        goto tt;
    }
    else
        new_node->emp.nationality=nat;
    cout<<"\t\t\tEnter the employee phone: ";
    pp:
        string ph; cin>>ph;
            if(isAlph(ph)||ph.size()<11){
            cout<<"\t\t\tPlease enter a valid Phone number: ";
            goto pp;
        }
    else{
        double phoneN = toInt(ph);
        new_node->emp.phone = phoneN;

    }
    cout<<"\t\t\tEnter the employee date of birth: \n";
    f:
    string d,m,y;
    cout<<"\t\t\t\tDay: "; cin>>d;
    cout<<"\t\t\t\tMonth: "; cin>>m;
    cout<<"\t\t\t\tyear: "; cin>>y;
    int dd,mm,yy; dd=toInt(d), mm=toInt(m), yy=toInt(y);
    if((!(isDigit(d)&&isDigit(m)&&isDigit(y)))||dd>31||dd<=0||mm>12||mm<=0||yy>2000){
        cout<<"\t\t\tPlease enter a valid date of birth: \n";
        goto f;
    }
    else{
        new_node->emp.DOB.day = dd;
        new_node->emp.DOB.month = mm;
        new_node->emp.DOB.year = yy;

    }

}
cout<<"\n\tEnter -1 to end or any key to continue: ";
cin>>n;
system("cls");
}
return start;
}
void see(node *start){
    cout<<"\n\t\t\t\t\xB2\xB2\xB2 VIEW DETAILS \xB2\xB2\xB2\n\n";
    cout<<"\tEnter the id for the employee that you want to see his details: ";
    int id; cin>>id;
    node *ptr;
    ptr = start;
    while(ptr->emp.id_no!=id && ptr->next!=NULL)
        ptr = ptr->next;
    if(ptr->emp.id_no==id){
    cout<<"\n\t\t\tthe employee name is: ";
    cout<<ptr->emp.name;
    cout<<"\n\t\t\tthe employee Experience is: ";
    cout<<ptr->emp.experiance;
    cout<<"\n\n\t\t\tthe employee id_no: ";
    cout<<ptr->emp.id_no;
    cout<<"\n\t\t\tthe employee age: ";
    cout<<ptr->emp.age;
    cout<<"\n\t\t\tthe employee address: ";
    cout<<ptr->emp.address;
    cout<<"\n\t\t\tthe employee nationality: ";
    cout<<ptr->emp.nationality;
    cout<<"\n\t\t\tthe employee phone: ";
    cout<<ptr->emp.phone;
    cout<<"\n\t\t\tthe employee date of birth: ";
    cout<<"\n\t\t\t\tDay: ";
    cout<<ptr->emp.DOB.day;
    cout<<"\n\t\t\t\tMonth: ";
    cout<<ptr->emp.DOB.month;
    cout<<"\n\t\t\t\tyear: ";
    cout<<ptr->emp.DOB.year<<"\n\n\t\t\t";
    }
    else{
        cout<<"\t\t\tThis id not exist.\n\n\n";
    }
    system("pause");//pause the consol till you press any key
}

int edit(node *start){
    string n;
    cout<<"\n\t\t\t\t\xB2\xB2\xB2 EDITING \xB2\xB2\xB2\n\n";
    node *ptr;
    cout<<"\n\tEnter the id for the employee that you want to edit it:  ";
    po:
    string id; cin>>id;
    if(isAlph(id)){
        cout<<"\n\t\t\tPlease enter a valid id: ";
        goto po;
    }
    else{
    int idi = toInt(id);
    ptr = start;
    while(ptr->emp.id_no!=idi&&ptr->next!=NULL)
        ptr = ptr->next;
    int choice;
    again:
    cout<<"\n\tEnter -1 to finish editing\n\twhat do you want to edit in this employee: ";
    cout<<"\n\t\t1.name\n\t\t2.id\n\t\t3.age\n\t\t4.address\n\t\t5.nationality\n\t\t6.phone number\n\t\t7.date of birth\n\t\t\t\t";
    cin>>choice;
    switch(choice){
    case 1: {cout<<"\n\t\t\tEnter the new name: ";
            string nam;
            kk:
            cin>>nam;
            if(isDigit(nam)||nam.size()<3){//check if string is alphabetical or not
                cout<<"\n\t\t\tPlease enter a valid name: ";
                goto kk;
            }else{
            ptr->emp.name=nam;
            }}
        break;
    case 2:{ cout<<"\n\t\t\tEnter the new id: ";
             string iid;
             jj:
             cin>>iid;
             if(isAlph(iid)){
                cout<<"\n\t\t\tPlease enter a valid name: ";
                goto jj;
             }
             else{
                int iiid = toInt(iid);
                ptr->emp.id_no=iiid;}
            }
        break;
    case 3: {cout<<"\n\t\t\tEnter the new age: ";
            string ag;
            aa:
            cin>>ag;
            if(isAlph(ag)){
                cout<<"\n\t\t\tPlease enter a valid age: ";
                goto aa;
            }
            else{
                int aag = toInt(ag);
                ptr->emp.age=aag;
            }
            }
        break;
    case 4: {cout<<"\n\t\t\tEnter the new address: ";
             string adr;
             ss:
             cin>>adr;
             if(isDigit(adr)){
                cout<<"\n\t\t\tPlease enter a valid address: ";
                goto ss;
             }
             else{
              ptr->emp.address=adr;
              }}
        break;
    case 5: {
            cout<<"\n\t\t\tEnter the new nationality: ";
             string nati;
             oo:
             cin>>nati;
             if(isDigit(nati)){
                cout<<"\n\t\t\tPlease enter a valid nationality: ";
                goto oo;
             }
             else{
                ptr->emp.nationality=nati;
            }
            }
        break;
    case 6: {cout<<"\n\t\t\tEnter the new phone number: ";
             string num;
             hj:
             cin>>num;
             if(isAlph(num)||num.size()<11){
                cout<<"\n\t\t\tPlease enter a valid Phone number: ";
             }
             else{
                int nuum = toInt(num);
                ptr->emp.phone=nuum;
            }}
        break;
    case 7: {
        cout<<"\n\t\t\tEnter the new Date of birth: "; string day,month,year;
                fg:
                cout<<"\n\t\t\t\tDay: ";cin>>day;
                cout<<"\n\t\t\t\tMonth: ";cin>>month;
                cout<<"\n\t\t\t\tYear: ";cin>>year;
                int dd,mm,yy; dd=toInt(day), mm=toInt(month), yy=toInt(year);
                if((!(isDigit(day)&&isDigit(month)&&isDigit(year)))||dd>31||dd<=0||mm>12||mm<=0||yy>2000){
                    cout<<"\t\t\tPlease enter a valid date of birth: ";
                goto fg;
                }
    else{
          ptr->emp.DOB.day=dd;
            ptr->emp.DOB.month=mm;
            ptr->emp.DOB.year=yy;
            }
            }
        break;
    case 8 :{cout<<"\n\t\t\tEnter the Experience:"; string exx;
                fgx:
                int ddf=toInt(exx);
                if(!isAlph(exx)){
                    cout<<"\t\t\tPlease enter a valid the Experience: ";
                goto fgx;
                }
    else{
          ptr->emp.experiance=ddf;
            }
            }
        break;
    default: break;
        }
    cout<<"\t\t\tEnter -1 to finish editing\n\t\t\tOR do you want to edit in this employee again if yes enter any key: ";
    cin>>n;
    if(n=="-1")
        return 0;
    else
        goto again;
    }
}

void erase(node* start){
    cout<<"\n\t\t\t\xB2\xB2\xB2 DELETING \xB2\xB2\xB2\n\n";
    node *ptr, *preptr;
    cout<<"\t\t\t\n Enter the id for the employee that you want to delete it: ";
    int id; cin>>id;
    ptr = start;
    preptr = ptr;
    while(ptr->emp.id_no!=id){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    delete ptr;
    cout<<"\t\t\t The employee that his id is "<<id<<" has been deleted\n";
    system("pause");
}

void view_list(node *start){
    node *ptr;
    ptr = start;
    int i=1;
    if(start==NULL){
        cout<<"\t\t\t not found the employee\n";
        system("pause");
        menu();
    }else if(start->next==NULL)
    {
        cout<<"\n\t\t\t "<<i;
        cout<<"\n\t\t\tthe employee name is: ";
        cout<<ptr->emp.name;
        cout<<"\n\n\t\t\tthe employee id_no: ";
        cout<<ptr->emp.id_no;
        cout<<"\n\t\t\tthe employee age: ";
        cout<<ptr->emp.age;
        cout<<"\n\t\t\tthe employee address: ";
        cout<<ptr->emp.address;
        cout<<"\n\t\t\tthe employee nationality: ";
        cout<<ptr->emp.nationality;
        cout<<"\n\t\t\tthe employee phone: ";
        cout<<ptr->emp.phone;
        cout<<"\n\t\t\tthe employee date of birth: ";
        cout<<"\n\t\t\t\tDay: ";
        cout<<ptr->emp.DOB.day;
        cout<<"\n\t\t\t\tMonth: ";
        cout<<ptr->emp.DOB.month;
        cout<<"\n\t\t\t\tyear: ";
        cout<<ptr->emp.DOB.year<<"\n\n\t\t\t";
        ptr = ptr->next;
        i++;
        cout<<"_________________________________________\n";
    }
    else{
    while(ptr->next!=NULL){
        cout<<"\n\t\t\t "<<i;
        cout<<"\n\t\t\tthe employee name is: ";
        cout<<ptr->emp.name;
        cout<<"\n\n\t\t\tthe employee id_no: ";
        cout<<ptr->emp.id_no;
        cout<<"\n\t\t\tthe employee age: ";
        cout<<ptr->emp.age;
        cout<<"\n\t\t\tthe employee address: ";
        cout<<ptr->emp.address;
        cout<<"\n\t\t\tthe employee nationality: ";
        cout<<ptr->emp.nationality;
        cout<<"\n\t\t\tthe employee phone: ";
        cout<<ptr->emp.phone;
        cout<<"\n\t\t\tthe employee date of birth: ";
        cout<<"\n\t\t\t\tDay: ";
        cout<<ptr->emp.DOB.day;
        cout<<"\n\t\t\t\tMonth: ";
        cout<<ptr->emp.DOB.month;
        cout<<"\n\t\t\t\tyear: ";
        cout<<ptr->emp.DOB.year<<"\n\n\t\t\t";
        ptr = ptr->next;
        i++;
        cout<<"_________________________________________\n";
    }}
    system("pause");
}
void view_salary(node*start){
    node *ptr;
    ptr=start;
 cout<<"\t\t\tEnter the employee id_no: ";
  	oy:
  	    int num1;
  	string no; cin>>no;
  	if(!isDigit(no)){
     cout<<"\t\t\tPlease enter a valid id: ";
      goto oy;
    }
  else{
    num1 = toInt(no);
  }
 while(ptr->emp.id_no!=num1 && ptr->next!=NULL)
        ptr = ptr->next;
    if(ptr->emp.id_no==num1){
    cout<<"\n\t\t\tthe employee name is: ";
    cout<<ptr->emp.name;
    cout<<"\n\t\t\tthe employee Experience is: ";
    cout<<ptr->emp.experiance;
    if(ptr->emp.experiance>=0&&ptr->emp.experiance<=2){
        cout<<"\n\t\t\tthe employee salary is: ";
            ptr->emp.salary=5000;
         cout<<ptr->emp.salary;}
    else if(ptr->emp.experiance>3&&ptr->emp.experiance<=5){
         cout<<"\n\t\t\tthe employee salary is: ";
            ptr->emp.salary=8000;
         cout<<ptr->emp.salary;}
     else if(ptr->emp.experiance>5&&ptr->emp.experiance<10){
         cout<<"\n\t\t\tthe employee salary is: ";
            ptr->emp.salary=12000;
         cout<<ptr->emp.salary;}
     else{
         cout<<"\n\t\t\tthe employee salary is: ";
            ptr->emp.salary=15000;
         cout<<ptr->emp.salary;}
       }
    else{
        cout<<"\t\t\tThis id not exist.\n\n\n";
    }
    cout<<"\n";
    system("pause");//pause the consol till you press any key
}


