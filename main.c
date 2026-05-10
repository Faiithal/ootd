#include <stdio.h>
#include <string.h>

struct Apparel
{
    char name[30];
    int available;
};

struct Outfit
{
    struct Apparel *top;
    struct Apparel *bottom;
    struct Apparel *shoes;
    struct Apparel *headwear;
    struct Apparel *accessory;
    struct Apparel *bag;
};

struct Apparel tops[9] = {0};
struct Apparel bottoms[9] = {0};
struct Apparel shoes[9] = {0};
struct Apparel headwears[9] = {0};
struct Apparel accessories[9] = {0};
struct Apparel bags[9] = {0};

struct Outfit outfits[50] = {0};
int created_outfits_count = 2;

// CHECK CLOSET FEATURE : Validate Choice

int actionMenu_choiceValidation(int numberOfChoices)
{
    // retrieves, validates, and returns the int of their corresponding choice
    int choice = 0;
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice >= 1 && choice < numberOfChoices)
        return choice;
    else
    {
        printf("Invalid. Enter an integer corresponding to a choice (1 to %d only).", numberOfChoices);
        actionMenu_choiceValidation(numberOfChoices);
    }
}

// CHECK CLOSET FEATURE : Display Clothing Section 

int chooseClothingSection()
{
    printf("nACTION MENU > Check closet > Choose a clothing section\n"
           "[1] top\t[4] headwear\n"
           "[2] bottom\t[5] accessory\n"
           "[3] shoes\t[6] bag\n");
    return actionMenu_choiceValidation(6);
}

void displayItems(struct Apparel section[])
{
    for (int i = 0; i < 9; i++)
    {
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
    struct Apparel bag[])
{

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
        // do nothing, input already validated
    }
}

// CHECK CLOSET FEATURE : Add a Piece to the Section

int chooseAddClothing() {
    printf("\nACTION MENU > Check closet > Choose a clothing section > section\n"
            "[1] Add clothing\n"
            "[2] Back\n");
    return actionMenu_choiceValidation(2);
}

// TODO: Implement Check Closet

void checkCloset(
    struct Apparel top[],
    struct Apparel bottom[],
    struct Apparel shoes[],
    struct Apparel headwear[],
    struct Apparel accessory[],
    struct Apparel bag[])
{

    int checkCloset_menuChoice = 0, clothingSection_choice = 0, addClothing_menuChoice = 0;

    while (1)
    {
        printf("\nACTION MENU > Check closet >\n"
               "[1] Choose a clothing section\n"
               "[2] Back\n");
        scanf("%d", &checkCloset_menuChoice);

        switch (checkCloset_menuChoice)
        {
        case 1:
            clothingSection_choice = chooseClothingSection();
            displayClothingSection(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag);
            addClothing_menuChoice = chooseAddClothing();
            if (addClothing_menuChoice == 1)
                // addClothing(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag);
                break;
        case 2:
            return;
        default:
            printf("Invalid. Enter an integer corresponding to a choice only (1-2).\n"
                   "Try again.\n");
        }
    }
}

