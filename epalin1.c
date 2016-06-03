#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXLEN		100000
 
int match (char , char *, int *);
void fail_func (int *, char *);
 
int res;
 
int main ()
{
	char *inp, *tmp;
	int len, i, j, *fail;
	
	while (1) {
		inp = (char *) malloc (MAXLEN);	
		tmp = (char *) malloc (MAXLEN);
		fail = (int *) malloc ((MAXLEN + 1) * sizeof (int));
		if (gets (inp) == NULL)
			break;
		len = strlen (inp);
		for (i = 0; i < len; i++)
			tmp[len - i - 1] = inp[i];
		tmp[len] = '\0';
		fail_func (fail, tmp);
		i = 0;
		while (i <= len) {
			j = match (inp[i], tmp, fail);
			if (j == -2) {
				i += fail[len - i] + 1;
			l1 :
				if (inp[i] == inp[i - 1]) {
					i++;
					goto l1;
				}
			}
			else if (j == -1) {
				if (len - i - fail[len - i] == res) {
					res += fail[len - i];
					i += fail[len - i] + 1;
				}
				else
					i++;
			}
			else
				i++;
		}
		if (j == len)
			printf ("%s\n", inp);
		else
			printf ("%s%s\n", inp, tmp + j);
		free (inp); free (tmp); free (fail);
	}
	
	return 0;
}
 
int match (char ch, char *pat, int *fail)
{
        int i, ret;
 
        if (ch == '\0') {
                ret = res;
		res = 0;
                return ret;
        }
        label :
        if (ch == pat[res]) {
                res++;
		return -1;
	}
        else {
                if (res > 0) {
                        res = fail[res];
                        goto label;
                }
		return -2;
        }
}
 
void fail_func (int *fail, char *pat)
{
        int i = 1, j = 0;
 
        fail[1] = 0;
        while (pat[i] != '\0') {
                if (pat[i] == pat[j]) {
                        fail[i + 1] = j + 1;
                        i++;
                        j++;
                }
                else if (j > 0)
                        j = fail[j];
                else {
                        fail[i + 1] = 0;
                        i++;
                }
        }
 
        return;
}
