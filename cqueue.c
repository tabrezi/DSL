             /*                     Experiment No. 6
                        Title: "Impln of Circular Queue using arrays."
                                                                                                        

                                                          Learner: XYZ
                                                          Roll No. 17CO01
            In this experiment, a program is written to implement circular queue using arrays.
theory about circular queue.
            The program has user defined functions like isFull, insert, delete, search, display and main.
*/
            

            #include<stdio.h>
            #include<unistd.h>
            #include<stdlib.h>
            #define MAX 5

            struct Queue
            {
            int data[MAX];
            int front,rear;
            };

            int isFull(struct Queue *q)
            {
            return (q->front==((q->rear+1)%MAX))?1:0;  //returns 1 if full else 0.
            }

            int insert(struct Queue *q,int d)
            {
            if(isFull(q))
            return 0;
            else
            {
            //q->rear++;
            q->rear=(q->rear+1)%MAX;        //increasing rear circularly using mod(%) operator
            q->data[q->rear]=d;
            if(q->front==-1)                //if first insertion then making front as 0.
            q->front=0;	
            return 1;
            }
            }


            void display(struct Queue *q)
            {
            int i;
            if(q->rear==-1)
            printf("\n\tQueue is Empty->");
            else
            {
            printf("\nQueue Contents ->->\n");
            for(i=q->front;i!=q->rear;i=(i+1)%MAX)          //looping through array circularly
            {
            printf("%d\n",q->data[i]);
            }
            printf("%d\n",q->data[i]);
            }
            }

            void initialize(struct Queue *q)
            {
            q->front=q->rear=-1;
            }

            void delete(struct Queue *q)
            {
            if(q->rear==-1)
            printf("\nQueue is empty..");
            else
            {
            int d;
            d=q->data[q->front];
            if(q->front==q->rear)
            q->front=q->rear=-1;
            else
            q->front=(q->front+1)%MAX;             //increasing rear circularly using mod(%) operator
            printf("\nElement deleted from Queue.");
            }
            }

            int search(struct Queue *q,int k)
            {
            int i;
            for(i=q->front;i!=q->rear;i=(i+1)%MAX)
            if(q->data[i]==k)
            return i;               //returning index of key found

            if(q->data[i]==k)       //checking for last element
            return i;               

            return -1;              //returning -1 since key not found
            }


            int main()              //main function starts here
            {
            int ch,d;
            struct Queue q;
            initialize(&q);
            while(1)
            {
            printf("\n\t\t\tMENU\n1. Insert.\n2. Delete.\n3. Search.");
            printf("\n4. Display.\n5. Exit.");
            printf("\n\tEnter your choice :: ");
            scanf("%d",&ch);
            switch(ch)
            {
            case 1:
            printf("\nEnter Data to be Inserted : ");
            scanf("%d",&d);
            insert(&q,d);
            break;
            case 2:
            delete(&q);
            break;
            case 3:
            printf("\nEnter Data to be Searched : ");
            scanf("%d",&d);
            d=search(&q,d);
            if(d==-1)
            printf("\nKey is not found..");
            else
            printf("\nKey is found at location %d..",d);
            break;
            case 4:
            display(&q);
            break;
            case 5:
            exit(0);
            default:
            printf("\n\tPlease enter correct choice->->->->");
            }
            }
            }

            /*
                Hence we have understood implementation of circular queue using arrays and have 
                understood the advantages of same over linear queue.
            */
