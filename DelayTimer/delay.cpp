/*
	Author	:	Saint Atique
	Date	:	2009
	Desc	:	A Console application for implementing delay
				As we know a sleep is not available in windows
				Hence I implemented this one. Redistributing it
				so that others do not have to reinvent the wheel
				This application will be useful for who write 
				windows batch script especially.

	Usage	:	DelayTimer.exe 5		// to make delay of 5s
				DelayTimer.exe 1:25		// to make delay of 1 minute and 25s
				DelayTimer.exe 1:30:25	// to make delay of 1 hour and 30 minutes and 25s
				DelayTimer.exe 70		// to make delay of 70s

	Image ack:	The image used in sourceforge devian art
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>

int main (int argc, char *argv[]) {
	char *token;
	char formatstr[100];
	char *sep = ":";
	bool nonzerof = true;

	int delay, i, res, formatlen=0;
	int prelen=0;

	if (argc<2) {
		printf("Argument delay time missing.\n");
		return 0;
	}
	else if (argc>2)
		printf("Ignoring extra %d arguments.\n", argc -2);

	// Split first token
	token = strtok(argv[1], sep);
	//printf("Current token: %s\n", token);
	res = atoi(token);
	if (res >= 0)
		delay = res;
	else {
		printf("Invalid token: %s.\n", token);
		return 0;
	}

	i = 0;
		
	// Split hours, minute and seconds
	while (token = strtok(NULL, sep)) {
		if (token) {
			res = atoi(token);
			if (res < 60)
				delay = delay * 60 + res;
			else {
				printf("Invalid token: %s.\n", token);
				return 0;
			}
			//printf("Current token: %s\n", token);
		}
		if (++i > 2) {
			printf("Too many seperator colons.\n");
			return 0;
		}
	}
	if (delay > 24 * 60 * 60)
		printf("****  Warning: delay more than 24 hours  ****\n");


	for (i=0; i<delay; i++) {
		res = (delay - i) / 3600;
		//printf("\rTime to wait:");
		putchar('\r');
		sprintf(formatstr, "Time to wait:");
		formatlen = strlen(formatstr);

		if (res) {
			sprintf(&formatstr[formatlen], " %dh", res);
			formatlen = strlen(formatstr);
			// printf(" %dh", res);
			nonzerof = false;
		}
		res = (delay-i)%3600;
		res /= 60;
		if (res) {
			// printf(" %dm", res);
			sprintf(&formatstr[formatlen], " %dm", res);
			formatlen = strlen(formatstr);
			nonzerof = false;
		}
		res = (delay-i)%3600;
		res %= 60;
		if (res || nonzerof) {
			sprintf(&formatstr[formatlen], " %ds", res);
			formatlen = strlen(formatstr);
			// printf(" %ds", res);
		}
		if (prelen && prelen > formatlen) {
			int j;
		    for (j = formatlen; j<prelen; j++)
		        //printf(" ");
				formatstr[j] = ' ';
			formatstr[j] = '\0';
		}
		printf(formatstr);
		/*if (prelen && prelen > formatlen) {
		    int diff = prelen - formatlen;
		    for (int j=0; j<diff; j++)
		        printf(" ");
		}*/
		prelen = formatlen;
		//printf("    ");

		Sleep(1000);
	}
	putchar('\r');
	nonzerof = true;
	printf("Time (");
	res = delay / 3600;
	if (res)
		printf("%dh ", res);
	res = delay%3600;
	res /= 60;
	if (res) {
		printf("%dm ", res);
		nonzerof = false;
	}
	res = delay%3600;
	res %= 60;
	if (res || nonzerof)
		printf("%ds", res);
	printf(") passed\n");
	return 0;
}
