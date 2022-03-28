#include "lms.h"

void Librarian::modify() { // modify function use for Modify/Add/Delete books.
    char st1[100];
    int i = 0, b, cont = 0;
    system("cls");
    cout << "\n\t\t>>Please Choose one option :-\n";
    cout << "\n\t\t1.Modification In Current Books\n\n\t\t2.Add New "
            "Book\n\n\t\t3.Delete A Book\n\n\t\t4.Go back\n";
    cout << "\n\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1) {
        system("cls");
        b = branch(2);
        ifstream intf1("Booksdata.txt", ios::binary); // modification under binary mode
        if (!intf1) {
            cout << "\n\t\tFile Not Found\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            librarian_menu(); // if file not found control backs in librarian menu.
        }
        intf1.close();
        system("cls");
        cout << "\n\t\tPlease Choose One Option :-\n";
        cout << "\n\t\t1.Search By Book Name\n\n\t\t2.Search By Book's ID\n";
        cout << "\n\t\tEnter Your Choice : ";
        cin >> i;
        fflush(stdin); //fflush() cleaning the output buffer.
        if (i == 1) {
            system("cls");
            cout << "\n\t\tEnter Book Name : ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Booksdata.txt",
                         ios::in | ios::out | ios::ate | ios::binary);
            intf.seekg(0);
            intf.read((char*)this, sizeof(*this));

            while (!intf.eof()) {
                const char* temp = Bk.book_name();
                cout << "temp book : " << *temp << endl;
                for (i = 0; Bk.branch_num() == b && temp[i] != '\0' &&
                            st1[i] != '\0' &&
                            (st1[i] == temp[i] || st1[i] == temp[i] + 32);
                     i++)
                    ;
                if (temp[i] == '\0' && st1[i] == '\0') {
                    cont++;
                    Bk.getdata();
                    intf.seekp((int)intf.tellp() - (int)sizeof(*this));
                    intf.write((char*)this, sizeof(*this));
                    break;
                }
                intf.read((char*)this, sizeof(*this));
            }
            intf.close();
        } else if (i == 2) {
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(st1, 100);
            system("cls");
            fstream intf("Booksdata.txt",
                         ios::in | ios::out | ios::ate | ios::binary);
            intf.seekg(0);
            intf.read((char*)this, sizeof(*this));
            while (!intf.eof()) {
                const char* B_id = Bk.book_ID();
                for (i = 0; b == Bk.branch_num() && B_id[i] != '\0' &&
                            st1[i] != '\0' && st1[i] == B_id[i];
                     i++)
                    ;
                if (B_id[i] == '\0' && st1[i] == '\0') {
                    cont++;
                    Bk.getdata();
                    intf.seekp((int)intf.tellp() - (int)sizeof(*this));
                    intf.write((char*)this, sizeof(*this));
                    break;
                }
                intf.read((char*)this, sizeof(*this));
            }

            intf.close();
        } else {
            cout << "\n\t\tIncorrect Input.....:(\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        }
        if (cont == 0) {
            cout << "\n\t\tBook Not Found.\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        } else
            cout << "\n\t\tUpdate Successful.\n";

    } else if (i == 2) {
        int temp = 0;
        system("cls");
        temp = branch(2);
        Bk.get_branch(temp);
        system("cls");
        Bk.getdata();
        ofstream outf("Booksdata.txt", ios::app | ios::binary);
        outf.write((char*)this, sizeof(*this));
        outf.close();
        cout << "\n\t\tBook added Successfully.\n";
    } else if (i == 3) {
        system("cls");
        b = branch(2);
        ifstream intf1("Booksdata.txt", ios::binary);
        if (!intf1) {
            cout << "\n\t\tFile Not Found\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            intf1.close();
            system("cls");
            librarian_menu();
        }
        intf1.close();
        system("cls");
        cout << "\n\t\tPlease Choose One Option for deletion:-\n";
        cout << "\n\t\t1.By Book Name\n\n\t\t2.By Book's ID\n";
        cout << "\n\t\tEnter Your Choice : ";
        cin >> i;
        fflush(stdin); //fflush() cleaning the output buffer.
        if (i == 1) {
            system("cls");
            cout << "\n\t\tEnter Book Name : ";
            cin.getline(st1, 100);
            ofstream outf("temp.txt", ios::app | ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char*)this, sizeof(*this));
            while (!intf.eof()) {
                const char* temp = Bk.book_name();
                for (i = 0; b == Bk.branch_num() && temp[i] != '\0' &&
                            st1[i] != '\0' &&
                            (st1[i] == temp[i] || st1[i] == temp[i] + 32);
                     i++)
                    ;
                if (temp[i] == '\0' && st1[i] == '\0') {
                    cont++;
                    intf.read((char*)this, sizeof(*this));

                } else {
                    outf.write((char*)this, sizeof(*this));
                    intf.read((char*)this, sizeof(*this));
                }
            }

            intf.close();
            outf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Booksdata.txt");
        } else if (i == 2) {
            cout << "\n\t\tEnter Book's ID : ";
            cin.getline(st1, 100);
            ofstream outf("temp.txt", ios::app | ios::binary);
            ifstream intf("Booksdata.txt", ios::binary);
            intf.read((char*)this, sizeof(*this));
            while (!intf.eof()) {
                const char* B_id = Bk.book_ID();
                for (i = 0; b == Bk.branch_num() && B_id[i] != '\0' &&
                            st1[i] != '\0' && st1[i] == B_id[i];
                     i++)
                    ;
                if (B_id[i] == '\0' && st1[i] == '\0') {
                    cont++;
                    intf.read((char*)this, sizeof(*this));
                } else {
                    outf.write((char*)this, sizeof(*this));
                    intf.read((char*)this, sizeof(*this));
                }
            }
            outf.close();
            intf.close();
            remove("Booksdata.txt");
            rename("temp.txt", "Booksdata.txt");
        } else {
            cout << "\n\t\tIncorrect Input.....:(\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        }
        if (cont == 0) {
            cout << "\n\t\tBook Not Found.\n";
            cout << "\n\t\tPress any key to continue.....";
            getch();
            system("cls");
            modify();
        } else
            cout << "\n\t\tDeletion Successful.\n";

    } else if (i == 4) {
        system("cls");
        librarian_menu();
    } else {
        cout << "\n\t\tWrong Input.\n";
        cout << "\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        modify();
    }
    cout << "\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian_menu();
}// modify function End Here.

