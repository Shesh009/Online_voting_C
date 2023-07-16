//creating a project for voting online.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

//creating a node of type structure to store information of candidate.
struct node
{
    char name[35];              //accepts name in list.
    char dob[11];                   //accepts date of birth of user in ddmmyyyy format.
    int age;                 //accepts age in list.
    char gender[2];                //accepts the gender of the user.
    char mobile[12];                //accepts the mobile number of the user.
    int ID;                  //It is the output given by us to a particular candidate.
    int password;                //needed to created by the user.
    int vote;                  //It is the input given by the member.
    struct node *next;          //next pointer to hold the next address link.
}*head=0,*newnode,*temp,*temp1;

int i,pass,inpid,v,ch1,ch2,ch3,ver,kl=0,rp=0,si=0,count=0,d,j=0;

void add_record(struct node *temp)
{
    FILE *fp;
    fp=fopen("Registered_Voters1.csv","ab+");
    if(fp==NULL)
    {
        printf("File cannot be opened");
        return;
    }
    fprintf(fp,"\n");
    fwrite(&temp,sizeof(temp),1,fp);
    fclose(fp);
}

void display_record()
{
    FILE *fp;
    fp=fopen("Registered_Voters1.csv","rb");
    if(fp==NULL)
    {
        printf("No contents in the file\n");
        getch();
    }
    else
    {
        printf("\nRegistered Voters details\n");
        while(fread(&temp,sizeof(temp),1,fp)==1)
        {
            printf("\nName : ",temp->name);
            printf("\nDate of birth : ",temp->dob);
            printf("\nAge : ",temp->age);
            printf("\nGender : ",temp->gender);
            printf("\nMobile : ",temp->mobile);
            printf("\n\n");
        }
        char myString[1000];
        fread(&myString,sizeof(char),1000, fp);
        printf("%s", myString);
        getch();
    }
}

/* void file_storing(struct node *temp,FILE *fp)
{
    if(temp->vote==0)
    {
        fprintf(fp,"%s,",temp->name);                   //printing the name of the user.
        fprintf(fp,"%s,",temp->dob);           //printng date of birth of user in ddmmyyyy format.
        fprintf(fp,"%d,",temp->age);                      //printing the age of the user.
        fprintf(fp,"%s,",temp->gender);                //printing the gender of the user.
        fprintf(fp,"%s,",temp->mobile);         //printing the mobile number of the user.
        fprintf(fp,"%d,",temp->ID);                  //printing voter ID of the user.
        fprintf(fp,"%d",temp->password);            //printing the password of the user.
        fprintf(fp,"\n");
    }
    else
    {
        fprintf(fp,"%d,",temp->ID);
        fprintf(fp,"%d",temp->vote);
        fprintf(fp,"\n");
    }
    fclose(fp);
} */

void Register()                                         //registration process for users.
{
    system("cls");
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter your details to register : ");
    printf("\n\tEnter your name : ");
    fflush(stdin);
    scanf("%[^\n]c",newnode->name);
    printf("\tDate of birth[dd/mm/yyyy] : ");
    fflush(stdin);
    scanf("%[^\n]c",newnode->dob);
    printf("\tAge : ");                                 //taking users age.
    scanf("%d",&newnode->age);
        printf("\tGender[M/F] : ");
        scanf("%s",newnode->gender);
        printf("\tEnter your mobile number : ");
        fflush(stdin);
        scanf("%[^\n]c",newnode->mobile);
        fflush(stdin);
        printf("\tCreate a 6 digit voter ID : ");
        scanf("%d",&newnode->ID);
        printf("\tEnter your own password(contain 4 digits) : ");            //asking to create their password.
        fflush(stdin);
        scanf("%d",&newnode->password);
        system("cls");
        printf("\n\tYour Voter ID is : %u\n",newnode->ID);      //giving voter ID
        printf("\tYour password is : %d\n",newnode->password);
        printf("\tPlease save it for further process!!!\n");
        getch();
        system("cls");
    newnode->vote=0;
    /*FILE *fp=fopen("Registered_Voters1.csv","a+");
    file_storing(newnode,fp);*/
    add_record(newnode);
    if(head==0)
    {
        head=temp=newnode;                  //assigning newly created node to beginning of the list if head pointer is null.
        newnode->next=0;
    }
    else
    {
        newnode->next=head;                 //inserting node in the beginning of the list before head.
        head=newnode;
    }
    //fclose(fp);
}

