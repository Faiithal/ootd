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

void createOutfit()
{
    // Display Current Outfit Configuration

    // Action Menu of two options: [1] Add/Modify a clothing piece, [2] Create Outfit

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
            createOutfit();
            break;

        case 2:
            pickOOTD();
            return;

        case 3:
            return;
        }
    }
}

void checkOutfits(struct Outfit outfits[], int created_outfits_count)
{
    int total_pieces = 6;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Outfits:\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    for (int i = 0; i < created_outfits_count; i++)
    {

        // TODO: Implement isOutfitAvailable()
        printf("( %s )", isOutfitAvailable(outfits[i]) ? "Available" : "Unavailable");

        printf("| Outfit %d | ", i + 1);

        if (outfits[i].top->name != NULL)
        {
            printf("Top: %s | ", outfits[i].top->name);
        }
        if (outfits[i].bottom->name != NULL)
        {
            printf("Bottom: %s | ", outfits[i].bottom->name);
        }
        if (outfits[i].shoes->name != NULL)
        {
            printf("Shoes: %s | ", outfits[i].shoes->name);
        }
        if (outfits[i].headwear->name != NULL)
        {
            printf("Headwear: %s | ", outfits[i].headwear->name);
        }
        if (outfits[i].accessory->name != NULL)
        {
            printf("Accessory: %s | ", outfits[i].accessory->name);
        }
        if (outfits[i].bag->name != NULL)
        {
            printf("Bag: %s | ", outfits[i].bag->name);
        }

        printf("\n");
    }

    // TODO: Implement displayOutfitMenu()
    displayOutfitMenu();
}

// TODO: Implement Display OOTD
// TODO: Implement Wash Clothes

int main()
{
    struct Apparel top[9] = {0};
    struct Apparel bottom[9] = {0};
    struct Apparel shoes[9] = {0};
    struct Apparel headwear[9] = {0};
    struct Apparel accessory[9] = {0};
    struct Apparel bag[9] = {0};

    struct Outfit outfits[50] = {0};
    int created_outfits_count = 2;

    // Sample Closet Data
    strcpy(top[0].name, "Elite Miko Shirt");
    top[0].available = 1;

    strcpy(top[1].name, "Black Suisei Shirt");
    top[1].available = 1;

    strcpy(bottom[0].name, "Black Jeans");
    bottom[0].available = 1;

    strcpy(shoes[0].name, "Adidas Sambas");
    shoes[0].available = 1;
    strcpy(shoes[1].name, "Converse Shoes");
    shoes[1].available = 1;

    printf("%s\n", top[0].name);

    // Sample Outfit Data
    outfits[0].top = &top[0];
    outfits[0].bottom = &bottom[0];
    outfits[0].shoes = &shoes[0];

    outfits[1].top = &top[1];
    outfits[1].bottom = &bottom[0];
    outfits[1].shoes = &shoes[1];

    // printf("%s %s %s\n", (*outfits[0].top).name, (*outfits[0].bottom).name, (*outfits[0].shoes).name);

    // -> version
    // printf("%s %s %s\n", outfits[1].top->name, outfits[1].bottom->name, outfits[1].shoes->name);

    // TODO: Implement Action Menu
    checkOutfits(outfits, created_outfits_count);
}