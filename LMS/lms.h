#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
#include"books.h"
using namespace std;

class Student {
    private :
        char student_name[50];
        char student_ID[6];
        int age;
        int mobile_no;
        char division;
        char student_addr[100];
        int num_book_parchase;

    public:
        Student()
        {
            strcpy(student_name , "No Student Name");
            strcpy(student_ID , "No ID");
            strcpy(student_addr , "No Addr available");
            age = 0 ;
            division = '\0';
            mobile_no = 0 ;
            num_book_parchase = 0 ;
        }

        void add_student();
};

class Transaction{
   private:
    char book_name[50];
    char book_Id[6];
    char stu_name[50];
    char stu_Id[6];
    int ddd;
    int mmm;
    int yyy;

public:
    Transaction()
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
Transaction Trans;
public:

    void pass();
    void password();
    void modify();
    void issue();
    void der(char[],int,int);
    void fine(int,int,int,int,int,int);

};

int branch(int);
void librarian_menu();
void student_menu();
void get();
#endif // LMS_H_INCLUDED
