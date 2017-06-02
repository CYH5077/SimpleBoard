#include "./info.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void * get_cpu_info(void* arg)
{
	reInfo * re = (reInfo*)arg;
	double a[4], b[4], loadavg;
	FILE *fp;
	
	fp = fopen("/proc/stat", "r");
	if(fp == NULL)
		return (void*)-1;
	fscanf(fp, "%*s %lf %lf %lf %lf",&a[0], &a[1], &a[2], &a[3]);
	fclose(fp);
	sleep(1);

	fp = fopen("/proc/stat","r");
	if(fp == NULL)
		return (void*)-1;
	fscanf(fp, "%*s %lf %lf %lf %lf", &b[0], &b[1], &b[2], &b[3]);
	fclose(fp);

	loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
	re->cpu = (int)(loadavg*100);
	get_cpu_name(re);
	return (void*)0;
}

static int cpu_parse(char * copy_target, char *string, char *parse_string, int string_len)
{
	if(strncmp(string, parse_string, string_len) == 0){
		strtok(string, ":");
		strcpy(copy_target, strtok(NULL,":"));
		return 0;
	}
	return -1;
}

int get_cpu_name(reInfo * re)
{
	FILE *fp;
	char cpu_model[200];
	int setting_count = 0;

	fp = fopen("/proc/cpuinfo", "r");
	if(fp == NULL) return -1;
	
	while((fgets(cpu_model,200, fp) != NULL) &&(setting_count != 3))
	{
		if(cpu_parse(re->cpu_model, cpu_model,  "model name", 10) == 0)
			setting_count++;	
		else if(cpu_parse(re->cpu_core_count, cpu_model, "vendor_id", 9) == 0)
			setting_count++;
		else if(cpu_parse(re->cpu_vendor, cpu_model, "cpu cores", 9) == 0)
			setting_count++;
	}
	fclose(fp);
	return 0;
}
