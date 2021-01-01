/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:29 by abourin           #+#    #+#             */
/*   Updated: 2019/10/22 13:21:34 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

#include "libft.h"

#define printf ft_printf

int main(void) {
	// test for %d
    unsigned int i = 123;
	
	printf("#01 [%u]\n", i);
	printf("#02 [%3u]\n", i);
	printf("#03 [%.3u]\n", i);
	printf("#04 [%3.3u]\n", i);
	printf("#05 [%*u]\n", 4, i);
	printf("#06 [%.*u]\n", 4, i);
	printf("#07 [%*.*u]\n", 4, 4, i);
	printf("#08 [%03u]\n", i);
	printf("#09 [%-3u]\n", i);
	printf("#10 [%0.3u]\n", i);
	printf("#11 [%-.3u]\n", i);
	printf("#12 [%0u]\n", i);
	printf("#13 [%.0u]\n", i);
	printf("#14 [%*u]\n", 0, i);
	printf("#15 [%.*u]\n", 0, i);
	printf("#16 [%*u]\n", -1, i);
	printf("#17 [%.*u]\n", -1, i);
	printf("#18 [% *u]\n", 10, i);
	printf("#19 [% .*u]\n", 10, i);
	printf("#20 [%-*u]\n", 10, i);
	printf("#21 [%-.*u]\n", 10, i);
	printf("#22 [%-5.10u]\n", i);
	printf("#23 [%-10.5u]\n", i);
	printf("#24 [%5.10u]\n", i);
	printf("#25 [%10.5u]\n", i);
	printf("#26 [%*u]\n", -10, i);
	printf("#27 [%.*u]\n", -10, i);
	printf("#28 [% 3u]\n", i);
	printf("#29 [%03u]\n", i);
	printf("#30 [% .3u]\n", i);
	printf("#31 [%0.3u]\n", i);
	return (0);
}

/*
int main(void)
{
	char *ptr = "123";

	printf("#01 [%p]\n", ptr);
	printf("#02 [%*p]\n", -3, ptr);
	printf("#03 [%.*p]\n", -3, ptr);
	printf("#04 [%*p]\n", 0, ptr);
	printf("#05 [%.*p]\n", 0, ptr);
	printf("#06 [%*p]\n", 3, ptr);
	printf("#07 [%.*p]\n", 3, ptr);
	printf("#08 [%*p]\n", 11, ptr);
	printf("#09 [%.*p]\n", 11, ptr);
	printf("#10 [%0*p]\n", 11, ptr);
	printf("#11 [%0.*p]\n", 11, ptr);
	printf("#12 [% *p]\n", 11, ptr);
	printf("#13 [% .*p]\n", 11, ptr);
	printf("#14 [%-*p]\n", 11, ptr);
	printf("#15 [%-.*p]\n", 11, ptr);
	return (0);
}
*/

/*
int main(void) {
	// test for %d
    int i = -9;
	
	printf("#01 [%d]\n", i);
	printf("#02 [%3d]\n", i);
	printf("#03 [%.3d]\n", i);
	printf("#04 [%3.3d]\n", i);
	printf("#05 [%*d]\n", 4, i);
	printf("#06 [%.*d]\n", 4, i);
	printf("#07 [%*.*d]\n", 4, 4, i);
	printf("#08 [%03d]\n", i);
	printf("#09 [%-3d]\n", i);
	printf("#10 [%0.3d]\n", i);
	printf("#11 [%-.3d]\n", i);
	printf("#12 [%0d]\n", i);
	printf("#13 [%.0d]\n", i);
	printf("#14 [%*d]\n", 0, i);
	printf("#15 [%.*d]\n", 0, i);
	printf("#16 [%*d]\n", -1, i);
	printf("#17 [%.*d]\n", -1, i);
	printf("#18 [% *d]\n", 10, i);
	printf("#19 [% .*d]\n", 10, i);
	printf("#20 [%-*d]\n", 10, i);
	printf("#21 [%-.*d]\n", 10, i);
	printf("#22 [%-5.10d]\n", i);
	printf("#23 [%-10.5d]\n", i);
	printf("#24 [%5.10d]\n", i);
	printf("#25 [%10.5d]\n", i);
	printf("#26 [%*d]\n", -10, i);
	printf("#27 [%.*d]\n", -10, i);
	printf("#28 [% 3d]\n", i);
	printf("#29 [%03d]\n", i);
	printf("#30 [% .3d]\n", i);
	printf("#31 [%0.3d]\n", i);
	return (0);
}
*/

