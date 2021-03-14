#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h> 
#include<string>
//#include<expansions.h>
using namespace std;
string str;
char command[100];
void error();
void maze();
void restart();
void credits();
void help();
int main()
{
	printf("zrx32 Terminal [版本 1.0.0]\n");
	printf("(c) 2021 zrx32 Corporation. 保留所有权利。\n");
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\n[操作提示]"); 
	printf("\n因为此程序制作匆忙，只制作了很少一部分功能，输入'help'即可查看全部功能。\n");
	printf("\n-------------------------------------------------------------------------------------\n\n");
	while(1){
		cout<<'>';
/*		cin>>str;
		const char* command = str.c_str();*/
		cin.getline(command,100);
		if(command[0]=='h'&&command[1]=='e'&&command[2]=='l'&&command[3]=='p'){
			help();
		}
		if(command[0]=='?'){
			help();
		}
		else if(command[0]=='v'&&command[1]=='e'&&command[2]=='r'){
			printf("\nzrx32 Terminal [版本 1.0.0]\n\n");
		}
		else if(command[0]=='r'&&command[1]=='e'&&command[2]=='b'&&command[3]=='o'&&command[4]=='o'&&command[5]=='t'){
			system("shutdown /r /t 30");
			printf("关机进程已启动，系统将于30秒后关机，在cmd中执行shutdown /a可取消关机。\n");
		}
		else if(command[0]=='p'&&command[1]=='a'&&command[2]=='i'&&command[3]=='n'&&command[4]=='t'){
			system("mspaint.exe");
			printf("\n"); 
		}
		else if(command[0]=='q'&&command[1]=='u'&&command[2]=='i'&&command[3]=='t'){
			system("taskkill /f /im terminal.exe");
		}
		else if(command[0]=='c'&&command[1]=='l'&&command[2]=='s'){
			system("cls");
		}
		else if(command[0]=='m'&&command[1]=='a'&&command[2]=='z'&&command[3]=='e'){
			maze();
		}
		else if(command[0]=='r'&&command[1]=='e'&&command[2]=='s'&&command[3]=='t'&&command[4]=='a'&&command[5]=='r'&&command[6]=='t'){
			restart();
		}
		else if(command[0]=='c'&&command[1]=='r'&&command[2]=='e'&&command[3]=='d'&&command[4]=='i'&&command[5]=='t'&&command[6]=='s'){
			credits();
		}
		else error();
	}
	return 0;
}
void error()
{
	printf("ERROR:");
	printf(" Unknown command. Type 'help' for help.\n");
}
void maze()
{
	system("cls");
	printf("---------------------------------\n");
	printf("\n[操作提示]\n");
	printf("恭喜发现彩蛋！下面是一个简单的迷宫，使用wasd控制，每次输入后按回车确定。\n");
	printf("游戏完成后会自动返回终端主界面。\n");
	printf("\n---------------------------------\n");
	char a[50][50]={"######",
					"#O #  ",
					"# ## #",
					"#  # #",
					"##   #",
					"######",};
	int i,x,y,p,q;
	char ch;
	
	x=1;y=1;p=1;q=5;
	for(i=0;i<=5;i++) puts(a[i]);
	while(x!=p || y!=q){
		cin>>ch;
		if(ch=='s'){
			if(a[x+1][y]!='#'){
				a[x][y]=' ';
				x++;
				a[x][y]='O';
			}
		}
		
		if(ch=='w')
		{
			if(a[x-1][y]!='#')
			{
				a[x][y]=' ';
				x--;
				a[x][y]='O';
			}
		}
		if(ch=='a')
		{
			if(a[x][y-1]!='#')
			{
				a[x][y]=' ';
				y--;
				a[x][y]='O';
			}
		}
		if(ch=='d')
		{
			if(a[x][y+1]!='#')
			{
				a[x][y]=' ';
				y++;
				a[x][y]='O';
			}
		}
		system("cls");
		printf("---------------------------------\n");
		printf("\n[操作提示]\n");
		printf("恭喜发现彩蛋！下面是一个简单的迷宫，使用wasd控制，每次输入后按回车确定。\n");
		printf("游戏完成后会自动返回终端主界面。\n");
		printf("\n---------------------------------\n");
		for(i=0;i<=5;i++) puts(a[i]);
	}
	system("cls");
	printf("You win!\n");
	Sleep(5000);
	restart();
}
void restart()
{
	system("cls");
	printf("zrx32 Terminal [版本 0.5.5]\n");
	printf("(c) 2021 zrx32 Corporation. 保留所有权利。\n");
	printf("\n-------------------------------------------------------------------------------------\n");
	printf("\n[操作提示]"); 
	printf("\n因为此程序制作匆忙，只制作了很少一部分功能，输入'help'即可查看全部功能。\n");
	printf("\n-------------------------------------------------------------------------------------\n\n");
}
void credits() //启用单独页面显示请去掉该函数的所有注释符号"//" 
{
//	system("cls");
	printf("---------------关于---------------\n");
	printf("制作者：ZRX32(https://zrx.rth.app)\n");
	printf("----------------------------------\n");
//	printf("\n请稍候，将自动退出此页面。\n");
//	Sleep(10000);
//	restart();
}
void help()
{
	printf("-------------Help:INDEX-------------\n");
	printf("cls       清屏。\n");
	printf("credits   打开'关于'页面。\n");
	printf("paint     绘图。\n"); 
	printf("quit      退出程序。\n");
	printf("reboot    在30秒后重启电脑。\n");
	printf("restart   重新启动程序。\n");
	printf("ver       显示程序版本。\n");
	printf("m██ e    （彩蛋:迷宫游戏）\n"); 
	printf("------------------------------------\n");
}
