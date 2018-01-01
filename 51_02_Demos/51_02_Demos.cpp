// 51_02_Demos.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <regex>
#include <string>
#include <assert.h>
#include <iostream>

int main()
{
	//����ƥ��
	//���ɺ���regex_match()�������һ���ַ����Ƿ�"��ȫƥ��"һ��������ʽ������bool�����
	{
		//ƥ�����֤����
		// ^\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d)$
		std::string regex_str("^(\\d{6})((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))$");
		std::regex pattern(regex_str, std::regex::icase);//������ĸ��Сд

		std::string id("61251719901212444X");
		assert(std::regex_match(id, pattern) == true);

		// [a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+  ���������
		std::string mail_reg_str("^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$");
		std::regex mail_reg(mail_reg_str, std::regex::icase);

		assert(std::regex_match("chm--1989@163.com", mail_reg) == true);
	}

	//ʹ������ƥ����
	//ʹ��match_results����ȡƥ������
	{
		//ʶ��һ��IP��ַ������ӡ��������
		//����exit�˳�����
		bool isInputEnd = false;
		//(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})
		//���ĸ��ӱ��ʽ�������е�����Ϊһ���ӱ��ʽ
		std::regex ip_reg("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
		std::smatch matchResult;
		const std::string exitStr("EXIT");
		while (!isInputEnd)
		{
			std::cout << "\nInput a IP address:";
			std::string inputStr;
			std::getline(std::cin, inputStr);
			if (inputStr.empty())
			{
				continue;
			}

			std::string tmpStr(inputStr);
			std::transform(tmpStr.begin(), tmpStr.end(), tmpStr.begin(), toupper);
			if (tmpStr == exitStr)
			{
				std::cout << "\nSYSTEM EXIT!";
				isInputEnd = true;
				continue;
			}
			//����ƥ��
			if (std::regex_match(inputStr, matchResult, ip_reg))
			{
				std::cout << "Match: ";
				//��ӡ�ӱ��ʽ���
				for (size_t i = 1; i < matchResult.size(); ++i)
				{
					std::cout << matchResult[i] << " "; //�����е���������һ������0�������е�ƥ��������1����ʼ�ǵ�һ������
				}
			}
			else
			{
				std::cout << "Not Match!";
			}

		}
	}

	//�������
	//regex_search() �� regex_match�������ǣ�regex_matchҪ��������ַ�������Ҫ��������ʽ��ȫƥ�䣬
	//��regex_search����������ʽ���Ƿ����������ʽ��������һ��ƥ��������ʽ���Ӵ���
	{
		//���������ַ�������������������ʽ \d{3} ���Ӵ�
		std::regex reg2("\\d{3}");
		std::string test_str("abc12312a--1b234-7890abc567");
		std::string::const_iterator iter = test_str.begin();
		std::string::const_iterator iterEnd = test_str.end();
		std::smatch match_result;
		std::cout << "\n\n" << test_str;
		while (std::regex_search(iter, iterEnd, match_result, reg2))
		{
			std::cout << "\nMatch: " << match_result[0];
			iter = match_result[0].second; //����������ʼλ��
		}
	}

	//�����滻
	//regex_replace �������ַ������в���������ʽe������ƥ�䡣����㷨ÿ�γɹ�ƥ��󣬾͸��ݲ���fmt��ƥ���ַ������и�ʽ����
	{
		//ʹ��regex_replace ʵ��trim���ܣ�ȥ���ַ���ǰ��Ŀհ��ַ�
		std::regex reg1("^(\\s)*");
		std::regex reg2("\\s*$");

		std::string test_str("  abc  \t");
		std::string t("");
		test_str = std::regex_replace(test_str, reg1, t); //trim_left
		test_str = std::regex_replace(test_str, reg2, t); //trim_right
	}

    return 0;
}

