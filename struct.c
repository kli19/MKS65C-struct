# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

struct menu {char food[10000]; int price;};
char * food[] = {"Apple Pie", "Giant 3 ton Banana", "One French Fry", "Creativity", "Will to Live", "Perfect SAT Score"};


struct menu makeMenu(){
  struct menu randomMenu;
  srand(time(NULL));
  strcpy(randomMenu.food, food[rand()%sizeof(food)/sizeof(food[0])]);
  randomMenu.price =rand(); 
  return randomMenu;
}

void replaceMenu(struct menu * aMenu, char * food, int price){
  strcpy(aMenu->food,  food);
  aMenu->price = price; 
}

void XLFood(struct menu * aMenu){
  strcat(aMenu->food,  " XL");
}

void incrementPrice(struct menu * aMenu, int i){
  aMenu->price += i;
}

void printMenu(struct menu fiveStars){
  printf("%s: $%d\n", fiveStars.food, fiveStars.price);
}

int main(){

  struct menu fiveStars = makeMenu();
  printMenu(fiveStars);
  replaceMenu(&fiveStars, "OOP", 0);
  printMenu(fiveStars);
  incrementPrice(&fiveStars, 5);
  printMenu(fiveStars);
  XLFood(&fiveStars);
  printMenu(fiveStars);
  return 0;
}
