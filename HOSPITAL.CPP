/*
=========================================================================


	Name of the project   :- Hospital Management System
	Name of the developer :- Rydam Agrawal , Abhishek Srivas,Yash Sharma

=========================================================================
*/

#include <iostream.h>      // for cin , cout , function
#include <conio.h>         // for clrscr(), getch() function
#include <process.h>       // for exit function
#include <stdio.h>         // for gets() , puts() ,cprintf() function
#include <fstream.h>       // for open(),close(),write(),read(),
#include <dos.h>           // for delay() function
#include <string.h>        // For strcpy() function
					//Inclusion of header files
#define b2 textbackground(BLACK)

struct Patient
{
	      char name[30];        // To store the info about patient
	      int  age;             // To store the age
	      char Fname[30];        // To store the father name
	      char Address[80];     // To store the address of patient
	      char issue[50];       // To store the issues faced by patient
	      char Pissue[50];       // previous issues faced by patient
	      char description[200]; // Description of patient
	      int number;      //  number of patient isuued by hospital


};

struct Trans
{
	char name[30];
	double money;
	int no_IT;
	int number;

};

struct Rating
{
      int star1;
      int star2;
      int star3;
      int star4;
      int star5;
      int sumstar;
      int times;

};

class HMS
{
  public:
	int pos;
	void intro_screen(void);
	void bar(void);                 // prints a bar containing name of cinema
	void menumaker(char[][20],int); // menu maker
	int  main_menu1(void);          // user type menu
	int  main_menu2(void);          // user menu
	int  main_menu3(void);          // admin menu
	void rating(void);              // feedback from user
	void welmenu();                 // Printing the welcome menu
	void new_patient(void);         // Creat a new entry for patient
	void show_patient(void);        // show list of all patient
	void search_patient(void);      // search for patient
	void delete_patient(void);      // delete patient record
	void sort_record(void);        // sorts all records
	void transaction(void);         // Transaction history
	void strans(void);              // searching of transaction history
	void about_us(void);
	HMS()
	{
	 pos=0;
	}
};

