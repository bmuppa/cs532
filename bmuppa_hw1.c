#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_line_buffer 4096

int line_counter();
char* get_each_line(char* array, int n);
void read_csv_to_array(int count, char line[],char *firstname[], char *lastname[],char *major_department[], char *major_degree[],char *gpa[],char *credit_hrs[], char *advisors[]);
void get_top_3_ranks(char *gpa[], int n, char *firstname[], char *lastname[],double rank1, double rank2, double rank3);
int get_advisors_count(int total_advisors_count,char *advisor_name[]);
unsigned int comparator(char *array[],int end,unsigned int value);
void sorted_array(double sorted_gpa[], int n);
void Solution1(char *major_degree[], int n);
void Solution2(char *gpa[], char *firstname[], char *lastname[],int n, double rank1, double rank2, double rank3);
void Solution3(char *credit_hrs[], int n);
void Solution4(char *major_department[], char *gpa[], int n);
void Solution5(char *major_department[], char *advisors[],int n);
void print_seperator();

void print_seperator(){
    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
}
int line_counter(){
    FILE* file_stream2 = fopen("students_dataset.csv", "r+");
    int counter = 0;
    char line_reader = getc(file_stream2);
    while (line_reader != EOF)
    {
        if (line_reader == '\n')
            counter++;
        line_reader =getc(file_stream2);
    }
    fclose(file_stream2);
    return counter;
}

char* get_each_line(char* line, int n)
{
    char* token_element;
    for (token_element = strtok(line, ",");token_element && *token_element;token_element = strtok(NULL, ","))
    {
        if (!--n)
            return token_element;
    }
    return NULL;
}

void read_csv_to_array(int count, char line[],char *firstname[], char *lastname[],char *major_department[], char *major_degree[],char *gpa[],char *credit_hrs[], char *advisors[]){
        
        char* tmp = strdup(line);
        firstname[count] = strdup(get_each_line(tmp,1));
        free(tmp);
        tmp = strdup(line);
        lastname[count] = strdup(get_each_line(tmp,2));
        free(tmp);
        tmp = strdup(line);
        major_department[count] = strdup(get_each_line(tmp,3));
        free(tmp);
        tmp = strdup(line);
        major_degree[count] = strdup(get_each_line(tmp,4));
        free(tmp);
        tmp = strdup(line);
        gpa[count] = strdup(get_each_line(tmp,5));
        free(tmp);
        tmp = strdup(line);
        credit_hrs[count] = strdup(get_each_line(tmp,6));
        free(tmp);
        tmp = strdup(line);
        advisors[count] = strdup(get_each_line(tmp,8));
        free(tmp);
        
}

void get_top_3_ranks(char *gpa[], int n, char *firstname[], char *lastname[],double rank1, double rank2, double rank3){
    // printf("%f %f %f\n",rank1, rank2, rank3);
    for (int i=0;i<n;i++){
        double student_gpa_value = atof(gpa[i]);
        if (student_gpa_value==rank1 ){
            printf("*\t\t\t\t\t1st %s %s: %f\n", firstname[i],lastname[i], student_gpa_value );
        }
        
    }
    for (int i=0;i<n;i++){
        double student_gpa_value2 = atof(gpa[i]);
        if (student_gpa_value2==rank2 ){
            printf("*\t\t\t\t\t2nd %s %s: %f\n", firstname[i],lastname[i], student_gpa_value2 );
        }
    }
    for (int i=0;i<n;i++){
        double student_gpa_value3 = atof(gpa[i]);
        if (student_gpa_value3==rank3){
            printf("*\t\t\t\t\t3rd %s %s: %f\n", firstname[i],lastname[i], student_gpa_value3 );
        }
        
    }
}
int get_advisors_count(int total_advisors_count,char *advisor_name[]){
    int major_level_advisor_count = 0, m = 0;
    while(m<total_advisors_count){
        unsigned int value3 = 0;
        int flag_bit = 0,n = 0;
        while(n<m){
            value3 = strcmp(advisor_name[m],advisor_name[n]);
            if (!value3){
                flag_bit=1;
            }
        n=n+1;
        }
        if(!flag_bit){
            major_level_advisor_count = major_level_advisor_count + 1;
        }
    flag_bit = 0;
    m=m+1;
    }
    return major_level_advisor_count;
}
unsigned int comparator(char *array[],int end,unsigned int value){
    int i=0;
    while(i<end){
        value = strcmp(array[end],array[i]);
        if(!value){
            break;
        }
    i=i+1;
    }
    return value;
}
void sorted_array(double sorted_gpa[], int n){
    int i=0,j=0;
    //bubble sort 
    while(i<n)
    {
        double dummy_val=0.0f;
        for(j=0;j<n-i-1;j++)
        {
            if(sorted_gpa[j]>sorted_gpa[j+1])
            {
                dummy_val=sorted_gpa[j+1];
                sorted_gpa[j+1]=sorted_gpa[j];
                sorted_gpa[j]=dummy_val;
            }
        }
    i=i+1;
    }

}
void Solution1(char *major_degree[], int n){

    //strcmp funtion returns 0 if strings are equal, else returns >0 as we declared unsigned int
    printf("\nSolution1: Unique degrees\n");    
    unsigned int value ;
    int i = 1;
    while(i<n){
        value = comparator(major_degree,i,value);
        if (value>0)
            printf("*\t\t\t\t\t%s\n",major_degree[i]);
        i=i+1;
    }
    print_seperator();
}

