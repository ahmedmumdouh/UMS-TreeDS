#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include<iostream>
#include<string>

using namespace std ;





class student
{
  public: // We can't make it  protected cause of some errors
    student* left;
    student* right;
    int id ;
    string name ;
    string last_name ;
    string Data_Birth ;
    string address ;
    string college ;
    string department ;
    string study_years ;
    string sel_subjects[6]={"NOT-Selected-Yet","NOT-Selected-Yet","NOT-Selected-Yet","NOT-Selected-Yet","NOT-Selected-Yet","NOT-Selected-Yet"};
    int grades[6]={0,0,0,0,0,0} ;

  public :
    student();
    ~student();
    void set_personal_data() ;
    void set_academic_data() ;
    void view_all_data() ;
};


class admin : public student   // we made this inherit cause we intended student data protected but couldn't
{
 private :
     string all_subjects[12];
     student* GetNewNode(int st_id);
     student* Insert(student* st_root, int st_id);
     student* Search(int st_id);
     student* Search(student* st_root,int st_id);
     student* FindMin(student* root);
     student* Delete(student* root, int st_id);
     void Inorder(student* root);

 public :
  bool check_id(int ad_id) ;
  void add_students_id(int st_id) ;
  void remove_student_id(int st_id) ;
  student* select_st_id(int st_id) ;
  void view_all_ids() ;
  void add_grades(student* st_root) ;
  void add_all_subjects() ;
  void view_all_subjects() ;
  void view_all_student_info(student* root);
  void view_all_student_info() ;
  void delete_all_student_info(student* root) ;
  void delete_all_student_info() ;
};






#endif // CLASSES_H_INCLUDED
