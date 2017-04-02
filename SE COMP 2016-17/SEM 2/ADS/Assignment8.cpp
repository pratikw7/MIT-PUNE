//------Ashwin Vaidya-----\
//-------202030------------
//------AVL----------------
//---------\CC\------------
#include <iostream>
using namespace std;
class cNode{
    string word;
    string meaning;
    cNode* left;
    cNode* right;
    int n;
public:
    cNode(){
        left = NULL;
        right = NULL;
        n=0;
    }
    friend class cBST;
};
class cBST{
    cNode* root;
public:
    cBST(){
        root = NULL;
    }
    void vInsert()
    {
    	cout<<"Enter word: ";
    	string word;
    	cin>>word;
    	vInsert(word,NULL,NULL);
    }
    void vInsert(string word,cNode* next,cNode* prev){
        if(root == NULL){
            root = new cNode();
            root->word.assign(word);
            cout<<"\n Enter meaning "<<word<<endl;
            cin>>(root->meaning);
            root->n=0;
        }else{
            if(next == NULL)
                next = root;
            if(word.compare(next->word)<0){
                if(next->left==NULL){
                    next->left=new cNode();
                    prev=next;
                    next = next->left;
                    next->word.assign(word);
                    cout<<"\n Enter meaning "<<word<<endl;
                    cin>>next->meaning;

                    next->n=iHeight(next->left)-iHeight(next->right);
                    prev->n=iHeight(prev->left)-iHeight(prev->right);

                    return;

                }else{

                    vInsert(word,next->left,next);
                }
            }else if(word.compare(next->word)>0){
                if(next->right==NULL){
                    next->right=new cNode();
                    prev=next;
                    next = next->right;
                    next->word.assign(word);
                    cout<<"\n Enter meaning "<<word<<endl;
                    cin>>next->meaning;


                    next->n=iHeight(next->left)-iHeight(next->right);
                    prev->n=iHeight(prev->left)-iHeight(prev->right);

                    return;
                }else{

                    vInsert(word,next->right,next);
                }
            }else{
                cout<<"\n The word "<<word<<" exists in the dictionary"<<endl;
            }


            next->n=iHeight(next->left)-iHeight(next->right);

            if(next->n == 2  || next->n == -2){              // tree is unbalanced
                        cNode* temp = nRotate(next);
                        if(prev == NULL)
                            root = temp;
                        else {
                            if(prev->left == next)
                                prev->left = temp;
                            else prev->right = temp;
                        }
                        temp->n=iHeight(temp->left)-iHeight(temp->right);
                        temp->left->n=iHeight(temp->left->left)-iHeight(temp->left->right);
                        temp->right->n=iHeight(temp->right->left)-iHeight(temp->right->right);
                    }

        }



    }

    int iHeight(cNode* next){
        if(next==NULL)
            return 0;
        if(next->left ==NULL && next->right == NULL)
            return 1;
        if(next->left != NULL && next->right == NULL)
            return iHeight(next->left)+1;
        if(next->left == NULL && next->right!= NULL)
            return iHeight(next->right)+1;
        int i = iHeight(next->left);
        int j = iHeight(next->right);
        return ((i>j)? i:j)+1;

    }

    cNode* nRotate(cNode* A){
        cNode *B,*C;
        if(A->n == +2 ){                  
            B = A->left;
            if(B->n>0){                   // LL Rotation
                C = B->left;

                A->left = B->right;
                B->right = A;
                cout<<"\n LL rotation \n";
                return B;

            }else{                        // LR Rotation
                C = B->right;

                B->right = C->left;
                A->left = C->right;
                C->left = B;
                C->right = A;
                cout<<"\n LR rotation \n";
                return C;
            }

        }else{                            
            B= A->right;
            if(B->n<0){					  // RR Rotation
                C = B->right;

                A->right = B->left;
                B->left = A;
                cout<<"\n RR rotation \n";
                return B;
            }else{                        // RL Rotation
                C = B->left;

                B->left = C->right;
                A->right = C->left;
                C->left = A;
                C->right = B;
                cout<<"\n RL rotation \n";
                return C;
            }
        }
	}
    void vDisplay()
    {
    	cout<<"Word\tMeaning\t\tHeight\n";
    	vDisplay(NULL);
    }
    void vDisplay(cNode* next)		//Inorder Traversal
    {
        if(root == NULL)
             cout<<"Empty tree!"<<endl;
        else{
        if(next == NULL)
            next = root;
        if(next->left!=NULL)
            vDisplay(next->left);
        cout<<next->word<<"\t"<<next->meaning<<"\t\t"<<next->n<<endl;
        if(next->right!=NULL)
            vDisplay(next->right);
        }
    }

};


int main()
{
	char inp;
	string word;
	cBST T;
	do
	{
		cout<<"1. Insert\n";
		cout<<"2. Display inorder traversal\n";
		cin>>inp;
		switch(inp)
		{
			case '1':
				T.vInsert();
				break;
			case '2':
				T.vDisplay();
				break;
		}
		cout<<"Enter y to continue ";
		cin>>inp;
	} while (inp=='y');
	return 0;
}