void voting_process()                                   //defining voting process.
{
    int vp=0,pass_vp;
    if(head==0)
    {
        printf("\n\n\tNo registered voters\n");           //if head==0 then no voters present in the list.
        printf("\tPlease register to vote!!\n");
        getch();
    }
    else
    {
        system("cls");
        printf("\n\tEnter your Voter ID : ");
        scanf("%d",&inpid);                                 //verifying voteer ID.
        printf("\tEnter your password : ");
        scanf("%d",&pass_vp);                                  //verifying password.
        temp=head;
        while(temp)
        {
            if(inpid==temp->ID && pass_vp==temp->password )            //verifying password and login ID.
            {
                vp++;
                system("cls");
                printf("\n\tName : %s",temp->name);                   //checking the list and details of voters.
                printf("\n\tDate of birth[dd/mm/yyyy] : %s",temp->dob);
                printf("\n\tAge : %d",temp->age);
                printf("\n\tGender : %s",temp->gender);
                printf("\n\tMobile number : %s",temp->mobile);
                if(temp->vote==0)
                {
                    printf("\n\n\tWhich programming language is better for AIML students : ");       //asking to vote.
                    printf("\n\t1.JAVA\n\t2.PYTHON\n\t3.NOTA\n");
                    printf("Please vote here : ");
                    scanf("%d",&v);
                    if(v==1 || v==2 || v==3)                        //verifying whetehr the option present in the list.
                    {
                        temp->vote=v;
                        printf("\x1b[31m""\nThank you for voting!!!\n""\x1b[0m");              //showing vote is completed.
                        /*FILE *fp2=fopen("Completed_Voters.csv","a+");
                        file_storing(temp,fp2);
                        fclose(fp2);*/
                        getch();
                        break;
                    }
                    else
                    {
                        printf("\nInvalid choice!!\nVote again\n");         //showing the option is invalid.
                        break;
                        getch();
                    }
                }
                else
                {
                    printf("\n\n\tYou have already voted!!!\n");            //showing that already vote is done.
                    getch();
                    break;
                }
            }
            temp=temp->next;                                                 //traversing temp pointer over the list.
        }
        if(vp==0)
        {
            printf("\n\n\tIncorrect credentials\n\tTry again.\n");
            getch();
        }
    }
}

void display()                                              //function to display the information in the list.
{
    if(head==0)
    {
        printf("\n\tNo data in the list\n");                //if head is not pointing to any node then list is empty. 
        getch();
    }
    else
    {
        temp=head;
        system("cls");
        while(temp)
        {                                                   
            printf("\n\tName : %s",temp->name);                   //printing the name of the user.
            printf("\n\tDate of birth[dd/mm/yyyy] : %s",temp->dob);           //printng date of birth of user in ddmmyyyy format.
            printf("\n\tAge : %d",temp->age);                      //printing the age of the user.
            printf("\n\tGender : %s",temp->gender);                //printing the gender of the user.
            printf("\n\tMobile Number : %s",temp->mobile);         //printing the mobile number of the user.
            printf("\n\tVoter ID : %d",temp->ID);                  //printing voter ID of the user.
            printf("\n\tPassword : %d",temp->password);            //printing the password of the user.
            printf("\n\tVote : %d",temp->vote);                    //printing the vote voted by the user.
            printf("\n\n");
            temp=temp->next;                                       //traversing the temp over the list.
        }
        getch();
    }
}

void winner()                                               //function to show who's the winner.
{
     if(head==0)                                            //if no node is present.
     {
        printf("\n\tNo Voting is done\n");                  //if head is equal to 0 voting is not done.
        getch();
     }
     else
     {
        temp=head;                                          //pointing head to temp for traversal.
        while(temp!=0)                                      //running loop upto temp pointing to any node.
        {
            if(temp->vote==1)                               
                kl++;                                       //counting the no.of votes of participant 1.
            else if(temp->vote==2)
                rp++;                                       //counting the no.of votes of participant 2.

            temp=temp->next;                                //traversing temp by moving temp to next node.
        }
            system("cls");
            if(kl>rp)
            {
                printf("\n\tJAVA won by %d votes\n\n",(kl-rp));getch();               
            }
            else if(rp>kl)
            {
                printf("\n\tPYTHON won by %d votes\n\n",(rp-kl));getch();
            }
            else
            {
                printf("\n\tVoting is tied\n");getch();
            }
     }
}

