#include<iostream>
#include<conio.h >
#include<string.h>
#include<stdlib.h>
using namespace std;
const int maxlength=80;
const int maxtries=5;
const int maxrow=7;
int letterfill(char,char[],char[]);
void initunknown(char [],char[]);
int main()
{
	int n;
	char unknown[maxlength];
	char letter;
	int wrong=0;
	char word[maxlength];
	char words[][maxlength]={"india","pakistan","nepal","malaysia","philippines","australia","iran","ethiopia","oman","indonesia"};
	 n=rand()%10;
	strcpy(word,words[n]);
	initunknown(word,unknown);
	cout<<"welcome to the guessing world"<<endl;
	cout<<"each letter is represented by a star"<<endl;
	cout<<"you have to type only one letter in one try"<<endl;
	cout<<"you have "<<maxtries<<" tries to try and guess the word"<<endl;
	while(wrong<maxtries)
	{
		cout<<endl<<unknown<<endl;
		cout<<"guess a letter"<<endl;
		cin>>letter;
		if(letterfill(letter,word,unknown)==0)
		{
			cout<<endl<<" its a wrong guess"<<endl;
			wrong++;
		}
		else
		{
			cout<<endl<<"amazing u made an correct choice"<<endl;
		}
		cout<<"you have "<<maxtries-wrong;
		cout<<"guesses left"<<endl;
		if(strcmp(word,unknown)==0)
		{
			cout<<word<<endl;
			cout<<"yeah you got it"<<endl;
			break;
		}
	}
	if(wrong==maxtries)
	{
		cout<<"sorrt you have exceeded your limit"<<endl;
		cout<<"the word was "<<word<<endl;
	}
	getch();
	return 0;
}
int letterfill(char guess,char secretword[],char guessword[])
{
	int i;
	int matches=0;
	for(i=0;secretword[i]!='\0';i++)
	{
		if(guess==guessword[i])
		{
			return 0;
		}
		if(guess==secretword[i])
		{
			guessword[i]=guess;
			matches++;
		}
	}
	return matches;
}
void initunknown(char word[],char unknown[])
{
	int i;
	int length=strlen(word);
	for(i=0;i<length;i++)
	{
		unknown[i]='*';
	}
	unknown[i]='\0';
}
   
