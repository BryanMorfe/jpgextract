#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extract(char *file_path);
int fpeekc(FILE *fp);
void help_menu();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        help_menu();
        exit(1);
    }
    
    if (strcmp(argv[1], "-h") == 0)
    {
        help_menu();
        exit(1);
    }
    
    extract(argv[1]);
    return 0;
}

void extract(char *file_path)
{
    FILE *fp = fopen(file_path, "r");
    
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening cache file %s\n", file_path);
        exit(1);
    }
    
    int ch, i = 0;
    
    printf("Extracting images...\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        
        if (ch == 0xFF && fpeekc(fp) == 0xD8)
        {
            
            char filename[10];
            snprintf(filename, 10, "%d", i);
            strcat(filename, ".jpg");
            FILE *img_fp = fopen(filename, "w");
            
            if (img_fp == NULL)
            {
                fprintf(stderr, "Error creating image file %s\n", filename);
                fclose(fp);
                exit(1);
            }
            
            while (!(ch == 0xFF && fpeekc(fp) == 0xD9) && ch != EOF)
            {
                fputc(ch, img_fp);
                ch = fgetc(fp);
            }
            
            fputc(ch, img_fp);
            fputc((ch = fgetc(fp)), img_fp);
            
            fclose(img_fp);
            i++;
        }
    }
    
    fclose(fp);
    
    printf("%d jpgs extracted.\n", i + 1);
    
}

int fpeekc(FILE *fp)
{
    int c;
    
    c = fgetc(fp);
    ungetc(c, fp);
    
    return c;
}

void help_menu()
{
    printf("Usage: jpgextract [file_path].\n");
}
