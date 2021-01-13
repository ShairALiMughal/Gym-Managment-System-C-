#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include"node.h"
using namespace std;
void login();
void welcomeman();
void tofile();
void tofile1();
static int roomnumber=3;
void gotoxy(int x, int y)
{
	COORD c;
    c.X =x;
	c.Y =y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void loding(){
	system("cls");
	int r;
	int q;
	int i=0;
	int j;
	char co=178;
	gotoxy(36,3);
	cout<<"Loading..."<<endl;
	
	for(r=1,i=0,j=30; r<20,i<=100,j<=50; r++,i=i+5,j++)
	{   
		Sleep(100);
		system("color b");
		gotoxy(j,5);
		cout<<co;
		gotoxy(38,7);
		cout<<i<<" %";
	}

	tofile();tofile1();
return;
}

void welcome()
{	
	
	{
	system("mode 104");
	ifstream file;
	file.open("start.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
	string a;
	getline(file,a);
		while(!file.eof())
		{
			system("color b");
			cout<<a<<endl;
			Sleep(100);
		  getline(file,a);
		}
		file.close();	
}
}

}
void we(){

system("color b");
char arr[]={'H','i',' ','S','H','A','I','R',' ',' ','A','L','I'};
  cout<<"\n\n\n\n\t\t";
int n= sizeof(arr)/sizeof(arr[0]);
for(int j=0; j<n; j++)
{
   for(int i=0; i<=10; i++)
   Sleep(6);
   cout<<arr[j];	
}
  cout << endl;}

class newroom
  {
  	node * head , * tail;
 
  public:
 
  		newroom()
  		{
  			head=NULL;
		    tail=NULL;
			  
		}

	
	  
  	node * search(int roomno)
  	{    
  		   node * temp = new node();
		   temp = head;
		   while(temp != NULL)
		   {
		   	if(roomno==temp->roomno)
		   	{
		   		break;
			   }
			   temp=temp->next;	   	
		    if(temp==NULL)
		   {
		   	cout<<"DATA NOT FOUND";
		   	return NULL;
		   	break;
		   }
		   }
		     return temp;
	  }
	  
	  
	void freeroom(int roomno)
	  {
	  	node * free= new node();
	  	free = search(roomno);
	  	if(free==NULL)
	  	{
	  		cout<<"\n\n           Room is not Available ";
		     return;
		  }
		  else
		  {
		  	if(free->remainings>0)
		  	{
		  		cout<<"   \n\n           The Remainings Are : " <<free->remainings;    	
		  		  cout<<" \n\n        Are You Shure want to free ROom ;";cout<<"\n\n\n              ";
		  	
			  	system("pause");
				
		
			  }
		free->name="";
	  	free->pay=0;
        free->days=0;
	  	free->remainings=0;
	  	free->pas="";
	  	free->guest=0;
	  	free->phoneno="";
	  	free->address="";
	  	cout<<"\n\n\n\n              The Room Has been free it can be used next time ";
		
		  }
	  	return;
	  }
	  
	 node *searchingfreeroom()
{
	node * temp= new node();
 	temp=head;
	while(temp!=NULL)
	{
		if(temp->name=="")
		{
			break;
		}
		
	if(temp->next==NULL)
	{
		return NULL;
	}
	temp=temp->next;
	}
	return temp;
	
}

void roomsetter()
{ node * temp= new node();
temp=head;
	int i=1;
	while(temp != NULL)
	{
		temp->roomno=i;
		temp=temp->next;
		i++;
	}
return;
}


		  
	  void add_newroom(string name, int days, int pay, string pass, int guest, string phoneno, string address)
	
	  {
	  	
	  	if(days<=0)
	  	{
	  		cout<<"\nDAYS ARE EQUAL TO ZERO OR LESS THAN ZERO ";
		    return;
		  }
		  
	  	if(searchingfreeroom() != NULL)
	  	{
	  	node * freeroom=searchingfreeroom();
	  	freeroom->name=name;
	  	freeroom->days=days;
	  	  int totalamount = days*500;
	  	freeroom->remainings=totalamount-pay;
	  	freeroom->pay=pay;
	  	freeroom->pas=pass;
	  	freeroom->guest=guest;
	  	freeroom->phoneno=phoneno;
	  	freeroom->address=address;  
		return;
		  }
		  
	  	node * temp= new node();
		temp->name=name;
	  	temp->days=days;
		int totalamount = days*500;
	  	temp->remainings=totalamount-pay;
		temp->pay=pay;
	  	temp->pas=pass;
	  	temp->guest=guest;
	  	temp->phoneno=phoneno;
	  	temp->address=address;
	  	temp->next=NULL;
		  if(head==NULL)
	  	{
	  		head=temp;
	  		tail=temp;
		  }
	  	else
	  	{
	  		tail->next=temp;
	  		tail=tail->next;
		    tail=temp;
		  }
	  roomsetter();
	  }
	  
	  void userlogin(int roomno)
	  {
	  	node * user= new node();
	  	user = search(roomno);
       if(user==NULL)
	  	{
	  	       cout<<"\n              The data room no is not available";
			   return;                 	//goto main data not found
		}
		  else
		  {
		     	passwor:
		        string pass;
	  	        cout<<"\n\n       Enter the Correct password of that room no : "<<user->roomno<<" :   ";
	  	        cin.ignore();getline(cin,pass);
	  	        if(pass==user->pas)
	  	{
	  	        	// user data;
	  	cout<<"\n\n\t \t   User has been Loged in \n\n";
	  	cout<<"             The Room Number is : "<<user->roomno;
	    cout<<"\n\n           The Room Guest Name is : "<<user->name;
		cout<<"\n\n           The Room Guest to stay days : "<<user->days;	
		cout<<"\n\n           The Room Payed Money is : "<<user->pay;
		cout<<"\n\n           The Room Remaining is : "<<user->remainings;
		cout<<"\n\n           The Room Password is : "<<user->pas;
		cout<<"\n\n           The Room numbers of Guests are : "<<user->guest;
		cout<<"\n\n           The Room Phone Number is : "<<user->phoneno;
		cout<<"\n\n           The Room Guest Address is : "<<user->address;
	    return;
		}
	  	        else{
	  	        	
				  cout<<" \n         The password is incorect ";
				  
				  system("color c");
				  return;
				  }
	  }
	  
	  }

void dispallroomsbooked()
{
    node * temp= new node();
	temp=head;
	if(temp==NULL)
	  	{
	  		cout<<"\n\n           Room is not Available ";
		return;
		  }
	while(temp != NULL)
	{   cout<<"\n\n\n\n";
		if(temp->name != ""){
		
		cout<<"     The Room Number is  ::-->>  "<<temp->roomno;
		cout<<"\n\n     The Room Guest Name is : "<<temp->name;
		cout<<"\n\n     The Room Guest to stay days : "<<temp->days;	
		cout<<"\n\n     The Room Payed Money is : "<<temp->pay;
		cout<<"\n\n     The Room Remaining is : "<<temp->remainings;
		cout<<"\n\n     The Room Password is : "<<temp->pas;
		cout<<"\n\n     The Room numbers of Guests are : "<<temp->guest;
		cout<<"\n\n     The Room Phone Number is : "<<temp->phoneno;
		cout<<"\n\n     The Room Guest Address is : "<<temp->address;}
		else
		{
			cout<<" RooM is free || room no is ||  "<<temp->roomno;
		}
	  temp=temp->next;
	}
	return;
}

void update(int room)
{
	node *update = search(room);
	if(update==NULL)
	  	{
	  		cout<<"\n\n           Room is not Available ";
		    return;
		  }
	
	cout<<"\n\n          The Room no is : "<<room<<"  Guest Head Name is : "<<update->name;
	cout<<"\n\n\n            Enter The Updated data now ROom number will be same \n\n";
	cout<<"\n            Enter the Head Guest name Updated : ";cin.ignore();getline(cin,update->name);
	cout<<"\n            Enter the days to stay Updated : ";cin>>update->days;
	int total = update->days*500;
	cout<<" \n            The Total Amount to pay : "<<total ;
	cout<<"\n\n            Enter the payed Advannce Updated : ";cin>>update->pay;
	update->remainings = total - update->pay;
	cout<<"\n            Enter the Password Updated : ";cin.ignore();getline(cin,update->pas);
	cout<<"\n            Enter the Number of Guest to stay Updated : ";cin>>update->guest;
	cout<<"\n            Enter the phone number Updated : ";cin>>update->phoneno;
	cout<<"\n            Enter the Address Updated : ";cin.ignore();getline(cin,update->address);
	cout<<"\n\n\n        Data has been Updated in searched Room no \n";
return;
}

void dispallremanings()
{
node * temp= new node();
	temp=head;	
	if(temp==NULL)
	  	{
	  		cout<<"\n\n           Room is not Available ";
		return;
		  }
	int total_remainings=0;
	cout<<"\n\n\n";
	while(temp != NULL)
	{ 
	
		if((temp->remainings)>0)
		{
			cout<<" \n\n      Remainigs from room no : "<< temp->roomno<<"   Amount is :  " <<temp->remainings;
		    total_remainings = total_remainings +  temp->remainings;
		
		}
		temp=temp->next;
	
	}
	
 cout<<"\n\n\n       total remanings are :-->> "<<total_remainings;
return;
}

void searchbyadmin()
{
	
		int room;
		cout<<"        Enter the room No TO search that data:  ";cin>>room;
 	node * admin= new node();
	admin = search(room);
	if(admin==NULL)
	  	{
	  		cout<<"\n\n           Room is not Available ";
		    return;
		  }
  cout<<" \n\n      In room No : "<<room<<" data is ";
  cout<<"  \n\n     The Head Guest Name  is :  " <<admin->name;
  cout<<"  \n\n     The Remainings  are  :  " <<admin->remainings;
  cout<<"  \n\n     The Payed Pyment is  :  " <<admin->pay;
  cout<<"  \n\n     The no of Guests are :  " <<admin->guest;
  cout<<"  \n\n     The days to stay are :  " <<admin->days;
  cout<<"  \n\n     The Adress is        :  " <<admin->address;
  cout<<"  \n\n     The phone number  is :  " <<admin->phoneno;
  cout<<"  \n\n     Password of guest is :  " <<admin->pas;
   return;
	
}
 
  };
  static newroom n;   
	
  
void add()
{
	here:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("addingnew.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			
			system("color a");
			cout<<a<<endl;
		    getline(file,a);
		}
		}
		file.close();
	
	       string name; int days=0, pay=0, guest=0; string pass, phoneno, address;		
	
		    cout<<" \n\n   Assigning Room NO : " <<roomnumber; 
			cin.ignore();
			cout<<"\n\n\n      Enter the Head Name of Guest : "; getline(cin,name);	
			cout<<"\n       Enter The days to Stay : ";cin>>days;
			cout<<"\n       The Total Amount to pay : = "<<days*500;
			cout<<"\n\n       Enter The Amount pay Advance : ";cin>>pay;
			cout<<"\n       Enter The Phone no : ";	cin.ignore();getline(cin,phoneno);
			cout<<"\n       Enter The Actual Address of head guest : ";	cin.ignore();getline(cin,address);
			cout<<"\n       Enter The Numbers Members to stay : ";	cin>>guest;
			cout<<"\n       Enter The password (Guest) : ";	cin.ignore();getline(cin,pass);;
		
			n.add_newroom(name,days,pay,pass,guest,phoneno,address);
			roomnumber++;
			string choice;  int check=0;
	 	    abc:
	 		
	 		if(check==0)
		    cout<<"\n\n\n\n                  --> Data has been saved <--"; 
		    cout<<"\n\n      now enter\n\n     -->> 0 for main menu \n\n      -->> 1 for add data aggain : ";cin>>choice;
	        if(choice=="1")
	        {
		    goto here;
	        }
	        else if(choice=="0")
	        welcomeman();
	
	        else{
	        cout<<"\n     Enter the Correct option ";
            check=1;
	        goto abc;}
			
			
			}
	
 void guestlog()
 {
    b:
		system("cls");
		
	system("mode 104");
	ifstream file;
	file.open("guestlogin.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			
			system("color a");
			cout<<a<<endl;		
		  getline(file,a);
		}
		}
		file.close();
		int roomno;
		cout<<"\n\n\n\n              Enter the Room no : ";cin>>roomno;
        n.userlogin(roomno);
	    
		
		string chek ;

	      ab: 
		
		
		    cout<<"\n\n\n\n     now enter \n      -->> 0 for main menu \n      -->> 1 for login room again : ";cin>>chek;
	        if(chek=="1")
	        {
		    goto b;
	        }
	        else if(chek=="0")
	         return login();
	
	        else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
 	
  } 