/*
int main(void) {
	// test for %s
	char *str = "abcdef";
	
	ft_printf("#01 [%s]\n", str);
	ft_printf("#02 [%3s]\n", str);
	ft_printf("#03 [%.3s]\n", str);
	ft_printf("#04 [%3.3s]\n", str);
	ft_printf("#05 [%*s]\n", 4, str);
	ft_printf("#06 [%.*s]\n", 4, str);
	ft_printf("#07 [%*.*s]\n", 4, 4, str);
	ft_printf("#08 [%03s]\n", str);
	ft_printf("#09 [%-3s]\n", str);
	ft_printf("#10 [%0.3s]\n", str);
	ft_printf("#11 [%-.3s]\n", str);
	ft_printf("#12 [%0s]\n", str);
	ft_printf("#13 [%.0s]\n", str);
	ft_printf("#14 [%*s]\n", 0, str);
	ft_printf("#15 [%.*s]\n", 0, str);
	ft_printf("#16 [%*s]\n", -1, str);
	ft_printf("#17 [%.*s]\n", -1, str);
	return (0);
}
*/

/*
int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	ft_printf("p0 % .3s\n", "cccc");
	ft_printf("pp %.50d\n", 10000);
	ft_printf("p1 %.4s\n", "cccc");
	ft_printf("p2 %.10s\n", "cccc");
	ft_printf("p3 %.4s\n", NULL);
	ft_printf("p4 %.5s\n", "aaaaa");
	ft_printf("p5 %.3d\n", 100);
	ft_printf("p6 %.0d\n", 100);
	ft_printf("p7 %.4d\n", 100);
	ft_printf("p8 %.10d\n", 100);
	ft_printf("p9 %.50d\n", 100);
	ft_printf("p10 %.1d\n", 100);
	ft_printf("p11 %.3d\n", 100);
	ft_printf("p12 %.0d\n", 0);
	ft_printf("p13 %.3i\n", 100);
	ft_printf("p14 %.0i\n", 100);
	ft_printf("p15 %.4i\n", 100);
	ft_printf("p16 %.10i\n", 100);
	ft_printf("p17 %.50i\n", 100);
	ft_printf("p18 %.1i\n", 100);
	ft_printf("p19 %.3x\n", 100);
	ft_printf("p20 %.0x\n", 0);
	ft_printf("p21 %.3x\n", 100);
	ft_printf("p22 %.0x\n", 100);
	ft_printf("p23 %.4x\n", 100);
	ft_printf("p24 %.10x\n", 100);
	ft_printf("p25 %.50x\n", 100);
	ft_printf("p26 %.1x\n", 100);
	ft_printf("p27 %.3x\n", 100);
	ft_printf("p28 %.0x\n", 0);
	ft_printf("p29 %.3u\n", 100);
	ft_printf("p30 %.0u\n", 100);
	ft_printf("p31 %.4u\n", 100);
	ft_printf("p32 %.10u\n", 100);
	ft_printf("p33 %.50u\n", 100);
	ft_printf("p34 %.1u\n", 100);
	ft_printf("p35 %.3u\n", 100);
	ft_printf("p36 %.0u\n", 0);
	ft_printf("%%\n");
	ft_printf("Hello 42 school! %s", NULL);
	ft_printf("%010%");
	ft_printf("%u", 4294967295);
	ft_printf("%d\n", 2147483647);
	ft_printf("%d\n", -2147483648);
	ft_printf("%x\n", 2147483647);
	ft_printf("%x\n", -2147483648);
	ft_printf("%X\n", 2147483647);
	ft_printf("%X\n", -2147483648);
	ft_printf("%x\n", 0);
	ft_printf("%010x\n", 0);
	ft_printf("%010x\n", 20);
	ft_printf("%010x\n", -20);
	ft_printf("%10x\n", 20);
	ft_printf("%10.2x\n", -20);
	ft_printf("%-10x\n", 50);
	ft_printf("%-15x\n", 0);
	ft_printf("%.1x\n", 500);
	ft_printf("%*.*x\n", 50, 10, 2);
	ft_printf("%x\n", -1);
	ft_printf("%");
	ft_printf("%40.50d\n", 50);
    ft_printf("%d\n", -589);
    ft_printf("%-4d\n", -2464);
    ft_printf("%.5d\n", -2372);
	ft_printf("%p\n", NULL);
	ft_printf("%015p\n", NULL);
	ft_printf("%15p\n", NULL);
	ft_printf("%-15p\n", NULL);
    ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", -8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", 8473));
    ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", 8473));
	ft_printf("%c", 'a');
	ft_printf("%10c", 't');
	ft_printf("%1c", 'y');
	ft_printf("%010c", 't');
	ft_printf("%50.2s", "Coucou");
	ft_printf("%50.2s", NULL);
	ft_printf("%5.0s", "Hello");
	ft_printf("%.1s", "Test");
	ft_printf("%10s", NULL);
	ft_printf("%10s", "Ok");
	ft_printf("%d\n", ft_printf("Les bornes :  %d, %d\n", -2147483648, 2147483647));
    ft_printf("%d\n", ft_printf("Les bornes :  %u, %u\n", 0, 4294967295));
	ft_printf("%d\n", ft_printf("Les bornes :  %x, %x\n", 0, 4294967295));
	ft_printf("%d\n", ft_printf("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	ft_printf("%d\n", ft_printf("2chiffre 1 %   d chiffre 2 % d\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4chiffre 1 %-12d chiffre 2 %-12d\n\n", 42, -42));
	ft_printf("%    i\n", -60);
    ft_printf("%   i\n", -60);
    ft_printf("%1p\n", &t);
    ft_printf("%1p\n", &t);
	ft_printf("t1 %050d\n", 10);
	ft_printf("t2 %-50d\n", 10);
	ft_printf("t3 %50.0d\n", 10);
	ft_printf("t4 %50.50d\n", 10);
	ft_printf("t5 %50.10d\n", 10);
	ft_printf("t6 %*.*d\n", 50,  5, 10);
	ft_printf("t7 %1.50d\n", -10);
	ft_printf("t8 %1.50d\n", 10);
	ft_printf("t9 %2.2d\n", 10);
	ft_printf("t10 %2.2d\n", -10);
	ft_printf("t12 %.0d\n", 0);
	ft_printf("t13 %01d\n", -20);
	ft_printf("t14 %10d\n", 1000);
	ft_printf("%d\n\n", ft_printf("5chiffre 1 %0d chiffre 2 %0d\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("6chiffre 1 %012d chiffre 2 %012d\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));
	ft_printf("%d\n\n", ft_printf("15chiffre 1 %.d chiffre 2 %.d\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4caractere 1 %12c caractere 2 %12c\n\n", 'a', 'c'));
	ft_printf("1caractere 1 %c caractere 2 %c\n\n", 'a', 'c');
	ft_printf("3caractere 1 %   c caractere 2 % c\n\n", 'a', 'c');
	ft_printf("%d\n\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("3hexa-maj 1 %   X hexa-maj 2 % X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %int12X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("8hexa-maj 1 %*X hexa-maj 2 %*X\n\n", 42, 6, 6, 6));
	ft_printf("%d\n\n", ft_printf("1pointeur 1 %p pointeur 2 %p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("3pointeur 1 %   p pointeur 2 % p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("4pointeur 1 %12p pointeur 2 %12p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("4pointeur 1 %-12p pointeur 2 %-12p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("5pointeur 1 %0p pointeur 2 %0p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("6pointeur 1 %012p pointeur 2 %012p\n\n", &c, &c));
	ft_printf("%d\n\n", ft_printf("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4unsigned 1 %12u unsigned 2 %12u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("5unsigned 1 %0u unsigned 2 %0u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("8unsigned 1 %*u unsigned 2 %*u\n\n", 42, 6, 6, 6));
	ft_printf("%d\n\n", ft_printf("15unsigned 1 %.u unsigned 2 %.u\n\n", 42, -42));
	ft_printf("%d\n\n", ft_printf("%s", 0));
	ft_printf("%d\n\n", ft_printf("%%\n")); 
	ft_printf("%d\n\n", ft_printf("%-.12u\n", -20000000));
	ft_printf("%d\n\n", ft_printf("%-.12i\n", -20000000));
	ft_printf("%d\n", ft_printf("truc"));
	ft_printf("%d\n", ft_printf("bonjour !\n", 42, -42));
	ft_printf("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	ft_printf("%d\n", ft_printf("03 This is a float : %f\n\n", 45.236));
	ft_printf("%d\n", ft_printf("02 This is a float : %.3f\n\n", 45.236));
	ft_printf("%d\n",   ft_printf("01 This is a float : %3f\n\n", 45.236));
	ft_printf("%d\n", ft_printf("000 This is a float : %f\n\n", -45.236));
	ft_printf("%d\n", ft_printf("0 This is a float : %.3f\n\n", -45.236));
	ft_printf("%d\n", ft_printf("00 This is a float : %3f\n\n", -45.236));
	ft_printf("1 This is a float : %f\n\n", 0.00025);
	ft_printf("2 This is a float : %.3f\n\n", 0.00025);
	ft_printf("3 This is a float : %3f\n\n", 0.00025);
	ft_printf("4 This is a float : %f\n\n", -0.00025);
	ft_printf("5 This is a float : %f\n\n", -0.00025);
	ft_printf("6 This is a float : %.3f\n\n", -0.00025);
	ft_printf("7 This is a float : %3f\n\n", -0.00025);
	ft_printf("8 This is a float : %3f\n\n", 1.0 / 0.0);
	ft_printf("9 This is a float : %3f\n\n", -1.0 / 0.0);
	ft_printf("10 This is a float : %3f\n\n", 0.0 / 0.0);
	ft_printf("11 This is a float : %3f\n\n", -0.0 / 0.0);
	ft_printf("12 This is a float : %.0f\n\n", 2.5);
	ft_printf("13 This is a float : %.0f\n\n", 3.5);
	ft_printf("14 This is a float : %.0f\n\n", -2.5);
	ft_printf("15 This is a float : %.0f\n\n", -3.5);
	ft_printf("16 This is a float : %.0f\n\n", 2.51);
	ft_printf("17 This is a float : %.0f\n\n", 3.51);
	ft_printf("18 This is a float : %10.0f\n\n", -2.51);
	ft_printf("19 This is a float : %10.0f\n\n", -3.51);
	ft_printf("20 This is a float : %10.5f\n\n", -2.51);
	ft_printf("21 This is a float : %10.5f\n\n", -3.51);
	ft_printf("22 This is a float : %10.5f\n\n", 2.51);
	ft_printf("23 This is a float : %10.5f\n\n", 3.51);
	ft_printf("24 This is a float : %10.0f\n\n", 2.51);
	ft_printf("25 This is a float : %10.0f\n\n", 3.51);
	ft_printf("26 This is a float : %010f\n\n", 2.51);
	ft_printf("27 This is a float : %-10f\n\n", 3.51);
	ft_printf("28 This is a float : %015f\n\n", 2.51);
	ft_printf("29 This is a float : %15f\n\n", 3.51);
	ft_printf("30 This is a float : %.0f\n\n", 0.0);
	ft_printf("31 This is an int : %.0d\n\n", 0);
	ft_printf("32 This is an int : %0d\n\n", 0);
	ft_printf("percent 1 %012%");
	ft_printf("percent 2 %12%");
	ft_printf("percent 3 %-12%");
	ft_printf("percent 4 %0%");
	ft_printf("percent 5 % %");
	ft_printf("percent 6 % 15%");
	ft_printf("percent 7 % 12%");
	ft_printf("percent 8 %  *%", 13);
	ft_printf("%n", &t);
	ft_printf("%d\n", t);
	ft_printf("%n", NULL);
	ft_printf("%d\n", t);
	ft_printf("test %n", &t);
	ft_printf("%d\n", t);
	ft_printf("%s %n", "hello world", &t);
	ft_printf("%d\n", t);
	ft_printf("% .1s %n", "hey", &t);
	ft_printf("%d\n", t);
	ft_printf("%40s %n", "co", &t);
	ft_printf("%d\n", t);
	ft_printf("%050 d%n", 500, &t);
	ft_printf("%d\n", t);
	ft_printf("%050 u%n", 500, &t);
	ft_printf("%d\n", t);
	ft_printf("%d\n\n", ft_printf("1string 1 %s string 2 %s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("3string 1 %   s string 2 % s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("4string 1 %12s string 2 %12s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("4string 1 %-12s string 2 %-12s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("5string 1 %0s string 2 %0s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("6string 1 %012s string 2 %012s\n\n", "toto", "bonjour"));
	ft_printf("%d\n\n", ft_printf("7string 1 %-012s string 2 %012s\n\n", "toto", "bonjour"));
	ft_printf("st1 %*.*d\n", 10, 10, 50);
	ft_printf("st2 %*.*d\n", 1, 50, 50);
	ft_printf("st3 %*.*d\n", 0, 0, 50);
	ft_printf("st4 %*.*d\n", 0, 50, 50);
	ft_printf("st5 %*.*d\n", 10, 0, 50);
	ft_printf("st6 %*.*d\n", 10, 10, 50);
	ft_printf("st12 %*d\n", 10, 50);
	ft_printf("st13 %*d\n", 0, 0);
	ft_printf("st14 %.*d\n", 0, 0);
	ft_printf("st15 %*d\n", 50, 5);
	ft_printf("st16 %0.*d\n", 50, 5);
	ft_printf("st17 %0.*d\n", 0, 0);
	ft_printf("st7 %*.*s\n", 1, 50, "hey");
	ft_printf("st8 %*.*s\n", 0, 0, "coucou");
	ft_printf("st9 %*.*s\n", 0, 50, "hey");
	ft_printf("st10 %*.*s\n", 10, 0, "dsa");
	ft_printf("st11 %*.*s\n", 10, 10, "hello");
	ft_printf("st7 %0.*s\n", 50, "hey");
	ft_printf("st8 %.*s\n", 0, "coucou");
	ft_printf("st9 %*s\n", 0, "hey");
	ft_printf("st10 %*s\n", 10, "dsa");
	ft_printf("st118 %*s\n", 100, "hello");
	ft_printf("st119 %*s\n", 1000, "hello");
	ft_printf("st120 %*s\n", 10000, "hello");
	ft_printf("st121 %*s\n", 100000, "hello");
	ft_printf("st118 %*d\n", 100, 0);
	ft_printf("st119 %*d\n", 1000, 10);
	ft_printf("st120 %*d\n", 10000, 467);
	ft_printf("st121 %*d\n", 100000, -589);
	ft_printf("ultimate1 %*d        %*i\n", 500, 0, 10, 10);
	ft_printf("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	ft_printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	ft_printf("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	ft_printf("ultimate5 %*.*u\n", 1, 50, 5000);
	ft_printf("neg1 %*s\n", -9, "coucou");
	ft_printf("neg2 %*.*s\n", -9, 4, "coucou");
	ft_printf("neg3 %*s\n", -9, NULL);
	ft_printf("neg4 %*.*s\n", 0, 0, "coucou");
	ft_printf("neg5 %*s\n", -100, "coucou");
	ft_printf("neg6 %*s\n", -156, "coucou");
	ft_printf("neg7 %*.*s\n", -1586, 15, "coucou");
	ft_printf("neg8 %*.*s\n", -1586, 15, "coucou");
	ft_printf("neg9 %*.*s\n", 15856, 155, "coucou");
	ft_printf("neg10 %*.*s\n", -15586, 15, "coucou");
	ft_printf("neg11 %*.*s\n", -15586, 15, "coucou");
	ft_printf("neg1 %*d\n", -9, 150);
	ft_printf("neg2 %*.*d\n", -9, 4, 1555);
	ft_printf("neg3 %*d\n", -9, -255);
	ft_printf("neg4 %*.*d\n", 0, 0, -30);
	ft_printf("neg5 %*d\n", -100, -589);
	ft_printf("neg6 %*d\n", -156, 15555);
	ft_printf("neg7 %*.*d\n", -1586, 15, 0);
	ft_printf("neg8 %*.*d\n", -1586, 15, 300);
	ft_printf("neg9 %*.*d\n", 15856, 155, -3000);
	ft_printf("neg10 %*.*d\n", -15586, 15, 150);
	ft_printf("neg11 %*.*d\n", -15586, 15, 0);
	ft_printf("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20);
	ft_printf("taaa %100s\n", "hello");
}
*/