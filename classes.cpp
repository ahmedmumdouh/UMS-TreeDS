

#include"classes.h"

student* st_root_g = nullptr;  // global ptr for tree actions


void student::set_personal_data()
    {
        cout<<" Enter first name : " ;
        cin>>name ;
        cout<<" Enter last name : " ;
        cin>> last_name ;
        cout<<" Enter your Data of Birth : " ;
        cin>>Data_Birth ;
        cout<<" Enter your address : " ;
        cin>>address ;
    }
void student::set_academic_data()
    {
        cout<<" Enter your college : " ;
        cin>>college ;
        cout<<" Enter your department : " ;
        cin>>department ;
        cout<<" Enter your study_years : " ;
        cin>>study_years ;
        cout<<" Enter six(6) selected subjects from above list only  : "<<endl ;
        for(int i=0;i <6;i++)
        {
            cout<<" Subject "<<i+1<<" : " ;
            cin>>sel_subjects[i] ;
        }
    }
void student::view_all_data()
      {
        cout<<" Name : "<<name<<" "<<last_name<<endl  ;
        cout<<" Data of Birth : "<<Data_Birth<<endl  ;
        cout<<" Address : "<<address<<endl  ;
        cout<<" College : "<<college<<endl  ;
        cout<<" Department : "<<department<<endl  ;
        cout<<" Study years : "<<study_years<<endl  ;
        for(int i=0;i<6;i++)
        {
          cout<<" Subject "<<sel_subjects[i]<<"  Grade :  "<<grades[i]<<endl;
        }
      }

 bool admin::check_id(int ad_id)
   {
     if(ad_id == 1234 )
        return true ;
     else
        return false ;
   }
   void admin::add_students_id(int st_id)
   {
    student* st_root = admin::Insert(st_root_g,st_id);
    st_root_g = st_root ;
   }

   void admin::remove_student_id(int st_id)
   {
     st_root_g = admin::Delete(st_root_g,st_id) ;
   }
   student* admin::select_st_id(int st_id)
   {
     return admin::Search(st_id) ;
   }


   void admin::view_all_ids()
   {
     admin::Inorder(st_root_g) ;
   }

  void admin::add_grades(student* st_root)
   {

      for(int i=0;i<6;i++)
        {
          cout<<" Subject "<<st_root->sel_subjects[i]<<"  Grade :  ";
          cin>>st_root->grades[i] ;
        }
    }

  void admin::add_all_subjects()
  {
    cout<<" Enter All available subjects : "<<endl ;
        for(int i=0;i <12;i++)
        {
           cout<<" Subject "<<i+1<<" : " ;
           cin>>all_subjects[i] ;
        }
  }
  void admin::view_all_subjects()
  {
    cout<<" All subjects are : " <<endl<<" ( ";
    for(int i=0;i<12;i++)
    {
      if(i!=5)
      cout<<all_subjects[i]<<" --" ;
      else
        cout<<endl<<"  " ;
    }
    cout<<" ) "<<endl ;
  }


void admin::view_all_student_info()
{
     admin::view_all_student_info(st_root_g) ;
}

void admin::view_all_student_info(student* root)
{
  if (root == NULL) return;
	admin::view_all_student_info(root->left);           //Visit left subtree
	cout<<" ============================================== "<<endl ;
	cout<<" ID -> "<<root->id<<endl ;     //Print data
	root->view_all_data() ;
	cout<<" ============================================== "<<endl ;
    admin::view_all_student_info(root->right);
}


void admin::delete_all_student_info()
{
     admin::delete_all_student_info(st_root_g) ;
}

void admin::delete_all_student_info(student* root)
{
  if (root == NULL) return;
	admin::delete_all_student_info(root->left);           //Visit left subtree
	admin::delete_all_student_info(root->right);
	admin::remove_student_id(root->id) ;


}





student::student()
{

}


student::~student()
{
}

// Function to create a new Node in heap
student* admin::GetNewNode(int st_id) {
    student* newNode = new student();
    newNode->id = st_id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
student* admin::Insert(student* st_root, int st_id) {
    if (st_root == NULL) { // empty tree
        st_root = admin::GetNewNode(st_id);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if (st_id < st_root->id) {
        st_root->left = admin::Insert(st_root->left, st_id);
    }
    // else, insert in right subtree.
    else if(st_id > st_root->id){
        st_root->right = admin::Insert(st_root->right, st_id);
    }
    else{return st_root;}

}

//To search an element in BST, returns true if element is found
student* admin::Search(int st_id)
{
  return admin::Search(st_root_g,st_id);
}


student* admin::Search(student* st_root,int st_id)
{
    if (st_root == NULL) {
        return nullptr;
    }
    else if (st_root->id == st_id) {
        return st_root;
    }
    else if (st_id <= st_root->id) {
        return admin::Search(st_root->left, st_id);
    }
    else {
        return admin::Search(st_root->right, st_id);
    }
}










student* admin::FindMin(student* root) {
	if (root == NULL) {
		cout << "Error :Tree is empty /n";
		return root;
	}
	else if (root->left == NULL) {
		return root;
	}
	return FindMin(root->left);
}

// Function to search and delete a value from the tree.
 student* admin::Delete(student* root, int st_id) {
	if (root == NULL) return root;
	else if (st_id < root->id) root->left = Delete(root->left,st_id );
	else if (st_id > root->id) root->right = Delete(root->right,st_id);
	// Wohoo... I found you, Get ready to be deleted
	else {
		// Case 1:  No child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if (root->left == NULL) {
			 student* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			 student* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			student* temp = FindMin(root->right);
			root->id = temp->id;
			root->right = Delete(root->right, temp->id);
		}
	}
	return root;

}

//Function to visit nodes in Inorder

void admin::Inorder(student* root) {

	if (root == NULL) return;
	Inorder(root->left);           //Visit left subtree
	//remove_student_id(root->id) ;
	cout<<" - "<<root->id<<endl ;     //Print data
	Inorder(root->right);          // Visit right subtree
}


