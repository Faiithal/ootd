#include <stdio.h>
#include <string.h>

struct Apparel {
    char name[30];
    int avaiable;
};

struct Outfit {
    struct Apparel top;
    struct Apparel bottom;
    struct Apparel shoes;
    struct Apparel headwear;
    struct Apparel accessory;
    struct Apparel bag;
};

// CHECK CLOSET FEATURE : Validate Choice

int actionMenu_choiceValidation(int numberOfChoices) {
    //retrieves, validates, and returns the int of their corresponding choice
    int choice = 0;
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice < numberOfChoices) return choice;
    else {
        printf("Invalid. Enter an integer corresponding to a choice (1 to %d only).", numberOfChoices);
        actionMenu_choiceValidation(numberOfChoices);
    }
}


// CHECK CLOSET FEATURE : Display Clothing Section 

int chooseClothingSection() {
    printf("nACTION MENU > Check closet > Choose a clothing section\n"
            "[1] top\t[4] headwear\n"
            "[2] bottom\t[5] accessory\n"
            "[3] shoes\t[6] bag\n");
    return actionMenu_choiceValidation(6); 
}

void displayItems(struct Apparel section[]) {
    for(int i = 0; i < 9; i++) {
    printf("%s", section[i].name);
    }
}

void displayClothingSection(
    int clothingSection_choice,
    struct Apparel top[],
    struct Apparel bottom[],
    struct Apparel shoes[],
    struct Apparel headwear[],
    struct Apparel accessory[],
    struct Apparel bag[]) {

    switch (clothingSection_choice)
    {
    case 1:
        displayItems(top);
        break;
    case 2:
        displayItems(bottom);
        break;
    case 3:
        displayItems(shoes);
        break;
    case 4:
        displayItems(headwear);
        break;
    case 5:
        displayItems(accessory);
        break;
    case 6:
        displayItems(bag);
        break; 
    default:
        break;
        //do nothing, input already validated
    }
}


// CHECK CLOSET FEATURE : Add a Piece to the Section

int chooseAddClothing() {
    printf("\nACTION MENU > Check closet > Choose a clothing section > section\n"
            "[1] Add clothing\n"
            "[2] Back\n");
    return actionMenu_choiceValidation(2);
}

void addItem(struct Apparel section[]) {
    int sectionSize = sizeof(section) / sizeof(section[0]);
    char newPiece[30] = {'\0'};

    printf("Enter the clothing to add: ");
    fgets(newPiece, sizeof(newPiece), stdin);
    strcpy(section[sectionSize+1].name, newPiece);
    getchar();
}

void addClothing(
    int clothingSection_choice,
    struct Apparel top[],
    struct Apparel bottom[],
    struct Apparel shoes[],
    struct Apparel headwear[],
    struct Apparel accessory[],
    struct Apparel bag[]) {
    
    switch (clothingSection_choice)
    {
    case 1:
        addItem(top);
        break;
    case 2:
        addItem(bottom);
        break;
    case 3:
        addItem(shoes);
        break;
    case 4:
        addItem(headwear);
        break;
    case 5:
        addItem(accessory);
        break;
    case 6:
        addItem(bag);
        break; 
    default:
        break;
        //do nothing, input already validated
    }       
}


// TODO : Implement Check Closet

void checkCloset(
    struct Apparel top[],
    struct Apparel bottom[],
    struct Apparel shoes[],
    struct Apparel headwear[],
    struct Apparel accessory[],
    struct Apparel bag[]) {

    int checkCloset_menuChoice=0, clothingSection_choice=0, addClothing_menuChoice=0;
   
    while (1) {
        printf("\nACTION MENU > Check closet >\n"
                "[1] Choose a clothing section\n"
                "[2] Back\n");
        scanf("%d", &checkCloset_menuChoice);

        switch (checkCloset_menuChoice) {
        case 1:
            clothingSection_choice = chooseClothingSection();
            displayClothingSection(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag);
            addClothing_menuChoice = chooseAddClothing();
            if (addClothing_menuChoice == 1) addClothing(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag);
            break;
        case 2:
            return;
        default:
            printf("Invalid. Enter an integer corresponding to a choice only (1-2).\n"
                    "Try again.\n");
        }
    }  
}

// TODO: Impelement Check Outfit
// TODO: Implement Display OOTD
// TODO: Implement Wash Clothes

int main() {
    struct Apparel top[9];
    struct Apparel bottom[9];
    struct Apparel shoes[9];
    struct Apparel headwear[9];
    struct Apparel accessory[9];
    struct Apparel bag[9];

    // TODO: Implement Action Menu
    checkCloset(top, bottom, shoes, headwear, accessory, bag);

    return 0;
}
