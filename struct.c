# include <stdio.h>
# include <stdlib.h>

struct menu {char * food; int price;};
char * food[] = {"Apple Pie", "Giant 3 ton Banana", "One French Fry"};


struct menu makeMenu(){
  struct menu randomMenu;
  srand(time(NULL));
  randomMenu.food = food[rand()%3];
  randomMenu.price =rand(); 
  return randomMenu;
}

void modifyMenu(struct menu * aMenu, char * food, int price){
  (*aMenu).food = food;
  (*aMenu).price = price; 
}

void printMenu(struct menu fiveStars){
  printf("%s: $%d\n", fiveStars.food, fiveStars.price);
}

int main(){

  struct menu fiveStars = makeMenu();
  printMenu(fiveStars);
  modifyMenu(fiveStars, "Poo", 0);
  printMenu(fiveStars);
  return 0;
}
