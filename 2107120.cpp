#include<bits/stdc++.h>
#include <vector>
#include <windows.h>
#include <string>
using namespace std;
string password="1234";
class all;
class student//Student class declare
{
    string name,roll,dept,number;
    int year;
public:
    friend  class all;
    student(string, string,string, string,int);
    ~student();
    friend void byname(all &ob);
    friend void bynumber(all &ob);
    friend int update(all &ob);
    void display();
};
student :: ~student()//class student destructor
{
    cout<<"Student"<<endl;
    cout<<"Name : "<<name<<"\nRoll: "<<roll<<"\nDept: "<<dept<<"\nNumber: "<<number<<"\nInformation has removed."<<endl;
    Sleep(2000);
}
student :: student(string nam,string pos,string dep,string num,int i)//class student constructor
{
    name=nam;
    roll=pos;
    dept=dep;
    number=num;
    year=i;

}
void student :: display()//displaying student information
{
    cout<<"\nName : "<<name<<"\nRoll :"<<roll<<"\nDepartment : "<<dept<<"\nPhone Number :"<<number<<"\nSession :"<<year<<endl;
}
class teacher//Teacher class declare
{
    string name,position,dept,number;
    int id;
public:
    friend  class all;
    teacher(string nam,string pos,string dep,string num,int i);
    ~teacher();
    void display();
    friend void byname(all &ob);
    friend void bynumber(all &ob);
    friend int update(all &ob);
};
teacher :: ~teacher()//Teacher destructor
{
    cout<<"Teacher"<<endl;
    cout<<"Name : "<<name<<"\nPosition: "<<position<<"\nDept: "<<dept<<"\nNumber: "<<number<<"\nInformation has removed."<<endl;
    Sleep(2000);
}
void teacher :: display()//Displaying teacher information
{
    cout<<"\nName : "<<name<<"\nPosition :"<<position<<"\nDepartment :"<<dept<<"\nPhone Number: "<<number<<"\nID Number :"<<id<<endl;
}
teacher :: teacher(string nam,string pos,string dep,string num,int i)//Teacher constructor
{
    name=nam;
    position=pos;
    dept=dep;
    number=num;
    id=i;

}
class worker//Worker class declare
{
    string name,position,number;

public:
    friend  class all;
    worker(string,string,string);
    ~worker();
    void display();
    friend void byname(all &ob);
    friend void bynumber(all &ob);
    friend int update(all &ob);
};
worker :: ~worker()//worker destructor
{
    cout<<"Worker"<<endl;
    cout<<"Name : "<<name<<"\nPosition: "<<position<<"\nNumber: "<<number<<"\nInformation has removed."<<endl;
    Sleep(2000);
}
worker :: worker(string nam,string pos,string num)//worker constructor
{
    name=nam;
    position=pos;
    number=num;
}
void worker :: display()//Displaying worker information
{
    cout<<"\nName :"<<name<<"\nPost Of The Job :"<<position<<"\nPhone Number :"<<number<<endl;

}
class all//All class which control student,teacher,worker class
{
    vector<student*> s;
    vector<teacher*> t;
    vector<worker*> w;
public:
    void addInfo(int );
    void displayInfo(int );
    void removeInfo(string, int );
    void totalnum();
    friend int update(all &ob);
    friend void byname(all &ob);
    friend void bynumber(all &ob);
    friend void delall(all &ob,int);
};
void delall(all &ob,int temp )//delete information
{
    system("cls");
    if(temp==1)
    {
        ob.t.erase(ob.t.begin(),ob.t.end());
        cout<<"\n\n\t\tSuccessfully deleted all teacher information.";
        Sleep(2000);
    }
    else if(temp==2)
    {
        ob.s.erase(ob.s.begin(),ob.s.end());
        cout<<"\n\n\t\tSuccessfully deleted all student information.";
        Sleep(2000);
    }
    else if(temp==3)
    {
        ob.w.erase(ob.w.begin(),ob.w.end());
        cout<<"\n\n\t\tSuccessfully deleted all worker information.";
        Sleep(2000);
    }
    else
    {
        cout<<"\n\n\t\tPlease, enter valid option."<<endl<<endl;
        Sleep(2000);
    }
  system("cls");
}
void all ::removeInfo(string com,int x)//remove data
{
    int temp=0;
   system("cls");
    int i;
    if(x==1)//for teacher
    {
        if(t.size()==0)
            cout<<"\n\n\tAt first add teachers information."<<endl;
        else
        {
            for(i=0; i<t.size(); i++)
            {
                if(t[i]->number==com)
                {
                    temp=1;
                    delete(t[i]);
                    t.erase(t.begin()+i);
                }
            }
        }
        cout<<endl<<endl<<endl;
    }
    else if(x==2)//for student
    {
        if(s.size()==0)
            cout<<"\n\n\tAt first add students information."<<endl;
        else
        {
            for(i=0; i<s.size(); i++)
            {
                if(s[i]->number==com)
                {
                    temp=1;
                    delete(s[i]);
                    s.erase(s.begin()+i);
                }
            }
        }
        cout<<endl<<endl<<endl;
    }
    else if(x==3)//for worker
    {
        if(w.size()==0)
            cout<<"\n\n\tAt first add workers information."<<endl;
        else
        {
            for(i=0; i<w.size(); i++)
            {
                if(w[i]->number==com)
                {
                    temp=1;
                    delete(w[i]);
                    w.erase(w.begin()+i);
                }
            }
        }
        cout<<endl<<endl<<endl;

    }
    else
    {

        cout<<"\n\n\t\tPlease, enter valid option."<<endl<<endl;
        Sleep(2000);
    }
    if(temp==0)cout<<"\tThis number not found."<<endl<<endl;
}
int update(all &ob)//update information
{
    string s;
   system("cls");
    int j=0;
    cout<<"\n\n\tEnter number:  ";
    cin>>s;
    string n,p,d,num;
    int I;
    fflush(stdin);
    for(int i=0; i<ob.t.size(); i++) //for teacher
    {
        if(s==ob.t[i]->number)
        {
            j=1;
            cout<<"\n\tTeacher"<<endl;
            cout<<"Enter Name :";
            getline(cin,n);
            ob.t[i]->name=n;
            fflush(stdin);
            cout<<"Enter Post: ";
            getline(cin,p);
            ob.t[i]->position=p;
            fflush(stdin);
            cout<<"Enter Dept : ";
            cin>>d;
            ob.t[i]->dept=d;
            fflush(stdin);
            cout<<"Enter Number : ";
            cin>>num;
            ob.t[i]->number=num;
            fflush(stdin);
            cout<<"Enter ID(integer): ";
            cin>>I;
            ob.t[i]->id=I;
            cout<<"\n\n\t\tSuccessfully added information.";
            Sleep(2000);
            system("cls");
            return 0;
        }
    }
    for(int i=0; i<ob.s.size(); i++) //for student
    {
        if(s==ob.s[i]->number)
        {
            j=1;
            cout<<"\n\tStudent"<<endl;
            cout<<"Enter Name :";
            getline(cin,n);
            ob.s[i]->name=n;
            fflush(stdin);
            cout<<"Enter Roll: ";
            getline(cin,p);
            ob.s[i]->roll=p;
            fflush(stdin);
            cout<<"Enter Dept : ";
            getline(cin,d);
            ob.s[i]->dept=d;
            fflush(stdin);
            cout<<"Enter Number : ";
            cin>>num;
            ob.s[i]->number=num;
            fflush(stdin);
            cout<<"Enter Session: ";
            cin>>I;
            ob.s[i]->year=I;
            cout<<"\n\n\t\tSuccessfully added information.";
            Sleep(2000);
            system("cls");
            return 0;

        }
    }
    for(int i=0; i<ob.w.size(); i++) ////for worker
    {
        if(s==ob.w[i]->number)
        {
            j=1;
            cout<<"\n\tWorker"<<endl;
            cout<<"Enter Name :";
            getline(cin,n);
            ob.w[i]->name=n;
            fflush(stdin);
            cout<<"Enter Position: ";
            getline(cin,p);
            ob.w[i]->position=p;
            fflush(stdin);
            cout<<"Enter Number : ";
            getline(cin,num);
            ob.w[i]->number=num;
            fflush(stdin);
            cout<<"\n\n\t\tSuccessfully added information.";
            Sleep(2000);
           system("cls");
            return 0;
        }
    }
    if(j==0)cout<<"Sorry,does not match anyone."<<endl<<endl;
}
void all::displayInfo(int x)//displaying all information
{
   system("cls");
    int i;
    if(x==1)//for teacher
    {
        if(t.size()==0)
            cout<<"\n\n\tAt first add teachers information."<<endl;
        else
        {
            for(i=0; i<t.size(); i++)
            {
                t[i]->display();
                cout<<endl;
            }
        }
        cout<<endl<<endl<<endl;
    }
    else if(x==2)//for student
    {
        if(s.size()==0)
            cout<<"\n\n\tAt first add students information."<<endl;
        else
        {
            for(i=0; i<s.size(); i++)
            {
                s[i]->display();
                cout<<endl;
            }
        }
        cout<<endl<<endl<<endl;
    }
    else if(x==3)//for worker
    {
        if(w.size()==0)
            cout<<"\n\n\tAt first add workers information."<<endl;
        else
        {
            for(i=0; i<w.size(); i++)
            {
                w[i]->display();
                cout<<endl;
            }
        }
        cout<<endl<<endl<<endl;

    }
    else
    {
        cout<<"\n\n\t\tPlease, enter valid option."<<endl<<endl;
        Sleep(2000);
    }

}
void all::addInfo(int temp )//adding information
{
   system("cls");
    string name,position,number,dept;
    int id;
    getchar();
    if(temp==1)//for teacher
    {
        cout<<"\n\n\t\tEnter name:";
        getline(cin,name);
        cout<<"\t\tEnter post:";
        fflush(stdin);
        getline(cin,position);

        cout<<"\t\tWitch department teacher:";
        fflush(stdin);
        getline(cin,dept);
        cout<<"\t\tEnter phone number:";
        fflush(stdin);
        cin>>number;
        cout<<"\t\tEnter ID number(integer):";
        cin>>id;
        t.push_back(new teacher(name,position,dept,number,id));
        cout<<"\n\n\t\tSuccessfully added information.";
        Sleep(2000);
    }
    else if(temp==2)//for student
    {
        cout<<"\n\n\t\tEnter name:";
        getline(cin,name);
        cout<<"\t\tEnter roll:";

        fflush(stdin);
        getline(cin,position);

        cout<<"\t\tEnter department name:";
        fflush(stdin);
        getline(cin,dept);
        cout<<"\t\tEnter phone number:";
        fflush(stdin);
        cin>>number;
        cout<<"\t\tEnter session(integer):";
        cin>>id;
        s.push_back(new student(name,position,dept,number,id));
        cout<<"\n\n\t\tSuccessfully added information.";
        Sleep(2000);
    }
    else if(temp==3)//for worker
    {
        cout<<"\n\n\t\tEnter name:";
        getline(cin,name);
        cout<<"\t\tEnter post:";

        fflush(stdin);
        getline(cin,position);

        cout<<"\t\tEnter phone number:";
        fflush(stdin);
        cin>>number;
        w.push_back(new worker(name,position,number));
        cout<<"\n\n\t\tSuccessfully added information.";
        Sleep(2000);
    }
    else
    {
        cout<<"\n\n\t\tPlease, enter valid option."<<endl<<endl;
        Sleep(2000);
    }
}
int select()//selecting teacher ,student or worker
{
   system("cls");
    int op;
    cout<<"\n\n\t\t[1] Teacher"<<endl;
    cout<<"\t\t[2] Student"<<endl;
    cout<<"\t\t[3] Worker"<<endl;
    cout<<"\n\n\t\tChoose option:";
    cin>>op;
    return op;

}
//search by name
void byname(all &ob)
{
    string s;
    system("cls");
    int j=0;
    fflush(stdin);
    cout<<"\n\n\tEnter name:  ";
    getline(cin,s);
    fflush(stdin);
    for(int i=0; i<ob.t.size(); i++) //for teacher
    {
        if(s==ob.t[i]->name)
        {
            j=1;
            cout<<"\n\tTeacher"<<endl;
            cout<<"Name :"<<ob.t[i]->name<<"\nPost: "<<ob.t[i]->position<<"\nDept : "<<ob.t[i]->dept<<"\nNumber : "<<ob.t[i]->number<<"\nID: "<<ob.t[i]->id<<endl;
        }
    }
    for(int i=0; i<ob.s.size(); i++) //for student
    {
        if(s==ob.s[i]->name)
        {
            j=1;
            cout<<"\n\tStudent"<<endl;
            cout<<"Name :"<<ob.s[i]->name<<"\nRoll: "<<ob.s[i]->roll<<"\nDept : "<<ob.s[i]->dept<<"\nNumber : "<<ob.s[i]->number<<"\nSession: "<<ob.s[i]->year<<endl;

        }
    }
    for(int i=0; i<ob.w.size(); i++) //for worker
    {
        if(s==ob.w[i]->name)
        {
            j=1;
            cout<<"\n\tWorker"<<endl;
            cout<<"Name :"<<ob.w[i]->name<<"\nPosition: "<<ob.w[i]->position<<"\nNumber : "<<ob.w[i]->number<<endl;
        }
    }
    if(j==0)cout<<"Sorry,does not match anyone."<<endl<<endl;

}
void all :: totalnum()//total member
{
        system("cls");
    cout<<"\n\n\tTotal number of teacher :"<<t.size()<<endl;
    cout<<"\tTotal number of student :"<<s.size()<<endl;
    cout<<"\tTotal number of worker :"<<w.size()<<endl;
    cout<<"\tTotal number of member :"<<s.size()+w.size()+t.size()<<endl<<endl;
    Sleep(2000);
}
void bynumber(all &ob)//search by number
{
    string s;
 system("cls");
    int j=0;
    cout<<"\n\n\tEnter number:  ";
    cin>>s;
    for(int i=0; i<ob.t.size(); i++) //for teacher
    {
        if(s==ob.t[i]->number)
        {
            j=1;
            cout<<"\n\tTeacher"<<endl;
            cout<<"Name :"<<ob.t[i]->name<<"\nPost: "<<ob.t[i]->position<<"\nDept : "<<ob.t[i]->dept<<"\nNumber : "<<ob.t[i]->number<<"\nID: "<<ob.t[i]->id<<endl;
            break;
        }
    }
    for(int i=0; i<ob.s.size(); i++) //for student
    {
        if(s==ob.s[i]->number)
        {
            j=1;
            cout<<"\n\tStudent"<<endl;
            cout<<"Name :"<<ob.s[i]->name<<"\nRoll: "<<ob.s[i]->roll<<"\nDept : "<<ob.s[i]->dept<<"\nNumber : "<<ob.s[i]->number<<"\nSession: "<<ob.s[i]->year<<endl;
            break;
        }
    }
    for(int i=0; i<ob.w.size(); i++) //for worker
    {
        if(s==ob.w[i]->number)
        {
            j=1;
            cout<<"\n\tWorker"<<endl;
            cout<<"Name :"<<ob.w[i]->name<<"\nPosition: "<<ob.w[i]->position<<"\nNumber : "<<ob.w[i]->number<<endl;
            break;
        }
    }
    if(j==0)cout<<"Sorry,does not match anyone."<<endl<<endl;
}
void pass()//change password
{
    system("cls");
    int temp=4;
    string newpass,oldpass;
    while(temp--)
    {          system("cls");
        cout<<"\n\tEnter old password: ";
        cin>>oldpass;
        fflush(stdin);
        if(temp==1)
        {
           system("cls");
            cout<<"\n\n\tYou enter wrong password too many time.\n\tTry again later."<<endl;
            getchar();
            return;

        }
        if(oldpass==password)
            break;
        else{
            cout<<"\n\tWrong password. Try again.";
            Sleep(2000);
            }


    }
    cout<<"\tEnter new password: ";
    cin>>newpass;
    fflush(stdin);
    password=newpass;

    cout<<"\tYour new password is :"<<password<<endl<<endl;

}
int main()//main function
{
    all obj;
    int time=4;
    cout<<"\n\n\n\t\t Enter Your Password: ";
    while(time--)
    {
       system("cls");
        cout<<"\n\n\n\t\t Enter Your Password: ";

        string pass;
        cin>>pass;
        if(pass==password)
            break;
        if(time==1)
        {
            cout<< "\n\n\n\t\tYou Have Entered Incorrect Password Too Many Times." <<endl;
            cout<< "\t\tTry Again Later!!!!" <<endl;
            getchar();
            getchar();
            return 0;

        }
        else
        {
            cout<< "\n\n\n\t\tWrong Password.Try Again!!!!" <<endl;
            Sleep(2000);
        }
        getchar();
    }
   system("cls");
    cout<<endl<<endl<<"\t\t..............................................."<<endl;
    cout<<"\t\t|*** WELCOME TO CONTACT INFORMATION OF KUET***|"<<endl;
    cout<<"\t\t..............................................."<<endl<<endl<<endl;
    while(1)
    {
        cout<<endl;
        cout<<"\t\t[1] Add Contacts"<<endl;
        cout<<"\t\t[2] Display All Contacts"<<endl;
        cout<<"\t\t[3] Search Contacts By Name"<<endl;
        cout<<"\t\t[4] Search Contacts By Number"<<endl;
        cout<<"\t\t[5] Update Contacts"<<endl;
        cout<<"\t\t[6] Delete Contact"<<endl;
        cout<<"\t\t[7] Delete All Contacts"<<endl;
        cout<<"\t\t[8] Total Number Of Contacts"<<endl;
        cout<<"\t\t[9] Change Password"<<endl;
        cout<<"\t\t[0] Exit"<<endl<<endl<<endl<<endl;
        int op;
        cout<<"\t\tEnter which operation do you want:";
        cin>>op;
        int x;
        string c;
        switch(op)
        {
        case 0:
           system("cls");
            cout<<"\n\n\n\n\t\tSuccessfully Exit The program."<<endl;
            getchar();
            getchar();
            return 0;
            break;
        case 1:
            x=select();
            obj.addInfo(x);
            system("cls");
            break;
        case 2:
            x=select();
            obj.displayInfo(x);
            break;
        case 3:
            byname(obj);
            break;
        case 4:
            bynumber(obj);
            break;
        case 5:
            int z;
            z=update(obj);
            break;
        case 6:
            system("cls");
            int k;
            k=select();
            cout<<"\n\n\tEnter the number :";
            cin>>c;
            obj.removeInfo(c,k);
            break;
        case 7:
            system("cls");
            int l;
            l=select();
            delall(obj,l);
            break;
        case 8:
            obj.totalnum();
            break;
        case 9:
            pass();
            break;
        default:
            cout<<"Please,enter valid option."<<endl;

        }
    }
    getchar();
    getchar();
    return 0;
}
