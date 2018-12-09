#include<bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node* left, *right;
};

struct node* newNode(int item){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* search(struct node* root, int key){
	//base code
	if(root == NULL || root->key == key)
		return root;
	
	if(root->key < key)
		return search(root->right);
	
	return search(root->left, key);
}

int main(){
	
}