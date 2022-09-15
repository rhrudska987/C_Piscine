/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main03_cpp.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeem <haeem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:37:20 by haeem             #+#    #+#             */
/*   Updated: 2022/09/02 19:23:49 by kyko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits.h>
/*
#include "./ex00/ft_strcmp.c"
*/
#include "./ex01/ft_strncmp.c"
/*
#include "./ex02/ft_strcat.c"
#include "./ex03/ft_strncat.c"
#include "./ex04/ft_strstr.c"
#include "./ex05/ft_strlcat.c"
*/
#define fl fflush(stdout)
using namespace std;
int main(void)
{	


	// man strcmp와 똑같이 구현해주시면 됩니다. 보안 상 허점이 존재합니다!
//	char a[10] = "abcd";
	char b[10] = "abcd";
	char c[10] = "ab0d";
	char	our_1[10] = {'H', 'E', 'L', 'L', 'O'};
	char	our_2[10] = {'H', 'E', 'L', 200, 'O'};
/*	
	cout<<"°º¤ø,,ø¤º°`°º¤ø, ex 00 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout<<ft_strcmp(a,b);;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strcmp(c,b)<0)cout<<"-";else if(ft_strcmp(c,b)>0)cout<<"+";else cout<<"0";;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'+'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strcmp(b,c)<0)cout<<"-";else if(ft_strcmp(b,c)>0)cout<<"+";else cout<<"0";;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strcmp(our_1, our_2)<0)cout<<"-";else if(ft_strcmp(our_1, our_2)>0)cout<<"+";else cout<<"0";cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
*/	

	// mans strncmp, return 값을 유의합시다! 보안 상 허점이 존재합니다!
	char d[10] = "abcdefg";
	char e[10] = "abcDefg";
	char f[10] = "abcdefg";
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 01 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << ft_strncmp(d,e,3);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'0'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << ft_strncmp(d,e,0);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'+'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strncmp(b,c,4)<0)cout<<"-";else if(ft_strncmp(b,c,4)>0)cout<<"+";else cout<<"0";;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strncmp(our_1,our_2,10)<0)cout<<"-";else if(ft_strncmp(our_1,our_2,10)>0)cout<<"+";else cout<<"0";;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'-'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;if(ft_strncmp(e,f,4)<0)cout<<"-";else if(ft_strncmp(e,f,4)>0)cout<<"+";else cout<<"0";;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;


/*
	// 역시 safe하지 않은 함수라 사용 시 주의가 필요합니다
	char hello[100] = "Oh my god! they killed Kenny!";
	char world[33] = {" You bastards!"};
	ft_strcat(hello, world);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 02 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'Oh my god! they killed Kenny! You bastards!'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << hello;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;



	// 휘청거리고 있다면 출력을 다시 확인!
	char foo[50] = {"왜 그러지?"};
	char bar[] = {" 휘청거리고 있지 않나?!!!!"};
	char foo1[50] = {"왜 그러지?"};
	char bar1[] = {" 휘청거리고 있지 않나?!!!!"};
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 03 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'"<< strncat(foo,bar,32)<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << ft_strncat(foo1,bar1,32);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	

	// man strstr 참조, return 값에 유의합시다 
	char adc[] = "do baron";
	char jng[] = "baron";
	char adc2[] = "do dragon";
	char jng2[] = "baron";
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 04 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;	cout<<"──────────answer──────────"<<endl;
	cout << "'";printf("%p", strstr(adc,jng));cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%p",ft_strstr(adc, jng));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";printf("%p", strstr(adc2,jng2));cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%p",ft_strstr(adc2, jng2));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";printf("%s", strstr(adc,jng));cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s",ft_strstr(adc, jng));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'";printf("%s", strstr(adc2,jng2));cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%s",ft_strstr(adc2, jng2));cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;





	// man strlcat 참조, 마지막에 널 값이 '반드시' 들어가 있어야 합니다!
	char add[75] = "strlcat이strcat인이세계에선null값이들어가면안되는걸까?!";
	char aff[14] = " 안돼요!!!";
	char add2[75] = "strlcat이strcat인이세계에선null값이들어가면안되는걸까?!";
	char aff2[14] = " 안돼요!!!";
	char add3[75] = "strlcat이strcat인이세계에선null값이들어가면안되는걸까?!";
	char aff3[14] = " 안돼요!!!";
	char add4[75] = "strlcat이strcat인이세계에선null값이들어가면안되는걸까?!";
	char aff4[14] = " 안돼요!!!";

	unsigned int length = strlcat(add,aff,120);
	unsigned int length2 = ft_strlcat(add2,aff2,120);
	unsigned int length3 = strlcat(add3,aff3,70);
	unsigned int length4 = ft_strlcat(add4,aff4,70);
	cout<<"\n\n\n°º¤ø,,ø¤º°`°º¤ø, ex 05 ,ø¤°º¤ø,,ø¤º°`°º¤ø,\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'"<< add <<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << add2 ;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'"<< add3 <<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << add4 ;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'"; cout<<length <<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;cout << length2 ;cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
	cout<<"──────────answer──────────"<<endl;
	cout << "'"; printf("%d" ,length3) ;cout<<"'"<<endl;
	cout << "────────────────────────────────────────────────"<<endl;
	cout << "'"; fl;printf("%d", length4);cout<<"'"<<endl;
	cout<<"──────────output──────────\n\n\n"<<endl;
*/
}

