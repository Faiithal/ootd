// ============================================================
// INTEGRATION CODE - Add to main.c
// ============================================================

// Add these function declarations at the top of main.c
void saveOutfitsToFile(const char *closetName);
void loadOutfitsFromFile(const char *closetName);
void outfitStatisticsMenu(const char *closetName);

// Modify the checkOutfits function to include statistics option
void checkOutfits(char *closetName) {
    while (1) {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Outfits:\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        
        for (int i = 0; i < created_outfits_count; i++) {
            char outfitLabel[50];
            snprintf(outfitLabel, sizeof(outfitLabel), "Outfit %d", i + 1);
            displayOutfitEntry(outfits[i], outfitLabel);
        }
        
        int option = 0;
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Create Outfit\n");
        printf("[2] Pick Outfit of the Day\n");
        printf("[3] View Outfit Statistics\n");  // NEW OPTION
        printf("[4] Back\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                createOutfitMenuWithSave(closetName);  // Use the modified version
                break;
            case 2:
                pickOOTD(closetName);
                break;
            case 3:
                outfitStatisticsMenu(closetName);  // NEW: Anna's Feature 4
                break;
            case 4:
                return;
            default:
                printf("ERROR: Invalid Option, Please try again.\n");
        }
    }
}

// In main(), add this line after getting closetName to load saved outfits:
// loadOutfitsFromFile(closetName);

int main() {
    // ... existing code ...
    
    // After getting closetName, load any saved outfits
    loadOutfitsFromFile(closetName);  // ADD THIS LINE
    
    // ... rest of main() ...
}
