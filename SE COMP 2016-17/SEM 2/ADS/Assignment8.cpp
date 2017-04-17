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
	cNode* find_min()
	{
	cNode *curr=this;
	while(curr->left!=NULL)
		curr=this->left;
	return curr;
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
	vDisplay();
    }
    void vInsert(string word,cNode* next,cNode* prev){
        if(root == NULL){
            root = new cNode();
            root->word.assign(word);
            cout<<"\nEnter its meaning "<<word<<endl;
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
                cout<<"\nLL Rotation \n";
                return B;

            }else{                        // LR Rotation
                C = B->right;

                B->right = C->left;
                A->left = C->right;
                C->left = B;
                C->right = A;
                cout<<"\nLR Rotation \n";
                return C;
            }

        }else{                            
            B= A->right;
            if(B->n<0){					  // RR Rotation
                C = B->right;

                A->right = B->left;
                B->left = A;
                cout<<"\nRR Rotation \n";
                return B;
            }else{                        // RL Rotation
                C = B->left;

                B->left = C->right;
                A->right = C->left;
                C->left = A;
                C->right = B;
                cout<<"\nRL Rotation \n";
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
    void vModify()
    {
	cNode *temp;
	temp=root;
	string  word;
	cout<<"Enter word whose meaning you want to modify:";
	cin>>word;
	while (word !=temp->word && temp!=NULL)
	{
		if (word > temp->word)
			temp=temp->right;
		else
			temp=temp->left;

	}
	if(temp!=NULL)
	{
		cout<<"Enter new meaning :";
		cin>>temp->meaning;
	}
	else
	{
		cout<<"Word not in dictionary, search on google\n";
	}
    }
void vDelete()
{
	string word;
	cout<<"Enter word to be deleted:";
	cin>>word;
	root=vDelete(root,word);
	cout<<"Word deleted\n";
}

cNode* vDelete(cNode *curr,string word)
{

	if(curr==NULL)
	{
		cout<<"\nWord not in dictionary, search on google";
		return curr;
	}

	if (word < curr->word)
	{
		curr->left=vDelete(curr->left,word);
		return curr;
	}

	if (word > curr->word)
	{
		curr->right=vDelete(curr->right,word);
		return curr;
	}
	if(curr->left==NULL && curr->right==NULL)
	{
		cNode *temp=curr;
		delete temp;
		return NULL;
	}
	if(curr->left==NULL)
	{
		cNode *temp=curr;
		curr=curr->right;
		delete temp;
		return curr;
	}
	if(curr->right==NULL)
	{
		cNode *temp=curr;
		curr=curr->left;
		delete temp;
		return curr;
	}
	cNode *temp=curr->right->find_min();
	curr->word=temp->word;
	curr->right=vDelete(curr->right,temp->word);
	return curr;


}
    void vSearch()
    {
	cNode *temp;
	int flag=0;
	temp=root;
	string word;
	cout<<"Enter word to be searched:";
	cin>>word;

	flag=0;
	while(flag==0 && temp!=NULL){

		if(word==temp->word){
			cout<<"Word: "<<temp->word;
			cout<<"\nMeaning: "<<temp->meaning;
			cout<<endl;
			flag=1;
		}

		else if (word > temp->word)
			temp = temp->right;
		else
			temp = temp->left;
	}

	if(flag==0)
		cout<<"Word not in dictionary,search on google "<<endl;
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
		cout<<"3. Search\n";
		cout<<"4. Modify\n";
		cout<<"5. Delete\n";
		cin>>inp;
		switch(inp)
		{
			case '1':
				T.vInsert();
				break;
			case '2':
				T.vDisplay();
				break;
			case '3':
				T.vSearch();
				break;
			case '4':
				T.vModify();
				break;
			case '5':
				T.vDelete();
		}
		cout<<"Enter y to continue ";
		cin>>inp;
	} while (inp=='y');
	return 0;
}
/*------OUTPUT------
1. Insert
2. Display inorder traversal
1
Enter word: mar

Enter its meaning mar
dsfg
Word	Meaning		Height
mar	dsfg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: may

 Enter meaning may
dfg
Word	Meaning		Height
mar	dsfg		-1
may	dfg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: nov

 Enter meaning nov
drg

RR Rotation 
Word	Meaning		Height
mar	dsfg		0
may	dfg		0
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: aug

 Enter meaning aug
fg
Word	Meaning		Height
aug	fg		0
mar	dsfg		1
may	dfg		1
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: apr

 Enter meaning apr
dfg

LL Rotation 
Word	Meaning		Height
apr	dfg		0
aug	fg		0
mar	dsfg		0
may	dfg		1
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: jan

 Enter meaning jan
dfg

LR Rotation 
Word	Meaning		Height
apr	dfg		0
aug	fg		0
jan	dfg		0
mar	dsfg		0
may	dfg		-1
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: dec

 Enter meaning dec
sfd
Word	Meaning		Height
apr	dfg		0
aug	fg		-1
dec	sfd		0
jan	dfg		1
mar	dsfg		1
may	dfg		-1
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: july

 Enter meaning july
df
Word	Meaning		Height
apr	dfg		0
aug	fg		-1
dec	sfd		0
jan	dfg		0
july	df		0
mar	dsfg		1
may	dfg		-1
nov	drg		0
Enter y to continue y
1. Insert
2. Display inorder traversal
1
Enter word: feb

 Enter meaning feb
df

RL Rotation 
Word	Meaning		Height
apr	dfg		0
aug	fg		1
dec	sfd		0
feb	df		0
jan	dfg		0
july	df		0
mar	dsfg		1
may	dfg		-1
nov	drg		0
Enter y to continue 


*/
