#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

char un[20];
char sid[20];
char ft[20];


class Admin
{
private:
int totitem, price[10];
char name [20];
char fmenu [10][10], retype [20];
char passwd [20], rpasswd [20];

protected:
char mobile [15], mail [50],stallid [20];

public:
char restid [15];

public:
//this function authenticates the login of both admin and food stall portal users
int login(){

if((strcmp(::un,restid))==0)
{
    cout<<"\nEnter the Login Password: ";
    int len=0;
    len=strlen(passwd);
    char inputpasswd [20];
    for(int i=0;i<len;i++){
        inputpasswd [i]=getch();
        cout<<"#";
        }
        int i;
    inputpasswd[i]=0;
    if ((strcmp(::un,restid)==0)&&(strcmp(passwd, inputpasswd)==0))
    return 1;
    else
    return 0;

}
else
return 0;
}

//This function helps in password recovery with the help of unique keyword provided by admin

int recover(){
    //cout<<"\nThe Input Username is "<<::un;
    char key [20];
    if(strcmp(:: un, restid)==0){
        cout<<"\nEnter the Unique Keyword (Provided by Admin):";
        cin>>key;
        if ((strcmp(key, rpasswd)==0))
        {
            cout<<"\n You are a Valid user.";
            cout<<"\n YourPassword is"<< passwd;
            cout<<"\n Please Exit to login again";  
            return 1;
        }

        else
        return 0;
    }
    else
    return 0;
}

void getredata()
{
    cout<<"\nEnter the Food Stall Name:";
    gets(name);
    cout<<"\nEnter the Food Stall ID: ";
    cin>>restid;
    cout<<"\nEnter the Mobile Number: ";
    gets (mobile);
    cout<<"\nEnter the E-Mail ID: ";
    gets (mail);
    cout<<"\nEnter the Stall Unique ID:";
    gets (stallid);
    cout<<"\nFood Stall Food Options Possible are \n1.South-Indian\n2.Continental\n3.Chinese\n4.Thailand\n5.Multiple";
    int foodtype;
    cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
    cin>>foodtype;
    if (foodtype==1) 
    strcpy(retype, "South Indian");
    else if(foodtype==2) 
    strcpy(retype, "Continental");
    else if (foodtype==3) 
    strcpy(retype, "Chinese");
    else if (foodtype=4)
    strcpy(retype, "Thailand");
    else 
    strcpy(retype, "Multiple");
    cout<<"\nEnter the Food Menu Items: ";
    int totitem;
    cin>> totitem;
    for(int i=0; i<totitem; i++){
        cout<< "\nEnter the Food Item " << i+1 << "Name: ";
        
        cin>>fmenu [i];
        cout<< "Enter the price of the Food" << i+1<< "INR:";
        cin>> price[i];
        }
    cout<<"\nCreate Your Login Password: ";
    cin>>passwd;
    cout<<"\nEnter the Unique Keyword to Recover Password: ";
    cin>>rpasswd;
    cout<<"\nPlease note your UserName is ID, i.e. "<<restid<<"\n";
}

void redisplay()
{
    cout<<"\nFood Stall Name : "<<name;
    cout<<"\nFood Stall ID : "<<restid;
    cout<<"\nFood Stall Mobile No. : "<<mobile;
    cout<<"\nFood Stall E-Mail ID : "<<mail;
    cout<<"\nFood Stall Food Menu Total Items: "<<totitem; 
    for(int i=0;i<totitem;i++){
    cout<<"\n\tFood Item: "<<1+1<<": "<<fmenu [i]<<":: Price:"<<price [i];
    }
    if(totitem==0)
    cout<<"(None Food Items Specified... )";
}

int reprofile(){
  if ((strcmp(::un, restid)==0)){
    cout<<"\nFood Stall Name : "<<name;
    cout<<"\nFood Stall Mobile :"<<mobile;
    cout<<"\nFood Stall Food Items Type :-"<<retype;
    return 1;
  }
  else
  return 0;
}

int knowremenu ()
{
 if ((strcmp(::un, restid)==0)){
    cout<<"\nFood Stall Food Items Type:-"<<retype;
    cout<<"\nFood Stall Total fmenus:-"<<totitem;
     for(int i=0;i<totitem;i++){
        cout<<"\n\tFood Item: "<<i+1<<": "<<fmenu [i]<<" :: Price: "<<price[i];
        }
        return 1;
    }
  else
return 0;
}

void addremenu()
{
if((strcmp(::un, restid)==0))
{
    cout<<"\nEnter the New Food Item: ";
    cin>>fmenu [totitem];
    cout<<"\nEnter the Price of new Food Item: ";
    cin>>price [totitem];
    totitem++;
    cout<<"\n\nNew fmenu Added Successfully...";
}
}

//this function helps a food stall portal user to delete a menu
void delremenu (){
    knowremenu();
    int de=0;
    if((strcmp(::un, restid)==0)){
        if(totitem==0|| totitem<0) 
        {
            totitem=0;
            cout<<"\n None fmenu Exists....";
            getch();
            exit(0);
        }
        cout<<"\nEnter the fmenu No. to be Delete: ";
        cin>> de;
        if(de==totitem){
            totitem--;
            strcpy(fmenu[totitem], "");
            price[totitem]=0;
        }
        else if(totitem==1){
            totitem=0;
            strcpy(fmenu[totitem], "");
            price[0]=0;
        }
        else{
            de--;
            strcpy(fmenu[totitem], "");
            for(int p=de; p<totitem; p++){
                strcpy(fmenu[p], fmenu[p+1]);
                price[p]=price[p+1];
            }
            totitem--;
        }
        cout<< "\n Records Updated Successfully...";
    }
}    
//this function helps a food stall portal user to modify the personal profile

void modreprofile()
{
    if ((strcmp(::un, restid)==0)){
    cout<<"\nThe Profile Details are";
    cout<<"\n 1. Food Stall E-Mail : "<<mail;
    cout<<"\n 2. Food Stall Mobile : "<<mobile;
    cout<<"\n 3. Food Stall Type : "<<retype;
    int g=-1;
    cout<<"\n\nEnter the Detail No. to be Modified: ";
    cin>>g;
    if( g==1){
        char nmail[50];
        cout<<"\nEnter the New Mail Address: ";
        strcpy(mail,nmail);
        cout<<"\nRecords Updated Successfully....";
        }
    else if(g==2){
        char nmobile[15];
        cout<<"\nEnter the New Mobile No. : ";
        gets(nmobile);
        strcpy(mobile, nmobile);
        cout<<"\nRecords Updated Successfully....";
    }
    else if(g==3){
        char nretype [20];
        cout<<"\nFood Stall Food Options Possible are \n1.South-Indian\n2.Continental\n3.Chinese\n4.Thailand\n5.Multiple";
        int foodtype;
        cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
        cin>>foodtype;
        if (foodtype==1)
        strcpy(nretype, "South Indian");
       else if (foodtype==2)
       strcpy(nretype, "Continental");
       else if (foodtype==3) 
       strcpy(nretype, "Chinese");
      else if(foodtype==4)
      strcpy(nretype, "Thailand");
      else
      strcpy(nretype, "Multiple");
    strcpy(nretype, retype);
    cout<< "\nRecords Updated Successfully....";
    }
    else
    cout<<"\n Invalid Input Provided....";
    }

}

int knowremenutocustomer()
{
    if((strcmp(::sid, stallid)==0))
    {
        cout<<"\nFood Stall Name ::"<<name;
        cout<<"\nFood Stall Unique ID ::" << stallid;
        cout<<"\nFood Stall Food Menu Type ::"<<retype;
        cout<<"\nFood Stall Total Food Menu Items: "<<totitem; 
        for(int i=0;i<totitem;i++){
        cout<<"\n\tFood Item "<<i+1<<": "<<fmenu[i]<<" :: Price: "<<price[i];
        }
        return 1;
    }
    else
    return 0;
}
void redisplaytocustomer(){
     cout<<"\nFood Stall Name ::"<<name;
        cout<<"\nFood Stall Unique ID ::" << stallid;
        cout<<"\nFood Stall Total Food Menu Items: "<<totitem; 
        for(int i=0;i<totitem;i++){
        cout<<"\n\tFood Item "<<i+1<<": "<<fmenu[i]<<" :: Price: "<<price[i];
        }


        if(totitem==0)
        cout<< "(None Food Items Specified...)";
 }
int searchbyfoodtype()
    {
        if((strcmp( ::ft, retype)==0))
        {
            cout<<"\n Food Stall Name ::"<<name;
            cout<<"\n Food Stall Unique ID ::"<<stallid;
            cout<<"\n Food Stall Total Food Items :-"<<totitem;
            for(int i=0;i<totitem;i++)
            {
                cout<<"\n\tFood Item "<<i+1<<": "<<fmenu[i]<<" :: Price: "<<price[i];
            }
            return 1;
        }
        else
        return 0;
    }
    void invalid_input()
    {
        cout<< "\n Invalid Input Provided...."; 
        getch();
        system("CLS");

        cout<< "\n\n\n\t\t\tThank You";
    }

}a,f;