void Librarian::issue() { //Issue function used for Issuing/View Issuing/Search/Reissued Books.
    char st[50], st1[6];
    int b, i, j, d, m, y, cont = 0;
    system("cls");
    cout << "\n\t\t->Please Choose one option :-\n";
    cout << "\n\t\t1.Issue Book\n\n\t\t2.View Issued Book\n\n\t\t3.Search "
            "student who issued books\n\n\t\t4.Reissue Book\n\n\t\t5.Return "
            "Book\n\n\t\t6.Go back to menu\n\n\t\tEnter Your Choice : ";
    cin >> i;
    fflush(stdin); //fflush() cleaning the output buffer.
    if (i == 1) {
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin); // fflush() cleaning the output buffer.
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\t\tEnter Book Name : ";
        cin.getline(st, 50);
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(st1, 6);
        der(st1, b, 1);
        strcpy(Trans.book_name, st);
        strcpy(Trans.book_Id, st1);
        cout << "\n\t\tEnter Student Name : ";
        cin.getline(Trans.stu_name, 50);
        cout << "\n\t\tEnter Student's ID : ";
        cin.getline(Trans.stu_Id, 6);
        cout << "\n\t\tEnter date (dd mm yy): ";
        cin >> Trans.ddd >> Trans.mmm >> Trans.yyy;
        ifstream inf("student.txt", ios::binary);
        cont = 1;
        while (inf.read((char*)&Stu, sizeof(Student))) {
            const char* temp = Stu.studentId();
            int k = strcmp(Trans.stu_Id, temp);
            if (k == 0) cont = 0;
        }
        if (cont == 0) {
            ofstream outf("transaction.txt", ios::app | ios::binary);
            outf.write((char*)this, sizeof(*this));
            outf.close();
            inf.close();
            cout << "\n\n\t\tIssue Successfully.\n";
        } else {
            inf.close();
            cout << "\n\n\tStudent Not allowed for Issuing Book , Student Not "
                    "a member of Library first be a member."
                 << endl;
        }
    } else if (i == 2) {
        ifstream intf("transaction.txt", ios::binary);
        system("cls");
        cout << "\n\t\t->The Details are :-\n";
        intf.read((char*)this, sizeof(*this));
        i = 0;
        while (!intf.eof()) {
            i++;
            cout << "\n\t\t********** " << i << ". ********** \n";
            cout << "\n\t\tStudent Name : " << Trans.stu_name << "\n\t\t"
                 << "Student's ID : " << Trans.stu_Id << "\n\t\t"
                 << "Book Name : " << Trans.book_name << "\n\t\t"
                 << "Book's ID : " << Trans.book_Id << "\n\t\t"
                 << "Date : " << Trans.ddd << "/" << Trans.mmm << "/"
                 << Trans.yyy << "\n";
            intf.read((char*)this, sizeof(*this));
        }
        intf.close();
    } else if (i == 3) {
        system("cls");
        fflush(stdin); //fflush() cleaning the output buffer.
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\n\t\tEnter Student Name : ";
        cin.getline(st, 50);
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st1, 6);
        system("cls");
        ifstream intf("transaction.txt", ios::binary);
        intf.read((char*)this, sizeof(*this));
        cont = 0;
        while (!intf.eof()) {
            for (i = 0; Trans.stu_Id[i] != '\0' && st1[i] != '\0' &&
                        Trans.stu_Id[i] == st1[i];
                 i++)
                ;
            if (Trans.stu_Id[i] == '\0' && st1[i] == '\0') {
                cont++;
                if (cont == 1) {
                    cout << "\n\t\t->The Details are :-\n";
                    cout << "\n\t\tStudent Name : " << Trans.stu_name;
                    cout << "\n\t\tStudent's ID : " << Trans.stu_Id;
                }
                cout << "\n\n\t\t******* " << cont
                     << ". Book details *******\n";
                cout << "\n\t\tBook Name : " << Trans.book_name;
                cout << "\n\t\tBook's ID : " << Trans.book_Id;
                cout << "\n\t\tDate : " << Trans.ddd << "/" << Trans.mmm << "/"
                     << Trans.yyy << "\n";
            }
            intf.read((char*)this, sizeof(*this));
        }
        intf.close();
        if (cont == 0) cout << "\n\t\tNo record found.";
    } else if (i == 4) {
        system("cls");
        fflush(stdin); //fflush() cleaning the output buffer.
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 50);
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(st1, 6);
        fstream intf("transaction.txt",
                     ios::in | ios::out | ios::ate | ios::binary);
        intf.seekg(0);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof()) {
            for (i = 0; Trans.book_Id[i] != '\0' && st1[i] != '\0' &&
                        st1[i] == Trans.book_Id[i];
                 i++)
                ;
            for (j = 0; Trans.stu_Id[j] != '\0' && st[j] != '\0' &&
                        st[j] == Trans.stu_Id[j];
                 j++)
                ;
            if (Trans.book_Id[i] == '\0' && Trans.stu_Id[j] == '\0' &&
                st[j] == '\0' && st1[i] == '\0') {
                d = Trans.ddd;
                m = Trans.mmm;
                y = Trans.yyy;
                cout << "\n\t\tEnter New Date : ";
                cin >> Trans.ddd >> Trans.mmm >> Trans.yyy;
                fine(d, m, y, Trans.ddd, Trans.mmm, Trans.yyy);      // fn1
                intf.seekp((int)intf.tellp() - (int)sizeof(*this));  // fn3
                intf.write((char*)this, sizeof(*this));              // fn5
                cout << "\n\n\t\tReissue successfully.";             // fn3
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }
        intf.close();
    } else if (i == 5) {
        system("cls");
        b = branch(2);
        system("cls");
        fflush(stdin); //fflush() cleaning the output buffer.
        cout << "\n\t\t->Please Enter Details :-\n";
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(st1, 6);
        der(st1, b, 2);
        cout << "\n\n\t\tEnter Student's ID : ";
        cin.getline(st, 6);
        cout << "\n\t\tEnter Present date : ";
        cin >> d >> m >> y;
        ofstream outf("temp.txt", ios::app);
        ifstream intf("transaction.txt", ios::binary);
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof()) {
            for (i = 0; Trans.book_Id[i] != '\0' && st1[i] != '\0' &&
                        st1[i] == Trans.book_Id[i];
                 i++)
                ;
            for (j = 0; Trans.stu_Id[j] != '\0' && st[j] != '\0' &&
                        st[j] == Trans.stu_Id[j];
                 j++)
                ;
            if (Trans.book_Id[i] == '\0' && Trans.stu_Id[j] == '\0' &&
                st[j] == '\0' && st1[i] == '\0' && cont == 0) {
                cont++;
                intf.read((char*)this, sizeof(*this));
                fine(Trans.ddd, Trans.mmm, Trans.yyy, d, m, y);
                cout << "\n\t\tReturned successfully.";
            } else {
                outf.write((char*)this, sizeof(*this));
                intf.read((char*)this, sizeof(*this));
            }
        }

        intf.close();
        outf.close();
        getch();
        remove("transaction.txt");
        rename("temp.txt", "transaction.txt");
    } else if (i == 6) {
        system("cls");
        librarian_menu();
    } else
        cout << "\n\t\tWrong Input.\n";

    cout << "\n\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian_menu();
}

