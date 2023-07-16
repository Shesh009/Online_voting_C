void voting_process()
{
    if(head==0)
    {
        printf("\n\tNo registered voters\n");           //if head==0 then no voters present in the list.
        printf("\tPlease register to vote!!\n");
    }
    else
    {
        printf("Enter your 4 digit voter id : ");
        scanf("%d",&inpid);                         //taking input of voter ID for verification.
        printf("Enter your password : ");
        scanf("%d",&pass);
        while(temp1)
        {
            if(inpid==(temp1->ID))                 //verifying their login details.
            {
                printf("\n\tName : %s",temp1->name);                        //printing their details
                printf("\n\tAge : %d",temp1->age);
                if(temp1->vote==0)
                {
                    printf("\n\n\tWho should be team India's vice captain : ");       //asking to vote.
                    printf("\n\t1.KL Rahul\n\t2.Rishab Pant\n\t3.Shreyas Iyer\n\t4.NOTA\n");
                    printf("Please vote here : ");
                    scanf("%d",&v);
                    if(v==1 || v==2 || v==3 || v==4)
                    {
                        temp1->vote=v;
                        printf("\nThank you for voting!!!\n");
                        break;
                    }
                    else
                    {
                        printf("\nInvalid choice!!\nVote again\n");
                    }
                }
                else
                {
                    printf("\n\t You have already voted!!!\n");
                    break;
                }
            }
            count++;
            temp1=temp1->next;
        }
        if(count==0)
        {
            printf("\n\tInvalid credentials\n\tPlease enter correct details or register first\n");
        }
    }
}