void search1()
{ 
	b:
		system("cls");
		
	system("mode 104");
	ifstream file;
	file.open("searchingroom.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			
			system("color a");
			cout<<a<<endl;		
		  getline(file,a);
		}
		}
		file.close();
n.searchbyadmin();
	      ab: 
	    string chek = "";
		
		
		    cout<<"\n\n\n\n    now enter\n      -->> 0 for main menu \n      -->> 1 for search new room again : ";cin.ignore(); getline(cin,chek);
	        if(chek=="1")
	        {
		    goto b;
	        }
	        else if(chek=="0")
	         return welcomeman();
	
	        else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
	
}

void update()
{
	upd:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("update.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
  string a;
	getline(file,a);
		while(!file.eof()){
		
		system("color a");
			cout<<a<<endl;
		  getline(file,a);
    }
	}
		file.close();
		int room;
		cout<<"\n\n\n          Enter The ROom No To Update:  ";cin>>room;
		n.update(room);
			
	 ab: 
	    string k;
		
		
		    cout<<"\n\n\n\n    now enter\n\n      -->> 0 for main menu \n\n        -->> 1 for Update new room again : \n";
			 cin>>k;
			 if(k == "1")
	        {
		    goto upd;
	        }
	        else if(k == "0"){
			
	          welcomeman();
	        }
			else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
	
}
void free()
{
	fre:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("free.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
  string a;
	getline(file,a);
		while(!file.eof()){
		
		system("color a");
			cout<<a<<endl;
		  getline(file,a);
    }
	}
		file.close();
		int room;
		cout<<"\n\n\n          Enter The ROom No To free :  ";cin>>room;
		n.freeroom(room);
	    ab: 
	    string chek = "";
		
		
		    cout<<"\n\n\n\n    now enter \n          -->> 0 for main menu \n      -->> 1 for free new room again : ";cin.ignore(); getline(cin,chek);
	        if(chek=="1")
	        {
		    goto fre;
	        }
	        else if(chek=="0")
	         return welcomeman();
	
	        else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
	
}