void Librarian::fine(int d, int m, int y, int dd, int mm, int yy) { // Fine function used for impose the fine after books return date.
    long int n1, n2;
    int years, l, i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    n1 = y * 365 + d;
    for (i = 0; i < m - 1; i++) n1 += monthDays[i];
    years = y;
    if (m <= 2) years--;
    l = years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy * 365 + dd;
    for (i = 0; i < mm - 1; i++) n2 += monthDays[i];
    years = yy;
    if (m <= 2) years--;
    l = years / 4 - years / 100 + years / 400;
    n2 += l;
    n1 = n2 - n1;
    n2 = n1 - 15;
    if (n2 > 0) cout << "\n\t\tThe Total Fine is : " << n2;
}

void Librarian::der(char st[], int b, int x) {
    int i, cont = 0;
    char St[6];
    strcpy(St, st);
    fstream intf("Booksdata.txt", ios::in | ios::out | ios::ate | ios::binary);
    intf.seekg(0);
    intf.read((char*)this, sizeof(*this));
    while (!intf.eof()) {
        const char* B_id = Bk.book_ID();
        for (i = 0; b == Bk.branch_num() && B_id[i] != '\0' && St[i] != '\0' &&
                    St[i] == B_id[i];
             i++)
            ;
        if (B_id[i] == '\0' && St[i] == '\0') {
            cont++;
            if (x == 1) {
                Bk.get_quantity(-1);
            } else {
                Bk.get_quantity(1);
            }
            intf.seekp((int)intf.tellp() - (int)sizeof(*this));
            intf.write((char*)this, sizeof(*this));
            break;
        }
        intf.read((char*)this, sizeof(*this));
    }
    if (cont == 0) {
        cout << "\n\t\tBook not found.\n";
        cout << "\n\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}

void Librarian::pass() { // Pass function used for managing Librarian password.
    int i = 0;
    char ch, st[21], ch1[21] = {"abc123"};
    cout << "\n\t\tEnter Password : ";
    while (1) {
        ch = getch();
        if (ch == 13) {
            st[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {
            i--;
            cout << "\b \b";
        } else {
            cout << "*";
            st[i] = ch;
            i++;
        }
    }
    ifstream inf("password.txt"); // password stored in password text file
    inf >> ch1;
    inf.close();
    for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
        ;
    if (st[i] == '\0' && ch1[i] == '\0') {
        system("cls");
        librarian_menu();
    } else {
        cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        get();
    }
}

void Librarian::password() { // password used for changing Default or old password
    int i = 0, j = 0;
    char ch, st[21], ch1[21] = {"abc123"};
    system("cls");
    cout << "\n\n\t\tEnter Old Password : ";
    while (1) {
        ch = getch();
        if (ch == 13) {
            st[i] = '\0';
            break;
        } else if (ch == 8 && i > 0) {
            i--;
            cout << "\b \b";
        } else {
            cout << "*";
            st[i] = ch;
            i++;
        }
    }
    ifstream intf("password.txt");
    intf >> ch1;
    intf.close();
    for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
        ;
    if (st[i] == '\0' && ch1[i] == '\0') {
        system("cls");
        cout << "\n\t**The Password Should be less than 20 characters & don't "
                "use spaces**\n\n";
        cout << "\n\t\tEnter New Password : ";
        fflush(stdin); //fflush() cleaning the output buffer.
        i = 0;
        while (1) {
            j++;
            ch = getch();
            if (ch == 13) {
                for (i = 0; st[i] != ' ' && st[i] != '\0'; i++)
                    ;
                if (j > 20 || st[i] == ' ') {
                    cout << "\n\n\t\tYou did't follow the instruction "
                            "\n\n\t\tPress any key for try again.....";
                    getch();
                    system("cls");
                    password();
                    librarian_menu();
                }
                st[i] = '\0';
                break;
            } else if (ch == 8 && i > 0) {
                i--;
                cout << "\b \b";
            } else {
                cout << "*";
                st[i] = ch;
                i++;
            }
        }
        ofstream outf("password.txt");
        cout << st;
        outf << st;
        outf.close();
        cout << "\n\n\t\tYour Password has been changed Successfully.";
        cout << "\n\t\tPress any key to continue......";
        getch();
        system("cls");
        librarian_menu();
    } else {
        cout << "\n\n\t\tPassword is incorrect.....\n";
        cout << "\n\t\tEnter 1 for retry or 2 for menu";
        cin >> i;
        if (i == 1) {
            system("cls");
            password();
        } else {
            system("cls");
            librarian_menu();
        }
    }
}

void Student::add_student() { // add_stdent is used for Adding/Show students
    int i = 0;
    system("cls");
    cout << "\n\t\t>>Please Choose one option :-\n";
    cout << "\n\t\t1.Add Student\n\n\t\t2.Show Student List\n\n\t\t3.Go back\n";
    cout << "\n\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1) {
        system("cls");
        get_student_data();
        ofstream outf("Student.txt", ios::app | ios::binary);
        outf.write((char*)this, sizeof(*this));
        outf.close();
        cout << "\n\t\tMember added Successfully.\n";
    } else if (i == 2) {
        int r = 0;
        system("cls");
        ifstream intf("student.txt", ios::binary);
        if (!intf)
            cout << "\n\t\tFile Not Found.";
        else {
            cout << "\n\t    ************ Student's List ************ \n\n";
            while (intf.read((char*)this, sizeof(*this))) {
                r++;
                cout << "\n\t\t********** " << r << ". ********** \n";
                show_student();
            }
        }
    } else if (i == 3) {
        system("cls");
        librarian_menu();
    } else {
        cout << "\n\t\tWrong Input.\n";
        cout << "\n\t\tPress any key to continue.....";
        getch();
        system("cls");
        add_student();
    }
    cout << "\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    librarian_menu();
}

void Student::show_student() {
    cout << "\n\t\tStudent Name : " << student_name << endl;
    cout << "\n\t\tStudent ID : " << student_ID << endl;
    cout << "\n\t\tStudent age : " << age << endl;
    cout << "\n\t\tStudent Mobile No. : " << mobile_no << endl;
    cout << "\n\t\tStudent division : " << division << endl;
    cout << "\n\t\tStudent Address : " << student_addr << endl;
}

void Student::get_student_data() {
    fflush(stdin); //fflush() cleaning the output buffer.
    cout << "\n\t\tEnter the details :-\n";
    cout << "\n\t\tEnter Student's Name : ";
    cin.getline(student_name, 50);
    cout << "\n\t\tEnter Student's ID : ";
    cin.getline(student_ID, 6);
    cout << "\n\t\tEnter Student's age : ";
    cin >> age;
    cout << "\n\t\tEnter Student Mo. number : ";
    cin >> mobile_no;
    cout << "\n\t\tEnter Student Addr : ";
    cin >> student_addr;
    cout << "\n\t\tEnter division : ";
    cin >> division;
}

void Books::getdata() { // Get_data is used for Adding Books.
    int i;
    fflush(stdin);
    cout << "\n\t\tEnter the details :-\n";
    cout << "\n\t\tEnter Book's Name : ";
    cin.getline(bname, 50);
    for (i = 0; bname[i] != '\0'; i++) {
        if (bname[i] >= 'a' && bname[i] <= 'z') bname[i] -= 32;
    }
    cout << "\n\t\tEnter Author's Name : ";
    cin.getline(aname, 20);
    cout << "\n\t\tEnter Publication name : ";
    cin.getline(bPublisher, 50);
    cout << "\n\t\tEnter Book's ID : ";
    cin.getline(bId, 6);
    cout << "\n\t\tEnter Book's Price : ";
    cin >> price;
    cout << "\n\t\tEnter Book's Quantity : ";
    cin >> quantity;
}

void Books::show(int i) { // show is used for display Book details
    cout << "\n\t\tBook Name : " << bname << endl;
    cout << "\n\t\tBook's Author Name : " << aname << endl;
    cout << "\n\t\tBook's ID : " << bId << endl;
    cout << "\n\t\tBook's Publication : " << bPublisher << endl;
    if (i == 2) {
        cout << "\n\t\tBook's Price : " << price << endl;
        cout << "\n\t\tBook's Quantity : " << quantity << endl;
    }
}

void Books::booklist(int i) { // booklist for showing all added books
    int b, r = 0;
    system("cls");
    b = branch(i);
    system("cls");
    ifstream intf("Booksdata.txt", ios::binary);
    if (!intf)
        cout << "\n\t\tFile Not Found.";
    else {
        cout << "\n\t    ************ Book List ************ \n\n";
        intf.read((char*)this, sizeof(*this));
        while (!intf.eof()) {
            if (b == br) {
                if (quantity == 0 && i == 1) {
                } else {
                    r++;
                    cout << "\n\t\t********** " << r << ". ********** \n";
                    show(i);
                }
            }
            intf.read((char*)this, sizeof(*this));
        }
    }
    cout << "\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if (i == 1)
        student_menu();
    else
        librarian_menu();
}

void Books::see(int x) { // See for Search Book by name or by ID.
    int i, b, cont = 0;
    char ch[100];
    system("cls");
    b = branch(x);
    ifstream intf("Booksdata.txt", ios::binary);
    if (!intf) {
        cout << "\n\t\tFile Not Found.\n";
        cout << "\n\t\t->Press any key to continue.....";
        getch();
        system("cls");
        if (x == 1)
            student_menu();
        else
            librarian_menu();
    }

    system("cls");
    cout << "\n\t\tPlease Choose one option :-\n";
    cout << "\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
    cout << "\n\t\tEnter Your Choice : ";
    cin >> i;
    fflush(stdin); //fflush() cleaning the output buffer.
    intf.read((char*)this, sizeof(*this));
    if (i == 1) {
        cout << "\n\t\tEnter Book's Name : ";
        cin.getline(ch, 100);
        system("cls");
        while (!intf.eof()) {
            for (i = 0;
                 b == br && quantity != 0 && bname[i] != '\0' &&
                 ch[i] != '\0' && (ch[i] == bname[i] || ch[i] == bname[i] + 32);
                 i++)
                ;
            if (bname[i] == '\0' && ch[i] == '\0') {
                cout << "\n\t\tBook Found :-\n";
                show(x);
                cont++;
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }
    } else if (i == 2) {
        cout << "\n\t\tEnter Book's ID : ";
        cin.getline(ch, 100);
        system("cls");
        while (!intf.eof()) {
            for (i = 0; b == br && quantity != 0 && bId[i] != '\0' &&
                        ch[i] != '\0' && ch[i] == bId[i];
                 i++)
                ;
            if (bId[i] == '\0' && ch[i] == '\0') {
                cout << "\n\t\tBook Found :-\n";
                show(x);
                cont++;
                break;
            }
            intf.read((char*)this, sizeof(*this));
        }

    } else {
        cont++;
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        see(x);
    }
    intf.close();
    if (cont == 0) cout << "\n\t\tThis Book is not available :( \n";

    cout << "\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if (x == 1)
        student_menu();
    else
        librarian_menu();
}

int branch(int x) {
    int i;
    cout << "\n\t\t>>Please Choose one Stream :-\n";
    cout << "\n\t\t1.Class "
            "12th\n\n\t\t2.CS\n\n\t\t3.EC\n\n\t\t4.CIVIL\n\n\t\t5."
            "Biography\n\n\t\t6.GK Books\n\n\t\t7.Go to main menu\n";
    cout << "\n\t\tEnter youur choice : ";
    cin >> i;
    switch (i) {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 5:
            return 5;
            break;
        case 6:
            return 6;
            break;
        case 7:
            system("cls");
            if (x == 1)
                student_menu();
            else
                librarian_menu();
        default:
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            branch(x);
    }
    return 0;
}

void librarian_menu() { //librarian_menu for getting input from librarian
    Books B_Temp;
    Librarian L_Temp;
    Student Stu;
    int i;
    cout << "\n\t************ WELCOME LIBRARIAN ************\n";
    cout << "\n\t\t>>Please Choose One Option:\n";
    cout << "\n\t\t1.Add_Member\n\n\t\t2.View BookList\n\n\t\t3.Search for a "
            "Book\n\n\t\t4.Modify/Add Book\n\n\t\t5.Issue Book\n\n\t\t6.Go to "
            "main menu\n\n\t\t7.Change Password\n\n\t\t8.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    switch (i) {
        case 1:
            Stu.add_student();
            break;
        case 2:
            B_Temp.booklist(2);
            break;
        case 3:
            B_Temp.see(2);
            break;
        case 4:
            L_Temp.modify();
            break;
        case 5:
            L_Temp.issue();
            break;
        case 6:
            system("cls");
            get();
            break;
        case 7:
            L_Temp.password();
            break;
        case 8:
            exit(0);
        default:
            cout << "\n\t\tPlease enter correct option :(";
            getch();
            system("cls");
            librarian_menu();
            break;
    }
}

void student_menu() { // Student_menue for geting input from student
    Books B_Temp;
    int i;
    cout << "\n\t************ WELCOME STUDENT ************\n";
    cout << "\n\t\t>>Please Choose One Option:\n";
    cout << "\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to "
            "main menu\n\n\t\t4.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
        B_Temp.booklist(1);
    else if (i == 2)
        B_Temp.see(1);
    else if (i == 3) {
        system("cls");
        get();
    } else if (i == 4)
        exit(0);
    else {
        cout << "\n\t\tPlease enter correct option :(";
        getch();
        system("cls");
        student_menu();
    }
}

void get() { // get function is used for entry point for student and Librarian.
    Librarian L_Temp;
    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n"
         << "\n\t\t\t    Library Management System C++\n";
    cout << "\n\t\t>>Please Choose Any Option To login \n";
    cout << "\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1) {
        system("cls");
        student_menu();
    } else if (i == 2)
        L_Temp.pass();

    else if (i == 3)
        exit(0);
    else {
        cout << "\n\t\tPlease enter correct option :(\n\n\t\t ****** PRESS ANY "
                "KEY TO GO BACK ****** \n";
        getch();
        system("CLS");
        get();
    }
}
