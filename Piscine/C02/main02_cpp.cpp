/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main02_cpp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:37:20 by haeem             #+#    #+#             */
/*   Updated: 2022/08/31 19:31:57 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
/*
#include "./ex00/ft_strcpy.c"
#include "./ex01/ft_strncpy.c"
#include "./ex02/ft_str_is_alpha.c"
#include "./ex03/ft_str_is_numeric.c"
#include "./ex04/ft_str_is_lowercase.c"
#include "./ex05/ft_str_is_uppercase.c"
#include "./ex06/ft_str_is_printable.c"
#include "./ex07/ft_strupcase.c"
#include "./ex08/ft_strlowcase.c"
*/
#include "./ex09/ft_strcapitalize.c"
/*
#include "./ex10/ft_strlcpy.c"
#include "./ex11/ft_putstr_non_printable.c"
#include "./ex12/ft_print_memory.c"
*/

#define fl fflush(stdout)
using namespace std;
int main(void)
{	
	/*
	// strcpy와 같은 기능을 합니다만 '버퍼 오버플로우' 공격에 취약해 strlcpy를 사용한답니다.
	cout<<"°º¤ø,,ø¤º°`°º¤ø, ex 00 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	char cat[60] = "나도 고양이 키우고 싶다 나만 고양이 없어";
	char a[60];
	ft_strcpy(a, cat);
	cout<<"──────────answer──────────"<<endl;
	cout << "'나도 고양이 키우고 싶다 나만 고양이 없어'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", a);;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	
	// strncpy와 같은 기능을 합니다만 '버퍼 오버플로우' 공격에 취약해 strlcpy를 사용한답니다.
	char b[60] = {"급침환 외않돼는지 몰르갰어요...."};
	char c[60];
	char d[60] = {"do you know kimchi?"};
	char e[60];
	ft_strncpy(c,b,45);
	ft_strncpy(e,d,15);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 01 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'급침환 외않돼는지 몰르갰어요....'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", c);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;

	cout<<"──────────answer──────────"<<endl;
	cout << "'do you know kim'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", e);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;


	// ASCII 코드에 대해 알아봅시다!
	char f[10] = {"holy moly"};
	char g[10] = {"abc"};
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 02 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", ft_str_is_alpha(f));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", ft_str_is_alpha(g));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;

	// ASCII 코드에 대해 알아봅시다2!
	char h[10] = {"123"};
	char ii[10] = {"haehehe"};
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 03 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", ft_str_is_numeric(h));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", ft_str_is_numeric(ii));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;


	char aa[10]={"Aaa"};
	char bb[10]={"aaa"};
	char cc[10]={"AAA"};

	// ASCII 코드에 대해 알아봅시다3!
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 04 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_lowercase(aa));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_lowercase(bb));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;



	// ASCII 코드에 대해 알아봅시다4!
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 05 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_uppercase(cc));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_uppercase(bb));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	

	// char 배열의 첫번째 문자로 각 아스키 번호의 문자를 넣어줍니다
	char canp1[10] = {32};
	char canp2[10] = {127};
	char canp3[10] = {33};
	char canp4[10] = {126};
	char canp5[10] = {27};
	char canp6[10] = {254};
	

	// 이왜틀??? 이 발생한다면 확장 아스키에 대해 알아봅시다 억까가 많은 문제입니다...
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 06 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp1));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp2));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp3));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"1'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp4));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp5));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";;cout<<"0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d",ft_str_is_printable(canp6));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;

	// 항상 출력에 유의합니다!!!!!!!
	char test1[40]={"Kimi No Toriko Ni Natte Shimaeba Kitto"};
	ft_strupcase(test1);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 07 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'KIMI NO TORIKO NI NATTE SHIMAEBA KITTO'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", test1);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	
	// 출력에 유의!!!!!!!
	char test2[40]={"Kono Natsu Wa Juujitsu Suru No Motto"};
	ft_strlowcase(test2);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 08 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'kono natsu wa juujitsu suru no motto'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", test2);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
*/


	// 정확한 구현이 필요한 문제입니다. 여러 테스트 케이스가 필요해서 넣어 놓았지만 시험 환경에 적응하려면 직접 만들어보는 게 좋아요
	char test3[] ={"null"};
	char test4[] ={"G}f,(As(%@@Zarvry-5`&_zvg@R9#>ea]U}erX"};
	char test5[] ={"umjuns1k, \'the ummaga junb1han s1ksa.\'"};
	ft_strcapitalize(test3);
	ft_strcapitalize(test4);
	ft_strcapitalize(test5);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 09 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "_sbP*ek_h]'Uk"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout <<  fl;printf("%s", test3);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "G}f,(As(%@@Zarvry-5`&_zvg@R9#>ea]U}erX"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << fl;printf("%s", test4);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'Umjuns1k, 'The Ummaga Junb1han S1ksa.''"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", test5);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
/*
	// 매뉴얼을 그대로 구현해야 합니다!
	char test6[67] = {"strlcpy는 strcpy의 보안 이슈를 방지하기 위해...읍읍"};
	char test7[67];
	unsigned int len = ft_strlcpy(test7, test6, 61);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 10 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'strlcpy는 strcpy의 보안 이슈를 방지하기 위해...'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s", test7);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'66'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", len);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;


	


	// 메모리 주소의 시작 지점은 상관 없어요!!! 풀다 보면 c에 대한 이해도가 깊어집니다 (...)
	char   s12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 12 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'00007ffee16ab3e0: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin\n00007ffee16ab3f0: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo\n00007ffee16ab400: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on \n00007ffee16ab410: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.\n00007ffee16ab420: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..\n00007ffee16ab430: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .\n'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;ft_print_memory((void *)s12, sizeof(s12));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n"<<endl;
*/
}