// Add Apparel Helper Functions
void modifyTop(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (tops[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, tops[i].name, tops[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!tops[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).top = &tops[option_piece - 1];
}
void modifyBottom(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (bottoms[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, bottoms[i].name, bottoms[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!bottoms[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).bottom = &bottoms[option_piece - 1];
}
void modifyShoes(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (shoes[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, shoes[i].name, shoes[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!shoes[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).shoes = &shoes[option_piece - 1];
}
void modifyHeadwear(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (headwears[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, headwears[i].name, headwears[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!headwears[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).headwear = &headwears[option_piece - 1];
}
void modifyAccessory(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (accessories[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, accessories[i].name, accessories[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!accessories[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).accessory = &accessories[option_piece - 1];
}
void modifyBag(struct Outfit *outfit)
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (bags[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, bags[i].name, bags[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (!bags[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return;
    }

    (*outfit).bag = &bags[option_piece - 1];
}

// Outfit Helper Functions
int isOutfitAvailable(struct Outfit outfit)
{
    // NOTE: AHHH Nabubulag ako sa lala ng readability
    if (outfit.top != NULL && !outfit.top->available)
    {
        return 0;
    }
    if (outfit.bottom != NULL && !outfit.bottom->available)
    {
        return 0;
    }
    if (outfit.shoes != NULL && !outfit.shoes->available)
    {
        return 0;
    }
    if (outfit.headwear != NULL && !outfit.headwear->available)
    {
        return 0;
    }
    if (outfit.accessory != NULL && !outfit.accessory->available)
    {
        return 0;
    }
    if (outfit.accessory != NULL && !outfit.bag->available)
    {
        return 0;
    }

    return 1;
}

int displayOutfitEntry(struct Outfit outfit, char outfitLabel[])
{
    printf("( %s )", isOutfitAvailable(outfit) ? "Available" : "Unavailable");

    printf("| %s | ", outfitLabel);

    if (outfit.top != NULL)
    {
        printf("Top: %s | ", outfit.top->name);
    }
    if (outfit.bottom != NULL)
    {
        printf("Bottom: %s | ", outfit.bottom->name);
    }
    if (outfit.shoes != NULL)
    {
        printf("Shoes: %s | ", outfit.shoes->name);
    }
    if (outfit.headwear != NULL)
    {
        printf("Headwear: %s | ", outfit.headwear->name);
    }
    if (outfit.accessory != NULL)
    {
        printf("Accessory: %s | ", outfit.accessory->name);
    }
    if (outfit.bag != NULL)
    {
        printf("Bag: %s | ", outfit.bag->name);
    }

    printf("\n");
}

// Outfit Main Features

void modifyOutfit(struct Outfit *outfit)
{
    int option = 0;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("What piece of clothing do you like to add/overwrite?\n");
    printf("[1] Tops\n");
    printf("[2] Bottom\n");
    printf("[3] Shoes\n");
    printf("[4] Headwear\n");
    printf("[5] Accessory\n");
    printf("[6] Bag\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        modifyTop(outfit);
        break;
    case 2:
        modifyBottom(outfit);
        break;
    case 3:
        modifyShoes(outfit);
        break;
    case 4:
        modifyHeadwear(outfit);
        break;
    case 5:
        modifyAccessory(outfit);
        break;
    case 6:
        modifyBag(outfit);
        break;
    default:
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }
}

void copyOutfit(struct Outfit *outfit, struct Outfit temp_outfit)
{
    (*outfit).top = temp_outfit.top;
    (*outfit).bottom = temp_outfit.bottom;
    (*outfit).shoes = temp_outfit.shoes;
    (*outfit).headwear = temp_outfit.headwear;
    (*outfit).accessory = temp_outfit.accessory;
    (*outfit).bag = temp_outfit.bag;
}

void createOutfitMenu()
{
    struct Outfit temp_outfit = {0};

    // Action Menu
    while (1)
    {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Current Outfit Configuration\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
        // Display Current Outfit Configuration
        displayOutfitEntry(temp_outfit, "Outfit");
        int option = 0;

        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Add/Overwrite a clothing piece\n");
        printf("[2] Save Outfit\n");
        printf("[3] Back\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf("Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            modifyOutfit(&temp_outfit);
            break;
        case 2:
            // TODO: Create Validation for Outfit Creation (Outfit needs at least a top, bottom, and shoes)

            // Copy Contents of temp_outfit to outfits[i]
            copyOutfit(&outfits[created_outfits_count++], temp_outfit);
            printf("Outfit Saved Successfully!\n");
            return;
        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
    //
}

void markOutfitClothesUnavailable(struct Outfit outfit)
{
    if (outfit.top != NULL && outfit.top->available)
        outfit.top->available = 0;

    if (outfit.bottom != NULL && outfit.bottom->available)
        outfit.bottom->available = 0;

    if (outfit.shoes != NULL && outfit.shoes->available)
        outfit.shoes->available = 0;

    if (outfit.headwear != NULL && outfit.headwear->available)
        outfit.headwear->available = 0;

    if (outfit.accessory != NULL && outfit.accessory->available)
        outfit.accessory->available = 0;

    if (outfit.bag != NULL && outfit.bag->available)
        outfit.bag->available = 0;
}

void pickOOTD()
{
    int option;
    char outfitLabel[50];

    for (int i = 0; i < created_outfits_count; i++)
    {
        snprintf(outfitLabel, sizeof(outfitLabel), "Outfit %d", i + 1);
        printf("[%d] %s\n", i + 1, outfitLabel);
    }

    while (1)
    {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Pick an outfit: ");
        scanf("%d", &option);

        if (option < 1 || option > created_outfits_count)
        {
            printf("ERROR: Invalid Option, Please try again.\n");
        }
        else
            break;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Outfit of the day:\n");

    snprintf(outfitLabel, sizeof(outfitLabel), "Outfit %d", option);
    displayOutfitEntry(outfits[option - 1], outfitLabel);

    markOutfitClothesUnavailable(outfits[option - 1]);
}

void checkOutfits()
{
    while (1)
    {
        // Current Outfits
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Outfits:\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        for (int i = 0; i < created_outfits_count; i++)
        {
            char outfitLabel[50];
            snprintf(outfitLabel, sizeof(outfitLabel), "Outfit %d", i + 1);
            displayOutfitEntry(outfits[i], outfitLabel);
        }

        // Outfit Menu
        int option = 0;

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Create Outfit\n");
        printf("[2] Pick Outfit of the Day\n");
        printf("[3] Back\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf("Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            createOutfitMenu();
            break;

        case 2:
            pickOOTD();
            break;

        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
}

// Wash Clothes Feature

void washClothes()
{
    for (int i = 0; tops[i].name[0] != '\0'; i++)
    {
        tops[i].available = 1;
    }

    for (int i = 0; bottoms[i].name[0] != '\0'; i++)
    {
        bottoms[i].available = 1;
    }

    for (int i = 0; shoes[i].name[0] != '\0'; i++)
    {
        shoes[i].available = 1;
    }

    for (int i = 0; headwears[i].name[0] != '\0'; i++)
    {
        headwears[i].available = 1;
    }

    for (int i = 0; accessories[i].name[0] != '\0'; i++)
    {
        accessories[i].available = 1;
    }

    for (int i = 0; bags[i].name[0] != '\0'; i++)
    {
        bags[i].available = 1;
    }
    printf("\n[!] Washing Clothes...\n");
    printf("[!] All items are now available again!\n");
}

int main()
{
    // Sample Closet Data
    strcpy(tops[0].name, "Elite Miko Shirt");
    tops[0].available = 1;

    strcpy(tops[1].name, "Black Suisei Shirt");
    tops[1].available = 1;

    strcpy(bottoms[0].name, "Black Jeans");
    bottoms[0].available = 1;

    strcpy(shoes[0].name, "Adidas Sambas");
    shoes[0].available = 1;
    strcpy(shoes[1].name, "Converse Shoes");
    shoes[1].available = 1;

    // Sample Outfit Data
    outfits[0].top = &tops[0];
    outfits[0].bottom = &bottoms[0];
    outfits[0].shoes = &shoes[0];

    outfits[1].top = &tops[1];
    outfits[1].bottom = &bottoms[0];
    outfits[1].shoes = &shoes[1];

    // Work by: ANNA L. PARRENO

    char closetName[50];
    int choice;

    // --- START ---
    printf("==========================================\n");
    printf("        WELCOME TO DIGITAL CLOSET        \n");
    printf("==========================================\n");
    printf("Enter Closet Name: ");
    scanf(" %[^\n]s", closetName);

    // --- ACTION MENU ---
    while (1)
    {
        printf("\n******************************************\n");
        printf("    ACTION MENU - %s\n", closetName);
        printf("******************************************\n");
        printf(" [1] Check Closet\n");
        printf(" [2] Check Outfit List\n");
        printf(" [3] Wash Laundry\n");
        printf(" [4] Exit\n");
        printf("------------------------------------------\n");
        printf("Select Action: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            // --- CLOSET VIEW ---
            checkCloset(tops, bottoms, shoes, headwears, accessories, bags);
        }
        else if (choice == 2)
        {
            // --- OUTFIT LIST ---
            checkOutfits();
        }
        else if (choice == 3)
        {
            washClothes();
        }
        else if (choice == 4)
        {
            printf("\nExiting Program...\n");
            break;
        }
    }
}