void Solution2(char *gpa[], char *firstname[], char *lastname[],int n, double rank1, double rank2, double rank3){

    printf("\nSolution2: Top 3 Scorers based on GPA\n");
    double sorted_gpa[n];
    for(int i=0;i<n;i++)
        sorted_gpa[i]=atof(gpa[i]);
    sorted_array(sorted_gpa,n);
    get_top_3_ranks(gpa,n,firstname,lastname,sorted_gpa[n-1],sorted_gpa[n-2],sorted_gpa[n-3]);
    print_seperator();
}

void Solution3(char *credit_hrs[], int n){

    printf("\nSolution3: Average Credit Hours\n");
    double sum = 0;
    int i = 1;
    while(i<n){
        sum+=atof(credit_hrs[i]);
        i=i+1;
    }
    printf("*\t\t\t\t\t%f\n",sum/(n-1));
    print_seperator();
}

void Solution4(char *major_department[], char *gpa[], int n){
    printf("\nSolution4: Average GPA Computer science major_department\n\n");
    double sum_gpa = 0;
    int computers_count = 0, i = 0;
    while(i<n){
        if (strcmp(major_department[i],"Computer Science") == 0){
            sum_gpa += atof(gpa[i]);
            computers_count++;
        }
    i=i+1;
    }
    printf("*\t\t\t\t\t%f\n",sum_gpa/computers_count);
    print_seperator();

}

void Solution5(char *major_department[], char *advisors[],int n){
    printf("\nSolution5: Major Level Advisors Count\n");
    char* unique_majors[n];
    int unique_major_count = 0;
    unsigned int value = 0, i=1;
    while(i<n){
        value = comparator(major_department,i,value);
        if(value>0){
            unique_majors[unique_major_count++] = major_department[i];
        }
        value = 0;
        i=i+1;
    }
    i=0;
    while(i<unique_major_count){
        int total_advisors_count = 0;
        char* advisor_name[n];
        unsigned int value2 = 0;
        int j=1;
        while(j<n){
            value2 = strcmp(major_department[j],unique_majors[i]);
            if (!value2){
                    advisor_name[total_advisors_count]=strdup(advisors[j]);
                    total_advisors_count++;
            }
        j=j+1;
        }
        int major_level_advisor_count = get_advisors_count(total_advisors_count,advisor_name);
        printf("*\t\t\t\t\t%s %d\n", unique_majors[i], major_level_advisor_count);
        total_advisors_count = 0;
        major_level_advisor_count = 0;
        i=i+1;
    }
    print_seperator();
}

int main()
{
    
    int line_count = line_counter();
    FILE* file_stream = fopen("students_dataset.csv", "r");
    int file_row_count = line_count;
    char *firstname[file_row_count];
    char *lastname[file_row_count] ;
    char *major_department[file_row_count];
    char *major_degree[file_row_count];
    char *gpa[file_row_count];
    char *credit_hrs[file_row_count];
    char *advisors[file_row_count];
    int count = 0;
    double rank1, rank2, rank3 =0;
    //line read size has maximum capacity of 4096 bytes
    char line[max_line_buffer];

    while (fgets(line, max_line_buffer, file_stream))
    {
        read_csv_to_array(count,line,firstname,lastname,major_department,major_degree,gpa,credit_hrs,advisors);
        count++;
    }
    Solution1(major_degree,file_row_count);
    Solution2(gpa,firstname,lastname, file_row_count, rank1, rank2, rank3);
    Solution3(credit_hrs,file_row_count);
    Solution4(major_department, gpa, file_row_count);
    Solution5(major_department, advisors, file_row_count);
    return 0;
}