void search()                                                   //program to search a voter by name (or) id (or) checking range of age.
{
    int ID1,c=0;
    temp=head;
    if(head==0)
    {
        printf("\n\tList is empty.\n");getch();
    }
    else
    {
        system("cls");
        printf("\tEnter the ID age you want to search : ");            //accepting voter ID of the list to search.
        scanf("%d",&ID1);
        while(temp)                                                    //traversing the list upto end.
        {
            if(temp->ID == ID1)
            {
                printf("\n\tName : %s",temp->name);                   //printing the name of the user.
                printf("\n\tDate of birth[dd/mm/yyyy] : %s",temp->dob);
                printf("\n\tAge : %d",temp->age);                      //printing the age of the user.
                printf("\n\tGender : %s",temp->gender);                //printing the gender of the user.
                printf("\n\tMobile Number : %s",temp->mobile);         //printing the mobile number of the user.
                printf("\n\tVoter ID : %d",temp->ID);                  //printing voter ID of the user.
                printf("\n\tPassword : %d",temp->password);            //printing the password of the user.
                printf("\n\tVote : %d",temp->vote);                    //printing the vote voted by the user.
                printf("\n\n");
                c++;
                getch();
            }
            temp=temp->next;
        }
        if(c==0)
        {
            printf("\tUser is not found with the ID");
            getch();
        }
    }
}

void help_for_ec()                                                          //function for help for election committee member
{
    system("cls");
    printf("STEPS TO BE FOLLOWED BY THE ELECTION COMMITEE MEMBER\n");
    printf("----------------------------------------------------\n");
    printf("1.Enter the unique login ID.\n");
    printf("2.There are 3 options : \n\t1.Registered candidates list\n\t2.Winner\n\t3.Search the user\n");
    printf("3.Select any one of the options.\n");
    printf("4.1st option shows voters list.\n  2nd option shows the winner.\n  3rd option shows the way to search registered user.\n");
    printf(" 4th option show you the way to exit.");
    getch();
}

void help_for_voters()                                                          //help for voters.
{
    system("cls");
    printf("STEPS TO BE FOLLOWED BY THE VOTERS\n");
    printf("----------------------------------\n");
    printf("1.First register in the voter's section through your details.\n");
    printf("2.Keep your login details protected.\n");
    printf("3.Vote in the voting section.\n");
    getch();
}

void change_password()
{
    int id2,cp=0,pass_cp,pass_cp1;
    system("cls");
    printf("Enter your 4 digit voter ID : ");
    scanf("%d",&id2);
    printf("Enter your old password : ");
    scanf("%d",&pass_cp);
    temp=head;
    if(head==0)
    {
        printf("\n\tNo users in the list.\n");getch();
    }
    else
    {
        while(temp)
        {
            if(temp->ID==id2 && pass_cp==temp->password)
            {
                system("cls");
                printf("\n\tName : %s",temp->name);                   //printing the name of the user.
                printf("\n\tDate of birth[dd/mm/yyyy] : %s",temp->dob);
                printf("\n\tAge : %d",temp->age);                      //printing the age of the useer.
                printf("\n\tGender : %s",temp->gender);                //printing the gender of the user.
                printf("\n\tMobile Number : %s",temp->mobile);         //printing the mobile number of the user.
                int i=0;
                printf("\n\n\tEnter your new password : ");
                scanf("%d",&pass_cp1);
                temp->password=pass_cp1;
                printf("\n\n\tYour password is updated....\n");
                cp++;
                getch();
            }
            temp=temp->next;
        }
        if(cp==0)
        {
            printf("\n\tInvalid credentials \n\tUser not found\n");getch();
        }
    }
}

int verify(char* name1,char* name2)
{
    int na=0,i=0;
    while(name1[i]!='\0')
    {
        if(name1[i]!=name2[i])
        {
            na=2;
            break;
        }
        i++;
    }
    if(na==2)
        return 1;
    else
        return 0;
}

void know_id()
{
    char name_id[35],mob_id[12],dob_id[12];

    temp=head;
    if(head==0)
    {
        printf("\n\tNo voters is registered\n");
        getch();
    }
    else
    {
        system("cls");
        printf("Enter your name : ");
        fflush(stdin);
        scanf("%[^\n]%*c",name_id);
        printf("Enter your date of birth : ");
        fflush(stdin);
        scanf("%[^\n]%*c",dob_id);
        printf("Enter your mobile number : ");
        fflush(stdin);
        scanf("%[^\n]%*c",mob_id);
        int n_id=verify(name_id,temp->name);
        int d_id=verify(dob_id,temp->dob);
        int m_id=verify(mob_id,temp->mobile);
        while(temp)
        {
            if(n_id==0 && d_id==0 && m_id==0)
            {
                printf("\tYour voter ID is : ",temp->ID);
                getch();
                break;
            }
            temp=temp->next;
        }
    }
}

