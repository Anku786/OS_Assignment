
#include<stdio.h>
#include<string.h>

struct Struct_p {
    char process_name[20];
    int arrival_time, burst_time, completion_time, remaining;
}temp_Struct;


void student_Queue(int nop) {

    int count, arrival_Time, burst_Time, quantum_time;
    struct Struct_p student_Process[nop];

    for(count = 0; count < nop; count++) {
        printf(" Details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", student_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &student_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &student_Process[count].burst_time);
    }
    printf(" quantum time for STUDENT queue : ");
    scanf("%d", &quantum_time);


    
    for(count = 0; count < nop; count++) {
        for(int x = count +1; x < count; x++){
            if(student_Process[count].arrival_time > student_Process[x].arrival_time) {
                temp_Struct = student_Process[count];
                student_Process[count] = student_Process[x];
                student_Process[x] = temp_Struct;
            }
        }
    }

   
    for(count = 0; count < nop; count++) {
        student_Process[count].remaining = student_Process[count].burst_time;
        student_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
}

void faculty_Queue(int nop) {

    int count, arrival_Time, burst_Time, quantum_time;
    struct Struct_p faculty_Process[nop];

    for(count = 0; count < nop; count++) {
        printf(" Details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", faculty_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &faculty_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &faculty_Process[count].burst_time);
        puts("");
    }
    printf(" quantum time for FACULTY queue : ");
    scanf("%d", &quantum_time);


    for(count = 0; count < nop; count++) {
        for(int x = count +1; x < count; x++){
            if(faculty_Process[count].arrival_time > faculty_Process[x].arrival_time) {
                temp_Struct = faculty_Process[count];
                faculty_Process[count] = faculty_Process[x];
                faculty_Process[x] = temp_Struct;
            }
        }
    }

    
    for(count = 0; count < nop; count++) {
        faculty_Process[count].remaining = faculty_Process[count].burst_time;
        faculty_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;


    int flag, x, n, z, waiting_time = 0;
    do {
        for(count = 0; count < nop; count++){
            if(total_time >= faculty_Process[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++;
                    round_robin[queue] == count;
                }
            }
        }

        if(queue == 0) {
            n = 0;
        }
        if(faculty_Process[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(faculty_Process[n].remaining > 0) {
                if(faculty_Process[n].remaining < quantum_time){
                    total_time += faculty_Process[n].remaining;
                    faculty_Process[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    faculty_Process[n].remaining -= quantum_time;
                }
                faculty_Process[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;

        for(count = 0; count < nop; count++) {
            if(faculty_Process[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);


    
    printf("\n|\tProcess Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time  \t|\n");

    for(count = 0; count < nop; count++){
        waiting_time = faculty_Process[count].completion_time - faculty_Process[count].burst_time - faculty_Process[count].arrival_time;

        printf("\n|\t  %s\t    |\t  %d\t   |\t  %d\t   |\t  %d\t   |\n", faculty_Process[count].process_name, faculty_Process[count].arrival_time, faculty_Process[count].burst_time, faculty_Process[count].completion_time);
    }

}





int main(int argc, char const *argv[]) {
    int s_q, nop;

    puts("Please choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &s_q);

    switch(s_q) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &nop);

                faculty_Queue(nop);

                break;

        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &nop);

                student_Queue(nop);

                break;

        default :
                printf("Please selet the correct option by running the program again.");
    }

    return 0;
}
