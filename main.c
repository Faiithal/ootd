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

// TODO: Implement Check Closet

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

    if(!tops[option_piece - 1].available){
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

    if(!bottoms[option_piece - 1].available){
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

    if(!shoes[option_piece - 1].available){
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

    if(!headwears[option_piece - 1].available){
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

    if(!accessories[option_piece - 1].available){
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

    if(!bags[option_piece - 1].available){
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
// TODO: Implement Wash Clothes

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

    printf("%s\n", tops[0].name);

    // Sample Outfit Data
    outfits[0].top = &tops[0];
    outfits[0].bottom = &bottoms[0];
    outfits[0].shoes = &shoes[0];

    outfits[1].top = &tops[1];
    outfits[1].bottom = &bottoms[0];
    outfits[1].shoes = &shoes[1];

    // printf("%s %s %s\n", (*outfits[0].top).name, (*outfits[0].bottom).name, (*outfits[0].shoes).name);

    // -> version
    // printf("%s %s %s\n", outfits[1].top->name, outfits[1].bottom->name, outfits[1].shoes->name);

    // TODO: Implement Action Menu
    checkOutfits();
}