void forgot_password()
{
    char name_fp[35],dob_fp[12],mob_fp[11];
    int id_fp,fp=0,v_fp,pass_fp;
    system("cls");
    printf("Enter your name : ");
    fflush(stdin);
    scanf("%[^\n]%*c",name_fp);
    printf("Enter your date of birth [dd/mm/yyyy] : ");
    fflush(stdin);
    scanf("%[^\n]%*c",dob_fp);
    printf("Enter your mobile number : ");
    fflush(stdin);
    scanf("%[^\n]%*c",mob_fp);
    printf("Enter your 4 digit voter ID : ");
    scanf("%d",&id_fp);
    temp=head;
    if(head==0)
    {
        printf("\n\tNo users found!!\n");getch();
    }
    else
    {
        while(temp)
        {
            int n_fp=verify(name_fp,temp->name);
            int d_fp=verify(dob_fp,temp->dob);
            int m_fp=verify(mob_fp,temp->mobile);
            if(id_fp==temp->ID && n_fp==0 && d_fp==0)
            {
                system("cls");
                printf("\n\tName : %s",temp->name);                   //printing the name of the user.
                printf("\n\tDate of birth[ddmmyyyy] : %s",temp->dob);
                printf("\n\tAge : %d",temp->age);                      //printing the age of the useer.
                printf("\n\tGender : %s",temp->gender);                //printing the gender of the user.
                printf("\n\tMobile Number : %s",temp->mobile);         //printing the mobile number of the user.

                printf("\n\n\tEnter your new password : ");
                scanf("%d",&pass_fp);
                temp->password=pass_fp;
                printf("\n\nYour password is updated...");
                fp++;
                getch();
            }
            temp=temp->next;
        }
        if(fp==0)
        {
            printf("\n\tUser is not found\n\tInvalid credentials\n");getch();
        }
    }
}

void ec_members()
{
    FILE *fp3=fopen("EC_members.txt","r+");
    char ch;
    if(fp3==NULL)
    {
        printf("\n\tFile is empty.\n");
        getch();
    }
    else
    {
        system("cls");
        while(ch!=EOF)
        {
            ch=fgetc(fp3);
            printf("%c",ch);
        }
        getch();
        fclose(fp3);
    }
}

void election_committe()
{
    int unqID,choice,choice1;
    system("cls");
    printf("\n\tEnter your unique login ID : ");                           //asking user to enter his login ID.
    scanf("%d",&unqID);
    do
    {
        if(unqID==1261)
        {
            system("cls");
            printf("\tWELCOME SHESHU\n");                               //welcome message.
            printf("\t--------------\n");
            printf("What you wanted to see : ");
            printf("\n1.Registered candidates list\n2.Winner of the poll\n3.Search the user by ID\n4.Election Committe members\n5.exit");
            printf("\nEnter your choice : ");                                           //asking user to enter the choice.
            scanf("%d",&choice);
            while(choice!=5)
            {
                if(choice==1)
                {
                    display_record();break;                                    //calling display function.
                }
                else if(choice==2)
                {    
                    winner();break;                                     //calling winner function.
                }
                else if(choice==3)
                {
                    search();break;
                }
                else if(choice==4)
                {
                    ec_members();break;
                }
                else
                {
                    printf("\n\tChoose correct option!!\n");getch();break;
                }
            }
        }
        else
        {
            printf("\n\tIncorrect login credentials\n");getch();                //telling user to enter correct crdentials.
            break;
        }
    }while(choice!=5);
}

void main()
{
    while(1)
    {
        system("cls");
        printf("MAIN MENU\n");
        printf("---------\n");
        printf("1.Election committe member\n2.Voter\n3.help\n4.exit\n");
        printf("\nSelect your choice : ");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:election_committe();break;                               //calling election committe function. 
            case 2:
            {
                system("cls");
                printf("\nWhat's your operation");
                printf("\n\t1.Register\n\t2.Vote\n\t3.change password\n\t4.forgot password\n\t5.know your voter ID\n\t6.exit");               
                printf("\nSelect your choice : ");
                scanf("%d",&ch2);
                switch(ch2)
                {
                    case 1:Register();break;                                       //calling register function to register.
                    case 2:voting_process();break;                                     //calling voting function to vote.
                    case 3:change_password();break;
                    case 4:forgot_password();break;
                    case 5:know_id();break;
                    case 6:break;
                    default:printf("\n\n\tInvalid choice!!\n\tTry again");getch();break;
                }
            }break;
            case 3:
            {
                system("cls");
                printf("HELP FOR : ");
                printf("\n1.Election commitee");
                printf("\n2.Voter\n3.exit");
                printf("\nSelect your option : ");
                scanf("%d",&d);
                switch(d)
                {
                    case 1:help_for_ec();break;
                    case 2:help_for_voters();break;
                    case 3:break;
                    default:printf("\n\tInvalid choice!!\n\tTry again\n");getch();break;
                }
            }break;
            case 4:exit(-1);                                                            //exiting from the function.
            default:printf("\n\nInvalid choice!!\nTry again\n");getch();
        }
    }
}