void HMS :: intro_screen(void)
{                                            // intro_screen() open
	int p = 0 ; char ch1;              // Function variables

	introscreen_01:                           // Label for goto

		_setcursortype(_NOCURSOR);             // Hiding cursor
		ch1 = ' '; cout<< "\n\n\n\n\n";

		textcolor(DARKGRAY);
		cout<< "\n\t";       cprintf("%c",(char)201); 		//Line 1
		for( p = 0 ; p< 63 ; p++)   cprintf("%c",(char)223);
									cprintf("%c",(char)187);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 2
		textcolor(YELLOW);
cprintf("                        LIFE CARE CENTER                       ");
		textcolor(DARKGRAY);
						cprintf("%c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 3
		textcolor(YELLOW);

		textcolor(DARKGRAY);
		 cout<<"                                                               ";cprintf("%c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)199);      // Line 4
		for(p = 0; p < 63 ; p++)   cprintf("%c",(char)196);
		cprintf("%c", (char)182);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 5
		textcolor(GREEN);
		cprintf("                       MAKING LIFES BETTER                     ");
		textcolor(DARKGRAY);
		cprintf("%c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)186);           textbackground(CYAN);  //Line 6
		for(p = 0; p < 63 ; p++)   cout<<(char)32;
		b2;						cprintf("%c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 7
		textcolor(MAGENTA + BLINK);
		cprintf("                          SAVED MANY                     ");
		textcolor(DARKGRAY); cprintf("      %c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 8
		for(p = 0; p < 63 ; p++)
									cprintf("%c",(char)32);
									cprintf("%c",(char)186);

		cout<< "\n\t";       cprintf("%c",(char)186);      //Line 9
		textcolor(GREEN);    cprintf(" Founded by  ");
		textcolor(RED);  cprintf(" DUSHYANT CHANDRAVANSHI ");
		textcolor(DARKGRAY); cprintf("                          %c", (char)186);

		cout<< "\n\t";       cprintf("%c",(char)200);      // Line 10
		for(p = 0; p < 63 ; p++)
									cprintf("%c",(char)223);
									cprintf("%c",(char)188);

		cout<< "\n\n\n\n\n\n\n\t";                         //Line 11
		for(p = 0; p < 66 ; p++)   cprintf("%c",(char)196);
		cout<< "\n\t";             cprintf("%c",(char)186);
		cprintf("       Enter = Continue          %c",(char)186);
		cprintf("       Esc = Exit             %c",(char)186);

		 ch1 = getch();                       // Entering choice

		 switch(ch1)
		 {
			 case (char)13 : clrscr(); break;           // Case of Enter key

			 case (char)27 : exit(0);          // Case of Esc key
									break;

			  default      : clrscr();
									goto introscreen_01;
		 }


}					   //introscreen() close

void HMS :: bar(void)                       // bar() open
{
	 int i;

	 cout<< "\n\t";                          // Line 1
	 textcolor(LIGHTBLUE);
	 cprintf("%c",(char)201);
	  for(i = 0; i <= 62 ; i++)  cprintf("%c", (char)177);
	  cprintf("%c",(char)187);

	 cout<< "\n\t";                          // Line 2
	 textcolor(LIGHTBLUE);
	  cprintf("%c",(char)178);   textcolor(MAGENTA);
	  textbackground(WHITE);
	 cprintf("                       LIFE CARE CENTRE                        ");
	  textbackground(BLACK);
	 textcolor(LIGHTBLUE);       cprintf("%c",(char)178);

	 cout<< "\n\t";                          // Line 3
	 textcolor(LIGHTBLUE);
	 cprintf("%c",(char)200);
	 for(i = 0; i <= 62 ; i++)  cprintf("%c", (char)177);
	 cprintf("%c",(char)188);
}					   // bar() close
//----------------------------------------------------------------------------------------------
void HMS :: menumaker(char a[][20],int z )
{
	  char i= ' ';
	  int  l = 0, m = 0, p;

	 menu_01:  clrscr();
				  bar();

				  _setcursortype(_NOCURSOR);

				  cout<< "\n\n\t\t\t";
				  textcolor(BROWN);  cprintf("%c",(char)201); 		//Line 1
		for( p = 0 ; p< 31 ; p++)   cprintf("%c",(char)223);
									cprintf("%c",(char)187);


				  cout<< "\n\t\t\t"; cprintf("%c",179);
				  textcolor(GREEN);  cprintf("              MENU             ");
				  textcolor(BROWN);  cprintf("%c",179);

				  cout<< "\n\t\t\t"; cprintf("%c",200);
				  cprintf("_______________________________");
				  cprintf("%c",188);
				  cout<< "\n\t\t\t"; cprintf("%c",186);
				  cprintf("                               ");
				  cprintf("%c",186);

					switch(i)
					{
						 case 'w':
						 case 'W': pos--;
										break;

						 case 's':
						 case 'S': pos++;
										break;

					 }

					 if(pos > (z-1))  pos = 0;
					 if(pos < 0)  pos = (z-1);

					 for(l = 0; l < z ; l++)
					 {
							cout<<"\n\t\t\t";

						 if(l != pos)
						 {
						  cprintf("%c",186);
						  cout<<"      ";
						  for(m = 0; m < 20; m++)
						  {
							textcolor(YELLOW);        cprintf("%c",a[l][m]);
						  }
						 }

						 else
						 {
						  cprintf("%c",char(186));
						  textcolor(RED);   cprintf("       ");
						  textbackground(WHITE);
							for(m = 0; m < 20; m++)			cprintf("%c",a[l][m]);
							textbackground(BLACK);
						 }

						 cout<< "\t";   textcolor(BROWN); cprintf("%c",char(186));

					 }

					 cout<<"\n\t\t\t";
					 cprintf("__________________________________");


					 cout<<"\n\n\n\n\n\n\n\n\t\t";
										cprintf("_______________________________________________");
					 cout<<"\n\t\t"; cprintf("|   W = Up   |   S = Down  |   Enter = Select |");
					  i = getch();
					 if(i == (char)13) 	goto exit;

	 goto menu_01;

	 exit :
}
//---------------------------------------------------------------------------
 int HMS :: main_menu1(void)
 {

	  char option[3][20] = {"User",
									"Administrator",
									"Exit"
								  };
	  int i, flag = 0, rep = 0;

	  menumaker(option,3);


		clrscr();

					  switch(pos)
					  {
						 case 1 :
						 label01:  clrscr();char pk[8];
						  cout<< "\n\n\n\n\n\n\n\t\t";
						  textcolor(YELLOW + BLINK);
						  cprintf("Maximum 3 attempts allowed ");
						  textcolor(CYAN);
						  cout<< "\n\t\t";
						  cprintf("Enter PIN : ");
						  for(i=0;i<8;i++)
				   {
							 pk[i] = getch();
							 textcolor(RED);
							 cprintf("*");
																	  }

						  if(pk[0] == 'a')  flag++;
						  if(pk[1] == 'b')  flag++;
						  if(pk[2] == 'h')  flag++;
						  if(pk[3] == 'i')  flag++;
						 if(pk[4] == 'a')  flag++;
						 if(pk[5] == 'g')  flag++;
						 if(pk[6] == 'a')  flag++;
						 if(pk[7] == 'r')  flag++;
						 if(flag == 8)
					      {
							cout<< "\n\n\t\t";
							textcolor(GREEN);
				      cprintf("Access Granted");
							delay(1000);
							main_menu3();
						 }
						 else
						{
							cout<< "\n\n\t\t";
						      textcolor(RED);
				      cprintf("Access Denied");
							delay(1000);
							rep++;
							if(rep == 3) exit(0);
					 //safety feature
							goto label01;
						 }

										break;

								  case 0 : welmenu();
											  main_menu2();

		 case 2 :  rating();

						break;

	 }

	  return pos;

 }
//---------------------------------------------------------------------------

 int HMS :: main_menu2(void)
 {

	  char option[4][20] = { "Transaction History",
									 "View Patient",
									 "About Us",
									 "Exit"
								 };

	  pos = 0;
	 usermenu_01:
		 menumaker(option,4);
	 usermenu_02: clrscr();
					  const int pos1 = pos;
					  switch(pos1)
					  {

						 case 0 : clrscr();

									 bar();
									  strans();
									  break;

						 case 1 : clrscr();
									 bar();
									search_patient();
									  break;

						 case 2 : clrscr();
									 bar();
								       about_us();
									  break;

						 case 3:  main_menu1();
									  break;

					  }

	  char x;
	  if(pos1 != 3)
	  {
	  cout<< "\n\n\n\n\n\n\n\n\t To goto to user menu press 'Esc'";
	  x = getch();

	  if(x == (char)27) goto usermenu_01;
	  }

	  return pos;
 }


//--------------------------------------------------------------------------

 int HMS :: main_menu3(void)
 {

	 char option[7][20] = { "New Patient Record",
								     "View All Record",
								     "Delete Record",
								     "Do Payment",
								     "Exit"
								 };


	 adminmenu_01: trans1: clrscr();
						menumaker(option,5);
					  switch(pos)
					  {

						 case 0 : clrscr();
									 bar();
								       new_patient();
									  break;


						 case 1 : clrscr();
									 bar();
								       show_patient();
									  break;

						 case 2:  clrscr();
									 bar();
								     delete_patient();
									  break;


						 case 3: clrscr();
									 bar();
								      transaction();
									 break;

						 case 4:	 main_menu1();
									  break;

					  }
	  char x;
	  cout<< "\n\n\n\n\n\n\n\n\t To goto to admin menu press 'Esc'";
	  x = getch()	  ;

	  if(x == (char)27) goto adminmenu_01;
	return pos;
 }
//---------------------------------------------------------------------------
 void HMS :: rating()
 {
       Rating obj;
       fstream fobj("feedback.dat",ios::binary | ios:: in);
	 obj.times++;
	 rerate:

	 system( "cls");

	  int si;

	  cout<< "\n\t";
	  cprintf("Please rate(1-5)so that we may improve your experience next time ");
	  cout<<"\n\t";
		cin>> si;

		 switch(si)
		 {
			 case 1 :                obj.star1++;
						 obj.sumstar+=1;
						 cout<< "\n\t\t"<<(char)2<<"  "<<(char)1<<"  "<<(char)1<<"  "<<(char)1<<"  "<<(char)1;
						 break;

			 case 2 :                obj.star2++;
						 obj.sumstar+=2;
						 cout<< "\n\t\t"<<(char)2<<"  "<<(char)2<<"  "<<(char)1<<"  "<<(char)1<<"  "<<(char)1;
						 break;

			 case 3 :                obj.star3++;
						 obj.sumstar+=3;
						  cout<< "\n\t\t"<<(char)2<<"  "<<(char)2<<"  "<<(char)2<<"  "<<(char)1<<"  "<<(char)1;
						 break;

			 case 4 :                obj.star4++;
						 obj.sumstar+=4;
						  cout<< "\n\t\t"<<(char)2<<"  "<<(char)2<<"  "<<(char)2<<"  "<<(char)2<<"  "<<(char)1;
						 break;

			 case 5 :                obj.star5++;
						 obj.sumstar+=5;
						  cout<< "\n\t\t"<<(char)2<<"  "<<(char)2<<"  "<<(char)2<<"  "<<(char)2<<"  "<<(char)2;
						 break;

			 default: goto rerate;

		}


		  delay(2000);
	  exit(0);
 }
 //=====================================================================
void HMS :: welmenu()
{
		int i = 0;
	introscreen_02 :

	  clrscr();
	  _setcursortype(_NOCURSOR);				  // Hiding cursor
	  textcolor(GREEN);
	  cout<< "\n\n\n\t\t"; cprintf("            The LIFE CARE CENTRE ");
	  cout<< "\n\t\t\t";   cprintf("       CURING THOUSAND");

														  // Rotating rod

	  cout<<"\n\n\n\t\t\t\t";
	  textcolor(BLUE);      cprintf("/ WELCOME /");	  delay(10);   //Phase 1

	  cout<<"\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b";
	  textcolor(MAGENTA);   cprintf("- WELCOME -");	  delay(10);   //Phase 2

	  cout<<"\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b";
	  textcolor(BROWN);     cprintf("\\ WELCOME \\"); delay(10);   //Phase 3

	  cout<<"\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b";
	  textcolor(CYAN);      cprintf("| WELCOME |");   delay(10);   //Phase 4

	  cout<<"\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b\b \b";
	  textcolor(YELLOW);    cprintf("- WELCOME -");   delay(10);     //Phase 5

	  i++;                                   // Iteration Counter
		 if(i==50);
		 else       goto introscreen_02;


}
//-----------------------------------------------------------------------

void HMS :: new_patient()
{
	 fstream fout("patient.dat", ios :: binary | ios :: app);
	 Patient m;

	  textcolor(DARKGRAY);
	  cout<< "\n\t";
cprintf("-------------------------------------------------------------");
 cout<< "\n\t";   cprintf("Hospital Number:");  cin>> m.number;
 cout<< "\n\t"; cprintf("Enter Name of Patient    :  ");  gets(m.name);
 cout<< "\t";   cprintf("Enter age :");  cin>>m.age;
 cout<< "\t";   cprintf("Fathers Name:");  gets(m.Fname);
 cout<< "\t";   cprintf("Address:");  gets(m.Address);
 cout<< "\t";   cprintf(" Medical issue:");  gets(m.issue);
 cout<< "\t";   cprintf(" Past medical issue:");  gets(m.Pissue);
 cout<< "\t";   cprintf("Problem faced by Patient:");
 cout<< "\n\t";  gets(m.description);
 cout<< "\n\t";
cprintf("-------------------------------------------------------------");
  fout.write( (char*)&m , sizeof(m));

  fout.close();

}
//-----------------------------------------------------------------------

 void HMS :: show_patient()
{
	ifstream fin("patient.dat", ios :: binary);
	Patient m ;
	sort_record();
	while(fin.read((char*)&m,sizeof(m)))
	{
	  textcolor(DARKGRAY);
	  cout<< "\n\t";
cprintf("-------------------------------------------------------------");
cout<< "\n\t";   cprintf(" Hospital Number        :  ");  cout<< m.number;
cout<< "\n\t"; cprintf(" Name of Patient        :  ");  puts(m.name);
cout<< "\t";   cprintf(" Age of Patient         :  ");  cout<<m.age;
cout<< "\t";   cprintf(" Father's Name           :  ");  puts(m.Fname);
cout<< "\t";   cprintf(" Address                :  ");  puts(m.Address);
cout<< "\t";   cprintf(" Medical issue          :  ");  puts(m.issue);
cout<< "\t";   cprintf(" Past medical issue     :  ");  puts(m.Pissue);
cout<< "\t";   cprintf(" Description of project :  ");
cout<< '\n';  puts(m.description);
cout<< "\n\t";
cprintf("-------------------------------------------------------------");

delay(1000);
}

}

//---------------------------------------------------------------------------

void HMS :: delete_patient()
{
	 fstream fp ,fs;
	 int a;

	 Patient m;
	 fs.open("patient.dat", ios :: in | ios :: binary);
	 fp.open("temp.dat", ios :: out | ios :: binary);
	  textcolor(DARKGRAY);
	 cout<< "\n\t";
	 cprintf(" Enter Hospital Number: ");
	  cin>>a;

	  while(fs.read((char*)&m,sizeof(m)))
	  {
		 if(m.number != a )   fp.write((char*)&m,sizeof(m));

	  }

	  fp.close();
	  fs.close();
	  remove("patient.dat");
	  rename("temp.dat","patient.dat");

	  cout<< "\n\n\t\t\t RECORDS REMOVED";
	  fstream to,tn;
	  Trans ob;
	  fs.open("Trans.dat", ios :: in | ios :: binary);
	 fp.open("tem.dat", ios :: out | ios :: binary);
	  textcolor(DARKGRAY);
	 cout<< "\n\t";

	  while(fs.read((char*)&m,sizeof(m)))
	  {
		 if(m.number != a )   fp.write((char*)&m,sizeof(m));

	  }

	  fp.close();
	  fs.close();
	  remove("Trans.dat");
	  rename("tem.dat","Trans.dat");

}


//-----------------------------------------------------------------------

void HMS :: search_patient()
{
	 ifstream fin( "patient.dat", ios :: binary);
	 Patient m;
	  int x ,flag = 0;
	 textcolor(DARKGRAY);
	 cout<< "\n\t";
	 cprintf("Enter Hospital Number of PAtient to be searched :  ");
	  cin>> x;

	while( fin.read((char*)&m,sizeof(m)))
	{
		 if(x == m.number)
		 {
			 cout<< "\n\t RECORD FOUND";

			 cout<< "\n\t";
cprintf("-------------------------------------------------------------");
  cout<< "\n\t"; cprintf(" Name of movie             :  ");  puts(m.name);
  cout<< "\t";   cprintf(" Age                       :  ");  cout<<m.age;
  cout<< "\t";   cprintf(" Father Name   :  ");  puts(m.Fname);
  cout<< "\t";   cprintf(" Address                   :  ");  puts(m.Address);
  cout<< "\t";   cprintf(" Medical issue             :  ");  puts(m.issue);
  cout<< "\t";   cprintf(" Past Medical Issue        :  ");  puts(m.Pissue);
  cout<< "\t";   cprintf(" Problem Faced by Patient  :  ");
  cout<< '\n';  puts(m.description);
  cout<< "\t";   cprintf(" Hospital number           :  ");  cout<< m.number;
  cout<< "\n\t";
cprintf("-------------------------------------------------------------");
		flag++;
			break;
}
}
		if(flag == 0) cout<< "\n\n\t\t RECORD NOT FOUND";

}

//----------------------------------------------------------------------------

void HMS :: sort_record()
{
      fstream f1("patient.dat", ios :: binary | ios :: ate | ios :: in | ios:: out);
      int i = 0 ,j = 0;

      Patient obj1 , obj2;

      long size = f1.tellg() / sizeof(Patient);

      for( i = 0; i < size - 1 ; ++i)
      {
	 for(j = 0 ; j < size - (i + 1) ; ++j)
	 {
	    f1.read((char*)&obj1,sizeof(obj1));
	    f1.read((char*)&obj2,sizeof(obj2));

	    if (strcmpi(obj1.name ,obj2.name))
	    {
	       f1.seekp(-48,ios::cur);
	       f1.write((char*)&obj2,sizeof(obj2));
	       f1.write((char*)&obj1,sizeof(obj1));
	       f1.seekp(-24,ios::cur);
	    }
	 }
      }


}


void HMS :: transaction()
{
    fstream fout("Trans.dat", ios :: binary | ios :: app);
    Trans ob;
	  textcolor(DARKGRAY);
	  cout<< "\n\t";
cprintf("-------------------------------------------------------------");
 cout<< "\n\t";   cprintf("Hospital Number:");  cin>> ob.number;
 cout<< "\n\t"; cprintf("Enter Name of Patient    :  ");  gets(ob.name);
 cout<< "\t";   cprintf("Enter age :");  cin>>ob.no_IT;
 cout<< "\t";   cprintf("Total price:");  cin>>ob.money;
cprintf("\n-------------------------------------------------------------");

  fout.write( (char*)&ob , sizeof(ob));

  fout.close();

   char x;
	  cout<< "\n\n\n\n\n\n\n\n\t To goto to admin menu press 'Esc'";
	  x = getch()	  ;

	  if(x == (char)27)
	  main_menu3();
}
//----------------------------------------------------------------------------
void HMS :: strans()
{
   ifstream fin("trans.dat",ios :: binary);
	 Trans ob;
	  int x ,flag = 0;
	 textcolor(DARKGRAY);
	 cout<< "\n\t";
	 cprintf("Enter Hospital Number of Patient to be searched :  ");
	  cin>> x;

	while( fin.read((char*)&ob,sizeof(ob)))
	{
		 if(x == ob.number)
		 {
			 cout<< "\n\t RECORD FOUND";

			 cout<< "\n\t";
cprintf("-------------------------------------------------------------");
	 cout<< "\n\t";   cprintf("Hospital Number:");     cout<<ob.number;
 cout<< "\n\t"; cprintf("Enter Name of Patient    :  ");  puts(ob.name);
 cout<< "\t";   cprintf("Enter age :");  cout<<ob.no_IT;
 cout<< "\t";   cprintf("Total price:");  cout<<ob.money;
cprintf("\n-------------------------------------------------------------");
		flag++;
			break;
}
}
		if(flag == 0) cout<< "\n\n\t\t RECORD NOT FOUND";

}
void HMS :: about_us()
{
	clrscr();
	bar();

	cout<< "\n\n\t";
	cprintf(" This is to home to some of the most eminent doctors in ");
	cout<< "\n\t";
	cprintf(" the world, most of whom are pioneers in their respective areas");
	cout<< "\n\t";
	cprintf(" Here preventive health checks our customized to take into consideration   ");
	cout<< "\n\n\t";
	cprintf("  Your life style and risk factors.");
	cout<< "\n\t";

	cprintf("       Thanks for giving us a chance of serving you ");


}




//---------------------------------------------------------------------------------
void main()
{
   clrscr();
	HMS obj;

	obj.intro_screen();
	obj.bar();
	char re_HMS;
	  if(obj.main_menu1() == 1 )
	  if(obj.main_menu1() == 0 )

    getch();
}