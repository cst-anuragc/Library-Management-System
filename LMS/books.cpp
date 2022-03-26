#include "books.h"

void Books::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tEnter the details :-\n";
                    cout<<"\n\t\tEnter Book's Name : ";
                    cin.getline(bname,50);
                    for(i=0;bname[i]!='\0';i++)
                    {
                        if(bname[i]>='a'&&bname[i]<='z')
                            bname[i]-=32;
                    }
                    cout<<"\n\t\tEnter Author's Name : ";
                    cin.getline(aname,20);
                    cout<<"\n\t\tEnter Publication name : ";
                    cin.getline(bPublisher,50);
                    cout<<"\n\t\tEnter Book's ID : ";
                    cin.getline(bId,6);
                    cout<<"\n\t\tEnter Book's Price : ";
                    cin>>price;
                    cout<<"\n\t\tEnter Book's Quantity : ";
                    cin>>quantity;
}

void Books::show(int i)
{
    cout<<"\n\t\tBook Name : "<<bname<<endl;
    cout<<"\n\t\tBook's Author Name : "<<aname<<endl;
    cout<<"\n\t\tBook's ID : "<<bId<<endl;
    cout<<"\n\t\tBook's Publication : "<<bPublisher<<endl;
    if(i == 2)
    {
    cout<<"\n\t\tBook's Price : "<<price<<endl;
    cout<<"\n\t\tBook's Quantity : "<<quantity<<endl;
    }
}

  void Books::booklist(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("Booksdata.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tFile Not Found.";
                else
                {
                    cout<<"\n\t    ************ Book List ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                    while(!intf.eof())
                    {
                        if(b==br)
                        {
                            if(quantity==0 && i == 1)
                            {

                            }
                            else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                        }
                        intf.read((char*)this,sizeof(*this));
                    }
                }
                cout<<"\n\t\tPress any key to continue.....";
                getch();
                system("cls");
                if(i == 1)
                    student_menu();
                else
                    librarian_menu();

}

  void Books::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("Booksdata.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tFile Not Found.\n";
            cout<<"\n\t\t->Press any key to continue.....";
            getch();
            system("cls");
            if(x==1)
                student_menu();
            else
                librarian_menu();
        }

      system("cls");
      cout<<"\n\t\tPlease Choose one option :-\n";
      cout<<"\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
      cout<<"\n\t\tEnter Your Choice : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tEnter Book's Name : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==br&&quantity!=0&&bname[i]!='\0'&&ch[i]!='\0'&&(ch[i]==bname[i]||ch[i]==bname[i]+32);i++);
            if(bname[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tBook Found :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tEnter Book's ID : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==br&&quantity!=0&&bId[i]!='\0'&&ch[i]!='\0'&&ch[i]==bId[i];i++);
              if(bId[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tBook Found :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tPlease enter correct option :(";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tThis Book is not available :( \n";

    cout<<"\n\t\tPress any key to continue.....";
    getch();
    system("cls");
    if(x == 1)
        student_menu();
    else
        librarian_menu();
  }
