#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class Librarian ;
class Student;

class Books
{
    private:
	char bname[50];
	char aname[20];
    char bPublisher[50];
    char bId[6];
    int price ;
    int quantity ;
    int br;

    public:
    Books()
    {
        strcpy(bname,"NO Book Name");
        strcpy(bId,"No Book ID");
        strcpy(aname,"No Author Name");
        strcpy(bPublisher,"No Publisher Name");
        price=0;
        quantity=0;
        br=0;
    }
    friend class Librarian;

};         //class ends here

/*
class Lib
{
   protected:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Publisher Name");
           q=0;
           B=0;
           p=0;
       }


};
*/

class Student{
   private:
    char book_name[50];
    char book_Id[6];
    char stu_name[50];
    char stu_Id[6];
    int ddd;
    int mmm;
    int yyy;

public:
    Student()
    {
        strcpy(book_name,"NO Book Name");
        strcpy(book_Id,"No Book ID");
        strcpy(stu_name,"No Student Name");
        strcpy(stu_Id,"No Student ID");
        ddd=0;
        mmm=0;
        yyy=0;
    }
    friend class Librarian;
} ;    // Class End Here

class Librarian {

Books Bk;
Student Stu;
public:

    void booklist(int);
    void see(int);
    void student_menu();
    int branch(int);
    void show(int);
    void pass();
    void password();
    void get();
    void getdata();
    void modify();
    void issue();
    void librarian();
    void der(char[],int,int);
    void fine(int,int,int,int,int,int);

};



#endif // LMS_H_INCLUDED
