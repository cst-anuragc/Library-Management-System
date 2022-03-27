#ifndef LMS_H_INCLUDED
#define LMS_H_INCLUDED

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <iostream>

using namespace std;

class Books { // Book Class Start Here
   private:
    char bname[50];
    char aname[20];
    char bPublisher[50];
    char bId[6];
    int price;
    int quantity;
    int br;

   public:
    Books() {
        strcpy(bname, "NO Book Name");
        strcpy(bId, "No Book ID");
        strcpy(aname, "No Author Name");
        strcpy(bPublisher, "No Publisher Name");
        price = 0;
        quantity = 0;
        br = 0;
    }

    void show(int);
    void getdata();
    void booklist(int);
    void see(int);

    int branch_num() { return br; }

    const char* book_name() { return bname; }

    const char* book_ID() { return bId; }

    void get_branch(int value) { br = value; }

    void get_quantity(int num) { quantity += num; }
}; // Book Class End Here

class Student { // Student Class Start Here
    char student_name[50];
    char student_ID[6];
    int age;
    long long int mobile_no;
    char division;
    char student_addr[100];
    int num_book_parchase;

   public:
    Student() {
        strcpy(student_name, "No Student Name");
        strcpy(student_ID, "No ID");
        strcpy(student_addr, "No Addr available");
        age = 0;
        division = '\0';
        mobile_no = 0;
        num_book_parchase = 0;
    }

    const char* studentId() { return student_ID; }
    void add_student();
    void get_student_data();
    void show_student();
};// Student Class End Here


class Transaction { // Transaction Class Start Here
   private:
    char book_name[50];
    char book_Id[6];
    char stu_name[50];
    char stu_Id[6];
    int ddd;
    int mmm;
    int yyy;

   public:
    Transaction() {
        strcpy(book_name, "NO Book Name");
        strcpy(book_Id, "No Book ID");
        strcpy(stu_name, "No Student Name");
        strcpy(stu_Id, "No Student ID");
        ddd = 0;
        mmm = 0;
        yyy = 0;
    }
    friend class Librarian;
};  // Transaction Class End Here

class Librarian { //Librarian Class Start Here
    Books Bk;
    Transaction Trans;
    Student Stu;

   public:
    void pass();
    void password();
    void modify();
    void issue();
    void der(char[], int, int);
    void fine(int, int, int, int, int, int);
}; // Librarian Class End Here

int branch(int);
void librarian_menu();
void get();
void student_menu();

#endif  // LMS_H_INCLUDED
