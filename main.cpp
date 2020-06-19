#include <iostream>
#include<string>
#include<windows.h>
using namespace std;
#include"classes.h"

admin main_ad ;
int main()
{

    int choice ,id ,n ;
     while(1)
    {
      main_menu : system("cls") ;
      cout << " 1. Admin " << endl;
      cout << " 2. Student " << endl;
      cout << " 3. Exit " << endl;
      cout <<" Select choice : " ;
      cin >> choice ;
     switch(choice)
     {
       case 1 :
        while(1)
         {
          system("cls") ;
          cout <<" Enter an Admin id : " ;
          cin>> id ;
         if(main_ad.check_id(id))
          {
             student* sel_root = nullptr ;
             cout << "          ======================== Correct-Admin-id =========================       " <<endl ;
             admin_main :
             cout << "1- Add students id(s)"<<endl;
             cout << "2- Select student id"<<endl;
             cout << "3- Remove Student-id"<<endl;
             cout << "4- Add All subjects"<<endl;
             cout << "5- Add Grades to selected-id"<<endl;
             cout << "6- View selected student-info"<<endl;
             cout << "7- View ALL student-info"<<endl;
             cout << "8- Delete ALL student-info"<<endl;
             cout << "9- Return to main menu"<<endl;
             cout<<" Select choice : " ;
             cin >> choice ;
             if(choice==1)
             {
              cout<<" Enter num.id(s) : " ;
              cin>>n ;
              //student* st_root = nullptr;  // Creating an empty tree
              for(int i=0;i<n;i++)
              {
                cout<<" Enter id no."<<i+1<<" : " ;
                cin>>id ;
                main_ad.add_students_id(id) ;
              }
              system("cls") ;
              cout<< " === id-Found === "<<endl ;
              goto admin_main ;
             }

            else if (choice==2)
            {
                main_ad.view_all_ids() ;
                cout<<" Enter a Student id from above id(s) : " ;
                cin>> id ;
                if(main_ad.select_st_id(id) != nullptr)
                {
                 system("cls") ;
                 sel_root = main_ad.select_st_id(id) ;
                 cout<<" Selected id- "<<main_ad.select_st_id(id)->id<<endl;
                 goto admin_main ;
                }
                else
                 {
                   system("cls") ;
                   cout<<" Not-Found id- "<<id<<endl;
                   goto admin_main ;
                 }
            }
            else if (choice==3)
                {
                    cout<<"==========================================="<<endl ;
                if(sel_root != nullptr)
                {
                  main_ad.remove_student_id(sel_root->id) ;
                  cout<<" Student id. "<<sel_root->id<<" has been Removed . "<<endl ;
                  cout<<endl<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                else
                {
                  cout<<" No-Selected id "<<endl ;
                  cout<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                system("cls") ;
                goto admin_main;
                }
            else if (choice==4)
                {
                  main_ad.add_all_subjects() ;
                  system("cls");
                  cout<<" ======= All-Subjects Added ======= \n" ;
                  goto admin_main ;
                }
            else if (choice==5)
            {
              cout<<"==========================================="<<endl ;
                if(sel_root != nullptr)
                {
                  main_ad.add_grades(sel_root) ;
                  cout<<" ==== Done ==== "<<endl ;
                  cout<<endl<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                else
                {
                  cout<<" No-Selected id "<<endl ;
                  cout<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                system("cls") ;
                goto admin_main;
            }
            else if (choice==6)
            {
               cout<<"==========================================="<<endl ;
                if(sel_root != nullptr)
                {
                  sel_root->view_all_data() ;
                  cout<<endl<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                else
                {
                  cout<<" No-Selected id "<<endl ;
                  cout<<" Press any num to return ... " ;
                  cin>>choice ;
                }
                system("cls") ;
                goto admin_main;
            }
            else if (choice==7)
            {
              main_ad.view_all_student_info() ;
              cout<<" Press any num to return ... " ;
              cin>>choice ;
              system("cls") ;
              goto admin_main;
            }
            else if (choice==8)
            {
              main_ad.delete_all_student_info() ;
              system("cls") ;
              cout<<" ===== Delete All Students ====="<<endl ;
              goto admin_main;
            }
            else
                goto main_menu ;
        }

          else
           {
             cout << "          ======================== Invalid-Admin-id =========================       " <<endl ;
             cout << "1- Re-Enter an Admin id"<<endl;
             cout << "2- Return to main menu"<<endl;
             cout<<" Select choice : " ;
             cin >> choice ;
             if(choice == 1)
                continue ;
             else
                break ;
             }
           }
        break ;
       case 2 :
          while(1)
         {
          system("cls") ;
          cout <<" Enter a Student id : " ;
          cin  >> id ;
         if(main_ad.select_st_id(id) != nullptr)
          {
            student* sel_root = main_ad.select_st_id(id) ;
            cout << "          ======================== Correct-Student-id-"<<sel_root->id<<" =========================       " <<endl ;
            st_main :
            cout << "1- Set personal-Info"<<endl;
            cout << "2- Set Academic-Info"<<endl;
            cout << "3- View All student-Info"<<endl;
            cout << "4- Return to main menu"<<endl;
            cout<<" Select choice : " ;
            cin >> choice ;
            if(choice==1)
               {
                 cout<<"==========================================="<<endl ;
                sel_root->set_personal_data() ;
                system("cls") ;
                goto st_main;
               }
            else if (choice==2)
            {
                cout<<"==========================================="<<endl ;
                main_ad.view_all_subjects() ;
                sel_root->set_academic_data() ;
                system("cls") ;
                goto st_main;
            }
            else if (choice==3)
            {
              cout<<"==========================================="<<endl ;
                sel_root->view_all_data() ;
                cout<<endl<<" Press any num to return ... " ;
                cin>>choice ;
                system("cls") ;
                goto st_main;
            }
            else
                break ;
          }
          else
           {
             cout << "          ======================== Invalid-Student-id =========================       " <<endl ;
             cout << "1- Re-Enter a Student id"<<endl;
             cout << "2- Return to main menu"<<endl;
             cout<<" Select choice : " ;
             cin >> choice ;
             if(choice == 1)
                continue ;
             else
                break ;
             }
           }
         break ;
       default :
         goto exit ;
     }
    }
    exit :
    return 0;
}
