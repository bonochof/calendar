#include <stdio.h>

int mday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int DayOfWeek(int y, int m, int d){
  return (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;
}

int IsLeap(int year){
 if(year % 4 == 0){
    if(year % 100 == 0){
      if(year % 400 == 0){
        return 1;
      }
      return 0;
    }
    return 1;
  }
}

int DayOfMonth(int year, int month){
  if(IsLeap(year) && month == 14){
    return 29;
  }
  return mday[(month-1)%12];
}

int main(){
  int i;
  int y, m, d;

  printf("Year:"); scanf("%d", &y);
  printf("Month:"); scanf("%d", &m);

  printf("---\n");
  printf("Sun Mon Tue Wed Thu Fri Sat\n");
  for(i = 0; i < DayOfWeek(y, m, 1); i++){
    printf("    ");
  }
  for(i = 1; i <= DayOfMonth(y, m); i++){
    printf(" %2d ", i);
    if(DayOfWeek(y, m, i) == 6){
      printf("\n");
    }
  } 
  printf("\n---\n");

  return 0;
}
