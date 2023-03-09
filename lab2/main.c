#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee{
	int em_id;
	char em_name[10];
	int em_age;
	char em_phone[10];
	float em_salary;
	
	
	
}employee_t;

void empoyee_info(employee_t emp){
	printf("em_id : %d\n", emp.em_id);
	printf("em_name : %s\n", emp.em_name);
	printf("em_age : %d\n", emp.em_age);
	printf("em_phone : %s\n", emp.em_phone);
	printf("em_id : %d\n", emp.em_id);
	printf("em_salary : %f\n", emp.em_salary);
	
}

int empoyee_size(employee_t emp){
	printf("size : %d", sizeof(emp));
}

int main (){
  employee_t em;
  em.em_id = 0;
  strcpy(em.em_name, "IU Lee");
  em.em_age = 18;
  strcpy(em.em_phone, "0937123456");
  em.em_salary = 10000.30;
  empoyee_info(em);
  empoyee_size(em);
  
}
