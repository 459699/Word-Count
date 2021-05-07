// Word Count.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int i, count = 1;
    FILE* file;    //文件指针


    if (argc != 3) {
        printf("请使用格式: %s 文件名", argv[0]);
        exit(1);
    }

    //没有相匹配的文件
    if ((file = fopen(argv[2], "r")) == NULL) {
        printf("打开文件 %s 失败", argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0) {
        count = 0;
        //循环读取文件所有内容
        while ((i = getc(file)) != EOF) {
            count++;
        }
        printf("字符总数：%d个\n", count);
    }
    else {
        while ((i = getc(file)) != EOF) {
            if ((i == ' ') || (i == ','))
                count++;
        }
        printf("单词总数：%d个\n", count);
    }
    fclose(file);
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件