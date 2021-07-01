#include<iostream>
using namespace std;
#include<iomanip>
char box[5][5];
class board{
	
	
	public:
		board(){
				for(int i=0;i<3;i++)
				{
				for(int j=0;j<3;j++)
				{
				box[i][j]= ' ';
		
				}
	
				}
		}
	//	char box[2][2];
		void show();
		int enter();
       bool checkplayer1win();
		bool checkplayer2win();
		void assignval(int ,int& ,int&);
};
void board::assignval(int no,int& m,int& n)
{
	if(no==1)
	{
		m=0;
		n=0	;
	}
	if(no==2)
	{
		m=0;
		n=1;	
	}
	if(no==3)
	{
		m=0;
		n=2;	
	}
	if(no==4)
	{
		m=1;
		n=0	;
	}
	if(no==5)
	{
		m=1;
		n=1;	
	}
	if(no==6)
	{
		m=1;
		n=2;	
	}if(no==7)
	{
		m=2;
		n=0;	
	}
	if(no==8)
	{
		m=2;
		n=1;	
	}
	if(no==9)
	{
		m=2;
		n=2;
	}
	

	
	
	
	
	
	
	
}
bool board::checkplayer1win()
{
	//int f=0;
	if(box[0][0]=='x'&&box[0][1]=='x'&&box[0][2]=='x'||box[1][0]=='x'&&box[1][1]=='x'&&box[1][2]=='x'||
		box[2][0]=='x'&&box[2][1]=='x'&&box[2][2]=='x'||box[0][0]=='x'&&box[1][1]=='x'&&box[2][2]=='x'||
		box[0][2]=='x'&&box[1][1]=='x'&&box[2][0]=='x'||box[0][0]=='x'&&box[1][0]=='x'&&box[2][0]=='x'||
		box[0][1]=='x'&&box[1][1]=='x'&&box[2][1]=='x'||box[0][2]=='x'&&box[1][2]=='x'&&box[2][2]=='x')
		{
		
		return true;	
		}
	

	else
	return  false;
	

}
bool board::checkplayer2win()
	{
		if(box[0][0]=='0'&&box[0][1]=='0'&&box[0][2]=='0'||box[1][0]=='0'&&box[1][1]=='0'&&box[1][2]=='0'||
		box[2][0]=='0'&&box[2][1]=='0'&&box[2][2]=='0'||box[0][0]=='0'&&box[1][1]=='0'&&box[2][2]=='0'||
		box[0][2]=='0'&&box[1][1]=='0'&&box[2][0]=='0'||box[0][0]=='0'&&box[1][0]=='0'&&box[2][0]=='0'||
		box[0][1]=='0'&&box[1][1]=='0'&&box[2][1]=='0'||box[0][2]=='0'&&box[1][2]=='0'&&box[2][2]=='0')
		{
		
		return true;	
		}
	

	else
	return  false;


	
	}
	

void board::show()
{
	cout<<setw(50)<<"_"<<"___________\n";
	cout<<setw(50)<<" | "<<box[0][0]<<" | "<<box[0][1]<<" | "<<box[0][2]<<" |\n";
		cout<<setw(50)<<"-"<<"-----------\n";
	cout<<setw(50)<<" | "<<box[1][0]<<" | "<<box[1][1]<<" | "<<box[1][2]<<" |\n";
		cout<<setw(50)<<"-"<<"-----------\n";
	cout<<setw(50)<<" | "<<box[2][0]<<" | "<<box[2][1]<<" | "<<box[2][2]<<" |\n";
	cout<<setw(50)<<"_"<<"___________\n";
	
}
int board::enter()
{
	int boxno;
	int i=0,j=0;
	int flag[9];
//	int term=3;
	for(int t=1;t<=9;t++)
		{
		if(t%2==1)
			{
			cout<<endl<<"player 1(x): \n";
			cout<<"enter box no\n";
			cin>>boxno;
			assignval(boxno,i,j);
			
			if(box[i][j]=='x'||box[i][j]=='0')
				{
				cout<<endl<<"this box is already filled\n";
				t--;
				}
			else{
	
				box[i][j]='x';
				system("cls");
				show();
				if(checkplayer1win())
					{
						
					cout<<setw(50)<<""<<"player 1 win :-)";
				
					break;
					}
				}
				
			}			
		else
			{
			cout<<endl<<"player 2(0): \n";
			cout<<"enter box no\n";
			cin>>boxno;
			assignval(boxno,i,j);
			if(box[i][j]=='x'||box[i][j]=='0')
				{
					cout<<endl<<"this box is already filled\n";
					t--;
				}
			else{	
					box[i][j]='0';
					system("cls");
					show();	
						if(checkplayer2win())
						{
							
							cout<<setw(50)<<""<<"player 2 win:-)";
						
						break;
						}
				}
			}				
	
	


		}
		if(!checkplayer2win() && !checkplayer1win())
		cout<<"congrats both are win i.e match in tie \n";
		cout<<"\n1-restart\n";
		int val;
		cin>>val;
		if(val==1)
		return 1;
		else
		return 0;
		
	
}
int main() 
{

	int i,j;
	

	int n=1;
	while(n)
	{
	system("cls");
	cout<<"lets start the game\n";
		board b;

		b.show();
		n=b.enter();	
		
	}

		
return 0;
	
}
