/*      #############
	#    _   _ 
	#   | \ | |    The Nebula Centre Project @ 2020
	#   |  \| |    https://nebulacentre.net
	#   | |\  |    https://nebulacentre.net/about.html
	#   |_| \_|    https://nebulacentre.net/code.html
	#
	#############

	The Nebula Centre Project is an active endeavour created by a small group.
	The Nebula Centre Project does not currently have an end goal, but does
	have a series of primary goals, which are currently being pursued and will
	always be considered in future judgements. To learn more about the
	Nebula Centre Project visit the project on the web at https://nebulacentre.net/about.html.

	We always welcome lain.
*/

/*
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

#define VERSION 1.0

void mainClock() {
	int hour, min, sec;
	char *strhour, *strmin, *strsec;
	for (;;) {
		time_t direct;
		struct tm* currentTime;
		struct tm* lastTime;
		strhour = "";
		strmin = "";
		strsec = "";
		time(&direct);
		currentTime = localtime(&direct);
		hour = currentTime->tm_hour;
		min = currentTime->tm_min;
		sec = currentTime->tm_sec;
		if (hour < 10) {
			strhour = "0";
		}
		if (min < 10) {
			strmin = "0";
		}
		if (sec < 10) {
			strsec = "0";
		}
		printf("\r        ");
		printf("\r%s%i:%s%i:%s%i", strhour, hour, strmin, min, strsec, sec);
		fflush(stdout);
		sleep(1);
	}
}

void timer(int duration) {
	int hour, min, sec;
	char *strhour, *strmin, *strsec;
	while (duration >= 0) {
		strhour = "";
		strmin = "";
		strsec = "";
		hour = duration / 3600;
		min = (duration - (3600 * hour)) / 60;
		sec = (duration - (3600 * hour) - (min * 60));
		if (hour < 10) {
			strhour = "0";
		}
		if (min < 10) {
			strmin = "0";
		}
		if (sec < 10) {
			strsec = "0";
		}
		printf("\r        ");
		printf("\r%s%i:%s%i:%s%i", strhour, hour, strmin, min, strsec, sec);
		fflush(stdout);
		duration--;
		sleep(1);
	}
}

void stopwatch() {
	int hour, min, sec;
	char *strhour, *strmin, *strsec;
	int duration = 0;
	for (;;) {
		strhour = "";
		strmin = "";
		strsec = "";
		hour = duration / 3600;
		min = (duration - (3600 * hour)) / 60;
		sec = (duration - (3600 * hour) - (min * 60));
		if (hour < 10) {
			strhour = "0";
		}
		if (min < 10) {
			strmin = "0";
		}
		if (sec < 10) {
			strsec = "0";
		}
		printf("\r        ");
		printf("\r%s%i:%s%i:%s%i", strhour, hour, strmin, min, strsec, sec);
		fflush(stdout);
		duration++;
		sleep(1);
	}
}

void help() {
	printf("\nUsage:\n ncc [options]\n\nOptions:\n -c, --clock             start a clock (default option)\n -h, --help              print this menu\n -s, --stopwatch         start a stopwatch\n -t, --timer <DURATION>  start a timer\n -v, --version           print the application version and other information\n\n <DURATION> may be specified as Hh:Mm:Ss, Mm:Ss or Ss.");
}

void version() {
	printf("The Nebula Centre Project @ 2020\nhttps://nebulacentre.net/about.html\n\nncc is licensed under the GPL V2 license.\nncc version %.1f", VERSION);
}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		if (argc > 3) {
			help();
			return 0;
		}
		for (int i = 0; i < argc; i++) {
			if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
				help();
				return 0;
			}
		}
		if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) {
			version();
			return 0;
		}
		else if (!strcmp(argv[1], "--clock") || !strcmp(argv[1], "-c")) {
			mainClock();
		}
		else if (!strcmp(argv[1], "--stopwatch") || !strcmp(argv[1], "-s")) {
			stopwatch();
		}
		else if (!strcmp(argv[1], "--timer") || !strcmp(argv[1], "-t")) {
			if (argc != 3) {
				help();
				return 0;
			}
			char timeBuf[11];
			int duration = 0;
			int currentSeek = 0;
			int cCount = 0;
			for (int k = 0; k < strlen(argv[2]); k++) {
				if (argv[2][k] == ':') {
					cCount++;
				}
				if (!argv[2][k] == ':' || !isdigit(argv[2][k])) {
					help();
					return 0;
				}
			}
			printf("%d", cCount);
			if (cCount < 2) {
				currentSeek = 1;
			}
			else if (cCount > 2) {
				help();
				return 0;
			}
			for (int k = 0; k < strlen(argv[2]); k++) {
				if (argv[2][k] != ':') {
					strncat(timeBuf, &argv[2][k], 1);
				}
				else {
					switch (currentSeek) {
						case 0:
							duration += 60 * (60 * atoi(timeBuf));
							memset(timeBuf, 0, 11);
							currentSeek++;
							break;
						case 1:
							duration += 60 * atoi(timeBuf);
							memset(timeBuf, 0, 11);
							break;
					}
				}
			}
			duration += atoi(timeBuf);
			timer(duration);
		}
		else {
			help();
			return 0;
		}
	}
	else {
		mainClock();
	}
	return 0;
}