class MainMenu
{
    public:
    void admin_call(){
        char adminuser [20],adminpass [20];
        cout<<"\n\t\t\tWelcome To Admin Login Portal ";
        cout<<"\n\nEnter the UserName: ";
        cin>>adminuser;
        cout<<"\nEnter the Password:";
        int k;
         for( k=0;k<8;k++){
            adminpass [k]=getch();
            cout<<"*";
         }
         getch();

         adminpass [k]=0;
         if ((strcmp(adminuser, "admin")==0)&&(strcmp(adminpass, "password")==0 ))
         {
            system("CLS");
;
         }
         else{
            cout<<"\n\n\t\t\t Invalid Access to Portal";
            cout<<"\n\n\t\t\t\tThank You !!!";
            //getch();
            exit(0);
         }
         int tmp;
         char opera='y';
         do{
            cout<<"\n\t\t\t\tWelcome To Admin Panel";
            cout<<"\n\nPress 1 to Add Single Food Stall with record";
            cout<<"\nPress 2 to Add Multiple Food Stalls with record";
            cout<<"\nPress 3 to View All Food Stalls with records ";
            cout<<"\nPress 4 to Delete a Food Stall with Record ";
            cout<<"\n\tEnter Your Choice: ";
            cin>>tmp;
            system("CLS");
;
            if (tmp==1)//for inserting a single Food Stall record 
            {
                cout<<"\nEnter the Details :- ";
                fstream fs;
                fs.open("rainfo.txt", ios::in| ios::out|ios::ate);
                a.getredata();
                fs.write((char *) &a, sizeof (Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully...";
                }//for inserting the single Food Stall records
            if (tmp==2)//for inserting multiple food stall records
            {
                int m=0;
                fstream fs;
                fs.open("rainfo.txt",ios::in | ios::out|ios::ate);
                do
                {
                    cout<<"\nEnter the Details :- ";
                    a.getredata();
                    fs.write((char *)&a, sizeof (Admin));
                    cout<<"Press 0 if you want to Enter More Records: ";
                    cin>>m;
                    }while (m==0);
                    fs.close();
                    cout<<"\nRecord Entered Successfully...";
                }//for inserting multiple food stall records 
            if (tmp==3)//to view all food stall records
            {
                fstream fs;
                fs.open("rainfo.txt", ios::in);
                fs.seekg(0);
                while(!fs.eof())
                { 
                    fs.read((char *) &a, sizeof (Admin));
                    a.redisplay();
                } 
                fs.close();
            }//to view all food stall records

       if (tmp==4)//for deleting a food stall record
       {
        char tmpfaid [15];
        int de=0, result=-1;
        cout<<"\nEnter the Food Stall ID. :- ";
        cin>>tmpfaid;
        fstream fs;
        fs.open("rainfo.txt",ios::in);
        fstream fsl;
        fsl.open("fanewinfo.txt", ios::out|ios::ate);
        while(!fs.eof())
        {
            fs.read((char *)&a, sizeof (Admin));
            result=strcmp(tmpfaid,a.restid);
            if (result==0)
            de=1;
          else
          fsl.write((char *)&a, sizeof(Admin));
        }
    if (de==1)
    cout<<"\nRecord Deleted Successfully...";
    else
    cout<<"\nRecord not found....";
fs.close();
fsl.close();
remove ("rainfo.txt");
rename("fanewinfo.txt", "rainfo.txt");

}//for deleting a food stall record

//getch();
cout<<"\n\nPress y; For More Operations otherwise n:";
cin>>opera;
if (opera!='y')
{
    //getch();
    system("CLS");

    cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!";
    //getch();
}//closing of thank you
}while (opera=='Y' || opera=='y');
}
void r_call()
{
    system("CLS");

    char un [20];
    int val, s = 0;
    cout<<"\n\t\t\tWelcome to Food Stall Login Page";
    cout<<"\n\nEnter the UserName:";
    cin>>::un;
    fstream fs;
    fs.open("rainfo.txt", ios::in |ios::binary);
    fs.seekg(0);
    while(!fs.eof()){
        val=-1;
        fs.read((char *) &f, sizeof (Admin));
        val=f.login();
        if ( val ==1){
            s=1;
            break;

        }

}

fs.close();
if (s==1)
{
    system("CLS");

}//if first login is valid
if (s!=1)//if first login is invalid
{
   system("CLS");

    int ho=0;
    cout<<"\n\n\t\tYour Login Credentials are In-Correct";
    cout<<"\nThe UserName is Your ID/restid.";
    cout<<"\nThe Password is Case-Sensitive.";
    cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login";
    cout<<"\nEnter the Choice:";
    cin>>ho;
    if (ho == 1 ) //recover password
    { 
        cout<<"Enter the UserName:-";
        cin>>::un;
        fstream fs;
        fs.open("rainfo.txt",ios::in| ios::binary);
        fs.seekg(0);
        int re, su=-1;
        while(!fs.eof()){
            re = -1;
            fs.read((char *)&f, sizeof (Admin));
            re=f.recover();
            if (re==1){
                su=1;
                break;
            }
         }

            fs.close();
            if (su==1)
            {
                //getch();
                system("CLS");

                cout<<"\n\n\n\t\t\t\tThank You !!!";
                //getch();
                exit(0);
            }
            else
            {
                cout<<"\nInvalid User.";
                //getch();
                exit(0);
            }
    }
    if (ho==2)
    {
        cout<<"\n\nEnter the UserName:";
        cin>>::un;
        fstream fs;
        fs.open("rainfo.txt", ios::in|ios::binary);
        fs.seekg(0);
        int suc=-1, valu;

        while(!fs.eof()){
            valu=-1;
            fs.read((char *)&f, sizeof (Admin));
            valu=f.login();
            if (valu==1){
                suc=1;
                break;
            }
        }
        fs.close();
        if (suc==1)
        {
            system("CLS");

        }
        else
        {
             //getch();
            cout<<"\n You are an Invalid User...";
            cout<<"\nThank You !!!";
            //getch();
            exit(0);
            exit(0);
        }

    }
    if(ho !=1 && ho!=2)
    {
        cout<<"\n\n Invalid Input Provided...";
        cout<<"\nThank You !!!";
        //getch();
        exit(0);
    }

}

//Beginning of the Food Stall main menu
char con='y';
do{
   system("CLS");

    cout<<"\n\t\t\t\tWelcome to Food Stall Portal";
    cout<<"\n\n\t\t\t\t\t\t Your userId is: "<<::un;
    cout<<"\n\nPress 1 to view Your Profile";
    cout<<"\nPress 2 to know your Food Menu(with Price)";
    cout<<"\nPress 3 to Add a Food Menu";
    cout<<"\nPress 4 to Delete a Food Menu";
    cout<<"\nPress 5 to Modify Your Profile";
    int choice;
    cout<<"\nEnter Your Choice: ";
    cin>>choice;
    if (choice==1)// view a food stall record
    {
        fstream fs;
        fs.open("rainfo.txt", ios::in);
        fs.seekg(0);
        int x;
        while(!fs.eof()){
            x=0;
            fs.read((char *)&f, sizeof (Admin));
            f.reprofile();
            if (x==1)
            break;
        }
        fs.close();
    }

    if (choice==2)//to view the food stall record
    {
        fstream fs;
        fs.open("rainfo.txt", ios::in);
        fs.seekg(0);
        int y;
        while(!fs.eof()){
            y=0;
            fs.read((char *)&f, sizeof (Admin));
            int y=f.knowremenu();
            if (y==1)
            break;
        }
        fs.close();
    }

    if(choice==3){ // Add an item in food stall menu
        fstream fs;
        fstream fs1;
        fs.open("rainfo.txt", ios::in);
        fs1.open("tmprainfo.txt", ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof()){
            fs.read((char *)&f, sizeof (Admin));
            f.addremenu();
            fs1.write((char *)&f, sizeof (Admin));

        }
        fs.close();
        fs1.close();
        remove("rainfo.txt");
        rename("tmprainfo.txt", "rainfo.txt");
    }
    if(choice==4)// Delete an item in food stall menu
    {
        fstream fs;
        fs.open("rainfo.txt", ios::in| ios::binary);
        fstream fs1;
        fs1.open("tmprainfo.txt", ios::out|ios::ate);
        fs.seekg(0);
        while(!fs.eof()){
            fs.read((char *)&f, sizeof (Admin));
            f.delremenu();
            fs1.write((char *)&f, sizeof (Admin));
        }
        fs.close();
        fs1.close();
        remove("rainfo.txt");   
        rename("delrainfo.txt", "rainfo.txt");
    }

    if(choice==5){// Modify the food stall profile
        fstream fs;
        cout<<"Enter the unique ID of the food stall: ";
        cin>> un;
        fs.open("rainfo.txt", ios::in|ios::binary);
        fs.seekg(0);
        fstream fs1;
        fs1.open("tmprainfo.txt", ios::out|ios::ate);
        
        while(!fs.eof()){
            fs.read((char *)&f, sizeof (Admin));
            f.modreprofile();
            fs1.write((char *)&f, sizeof (Admin));
        }
        fs.close();
        fs1.close();
        remove("rainfo.txt");
        rename("tmprainfo.txt", "rainfo.txt");

    }
    if(choice<1 || choice>5)
    cout<<"\n Invalid Input Provided !!!";
    cout<<"\n\n\t\t\t\t Enter to continue";

    getch();
    cout<<"\n\n Press Y to continue ; otherwise n:";
    cin>>con;
    if(con!='y' && con!='Y')
    {   system("CLS");

        cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!";
        getch();
        exit(0);
    } 
}while(con=='y' || con=='Y');
}



void customer_call(){
    char moreop;
    system("CLS");

    do
    {
        system("CLS");

        cout<<"\n\n\t\t\tWelcome to Customer Panel";
        cout<<"\n\n\t\t\t\t\t\t Guest Login";
        cout<<"\n\nPress 1 to View All Food Stall/Food Stall Details.";
        cout<<"\nPress 2 to Search a Stall by Stall unique ID.";
        cout<<"\nPress 3 to Search a Food Stall (Depending on Taste)";
        int inchoice;
        cout<<"\n\nEnter Your Choice: ";
        cin>>inchoice;
        if (inchoice==1)//to view all food stall records
        {
            fstream fs;
            fs.open("rainfo.txt",ios::in);
            fs.seekg(0);
            while(!fs.eof()){
                fs.read((char *) &a, sizeof (Admin));
                a.redisplaytocustomer();
                
            }
            fs.close();
        }//to view all food stall records
        if (inchoice==2)//to search a food stall by unique stallid
        {
            int result=-1;
            cout<<"\nEnter the Food Stall Unique ID. :-";
            cin>>::sid;
            fstream fs;
            fs.open("rainfo.txt",ios::in);
            while(!fs.eof()){
                fs.read((char *) &a, sizeof (Admin));
                result=a.knowremenutocustomer();
                if(result==1)
                break;

            }
            if (result!=1)
            cout<<"\nRecord not found....";
        }
        if (inchoice==3)//to search a food stall by food type
        {
            int result;
            cout<<"\nFood Stall Pood Options Possibilities are \n1.South- Indian\n2.Continental\n3.Chinese\n4.Thailand\n5 Multiple";
            cout<<"\nEnter the Food Stall Food Options Type (Unique Number)";
            cin>>result;
            if (result==1)
            strcpy(ft, "South Indian");
            else if (result==2)
            strcpy(ft, "Continental");
            else if (result==3)
            strcpy(ft, "Chinese");
            else if (result==4)
            strcpy(ft, "Thailand");
            else
            strcpy(ft, "Multiple"); 
            fstream fs;
            fs.open("rainfo.txt",ios::in); 
            while(!fs.eof())
            {
                fs.read((char *)&a, sizeof (Admin));
                result=a.searchbyfoodtype();
                if (result==1)
                {
                  break;
                }
            }
            if (result!=1)
            cout<<"\nNo Such Food Stall found. ";
        }//to search a food stali by food type
        if(inchoice<1||inchoice>3)
        cout<<"\nInvalid Input Provided..."; 
        
        cout<<"\n\n\t\t\tEnter to Continue";
        getch();
        cout<<"\n\nPress y, otherwise n to Perform More Operations: ";
        cin>>moreop;
        if (moreop!='Y' && moreop!='y')
        { 
            system("CLS");

            cout<<"\n\n\n\t\t\tThank You !!!";
            getch();
            exit(0);
        } 
    }while (moreop=='Y' ||moreop=='y');

getch();
}



void invalid_user_input() {
    a.invalid_input();
    }
}m;




int main(){
    int ch, tmp;
    system("CLS");

    cout<< "\n\n\n\t\t\t Welcome to food Court Management System";
    cout<< "\n\n\n\t\t\t Enter to Continue";

    getch();
    system("CLS");

    cout<<"\n\n\n\t\t\t Press 1 for Admin Portal";
    cout<<"\n\t\t\t Press 2 for Food Stall Portal";
    cout<<"\n\t\t\t Press 3 for Customer Portal";
    cout<<"\n\n\t\t\t Enter Your Choice";
    cin>>ch;
    system("CLS");

    if(ch==1)
    m.admin_call();
    
    if(ch==2)
    m.r_call();

    if(ch==3)
    m.customer_call();

   if(ch<1|| ch>3)
   m.invalid_user_input();

return 0;

}


























