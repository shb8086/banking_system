#include<conio.h>
#include<iostream>
#include<ctime> 
#include<cstring>
#include<cstdlib>//header file for system
using namespace std;

#define Max 100

static int i=0;//counter for accounts

int random(int low,int high);//function for account number and passwords

struct info{
	char Name[20];
	char LName[30];
	char PhoneNum[30];
	char City[30];
	char Address[100];
	int deposit;
	int Pass;
	int AccountNum;
};

int main()
{
	info accounts[Max];
menu:
{
	_getch();
	system("cls");//clean page
	cout<<"--------------------------------------------------\n";
	cout<<"1.Add new account\n";
	cout<<"2.Remove account\n";
	cout<<"3.Edit account\n";
	cout<<"4.Change Password\n";
	cout<<"5.Show all accounts\n";
	cout<<"6.Search based on First and Last name\n";
	cout<<"7.List of accounts with more than a given number\n";
	cout<<"8.Draw from account\n";
	cout<<"9.Transfer\n";
	cout<<"10.seeing acccount\n";
	cout<<"11.Lottery\n";
	cout<<"12.Exit\n";
	cout<<"--------------------------------------------------\n";
	cout<<"choose:";
};
int choice;
cin>>choice;
system("cls");

//choice 1-->Add new account
if(choice==1)
{
	char e[20];
	if(i>Max)
	{
		cout<<"Memory Full!";
		goto menu;
	}
	cout<<"Enter account number "<<i+1<<"'s informations:\n";
	cin.getline(e,20);
	cout<<"Name: ";
	cin.getline(accounts[i].Name,20);
	cout<<"Last name: ";
	cin.getline(accounts[i].LName,30);
	cout<<"Phone number: ";
	cin.getline(accounts[i].PhoneNum,30);
	cout<<"City: ";
	cin.getline(accounts[i].City,30);
	cout<<"Address: ";
	cin.getline(accounts[i].Address,100);
	cout<<"Deposit to toman: ";
	cin>>accounts[i].deposit;
	accounts[i].Pass=random(1000,10000);
	accounts[i].AccountNum=random(10000000000,100000000000);
	cout<<"Account number: "<<accounts[i].AccountNum;
	cout<<"\nPassword: "<<accounts[i].Pass;
	i++;
	goto menu;
}

//exit
else if(choice==12)
	exit(0);

//out of range
else if(choice>13||choice<0)
{
	cout<<"Choose between 1-12!\n";
	goto menu;
}

//choice 2-->Remove account
else if(choice==2)
{
	bool status=false;
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int a,b,s;
	cout<<"Please Enter\n";
	cout<<"Account number: ";
	cin>>a;
	cout<<"Password:";
	cin>>b;
	for(int c=0;c<=i;c++)
	{
		if(a==accounts[c].AccountNum && b==accounts[c].Pass)
		{
			status=true;
			s=c;
			break;
		}

	}
	if(status)
	{
		cout<<"Are you sure you want remove "<<accounts[s].Name<<" "<<accounts[s].LName<<"? (Y or N)"<<endl;
		char ch;
		cin>>ch;
		if(ch=='Y'||ch=='y')
		{
			for(int p=s;p<i && p>=s;p++)
				accounts[p]=accounts[p+1];
			--i;
			cout<<"Done!";
		}
	}
	else
		cout<<"The Password or Account  Number isn't correct!\nPlease try again!";
	goto menu;
}

//choice 3-->Edit account
else if(choice==3)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	char e[20];
	int a,b;
	cout<<"Account number: ";
	cin>>a;
	cout<<"Password:";
	cin>>b;
	cin.getline(e,20);
	bool status=true;
	for(int c=0;c<i;c++)
	{
		
		if(a==accounts[c].AccountNum && b==accounts[c].Pass)
		{
			status=false;
			cout<<"Account number "<<c+1<<"'s informations:\n";
			cout<<"New Name:";
			cin.getline(accounts[c].Name,20);
			cout<<"New Last name: ";
			cin.getline(accounts[c].LName,30);
			cout<<"New Phone number: ";
			cin.getline(accounts[c].PhoneNum,30);
			cout<<"New City: ";
			cin.getline(accounts[c].City,30);
			cout<<"New Address: ";
			cin.getline(accounts[c].Address,100);
			cout<<"\nDone!";
		}
	}
	if(status)
		cout<<"The Password or Account  Number isn't correct!\nPlease try again!";

	goto menu;
}

