#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPi.h>

const int Dpin0 = 0;
const int Dpin1 = 1;
const int Dpin2 = 2;
const int Dpin3 = 3;
const int Dpin4 = 4;
const int Dpin5 = 5;
const int Dpin6 = 6;
const int Dpin7 = 7;
const int Dpin20 = 20;
const int Dpin21 = 21;
const int Dpin22 = 22;
const int Dpin23 = 23;
const int Dpin24 = 24;
const int Dpin25 = 25;
const int Dpin26 = 26;
const int Dpin27 = 27;

void off()
{
    pinMode(Dpin0,OUTPUT);
    pinMode(Dpin1,OUTPUT);
    pinMode(Dpin2,OUTPUT);
    pinMode(Dpin3,OUTPUT);
    pinMode(Dpin4,OUTPUT);
    pinMode(Dpin5,OUTPUT);
    pinMode(Dpin6,OUTPUT);
    pinMode(Dpin7,OUTPUT);
    pinMode(Dpin20,OUTPUT);
    pinMode(Dpin21,OUTPUT);
    pinMode(Dpin22,OUTPUT);
    pinMode(Dpin23,OUTPUT);
    pinMode(Dpin24,OUTPUT);
    pinMode(Dpin25,OUTPUT);
    pinMode(Dpin26,OUTPUT);
    pinMode(Dpin27,OUTPUT);
    digitalWrite(Dpin0,LOW);
    digitalWrite(Dpin1,LOW);
    digitalWrite(Dpin2,LOW);
    digitalWrite(Dpin3,LOW);
    digitalWrite(Dpin4,LOW);
    digitalWrite(Dpin5,LOW);
    digitalWrite(Dpin6,LOW);
    digitalWrite(Dpin7,LOW);
    digitalWrite(Dpin20,LOW);
    digitalWrite(Dpin21,LOW);
    digitalWrite(Dpin22,LOW);
    digitalWrite(Dpin23,LOW);
    digitalWrite(Dpin24,LOW);
    digitalWrite(Dpin25,LOW);
    digitalWrite(Dpin26,LOW);
    digitalWrite(Dpin27,LOW);
}

void main()
{
    FILE *fp = popen("ps -e | grep \'java\' | awk \'{print $1}\'", "r");//打开管道，执行shell 命令
    char buffer[10] = {0};
    while (NULL != fgets(buffer, 10, fp)) //逐行读取执行结果并打印
    {
        printf("PID:  %s", buffer);
	char *firstName = "sudo kill\t";
        char *lastName = buffer;
        char *name = (char *) malloc(strlen(firstName) + strlen(lastName));
        sprintf(name, "%s%s", firstName, lastName);
	printf(name);
	system(name);
    }
    pclose(fp); //关闭返回的文件指针，注意不是用fclose噢

    off();
    //getchar();
}