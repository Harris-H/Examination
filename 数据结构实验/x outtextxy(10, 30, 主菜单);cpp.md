```cpp
outtextxy(10, 30, "主菜单");
else if (m.x >= 5 && m.x <= 80 && m.y >= 30 && m.y <= 60) {
				setlinecolor(RED);
				rectangle(5, 30, 80, 60);
				if (m.uMsg == WM_LBUTTONDOWN) {
					closegraph();
					PlaySound("Appclick.wav", NULL, SND_FILENAME | SND_ASYNC);
					break;
				}
			}

rectangle(5, 30, 80, 60);
```

