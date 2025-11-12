#ifndef FORGE_H
#define FORGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>


void list_directory(const char *path);
void copy_file(const char *src, const char *dest);
void move_file(const char *src, const char *dest);
void delete_file(const char *path);
void show_file_info(const char *path);
void diff_file(const char *file1, const char *file2);



void print_error(const char *message);

#endif
