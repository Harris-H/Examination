#undef UNICODE
#include "Store.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <graphics.h>
#include <conio.h>
using namespace std;
void Store::option(int op) {
	if (op == 1) num = 690,set_num=num/20,bh = 1,name="four.txt",file.close(), file.open("four.txt");
	else if (op == 2) num = 687, set_num=num/20,bh = 2 ,name="six.txt",file.close(), file.open("six.txt");
	order = 0;
}
void Store::Show() {
	system("cls");
	MOUSEMSG m;
	const char* str[6] = { "1.四级","2.六级" };
	initgraph(640, 480);
	IMAGE background;//定义一个图片名.
	loadimage(&background, "background.jpg", 640, 480, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	// 设置背景色为白色
	//setbkcolor(WHITE);
	// 用背景色清空屏幕
	//cleardevice();
	setfillcolor(BLUE);
	//fillrectangle(100, 30, 500, 80);
	int lx = 130, rx = 270, uy = 100, dy = 130, delta = 200;
	for (int i = 0; i < 2; i++) {	//填充矩形.
		fillrectangle(lx, uy, rx, dy);
		lx += delta, rx += delta;
	}
	settextstyle(15, 0, "Consolas");
	setbkmode(TRANSPARENT);
	int str_x = 175, str_y = 110;
	for (int i = 0; i < 2; i++) {	//输出字符串
		outtextxy(str_x, str_y, str[i]);
		str_x += delta;
	}
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 160 && m.x <= 300 && m.y >= 100 && m.y <= 130) {
			setlinecolor(RED);
			rectangle(120, 95, 280, 135);
			if (m.uMsg == WM_LBUTTONDOWN) {	
				PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
				closegraph();	//四级.
				break;
			}
		}
		else if (m.x >= 360 && m.x <= 500 && m.y >= 100 && m.y <= 130) {
			setlinecolor(RED);
			rectangle(120+delta, 95, 280+delta, 135);
			if (m.uMsg == WM_LBUTTONDOWN) {	
				PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
				closegraph();
				option(2);	//六级.
				break;
			}
		}
		else {
			setlinecolor(LIGHTCYAN);
			rectangle(120, 95, 280, 135);
			rectangle(120 + delta, 95, 280 + delta, 135);
		}
	}
	/*
	for (int i = 1; i <= x; i++) {
		getline(file, s);
		Word tmp;
		tmp.Get_information(s);
		printf("单词编号:%03d\n", tmp.Get_id());
		printf("单词英文:");
		cout << tmp.Get_s() << endl;
		printf("单词中文:");
		cout << tmp.Get_t() << endl;
		printf("\n\n");
		int opt;
		printf("您学会了吗？学习下一个单词请按1,退出请按2\n");
		scanf_s("%d", &opt);
		if (opt == 2) break;
		//cout << s << endl;
		//cout << num << endl;
		v.push_back(tmp);
	}
	*/
}
void Store::AddNewWord(int x, string s, string t) {
	v.push_back(Word(x, s, t));
}
void Store::DeleteWord(int id) {
	v.erase(v.begin() + id-1);
}
void Store::StudySet() {
	string tmp;
	ifstream fi("number.txt");
	for (int i = 1; i <= bh; i++)
		getline(fi, tmp);
	have_num = stoi(tmp);
	fi.close();
	/*
	printf("您已经学习了%d个单词\n", have_num);
	printf("今天您需要学习%d个单词\n",set_num);
	getchar();
	getchar();
	*/
	initgraph(640, 480);
	IMAGE background;//定义一个图片名.
	loadimage(&background, "bk2.jpg", 640, 480, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	char str1[20];
	InputBox(str1, 10, "请设置你今天想学习的单词数");
	//wchar_t str[20];
	//InputBox(str, 10, L"请输入单词数");
	int tmp_num=0;
	for (int i = 0; str1[i]; i++) {
		tmp_num = tmp_num * 10 + str1[i] - '0';
	}
	PlaySound("SetT.wav", NULL, SND_FILENAME | SND_ASYNC);
	set_num = tmp_num;
	//Sleep(500);
	setbkcolor(WHITE);
	cleardevice();
	putimage(0, 0, &background);
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(RED);
	outtextxy(250, 100, "设置成功!");
	char str2[500];
	sprintf_s(str2, "今天您的目标是学习%d个单词.", set_num);
	outtextxy(150, 130, str2);
	MOUSEMSG m;
	while (1) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			//closegraph();
			break;
		}
	}
	cleardevice();
	putimage(0, 0, &background);
	settextcolor(BLACK);
	outtextxy(195, 100, "请设置单词学习顺序");
	setfillcolor(RED);
	fillrectangle(120, 200, 250, 250);
	fillrectangle(320, 200, 450, 250);
	settextcolor(WHITE);
	settextstyle(22, 0, "微软雅黑");
	outtextxy(150, 215, "词表顺序");
	outtextxy(350, 215, "随机顺序");
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 120 && m.x <= 250 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(110,195, 260, 260);
			if (m.uMsg == WM_LBUTTONDOWN) {
				PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
				closegraph();
				break;
			}
		}
		else if (m.x >= 320 && m.x <= 450 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(310,195, 460, 260);
			if (m.uMsg == WM_LBUTTONDOWN) {
				PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
				order = 1;
				closegraph();
				break;
			}
		}
		else {
			setlinecolor(CYAN);
			rectangle(110, 195, 260, 260);
			rectangle(310, 195, 460, 260);
		}
	}
	//initgraph(640, 480);
	//getchar();
	//closegraph();
	//getchar();
	/*
	printf("------------------%d\n", set_num);
	getchar();
	getchar();
	*/
}
void Store::Study() {
	cnt_now= 0;
	string s;
	 vector<Word>key_words;//重点需要记忆的单词.
	 ofstream fi("have_remember.txt", ios_base::app);//已记忆生词表添加到文件末尾.
	 ofstream fi1("Glossary.txt", ios_base::app);//生词表.
	 initgraph(640, 480);
	 IMAGE background;//定义一个图片名.
	 loadimage(&background, "bk1.jpg", 640, 480, 1);//从图片文件获取图像
	 putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	 //setbkcolor(WHITE);
	 //cleardevice();
	 settextstyle(30, 0, "微软雅黑");
	 setbkmode(TRANSPARENT);
	 settextcolor(BLACK);
	 if (!order) {
		 for (int i = 1; i <= set_num; i++) {
			 cleardevice();
			 putimage(0, 0, &background);
			 outtextxy(10, 30, "主菜单");
			 setlinecolor(BLUE);
			 rectangle(5, 30, 80, 60);
			 cnt_now++;
			 getline(file, s);
			 fi << s << endl;
			 Word tmp;
			 tmp.Get_information(s);
			 char str1[500],str2[500],str3[500],str4[500];
			 sprintf_s(str1,"单词编号:%03d\n", tmp.Get_id());
			 sprintf_s(str2,"单词英文:%s",tmp.Get_s().c_str());
			 outtextxy(200, 100, str1);
			 outtextxy(200, 150, str2);
			 /*
			 cout << tmp.Get_s() << endl;
			 //printf("\n\n");
			 */
			 sprintf_s(str3, "单词中文:");
			 outtextxy(200, 200, str3);
			 MOUSEMSG m;
			 while (1) {
				 m = GetMouseMsg();
				 if (m.x>=300&&m.x<=500&&m.y>=200&&m.y<=250) {
							setlinecolor(BLUE);
				   rectangle(300, 200, 610, 250);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 outtextxy(300, 200, tmp.Get_t().c_str());
						 setlinecolor(WHITE);
						 rectangle(300, 200, 610, 250);
						 //closegraph();
						 break;
					 }
					 else if (m.uMsg == WM_RBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 setfillcolor(WHITE);
						 fillrectangle(200, 200, 610, 250);
						 setlinecolor(WHITE);
						 rectangle(200, 200, 610, 250);
						 //getchar();
						 break;
					 }
				 }
				 else if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
					 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					 setlinecolor(RED);
					 rectangle(5, 30, 80, 60);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 goto next_part;
					 }
				 }
				 else {
					 setlinecolor(WHITE);
					 rectangle(300, 200, 610, 250);
					 setlinecolor(BLUE);
					 rectangle(5, 30, 80, 60);
				 }
			 }
			 Sleep(200);
			 sprintf_s(str4,"请问是否需要将该单词添加到生词表");
			 outtextxy(130,300,str4);
			 setlinecolor(BLUE);
			 //rectangle(190, 340, 250, 370);
			 //rectangle(375, 340, 435, 370);
			 outtextxy(190, 340, "是");
			 outtextxy(375, 340, "否");
			 while (1) {
				 m = GetMouseMsg();
				 if (m.x >= 190 && m.x <= 250 && m.y >= 340 && m.y <= 370) {
					 setlinecolor(BLUE);
					 rectangle(170, 340, 235, 370);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 //closegraph();
						 key_words.push_back(tmp);
						 fi1 << s << endl;
						 Sleep(100);
						 break;
					 }
				 }
				 else if (m.x >= 375 && m.x <= 435 && m.y >= 340 && m.y <= 370) {
					 setlinecolor(BLUE);
					 rectangle(355, 340, 420, 370);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 //closegraph();
						 Sleep(100);
						 break;
					 }
				 }
				 else if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
					 setlinecolor(RED);
					 rectangle(5, 30, 80, 60);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 Sleep(100);
						 goto next_part;
					 }
				 }
				 else {
					 setlinecolor(WHITE);
					 rectangle(170, 340, 235, 370);
					 rectangle(355, 340, 420, 370);
					 setlinecolor(BLUE);
					 rectangle(5, 30, 80, 60);
				 }
			 }
			 //getchar();
			 /*
			 int opt;
			 printf("请问是否需要给出中文对照?\n");
			 printf("   1.是        2.否\n");
			 scanf_s("%d", &opt);
			 if (opt == 1) {
				 printf("单词中文:");
				 cout << tmp.Get_t() << endl;
			 }
			 v.push_back(tmp);
			 fi << s << endl;
			 printf("请问是否需要将该单词作为重点词汇添加到生词表\n");
			 printf("   1.是        2.否\n");
			 int opt1;
			 scanf_s("%d", &opt1);
			 if (opt1 == 1) {
				 key_words.push_back(tmp);
				 fi1 << s << endl;
			 }
			 printf("\n请问是否回到主程序?");
			 printf("  1.是         2.否\n");
			 int opt2;
			 scanf_s("%d", &opt2);
			 if (opt2 == 1) break;
			 */
		 }
	 }
	 else {
		 for (int i = 1; i <= set_num; i++) {
			 //cnt_now++;
			 getline(file, s);
			 Word tmp;
			 tmp.Get_information(s);
			 v.push_back(tmp);
			 fi << s << endl;
		 }
		 for (int i = 0; i < set_num; i++) {
			 int r_id = rand() % set_num;
			 swap(v[i], v[r_id]);
		 }
		 for (int i = 0; i < set_num; i++) {
			 cleardevice();
			 putimage(0, 0, &background);
			 cnt_now++;
			 //v[i].Get_information(s);
			 char str1[500], str2[500], str3[500], str4[500];
			 sprintf_s(str1, "单词编号:%03d\n", v[i].Get_id());
			 sprintf_s(str2, "单词英文:%s", v[i].Get_s().c_str());
			 outtextxy(200, 100, str1);
			 outtextxy(200, 150, str2);
			 sprintf_s(str3, "单词中文:");
			 outtextxy(200, 200, str3);
			 MOUSEMSG m;
			 while (1) {
				 m = GetMouseMsg();
				 if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 250) {
					 setlinecolor(BLUE);
					 rectangle(300, 200, 610, 250);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 outtextxy(300, 200, v[i].Get_t().c_str());
						 setlinecolor(WHITE);
						 rectangle(300, 200, 610, 250);
						 //closegraph();
						 break;
					 }
					 else if (m.uMsg == WM_RBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 setfillcolor(WHITE);
						 fillrectangle(200, 200, 610, 250);
						 setlinecolor(WHITE);
						 rectangle(200, 200, 610, 250);
						 //getchar();
						 break;
					 }
				 }
				 else {
					 setlinecolor(WHITE);
					 rectangle(300, 200, 610, 250);
				 }
			 }
			 Sleep(200);
			 sprintf_s(str4, "请问是否需要将该单词添加到生词表");
			 outtextxy(130, 300, str4);
			 setlinecolor(BLUE);
			 //rectangle(190, 340, 250, 370);
			 //rectangle(375, 340, 435, 370);
			 outtextxy(190, 340, "是");
			 outtextxy(375, 340, "否");
			 while (1) {
				 m = GetMouseMsg();
				 if (m.x >= 190 && m.x <= 250 && m.y >= 340 && m.y <= 370) {
					 setlinecolor(BLUE);
					 rectangle(170, 340, 235, 370);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 //closegraph();
						 key_words.push_back(v[i]);
						 fi1 << s << endl;
						 Sleep(100);
						 break;
					 }
				 }
				 else if (m.x >= 375 && m.x <= 435 && m.y >= 340 && m.y <= 370) {
					 setlinecolor(BLUE);
					 rectangle(355, 340, 420, 370);
					 if (m.uMsg == WM_LBUTTONDOWN) {
						 PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
						 //closegraph();
						 Sleep(100);
						 break;
					 }
				 }
				 else {
					 setlinecolor(WHITE);
					 rectangle(170, 340, 235, 370);
					 rectangle(355, 340, 420, 370);
				 }
			 }
			 /*
			 int opt;
			 printf("请问是否需要给出中文对照?\n");
			 printf("   1.是        2.否\n");
			 scanf_s("%d", &opt);
			 if (opt == 1) {
				 printf("单词中文:");
				 cout << v[i].Get_t() << endl;
			 }
			 printf("请问是否需要将该单词作为重点词汇添加到生词表\n");
			 printf("   1.是        2.否\n");
			 int opt1;
			 scanf_s("%d", &opt1);
			 if (opt1 == 1) {
				 key_words.push_back(v[i]);
				 fi1 << s << endl;
			 }
			 */
		 }
	}
	next_part:;
	ofstream tmp;
	tmp.open("temp.txt");
	while (getline(file, s)) {
		tmp << s << endl;
	}
	file.close();
	tmp.close();
	remove(name);	//更新未记忆单词列表,删除已学习单词
	rename("temp.txt",name);
	/*
	printf("ok=%d\n", ok);
	int space;
	scanf_s("%d", &space);
	*/
	Update_num(bh,cnt_now);
	if (cnt_now == set_num) {
		PlaySound("Task_completed.wav", NULL, SND_FILENAME | SND_ASYNC);
		settextcolor(RED);
		cleardevice();
		putimage(0, 0, &background);
		outtextxy(180, 150, "恭喜你！完成今日的任务!");
		MOUSEMSG m;
		while (1) {
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN) {
				//closegraph();
				break;
			}
		}
	}
	closegraph();
}
void Store::Review() {	//复习生词表
	vector<string>ve;
	string s;
	ifstream fi("Glossary.txt");
	ofstream temp("temp1.txt");
	initgraph(640, 480);
	IMAGE background;//定义一个图片名.
	loadimage(&background, "bk1.jpg", 640, 480, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	//setbkcolor(WHITE);
	//cleardevice();
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	while (getline(fi, s)) {
		cleardevice();
		putimage(0, 0, &background);
		outtextxy(10, 30, "主菜单");
		setlinecolor(BLUE);
		rectangle(5, 30, 80, 60);
		Word tmp;
		tmp.Get_information(s);
		char str1[500], str2[500], str3[500], str4[500];
		sprintf_s(str1, "单词编号:%03d\n", tmp.Get_id());
		sprintf_s(str2, "单词英文:%s", tmp.Get_s().c_str());
		outtextxy(200, 100, str1);
		outtextxy(200, 150, str2);
		sprintf_s(str3, "单词中文:");
		outtextxy(200, 200, str3);
		MOUSEMSG m;
		while (1) {
			m = GetMouseMsg();
			if (m.x >= 300 && m.x <= 500 && m.y >= 200 && m.y <= 250) {
				setlinecolor(BLUE);
				rectangle(300, 200, 610, 250);
				if (m.uMsg == WM_LBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					outtextxy(300, 200, tmp.Get_t().c_str());
					setlinecolor(WHITE);
					rectangle(300, 200, 610, 250);
					//closegraph();
					break;
				}
				else if (m.uMsg == WM_RBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					setfillcolor(WHITE);
					fillrectangle(200, 200, 610, 250);
					setlinecolor(WHITE);
					rectangle(200, 200, 610, 250);
					//getchar();
					break;
				}
			}
			else if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
				setlinecolor(RED);
				rectangle(5, 30, 80, 60);
				if (m.uMsg == WM_LBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					goto next_part;
				}
			}
			else {
				setlinecolor(WHITE);
				rectangle(300, 200, 610, 250);
				setlinecolor(BLUE);
				rectangle(5, 30, 80, 60);
			}
		}
		/*
		int opt;
		printf("请问是否需要给出中文对照?\n");
		printf("   1.是        2.否\n");
		scanf_s("%d", &opt);
		if (opt == 1) {
			printf("单词中文:");
			cout << tmp.Get_t() << endl;
		}
		*/
		sprintf_s(str4, "您学会该单词了吗?");
		outtextxy(190, 300, str4);
		setlinecolor(BLUE);
		//rectangle(190, 340, 250, 370);
		//rectangle(375, 340, 435, 370);
		outtextxy(140, 340, "学会了");
		outtextxy(350, 340, "下次再学");
		while (1) {
			m = GetMouseMsg();
			if (m.x >= 150 && m.x <= 250 && m.y >= 340 && m.y <= 370) {
				setlinecolor(BLUE);
				rectangle(130, 340, 210, 370);
				if (m.uMsg == WM_LBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					//closegraph();
					break;
				}
			}
			else if (m.x >= 350 && m.x <= 435 && m.y >= 340 && m.y <= 370) {
				setlinecolor(BLUE);
				rectangle(345, 340, 450, 370);
				if (m.uMsg == WM_LBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					temp << s << endl;
					//closegraph();
					break;
				}
			}
			else if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
				setlinecolor(RED);
				rectangle(5, 30, 80, 60);
				if (m.uMsg == WM_LBUTTONDOWN) {
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					goto next_part;
				}
			}
			else {
				setlinecolor(WHITE);
				rectangle(130, 340, 210, 370);
				rectangle(345, 340, 450, 370);
				setlinecolor(BLUE);
				rectangle(5, 30, 80, 60);
			}
		}
		/*
		printf("\n 您想继续学习吗?\n");
		printf("     1.继续    2.退出\n");
		int opt2;
		scanf_s("%d", &opt2);
		if (opt2 == 2) break;
		*/
	}
	next_part:;
	while (getline(fi, s)) {
		temp << s << endl;
	}
	fi.close();
	temp.close();
	remove("Glossary.txt");	//更新生词表
	rename("temp1.txt", "Glossary.txt");
	closegraph();
}
void Store::Update_num(int op,int cnt) {	//更新学习记录
	vector<string>v;
	ifstream fi("number.txt");
	string s;
	for (int i = 1; i <= 3; i++) {
		getline(fi, s);
		if (op == i) {
			int x = stoi(s);
			x += cnt;
			s = to_string(x);
		}
		v.push_back(s);
	}
	fi.close();
	ofstream tmp("number.txt");
	for (string i : v) {
		tmp << i << endl;
	}
	tmp.close();
}
void Store::Study_Record() {//5.显示打卡记录
	//const char * str[2]={}
	string tmp;
	ifstream fi("number.txt");
	int  tot = 0;
	for (int i = 1; i <= 3; i++) {
		getline(fi, tmp);
		int x=stoi(tmp);
		tot += x;
	}
	fi.close();
	string str = "您今天已经学习了";
	string str1 = "您总共学习了";
	str1 += to_string(tot) + "个单词";
	str += to_string(cnt_now)+"个单词";
	system("cls");
	initgraph(640, 480);
	IMAGE background;//定义一个图片名.
	loadimage(&background, "bk2.jpg", 640, 480, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	//setfillcolor(BLUE);
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(200, 100, str.c_str());
	outtextxy(200, 150, str1.c_str());
	//printf("     您今天已经学习了%d个单词\n",cnt_now);
	//printf("     您总共学习了%d个单词\n", tot);
	time_t now = time(0);
	/*
	time_t now;
	time(&now);
	*/
	struct tm p;//指向本地时间的tm结构体
	localtime_s(&p, &now);	
	 char date1[500];
	 char date2[500];
	sprintf_s(date1,"%04d年%02d月%02d日", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday);
	//sprintf_s(date2,"%02d时%02d分%02d秒", p.tm_hour, p.tm_min, p.tm_sec);
	settextstyle(25, 0, "微软雅黑");
	outtextxy(400, 400, date1);
	int Month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int mo = p.tm_mon + 1, day = p.tm_mday;
	ifstream fi1;
	fi1.open("date_study.txt");
	string date_s;
	ofstream tmp1;
	tmp1.open("temp2.txt");
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= Month[i]; j++) {
			getline(fi1, date_s);
			if (i == mo && day == j&&date_s=="0") {
				tmp1 << to_string(cnt_now) << endl;
			}
			else {
				int num3 = stoi(date_s) + cnt_now;
				tmp1 << to_string(num3) << endl;
			}
		}
	}
	fi1.close();
	tmp1.close();

	remove("date_study.txt");
	rename("temp2.txt","date_study.txt");
	/*
	int Month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	char str2[20];
	InputBox(str2, 10, "请设置你今天想学习的单词数");
	*/
	//outtextxy(400, 400, date2);
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(200, 300, "查看以前学习记录");
	setlinecolor(WHITE);
	rectangle(190, 290, 395, 340);
	outtextxy(10, 30, "主菜单");
	setlinecolor(BLUE);
	rectangle(5, 30, 80, 60);
	MOUSEMSG m;
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
			setlinecolor(RED);
			rectangle(5, 30, 80, 60);
			if (m.uMsg == WM_LBUTTONDOWN) {
				PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
				closegraph();
				break;
			}
		}
		else if (m.x>=190&&m.x<=395&&m.y>=290&&m.y<=340) {
			setlinecolor(RED);
			rectangle(190, 290, 395, 340);
			if (m.uMsg == WM_LBUTTONDOWN) {
				Search_before();
				closegraph();
				break;
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(190, 290, 395, 340);
			setlinecolor(BLUE);
			rectangle(5, 30, 80, 60);
		}
	}
	//char space;
	//scanf_s("\n%c", &space);
}
void Store::Search_before() {
	int Month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int mo, day;
	char str2[30];
	while (1) {
		InputBox(str2, 10, "请输入日期(格式xx-xx)如0925,0609");
		 mo = (str2[0] - '0') * 10 + str2[1] - '0';
		 day = (str2[2] - '0') * 10 + str2[3] - '0';
		if (strlen(str2) == 4 && mo >= 1 && mo <= 12 && day >= 1 && day <= Month[mo]) break;
	}
	cleardevice();
	IMAGE background;//定义一个图片名.
	loadimage(&background, "bk2.jpg", 640, 480, 1);//从图片文件获取图像
	putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)
	ifstream file;
	file.open("date_study.txt");
	string ans;
	bool jg = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= Month[i]; j++) {
			getline(file, ans);
			if (mo == i && day == j) {
				jg = 1;
				break;
			}
		}
		if (jg) break;
	}
	
	string date_show = to_string(mo) + "月";
	date_show += to_string(day) + "日";
	date_show = "您在" + date_show + "学习了" + ans + "个单词!";
	settextstyle(30, 0, "微软雅黑");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	outtextxy(160, 150, date_show.c_str());
	outtextxy(230, 200, "继续加油呀!");
	time_t now = time(0);
	/*
	time_t now;
	time(&now);
	*/
	struct tm p;//指向本地时间的tm结构体
	localtime_s(&p, &now);
	char date1[500];
	char date2[500];
	sprintf_s(date1, "%04d年%02d月%02d日", p.tm_year + 1900, p.tm_mon + 1, p.tm_mday);
	//sprintf_s(date2,"%02d时%02d分%02d秒", p.tm_hour, p.tm_min, p.tm_sec);
	settextstyle(25, 0, "微软雅黑");
	outtextxy(400, 400, date1);
	//outtextxy(200, 250, str2);
	MOUSEMSG m;
	while (1) {
		m = GetMouseMsg();
		if (m.x>=100&&m.x<=500&&m.y>=100&&m.y<=300) {
			if (m.uMsg == WM_LBUTTONDOWN) {
				closegraph();
				break;
			}
		}
	}
}