//choice 4-->Change Password
else if(choice==4)
{
	bool status=true;
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int a,b,b2;
	cout<<"Account number: ";
	cin>>a;
	cout<<"Password:";
	cin>>b;
	for(int c=0;c<=i;c++)
	{
		if(a==accounts[c].AccountNum && b==accounts[c].Pass)
		{
			status=false;
			cout<<"\n"<<accounts[c].Name<<" "<<accounts[c].LName<<endl;
			cout<<"Enter new Password:";
			cin>>b;
			cout<<"Enter new Password again: ";
			cin>>b2;
			cout<<"\n-----------------------------------\n";
			if(b>999 && b<10000 && b2==b)
				cout<<"New password: "<<b<<endl;
			else if(b2!=b)
			{
				cout<<"Not Possible!\nFirst and Second entered numbers aren't similar.";
				goto menu;
			}
			else
			{
				cout<<"Not Possible!\nYour password must be FOUR digit.";
				goto menu;
			}
			cout<<"Accept? (Y or N)";
			char ch;
			cin>>ch;
			if(ch=='Y'||ch=='y')
			{
				accounts[c].Pass=b;
				cout<<"Done!";
			}
		}
	}
	if(status)
		cout<<"The Password or Account  Number isn't correct!\nPlease try again!";
	goto menu;
}

//choice 5-->Show all accounts
else if(choice==5)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	else
	{
		for(int c=0;c<i;c++)
		{
			cout<<"Name: "<<accounts[c].Name<<endl;
			cout<<"Last name: "<<accounts[c].LName<<endl;
			cout<<"Phone number: "<<accounts[c].PhoneNum<<endl;
			cout<<"City: "<<accounts[c].City<<endl;
			cout<<"Address: "<<accounts[c].Address<<endl;
			cout<<"Account number: "<<accounts[c].AccountNum<<endl;
			cout<<"Password: "<<accounts[c].Pass<<endl;
			cout<<"Deposit: "<<accounts[c].deposit<<" Tomans"<<endl;
			cout<<"----------------------------------"<<endl;
		}
	}
	goto menu;
}

//choice 6-->Search
else if(choice==6)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int q,n;
	char a[20];
	char b[30];
	cout<<"Enter First name: ";
	cin>>a;
	cout<<"Enter Last name: ";
	cin>>b;
	cout<<endl;
	bool status=false;
	for(q=0;q<i;q++)
	{
		int z=0,y=0;
		for(int r=0;r<20 && accounts[q].Name[r]!='\0';r++)
			if(accounts[q].Name[r]==a[r])
				z++;
		for(int s=0;s<20 && accounts[q].LName[s]!='\0';s++)
			y++;
		if(y==strlen(accounts[q].LName) && z==strlen(accounts[q].Name))
		{
			status=true;
			n=q;
		}
	}
	if(status)
	{
		cout<<"Name: "<<accounts[n].Name<<endl;
		cout<<"Last name: "<<accounts[n].LName<<endl;
		cout<<"Phone number: "<<accounts[n].PhoneNum<<endl;
		cout<<"City: "<<accounts[n].City<<endl;
		cout<<"Address: "<<accounts[n].Address<<endl;
		cout<<"Account number: "<<accounts[n].AccountNum<<endl;
		cout<<"Password: "<<accounts[n].Pass<<endl;
		cout<<"Deposit: "<<accounts[n].deposit<<" Tomans"<<endl;
		cout<<"------------------------------------------"<<endl;
	}
	goto menu;
}

//choice 7-->List of accounts with more than a given number
else if(choice==7)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int leastconfine;
	cout<<"Enter the confine: ";
	cin>>leastconfine;
	for(int a=0;a<i;a++)
	{
		if(leastconfine<=accounts[a].deposit)
		{
			cout<<"Name: "<<accounts[a].Name<<endl;
			cout<<"Last name: "<<accounts[a].LName<<endl;
			cout<<"Phone number: "<<accounts[a].PhoneNum<<endl;
			cout<<"City: "<<accounts[a].City<<endl;
			cout<<"Address: "<<accounts[a].Address<<endl;
			cout<<"Account number: "<<accounts[a].AccountNum<<endl;
			cout<<"Password: "<<accounts[a].Pass<<endl;
			cout<<"Deposit: "<<accounts[a].deposit<<" Tomans"<<endl;
			cout<<"-------------------------------------------\n"<<endl;
		}
	}
	goto menu;
}