void dispall()
{
	fre:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("dispall.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
  string a;
	getline(file,a);
		while(!file.eof()){
		
		system("color a");
			cout<<a<<endl;
		  getline(file,a);
    }
	}
		file.close();
		cout<<"\n\n\n          Displaying ALl The Booked ROoms :  ";
		n.dispallroomsbooked();
	    ab: 
	    string chek = "";
	
		    cout<<"\n\n\n\n    now enter \n           -->> 0 for main menu \n -->> 1 for free new room again : ";cin.ignore(); getline(cin,chek);
	        if(chek=="1")
	        {
		    goto fre;
	        }
	        else if(chek=="0")
	         return welcomeman();
	
	        else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
	
}

void remain()
{
	fre:
	system("cls");
	
	system("mode 130");
	ifstream file;
	file.open("remain.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
    string a;
	getline(file,a);
		while(!file.eof()){
		
		system("color a");
			cout<<a<<endl;
		  getline(file,a);
    }
	}
		file.close();
		cout<<"\n\n\n          Displaying The Remainings of Booked ROoms :  ";
		n.dispallremanings();
	    string chek ;
		
		ab: 
	    
		    cout<<"\n\n\n\n    now enter \n               -->>  0 for main menu  "; cin>>chek;
	         if(chek=="0")
	         return welcomeman();
	
	        else
			{
	        cout<<"\n     Enter the Correct option ";
	        goto ab;
			}
	
}

