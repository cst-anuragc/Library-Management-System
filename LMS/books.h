#ifndef BOOKS_H_INCLUDED
#define BOOKS_H_INCLUDED

using namespace std;

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

    void show(int);
    void getdata();
    void booklist(int);
    void see(int);

    int branch_num()
    {
        return br;
    }

    const char* book_name()
    {
        return bname;
    }

    const char* book_ID()
    {
        return bId;
    }

    void get_branch(int value)
    {
        br = value;
    }

    void get_quantity(int num)
    {
        quantity += num;
    }

};

#endif // BOOKS_H_INCLUDED
