    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    typedef struct sPOINT {                                                                 // struct to store our user information x and y coords of a point
            int student_no;
            char fname[10];
            char lname[10];
            char phone[20];
            struct sPOINT* next;                                                                    // pointer to next element of list
    } point;
     
    point *create_element(void);                                                            // function to create a node
    point *add_point(point *start);                                                         // function to add node
    point *remove_point(point *start);                                                      // function to remove a node
    point *element_at_index(point *e, int index);                                   // function to find element at a specific index
    point *add_pointnoinput(point *start,FILE *fp2);
     
    void input(point *p);                                                                           // requests user information
    void write(point *p);                                                                   // writes a particular node
    void write_all(point *p);                                                                       // writes all nodes in list
    int write_to_disk(point *p);
    void input1(point *p,FILE *fp2);
    int counter(void);
     
     
    point *read(point *p);
    void read_all(point *p);
    void display_all(point *p);
    void display(point *p);                                                 // print a point p's user information
     
     
     
     
    int main(void)
    {
            int option;
            point *start=NULL;                                                                      // root node
     
            do                                                                                              // do while loop
            {
                    //Display user menu
                    printf("\n0 - quit\n");
                    printf("1 - add student details\n");
                    printf("2 - remove\n");
                    printf("3 - write all to file\n");
                    printf("4 - read from file\n");
                    printf("5 - make an empty list item and then insert from file\n");
                    printf("Enter option: ");
                    fflush(stdout);
     
                    scanf("%2d", &option);
     
                    //Process option
                    switch (option)                                                                 // switch statement to decide next action
                    {
                            case 1: start = add_point(start);
                                    break;
                            case 2: start = remove_point(start);
                                    break;
                            case 3: write_all(start);
                                    break;
                            case 4:
                            //getchar();
                            start =read(start);
                                    break;
                            case 5:
                            printf("New node added\n");
                    //      start = add_pointnoinput(start);
                            break;
                            case 6:
                           
                            display_all(start);
                            break;
                    }
            }while (option != 0);
     
     
            return 0;
    }
     
    //This function just allocates a single element, and initialises its values
    point *create_element(void)
    {
            point *p = (point*) malloc(sizeof(point));                      // allocate memory
            p->next=NULL;                                                           // set next pointer to NULL
     
    //      p->student_no = 0;                                                                      // initialise user information
            //p->y = "\0";                                                                  // initialise user information
            return p;                                                                       // return pointer to point p
    }
     
    //Adds a new point to the array. start may be NULL.
    point* add_point(point *start)
    {
            point *last;
            point *n = create_element();                                                    // creates new point
     
            input(n);                                                                      
           
            //Add n to the end of the list
            if (start != NULL)                                                     
            {
                    for (last = start; last->next != NULL; last = last->next);      // iterate to end of list
                    last->next = n;                                                                 // add new point to end of list
            }
            else start=n;                                                                           //this element is the new start
     
            return start;
    }
     
    //return a pointer to the element at the specified index
    point *element_at_index(point *e, int index)
    {
            for (; index > 0 && e != NULL; index--, e=e->next);                     // each iteration jumps to the next node - perform this loop index number of times and you reach the desired node
            return e;
    }
     
    point *remove_point(point *start)
    {
            point *rem, *previous;
            int index,count;
     
            if (start == NULL)                                                                              // error checking
            {
                    printf("No elements to remove\n");
                    return start;
            }
     
            printf("Which element index do you want to remove? (starting from 0)\n");
            scanf("%9d", &index);
     
            //The first element is a special case as the 2nd element will become the start
            if (index == 0)
            {
                    point *next = start->next;                                                                      // set pointer
                    free(start);                                                                                            // free memory
                    return next;                                                                                    // return from function
            }
           
            //find the element to remove and the previous element
            rem = element_at_index(start, index);                                                   // find node to remove
            previous = element_at_index(start, index-1);                                            // set previous node (node before node you want to remove)
     
            if (rem == NULL)                                                                                        // if node not found
            {
                    printf("Invalid index: %d\n", index);
                    return start;
            }
     
            previous->next = rem->next;                     // set the previous element to point to the one after the one being removed
            free(rem);                                                      // free memory
            return start;                                           // return from function
    }
     
    //input values into element
    void input(point *p)
    {       char c;
            printf("enter values for first name and last name(e.g. John Doe): \n");         // asks for user input
            scanf("%s %s", &p->fname, &p->lname);                                   // -> syntax used where a pointer to a struct exists
            printf("enter values for student number and phone number (e.g. 112 087912): \n");               // asks for user input
            scanf("%d %s", &p->student_no, &p->phone);                                      // -> syntax used where a pointer to a struct exists
            c=getchar();
            //write(p);
    }
     
    //write a single element
    void write(point *p)                                                    // print a point p's user information
    {
     
           
            FILE *fp1;
            char filename[50];
            fp1= fopen("filename.txt","a");                         //apend the file
            fprintf(fp1,"%s %s %d %s\n", p->fname, p->lname,  p->student_no, p->phone);
    }
     
    //write all elements
    void write_all(point *p)
    {
            int count=0;
            if (p == NULL)                                                          // check if list is NULL
            {
                    printf("No elements in the list!\n");
                    return;
            }
     
            printf("\n\nAll points in the list:\n");
            for (; p != NULL; p = p->next)                                  // iterate over all points and print
            {
                    if (count==0)
                    {
                   
                    printf("%d: ", count++);
                    getchar();
                    write(p);
                    }
                    else
                    {
                    printf("%d: ", count++);
                    write(p);
                    }
            }
            printf("\n\n");
    }
     
     
    void read_all(point *p)
    {
            int count=0;
            if (p == NULL)                                                          // check if list is NULL
            {
                    printf("No elements in the list!\n");
                    return;
            }
     
            printf("\n\nAll points in the list:\n");
            for (; p != NULL; p = p->next)                                  // iterate over all points and print
            {
                    if (count==0)
                    {
                   
                    printf("%d: ", count++);
                    read(p);
                    }
                    else
                    {
                    printf("%d: ", count++);
                    ;
                    }
            }
            printf("\n\n");
    }
     
     
    point *read(point *p)
    {       FILE *fp2;
            char c,d;
            int count1=0,i=0,j=4;
            char temp[50];
                    count1=counter();
            fp2= fopen("filename.txt","r");
           
            //p=add_pointnoinput(p,fp2);
           
     
            printf("****%d*******",count1);
                   
           printf("before loop, count = %d\n", count1);
            printf("%d",j);
            for(i=0;i<count1;i++)
            {
            p=add_pointnoinput(p,fp2);
            }
    }
    point* add_pointnoinput(point *start,FILE *fp2)
    {
            point *last;
            point *n = create_element();                                                    // creates new point
     
            input1(n,fp2);                         
           
            //Add n to the end of the list
            if (start != NULL)                                                     
            {
                    for (last = start; last->next != NULL; last = last->next);      // iterate to end of list
                    last->next = n;                                                                 // add new point to end of list
            }
            else start=n;                                                                           //this element is the new start
     
            return start;
    }
     
    void display_all(point *p)
    {
            int count=0;
            if (p == NULL)                                                          // check if list is NULL
            {
                    printf("No elements in the list!\n");
                    return;
            }
     
            printf("\n\nAll points in the list:\n");
            for (; p != NULL; p = p->next)                                  // iterate over all points and print
            {
                    printf("%d: ", count++);
                    //display(p);
            }
            printf("\n\n");
    }
    void display(point *p)                                                  // print a point p's user information
    {
            //printf("x: %s, y: %d\n", p->fname, p->student_no);
    }
     
    void input1(point *p,FILE *fp2)
     
    {
     
            fscanf(fp2,"%s %s %d %s\n", &p->fname, &p->lname,&p->student_no,&p->phone);
            printf("***pest**");            // asks for user input
                   
    }
    int counter()
    {       FILE *fp1;
            char temp[50];
            int count2;
           
            fp1= fopen("filename.txt","r");
           
            //p=add_pointnoinput(p,fp2);
            char buffer[BUFSIZ];
            count2 = 0;
            printf("test");
            while (fgets(buffer, sizeof buffer, fp1) != NULL)
            {
                   
                    count2 ++;
            }rewind(fp1);
            close(fp1);
            return count2;
           
    }
