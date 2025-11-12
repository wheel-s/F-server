#include "../include/forge.h"





void print_error(const char *message){
    fprintf(stderr,"❌ Error: %s\n", message);
}

void list_directory(const char *path){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);
    if(dir == NULL){
        print_error("Unable to open directory");
        return;
    }

    printf("📁 Listing: %s\n", path);
    printf("--------------------------\n");

    printf("%s\n", path);
    while((entry=readdir(dir)) !=NULL){
        if(strcmp(entry->d_name, ".") ==0 ||strcmp(entry->d_name, "..") == 0){
            continue;
          
        }
        printf("%s\n", entry->d_name);
   
    }
    closedir(dir);
}


void copy_file(const char *src, const char *dest){
    FILE *source, *destination;

    char buffer[4096];
    size_t bytesRead;


    source = fopen(src, "rb");

    if(source==NULL){
        print_error("Unable to access source file");
        return;
    }

    destination = fopen(dest, "wb");

    if(destination==NULL){
        fclose(source);
        print_error("Unable to create destination file.");
        return;
    }
    
    while ((bytesRead=fread(buffer,1,sizeof(buffer), source))>0){
        fwrite(buffer,1,bytesRead,destination);

    }
    fclose(source);
    fclose(destination);
    printf("✅ Copied '%s' ---> '%s'\n", src, dest);

}



void move_file(const char *src, const char *dest){
    if(rename(src,dest) == 0){
        printf("📦 Moved '%s' ----> '%s'\n", src, dest);
    }else{
        print_error("failed to move file");
    }
}


void delete_file(const char *path){
    if(remove(path) == 0){
        printf("🗑️ Deleted '%s'\n", path);
    }else{
        print_error("failed to delete file");
    }
}



void show_file_info(const char *path){
    struct stat fileStat;

    if(stat(path, & fileStat)==-1){
        print_error("Unable to get file information");
    }

    printf("\n File:%s\n",path);

    printf("-------------------------------info---------------------------\n");



    printf("Size: %ld bytes\n",fileStat.st_size);

    printf( (S_ISDIR(fileStat.st_mode))?"d" : "-");
    printf((fileStat.st_mode & S_IRUSR)?"r" :"-");
    printf((fileStat.st_mode & S_IWUSR)?"w":"-");
    printf((fileStat.st_mode & S_IXUSR)?"w":"-");
    printf("\n");
    printf("Last modified: %s", ctime(&fileStat.st_mtime));




    
    printf("-------------------------------Data---------------------------\n");

    FILE *fp = fopen(path, "r");
    if(fp==NULL){
        print_error("Unabale to open file");
    }
    if(S_ISREG(fileStat.st_mode)){
        char buffer[1024];
        size_t bytes_read;
        printf("-----CONTENTS-----");
        while((bytes_read=fread(buffer,1,sizeof(buffer),fp))>0){
            fwrite(buffer,1,bytes_read,stdout);
           

        }
         printf("\n----End of File----");
           fclose(fp);
    }else{
        printf("cant read file");
    }
  
}





