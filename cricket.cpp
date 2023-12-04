#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>
using namespace std;
void moveon()//clears the screen//
{
	char a;
	cout << "PRESS SPACE TO CONTINUE." << endl;
	a = _getch();
	while (a != ' ')
	{
		a = _getch();
	}
	system("cls");
}
void crossing(int& playingindex, int& facing, int& running)//over crossing//
{
	if (playingindex == facing)
	{
		playingindex = running;
	}
	else if (playingindex == running)
	{
		playingindex = facing;
	}
}
void award(int yourbowl[][4], int bowler[][4], char yteam[][50], char oppteam[][50], int arr1[][4], int arr2[][4])//Determines award//
{
	ofstream gamefile;
	gamefile.open("gamesave.txt", ios::app);
	int highscore[1][3] = { INT_MIN,0,0 };
	int highwicket[1][3] = { INT_MIN,0,0 };
	int mostboundry[1][3] = { INT_MIN,0,0 };
	int highscore1[1][3] = { INT_MIN,0,0 };
	int highwicket1[1][3] = { INT_MIN,0,0 };
	int mostboundry1[1][3] = { INT_MIN,0,0 };
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (arr1[i][j] > highscore[0][0])
			{
				highscore[0][0] = arr1[i][j];
				highscore[0][1] = i;
				highscore[0][2] = arr1[i][j + 1];
			}
			if (arr1[i][j] == highscore[0][0])
			{
				if (arr1[i][j + 1] < highscore[0][2])
				{
					highscore[0][0] = arr1[i][j];
					highscore[0][1] = i;
					highscore[0][2] = arr1[i][j + 1];
				}
				else
				{
					continue;
				}
			}
		}
		for (int j = 2; j < 3; j++)
		{
			if ((arr1[i][j] + arr1[i][j + 1]) > mostboundry[0][0])
			{
				mostboundry[0][0] = (arr1[i][j] + arr1[i][j + 1]);
				mostboundry[0][1] = i;
				mostboundry[0][2] = arr1[i][j - 1];
			}
			if ((arr1[i][j] + arr1[i][j + 1]) == mostboundry[0][0])
			{
				if (arr1[i][j - 1] < mostboundry[0][2])
				{
					mostboundry[0][0] = (arr1[i][j] + arr1[i][j + 1]);
					mostboundry[0][1] = i;
					mostboundry[0][2] = arr1[i][j - 1];
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (arr2[i][j] > highscore1[0][0])
			{
				highscore1[0][0] = arr2[i][j];
				highscore1[0][1] = i;
				highscore1[0][2] = arr2[i][j + 1];
			}
			if (arr2[i][j] == highscore1[0][0])
			{
				if (arr2[i][j + 1] < highscore1[0][2])
				{
					highscore1[0][0] = arr2[i][j];
					highscore1[0][1] = i;
					highscore1[0][2] = arr2[i][j + 1];
				}
				else
				{
					continue;
				}
			}
		}
		for (int j = 2; j < 3; j++)
		{
			if ((arr2[i][j] + arr2[i][j + 1]) >= mostboundry1[0][0])
			{
				mostboundry1[0][0] = (arr2[i][j] + arr2[i][j + 1]);
				mostboundry1[0][1] = i;
				mostboundry1[0][2] = arr2[i][j - 1];
			}
			if ((arr2[i][j] + arr2[i][j + 1]) == mostboundry1[0][0])
			{
				if (arr2[i][j - 1] < mostboundry1[0][2])
				{
					mostboundry1[0][0] = (arr2[i][j] + arr2[i][j + 1]);
					mostboundry1[0][1] = i;
					mostboundry1[0][2] = arr2[i][j - 1];
				}
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 3; j < 4; j++)
		{
			if (yourbowl[i][j] > highwicket[0][0])
			{
				highwicket[0][0] = yourbowl[i][j];
				highwicket[0][1] = i + 6;
				highwicket[0][2] = yourbowl[i][j - 1];
			}
			if (yourbowl[i][j] == highwicket[0][0])
			{
				if (yourbowl[i][j - 1] < highwicket[0][2])
				{
					highwicket[0][0] = yourbowl[i][j];
					highwicket[0][1] = i + 6;
					highwicket[0][2] = yourbowl[i][j - 1];
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 3; j < 4; j++)
		{
			if (bowler[i][j] > highwicket1[0][0])
			{
				highwicket1[0][0] = bowler[i][j];
				highwicket1[0][1] = i + 6;
				highwicket1[0][2] = bowler[i][j - 1];
			}
			if (bowler[i][j] == highwicket1[0][0])
			{
				if (bowler[i][j - 1] < highwicket1[0][2])
				{
					highwicket1[0][0] = bowler[i][j];
					highwicket1[0][1] = i + 6;
					highwicket1[0][2] = bowler[i][j - 1];
				}
			}
		}
	}
	cout << "\t\tWELCOME TO AWARD CERMONY" << endl;
	if (highscore[0][0] > highscore1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "BEST BATSMEN OF THE MATCH IS." << endl;
		cout << yteam[highscore[0][1]] << " scored the highest score of match " << arr1[highscore[0][1]][0] << "(" << arr1[highscore[0][1]][1] << ")" << endl;
		gamefile<< "BEST BATSMEN OF THE MATCH IS." << endl;
		gamefile << yteam[highscore[0][1]] << " scored the highest score of match " << arr1[highscore[0][1]][0] << "(" << arr1[highscore[0][1]][1] << ")" << endl;
		gamefile << "\n";
	}
	if (highscore[0][0] < highscore1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "BEST BATSMEN OF THE MATCH IS." << endl;
		cout << oppteam[highscore1[0][1]] << " scored the highest score of match " << arr2[highscore1[0][1]][0] << "(" << arr2[highscore1[0][1]][1] << ")" << endl;
		gamefile << "BEST BATSMEN OF THE MATCH IS." << endl;
		gamefile << oppteam[highscore1[0][1]] << " scored the highest score of match " << arr2[highscore1[0][1]][0] << "(" << arr2[highscore1[0][1]][1] << ")" << endl;
		gamefile << "\n";
	}
	if (highscore[0][0] == highscore1[0][0])
	{
		if (highscore[0][2] > highscore1[0][2])
		{
			cout << "\n\n\n\n" << endl;
			cout << "BEST BATSMEN OF THE MATCH IS." << endl;
			cout << oppteam[highscore1[0][1]] << " scored the highest score of match " << arr2[highscore1[0][1]][0] << "(" << arr2[highscore1[0][1]][1] << ")" << endl;
			gamefile << "BEST BATSMEN OF THE MATCH IS." << endl;
			gamefile << oppteam[highscore1[0][1]] << " scored the highest score of match " << arr2[highscore1[0][1]][0] << "(" << arr2[highscore1[0][1]][1] << ")" << endl;
			gamefile << "\n";
		}
		else
		{
			cout << "\n\n\n\n" << endl;
			cout << "BEST BATSMEN OF THE MATCH IS." << endl;
			cout << yteam[highscore[0][1]] << " scored the highest score of match " << arr1[highscore[0][1]][0] << "(" << arr1[highscore[0][1]][1] << ")" << endl;
			gamefile << "BEST BATSMEN OF THE MATCH IS." << endl;
			gamefile << yteam[highscore[0][1]] << " scored the highest score of match " << arr1[highscore[0][1]][0] << "(" << arr1[highscore[0][1]][1] << ")" << endl;
			gamefile << "\n";
		}
	}
	moveon();
	if (mostboundry[0][0] > mostboundry1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "MOST IMPACTFULL PLAYER IS." << endl;
		cout << yteam[mostboundry[0][1]] << " hit the most boundries of match " << arr1[mostboundry[0][1]][2] << " FOURS AND " << arr1[mostboundry[0][1]][3] << " SIXES." << endl;
		gamefile << "MOST IMPACTFULL PLAYER IS." << endl;
		gamefile << yteam[mostboundry[0][1]] << " hit the most boundries of match " << arr1[mostboundry[0][1]][2] << " FOURS AND " << arr1[mostboundry[0][1]][3] << " SIXES." << endl;
		gamefile << "\n";
	}
	if (mostboundry[0][0] < mostboundry1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "MOST IMPACTFULL PLAYER IS." << endl;
		cout << oppteam[mostboundry1[0][1]] << " hit the most boundries of match " << arr2[mostboundry1[0][1]][2] << " FOURS AND " << arr2[mostboundry1[0][1]][3] << " SIXES." << endl;
		gamefile << "MOST IMPACTFULL PLAYER IS." << endl;
		gamefile << oppteam[mostboundry1[0][1]] << " hit the most boundries of match " << arr2[mostboundry1[0][1]][2] << " FOURS AND " << arr2[mostboundry1[0][1]][3] << " SIXES." << endl;
		gamefile << "\n";
	}
	if (mostboundry[0][0] == mostboundry1[0][0])
	{
		if (mostboundry[0][2] > mostboundry1[0][2])
		{
			cout << "\n\n\n\n" << endl;
			cout << "MOST IMPACTFULL PLAYER IS." << endl;
			cout << oppteam[mostboundry1[0][1]] << " hit the most boundries of match " << arr2[mostboundry1[0][1]][2] << " FOURS AND " << arr2[mostboundry1[0][1]][3] << " SIXES." << endl;
			gamefile << "MOST IMPACTFULL PLAYER IS." << endl;
			gamefile << oppteam[mostboundry1[0][1]] << " hit the most boundries of match " << arr2[mostboundry1[0][1]][2] << " FOURS AND " << arr2[mostboundry1[0][1]][3] << " SIXES." << endl;
			gamefile << "\n";
		}
		else
		{
			cout << "\n\n\n\n" << endl;
			cout << "MOST IMPACTFULL PLAYER IS." << endl;
			cout << yteam[mostboundry[0][1]] << " hit the most boundries of match " << arr1[mostboundry[0][1]][2] << " FOURS AND " << arr1[mostboundry[0][1]][3] << " SIXES." << endl;
			gamefile << "MOST IMPACTFULL PLAYER IS." << endl;
			gamefile << yteam[mostboundry[0][1]] << " hit the most boundries of match " << arr1[mostboundry[0][1]][2] << " FOURS AND " << arr1[mostboundry[0][1]][3] << " SIXES." << endl;
			gamefile << "\n";
		}
	}
	moveon();
	if (highwicket[0][0] > highwicket1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "BEST BOWLER OF THE MATCH IS." << endl;
		cout << yteam[highwicket[0][1]] << " took the most wickets of match " << yourbowl[highwicket[0][1] - 6][3] << endl;
		gamefile << "BEST BOWLER OF THE MATCH IS." << endl;
		gamefile << yteam[highwicket[0][1]] << " took the most wickets of match " << yourbowl[highwicket[0][1] - 6][3] << endl;
		gamefile << "\n";
	}
	if (highwicket[0][0] < highwicket1[0][0])
	{
		cout << "\n\n\n\n" << endl;
		cout << "BEST BOWLER OF THE MATCH IS." << endl;
		cout << oppteam[highwicket1[0][1]] << " took the most wickets of match " << bowler[highwicket1[0][1] - 6][3] << endl;
		gamefile << "BEST BOWLER OF THE MATCH IS." << endl;
		gamefile << oppteam[highwicket1[0][1]] << " took the most wickets of match " << bowler[highwicket1[0][1] - 6][3] << endl;
		gamefile << "\n";
	}
	if (highwicket[0][0] == highwicket1[0][0])
	{
		if (highwicket[0][2] > highwicket1[0][2])
		{
			cout << "\n\n\n\n" << endl;
			cout << "BEST BOWLER OF THE MATCH IS." << endl;
			cout << oppteam[highwicket1[0][1]] << " took the most wickets of match " << bowler[highwicket1[0][1] - 6][3] << endl;
			gamefile << "BEST BOWLER OF THE MATCH IS." << endl;
			gamefile << oppteam[highwicket1[0][1]] << " took the most wickets of match " << bowler[highwicket1[0][1] - 6][3] << endl;
			gamefile << "\n";
		}
		else
		{
			cout << "\n\n\n\n" << endl;
			cout << "BEST BOWLER OF THE MATCH IS." << endl;
			cout << yteam[highwicket[0][1]] << " took the most wickets of match " << yourbowl[highwicket[0][1] - 6][3] << endl;
			gamefile << "BEST BOWLER OF THE MATCH IS." << endl;
			gamefile << yteam[highwicket[0][1]] << " took the most wickets of match " << yourbowl[highwicket[0][1] - 6][3] << endl;
			gamefile << "\n";
		}
	}
	gamefile.close();
	moveon();
}
void out(int& i, int& overwic, int& wickets, int oppteamscore[][4], int yourbowl[][4], int& ballerindex)//DETERMINES OUT AND ADD VALUES TO ARRAYS//
{
	overwic += 1;
	wickets++;
	cout << "\t\tOUT-BATSMEN" << endl;
	oppteamscore[1][3] = wickets;
	oppteamscore[1][1] = i;
	yourbowl[ballerindex][1] = i;
	yourbowl[ballerindex][3] += 1;
}
void runningbt(int n, int& playingindex, int& facing, int& running, int yourteam[][4], char yteam[][50], int half[11], int cen[11])//CHECKS NUMBER OF SIXES AND FOURS AND ADDS THEM TO ARRAY AND CHECKS IF ODD NUMBER OF SCORE SO CROSSING TAKES PLACE AND CHECKS HALF CENTURY AND CENTURY//
{
	int found = 0;
	if (n % 2 == 0)
	{
		if (playingindex == facing)
		{
			yourteam[facing][0] += n;
			yourteam[facing][1] += 1;
			if (n == 4)
			{
				cout << "\t\tFOUR RUNS" << endl;
				yourteam[facing][2] += 1;
			}
			if (n == 6)
			{
				cout << "\t\tSIX RUNS" << endl;
				yourteam[facing][3] += 1;
			}
			if (yourteam[facing][0] >= 50 && yourteam[facing][0] < 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (half[i] == facing)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						half[facing] = facing;
					}
				}
				if (found == 0)
				{
					cout << yteam[facing] << " HALF-CENTURY" << endl;
					moveon();
				}
			}
			found = 0;
			if (yourteam[facing][0] >= 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (cen[i] == facing)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						cen[facing] = facing;
					}
				}
				if (found == 0)
				{
					cout << yteam[facing] << " CENTURY" << endl;
					moveon();
				}
			}
		}
		else if(playingindex == running)
		{
			found = 0;
			yourteam[running][0] += n;
			yourteam[running][1] += 1;
			if (n == 4)
			{
				cout << "\t\tFOUR RUNS" << endl;
				yourteam[running][2] += 1;
			}
			if (n == 6)
			{
				cout << "\t\tSIX RUNS" << endl;
				yourteam[running][3] += 1;
			}
			if (yourteam[running][0] >= 50 && yourteam[running][0] < 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (half[i] == running)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						half[running] = running;
					}
				}
				if (found == 0)
				{
					cout << yteam[running] << " HALF-CENTURY" << endl;
					moveon();
				}
			}
			found = 0;
			if (yourteam[running][0] >= 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (cen[i] == running)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						cen[running] = running;
					}
				}
				if (found == 0)
				{
					cout << yteam[running] << " CENTURY" << endl;
					moveon();
				}
			}
		}
	}
	else if (n % 2 != 0)
	{
	    found = 0;
		if (playingindex == facing)
		{
			yourteam[facing][0] += n;
			if (yourteam[facing][0] >= 50 && yourteam[facing][0] < 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (half[i] == facing)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						half[facing] = facing;
					}
				}
				if (found == 0)
				{
					cout << yteam[facing] << " HALF-CENTURY" << endl;
					moveon();
				}
			}
			found = 0;
			if (yourteam[facing][0] >= 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (cen[i] == facing)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						cen[facing] = facing;
					}
				}
				if (found == 0)
				{
					cout << yteam[facing] << " CENTURY" << endl;
					moveon();
				}
			}
			playingindex = running;
			yourteam[facing][1] += 1;
		}
		else if (playingindex == running)
		{
			found = 0;
			yourteam[running][0] += n;
			if (yourteam[running][0] >= 50 && yourteam[running][0] < 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (half[i] == running)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						half[running] = running;
					}
				}
				if (found == 0)
				{
					cout << yteam[running] << " HALF-CENTURY" << endl;
					moveon();
				}
			}
			found = 0;
			if (yourteam[running][0] >= 100)
			{
				for (int i = 0; i < 11; i++)
				{
					if (cen[i] == running)
					{
						found = 1;
					}
					else if (i == 10 && found == 0)
					{
						cen[running] = running;
					}
				}
				if (found == 0)
				{
					cout << yteam[running] << " CENTURY" << endl;
					moveon();
				}
			}
			playingindex = facing;
			yourteam[running][1] += 1;
		}
	}
}
void extrarun(int& extra, int& overrun, int& n, int teamscore[][4], int bowler[][4], int& ballerindex, int i)//GIVES EXTRA RUN AND ADD THEM TO BOWLER AND TEAMSCORE//
{
	overrun += 1;
	extra++;
	overrun += n;
	teamscore[1][0] += n;
	teamscore[1][0] += 1;
	teamscore[1][1] = i;
	bowler[ballerindex][1] = i;
	bowler[ballerindex][2] += n;
	bowler[ballerindex][2] += 1;
}
void run(int& overrun, int& n, int teamscore[][4], int bowler[][4], int& i, int& ballerindex)//ADD number of run to teamscore and bowler//
{
	overrun += n;
	teamscore[1][0] += n;
	teamscore[1][1] = i;
	bowler[ballerindex][1] = i;
	bowler[ballerindex][2] += n;
}
int margin(int target, int arr[][4])//Determines target difference//
{
	int j = target - 1;
	j = j - arr[1][0];
	return j;
}
int balleroption(int ballerindex, int yourbowl[5][4], char ybow[5][30], int limit)// GIVES YOU OPTION TO CHOOSE YOUR OWN BOWLER OPTION//
{
	int pre = ballerindex;
	int next = 0;
	cout << "FROM WHICH BOWLER DO YOU WANT BOWL\n" << endl;
	cout << "  BOWLER\t\tOVER\tBALLS\tRUN\tWICKETS\tECO" << endl;
	cout << endl;
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		for (k = 1; k < 2; k++)
		{
			if (yourbowl[i][k] == 5)
			{
				yourbowl[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int n = strlen(ybow[i]);
		if (n < 6)
		{
			cout << i + 1 << "." << ybow[i] << "\t\t";
		}
		else
		{
			cout << i + 1 << "." << ybow[i] << "\t";
		}
		for (int j = 0; j < 4; j++)
		{
			cout << yourbowl[i][j] << "\t";

		}
		float eco1 = 0;
		if (yourbowl[i][2] == 0)
		{
			eco1 = 0;
		}
		else
		{
			float eco = yourbowl[i][2];
			float ball = yourbowl[i][0];
			eco1 = eco / ball;
		}
		cout << eco1;
		cout << endl;

	}
	cout << endl;
	cout << "YOUR INPUT:";
	cin >> next;
	if (next > 5 || next <= 0)
	{
		cout << "ENTER CORRECT INPUT.";
		cin >> next;
	}
	next = next - 1;
	while (next == pre || yourbowl[next][0] >= limit / 5)
	{
		cout << "ENTER CORRECT INPUT.";
		cin >> next;
		next = next - 1;
	}
	return next;
}
void targetl(int target, int arr[][4], int arr1[][4], int o, int i, int wickets, int v, int limit)//OUTPUTS THE HEADER OF YOUR OWN SCORE AND TEAM SCORE AND DETERMINES CURRENT RUN RATE AND TARGET LEFT AND OVERALL RUNRATE//
{
	if (arr1[1][2] == limit)
	{
		arr1[1][1] = 0;
	}
	if (arr[1][2] == limit)
	{
		arr[1][1] = 0;
	}
	if (arr[1][2] == limit / 2)
	{
		arr[1][1] = i;
		if (arr[1][0] < 100)
		{
			cout << " " << arr[1][0] << "/" << arr[1][3] << setw(52) << " " << arr1[1][0] << "/" << arr1[1][3] << endl;
			cout << "(" << arr[1][2] << " . " << arr[1][1] << ")" << setw(50) << "(" << arr1[1][2] << " . " << arr1[1][1] << ")" << endl;

		}
		else if (arr[1][0] >= 100)
		{
			cout << " " << arr[1][0] << "/" << arr[1][3] << setw(52) << " " << arr1[1][0] << "/" << arr1[1][3] << endl;
			cout << "(" << arr[1][2] << " . " << arr[1][1] << ")" << setw(50) << "(" << arr1[1][2] << " . " << arr1[1][1] << ")" << endl;
		}
	}
	else if (arr[1][0] < 100)
	{
		cout << " " << arr[1][0] << "/" << arr[1][3] << setw(52) << " " << arr1[1][0] << "/" << arr1[1][3] << endl;
		cout << "(" << arr[1][2] << " . " << arr[1][1] << ")" << setw(50) << "(" << arr1[1][2] << " . " << arr1[1][1] << ")" << endl;

	}
	else if (arr[1][0] >= 100)
	{
		cout << " " << arr[1][0] << "/" << arr[1][3] << setw(52) << " " << arr1[1][0] << "/" << arr1[1][3] << endl;
		cout << "(" << arr[1][2] << " . " << arr[1][1] << ")" << setw(50) << "(" << arr1[1][2] << " . " << arr1[1][1] << ")" << endl;
	}
	float c = arr[1][0];
	float r = ((arr[1][2] + 1));
	float crr = c / r;
	if (v == 0)
	{
		if (arr[1][3] != 10)
		{
			cout << "\t            " << "CRR: " << crr << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}
		if (arr[1][3] == 10)
		{
			crr = c / limit;
			cout << "\t            " << "CRR: " << crr << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}
	}
	else if (v == 1)
	{
		float over = limit - o;
		float rr = target - arr[1][0];
		float rrr = rr / over;
		int j = 10 - wickets;
		c = arr[1][0];
		r = ((o + 1));
		crr = c / r;
		int s = target - arr[1][0];
		int v = (limit * 6) - ((o * 6) + i);
		if (s <= 0)
		{
			s = 0;
			rrr = 0;
			crr = c / limit;
		}
		if (j == 0)
		{
			crr = c / limit;
		}
		cout << "TARGET LEFT : " << s << "   BALLS LEFT : " << v << "   CRR : " << crr;
		cout << "  WICKETS LEFT : " << j << "   RR : " << rrr << endl;
		cout << "------------------------------------------------------------------------------ " << endl;
	}
}
void current(char yteam[][50], int arr1[][4], int facing, int running, int playinngindex, char oppbal[][30], int ballingindex, int arr[][4])//OUTPUTS THE CURRENT PLAYING BATSMENS SCORE AND THE BOWLER BOWLING TO THEM//
{
	if (playinngindex == facing)
	{
		cout << yteam[facing] << "*" << " :   " << arr1[facing][0] << "(" << arr1[facing][1] << ")" << "\t\t" << oppbal[ballingindex] << ":  " << arr[ballingindex][3] << "/" << arr[ballingindex][2] << "  (" << arr[ballingindex][0] << "." << arr[ballingindex][1] << ")" << endl;
		cout << yteam[running] << " :    " << arr1[running][0] << "(" << arr1[running][1] << ")" << endl;
	}
	else if (playinngindex == running)
	{
		cout << yteam[facing] << " :    " << arr1[facing][0] << "(" << arr1[facing][1] << ")" << "\t\t" << oppbal[ballingindex] << ":  " << arr[ballingindex][3] << "/" << arr[ballingindex][2] << "  (" << arr[ballingindex][0] << "." << arr[ballingindex][1] << ")" << endl;
		cout << yteam[running] << "*" << " :   " << arr1[running][0] << "(" << arr1[running][1] << ")" << endl;
	}
}
void overallbat(ofstream& gamefile, char yteam[][50], int arr1[][4])//PRINTS THE BATSMEN ARRAY WITH SCORE AND NUMBER OF SIXES FOURS AND STRIKE RATE AND ADDING THE TO FILE//
{
	gamefile.open("gamesave.txt", ios::app);
	if (gamefile.is_open())
	{
		cout << "BATSMEN\t\tRUN\tBALLS\tFOUR\tSIXES\tSR" << endl;
		gamefile << "BATSMEN\t\tRUN\tBALLS\tFOUR\tSIXES\tSR" << endl;
		cout << endl;
		for (int i = 0; i < 11; i++)
		{
			int n = strlen(yteam[i]);
			if (n > 7)
			{
				cout << yteam[i] << "\t";
				gamefile << yteam[i] << "\t";
			}
			else
			{
				cout << yteam[i] << "\t\t";
				gamefile << yteam[i] << "\t\t";
			}
			for (int j = 0; j < 4; j++)
			{
				cout << arr1[i][j] << "\t";
				gamefile << arr1[i][j] << "\t";
			}
			float run = arr1[i][0];
			float ball = arr1[i][1];
			float sr = (run / ball) * 100;
			if (arr1[i][0] == 0)
			{
				sr = 0;
			}
			else
			{
				sr = (run / ball) * 100;
			}
			cout << sr;
			gamefile << sr;
			cout << endl;
			gamefile << endl;
		}
		gamefile << "\n";
	}
	gamefile.close();
}
void overallball(ofstream& gamefile, int arr[][4], char oppbal[][30])//PRINTS THE SCORE OF BOWLER WITH WICKETS AND RUNS AND ECONOY AND PRINTS THEM IN FILE//
{
	gamefile.open("gamesave.txt", ios::app);
	cout << "BOWLER\t\tOVER\tBALLS\tRUN\tWICKETS\tECO" << endl;
	gamefile << "BOWLER\t\tOVER\tBALLS\tRUN\tWICKETS\tECO" << endl;
	cout << endl;
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		for (k = 1; k < 2; k++)
		{
			if (arr[i][k] == 5)
			{
				arr[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int n = strlen(oppbal[i]);
		if (n > 7)
		{
			cout << oppbal[i] << "\t";
			gamefile << oppbal[i] << "\t";
		}
		else
		{
			cout << oppbal[i] << "\t\t";
			gamefile << oppbal[i] << "\t\t";
		}
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
			gamefile << arr[i][j] << "\t";

		}
		float eco1 = 0;
		if (arr[i][0] == 0 && arr[i][2] == 0 && arr[i][1] == 0)
		{
			eco1 = 0;
		}
		else if (arr[i][0] == 0 && arr[i][2] > 0 && arr[i][1] >= 0)
		{
			float eco = arr[i][2];
			float ball = 1;
			eco1 = eco / ball;
		}
		else
		{
			float eco = arr[i][2];
			float ball = arr[i][0];
			eco1 = eco / ball;
		}
		cout << eco1;
		cout << endl;
		gamefile << eco1;
		gamefile << endl;
	}
	gamefile << "\n";
	gamefile.close();
}
int baller1(int ballerindex)//CHOOSES OPPOSITION BOWLERS//
{
	int n = ballerindex;
	n--;
	if (n < 0)
	{
		n = 4;
	}
	return n;
}
int toss()//DETERMINES TOSS//
{
	srand((unsigned)time(NULL));
	int n = rand() % 2;
	return n;
}
int option()//DETERMINES OPPOSITION STANCE ON WINNING TOSS//
{
	srand((unsigned)time(NULL));
	int n = rand() % 2;
	return n;
}
int wicket7()//GIVES SCORE TO BATSMEN ABOVE INDEX 7//
{
	srand((unsigned)time(NULL));
	int n = rand() % 20;
	int x = 0;
	int s = n;
	if (s == 10)
	{
		x = 5;
	}
	if (s == 19)
	{
		x = 3;
	}
	if (s == 6)
	{
		x = 0;
	}
	if (s == 15)
	{
		x = 2;
	}
	if (s == 3 || s == 5)
	{
		x = 6;
	}
	if (s == 1 || s == 17)
	{
		x = 4;
	}
	if (s == 8)
	{
		x = 1;
	}
	if (s == 0 || s == 2 || s == 4 || s == 7 || s == 9 || s == 11 || s == 12 || s == 14 || s == 16 || s == 17)
	{
		x = -2;
	}
	if (s == 13)
	{
		x = -3;
	}
	return x;
}
int wicket0()//GIVES SCORE TO BATSMEN BELOW INDEX 7//
{
	srand((unsigned)time(NULL));
	int n = rand() % 20;
	int x = 0;
	int s = n;
	if (s == 0)
	{
		x = 5;
	}
	if (s == 3)
	{
		x = 3;
	}
	if (s == 5 || s == 11 || s == 9)
	{
		x = 0;
	}
	if (s == 6 || s == 10 || s == 18 || s == 12)
	{
		x = 2;
	}
	if (s == 8)
	{
		x = 6;
	}
	if (s == 17 || s == 14)
	{
		x = 4;
	}
	if (s == 19 || s == 15 || s == 7)
	{
		x = 1;
	}
	if (s == 13 || s == 2)
	{
		x = -2;
	}
	if (s == 16 || s == 4)
	{
		x = -1;
	}
	if (s == 1)
	{
		x = -3;
	}
	return x;
}
void overallbatinn(char yteam[][50], int arr1[][4])//PRINTS THE BATSMEN ARRAY WITH SCORE AND NUMBER OF SIXES FOURS AND STRIKE RATE//
{
	cout << "BATSMEN\t\tRUN\tBALLS\tFOUR\tSIXES\tSR" << endl;
	cout << endl;
	for (int i = 0; i < 11; i++)
	{
		int n = strlen(yteam[i]);
		if (n > 7)
		{
			cout << yteam[i] << "\t";
		}
		else
		{
			cout << yteam[i] << "\t\t";
		}
		for (int j = 0; j < 4; j++)
		{
			cout << arr1[i][j] << "\t";
		}
		float run = arr1[i][0];
		float ball = arr1[i][1];
		float sr = (run / ball) * 100;
		if (arr1[i][0] == 0)
		{
			sr = 0;
		}
		else
		{
			sr = (run / ball) * 100;
		}
		cout << sr;
		cout << endl;
	}
}
void overallballinn(int arr[][4], char oppbal[][30])//PRINTS THE SCORE OF BOWLER WITH WICKETS AND RUNS AND ECONOY//
{
	cout << "BOWLER\t\tOVER\tBALLS\tRUN\tWICKETS\tECO" << endl;
	cout << endl;
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		for (k = 1; k < 2; k++)
		{
			if (arr[i][k] == 5)
			{
				arr[i][k] = 0;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		int n = strlen(oppbal[i]);
		if (n > 7)
		{
			cout << oppbal[i] << "\t";
		}
		else
		{
			cout << oppbal[i] << "\t\t";
		}
		for (int j = 0; j < 4; j++)
		{
			cout << arr[i][j] << "\t";
		}
		float eco1 = 0;
		if (arr[i][0] == 0 && arr[i][2] == 0 && arr[i][1] == 0)
		{
			eco1 = 0;
		}
		else if (arr[i][0] == 0 && arr[i][2] > 0 && arr[i][1] > 0)
		{
			float eco = arr[i][2];
			float ball = 1;
			eco1 = eco / ball;
		}
		else if (arr[i][0] > 0 && arr[i][2] > 0)
		{
			float eco = arr[i][2];
			float ball = arr[i][0];
			eco1 = eco / ball;
		}
		cout << eco1;
		cout << endl;
	}
}
int main()
{
	cout << "WELCOME TO CONSOLE CRICKET 2023" << endl;//MENU SETTING//
	moveon();
	cout << "\t\tMENU" << endl;
	cout << "\tPRESS 1 TO SEE SETTINGS" << endl;
	cout << "\tPRESS 2 TO SEE HOW TO PLAY" << endl;
	cout << "\tPRESS 3 TO KNOW ABOUT THE GAME" << endl;
	cout << "\tPRESS 4 TO PLAY THE GAME" << endl;
	int e;
	cin >> e;
	moveon();
	while (e != 1 && e != 2 && e != 3 && e != 4)
	{
		system("cls");
		cout << "ENTER CORRECT INPUT" << endl;
		cin >> e;
		moveon();
	}
	if (e == 1)
	{
		cout << "\n\n\n\n" << endl;
		cout << "\tPRESS ENTER TO PLAY" << endl;
		cout << "\tPRESS SPACE TO MOVE TO OTHER STAGE" << endl;
		cout << "\tPRESS S TO SAVE GAME IN END" << endl;
		cout << "\tPLAYER 1-6 ARE BATSMEN" << endl;
		cout << "\tPLAYER 7-11 ARE BOWLER" << endl;
		cout << "\tYOU CAN CHOOSE YOUR OWN BOWLERS" << endl;
		moveon();
	}
	if (e == 2)
	{
		cout << "\n\n\n\n" << endl;
		cout << "\tFIRST ENTER TEAM NAMES" << endl;
		cout << "\tTHEN CHOOSE A TEAM" << endl;
		cout << "\tTHEN PICKS HEADS OR TAILS" << endl;
		cout << "\tTHEN COMPLETE YOUR INNINGS" << endl;
		moveon();
	}
	if (e == 3)
	{
		cout << "\n\n\n\n" << endl;
		cout << "\tMADE BY MOHAMMAD FAKHIR AND ABDULLAH BOTTAR" << endl;
		cout << "\tA CONSOLE COPY VERSION OF EA SPORTS 2007" << endl;
		cout << "\tCOPY RIGHTS RESERVED" << endl;
		moveon();
	}
	cout << "ENTER THE PLAYERS NAME FOR TWO TEAMS" << endl;
	char teama[11][50];
	char teamb[11][50];
	cout << "ENTER THE PLAYERS NAME FOR TEAM A" << endl;//TEAM A PLAYERS ENTRY//
	for (int i = 0; i < 11; i++)
	{
		cout << "Player " << i + 1 << " name: ";
		cin >> teama[i];
	}
	cout << endl;
	system("cls");
	cout << "ENTER THE PLAYERS NAME FOR TEAM B" << endl;//TEAM B PLAYER ENTRY//
	for (int i = 0; i < 11; i++)
	{
		cout << "Player " << i + 1 << " name: ";
		cin >> teamb[i];
	}
	cout << endl;
	system("cls");
	cout << "\tTHE TWO TEAMS ARE" << endl;
	cout << "TEAM A" << "\t\t\t\t" << "TEAM B" << endl;//PRESENTS THE TWO TEAMS//
	for (int i = 0; i < 11; i++)
	{
		int n = strlen(teama[i]);
		if (n > 7)
		{
			cout << teama[i] << "\t" << "|" << "\t\t" << teamb[i] << endl;
		}
		else
		{
			cout << teama[i] << "\t\t" << "|" << "\t\t" << teamb[i] << endl;
		}
	}
	moveon();
	cout << "WHICH TEAM DO YOU WANT TO CHOOSE A OR B:";//SELECTING ONE TEAM//
	char op;
	cin >> op;
	while (op != 'a' && op != 'A' && op != 'b' && op != 'B')
	{
		system("cls");
		cout << "ENTER CORRECT OPTION:";
		cin >> op;
	}
	char yteam[11][50];
	char oppteam[11][50];
	int n = 0;
	if (op == 'a' || op == 'A')
	{
		for (int i = 0; i < 11; i++)
		{
			strcpy_s(yteam[i], teama[i]);
			strcpy_s(oppteam[i], teamb[i]);
		}
	}
	else if (op == 'b' || op == 'B')
	{
		for (int i = 0; i < 11; i++)
		{
			strcpy_s(yteam[i], teamb[i]);
			strcpy_s(oppteam[i], teama[i]);
		}
	}
	cout << "your team" << "\t\t" << "oppistion team" << endl;//PRESENTS YOUR TEAM//
	for (int i = 0; i < 11; i++)
	{
		int n = strlen(yteam[i]);
		if (n > 7)
		{
			cout << yteam[i] << "\t\t" << oppteam[i] << endl;
		}
		else
		{
			cout << yteam[i] << "\t\t\t" << oppteam[i] << endl;
		}
	}
	moveon();
	string strh = "head";
	string strt = "tail";
	char str[5];
	cout << "Choose head or tail for the toss:";//TOSS SETTING//
	cin >> str;
	if (str != strh && str != strt)
	{
		while (str != strh && str != strt)
		{
			cout << "Enter correct option." << endl;
			cin.getline(str, 5);
		}
	}
	int up = 0;
	n = toss();
	system("cls");
	int o = 0;
	if (str == strh)
	{
		if (n == 0)
		{
			cout << "YOU WON THE TOSS" << endl;
			o++;
		}
		else
		{
			cout << "YOU LOST THE TOSS" << endl;
		}
	}
	else
	{
		if (n == 1)
		{
			cout << "YOU WON THE TOSS" << endl;
			o++;
		}
		else
		{
			cout << "YOU LOST THE TOSS" << endl;
		}
	}
	char u;
	int target = 0;
	int half[11];
	int cen[11];
	if (o == 1)
	{
		char u;
		cout << "What do you want to choose batting or fielding." << endl;//CHOOSES BETWEEN BATTING OR FIELDING//
		cout << "For batting press b and for fielding press f:";
		cin >> u;
		if (u == 'b' || u == 'B')
		{
			up++;
		}
		else if (u == 'f' || u == 'F')
		{
			up = 0;
		}
		if (u != 'b' && u != 'B' && u != 'f' && u != 'F')
		{
			while (u != 'b' && u != 'B' && u != 'f' && u != 'F')
			{
				system("cls");
				cout << "Enter correct option:";
				cin >> u;
				system("cls");
			}
			if (u == 'b' || u == 'B')
			{
				up++;
			}
			else if (u == 'f' || u == 'F')
			{
				up = 0;
			}
		}
	}
	else//CHOOSES OPTISSTION CHOICE//
	{
		n = option();
		if (n == 1)
		{
			cout << "Opponent choose to Bat first." << endl;
			up = 0;
		}
		else
		{
			cout << "Opponent choose to Field first." << endl;
			up++;
		}
	}
	fstream obj;
	string temp;
	int limit;
	obj.open("Configuration.txt", ios::in);
	if (obj.is_open()) {
		getline(obj, temp, '=');
		getline(obj, temp, '\n');
	}
	obj.close();
	limit = stoi(temp);
	moveon();
	int yourteam[11][4];//ARRAY FOR YOUR TEAM BATTING//
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			yourteam[i][j] = 0;
		}
	}
	int yteamindex = 0;
	int facing = 0;
	int running = yteamindex + 1;
	int bowler[5][4];//ARRAY FOR OPPOSITION BOWLERS//
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			bowler[i][j] = 0;
		}
	}
	int teamscore[2][4];
	for (int i = 0; i < 2; i++)//ARRAY FOR YOUR SCORE//
	{
		for (int j = 0; j < 4; j++)
		{
			teamscore[i][j] = 0;
		}
	}
	char oppbal[5][30];
	int ballerindex = 6;
	for (int i = 0; i < 5; i++)//COPIES OPPOSITION BOWLERS NAME//
	{
		strcpy_s(oppbal[i], oppteam[ballerindex]);
		ballerindex++;
	}
	ballerindex = 4;
	int overrun = 0;
	int overwic = 0;
	int teams = 0;
	int over = 0;
	int playingindex = facing;
	int wickets = 0;
	int extra = 0;
	int batout = 1;
	int desicion = 1;
	int oppteamscore[2][4];
	int a;
	int count = 0;
	for (int i = 0; i < 11; i++)
	{
		half[i] = 0;
	}
	for (int i = 0; i < 11; i++)
	{
		cen[i] = 0;
	}
	for (int i = 0; i < 2; i++)//ARRAY FOR OPPOSITION TEAM SCORE//
	{
		for (int j = 0; j < 4; j++)
		{
			oppteamscore[i][j] = 0;
		}
	}
	if (up == 1)//IF YOU CHOOSE TO BAT//
	{
		int v = 0;
		cout << "Your two playing batsmen are." << endl;//PRESENTS YOUR PLAYING BATSMEN//
		for (int i = 0; i < 2; i++)
		{
			cout << yteam[i] << endl;
		}
		cout << "\n" << endl;
		cout << "OPPOSITION BOWLERS ARE." << endl;//PRESENTS OPPOSITION BOWLERS//
		for (int i = 0; i < 5; i++)
		{
			cout << oppbal[i] << endl;
		}
		moveon();
		cout << "Press Enter to play." << endl;
		while (over < limit)//LIMITS THE NUMBER OF OVERS//
		{
			v = 0;
			if (wickets == 10)
			{
				desicion = 0;
				break;
			}
			overrun = 0;
			overwic = 0;
			for (int i = 0; i < 6; i++)//LIMITS NUMBER OF BALLS//
			{
				a = _getch();
				system("cls");
				if (a != 13)
				{
					while (a != 13)
					{
						system("cls");
						cout << "Enter the correct input:" << endl;
						a = _getch();
						system("cls");
					}
				}
				if (playingindex >= 6)
				{
					n = wicket7();
				}
				else
				{
					n = wicket0();
				}
				if (n == -1)//FOR WIDE BALL//
				{
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					count = 0;
					cout << "\t\tWIDE-BALL" << endl;
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					extrarun(extra, overrun, n, teamscore, bowler, ballerindex, i);
					targetl(target, teamscore, oppteamscore, o, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
				}
				else if (n == -2)//FOR OUT//
				{
					count++;
					if (count == 3)
					{
						cout << oppteam[ballerindex + 6] << " GETS HAT-TRICK" << endl;
					}
					out(i, overwic, wickets, teamscore, bowler, ballerindex);
					if (bowler[ballerindex][3] == 5)
					{
						cout << oppteam[ballerindex + 6] << " GETS FIFER" << endl;
					}
					if (playingindex == facing)
					{
						yourteam[playingindex][1] += 1;
						cout << "\t" << yteam[playingindex] << ": " << yourteam[playingindex][0] << "/" << yourteam[playingindex][1] << endl;

						cout << "\n";
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						facing = playingindex;
						cout << "NEW-BATSMEN:    " << "(" << yteam[playingindex] << ")" << endl;
					}
					else if (playingindex == running)
					{
						yourteam[playingindex][1] += 1;
						cout << "\t" << yteam[playingindex] << ": " << yourteam[playingindex][0] << "/" << yourteam[playingindex][1] << endl;
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						running = playingindex;
						cout << "NEW-BATSMEN:    " << "(" << yteam[playingindex] << ")" << endl;
						cout << "\n";
					}
					moveon();
					targetl(target, teamscore, oppteamscore, o, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
				}
				else if (n == -3)//FOR NO BALL//
				{
					count = 0;
					cout << "\t\tNO-BALL" << endl;
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					extrarun(extra, overrun, n, teamscore, bowler, ballerindex, i);
					targetl(target, teamscore, oppteamscore, o, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
				}
				else//FOR NORMAL SCORE//
				{
					count = 0;
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					run(overrun, n, teamscore, bowler, i, ballerindex);
					targetl(target, teamscore, oppteamscore, o, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
				}
			}
			if (wickets < 10)
			{
				teamscore[1][2] += 1;
				crossing(playingindex, facing, running);
				bowler[ballerindex][0] += 1;
			}
			over++;
			cout << "OVER FINISHED. OVER SUMMARY \t";
			cout << overrun << "/" << overwic << endl;
			moveon();
			int pre = ballerindex;
			ballerindex = baller1(pre);
			while (ballerindex == pre || bowler[ballerindex][0] >= limit / 2)
			{
				ballerindex = baller1(pre);
			}
			if (over == limit / 2 || wickets == 10 || over == limit)
			{
				if (over == limit / 2 && desicion == 1)//PRSENTS INNING BREAK//
				{
					cout << "INNING BREAK" << endl;
				}
				if (wickets == 10 || desicion == 0 || over == limit)//PRESENTS INNING SUMMARY//
				{
					cout << "INNING SUMMARY" << endl;
				}
				cout << endl;
				int i = 0;
				targetl(target, teamscore, oppteamscore, o, i, wickets, v, limit);
				overallbatinn(yteam, yourteam);
				cout << "EXTRA (" << extra << ")" << endl;
				cout << endl;
				moveon();
				system("cls");
				overallballinn(bowler, oppbal);
				cout << endl;
				moveon();
			}
		}
		desicion = 1;
		target = teamscore[1][0];
		target++;
		cout << "YOU SET THE TARGET :" << target << endl;
		cout << endl;
		cout << "OPPOSITION WILL BAT NOW" << endl;
		moveon();
		char ybow[5][30];
		ballerindex = 6;
		for (int i = 0; i < 5; i++)//COPIES YOUR BOWLERS INTO AN ARRAY//
		{
			strcpy_s(ybow[i], yteam[ballerindex]);
			ballerindex++;
		}
		count = 0;
		ballerindex = 4;
		facing = 0;
		running = 1;
		batout = 1;
		playingindex = facing;
		int oppteambat[11][4];
		for (int i = 0; i < 11; i++)//SETS OPPOSITION BATSMEN ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				oppteambat[i][j] = 0;
			}
		}
		int yourbowl[5][4];
		for (int i = 0; i < 5; i++)//SETS YOUR BOWLERS ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				yourbowl[i][j] = 0;
			}
		}
		overrun = 0;
		wickets = 0;
		overwic = 0;
		extra = 0;
		over = 0;
		v = 1;
		for (int i = 0; i < 11; i++)//FOR HALF CENTURY//
		{
			half[i] = 0;
		}
		for (int i = 0; i < 11; i++)//FOR CENTURY//
		{
			cen[i] = 0;
		}
		cout << "Opposition two playing batsmen are." << endl;//PRESENTS OPPOSITION BATSMEN//
		for (int i = 0; i < 2; i++)
		{
			cout << oppteam[i] << endl;
		}
		cout << "\n" << endl;
		cout << "YOUR BOWLERS ARE." << endl;//PRESENTS YOUR BOWLERS//
		for (int i = 0; i < 5; i++)
		{
			cout << ybow[i] << endl;
		}
		moveon();
		cout << "Press Enter to play." << endl;
		while (over < limit)//LIMITS OVERS//
		{
			if (oppteamscore[1][0] >= target)
			{
				desicion = 0;
				break;
			}
			if (wickets == 10)
			{
				desicion = 0;
				break;
			}
			overrun = 0;
			overwic = 0;
			for (int i = 0; i < 6; i++)//LIMITS BALLS//
			{
				a = _getch();
				system("cls");
				if (a != 13)
				{
					while (a != 13)
					{
						system("cls");
						cout << "Enter the correct input:" << endl;
						a = _getch();
						system("cls");
					}
				}
				if (playingindex >= 6)
				{
					n = wicket7();
				}
				else
				{
					n = wicket0();
				}
				if (n == -1)//FORWIDE BALL//
				{
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					count = 0;
					cout << "\t\tWIDE-BALL" << endl;
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					extrarun(extra, overrun, n, oppteamscore, yourbowl, ballerindex, i);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
					if (oppteamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
				else if (n == -2)//FOR OUT//
				{
					count++;
					if (count == 3)
					{
						cout << yteam[ballerindex + 6] << " GETS HAT-TRICK" << endl;
					}
					out(i, overwic, wickets, oppteamscore, yourbowl, ballerindex);
					if (yourbowl[ballerindex][3] == 5)
					{
						cout << yteam[ballerindex + 6] << " GETS FIFER" << endl;
					}
					if (playingindex == facing)
					{
						oppteambat[playingindex][1] += 1;
						cout << "\t" << oppteam[playingindex] << ": " << oppteambat[playingindex][0] << "/" << oppteambat[playingindex][1] << endl;
						cout << "\n";
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						facing = playingindex;
						cout << "NEW-BATSMEN:    " << "(" << oppteam[playingindex] << ")" << endl;
					}
					else if (playingindex == running)
					{
						oppteambat[playingindex][1] += 1;
						cout << "\t" << oppteam[playingindex] << ": " << oppteambat[playingindex][0] << "/" << oppteambat[playingindex][1] << endl;
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						running = playingindex;
						cout << "NEW-BATSMEN:    (" << oppteam[playingindex] << ")" << endl;
						cout << "\n";
					}
					moveon();
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
				}
				else if (n == -3)//FOR NO-BALL//
				{
					count = 0;
					cout << "\t\tNO-BALL" << endl;
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					extrarun(extra, overrun, n, oppteamscore, yourbowl, ballerindex, i);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
					if (oppteamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
				else//FOR NORMAL SCORE//
				{
					count = 0;
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					run(overrun, n, oppteamscore, yourbowl, i, ballerindex);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
					if (oppteamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
			}
			if (wickets < 10)
			{
				oppteamscore[1][2] += 1;
				crossing(playingindex, facing, running);
				yourbowl[ballerindex][0] += 1;
			}
			over++;
			cout << "OVER FINISHED. OVER SUMMARY \t";
			cout << overrun << "/" << overwic << endl;
			moveon();
			if (wickets < 10 && over < limit && desicion == 1)//CHOOSES YOUR OWN BOWLER//
			{
				ballerindex = balleroption(ballerindex, yourbowl, ybow, limit);
				moveon();
			}
			if (over == (limit / 2) && wickets != 10)
			{
				cout << "INNING BREAK" << endl;//INING BREAK//
				int i = 0;
				targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
				cout << endl;
				overallbatinn(oppteam, oppteambat);
				cout << "EXTRA (" << extra << ")" << endl;
				cout << endl;
				moveon();
				overallballinn(yourbowl, ybow);
				cout << endl;
				moveon();
			}
			moveon();
			if (wickets == 10 || oppteamscore[1][0] <= target || oppteamscore[1][0] >= target || over == limit)
			{
				if (oppteamscore[1][0] < target && over == limit || wickets == 10)//IF YOU WON//
				{
					cout << "YOU WON" << endl;
					int v = margin(target, oppteamscore);
					cout << "\nBY " << v << " RUNS" << endl;
					cout << "WITH  " << 20 - over << " OVERS LEFT." << endl;
					cout << "\nDO YOU WANT TO SAVE THE GAME" << endl;
					cout << "PRESS S TO SAVE AND P TO JUST SHOW RESULT ON SCREEN." << endl;//OPTION TO SAVE IN FILE OR NOT//
					u = _getch();
					while (u != 'p' && u != 'P' && u != 's' && u != 'S')
					{
						u = _getch();
					}
					moveon();
					if (u == 's' || u == 'S')
					{
						ofstream gamefile;
						overallbat(gamefile, oppteam, oppteambat);
						cout << "EXTRA (" << extra << ")" << endl;
						cout << endl;
						moveon();
						overallball(gamefile, yourbowl, ybow);
						cout << endl;
						moveon();
						cout << endl;
						overallbat(gamefile, yteam, yourteam);
						cout << endl;
						moveon();
						overallball(gamefile, bowler, oppbal);
						cout << endl;
						moveon();
						gamefile.open("gamesave.txt", ios::app);
						gamefile << "YOU WON" << endl;
						gamefile << "BY " << v << " RUNS" << endl;
						gamefile << "WITH  " << 20 - over << " OVERS LEFT." << endl;
						gamefile << "MATCH SUMMARY" << endl;
						gamefile.close();
					}
					if (u == 'p' || u == 'P')
					{
						cout << endl;
						int i = 0;
						targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
						cout << endl;
						overallbatinn(oppteam, oppteambat);
						cout << "EXTRA (" << extra << ")" << endl;
						cout << endl;
						moveon();
						overallballinn(yourbowl, ybow);
						cout << endl;
						moveon();
						overallbatinn(yteam, yourteam);
						cout << endl;
						moveon();
						overallballinn(bowler, oppbal);
						cout << endl;
						moveon();
						award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
					}
				}
				else if (oppteamscore[1][0] >= target)
				{
					ofstream gamefile;
					cout << "YOU LOST" << endl;//IF YOU LOST//
					int i = 0;
					cout << " BY " << 10 - wickets << " WICKETS" << endl;
					cout << "\nDO YOU WANT TO SAVE THE GAME" << endl;
					cout << "PRESS S TO SAVE AND P TO JUST SHOW RESULT ON SCREEN." << endl;//OPTION TO SAVE IN FILE OR NOT//
					u = _getch();
					while (u != 'p' && u != 'P' && u != 's' && u != 'S')
					{
						u = _getch();
					}
					moveon();
					if (u == 's' || u == 'S')
					{
						overallbat(gamefile, oppteam, oppteambat);
						cout << "EXTRA (" << extra << ")" << endl;
						cout << endl;
						moveon();
						overallball(gamefile, yourbowl, ybow);
						cout << endl;
						moveon();
						cout << endl;
						overallbat(gamefile, yteam, yourteam);
						cout << endl;
						moveon();
						overallball(gamefile, bowler, oppbal);
						cout << endl;
						moveon();
						award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
						moveon();
						gamefile.open("gamesave.txt", ios::app);
						gamefile << "YOU LOST" << endl;
						gamefile << " BY " << 10 - wickets << " WICKETS" << endl;
						gamefile << "MATCH SUMMARY" << endl;
						gamefile.close();
					}
					if (u == 'p' || u == 'P')
					{
						cout << "MATCH SUMMARY" << endl;
						int i = 0;
						targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
						cout << endl;
						overallbatinn(oppteam, oppteambat);
						cout << "EXTRA (" << extra << ")" << endl;
						cout << endl;
						moveon();
						overallballinn(yourbowl, ybow);
						cout << endl;
						moveon();
						overallbatinn(yteam, yourteam);
						cout << endl;
						moveon();
						overallballinn(bowler, oppbal);
						cout << endl;
						moveon();
						award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
						moveon();
					}
				}
			}
		}
		cout << "\n\n\n\nMATCH FINISHED" << endl;
	}
	count = 0;
	target = 0;
	desicion = 1;
	for (int i = 0; i < 11; i++)//FOR HALF CENTURY//
	{
		half[i] = 0;
	}
	for (int i = 0; i < 11; i++)//FOR CENTURY//
	{
		cen[i] = 0;
	}
	if (up == 0)//IF OTHER TEAM BAT FIRST//
	{
		int v = 0;
		char ybow[5][30];
		ballerindex = 6;
		for (int i = 0; i < 5; i++)//COPIES YOUR BOWLERS//
		{
			strcpy_s(ybow[i], yteam[ballerindex]);
			ballerindex++;
		}
		ballerindex = 4;
		facing = 0;
		running = 1;
		batout = 1;
		playingindex = facing;
		int oppteambat[11][4];
		for (int i = 0; i < 11; i++)//SETS OPPOSITION BATTING ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				oppteambat[i][j] = 0;
			}
		}
		int yourbowl[5][4];
		for (int i = 0; i < 5; i++)//SETS YOUR BOWLING ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				yourbowl[i][j] = 0;
			}
		}
		overrun = 0;
		wickets = 0;
		overwic = 0;
		extra = 0;
		over = 0;
		int teamscore[2][4];
		for (int i = 0; i < 2; i++)//SETS YOUR SCORE ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				teamscore[i][j] = 0;
			}
		}
		int oppteamscore[2][4];
		for (int i = 0; i < 2; i++)//SETS YOUR OPPOSITION SCORE ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				oppteamscore[i][j] = 0;
			}
		}
		cout << "Opposition two playing batsmen are." << endl;//PRESENTS OPPOSITION PLAYING BATSMEN//
		for (int i = 0; i < 2; i++)
		{
			cout << oppteam[i] << endl;
		}
		cout << "\n" << endl;
		cout << "YOUR BOWLERS ARE." << endl;//PRESENTS YOUR BOWLERS//
		for (int i = 0; i < 5; i++)
		{
			cout << ybow[i] << endl;
		}
		moveon();
		cout << "Press Enter to play." << endl;
		while (over < limit)//LIMITS OVERS//
		{
			if (wickets == 10)
			{
				desicion = 0;
				break;
			}
			overrun = 0;
			overwic = 0;
			for (int i = 0; i < 6; i++)//LIMITS BALLS//
			{
				a = _getch();
				system("cls");
				if (a != 13)
				{
					while (a != 13)
					{
						system("cls");
						cout << "Enter the correct input:" << endl;
						a = _getch();
						system("cls");
					}
				}
				if (playingindex >= 6)
				{
					n = wicket7();
				}
				else
				{
					n = wicket0();
				}
				if (n == -1)//FOR WIDE BALL//
				{
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					count = 0;
					cout << "\t\tWIDE-BALL" << endl;
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					extrarun(extra, overrun, n, oppteamscore, yourbowl, ballerindex, i);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
				}
				else if (n == -2)//FOR OUT//
				{
					count++;
					if (count == 3)
					{
						cout << yteam[ballerindex + 6] << " GETS HAT-TRICK" << endl;
					}
					out(i, overwic, wickets, oppteamscore, yourbowl, ballerindex);
					if (yourbowl[ballerindex][3] == 5)
					{
						cout << yteam[ballerindex + 6] << " GETS FIFER" << endl;
					}
					if (playingindex == facing)
					{
						oppteambat[playingindex][1] += 1;
						cout << "\t" << oppteam[playingindex] << ": " << oppteambat[playingindex][0] << "/" << oppteambat[playingindex][1] << endl;
						cout << "\n";
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						facing = playingindex;
						cout << "NEW-BATSMEN:    (" << oppteam[playingindex] << ")" << endl;
					}
					else if (playingindex == running)
					{
						oppteambat[playingindex][1] += 1;
						cout << "\t" << oppteam[playingindex] << ": " << oppteambat[playingindex][0] << "/" << oppteambat[playingindex][1] << endl;
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						running = playingindex;
						cout << "NEW-BATSMEN:    (" << oppteam[playingindex] << ")" << endl;
						cout << "\n";
					}
					moveon();
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
				}
				else if (n == -3)//FOR NO BALL//
				{
					count = 0;
					cout << "\t\tNO-BALL" << endl;
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					extrarun(extra, overrun, n, oppteamscore, yourbowl, ballerindex, i);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
				}
				else//FOR NORMAL SCORE//
				{
					count = 0;
					runningbt(n, playingindex, facing, running, oppteambat, oppteam, half, cen);
					run(overrun, n, oppteamscore, yourbowl, i, ballerindex);
					targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
					current(oppteam, oppteambat, facing, running, playingindex, ybow, ballerindex, yourbowl);
				}
			}
			if (wickets < 10)
			{
				crossing(playingindex, facing, running);
				oppteamscore[1][2] += 1;
				yourbowl[ballerindex][0] += 1;
			}
			over++;
			cout << "OVER FINISHED. OVER SUMMARY \t";
			cout << overrun << "/" << overwic << endl;
			moveon();
			if (wickets < 10 && over < 20 && desicion == 1)//YOUR BOWLING OPTION//
			{
				ballerindex = balleroption(ballerindex, yourbowl, ybow, limit);
				moveon();
			}
			if (over == limit / 2 || wickets == 10 || over == limit)
			{
				if (over == limit / 2 && desicion == 1)//INNING BREAK//
				{
					cout << "INNING BREAK" << endl;
				}
				if (wickets == 10 || over == limit)//INNING SUMMARY//
				{
					cout << "INNING SUMMARY" << endl;
				}
				cout << endl;
				int i = 0;
				targetl(target, oppteamscore, teamscore, over, i, wickets, v, limit);
				overallbatinn(oppteam, oppteambat);
				cout << "EXTRA (" << extra << ")" << endl;
				cout << endl;
				moveon();
				system("cls");
				overallballinn(yourbowl, ybow);
				cout << endl;
				moveon();
			}
		}
		target = oppteamscore[1][0];
		target++;
		cout << "OPPOSITION SET THE TARGET :" << target << endl;//SETS TARGET//
		cout << endl;
		moveon();
		int yourteam[11][4];
		for (int i = 0; i < 11; i++)//SETS YOUR BATTING ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				yourteam[i][j] = 0;
			}
		}
		count = 0;
		desicion = 1;
		int yteamindex = 0;
		int facing = 0;
		int running = yteamindex + 1;
		int bowler[5][4];
		for (int i = 0; i < 5; i++)//SETS OPPOSITION BOWLING ARRAY//
		{
			for (int j = 0; j < 4; j++)
			{
				bowler[i][j] = 0;
			}
		}
		char oppbal[5][30];
		int ballerindex = 6;
		for (int i = 0; i < 5; i++)//COPIES OPPOSITION BOWLERS NAME//
		{
			strcpy_s(oppbal[i], oppteam[ballerindex]);
			ballerindex++;
		}
		ballerindex = 4;
		int overrun = 0;
		int overwic = 0;
		int teams = 0;
		up = 0;
		int over = 0;
		int playingindex = facing;
		int wickets = 0;
		int extra = 0;
		int batout = 1;
		for (int i = 0; i < 11; i++)//SETS HALF CENTURY//
		{
			half[i] = 0;
		}
		for (int i = 0; i < 11; i++)//SETS CENTURY//
		{
			cen[i] = 0;
		}
		cout << "Your two playing batsmen are." << endl;//PRSENTS YOUR PLAYING BATSMEN//
		for (int i = 0; i < 2; i++)
		{
			cout << yteam[i] << endl;
		}
		cout << "\n" << endl;
		cout << "OPPOSITION BOWLERS ARE." << endl;//PRESENTS OPPOSITION BOWLERS//
		for (int i = 0; i < 5; i++)
		{
			cout << oppbal[i] << endl;
		}
		moveon();
		cout << "Press Enter to play." << endl;
		while (over < limit)//LIMITS OVERS//
		{
			v = 1;
			if (teamscore[1][0] >= target)
			{
				desicion = 0;
				break;
			}
			if (wickets == 10)
			{
				desicion = 0;
				break;
			}
			overrun = 0;
			overwic = 0;
			for (int i = 0; i < 6; i++)//LIMITS BALLS//
			{
				a = _getch();
				system("cls");
				if (a != 13)
				{
					while (a != 13)
					{
						system("cls");
						cout << "Enter the correct input:" << endl;
						a = _getch();
						system("cls");
					}
				}
				if (playingindex >= 6)
				{
					n = wicket7();
				}
				else
				{
					n = wicket0();
				}
				if (n == -1)//FOR WIDE//
				{
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					count = 0;
					cout << "\t\tWIDE-BALL" << endl;
					overrun += 1;
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					extrarun(extra, overrun, n, teamscore, bowler, ballerindex, i);
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
					if (teamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
				else if (n == -2)//FOR OUT//
				{
					count++;
					if (count == 3)
					{
						cout << oppteam[ballerindex + 6] << " GETS HAT-TRICK" << endl;
					}
					out(i, overwic, wickets, teamscore, bowler, ballerindex);
					if (bowler[ballerindex][3] == 5)
					{
						cout << oppteam[ballerindex + 6] << " GETS FIFER" << endl;
					}
					if (playingindex == facing)
					{
						yourteam[playingindex][1] = yourteam[playingindex][1] + 1;
						cout << "\t" << yteam[playingindex] << ": " << yourteam[playingindex][0] << "/" << yourteam[playingindex][1] << endl;
						cout << "\n";
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						facing = playingindex;
						cout << "NEW-BATSMEN:    (" << yteam[playingindex] << ")" << endl;
					}
					else if (playingindex == running)
					{
						yourteam[playingindex][1] = yourteam[playingindex][1] + 1;
						cout << "\t" << yteam[playingindex] << ": " << yourteam[playingindex][0] << "/" << yourteam[playingindex][1] << endl;
						batout += 1;
						if (wickets == 10)
						{
							desicion = 0;
							break;
						}
						playingindex = batout;
						running = playingindex;
						cout << "NEW-BATSMEN:    (" << yteam[playingindex] << ")" << endl;
						cout << "\n";
					}
					moveon();
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
				}
				else if (n == -3)//FOR NO BALL//
				{
					count = 0;
					cout << "\t\tNO-BALL" << endl;
					while (n == -1 || n == -3 || n == -2)
					{
						if (playingindex >= 6)
						{
							n = wicket7();
						}
						else
						{
							n = wicket0();
						}
					}
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					extrarun(extra, overrun, n, oppteamscore, yourbowl, ballerindex, i);
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
					if (teamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
				else//FOR NORMAL SCORE//
				{
					count = 0;
					runningbt(n, playingindex, facing, running, yourteam, yteam, half, cen);
					run(overrun, n, teamscore, bowler, i, ballerindex);
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					current(yteam, yourteam, facing, running, playingindex, oppbal, ballerindex, bowler);
					if (teamscore[1][0] >= target)
					{
						desicion = 0;
						break;
					}
				}
			}
			if (wickets < 10)
			{
				crossing(playingindex, facing, running);
				bowler[ballerindex][0] += 1;
				teamscore[1][2] += 1;
			}
			over++;
			cout << "OVER FINISHED. OVER SUMMARY \t";
			cout << overrun << "/" << overwic << endl;
			moveon();
			int pre = ballerindex;
			ballerindex = baller1(pre);
			while (ballerindex == pre || bowler[ballerindex][0] >= limit / 5)
			{
				ballerindex = baller1(pre);
			}
			if (over == (limit / 2) && wickets != 10)//INNING SUMMARY//
			{
				cout << "INNING BREAK" << endl;
				int i = 0;
				targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
				cout << endl;
				overallbatinn(yteam, yourteam);
				cout << "EXTRA (" << extra << ")" << endl;
				cout << endl;
				moveon();
				overallballinn(bowler, oppbal);
				cout << endl;
				moveon();
			}
		}
		if (wickets == 10 || teamscore[1][0] <= target || teamscore[1][0] >= target)
		{
			if (teamscore[1][0] < target && over == limit || wickets == 10)//IF YOU LOST//
			{
				cout << "YOU LOST" << endl;
				cout << " BY " << 20 - over << " OVERS LEFT" << endl;
				cout << " BY " << 10 - wickets << " WICKETS" << endl;
				cout << " BY " << target - teamscore[1][0] << " RUNS" << endl;
				cout << "\nDO YOU WANT TO SAVE THE GAME" << endl;
				cout << "PRESS S TO SAVE AND P TO JUST SHOW RESULT ON SCREEN." << endl;//GIVES YOU OPTION TO SAVE FILE OR NOT//
				u = _getch();
				while (u != 'p' && u != 'P' && u != 's' && u != 'S')
				{
					u = _getch();
				}
				moveon();
				if (u == 's' || u == 'S')
				{
					ofstream gamefile;
					overallbat(gamefile, yteam, yourteam);
					cout << "EXTRA (" << extra << ")" << endl;
					cout << endl;
					moveon();
					overallball(gamefile, bowler, oppbal);
					cout << endl;
					moveon();
					cout << endl;
					overallbat(gamefile, oppteam, oppteambat);
					cout << endl;
					moveon();
					overallball(gamefile, yourbowl, ybow);
					cout << endl;
					moveon();
					award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
					gamefile.open("gamesave.txt", ios::app);
					gamefile << "YOU LOST" << endl;
					gamefile << "MATCH SUMMARY" << endl;
					gamefile << " BY " << 20 - over << " OVERS LEFT" << endl;
					gamefile << " BY " << 10 - wickets << "WICKETS" << endl;
					gamefile << " BY " << target - teamscore[1][0] << " RUNS" << endl;
					gamefile.close();
				}
				else if (u == 'p' || u == 'P')
				{
					int i = 0;
					cout << "MATCH SUMMARY" << endl;
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					cout << endl;
					overallbatinn(yteam, yourteam);
					cout << "EXTRA (" << extra << ")" << endl;
					cout << endl;
					moveon();
					overallballinn(bowler, oppbal);
					cout << endl;
					moveon();
					overallbatinn(oppteam, oppteambat);
					cout << endl;
					moveon();
					overallballinn(yourbowl, ybow);
					cout << endl;
					moveon();
					award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
				}
			}
			else if (teamscore[1][0] >= target)//IF YOU WON//
			{
				cout << "YOU WON" << endl;
				cout << " BY " << 10 - wickets << " WICKETS" << endl;
				cout << "\nDO YOU WANT TO SAVE THE GAME" << endl;
				cout << "PRESS S TO SAVE AND P TO JUST SHOW RESULT ON SCREEN." << endl;//GIVES YOU OPTION TO SAVE FILE OR NOT//
				u = _getch();
				while (u != 'p' && u != 'P' && u != 's' && u != 'S')
				{
					u = _getch();
				}
				moveon();
				if (u == 's' || u == 'S')
				{
					ofstream gamefile;
					overallbat(gamefile, yteam, yourteam);
					cout << "EXTRA (" << extra << ")" << endl;
					cout << endl;
					moveon();
					overallball(gamefile, bowler, oppbal);
					cout << endl;
					moveon();
					cout << endl;
					overallbat(gamefile, oppteam, oppteambat);
					cout << endl;
					moveon();
					overallball(gamefile, yourbowl, ybow);
					cout << endl;
					moveon();
					award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
					gamefile.open("gamesave.txt", ios::app);
					gamefile << "YOU WON" << endl;
					gamefile << "MATCH SUMMARY" << endl;
					gamefile << " BY " << 10 - wickets << " WICKETS" << endl;
					gamefile.close();
				}
				if (u == 'p' || u == 'P')
				{
					int i = 0;
					cout << "MATCH SUMMARY" << endl;
					targetl(target, teamscore, oppteamscore, over, i, wickets, v, limit);
					cout << endl;
					overallbatinn(yteam, yourteam);
					cout << "EXTRA (" << extra << ")" << endl;
					cout << endl;
					moveon();
					overallballinn(bowler, oppbal);
					cout << endl;
					moveon();
					overallbatinn(oppteam, oppteambat);
					cout << endl;
					moveon();
					overallballinn(yourbowl, ybow);
					cout << endl;
					moveon();
					award(yourbowl, bowler, yteam, oppteam, yourteam, oppteambat);
				}
			}
		}
		cout << "\n\n\n\nMATCH FINISHED" << endl;// MATCH FINISHED//
	}
	return 0;
}