//choice 8-->Draw from account
else if(choice==8)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}

	int a,b,amount;
	cout<<"Account number: ";
	cin>>a;
	cout<<"Password:";
	cin>>b;
	cout<<endl;
	bool status=true;
	for(int c=0;c<=i;c++)
	{
		if(a==accounts[c].AccountNum &&b==accounts[c].Pass)
		{
			status=false;
			cout<<accounts[c].Name<<" "<<accounts[c].LName<<endl;
			cout<<"Enter the amount you want to draw: ";
			cin>>amount;
			cout<<"\n----------------------------------------\n";
			if(amount<0 || amount>200000)
				cout<<"\nYou can draw between 0-2,000,000 Rial!\n";
			else if(accounts[c].deposit < amount)
				cout<<"impossible!\nYour Deposit is less than the amount you want!\n";
			else
			accounts[c].deposit-=amount;
			cout<<"Your Deposit is: "<<accounts[c].deposit<<" Tomans"<<endl;
			break;
		}
	}
	if(status)
		cout<<"The Password or Account  Number isn't correct!\nPlease try again!";
	goto menu;
}

//choice 9-->Transfer
else if(choice==9)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int s,d,s_num,s_pass,d_num,amount;
	cout<<endl;
	if(i<2)
	{
		cout<<"Not enough data!\n";
		goto menu;
	}
	cout<<"Please enter source account number: ";
	cin>>s_num;
	cout<<"Please enter source Password: ";
	cin>>s_pass;
	cout<<"Please enter destination account number: ";
	cin>>d_num;
	bool s1,s2=false;
	for(s=0;s<i;s++)
	{
		if(s_num==accounts[s].AccountNum && s_pass==accounts[s].Pass)
		{
			s1=true;
			break;
		}
	}
	for(d=0;d<i;d++)
	{
		if(d_num==accounts[d].AccountNum)
		{
			s2=true;
			break;
		}
	}
	if(s1 && s2)
	{
		cout<<"\nEnter the amount that you want to transfer:";
		cin>>amount;
		if(amount>accounts[s].deposit)
		{
			cout<<"The amount for transfer is more than your deposit";
			goto menu;
		}	
		cout<<"You want transfer "<<amount<<" Toman"<<endl;
		cout<<"From: "<<accounts[s].Name<<"  "<<accounts[s].LName<<endl;
		cout<<"To: "<<accounts[d].Name<<"  "<<accounts[d].LName<<endl;
		cout<<"Are you sure? (Y or N):"<<endl;
		char ch;
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			cout<<"Done!"<<endl;
			accounts[s].deposit -= amount;
			accounts[d].deposit += amount;
			cout<<"New deposit is: "<<accounts[s].deposit<<endl;
		}
		else
			goto menu;
	}
	else
		cout<<"The Password or Account  Number isn't correct!\nPlease try again!";
	goto menu;
}

//choice 10-->seeing acccount
else if(choice==10)
{
	if(i<=0)
	{
		cout<<"No Data!\n";
		goto menu;
	}
	int a,b;
	cout<<"Please Enter\n";
	cout<<"Account number: ";
	cin>>a;
	cout<<"Password: ";
	cin>>b;
	bool status=true;
	for(int c=0;c<i;c++)
	{
		if(a==accounts[c].AccountNum &&b==accounts[c].Pass)
		{
			status=false;
			cout<<"Name: "<<accounts[c].Name<<endl;
			cout<<"Last name: "<<accounts[c].LName<<endl;
			cout<<"Phone number: "<<accounts[c].PhoneNum<<endl;
			cout<<"City: "<<accounts[c].City<<endl;
			cout<<"Address: "<<accounts[c].Address<<endl;
			cout<<"Account number: "<<accounts[c].AccountNum<<endl;
			cout<<"Password: "<<accounts[c].Pass<<endl;
			cout<<"Deposit: "<<accounts[c].deposit<<endl;
			cout<<"----------------------------------\n"<<endl;	
		}
	}
	if(status)
		cout<<"The password or account number isn't correct!\n";
	goto menu;
}

//choice 11-->Lottery
else if(choice==11)
{
	if(i>4)
	{
		int a=random(1,i);
		cout<<"500,000 Toman goes to:"<<endl;
		cout<<"1."<<accounts[a].Name<<" "<<accounts[a].LName<<endl;
		a=random(1,i);
		cout<<"200,000 Toman goes to:"<<endl;
		cout<<"2."<<accounts[a].Name<<" "<<accounts[a].LName<<endl;
		a=random(1,i);
		cout<<"200,000 Toman goes to:"<<endl;
		cout<<"3."<<accounts[a].Name<<" "<<accounts[a].LName<<endl;
	}
	else
		cout<<"Not enough account!";
	goto menu;
}

_getch();
return 0;
}

//random
int random(int low,int high)
{
	//time return time of now so there isn't any repeated number
	srand((unsigned)time(0));
	//%--> max of range +Min of range  (rand() % 6 + 1 )-->between 1-6
	return ( rand() % (high-low) + low );
}