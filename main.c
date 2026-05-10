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

// TODO: Impelement Check Outfit
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

    if (outfit.top->name != NULL)
    {
        printf("Top: %s | ", outfit.top->name);
    }
    if (outfit.bottom->name != NULL)
    {
        printf("Bottom: %s | ", outfit.bottom->name);
    }
    if (outfit.shoes->name != NULL)
    {
        printf("Shoes: %s | ", outfit.shoes->name);
    }
    if (outfit.headwear->name != NULL)
    {
        printf("Headwear: %s | ", outfit.headwear->name);
    }
    if (outfit.accessory->name != NULL)
    {
        printf("Accessory: %s | ", outfit.accessory->name);
    }
    if (outfit.bag->name != NULL)
    {
        printf("Bag: %s | ", outfit.bag->name);
    }

    printf("\n");
}

void modifyOutfit(struct Outfit outfit)
{
    int option = 0;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("What piece of clothing do you like to add/overwrite?");
    printf("[1] Tops\n");
    printf("[2] Bottom\n");
    printf("[3] Shoes\n");
    printf("[4] Headwear\n");
    printf("[5] Accessory\n");
    printf("[6] Bag\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    
    switch (option)
    // TODO: Figure a clean way to Implement Display available clothing of the chosen piece
    {
    case 1:
        
        break;
    default:
        printf("ERROR: Invalid Option, Please try again.\n");
        return;
    }

    if (option < 1 || option > 6)
    {
    }

    // TODO: Action Menu to choose to add or overwrite a piece
    // TODO: Do action
}

void copyOutfit(struct Outfit outfit, struct Outfit temp_outfit)
{
    outfit.top = temp_outfit.top;
    outfit.bottom = temp_outfit.bottom;
    outfit.shoes = temp_outfit.shoes;
    outfit.headwear = temp_outfit.headwear;
    outfit.accessory = temp_outfit.accessory;
    outfit.bag = temp_outfit.bag;
}

void createOutfitMenu()
{
    struct Outfit temp_outfit;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Current Outfit Configuration");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    // Display Current Outfit Configuration
    displayOutfitEntry(temp_outfit, "Outfit");

    // Action Menu
    while (1)
    {
        int option = 0;

        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Add/Overwrite a clothing piece\n");
        printf("[2] Save Outfit\n");
        printf("[3] Back\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf("Choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            modifyOutfit(temp_outfit);
            break;
        case 2:
            // TODO: Create Validation for Outfit Creation

            // Copy Contents of temp_outfit to outfits[i]
            copyOutfit(outfits[created_outfits_count++], temp_outfit);
            break;
        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
    //
}

void displayOutfitMenu()
{
    while (1)
    {
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
            // pickOOTD();
            return;

        case 3:
            return;
        default:
            printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
}

void checkOutfits(struct Outfit outfits[], int created_outfits_count)
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Outfits:\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for (int i = 0; i < created_outfits_count; i++)
    {
        char outfitLabel[50];
        snprintf(outfitLabel, sizeof(outfitLabel), "Outfit %d", i + 1);
        displayOutfitEntry(outfits[i], outfitLabel);
    }

    // TODO: Implement displayOutfitMenu()
    displayOutfitMenu();
}

// TODO: Implement Display OOTD
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
    checkOutfits(outfits, created_outfits_count);
}