#include<stdio.h>
#include<conio.h>
#include<string.h>
void itemf();
void itedit();
void itdel();
void itadd();
void itdisplay();
void prod();
void pedit();
void pdel();
void padd();
void pdisplay();
void sale();
void sedit();
void sdel();
void sadd();
void sdisplay();
struct item_File
{
int it_code;
int it_price;
int it_os;
int it_cs;
char it_name[20];
}it;

struct purchase
{
 int p_no;
 char p_date[20];
 int c_code;
 char c_name[20];
 int it_code;
 int p_qty;
 int p_price;
 int p_amt;
}pr;
struct sales
{
 int b_no;
 char b_date[20];
 int it_code;
 int b_qty;
 int b_rate;
 int b_tax;
 int b_amt;
}sl;
FILE *fp;

void main()
{
 int ch;
 do
 {
 system("cls");
 printf("\t\t\t\t\t Inventory Management System:-\n");
 printf("\t\t\t\t\t _______________________________\n");
 printf("\n\t\t\t1. ITEM FILE\n\n\t\t\t2. PURCHASE FILE\n\n\t\t\t3. SALES FILE\n\n\t\t\t4. EXIT");
 printf("\nEnter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: itemf();
 break;
 case 2: prod();
 break;
 case 3: sale();
 break;
 case 4: exit(1);
 default: printf("\nInvalid Choice");
printf("\n\n\tPress any key to continue...");
 getch();
 }
 }while(ch!=4);
 getch();
}
void itemf()
{
 int ch;
 do{
 system("cls");
 printf("\t\t\t\t\t Item File:-\n");
 printf("\t\t\t\t\t ________________\n");
 printf("\n\t\t\t1. ADD NEW ITEM\n\n\t\t\t2. EDIT ITEM\n\n\t\t\t3. DELETE ITEM\n\n\t\t\t4. DISPLAY ITEM\n\n\t\t\t5. EXIT");
 printf("\nEnter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: itadd();
 break;
 case 2: itedit();
 break;
 case 3: itdel();
 break;
 case 4: itdisplay();
 break;
 case 5: break;
 default: printf("\nInvalid choice");
 printf("\n\n\tPress any key to continue...");
 getch();
 }
 }while(ch!=5);
}
void itadd()
{
 fp=fopen("it.txt","ab+");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
}
printf("\nEnter item code :");
 scanf("%d",&it.it_code);
 printf("\nEnter item name :");
 scanf("%s",&it.it_name);
 printf("\nEnter item price :");
 scanf("%d",&it.it_price);
 printf("\nEnter opening stock :");
 scanf("%d",&it.it_os);
 it.it_cs=it.it_os;
 fwrite(&it,sizeof(it),1,fp);
 printf("\nItem inserted successfully");
 fclose(fp);
 printf("\n\n\tPress any key to continue...");
 getch();
}
void itdisplay()
{
 fp=fopen("it.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 while(fread(&it,sizeof(struct item_File),1,fp)==1)
 {
 printf("\n Item code: %d \n Item name: %s \n Item price: %d \n Opening stock: %d\n Closing stock: %d \n",it.it_code,it.it_name,it.it_price,it.it_os,it.it_cs);
 }
 fclose(fp);
 printf("\n\n\tPress any key to continue...");
 getch();
}
void itedit()
{
 int f=0,rec;
 FILE *fp2;
 fp=fopen("it.txt","rb+");
 fp2=fopen("itmp.txt","a+");
 if(fp==NULL)
 {
 printf("\nInvalid File");
 }
printf("\nEnter the item code :");
 scanf("%d",&rec);
 while(fread(&it,sizeof(struct item_File),1,fp)==1 && f==0)
 {
 if(it.it_code==rec)
 {
 f=1;
 printf("\nEnter new item code :");
 scanf("%d",&it.it_code);
 printf("\nEnter item name :");
 scanf("%s",&it.it_name);
 printf("\nEnter item price :");
 scanf("%d",&it.it_price);
 printf("\nEnter opening stock :");
 scanf("%d",&it.it_os);
 printf("\nEnter closing stock :");
 scanf("%d",&it.it_cs);
 fseek(fp,-sizeof(it),1);
 fwrite(&it,sizeof(it),1,fp);
 printf("\nUpdated successfully");
 fclose(fp);
 fclose(fp2);
 remove("it.txt");
 rename("itmp.txt","it.txt");
 }
 }
 if(f==0)
 {
 printf("\nNo item found");
 fclose(fp);
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}


void itdel()
{
 FILE *fp1;
 int f=0,c=0;
 int rec;
 fp=fopen("it.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS FOR DELETION..!!!");
 }
 fp1=fopen("temp.txt","a+");
printf("\nEnter the item code for deletion :");
 scanf("%d",&rec);
 while(fread(&it,sizeof(struct item_File),1,fp)==1)
 {
 if(it.it_code!=rec)
 {
 fwrite(&it,sizeof(it),1,fp1);
 c++;
 }
 else
 {
 f=1;
 printf("\nRecord deleted successfully");
 }
 }
 if(f==0)
 {
 printf("\nNo records found.");
 }
 fclose(fp);
 fclose(fp1);
 remove("it.txt");
 rename("temp.txt","it.txt");
 if(c==0)
 {
 remove("it.txt");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
void prod()
{
 int ch;
 do{
 system("cls");
 printf("\t\t\t\t\t Purchase File:-\n");
 printf("\t\t\t\t\t _________________\n");
 printf("\n\t\t\t1. ADD RECORD\n\n\t\t\t2. EDIT RECORD\n\n\t\t\t3. DELETE RECORD\n\n\t\t\t4. VIEW PURCHASE FILE\n\n\t\t\t5. EXIT");
printf("\nEnter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: padd();
 break;
 case 2: pedit();
 break;
 case 3: pdel();
 break;
 case 4: pdisplay();
 break;
 case 5: break;
 default: printf("\nInvalid choice");
 printf("\n\n\tPress any key to continue...");
 getch();
 }
 }while(ch!=5);
}
void padd()
{
 FILE *fp1,*fp2;
 int in=0;
 fp2=fopen("tp.txt","ab+");
 fp1=fopen("it.txt","r");
 fp=fopen("pd.txt","a+");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 printf("\nEnter purchase number :");
 scanf("%d",&pr.p_no);
 printf("\nEnter purchase date :");
 scanf("%s",&pr.p_date);
 printf("\nEnter client code :");
 scanf("%d",&pr.c_code);
 printf("\nEnter client name :");
 scanf("%s",&pr.c_name);
 printf("\nEnter item code :");
 scanf("%d",&pr.it_code);
 printf("\nEnter purchase quantity :");
 scanf("%d",&pr.p_qty);
 while(fread(&it,sizeof(struct item_File),1,fp1)==1)
{
if(it.it_code==pr.it_code)
 {
 in=1;
 it.it_cs=it.it_cs + pr.p_qty;
 it.it_os=it.it_os + pr.p_qty;
 pr.p_amt= pr.p_qty * it.it_price;
 pr.p_price=it.it_price;
 fwrite(&pr,sizeof(pr),1,fp);
 fwrite(&it,sizeof(it),1,fp2);
 printf("\nRecord inserted successfully.\n");
 }
 else
 {
 fwrite(&it,sizeof(it),1,fp2);
 }
 }
 if(in==0)
 {
 printf("\nInvalid item code");
 }
 fclose(fp1);
 fclose(fp);
 fclose(fp2);
 remove("it.txt");
 rename("tp.txt","it.txt");
 printf("\n\n\tPress any key to continue...");
 getch();
}
void pdisplay()
{
 int s;
 fp=fopen("pd.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 if (NULL != fp)
 {
 fseek(fp, 0, SEEK_END);
 s = ftell(fp);
if (0 == s)
 {
 printf("file is empty\n");
 }
 }
 rewind(fp);
 while(fread(&pr,sizeof(struct purchase),1,fp)==1)
 {
 printf("\n Purchase No: %d \n Purchase Date: %s \n Client code: %d \n Client Name: %s\n Item Code: %d \n Purchase Quantity: %d \n Purchase Price: %d \n Purchase Amount: %d\n",pr.p_no,pr.p_date,pr.c_code,pr.c_name,pr.it_code,pr.p_qty,pr.p_price,pr.p_amt);
 }
 fclose(fp);
 printf("\n\n\tPress any key to continue...");
 getch();
}
void pedit()
{
 int f=0,c=0,in=0,rec,t;
 FILE *fp1,*fp2;
 fp1=fopen("it.txt","rb+");
 fp=fopen("pd.txt","r");
 fp2=fopen("ptmp.txt","a+");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 printf("\nEnter the purchase number :");
 scanf("%d",&rec);
 while(fread(&pr,sizeof(struct purchase),1,fp)==1)
 {
 if(rec!=pr.p_no)
 {
 fwrite(&pr,sizeof(pr),1,fp2);
 }
 else
 {
 c++;
 printf("\nEnter new purchase number :");
 scanf("%d",&pr.p_no);
printf("\nEnter purchase date :");
 scanf("%s",&pr.p_date);
 printf("\nEnter client code :");
 scanf("%d",&pr.c_code);
 printf("\nEnter client name :");
 scanf("%s",&pr.c_name);
 printf("\nEnter item code :");
 scanf("%d",&pr.it_code);
 t=pr.p_qty;
 printf("\nEnter purchase quantity :");
 scanf("%d",&pr.p_qty);
 while(fread(&it,sizeof(struct item_File),1,fp1)==1 && f==0)
 {
 if(it.it_code==pr.it_code)
 {
 it.it_cs= it.it_cs - t;
 it.it_os= it.it_os - t;
 f=1;
 in=1;
 it.it_cs=it.it_cs + pr.p_qty;
 it.it_os=it.it_os + pr.p_qty;
 pr.p_price=it.it_price;
 pr.p_amt= pr.p_qty * pr.p_price;
 fseek(fp1,-sizeof(it),1);
 fwrite(&it,sizeof(it),1,fp1);
 fwrite(&pr,sizeof(pr),1,fp2);
 }
 }
 }
 }
 fclose(fp1);
 fclose(fp2);
 fclose(fp);
 remove("pd.txt");
 rename("ptmp.txt","pd.txt");
if(c==0)
 {
 printf("\nInvalid purchase number");
 }
 else if(in==0)
 {
 printf("\nInvalid item number");
 }
 else
 {
 printf("\nUpdated successfully");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
void pdel()
{
 FILE *fp1;
 int f=0,c=0,i=0;
 int rec;
 fp=fopen("pd.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS FOR DELETION..!!!");
 }
 fp1=fopen("t.txt","a+");
 printf("\nEnter the purchase number for deletion :");
 scanf("%d",&rec);
 while(fread(&pr,sizeof(struct purchase),1,fp)==1)
 {
 if(pr.p_no!=rec )
 {
 fwrite(&pr,sizeof(pr),1,fp1);
 c++;
 }
 else
 {
 f=1;
 }
 }
if(f==0)
 {
 printf("\nNo records found.");
 }
 else
 {
 printf("\nPurchase record deleted ",i);
 }
 fclose(fp);
 fclose(fp1);
 remove("pd.txt");
 rename("t.txt","pd.txt");
 if(c==0)
 {
 remove("pd.txt");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
void sale()
{
 int ch;
 do{
 system("cls");
 printf("\t\t\t\t\t Sales File:-\n");
 printf("\t\t\t\t\t ________________\n");
 printf("\n\t\t\t1. ADD SALES RECORD\n\n\t\t\t2. EDIT SALES RECORD\n\n\t\t\t3. DELETE SALES RECORD\n\n\t\t\t4. DISPLAY SALES RECORD\n\n\t\t\t5. EXIT");
 printf("\nEnter your choice :");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: sadd();
 break;
 case 2: sedit();
 break;
 case 3: sdel();
 break;
 case 4: sdisplay();
 break;
 case 5: break;
default: printf("\nInvalid choice");
printf("\n\n\tPress any key to continue...");
 getch();
}
}
while(ch!=5); 
}
void sadd() 
{
FILE *fp1,*fp2;
int in=0,qt=0;
fp2=fopen("tem.txt","ab+");
fp1=fopen("it.txt","r");
fp=fopen("sale.txt","a+");
if(fp==NULL) 
{
printf("\n\t NO RECORDS AVAILABLE..!!!");
exit(0); 
}
printf("\nEnter bill number :");
scanf("%d",&sl.b_no);
printf("\nEnter bill date : ");
scanf("%s",&sl.b_date);
printf("\nEnter item code :");
scanf("%d",&sl.it_code);
printf("\nEnter quantity :");
scanf("%d",&sl.b_qty);
while(fread(&it,sizeof(struct item_File),1,fp1)==1 ) 
{
if(sl.it_code==it.it_code)
{
 in=1;
 if(sl.b_qty<it.it_cs)
 
{
 it.it_cs= it.it_cs-sl.b_qty;
 sl.b_rate= it.it_price;
 sl.b_amt= sl.b_qty * it.it_price;
 sl.b_tax= (int) (sl.b_amt * 0.1);
 sl.b_amt = sl.b_amt + sl.b_tax;
 fwrite(&sl,sizeof(sl),1,fp);
 fwrite(&it,sizeof(it),1,fp2);
 printf("\nRecord inserted successfully");
}
 else
{
 qt=1;
 fwrite(&it,sizeof(it),1,fp2);
 }
 }
 else
 {
 fwrite(&it,sizeof(it),1,fp2);
 }
 }
 fclose(fp);
 fclose(fp1);
 fclose(fp2);
 remove("it.txt");
 rename("tem.txt","it.txt");
 if(in==0)
 {
 printf("\nInvalid item code");
 }
 else if(qt==1)
 {
 printf("\nNot enough stock");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
void sdisplay()
{
 int s;
 fp=fopen("sale.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 if (NULL != fp)
 {
 fseek(fp, 0, SEEK_END);
 s=ftell(fp);
 if(0==s)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
}
}
rewind(fp);
while(fread(&sl,sizeof(struct sales),1,fp)==1)
{
printf("\n Bill No: %d \n Bill Date: %s \n Item code: %d \n Quantity: %d\n Rate: %d \n Tax : %d \n Amount payable: %d\n",sl.b_no,sl.b_date,sl.it_code,sl.b_qty,sl.b_rate,sl.b_tax,sl.b_amt);
 }
 fclose(fp);
 printf("\n\n\tPress any key to continue...");
 getch();
}
void sedit()
{
 int qt=0,in=0,c=0,rec,t;
 FILE *fp1,*fp2,*fp3;
 fp=fopen("sale.txt","r");
 fp1=fopen("tempit.txt","ab+");
 fp2=fopen("stmp.txt","a+");
 fp3=fopen("it.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS AVAILABLE..!!!");
 }
 printf("\nEnter the bill number :");
 scanf("%d",&rec);
 while(fread(&sl,sizeof(struct sales),1,fp)==1)
 {
 if(sl.b_no!=rec)
 {
 fwrite(&sl,sizeof(sl),1,fp2);
 }
 if(sl.b_no==rec)
 {
 c++;
 printf("\nEnter new bill number :");
 scanf("%d",&sl.b_no);
 printf("\nEnter bill date : ");
 scanf("%s",&sl.b_date);
printf("\nEnter item code :");
 scanf("%d",&sl.it_code);
 t=sl.b_qty;
 printf("\nEnter quantity :");
 scanf("%d",&sl.b_qty);
 while(fread(&it,sizeof(struct item_File),1,fp3)==1)
 {
 if(sl.it_code!=it.it_code)
 {
 fwrite(&it,sizeof(it),1,fp1);
 }
 if(sl.it_code==it.it_code)
 {
 in=1;
 if(sl.b_qty<it.it_cs)
 {
 it.it_cs=it.it_cs + t;
 it.it_cs = it.it_cs - sl.b_qty;
 sl.b_rate= it.it_price;
 sl.b_amt= sl.b_qty * it.it_price;
 sl.b_tax= 10;
 sl.b_amt = sl.b_amt + sl.b_tax;
 fwrite(&sl,sizeof(sl),1,fp2);
 fwrite(&it,sizeof(it),1,fp1);
 }
 else
 {
 qt=1;
 fwrite(&it,sizeof(it),1,fp1);
 fwrite(&sl,sizeof(sl),1,fp2);
 }
 }
 }
 }
 }
 fclose(fp);
 fclose(fp2);
 fclose(fp1);
 fclose(fp3);
 remove("sale.txt");
 rename("stmp.txt","sale.txt");
remove("it.txt");
 rename("tempit.txt","it.txt");
 if(c==0)
 {
 printf("\nInvalid bill number");
 }
 else if(in==0)
 {
 printf("\nInvalid item code");
 }
 else if(qt==1)
 {
 printf("\nNot enough stock");
 }
 else
 {
 printf("\nRecord updated successfully");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
void sdel()
{
 FILE *fp1;
 int f=0,c=0,i=0;
 int rec;
 fp=fopen("sale.txt","r");
 if(fp==NULL)
 {
 printf("\n\tNO RECORDS FOR DELETION..!!!");
 }
 fp1=fopen("tp.txt","a+");
 printf("\nEnter the bill number for deletion :");
 scanf("%d",&rec);
 while(fread(&sl,sizeof(struct sales),1,fp)==1)
 {
 if(sl.b_no!=rec )
 {
 fwrite(&sl,sizeof(sl),1,fp1);
 c++;
}
 if(sl.b_no==rec)
 {
 f=1;
 printf("\nRecord deleted successfully");
 }
 }
 if(f==0)
 {
 printf("\nNo records found");
 }
 fclose(fp);
 fclose(fp1);
 remove("sale.txt");
 rename("tp.txt","sale.txt");
 if(c==0)
 {
 remove("sale.txt");
 }
 printf("\n\n\tPress any key to continue...");
 getch();
}
