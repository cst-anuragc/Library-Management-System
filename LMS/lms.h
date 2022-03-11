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

class Lib
{
   public:
       char bookname[100],auname[50],sc[20],sc1[50];
       int q,B,p;
       Lib()
       {
           strcpy(bookname,"NO Book Name");
           strcpy(auname,"No Author Name");
           strcpy(sc,"No Book ID");
           strcpy(sc1,"No Book ID");
           q=0;
           B=0;
           p=0;
       }

};

class Student : public Lib{
public :

    void booklist(int);
    void see(int);
    void student();
    int branch(int);
    void show(int);

  //  friend class Librarian ;

} ;

class Librarian : public Student{
public:

    void pass();
    void get();
    void password();
    void getdata();
    void modify();
    void issue();
    void librarian();
    void der(char[],int,int);
    void fine(int,int,int,int,int,int);

};


#endif // LMS_H_INCLUDED
