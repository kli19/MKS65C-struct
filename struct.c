# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

struct menu {char food[10000]; int price;};
char * food[] = {"Apple Pie", "Giant 3 ton Banana", "One French Fry", "Creativity", "Will to Live", "Perfect SAT Score"};


struct menu makeMenu(){
  struct menu randomMenu;
  strcpy(randomMenu.food, food[rand()%sizeof(food)/sizeof(food[0])]);
  randomMenu.price =rand(); 
  return randomMenu;
}

void replaceMenu(struct menu * aMenu, char * food, int price){
  strcpy(aMenu->food,  food);
  aMenu->price = price; 
}

void XLFood(struct menu * aMenu){
  strcat(aMenu->food, " XL");
}

void incrementPrice(struct menu * aMenu, int i){
  aMenu->price += i;
}

void printMenu(struct menu fiveStars){
  printf("%s costs $%d\n", fiveStars.food, fiveStars.price);
}

int main(){

  srand(time(NULL));
  
  struct menu fiveStars = makeMenu();
  printf("Let's look at our menu item!\n");
  printMenu(fiveStars);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("We are replacing our menu item and price!\n");
  replaceMenu(&fiveStars, "Nothing", 0);
  printMenu(fiveStars);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Let's make this new item extra large!\n");
  XLFood(&fiveStars);
  printMenu(fiveStars);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("Extra large means extra pricey, right?\n");
  incrementPrice(&fiveStars, 5);
  printMenu(fiveStars);
  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  return 0;
}
