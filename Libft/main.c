/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:06:38 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/17 18:35:38 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char	testing(unsigned int i, char c)
{
	if (ft_isdigit(ft_itoa(i)[0]))
		return (ft_toupper(c));
	else
		return ('-');
}

int	main()
{
	char		str[50];
	char		dest[50];
	char		str_base[50];
	char		dest_base[50];
	char		*msg;
	const char	c = '.';
	char		ch;
	int			*a;
	int			i;
	char		**words;

	printf("\n%s\n\n", "TEST 1");

	printf("%s\n", "My ft_strlcpy:");
	ft_strlcpy(str, "s testing", 0);
	puts(str);

	printf("%s\n", "Base strlcpy:");
	strlcpy(str_base, "s testing", 0);
	puts(str_base);

	printf("%s\n", "My ft_memset:");
	ft_memset(str, 'm', 1);
	puts(str);
	printf("%s\n", "Base memset:"); 
	memset(str_base, 'm', 1);
	puts(str_base);

	printf("\n%s\n\n", "TEST 2");

	printf("%s\n", "My ft_bzero:");
	ft_bzero(str, 10);
	puts(str);
	printf("%s\n", "Base bzero:");
	bzero(str_base, 10);
	puts(str_base);

	printf("\n%s\n\n", "TEST 3");

	printf("%s\n", "My ft_strlcpy:");
	ft_strlcpy(str, "So, lets check this shit", 50);
	ft_strlcpy(dest, "Yeah, i will check you", 50);
	printf("Before ft_memcpy dest = %s\n", dest);
	printf("My ft_strlen func knows that len of str is: %zu\n", ft_strlen(str));
	ft_memcpy(dest, str, ft_strlen(str) + 1);
	printf("My ft_memcpy result dest = %s\n", dest);

	printf("%s\n", "Base strlcpy:");
	strlcpy(str_base, "So, lets check this shit", 50);
	strlcpy(dest_base, "Yeah, i will check you", 50);
	printf("Before memcpy dest = %s\n", dest_base);
	printf("Base strlen func knows that len of str is: %zu\n", strlen(str_base));
	memcpy(dest_base, str_base, strlen(str_base) + 1);
	printf("Base memcpy result dest = %s\n", dest_base);

	printf("\n%s\n\n", "TEST 4");

	msg = "This should be copied, but this is not";
	printf("My ft_memset sets %s to terminated\n", dest);
	ft_memset(dest, '\0', 50);
	printf("While base memset does the same with: %s\n", dest_base); 
	memset(dest_base, '\0', 50);
	ft_memccpy(dest, msg, ',', 50);
	printf("Result of my ft_memccpy: %s\n", dest);
	memccpy(dest_base, msg, ',', 50);
	printf("Result of base memccpy is: %s\n", dest_base);

	printf("\nTEST 5\n\n");

	ft_memset(dest, '\0', 50);
	ft_strlcpy(dest, "oldstring", 50);
	ft_memset(str, '\0', 50);
	ft_strlcpy(str, "newstring", 50);
	printf("We have such in dest and str:|%s| |%s|\n", dest, str);
	ft_memmove(dest, str, 9);
	printf("After ft_memmove dest and str:|%s| |%s|\n", dest, str);

	memset(dest_base, '\0', 50);
	strlcpy(dest_base, "oldstring", 50);
	memset(str_base, '\0', 50);
	strlcpy(str_base, "newstring", 50);
	printf("We have such in dest and str:|%s| |%s|\n", dest_base, str_base);
	memmove(dest_base, str_base, 9);
	printf("After memmove dest and str:|%s| |%s|\n", dest_base, str_base);

	printf("\nTEST 6\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "https://www.hse.ru", 50);
	printf("String after my ft_memchr |%c| is |%s|\n", c, ft_memchr(str, c, ft_strlen(str)));

	bzero(str_base, 50);
	strlcpy(str_base, "https://www.hse.ru", 50);
	printf("String after my memchr |%c| is |%s|\n", c, memchr(str_base, c, strlen(str_base)));

	printf("\nTEST 7\n\n");

	ft_bzero(str, 50);
	ft_bzero(dest, 50);
	ft_memcpy(str, "abcdef", 6);
	ft_memcpy(dest, "ABCDEF", 6);
	printf("Answer is %d\n", ft_memcmp(str, dest, 5));

	bzero(str_base, 50);
	bzero(dest_base, 50);
	memcpy(str_base, "abcdef", 6);
	memcpy(dest_base, "ABCDEF", 6);
	printf("Answer is %d\n", memcmp(str_base, dest_base, 5));

	printf("\nTEST 8\n\n");

	ft_strlcat(dest, str, 50);
	printf("My ft_strlcat result: |%s|\n", dest);

	strlcat(dest_base, str_base, 50);
	printf("Base strlcat result: |%s|\n", dest_base);

	printf("\nTEST 9\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "https://www.hse.ru", 50);
	printf("String after my ft_strchr |%c| is |%s|\n", c, ft_strchr(str, c));

	bzero(str_base, 50);
	strlcpy(str_base, "https://www.hse.ru", 50);
	printf("String after base strchr |%c| is |%s|\n", c, strchr(str_base, c));

	printf("\nTEST 10\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "https://www.hse.ru", 50);
	printf("String after my ft_strchr |%c| is |%s|\n", c, ft_strrchr(str, c));

	bzero(str_base, 50);
	strlcpy(str_base, "https://www.hse.ru", 50);
	printf("String after base strchr |%c| is |%s|\n", c, strrchr(str_base, c));

	printf("\nTEST 11\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "How are you, bro?", 50);
	ft_bzero(dest, 50);
	ft_strlcpy(dest, ",", 50);
	printf("Result of ft_strnstr: %s\n", ft_strnstr(str, dest, 50));

	bzero(str_base, 50);
	strlcpy(str_base,  "How are you, bro?", 50);
	bzero(dest_base, 50);
	strlcpy(dest_base,  ",", 50);
	printf("Result of strnstr: %s\n", strnstr(str, dest, 50));

	printf("\nTEST 12\n\n");

	ft_bzero(str, 50);
	ft_bzero(dest, 50);
	ft_memcpy(str, "abcdef", 6);
	ft_memcpy(dest, "ABCDEF", 6);
	printf("For ft_strncmp answer is %d\n", ft_strncmp(str, dest, 4));

	bzero(str_base, 50);
	bzero(dest_base, 50);
	memcpy(str_base, "abcdef", 6);
	memcpy(dest_base, "ABCDEF", 6);
	printf("Base strncmp answer is %d\n", strncmp(str_base, dest_base, 4));

	printf("\nTEST 13\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "-2147483648", 50);
	ft_bzero(dest, 50);
	ft_strlcpy(dest, "2147483647", 50);
	printf("ft_atoi result [min int]: %d\n", ft_atoi(str));
	printf("ft_atoi result [max int]: %d\n", ft_atoi(dest));
	ft_bzero(str, 50);
	ft_strlcpy(str, "---0", 50);
	ft_bzero(dest, 50);
	ft_strlcpy(dest, "-17", 50);
	printf("ft_atoi result [zero]: %d\n", ft_atoi(str));
	printf("ft_atoi result [-17]: %d\n", ft_atoi(dest));

	bzero(str_base, 50);
	strlcpy(str_base, "-2147483648", 50);
	bzero(dest_base, 50);
	strlcpy(dest_base, "2147483647", 50);
	printf("ft_atoi result [min int]: %d\n", atoi(str_base));
	printf("ft_atoi result [max int]: %d\n", atoi(dest_base));
	bzero(str_base, 50);
	strlcpy(str_base, "---0", 50);
	bzero(dest_base, 50);
	strlcpy(dest_base, "-17", 50);
	printf("ft_atoi result [zero]: %d\n", atoi(str_base));
	printf("ft_atoi result [-17]: %d\n", atoi(dest_base));

	printf("\nTEST 14\n\n");

	printf("Results of ft_toupper and ft_tolower:\n");
	ch = 'm';
	printf("%c -> %c\n", ch, ft_toupper(ch));
	ch = 'D';
	printf("%c -> %c\n", ch, ft_toupper(ch));
	ch = '9';
	printf("%c -> %c\n", ch, ft_toupper(ch));
	ch = 'm';
	printf("%c -> %c\n", ch, ft_tolower(ch));
	ch = 'D';
	printf("%c -> %c\n", ch, ft_tolower(ch));
	ch = '9';
	printf("%c -> %c\n", ch, ft_tolower(ch));

	printf("Results of toupper and tolower:\n");
	ch = 'm';
	printf("%c -> %c\n", ch, toupper(ch));
	ch = 'D';
	printf("%c -> %c\n", ch, toupper(ch));
	ch = '9';
	printf("%c -> %c\n", ch, toupper(ch));
	ch = 'm';
	printf("%c -> %c\n", ch, tolower(ch));
	ch = 'D';
	printf("%c -> %c\n", ch, tolower(ch));
	ch = '9';
	printf("%c -> %c\n", ch, tolower(ch));

	printf("\nTEST 15\n\n");

	printf("ft_calloc used:\n");
	a = (int *)ft_calloc(5, sizeof(int));
	a[0] = 3;
	a[1] = 2;
	a[2] = 5;
	a[3] = 17;
	a[4] = -2147483648;
	printf("The numbers in array: ");
	for(i = 0 ; i < 5 ; i++)
		printf("%d ", a[i]);
	free(a);
	
	printf("\nA base calloc used:\n");
	a = (int *)calloc(5, sizeof(int));
	a[0] = 3;
	a[1] = 2;
	a[2] = 5;
	a[3] = 17;
	a[4] = -2147483648;
	printf("The numbers in array: ");
	for(i = 0 ; i < 5 ; i++)
		printf("%d ", a[i]);
	free(a);

	printf("\n\nTEST 16\n\n");

	msg = ft_strdup(str);
	printf("The msg after ft_strdup is: %s\n", msg);
	free(msg);

	msg = strdup(str);
	printf("The msg after strdup is: %s\n", msg);
	free(msg);

	printf("\nTEST 17\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, ".|. What can you do? .|.", 50);
	msg = ft_substr(str, 4, 16);
	printf("The sub string is: %s\n", msg);
	free(msg);

	printf("\nTEST 18\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "Jjjjoin .|", 50);
	ft_bzero(dest, 50);
	ft_strlcpy(dest, ". meee!!", 50);
	msg = ft_strjoin(str, dest);
	printf("Res of ft_strjoin: %s\n", msg);
	free(msg);

	printf("\nTEST 19\n\n");

	ft_bzero(dest, 50);
	ft_strlcpy(dest, " ,.-/()}{:;", 50);
	ft_bzero(str, 50);
	ft_strlcpy(str, "               ", 50);
	msg = ft_strtrim(str, " ");
	ft_putnbr_fd(ft_strlen(msg), 1);
	ft_putendl_fd("", 1);
    printf("Res of ft_strtrim: %s\n", msg == NULL ? "NULL" : msg);
    char s1[] = "          ";
    if (!(msg = ft_strtrim(s1, " ")))
        ft_putendl_fd("NULL", 1);
    else
        ft_putendl_fd(msg, 1);
    if (msg == s1)
        ft_putendl_fd("\nA new string was not returned", 1);

	free(msg);

	printf("\nTEST 20\n\n");

	ft_bzero(str, 50);
	ft_strlcpy(str, "We   do not want  to be together !!!", 50);
	words = ft_split(str, '\0');
	printf("ft_split splitted words: ");
	for (i = 0 ; i < 1 ; i++)
		printf("|%s| ", words[i]);
	printf("\n");
	free(words);

	printf("\nTEST 21\n\n");

	msg = ft_itoa(-2147483648);
	printf("Result [min int]: %s\n", msg);
	free(msg);
	msg = ft_itoa(2147483647);
	printf("Result [max int]: %s\n", msg);
	free(msg);
	msg = ft_itoa(0);
	printf("Result [zero]: %s\n", msg);
	free(msg);
	msg = ft_itoa(10011009);
	printf("Result [10011009]: %s\n", ft_itoa(10011009));
	free(msg);

	printf("\nTEST 22\n\n");

	msg = ft_strmapi(str, *testing);
	printf("After ft_strmapi str became: %s\n", msg);
	free(msg);

	printf("\nTEST 23\n\n");

	printf("ft_putchar_fd: \n");
	ft_putchar_fd('H', 1);
	ft_putchar_fd('i', 1);
	ft_putchar_fd('!', 1);

	ft_putendl_fd("", 1);

	printf("ft_putstr_fd: \n");
	ft_putstr_fd("_____OK_____", 1);
	ft_putendl_fd("", 1);

	printf("ft_putnbr_fd: \n");
	ft_putnbr_fd(-2147483648, 1);
	ft_putendl_fd("", 1);

	ft_putnbr_fd(0, 1);
	ft_putendl_fd("", 1);

	ft_putnbr_fd(7, 1);
	ft_putendl_fd("", 1);

	ft_putnbr_fd(2147283647, 1);
    
    char *st = "01234";
    size_t size = 10;
    char *ret = ft_substr(st, 10, size);
    
    printf("%d\n", strncmp(ret, "", 1));
    
	return (0);
}
