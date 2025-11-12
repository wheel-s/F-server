#include "../include/forge.h"

int main(int argc, char *argv[]){

    if(argc <2){
        printf("Usage: forge <command> [arguments]\n");
        printf("Commands: list, copy, move, delete, info, diff\n");

        return 1;
    }


    const char *command = argv[1];
    if(strcmp(command, "list")==0){
        if(argc <3){
            print_error("Missing directory path");
            return 1;
        }
     
        list_directory(argv[2]);
    }
    
    else if(strcmp(command, "copy")==0){
        if(argc <4){
            print_error("Usage: forge copy <src> <dest>");
            return 1;
        }
        copy_file(argv[2], argv[3]);

    }

    
    else if(strcmp(command, "move")==0){
         if(argc <4){
            print_error("Usage: forge move <src> <dest>");
            return 1;
        }
        move_file(argv[2], argv[3]);
    }

    else if(strcmp(command, "delete")== 0){
        if(argc <3){
            print_error("Usage: forge delete <path>");
            return 1;
        }
        delete_file(argv[2]);
    }

    else if(strcmp(command, "info")==0){
        if(argc <3){
            print_error("Usage: forge info <path>");
            return 1;
        }
        show_file_info
        
        (argv[2]);
    }
    /*
    else if(strcmp(command, "diff")){
        if(argc <4){
            print_error("Usage: forge dif <file1> <file2>");
            return 1;
        }
        diff_file(argv[2], argv[3]);
    }
    */
    else{
        print_error("unknown command");
        printf("Available commands: list, copy, move, delete, info, diff\n");
        return 1;
    }
        
   
    return 0;


}