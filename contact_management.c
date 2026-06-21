#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct project{
	char name[100];
	unsigned long long int phonenumber;
	struct project *next;
};
int i,j;
struct project *sort(struct project *head,int i);
void display(struct project *head);
struct project *addcontact(struct project *head);
struct project *delcontact(struct project *head);
struct project *createnewcontact();
void searchcontact(struct project *head);
int main(){
	struct project *head=NULL,*temp=NULL,*newcontact=NULL;
	int n,operation;
	unsigned long long int phonenumber;
	char name[100];
	printf("Enter number of contacts to create:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	    head=sort(head,i);
	}
	while(1){
	printf("1)Add Contact\n2)Search contact\n3)Delete Contact\n4)Display Contact\n0)Exit\n");
	scanf("%d",&operation);
	switch(operation){
	case 1:
	head=addcontact(head);
	if(j!=0){
		printf("Contact added\n");
	}
	else{
	printf("Duplicate contact not added\n");
}
	display(head);
	break;
	case 2:
	searchcontact(head);
	break;
	case 3:
	head=delcontact(head);
	display(head);
	break;
	case 4:
	display(head);
	break;
	case 0:
	printf("Exiting..");
	return 0;
	default :
	printf("wrong selection!!\n");
  }
}
return 0;
}
struct project *sort(struct project *head,int i){
	struct project *newcontact,*temp;
	int count=1;
	j=1;
		newcontact=(struct project*)malloc(sizeof(struct project));
		printf("Enter name for contact %d:\n",i);
		scanf(" %99[^\n]", newcontact->name);
		printf("Enter phone number of %s:",newcontact->name);
		scanf("%llu",&newcontact->phonenumber);
		newcontact->next=NULL;
		temp=head;
		while(temp!=NULL){
			if((strcmp(temp->name,newcontact->name)==0)&&(temp->phonenumber==newcontact->phonenumber)){
				printf("Duplicate contact found %s and with same phone number %llu\n",newcontact->name,newcontact->phonenumber);
				free(newcontact);
				j=0;
				return head;
			}
			if(strcmp(temp->name,newcontact->name)==0){
				printf("The newcontact have same name in the list \n");
					printf("%d)In the list of contact name called %s\n",count,temp->name);
					printf("Please enter new name for contact number %llu:\n",newcontact->phonenumber);
					scanf(" %99[^\n]", newcontact->name);
				}
				if(temp->phonenumber==newcontact->phonenumber){
					printf("The phonenumber already exist for %s\n",temp->name);
					printf("Please enter another phonenumber for this contact %s:\n",newcontact->name);
					scanf("%llu",&newcontact->phonenumber);	
				}
			temp=temp->next;
			count=count+1;
		}
	if(head==NULL||strcmp(newcontact->name,head->name)<0){
		newcontact->next=head;
		head=newcontact;
		return head;
	}
	temp=head;
	while(temp->next!=NULL&&strcmp(newcontact->name,temp->next->name)>0){
		temp=temp->next;
	}
	newcontact->next=temp->next;
	temp->next=newcontact;
	return head;
}
void display(struct project *head){
	if(head==NULL){
		printf("No contacts found\n");
		return;
	}
	struct project *temp;
	temp=head;
	while(temp!=NULL){
		printf("Name: %s-",temp->name);
		printf("Phone number:%llu\n",temp->phonenumber);
		temp=temp->next;
	}
}
struct project *createnewcontact(){
	struct project *newcontact;
	newcontact=(struct project*)malloc(sizeof(struct project));
	if(newcontact==NULL){
		printf("Contact creation failed\n");
		exit(1);
	}
		printf("Enter newcontact name:");
	    scanf(" %99[^\n]",newcontact->name);
		printf("Enter phone number of %s:",newcontact->name);
		scanf("%llu",&newcontact->phonenumber);
		newcontact->next=NULL;
		return newcontact;
	
}
struct project *addcontact(struct project *head){
	head=sort(head,i);
	i++;
	return head;
}
struct project *delcontact(struct project *head){
	if(head==NULL){
		printf("contact not found\n");
		return head;
	}
	struct project *temp1,*temp2;
	temp1=head;
	temp2=head->next;
	char name[100];
	printf("Enter contact name or phone number to delete:");
	scanf(" %99[^\n]",name);
	unsigned long long int phonenumber=atoll(name);
	if(strcmp(temp1->name,name)==0||phonenumber==temp1->phonenumber){
		head=head->next;
		free(temp1);
		printf("Contact Deleted\n");
		return head;
	}
	while(temp2!=NULL){
		if(strcmp(name,temp2->name)==0||phonenumber==temp2->phonenumber){
			temp1->next=temp2->next;
			free(temp2);
			printf("Contact Deleted\n");
			return head;
		}
			temp1=temp1->next;
			temp2=temp2->next;
	}
	printf("contact not found to delete\n");
	return head;
}
void searchcontact(struct project *head){
	struct project *temp;
	temp=head;
	char name[100];
	printf("Enter contact to search or phone number:\n");
	scanf(" %99[^\n]",name);
	unsigned long long int phonenumber=atoll(name);
	if(temp==NULL){
		printf("No contacts are there\n");
		return;
	}
	while(temp!=NULL){
	if(strcmp(name,temp->name)==0||phonenumber==temp->phonenumber){
		printf("Contact found\n");
		printf("Name: %s\n",temp->name);
		printf("Phone number: %llu\n",temp->phonenumber);
		return;
	}
	temp=temp->next;
   }
   printf("Contact not found\n");
}