void welcomeman()
{
    main:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("Main.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			
			system("color a");
			cout<<a<<endl;
		  getline(file,a);
		}
		}
		file.close();

	
	int entry=0;
	cout<<"\n             Enter the Entry from 1 to 8 : ";cin>>entry;
	
	switch(entry)
{

	case 1: 
           add();
	case 2:
		 search1();
	case 3:
	       update();
	case 4:
	       free();
	case 5: 
	       dispall();
	case 6:
	       remain();       
	case 7:
	       login();
	case 8:
		   system("pause");
		    exit(1);
	default:
		
		goto main;



}
	 
	       
  	}


  void hotleinfo()
{
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("Shair.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
	string a;
	getline(file,a);
		while(!file.eof())
		{
			system("color b");
			cout<<a<<endl;
			Sleep(100);
		  getline(file,a);
		}
		}
		file.close();	

}
void wronge()
{
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("wrongp.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			
			system("color c");
			cout<<a<<endl;
			Sleep(4);
		  getline(file,a);
		}
		}
		file.close();
}


managerlogin()
{  int s=0;
	
	mlogin:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("mangerlogin.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{   
	string a;
	getline(file,a);
		while(!file.eof())
		{
			if(s==0)
			system("color a");
			cout<<a<<endl;
			Sleep(4);
		   getline(file,a);
		}
		}
		file.close();	
string password;
if(s==1)
cout<<"    -->>  You Can ALso type 0 To go back :";
cout<<"\n\n\n";
cout<<"           Enter the Correct Password of Manager : ";cin>>password;

if(password=="shair")
{
	welcomeman();
}
else if(password=="0")
{
	login();
}
else
{
 system("color c");
 s=1;
wronge();
Sleep(2500);
goto mlogin;
}
}
void login()
{
    int color=0;
	login:
	system("cls");
	
	system("mode 104");
	ifstream file;
	file.open("Login.txt");
	if(file.eof())
	{
		cout<<"file unable to open successfully:  ";
	}
	else
	{
	string a;
	getline(file,a);
		while(!file.eof())
		{  if(color==0)
			system("color b");
			cout<<a<<endl;
		  getline(file,a);
		}
		}
		file.close();	
cout<<"\n\n\n";
string login="";
cout<<"                    Enter The Selection 1 or 2 :: ";
cin>>login;
if(login=="1")
{
	system("cls");
	managerlogin();
}
else if(login=="2")
{
	system("cls");
	guestlog();
	
}

else if(login != "" && login != "1" && login != "2"  )
{
	color =1;
    system("color c");
	goto login;
}

}
void tofile()
{
	ifstream o;
	o.open("list.txt");


int remainings=0;
	string name; int days,  pay; string pass; int guest; string phoneno; string address;
	
	getline(o,name);
	getline(o,pass);
	getline(o,phoneno);
	getline(o,address);

	o>>days;
    o>>pay;
	o>>guest;
		
	n.add_newroom(name,days,pay,pass,guest,phoneno,address);

o.close();
	
}

void tofile1()
{
	ifstream o;
	o.open("list1.txt");


int remainings=0;
	string name; int days,  pay; string pass; int guest; string phoneno; string address;
	
	getline(o,name);
	getline(o,pass);
	getline(o,phoneno);
	getline(o,address);

	o>>days;
    o>>pay;
	o>>guest;
		
	n.add_newroom(name,days,pay,pass,guest,phoneno,address);

o.close();}
	


