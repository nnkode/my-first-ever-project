#include<stdio.h>
#include<string.h>
struct item
{
    char name[100];
    int c;
    float price;
};
float calc(float firstt, char ab, float secondd)
{
    float result;
    switch(ab)
    {
    case '+':
    {
        result = firstt + secondd;
        return result;
        break;
    }
    case '-':
    {
        result = firstt - secondd;
        return result;
        break;
    }
    case '*':
    {
        result = firstt * secondd;
        return result;
        break;
    }
    case '/':
    {
        result = firstt / secondd;
        return result;
        break;
    }
    }
}
int main()
{
    struct item f[100],ff[100],add[100];
    FILE *fp;
    FILE *fc;
    FILE *fd;
    FILE *fptr;
    FILE *fpt;
    FILE *fff;
    FILE *fpp, *fdd, *fpo;
    fc = fopen("menuu.txt","a");
    fd = fopen("menuu.txt","a");
    fp = fopen("store.txt","a");
    fptr = fopen("menuu.txt","r");
    fpt = fopen("menuu.txt","r");
    fff = fopen("store.txt","r");
    fpp = fopen("del.txt","a");
    fpo = fopen("del.txt","a");
    fdd = fopen("del.txt","r");
    int a,p,am,c,i,j,num,i1,i2,k1,k2,k3,k4,dell;
    float first,second,r;
    char n[100],name[100],ch,op,singleline[2000];

    printf("**********NK'S ONLINE SUPERSHOP**********\n\n");
    printf("-----------------WELCOME!---------------\n\n");
    printf("CHOOSE OPTION->\n");
    printf("[PRESS 1 FOR ADMIN]\n\n[PRESS 2 FOR CUSTOMER]\n\n[PRESS 3 FOR DELIVERY MAN]\n\n[PRESS 0 TO EXIT]\n\n");

    scanf("%d",&a);
    if(a==0)
    {
        return 0;
    }
    else if(a==1)
    {
        printf("Enter Admin Name: ");
        fflush(stdin);
        gets(n);
        fflush(stdin);
        printf("Enter numerical pin: ");
        if(strcmp(n,"Sara")==0)
        {
            scanf("%d",&p);
            if(p==1234)
            {
                printf("Logged in successfully.\n\n");

                printf("CREATE MENU IF NOT DONE ALREADY-----[PRESS 1]\n");
                printf("DELIVERY INFO-----------------------[PRESS 2]\n");
                printf("ADD ITEMS---------------------------[PRESS 3]\n");
                printf("EXIT--------------------------------[PRESS 4]\n");
                scanf("%d",&am);
                switch(am)
                {
                case 1:
                {
                    printf("\nCREATE MENU \n\n");
                    printf("Enter number of food items and fashion items: ");
                    scanf("%d%d",&k1, &k2);
                    printf("FOOD MENU: \n");
                    for(i=0; i<k1; i++)
                    {
                        printf("\nProduct CODE: ");
                        scanf("%d",&f[i].c);
                        printf("Product Name: ");
                        fflush(stdin);
                        gets(f[i].name);
                        fflush(stdin);
                        printf("Product Price: $");
                        scanf("%f",&f[i].price);
                    }
                    printf("\nFASHION MENU: \n");
                    for(j=0; j<k2; j++)
                    {
                        printf("\nProduct CODE: ");
                        scanf("%d",&ff[i].c);
                        printf("Product Name: ");
                        fflush(stdin);
                        gets(ff[i].name);
                        fflush(stdin);
                        printf("Product Price: $");
                        scanf("%f",&ff[i].price);
                    }
                    fflush(stdin);
                    if(fc==NULL)
                    {
                        printf("Error! FILE NOT FOUND");
                        return 0;
                    }
                    else
                    {
                        fputs("Food Menu",fc);
                        for(i=0; i<k1; i++)
                        {
                            fprintf(fc,"\nProduct CODE: %d",f[i].c);
                            fprintf(fc,"\nProduct Name: %s",f[i].name);
                            fprintf(fc,"\nProduct Price: $%f\n",f[i].price);
                        }
                        fputs("Fashion Menu",fc);
                        for(j=0; j<k2; j++)
                        {
                            fprintf(fc,"\nProduct CODE: %d",ff[i].c);
                            fprintf(fc,"\nProduct Name: %s",ff[i].name);
                            fprintf(fc,"\nProduct Price: $%f\n",ff[i].price);
                        }
                        fclose(fc);
                    }
                    return 0;
                }
                case 2:
                {
                    printf("Menu for reference\n");
                    if(fpt!=NULL)
                    {
                        while(!feof(fpt))
                        {
                            fgets(singleline, 2000, fpt);
                            puts(singleline);
                        }
                        fclose(fpt);
                    }

                    printf("\nORDER INFORMATION: \n\n");

                    if(fff==NULL)
                    {
                        printf("No order has been placed.");
                        return 0;
                    }
                    else
                    {
                        while(!feof(fff))
                        {
                            fgets(singleline, 2000, fff);
                            puts(singleline);
                        }
                        fclose(fff);
                    }
                    printf("\nCalculate total bill: \n");
                    printf("Enter value: \n");
                    scanf("%f",&first);
                    printf("Enter operator: ");
                    fflush(stdin);
                    scanf("%c",&op);
                    fflush(stdin);
                    printf("Enter value: \n");
                    scanf("%f",&second);
                    r = calc(first,op,second);
                    printf("\nTotal bill = $%.2f",r);
                    if(fpo!=NULL)
                    {
                        fprintf(fpo,"Total Bill: %f", r);
                        fclose(fpo);
                    }
                    printf("\nThis order has been sent to deliver.");
                    return 0;
                }
                case 3:
                {
                    printf("Enter the number of items to add: ");
                    scanf("%d",&k3);
                    for(i=0; i<k3; i++)
                    {
                        printf("\nProduct CODE: ");
                        scanf("%d",&add[i].c);
                        printf("Product Name: ");
                        fflush(stdin);
                        gets(add[i].name);
                        fflush(stdin);
                        printf("Product Price: $");
                        scanf("%f",&add[i].price);
                    }
                    if(fd!=NULL)
                    {
                        for(i=0; i<k3; i++)
                        {
                            fprintf(fc,"\nProduct CODE: %d",add[i].c);
                            fprintf(fc,"\nProduct Name: %s",add[i].name);
                            fprintf(fc,"Product Price: $%f\n",add[i].price);
                        }
                        fclose(fd);
                    }
                }
                case 4:
                {
                    return 0;
                }
                }
            }
            else
            {
                printf("Wrong pin, try again.");
                return 0;
            }
        }
    }
    else if(a==2)
    {
        printf("WELCOME DEAR CUSTOMER!\n\n");
        if(fptr!=NULL)
        {
            while(!feof(fptr))
            {
                fgets(singleline, 2000, fptr);
                puts(singleline);
            }
            fclose(fptr);
        }
        printf("PROVIDE YOUR DETAILS & SELECT ITEMS TO PLACE AN ORDER: \n");
        printf("Name: ");
        fflush(stdin);
        gets(name);
        fflush(stdin);
        printf("Contact Number: ");
        scanf("%d",&num);
        printf("Item codes: (please enter only 2 codes at a time)\n");
        scanf("%d%d",&i1,&i2);
        printf("Your order has been placed!\nThank you for shopping with us!");

        if(fp!=NULL)
        {
            fprintf(fp,"\nCustomer name: %s\n",name);
            fprintf(fp,"Contact Number: %d\n",num);
            fprintf(fp,"Codes: %d, %d\n", i1, i2);
            fclose(fp);
        }
        if(fpp!=NULL)
        {
            fprintf(fpp,"Customer name: %s\n",name);
            fprintf(fpp,"Contact Number: %d\n",num);
            fclose(fpp);
        }
    }
    else if(a==3)
    {
        printf("Hello delivery man!\n\n");
        printf("Enter pin: ");
        scanf("%d",&dell);
        if(dell=321)
        {

            if(fdd==NULL)
            {
                printf("No order has been placed.");
                return 0;
            }
            else
            {
                while(!feof(fdd))
                {
                    fgets(singleline, 2000, fdd);
                    puts(singleline);
                }
                fclose(fdd);
            }
        }
    }
}
