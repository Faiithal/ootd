#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int actionMenu_choiceValidation(int numberOfChoices) {
    int choice = 0;
    printf("Choice: ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. Enter an integer corresponding to a choice (1 to %d only).\n", numberOfChoices);
        return actionMenu_choiceValidation(numberOfChoices);
    }
    if (choice >= 1 && choice <= numberOfChoices) return choice;
    else {
        printf("Invalid. Enter an integer corresponding to a choice (1 to %d only).\n", numberOfChoices);
        return actionMenu_choiceValidation(numberOfChoices);
    }
}


// CHECK CLOSET FEATURE : Display Clothing Section 

int chooseClothingSection() {
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("%-15s %-15s\n", "[1] top", "[4] headwear");
    printf("%-15s %-15s\n", "[2] bottom", "[5] accessory");
    printf("%-15s %-15s\n", "[3] shoes", "[6] bag");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return actionMenu_choiceValidation(6); 
}

void displayItems(struct Apparel section[]) {
    if(section[0].name[0] == '\0')
        printf("No clothes stored in this section.\n");
    else 
    {
        for(int i = 0; i < 9; i++) 
        {     
            if(section[i].name[0] != '\0') 
                printf("[%d] %s (%s)\n", i + 1, section[i].name, section[i].available ? "Available" : "Unavailable");
            else 
                break;
        }
    }
    printf("\n");
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

void loadClosetFile(const char *filename,
                    struct Apparel tops[],
                    struct Apparel bottoms[],
                    struct Apparel shoes[],
                    struct Apparel headwears[],
                    struct Apparel accessories[],
                    struct Apparel bags[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;  // nothing to load yet

    char buffer[256];
    struct Apparel *currentSection = NULL;
    int index = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        buffer[strcspn(buffer, "\n")] = '\0';  

        if (strcmp(buffer, "TOPS") == 0) { currentSection = tops; index = 0; continue; }
        if (strcmp(buffer, "BOTTOMS") == 0) { currentSection = bottoms; index = 0; continue; }
        if (strcmp(buffer, "SHOES") == 0) { currentSection = shoes; index = 0; continue; }
        if (strcmp(buffer, "HEADWEAR") == 0) { currentSection = headwears; index = 0; continue; }
        if (strcmp(buffer, "ACCESSORIES") == 0) { currentSection = accessories; index = 0; continue; }
        if (strcmp(buffer, "BAGS") == 0) { currentSection = bags; index = 0; continue; }

        if (buffer[0] == '\0') continue;

        // Parse line: e.g. "T3,Blue Shirt,1"
        char *firstComma = strchr(buffer, ',');
        if (firstComma && currentSection) {
            *firstComma = '\0';
            char *itemName = firstComma + 1;

            char *secondComma = strchr(itemName, ',');
            int availableFlag = 1;
            if (secondComma) {
                *secondComma = '\0';
                availableFlag = atoi(secondComma + 1);
            }

            if (itemName[0] != '\0') {
                strcpy(currentSection[index].name, itemName);
                currentSection[index].available = availableFlag;
            }
            index++;
        }
    }

    fclose(fp);
}


// CHECK CLOSET FEATURE : Add a Piece to the Section

int chooseAddClothing() {
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
            "[1] Add clothing\n"
            "[2] Back\n"
            "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    return actionMenu_choiceValidation(2);
}

void setupClosetFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) { perror("Error creating file"); exit(1); }

    fprintf(fp, "TOPS\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "T%d,\n", i);

    fprintf(fp, "BOTTOMS\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "B%d,\n", i);

    fprintf(fp, "SHOES\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "S%d,\n", i);

    fprintf(fp, "HEADWEAR\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "H%d,\n", i);

    fprintf(fp, "ACCESSORIES\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "A%d,\n", i);

    fprintf(fp, "BAGS\n");
    for (int i = 0; i < 9; i++) fprintf(fp, "G%d,\n", i);

    fclose(fp);
}

void appendItemToFile(char sectionCode, int order, const char *filename, const char *itemName, int availableFlag) {
    FILE *fp = fopen(filename, "r");
    
    // If file doesn't exist, create it with template
    if (!fp) {
        setupClosetFile(filename);
        fp = fopen(filename, "r");
        if (!fp) { perror("Error opening file"); exit(1); }
    }

    FILE *tempFp = fopen("temp_closet", "w");
    if (!tempFp) { perror("Error creating temp file"); fclose(fp); exit(1); }

    char buffer[256];
    char target[10];
    snprintf(target, sizeof(target), "%c%d,", sectionCode, order);
    int found = 0;

    // Copy file, replacing the matching line
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (!found && strncmp(buffer, target, strlen(target)) == 0) {
            fprintf(tempFp, "%c%d,%s,%d\n", sectionCode, order, itemName, availableFlag);
            found = 1;
        } else {
            fputs(buffer, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    // Replace original file with temp file
    remove(filename);
    rename("temp_closet", filename);
}

void updateClosetFile(const char *filename, const char *sectionName, int i, const char *itemName, int availableFlag) {
    if (strcmp(sectionName, "top") == 0)
        appendItemToFile('T', i, filename, itemName, availableFlag);
    else if (strcmp(sectionName, "bottom") == 0)
        appendItemToFile('B', i, filename, itemName, availableFlag);
    else if (strcmp(sectionName, "shoes") == 0)
        appendItemToFile('S', i, filename, itemName, availableFlag);
    else if (strcmp(sectionName, "headwear") == 0)
        appendItemToFile('H', i, filename, itemName, availableFlag);
    else if (strcmp(sectionName, "accessory") == 0)
        appendItemToFile('A', i, filename, itemName, availableFlag);
    else if (strcmp(sectionName, "bag") == 0)
        appendItemToFile('G', i, filename, itemName, availableFlag);
}

void addItem(struct Apparel section[], const char *filename, const char *sectionName) {
    char item[30] = {'\0'};
    char fullFilename[100];
    
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
            "Enter the clothing to add: ");
    getchar();
    fgets(item, sizeof(item), stdin);
    item[strcspn(item, "\n")] = '\0';

    snprintf(fullFilename, sizeof(fullFilename), "%s", filename);

    for (int i = 0; i < 9; i++) {
        if (section[i].name[0] == '\0') {
            strncpy(section[i].name, item, sizeof(section[i].name) - 1);
            section[i].name[sizeof(section[i].name) - 1] = '\0';
            section[i].available = 1;
            updateClosetFile(fullFilename, sectionName, i, item, 1);
            printf("%s successfully added.\n", item);
            return;
        }
    }
    printf("Section full (MAX 9)! Cannot add any more items.\n");
}

void addClothing(
    int clothingSection_choice,
    struct Apparel top[],
    struct Apparel bottom[],
    struct Apparel shoes[],
    struct Apparel headwear[],
    struct Apparel accessory[],
    struct Apparel bag[],
    char *closetName) {
    
    switch (clothingSection_choice)
    {
    case 1:
        addItem(top, closetName, "top");
        break;
    case 2:
        addItem(bottom, closetName, "bottom");
        break;
    case 3:
        addItem(shoes, closetName, "shoes");
        break;
    case 4:
        addItem(headwear, closetName, "headwear");
        break;
    case 5:
        addItem(accessory, closetName, "accessory");
        break;
    case 6:
        addItem(bag, closetName, "bag");
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
    struct Apparel bag[],
    char *closetName) {

    char closetFile[100];
    snprintf(closetFile, sizeof(closetFile), "%s", closetName);
    loadClosetFile(closetFile, top, bottom, shoes, headwear, accessory, bag);

    int checkCloset_menuChoice=0, clothingSection_choice=0, addClothing_menuChoice=0;
   
    while (1) {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                "[1] Choose a clothing section\n"
                "[2] Back\n"
                "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Choice: ");
        scanf("%d", &checkCloset_menuChoice);

        switch (checkCloset_menuChoice) {
        case 1:
            clothingSection_choice = chooseClothingSection();
            displayClothingSection(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag);
            addClothing_menuChoice = chooseAddClothing();
            if (addClothing_menuChoice == 1) 
                addClothing(clothingSection_choice, top, bottom, shoes, headwear, accessory, bag, closetName);
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

struct Apparel *chooseOutfitApparel(struct Outfit *outfit, struct Apparel apparels[])
{
    int option_piece;
    int createdApparelSize = 0;
    for (int i = 0; i < 9; i++)
    {
        if (apparels[i].name[0] != '\0')
            createdApparelSize++;
    }

    if (createdApparelSize == 0)
    {
        printf("There are currently no pieces here, try adding one!\n");
        return NULL;
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i = 0; i < createdApparelSize; i++)
    {
        printf("[%d] %s ( %s )\n", i + 1, apparels[i].name, apparels[i].available ? "Available" : "Unavailable");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("Choice: ");
    scanf("%d", &option_piece);

    if (option_piece < 1 || option_piece > createdApparelSize)
    {
        printf("ERROR: Invalid Option, Please try again.\n");
        return NULL;
    }

    if (!apparels[option_piece - 1].available)
    {
        printf("ERROR: Chosen piece is unavailable. Please use an available piece");
        return NULL;
    }

    return &apparels[option_piece - 1];
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
    if (outfit.bag != NULL && !outfit.bag->available)
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
        (*outfit).top = chooseOutfitApparel(outfit, tops);
        break;
    case 2:
        (*outfit).bottom = chooseOutfitApparel(outfit, bottoms);
        break;
    case 3:
        (*outfit).shoes = chooseOutfitApparel(outfit, shoes);
        break;
    case 4:
        (*outfit).headwear = chooseOutfitApparel(outfit, headwears);
        break;
    case 5:
        (*outfit).accessory = chooseOutfitApparel(outfit, accessories);
        break;
    case 6:
        (*outfit).bag = chooseOutfitApparel(outfit, bags);
        break;
    default:
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    // Error
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
            if (temp_outfit.top != NULL &&
                temp_outfit.bottom != NULL &&
                temp_outfit.shoes != NULL)
            {
                if (created_outfits_count >= 50) {
                    printf("ERROR: Maximum outfits reached (50)!\n");
                    break;
                }
                copyOutfit(&outfits[created_outfits_count++], temp_outfit);
                printf("Outfit Saved Successfully!\n");
                return;
            }
            else {
                printf("ERROR: Outfit must have at least a top, bottom, and shoes!\n");
                break;
            }
        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
    //
}

// Helper for markOutfitClothesUnavailable
int findIndex(struct Apparel section[], struct Apparel *item) {
    for (int i = 0; i < 9; i++) {
        if (&section[i] == item) return i;
    }
    return -1;
}

void markOutfitClothesUnavailable(struct Outfit outfit, const char *filename) {
    int idx;

    if (outfit.top != NULL && outfit.top->available) {
        outfit.top->available = 0;
        idx = findIndex(tops, outfit.top);
        if (idx >= 0) updateClosetFile(filename, "top", idx, outfit.top->name, 0);
    }

    if (outfit.bottom != NULL && outfit.bottom->available) {
        outfit.bottom->available = 0;
        idx = findIndex(bottoms, outfit.bottom);
        if (idx >= 0) updateClosetFile(filename, "bottom", idx, outfit.bottom->name, 0);
    }

    if (outfit.shoes != NULL && outfit.shoes->available) {
        outfit.shoes->available = 0;
        idx = findIndex(shoes, outfit.shoes);
        if (idx >= 0) updateClosetFile(filename, "shoes", idx, outfit.shoes->name, 0);
    }

    if (outfit.headwear != NULL && outfit.headwear->available) {
        outfit.headwear->available = 0;
        idx = findIndex(headwears, outfit.headwear);
        if (idx >= 0) updateClosetFile(filename, "headwear", idx, outfit.headwear->name, 0);
    }

    if (outfit.accessory != NULL && outfit.accessory->available) {
        outfit.accessory->available = 0;
        idx = findIndex(accessories, outfit.accessory);
        if (idx >= 0) updateClosetFile(filename, "accessory", idx, outfit.accessory->name, 0);
    }

    if (outfit.bag != NULL && outfit.bag->available) {
        outfit.bag->available = 0;
        idx = findIndex(bags, outfit.bag);
        if (idx >= 0) updateClosetFile(filename, "bag", idx, outfit.bag->name, 0);
    }
}

void pickOOTD(const char *filename)
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

    markOutfitClothesUnavailable(outfits[option - 1], filename);
}

void checkOutfits(const char *filename)
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
            pickOOTD(filename);
            break;

        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
}


// Wash Laundry Feature

void washApparels(struct Apparel apparels[], const char *filename, const char *sectionName) {
    for (int i = 0; apparels[i].name[0] != '\0'; i++) {
        apparels[i].available = 1;
        updateClosetFile(filename, sectionName, i, apparels[i].name, 1);
    }
}

void washLaundry(const char *filename) {
    washApparels(tops, filename, "top");
    washApparels(bottoms, filename, "bottom");
    washApparels(shoes, filename, "shoes");
    washApparels(headwears, filename, "headwear");
    washApparels(accessories, filename, "accessory");
    washApparels(bags, filename, "bag");

    printf("\n[!] Washing Clothes...\n");
    printf("[!] All items are now available again!\n");
}


int main()
{
    /* Sample Closet Data
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
    outfits[1].shoes = &shoes[1]; */


    char closetName[50];
    int choice;

    // --- START ---
    printf("==========================================\n");
    printf("        WELCOME TO DIGITAL CLOSET        \n");
    printf("==========================================\n");

    
    // Checks for current closet thru another file, if it exists, change the value of closetName to current, else create one. 
    FILE *closet_fp;
    
    closet_fp = fopen("current-closet", "a+");

    if(fscanf(closet_fp, "%s", closetName) <= 0) {
        printf("Enter Closet Name: ");
        scanf("%[^\n]", closetName);
        fprintf(closet_fp, "%s", closetName);
    }

    char closetFile[100];
    snprintf(closetFile, sizeof(closetFile), "%s", closetName);

    FILE *fp = fopen(closetFile, "r");
    if (!fp) {
        setupClosetFile(closetFile);  // create with placeholders
    } else {
        fclose(fp);
    }

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
            checkCloset(tops, bottoms, shoes, headwears, accessories, bags, closetFile);
        }
        else if (choice == 2)
        {
            // --- OUTFIT LIST ---
            checkOutfits(closetName);
        }
        else if (choice == 3)
        {
            washLaundry(closetName);
        }
        else if (choice == 4)
        {
            printf("\nExiting Program...\n");
            break;
        }
    }
}
