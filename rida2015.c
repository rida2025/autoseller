#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void click() 
{
    INPUT input = {0};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));
	Sleep(60);
}

int main() 
{
    int RandomList[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int len = sizeof(RandomList) / sizeof(RandomList[0]);
    srand(time(NULL));
    printf("the auto seller is ON\n");
    while(1){
    	if(GetAsyncKeyState(VK_F6))
    	{

		    int x = 1372;
		    int y = 642;

		    for (int i = 0; i < 4; ++i)
		    {
		    	for (int i = 0; i < 7; ++i)
		    	{
		    		int rx = RandomList[rand() % len];
		    		int ry = RandomList[rand() % len];
		    		SetCursorPos(x+rx, y+ry);
		    		printf("we clicked on x: %d y: %d\n", x+rx, y+ry);
		    		x = x + 80;
		    		click();
		    	}
		    	x = 1372;
		    	y = y + 80;
		    }
    	}
    	else if (GetAsyncKeyState(VK_F7))
    	{
    		break;
    	}
    }
    return 0;
}