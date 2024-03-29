#include <stdio.h>
#include <stdbool.h>

// function to test if the year entered is a leap year
bool is_leap_year(int year) {
  // if (year % 4 != 0) {
  //   return false;
  // } else if (year % 100 != 0) {
  //   return true;
  // } else if (year % 400 != 0) {
  //   return false;
  // } else {
  //   return true;
  // }

  return (year % 4 == 0 && (year % 100 || year % 400 == 0));

}

// number of days in a particular month. index 0 is a placeholder.
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


// function to add the number of days entered to the date entered by user
void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
  int days_left_in_month = 0;

  while (days_left_to_add > 0) {

    days_left_in_month = days_in_month[*mm] - *dd;
    // add 1 day to february if the year is a leap year
    if (*mm == 2 && is_leap_year(*yy)) {
      days_left_in_month += 1;
    }
    // if the days to add is more than the days left in a month
    if (days_left_to_add > days_left_in_month) {
      days_left_to_add -= days_left_in_month;
      days_left_to_add -= 1;
      *dd = 1;
      if (*mm == 12) {
        *mm = 1;
        *yy += 1;
      } else {
        *mm +=1;
      }
    } else {
      *dd += days_left_to_add;
      days_left_to_add = 0;
    }
  }
}

int main() {
  // int year;
  // printf("Enter a year: ");
  // scanf("%i", &year);
  // if (is_leap_year(year)) {
  //   printf("Leap Year\n");
  // } else {
  //   printf("Not Leap Year\n");
  // }

  int mm, dd, yy, days_left_to_add;
  char *month[] = {"NA", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  printf("Please enter a date in the format mm dd yyyy and provide the number of days to add to this date : ");
  scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
  add_days_to_date(&mm, &dd, &yy, days_left_to_add);

  switch(dd) {
    case 1: case 21: case 31:
    printf("The new date is in mmm dd, yyyy: %s %dst, %d\n", month[mm], dd, yy);
    break;
    case 2: case 22:
    printf("The new date is in mmm dd, yyyy: %s %dnd, %d\n", month[mm], dd, yy);
    break;
    case 3: case 23:
    printf("The new date is in mmm dd, yyyy: %s %drd, %d\n", month[mm], dd, yy);
    break;
    default:
    printf("The new date is in mmm dd, yyyy: %s %dth, %d\n", month[mm], dd, yy);
    break;
  }
  
}